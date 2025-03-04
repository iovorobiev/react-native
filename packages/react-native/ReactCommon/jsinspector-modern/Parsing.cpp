/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <folly/dynamic.h>
#include <folly/json.h>
#include <jsinspector-modern/Parsing.h>

namespace facebook::react::jsinspector_modern::cdp {

PreparsedRequest preparse(std::string_view message) {
  folly::dynamic parsed = folly::parseJson(message);
  return PreparsedRequest{
      .id = parsed["id"].getInt(),
      .method = parsed["method"].getString(),
      .params = parsed.count("params") ? parsed["params"] : nullptr};
}

} // namespace facebook::react::jsinspector_modern::cdp
