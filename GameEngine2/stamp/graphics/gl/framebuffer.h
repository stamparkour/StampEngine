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
#include <stamp/noncopyable.h>

STAMP_GRAPHICS_GL_NAMESPACE_BEGIN


using clear_bitfield_t = uint32_t;
namespace clear_bitfield {
	enum : clear_bitfield_t {
		Color = GL_COLOR_BUFFER_BIT,
		Depth = GL_DEPTH_BUFFER_BIT,
		Stencil = GL_STENCIL_BUFFER_BIT,
	};
}

class IFrameBuffer : STAMP_NAMESPACE::INonCopyable {
protected:
	GLuint frameBuffer = 0;
	std::vector<GLenum> attachments{};

	void InitBuffer() {
		if (frameBuffer != 0) return;
		glCreateFramebuffers(1, &frameBuffer);
	}
	void DeleteBuffer() {
		if (frameBuffer == 0) return;
		glDeleteFramebuffers(1, &frameBuffer);
		frameBuffer = 0;
	}

	virtual void BindReadRaw() {
		glBindFramebuffer(GL_READ_FRAMEBUFFER, frameBuffer);		
	}
	virtual void BindDrawRaw() {
		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, frameBuffer);
	}
public:
	virtual ~IFrameBuffer() = 0;

	void BindRead(uint32_t colorAttachmentIndex = 0) {
		BindReadRaw();
		glReadBuffer(colorAttachmentIndex + GL_COLOR_ATTACHMENT0);
	}
	template<STAMP_NAMESPACE::forward_iterator_derefrence_to<uint32_t> Iter>
	void BindDraw(Iter begin, Iter end) {
		std::vector<GLenum> binds{};
		binds.reserve(std::distance(begin, end));
		for (auto i = begin; i != end; i++) {
			binds.push_back(*i + GL_COLOR_ATTACHMENT0);
		}
		BindDrawRaw();
		glDrawBuffer(binds.size(), binds.data());
	}
	void BindDraw() {
		BindDrawRaw();
		glDrawBuffers(attachments.size(), attachments.data());
	}
	GLuint InternalFrameBuffer() const {
		return frameBuffer;
	}
	void Clear(clear_bitfield_t clear = clear_bitfield::Color) {
		BindDraw();
		glClear(clear);
	}
	void ClearColor(uint32_t colorAttachmentIndex = 0, const STAMP_GRAPHICS_NAMESPACE::ColorRGBA<GLfloat>& color = {0.5f,0.5f,0.5f,1}) {
		BindDrawRaw();
		glDrawBuffers(frameBuffer, 1, &colorAttachmentIndex);
		glClearBufferfv(GL_COLOR, 0, color.V);
	}
	void ClearDepth(GLfloat depth = 0) {
		BindDrawRaw();
		glClearBufferfv(GL_DEPTH, 0, &depth);
	}
	void ClearStencil(GLint stencil = 0) {
		BindDrawRaw();
		glClearBufferiv(GL_STENCIL, 0, &stencil);
	}

};

class FrameBuffer {

};

STAMP_GRAPHICS_GL_NAMESPACE_END

#endif