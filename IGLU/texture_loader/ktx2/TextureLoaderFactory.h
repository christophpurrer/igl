/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <IGLU/texture_loader/ktx/TextureLoaderFactory.h>

namespace iglu::textureloader::ktx2 {

/**
 * @brief ITextureLoaderFactory implementation for KTX v2 texture containers
 * @note Texture container format specifications:
 *   https://registry.khronos.org/KTX/specs/2.0/ktxspec.v2.html
 */
class TextureLoaderFactory final : public ktx::TextureLoaderFactory {
 public:
  explicit TextureLoaderFactory() noexcept = default;

  [[nodiscard]] uint32_t headerLength() const noexcept final;

 private:
  [[nodiscard]] bool canCreateInternal(DataReader headerReader,
                                       igl::Result* IGL_NULLABLE outResult) const noexcept final;

  [[nodiscard]] igl::TextureRangeDesc textureRange(DataReader reader) const noexcept final;

  [[nodiscard]] bool validate(DataReader reader,
                              const igl::TextureRangeDesc& range,
                              igl::Result* IGL_NULLABLE outResult) const noexcept final;

  [[nodiscard]] igl::TextureFormat textureFormat(const ktxTexture* texture) const noexcept final;
};

} // namespace iglu::textureloader::ktx2
