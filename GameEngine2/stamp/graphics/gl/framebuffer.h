//stamp/graphics/gl/framebuffer.h

#pragma once
#ifndef STAMP_GRAPHICS_GL_FRAMEBUFFER_H
#define STAMP_GRAPHICS_GL_FRAMEBUFFER_H

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


#include <stdint.h>
#include <utility>
#include <vector>
#include <iterator>
#include <algorithm>

#include <stamp/graphics/gl/define.h>
#include <stamp/graphics/gl/texture.h>
#include <stamp/graphics/color.h>
#include <stamp/core/noncopyable.h>

STAMP_GRAPHICS_GL_NAMESPACE_BEGIN


using clear_bitfield_t = uint32_t;
namespace clear_bitfield {
	enum : clear_bitfield_t {
		Color = GL_COLOR_BUFFER_BIT,
		Depth = GL_DEPTH_BUFFER_BIT,
		Stencil = GL_STENCIL_BUFFER_BIT,
	};
}

class FrameBuffer : STAMP_CORE_NAMESPACE::INonCopyable {
protected:
	GLuint frameBuffer = 0;
	std::vector<STAMP_CORE_NAMESPACE::threadsafe_ptr<Texture>> textures{};
	STAMP_CORE_NAMESPACE::threadsafe_ptr<Texture> depthTexture = nullptr;

	void InitBuffer() {
		if (frameBuffer != 0) return;
		glCreateFramebuffers(1, &frameBuffer);
	}
	void DeleteBuffer() {
		if (frameBuffer == 0) return;
		glDeleteFramebuffers(1, &frameBuffer);
		frameBuffer = 0;
	}
public:
	FrameBuffer() {
		InitBuffer();
	}
	~FrameBuffer() {
		DeleteBuffer();
	}

	STAMP_CORE_NAMESPACE::threadsafe_ptr<Texture> Attachment(int attachment, const STAMP_MATH_NAMESPACE::Vector2ui& size, texture_format_t format = texture_format::RGBA) {
		if (format == 0) {
			if (textures.size() > attachment) {
				textures[attachment] = nullptr;
			}
			return nullptr;
		}
		
		Texture tex{ format, size.x, size.y };
		tex.Set(ClearTexture2d(pixel_rgba8{ 0,0,0, 1 }), 0);
		if (textures.size() <= attachment) textures.resize(attachment + 1);
		// this is because i want to have a previous reference to the texture reference the new texture
		if (textures[attachment] == nullptr) textures[attachment] = STAMP_CORE_NAMESPACE::make_threadsafe<Texture>(std::move(tex));
		else *textures[attachment].get_unsafe() = std::move(tex);

		glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + attachment, GL_TEXTURE_2D, tex.InternalTextureBuffer(), 0);
		return textures[attachment];
	}
	STAMP_CORE_NAMESPACE::threadsafe_ptr<Texture> AttachmentDepth(const STAMP_MATH_NAMESPACE::Vector2ui& size = { 256,256 }, texture_format_t format = texture_format::Depth32F) {
		Texture tex = { format, size.x, size.y };
		tex.Set(ClearTexture2d(pixel_r32f{ 0 }), 0);
		if (depthTexture == nullptr) depthTexture = STAMP_CORE_NAMESPACE::make_threadsafe<Texture>(std::move(tex));
		else *depthTexture.get_unsafe() = std::move(tex);

		glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, tex.InternalTextureBuffer(), 0);
		return depthTexture;
	}
	STAMP_CORE_NAMESPACE::threadsafe_ptr<Texture> Attachment(int attachment) const {
		if (textures.size() <= attachment || !textures[attachment]) {
			return nullptr;
		}
		return textures[attachment];
	}
	STAMP_CORE_NAMESPACE::threadsafe_ptr<Texture> AttachmentDepth() const {
		return depthTexture;
	}

	void RemoveAttachment(int attachment) {
		Attachment(attachment, {}, 0);
	}

	/*void BindRead(uint32_t colorAttachmentIndex = 0) {
		glBindFramebuffer(GL_READ_FRAMEBUFFER, frameBuffer);
		glReadBuffer(colorAttachmentIndex + GL_COLOR_ATTACHMENT0);
	}*/
	template<STAMP_NAMESPACE::forward_iterator_derefrence_to<uint32_t> Iter>
	void Bind(Iter begin, Iter end) {
		std::vector<GLenum> binds{};
		for (auto i = begin; i != end; i++) {
			binds.push_back(*i + GL_COLOR_ATTACHMENT0);
		}
		glNamedFramebufferDrawBuffers(frameBuffer, binds.size(), binds.data());
	}
	void Bind() {
		std::vector<GLenum> binds{};
		binds.reserve(textures.size());
		int i = 0;
		for (auto& k : textures) {
			binds.push_back(i + GL_COLOR_ATTACHMENT0);
			i++;
		}
		glNamedFramebufferDrawBuffers(frameBuffer, binds.size(), binds.data());
	}
	GLuint InternalFrameBuffer() const {
		return frameBuffer;
	}
	void Clear(clear_bitfield_t clear = clear_bitfield::Color) {
		Bind();
		glClear(clear);
	}
	void ClearColor(uint32_t colorAttachmentIndex = 0, const STAMP_GRAPHICS_NAMESPACE::ColorRGBA<GLfloat>& color = {0.5f,0.5f,0.5f,1}) {
		glClearNamedFramebufferfv(frameBuffer, GL_COLOR, colorAttachmentIndex, (GLfloat*)color.V);
	}
	void ClearColor(uint32_t colorAttachmentIndex = 0, const STAMP_GRAPHICS_NAMESPACE::ColorRGBA<GLint>& color = { 1,1,1,1 }) {
		glClearNamedFramebufferiv(frameBuffer, GL_COLOR, 0, (GLint*)color.V);
	}
	void ClearDepth(GLfloat depth = 0) {
		glClearNamedFramebufferfv(frameBuffer, GL_DEPTH, 0, &depth);
	}
	void ClearStencil(GLint stencil = 0) {
		glClearNamedFramebufferiv(frameBuffer, GL_STENCIL, 0, &stencil);
	}

};

STAMP_GRAPHICS_GL_NAMESPACE_END

#endif