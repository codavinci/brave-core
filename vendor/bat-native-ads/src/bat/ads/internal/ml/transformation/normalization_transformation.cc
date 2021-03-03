/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include <map>
#include <memory>
#include <string>

#include "bat/ads/internal/ml/data/vector_data.h"
#include "bat/ads/internal/ml/transformation/normalization_transformation.h"

namespace ads {
namespace ml {

NormalizationTransformation::NormalizationTransformation()
    : Transformation(TransformationType::NORMALIZATION) {}

NormalizationTransformation::~NormalizationTransformation() = default;

std::unique_ptr<Data> NormalizationTransformation::Apply(
    const std::unique_ptr<Data>& input_data) const {
  if (input_data->GetType() != DataType::VECTOR_DATA) {
    return std::make_unique<VectorData>(
        VectorData(0, std::map<unsigned, double>()));
  }

  VectorData* vector_data = static_cast<VectorData*>(input_data.get());

  VectorData vector_data_copy = *vector_data;
  vector_data_copy.Normalize();
  return std::make_unique<VectorData>(vector_data_copy);
}

}  // namespace ml
}  // namespace ads