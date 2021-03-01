/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include <algorithm>
#include <memory>
#include <string>

#include "base/strings/string_util.h"
#include "bat/ads/internal/ml/data/text_data.h"
#include "bat/ads/internal/ml/transformation/lowercase.h"

namespace ads {
namespace ml {
namespace transformation {

Lowercase::Lowercase() : Transformation(TransformationType::LOWERCASE) {}

Lowercase::~Lowercase() = default;

std::unique_ptr<Data> Lowercase::Apply(
    const std::unique_ptr<Data>& input_data) {
  if (input_data->GetType() != DataType::TEXT_DATA) {
    return std::make_unique<Data>(TextData(""));
  }

  TextData* text_data = static_cast<TextData*>(input_data.get());

  std::string lowercase_text = base::ToLowerASCII(text_data->GetText());

  return std::make_unique<TextData>(TextData(lowercase_text));
}

}  // namespace transformation
}  // namespace ml
}  // namespace ads
