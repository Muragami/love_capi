/**
 * Copyright (c) 2006-2023 LOVE Development Team
 *
 * This software is provided 'as-is', without any express or implied
 * warranty.  In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 **/

#pragma once

#include "common/config.h"
#include "common/Color.h"
#include "common/int.h"
#include "graphics/Texture.h"
#include "Metal.h"

namespace love
{
namespace graphics
{
namespace metal
{

class Texture final : public love::graphics::Texture
{
public:

	Texture(love::graphics::Graphics *gfx, id<MTLDevice> device, const Settings &settings, const Slices *data);
	virtual ~Texture();

	void copyFromBuffer(love::graphics::Buffer *source, size_t sourceoffset, int sourcewidth, size_t size, int slice, int mipmap, const Rect &rect) override;
	void copyToBuffer(love::graphics::Buffer *dest, int slice, int mipmap, const Rect &rect, size_t destoffset, int destwidth, size_t size) override;

	void setSamplerState(const SamplerState &s) override;

	ptrdiff_t getHandle() const override { return (ptrdiff_t) texture; }
	ptrdiff_t getRenderTargetHandle() const override { return msaaTexture != nil ? (ptrdiff_t) msaaTexture : (ptrdiff_t) texture; }
	ptrdiff_t getSamplerHandle() const override { return (ptrdiff_t) sampler; }

	int getMSAA() const override { return actualMSAASamples; }

	id<MTLSamplerState> getMTLSampler() const { return sampler; }

private:

	void uploadByteData(PixelFormat pixelformat, const void *data, size_t size, int level, int slice, const Rect &r) override;
	void generateMipmapsInternal() override;

	id<MTLTexture> texture;
	id<MTLTexture> msaaTexture;
	id<MTLSamplerState> sampler;

	int actualMSAASamples;

}; // Texture

} // metal
} // graphics
} // love
