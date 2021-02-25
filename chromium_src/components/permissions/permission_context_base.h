/* Copyright (c) 2021 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_CHROMIUM_SRC_COMPONENTS_PERMISSIONS_PERMISSION_CONTEXT_BASE_H_
#define BRAVE_CHROMIUM_SRC_COMPONENTS_PERMISSIONS_PERMISSION_CONTEXT_BASE_H_

namespace permissions {
class PermissionContextBase;
}

#define PermissionContextBase PermissionContextBase_ChromiumImpl
#define PermissionDecided virtual PermissionDecided
#include "../../../../components/permissions/permission_context_base.h"
#undef PermissionDecided
#undef PermissionContextBase

namespace permissions {
class PermissionLifetimeManager;

class PermissionContextBase : public PermissionContextBase_ChromiumImpl {
 public:
  using PermissionContextBase_ChromiumImpl::PermissionContextBase_ChromiumImpl;

  void PermissionDecided(const PermissionRequestID& id,
                         const GURL& requesting_origin,
                         const GURL& embedding_origin,
                         BrowserPermissionCallback callback,
                         ContentSetting content_setting,
                         bool is_one_time) override;

  void SetPermissionLifetimeManager(
      PermissionLifetimeManager* lifetime_manager);

 private:
  PermissionLifetimeManager* permission_lifetime_manager_ = nullptr;
};

}  // namespace permissions

#endif  // BRAVE_CHROMIUM_SRC_COMPONENTS_PERMISSIONS_PERMISSION_CONTEXT_BASE_H_
