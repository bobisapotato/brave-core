/* Copyright (c) 2021 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/components/permissions/permission_lifetime_manager.h"

#include "base/strings/string_number_conversions.h"
#include "brave/components/permissions/permission_lifetime_pref_names.h"
#include "components/content_settings/core/browser/content_settings_utils.h"
#include "components/content_settings/core/browser/host_content_settings_map.h"
#include "components/content_settings/core/browser/website_settings_info.h"
#include "components/content_settings/core/browser/website_settings_registry.h"
#include "components/permissions/permissions_client.h"
#include "components/pref_registry/pref_registry_syncable.h"
#include "services/preferences/public/cpp/scoped_pref_update.h"

namespace permissions {

namespace {

std::string ToStr(base::Optional<base::TimeDelta> lifetime) {
  if (!lifetime)
    return "nullopt";
  return base::NumberToString(lifetime->InSeconds());
}

}  // namespace

PermissionLifetimeManager::PermissionLifetimeManager(
    content::BrowserContext* browser_context)
    : browser_context_(browser_context) {
  DCHECK(browser_context_);
  PermissionsClient::Get()->GetSettingsMap(browser_context_)->AddObserver(this);
}

PermissionLifetimeManager::~PermissionLifetimeManager() {}

void PermissionLifetimeManager::RegisterProfilePrefs(
    user_prefs::PrefRegistrySyncable* registry) {
  registry->RegisterDictionaryPref(prefs::kPermissionLifetimeRoot);
  registry->RegisterDictionaryPref(prefs::kPermissionLifetimeExpirations);
}

void PermissionLifetimeManager::Shutdown() {
  PermissionsClient::Get()
      ->GetSettingsMap(browser_context_)
      ->RemoveObserver(this);
}

void PermissionLifetimeManager::OnContentSettingChanged(
    const ContentSettingsPattern& primary_pattern,
    const ContentSettingsPattern& secondary_pattern,
    ContentSettingsType content_type) {
  auto* settings_map =
      PermissionsClient::Get()->GetSettingsMap(browser_context_);
  for (const auto& timed_expirations : expirations_) {
    auto expirations_it = timed_expirations.second.find(content_type);
    if (expirations_it == timed_expirations.second.end()) {
      continue;
    }

    for (const auto& expiring_permission : expirations_it->second) {
      if (primary_pattern.IsValid() &&
          !primary_pattern.Matches(expiring_permission.requesting_origin)) {
        continue;
      }
      if (secondary_pattern.IsValid() &&
          !secondary_pattern.Matches(expiring_permission.embedding_origin)) {
        continue;
      }
      if (settings_map->GetContentSetting(
              expiring_permission.requesting_origin,
              expiring_permission.embedding_origin,
              content_type) != CONTENT_SETTING_ALLOW) {
        // ERASE RULE.
        LOG(ERROR) << "ERASE ME!";
      }
    }
  }
  LOG(ERROR) << "PermissionLifetimeManager::OnContentSettingChanged "
             << "\nprimary_pattern: " << primary_pattern.ToString()
             << "\nsecondary_pattern: " << secondary_pattern.ToString()
             << "\ntype: "
             << content_settings::WebsiteSettingsRegistry::GetInstance()
                    ->Get(content_type)
                    ->name();
}

void PermissionLifetimeManager::PermissionDecided(
    const PermissionRequest* permission_request,
    const GURL& requesting_origin,
    const GURL& embedding_origin,
    ContentSetting content_setting,
    bool is_one_time) {
  DCHECK(permission_request);
  if (content_setting != ContentSetting::CONTENT_SETTING_ALLOW) {
    return;
  }

  const auto& lifetime = permission_request->GetLifetime();
  if (!lifetime) {
    return;
  }

  const ContentSettingsType content_settings_type =
      permission_request->GetContentSettingsType();
  const base::Time expiration_time = base::Time::Now() + *lifetime;

  expirations_[expiration_time][content_settings_type].push_back(
      ExpiringPermission{.content_settings_type = content_settings_type,
                         .requesting_origin = requesting_origin,
                         .embedding_origin = embedding_origin,
                         .expiration_time = expiration_time});

  UpdateExpirationTimerHandler();

  const auto& patterns =
      HostContentSettingsMap::GetPatternsForContentSettingsType(
          requesting_origin, embedding_origin, content_settings_type);
  LOG(ERROR) << "PermissionLifetimeManager::PermissionDecided"
             << "\ntype: "
             << content_settings::WebsiteSettingsRegistry::GetInstance()
                    ->Get(content_settings_type)
                    ->name()
             << "\nrequesting_origin: " << requesting_origin
             << "\nembedding_origin: " << embedding_origin
             << "\nprimary_pattern: " << patterns.first.ToString()
             << "\nsecondary_pattern: " << patterns.second.ToString()
             << "\ncontent_setting: "
             << content_settings::ContentSettingToString(content_setting)
             << "\nlifetime: " << ToStr(permission_request->GetLifetime())
             << " seconds";
}

void PermissionLifetimeManager::UpdateExpirationTimerHandler() {
  if (expirations_.empty()) {
    current_scheduled_expiration_time_ = base::Time();
    expiration_timer_.Stop();
    return;
  }

  const auto& first_expiration = *expirations_.begin();
  if (current_scheduled_expiration_time_ == first_expiration.first) {
    // Timer is already correct. Do nothing.
    return;
  }

  current_scheduled_expiration_time_ = first_expiration.first;
  expiration_timer_.Start(
      FROM_HERE, current_scheduled_expiration_time_ - base::Time::Now(),
      base::BindOnce(&PermissionLifetimeManager::OnExpirationTimer,
                     base::Unretained(this)));
}

void PermissionLifetimeManager::OnExpirationTimer() {
  auto* settings_map =
      PermissionsClient::Get()->GetSettingsMap(browser_context_);
  std::vector<base::Time> expirations_to_clear;
  for (const auto& timed_expirations : expirations_) {
    if (timed_expirations.first > current_scheduled_expiration_time_) {
      break;
    }
    expirations_to_clear.push_back(timed_expirations.first);
    for (const auto& typed_expirations : timed_expirations.second) {
      for (const auto& expiring_permission : typed_expirations.second) {
        settings_map->SetContentSettingDefaultScope(
            expiring_permission.requesting_origin,
            expiring_permission.embedding_origin, typed_expirations.first,
            CONTENT_SETTING_DEFAULT);
      }
    }
  }
  for (const auto& expiration_to_clear : expirations_to_clear) {
    expirations_.erase(expiration_to_clear);
  }
  UpdateExpirationTimerHandler();
}

}  // namespace permissions