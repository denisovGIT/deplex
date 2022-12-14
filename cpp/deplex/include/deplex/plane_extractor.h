/**
 * Copyright 2022 prime-slam
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include <memory>

#include <Eigen/Core>

#include "deplex/config.h"

namespace deplex {
class PlaneExtractor {
 public:
  PlaneExtractor(int32_t image_height, int32_t image_width, config::Config config = kDefaultConfig);
  ~PlaneExtractor();

  Eigen::VectorXi process(Eigen::MatrixXf const& pcd_array);

  PlaneExtractor(PlaneExtractor && op) noexcept;
  PlaneExtractor& operator=(PlaneExtractor && op) noexcept;

  const static config::Config kDefaultConfig;
 private:
  class Impl;
  std::unique_ptr<Impl> impl_;
};
}  // namespace deplex