/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BAT_ADS_INTERNAL_ML_TOOLS_PIPELINE_STATIC_VALUES_H_  // NOLINT
#define BAT_ADS_INTERNAL_ML_TOOLS_PIPELINE_STATIC_VALUES_H_  // NOLINT

namespace ads {
namespace ml_tools {

static const int kMinimumWordsToClassify = 20;
static const int kMaximumWordsToClassify = 1234;
static const int kMaximumHtmlLengthToClassify = 1024 * 1024;
static const int kMaxSubLen = 6; 
static const int kNumBuckets = 10000;

}  // namespace ml_tools
}  // namespace ads

#endif  // BAT_ADS_INTERNAL_ML_TOOLS_PIPELINE_STATIC_VALUES_H_  // NOLINT
