/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BAT_ADS_INTERNAL_TIME_FORMATTING_UTIL_H_
#define BAT_ADS_INTERNAL_TIME_FORMATTING_UTIL_H_

#include <stdint.h>

#include <string>

#include "base/time/time.h"

namespace ads {

std::string LongFriendlyDateAndTime(
    const base::Time& time,
    const bool use_sentence_style = true);

std::string FriendlyDateAndTime(
    const base::Time& time,
    const bool use_sentence_style = true);

std::string FriendlyDateAndTime(
    const int64_t timestamp,
    const bool use_sentence_style = true);

std::string TimeToISO8601(
    const base::Time& time);

std::string TimestampToISO8601(
    const int64_t timestamp);

std::string TimeAsTimestampString(
    const base::Time& time);

}  // namespace ads

#endif  // BAT_ADS_INTERNAL_TIME_FORMATTING_UTIL_H_
