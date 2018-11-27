/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "client.h"

#include "json_helper.h"
#include "time_helper.h"
#include "static_values.h"
#include "logging.h"

using namespace std::placeholders;

namespace ads {

Client::Client(AdsImpl* ads, AdsClient* ads_client) :
    ads_(ads),
    ads_client_(ads_client),
    client_state_(new ClientState()) {
}

Client::~Client() = default;

void Client::SaveState() {
  auto callback = std::bind(&Client::OnStateSaved, this, _1);
  ads_client_->Save(_client_name, ToJson(), callback);
}

void Client::LoadState() {
  auto callback = std::bind(&Client::OnStateLoaded, this, _1, _2);
  ads_client_->Load(_client_name, callback);
}

void Client::AppendCurrentTimeToAdsShownHistory() {
  auto now = helper::Time::Now();
  client_state_->ads_shown_history.push_front(now);
  if (client_state_->ads_shown_history.size() >
      kMaximumEntriesInAdsShownHistory) {
    client_state_->ads_shown_history.pop_back();
  }
}

const std::deque<uint64_t> Client::GetAdsShownHistory() {
  return client_state_->ads_shown_history;
}

void Client::UpdateAdUUID() {
  if (!client_state_->ad_uuid.empty()) {
    return;
  }

  client_state_->ad_uuid = ads_client_->GenerateUUID();
}

void Client::UpdateAdsUUIDSeen(
    const std::string& uuid,
    const uint64_t value) {
  client_state_->ads_uuid_seen.insert({uuid, value});
}

const std::map<std::string, uint64_t> Client::GetAdsUUIDSeen() {
  return client_state_->ads_uuid_seen;
}

void Client::ResetAdsUUIDSeen(
    const std::vector<AdInfo>& ads) {
  LOG(INFO) << "Resetting seen ads";

  for (const auto& ad : ads) {
    auto ad_uuid_seen = client_state_->ads_uuid_seen.find(ad.uuid);
    if (ad_uuid_seen != client_state_->ads_uuid_seen.end()) {
      client_state_->ads_uuid_seen.erase(ad_uuid_seen);
    }
  }
}

void Client::SetAvailable(const bool available) {
  client_state_->available = available;
}

bool Client::GetAvailable() const {
  return client_state_->available;
}

void Client::SetExpired(const bool expired) {
  client_state_->expired = expired;
}

bool Client::GetExpired() const {
  return client_state_->expired;
}

void Client::SetCurrentSSID(const std::string& ssid) {
  client_state_->current_ssid = ssid;
}

void Client::FlagShoppingState(
    const std::string& url,
    const uint64_t score) {
  client_state_->shop_activity = true;
  client_state_->shop_url = url;
  client_state_->score = score;

  client_state_->last_shop_time = helper::Time::Now();
}

void Client::UnflagShoppingState() {
  client_state_->shop_activity = false;
}

bool Client::GetShoppingState() {
  return client_state_->shop_activity;
}

void Client::FlagSearchState(
    const std::string& url,
    const uint64_t score) {
  client_state_->search_activity = true;
  client_state_->search_url = url;
  client_state_->score = score;

  client_state_->last_search_time = helper::Time::Now();
}

void Client::UnflagSearchState(const std::string& url) {
  if (client_state_->search_url == url) {
    return;
  }

  client_state_->search_activity = false;

  client_state_->last_search_time = helper::Time::Now();
}

bool Client::GetSearchState() {
  return client_state_->search_activity;
}

void Client::UpdateLastUserActivity() {
  client_state_->last_user_activity = helper::Time::Now();
}

uint64_t Client::GetLastUserActivity() {
  return client_state_->last_user_activity;
}

void Client::UpdateLastUserIdleStopTime() {
  client_state_->last_user_idle_stop_time = helper::Time::Now();
}

void Client::SetLocale(const std::string& locale) {
  client_state_->locale = locale;
}

const std::string Client::GetLocale() {
  return client_state_->locale;
}

void Client::SetLocales(const std::vector<std::string>& locales) {
  client_state_->locales = locales;
}

const std::vector<std::string> Client::GetLocales() {
  return client_state_->locales;
}

void Client::AppendPageScoreToPageScoreHistory(
    const std::vector<double>& page_scores) {
  client_state_->page_score_history.push_front(page_scores);
  if (client_state_->page_score_history.size() >
      kMaximumEntriesInPageScoreHistory) {
    client_state_->page_score_history.pop_back();
  }
}

const std::deque<std::vector<double>> Client::GetPageScoreHistory() {
  return client_state_->page_score_history;
}

const std::string Client::GetCurrentPlace() {
  auto place = client_state_->places.find(client_state_->current_ssid);
  if (place != client_state_->places.end()) {
    return place->second;
  } else {
    return kUndisclosedPlace;
  }
}

void Client::RemoveAllHistory() {
  client_state_.reset(new ClientState());
}

///////////////////////////////////////////////////////////////////////////////

void Client::OnStateSaved(const Result result) {
  if (result == FAILED) {
    LOG(ERROR) << "Failed to save client state";

    ads_client_->OnError(CLIENT_STATE_FAILED_TO_SAVE);

    return;
  }

  LOG(INFO) << "Successfully saved client state";
}

void Client::OnStateLoaded(const Result result, const std::string& json) {
  if (result == FAILED) {
    LOG(ERROR) << "Failed to load client state";

    LOG(INFO) << "Resetting client state";
    client_state_.reset(new ClientState());
  } else {
    if (!FromJson(json)) {
      LOG(ERROR) << "Failed to parse client state: " << json;

      return;
    }

    LOG(INFO) << "Successfully loaded client state";
  }

  ads_->InitializeStep2();
}

bool Client::FromJson(const std::string& json) {
  ClientState state;
  if (!LoadFromJson(state, json)) {
    return false;
  }

  client_state_.reset(new ClientState(state));

  return true;
}

const std::string Client::ToJson() {
  std::string json;
  SaveToJson(*client_state_, json);
  return json;
}

}  // namespace ads
