//stamp/graphics/gl/texture.h

#pragma once
#ifndef STAMP_GRAPHICS_GL_TEXTURE_H
#define STAMP_GRAPHICS_GL_TEXTURE_H

// Copyright 2025 Elijah Clark, Stamparkour
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#include <string>
#include <iterator>
#include <algorithm>
#include <stamp/graphics/gl/define.h>
#include <stamp/graphics/gl/pixel.h>
#include <stamp/memory.h>
#include <stamp/noncopyable.h>
#include <stamp/math/vector.h>
#include <stamp/math/matrix.h>
#include <stamp/debug.h>
#include <algorithm>

STAMP_GRAPHICS_GL_NAMESPACE_BEGIN

using texture_type_t = GLenum;
namespace texture_type {
	enum : texture_type_t {
		_2D = GL_TEXTURE_2D
	};

	std::string to_string(texture_type_t textureType) {
		switch (textureType) {
		case _2D: return "Texture2D";
		}
	}
};

using texture_format_t = GLenum;
namespace texture_format {
	enum : texture_format_t {
		Red = GL_RED,
		RG = GL_RG,
		RGB = GL_RGB,
		RGBA = GL_RGBA,
	};
};

class RawTexture;

class Texture {
	friend class TextureBinding;
public:
	struct desc_t {
		GLuint textureBuffer = 0;
		GLint maxMipmapLevel = 0;
		texture_type_t type = 0;
		texture_format_t format = 0;
		size_t width = 0;
		size_t height = 0;
		size_t depth = 0;
		size_t bindingLocation = 0;
	};
private:
	desc_t desc;

	void InitBuffer() {
		if (desc.textureBuffer != 0) return;
		glGenTextures(1, &desc.textureBuffer);
	}

public:
	Texture(texture_format_t format = texture_format::RGBA) {
		desc.format = format;
		InitBuffer();
	}

	~Texture() {
		Clear();
	}

	int Width(size_t mipmapLevel = 0) const {
		return std::max(desc.width >> mipmapLevel, 1ull);
	}
	int Height(size_t mipmapLevel = 0) const {
		return std::max(desc.height >> mipmapLevel, 1ull);
	}
	int Depth(size_t mipmapLevel = 0) const {
		return std::max(desc.depth >> mipmapLevel,1ull);
	}
	int MaxMipmapLevel() {
		return desc.maxMipmapLevel;
	}

	GLuint TextureBuffer() const {
		return desc.textureBuffer;
	}
	texture_type_t Type() const {
		return desc.type;
	}
	size_t Bind(size_t bindingIndex) const {
		return desc.bindingLocation;
	}
	size_t BindingLocation() const {
		return desc.bindingLocation;
	}
	void GenMipmap() {
		glGenerateTextureMipmap(desc.textureBuffer);
	}
	void Clear() {
		if (desc.textureBuffer == 0) return;
		glDeleteTextures(1, &desc.textureBuffer);
		desc.textureBuffer = 0;
		desc.type = 0;
	}

	void Set(RawTexture& tex, size_t mipmapLevel = 0);
};

class RawTexture {
	friend class Texture;
protected:
	RawTexture() {}

	virtual void SetTexture(Texture* tex, Texture::desc_t* buf, size_t mipmap) = 0;
public:
	virtual ~RawTexture() = 0;
	virtual const void* data() = 0;
};

template<typename T>
class RawTexture2d : RawTexture {
public:
	using pixel_type = T;
private:
	size_t width = 0;
	size_t height = 0;
	std::vector<T> buffer{};

	void SetTexture(Texture* tex, Texture::desc_t* buf, size_t mipmap) override {
		if (buf->type == 0) {
			buf->width = width;
			buf->height = height;
			buf->depth = 1;
			buf->type = texture_type::_2D;
			int max = 0;
			for (size_t w = width, h = height; w > 1 || h > 1; w >>= 1, h >>= 1) max++;
			buf->maxMipmapLevel = max + mipmap;
		}
		else {
			STAMPASSERT(buf->type == buf->type, "stamp::graphics::gl::Texture::Set - tex is not same type as current texture: " << texture_type::to_string(buf->type));
			STAMPASSERT(tex->Width(mipmap) == width, "stamp::graphics::gl::Texture::Set - width (" << width << ") must match mipmap (" << mipmap << ") width : " << tex->Width(mipmap));
			STAMPASSERT(tex->Height(mipmap) == height, "stamp::graphics::gl::Texture::Set - height (" << height << ") must match mipmap (" << mipmap << ") height: " << tex->Height(mipmap));
		}

		glBindTexture(buf->type, buf->textureBuffer);
		glTexImage2D(buf->type, mipmap, buf->format, width, height, 0, pixel_type::format, pixel_type::type, buffer.data());
	}

	
public:
	RawTexture2d() {}
	RawTexture2d(size_t width, size_t height) {
		buffer = std::vector<T>(width * height);
		this->width = width;
		this->height = height;

		STAMPASSERT(width != 0, "stamp::graphics::gl::RawTexture2d - width cannot be 0.");
		STAMPASSERT(height != 0, "stamp::graphics::gl::RawTexture2d - height cannot be 0.");
	}

	~RawTexture2d() {}

	const void* data() override {
		return buffer.data();
	}

	size_t Width() { return width; }
	size_t Height() { return height; }

	T& operator[] (size_t x, size_t y) {
		STAMPASSERT(x < width, "stamp::graphics::gl::RawTexture::operator[] - x (" << x << ") is greater than or equal to width: " << width);
		STAMPASSERT(y < height, "stamp::graphics::gl::RawTexture::operator[] - y (" << y << ") is greater than or equal to height: " << height);
		return buffer[x + y * height];
	}

	const T& operator[] (size_t x, size_t y) const {
		STAMPASSERT(x < width, "stamp::graphics::gl::RawTexture::operator[] - x (" << x << ") is greater than or equal to width: " << width);
		STAMPASSERT(y < height, "stamp::graphics::gl::RawTexture::operator[] - y (" << y << ") is greater than or equal to height: " << height);
		return buffer[x + y * height];
	}
};


STAMP_GRAPHICS_GL_NAMESPACE_END
#endif