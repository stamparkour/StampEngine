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

	inline std::string to_string(texture_type_t textureType) {
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

		Depth32F = GL_DEPTH_COMPONENT32F,
	};

	bool IsFormatFloatingPoint(texture_format_t format);
};

class RawTexture;

class Texture {
public:
	struct desc_t {
		GLuint textureBuffer = 0;
		GLint maxMipmapLevel = 0;
		texture_type_t type = 0;
		texture_format_t format = 0;
		size_t width = 0;
		size_t height = 0;
		size_t depth = 0;
		size_t bindingIndex = 0;
	};
private:
	desc_t desc;
	void InitBuffer();
public:
	Texture(texture_format_t format = texture_format::RGBA);
	Texture(texture_format_t format, size_t width, size_t height);
	~Texture();

	int Width(size_t mipmapLevel = 0) const;
	int Height(size_t mipmapLevel = 0) const;
	int Depth(size_t mipmapLevel = 0) const;
	int MaxMipmapLevel();

	GLuint InternalTextureBuffer() const;
	texture_type_t Type() const;
	texture_format_t Format() const;
	void Bind(size_t bindingIndex);
	size_t Binding() const;
	void GenMipmap();
	void Clear();

	void Set(const RawTexture& tex, size_t mipmapLevel = 0);
};

class RawTexture {
	friend class Texture;
protected:
	RawTexture() {}
	virtual void SetTexture(Texture* tex, Texture::desc_t* buf, size_t mipmap) const = 0;
public:
	virtual ~RawTexture() = 0;
	virtual const void* data() = 0;
};

template<typename T>
class ClearTexture2d : public RawTexture {
public:
	using pixel_type = T;
private:
	pixel_type clearColor;
	size_t width = 0;
	size_t height = 0;

	void SetTexture(Texture* tex, Texture::desc_t* buf, size_t mipmap) const override {
		if (width == 0 || height == 0) {
			STAMPASSERT(buf->width != 0 && buf->height != 0, "stamp::graphics::gl::Texture::Set(ClearTexture2d) - texture size should be initialized. Either width or height is currently unitialized");
			width = tex->Width(mipmap);
			height = tex->Height(mipmap);
		}
		else if (buf->width != 0 || buf->height != 0) {
			STAMPASSERT(tex->Width(mipmap) == width, "stamp::graphics::gl::Texture::Set(RawTexture2d) - width (" << width << ") must match mipmap (" << mipmap << ") width : " << tex->Width(mipmap));
			STAMPASSERT(tex->Height(mipmap) == height, "stamp::graphics::gl::Texture::Set(RawTexture2d) - height (" << height << ") must match mipmap (" << mipmap << ") height: " << tex->Height(mipmap));
		}
		if (buf->type == 0) {
			STAMPASSERT(mipmap == 0, "stamp::graphics::gl::Texture::Set(ClearTexture2d) - mipmap level (" << mipmap << ") must be 0 when first setting Texture content.");
			buf->width = width << mipmap;
			buf->height = height << mipmap;
			buf->depth = 1;
			buf->type = texture_type::_2D;

		}
		else {
			STAMPASSERT(buf->type == buf->type, "stamp::graphics::gl::Texture::Set(ClearTexture2d) - tex is not same type as current texture: " << texture_type::to_string(buf->type));
		}

		glBindTexture(buf->type, buf->textureBuffer);
		glTexImage2D(buf->type, mipmap, buf->format, width, height, 0, pixel_type::format, pixel_type::type, nullptr);
		glClearTexImage(buf->textureBuffer, mipmap, pixel_type::format, pixel_type::type, &clearColor);
	}
public:
	ClearTexture2d(pixel_type clearColor) {
		this->clearColor = clearColor;
	}
	ClearTexture2d(pixel_type clearColor, size_t width, size_t height) {
		this->clearColor = clearColor;
		this->width = width;
		this->height = height;
	}
	~ClearTexture2d() {}
	const void* data() override {
		return nullptr;
	}
	size_t Width() { return width; }
	size_t Height() { return height; }
};

template<typename T>
class RawTexture2d : public RawTexture {
public:
	using pixel_type = T;
private:
	size_t width = 0;
	size_t height = 0;
	std::vector<T> buffer{};

	void SetTexture(Texture* tex, Texture::desc_t* buf, size_t mipmap) const override {
		if(buf->width != 0 || buf->height != 0) {
			STAMPASSERT(tex->Width(mipmap) == width, "stamp::graphics::gl::Texture::Set(RawTexture2d) - width (" << width << ") must match mipmap (" << mipmap << ") width : " << tex->Width(mipmap));
			STAMPASSERT(tex->Height(mipmap) == height, "stamp::graphics::gl::Texture::Set(RawTexture2d) - height (" << height << ") must match mipmap (" << mipmap << ") height: " << tex->Height(mipmap));
		}
		if (buf->type == 0) {
			STAMPASSERT(mipmap == 0, "stamp::graphics::gl::Texture::Set(RawTexture2d) - mipmap level (" << mipmap << ") must be 0 when first setting Texture content.");
			buf->width = width << mipmap;
			buf->height = height << mipmap;
			buf->depth = 1;
			buf->type = texture_type::_2D;
		}
		else {
			STAMPASSERT(buf->type == buf->type, "stamp::graphics::gl::Texture::Set(RawTexture2d) - tex is not same type as current texture: " << texture_type::to_string(buf->type));
		}

		glBindTexture(buf->type, buf->textureBuffer);
		glTexImage2D(buf->type, mipmap, buf->format, width, height, 0, pixel_type::format, pixel_type::type, buffer.data());
	}

	
public:
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


//Definitions



STAMP_GRAPHICS_GL_NAMESPACE_END
#endif