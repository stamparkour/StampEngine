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

STAMP_GRAPHICS_GL_NAMESPACE_BEGIN

using texture_type_t = GLenum;
namespace texture_type {
	enum : texture_type_t {
		_2D = GL_TEXTURE_2D
	};

	std::string to_string(texture_type_t textureType) {

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

template<typename T>
class RawTexture {
	friend class Texture;
protected:
	RawTexture() {}

	virtual texture_type_t SetTexture(GLuint textureBuffer, GLint level, GLint internalFormat) = 0;
public:
	virtual ~RawTexture() = 0;
	virtual const void* data() = 0;
};

class Texture {
private:
	GLuint textureBuffer = 0;
	texture_type_t textureType = 0;
	texture_format_t textureFormat = 0;

	void InitBuffer() {
		if (textureBuffer != 0) return;
		glGenTextures(1, &textureBuffer);
	}

public:
	Texture(texture_format_t format = texture_format::RGBA) {
		this->textureFormat = format;
		InitBuffer();
	}
	~Texture() {
		Clear();
	}

	GLuint TextureBuffer() {
		return textureBuffer;
	}
	void GenMipmap() {
		glGenerateTextureMipmap(textureBuffer);
	}
	void Bind() {
		glBindTexture(textureType, textureBuffer);
	}
	void Clear() {
		if (textureBuffer == 0) return;
		glDeleteTextures(1, &textureBuffer);
		textureBuffer = 0;
		textureType = 0;
	}

	template<typename T>
	void Set(const RawTexture<T>& tex, size_t mipmapLevel = 0) {
		auto type = tex.SetTexture(0, mipmapLevel, format);
		STAMPASSERT(textureType == 0 || textureType == type, "stamp::graphics::gl::Texture::Set - tex is not same type as current texture");
		tex.SetTexture(textureBuffer, mipmapLevel, format);
		textureType = type;
	}
};



template<typename T>
class RawTexture2d : RawTexture<T> {
	friend class Texture;
public:
	using pixel_type = T;
private:
	size_t width = 0;
	size_t height = 0;
	std::vector<T> buffer{};

	SetTexture(GLuint textureBuffer, GLint level, GLint internalFormat) {
		if(textureBuffer != 0) {
			glBindTexture(texture_type::_2D, textureBuffer);
			glTexImage2D(texture_type::_2D, level, internalFormat, width, height, pixel_type::format, pixel_type::type, data());
		}
		return texture_type::_2D;
	}
public:
	RawTexture() {}
	RawTexture(size_t width, size_t height) {
		buffer = std::vector<T>(width * height);
		this->width = width;
		this->height = height;
	}

	const T* data() {
		return buffer.data();
	}

	size_t Width() { return width; }
	size_t Height() { return height; }

	T& operator[] (size_t x, size_t y) {
		STAMPASSERT(x < width, "stamp::graphics::gl::RawTexture::operator[] - x(" << x << ") is greater than or equal to width: " << width);
		STAMPASSERT(y < height, "stamp::graphics::gl::RawTexture::operator[] - y(" << y << ") is greater than or equal to height: " << height);
		return buffer[x + y * height];
	}

	const T& operator[] (size_t x, size_t y) const {
		STAMPASSERT(x < width, "stamp::graphics::gl::RawTexture::operator[] - x(" << x << ") is greater than or equal to width: " << width);
		STAMPASSERT(y < height, "stamp::graphics::gl::RawTexture::operator[] - y(" << y << ") is greater than or equal to height: " << height);
		return buffer[x + y * height];
	}
};

STAMP_GRAPHICS_GL_NAMESPACE_END
#endif