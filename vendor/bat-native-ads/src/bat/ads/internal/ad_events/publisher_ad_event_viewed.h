/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BAT_ADS_INTERNAL_AD_EVENTS_PUBLISHER_AD_EVENT_VIEWED_H_
#define BAT_ADS_INTERNAL_AD_EVENTS_PUBLISHER_AD_EVENT_VIEWED_H_

#include <string>

#include "bat/ads/internal/ad_events/ad_event.h"

namespace ads {

class AdsImpl;
struct PublisherAdInfo;

class PublisherAdEventViewed : public AdEvent<PublisherAdInfo> {
 public:
  PublisherAdEventViewed(
      AdsImpl* ads);

  ~PublisherAdEventViewed() override;

  void Trigger(
      const PublisherAdInfo& info) override;

 private:
  void OnFlagPublisherAdWasPreCached(
      const std::string& creative_instance_id,
      const bool was_cached);

  AdsImpl* ads_;  // NOT OWNED
};

}  // namespace ads

#endif  // BAT_ADS_INTERNAL_AD_EVENTS_PUBLISHER_AD_EVENT_VIEWED_H_
