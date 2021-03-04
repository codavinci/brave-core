// Copyright (c) 2020 The Brave Authors. All rights reserved.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this file,
// you can obtain one at http://mozilla.org/MPL/2.0/.

#include "brave/components/brave_shields/common/features.h"

#include "base/feature_list.h"

namespace brave_shields {
namespace features {

const base::Feature kBraveAdblockCosmeticFiltering{
    "BraveAdblockCosmeticFiltering",
    base::FEATURE_ENABLED_BY_DEFAULT};
// When enabled, Brave will block domains listed in the user's selected adblock
// filters and present a security interstitial with choice to proceed and
// optionally whitelist the domain.
// Domain block filters look like this:
// ||ads.example.com^
const base::Feature kBraveDomainBlock{"BraveDomainBlock",
                                      base::FEATURE_ENABLED_BY_DEFAULT};

}  // namespace features
}  // namespace brave_shields
