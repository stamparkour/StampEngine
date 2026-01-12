//stamp/engine/displayscene.h

#pragma once
#ifndef STAMP_ENGINE_DISPLAYSCENE_H
#define STAMP_ENGINE_DISPLAYSCENE_H

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


#include <stamp/engine/define.h>
#include <stamp/engine/module.h>
#include <stamp/core/memory.h>
#include <stamp/graphics/window.h>
#include <stamp/math/rect.h>
#include <stamp/graphics/gl/mesh.h>
#include <stamp/graphics/gl/shader.h>
#include <stamp/graphics/gl/material.h>
#include <stamp/graphics/gl/framebuffer.h>
#include <stamp/stamp.h>
#include <atomic>

STAMP_ENGINE_NAMESPACE_BEGIN

inline const char* WindowScene_shader = R"(
#version 460
#include <stampdefaults>

layout(binding=0) uniform sampler2d tex1;
layout(binding=1) uniform vec4 scale;

#ifdef VERTEX_SHADER

in layout(location = 0) vec4 position;
in layout(location = 1) vec2 uvCoord;
out vec2 uv;

void main() {
	uv = uvCoord;
	gl_Position = position * scale;
}

#endif
#ifdef FRAGMENT_SHADER

in vec2 uv;

layout(location=0) out vec4 color;

void main() {
	out_Color = texture(tex1, uv);
}

#endif
)";

class WindowScene : public IModule, STAMP_GRAPHICS_NAMESPACE::IWindowListener, public STAMP_CORE_NAMESPACE::enable_threadsafe_from_this_derived<WindowScene, IModule> {
	virtual void OnWindowResize(const STAMP_MATH_NAMESPACE::recti& newRect) override {
		auto winSize = newRect.Size();
		windowRatio.store(static_cast<float>(winSize.x) / static_cast<float>(winSize.y));
	}
	virtual void OnWindowVisibility(STAMP_GRAPHICS_NAMESPACE::window::visibility_t visibility) override {
		visible = STAMP_GRAPHICS_NAMESPACE::window::visibility::is_shown(visibility);
	}
	virtual void OnWindowDisplay(STAMP_GRAPHICS_NAMESPACE::window::displaymode_t displaymode) override {}
	virtual void OnWindowFocus(bool isFocused) override {}
	virtual void OnWindowClose() override {}
	
	static std::weak_ptr<STAMP_GRAPHICS_GL_NAMESPACE::RenderShaderProgram> shaderProgram_w;

	STAMP_CORE_NAMESPACE::threadsafe_ptr<STAMP_GRAPHICS_NAMESPACE::Window> window;
	std::shared_ptr<STAMP_GRAPHICS_GL_NAMESPACE::Mesh> quad;
	std::shared_ptr<STAMP_GRAPHICS_GL_NAMESPACE::RenderShaderProgram> shaderProgram;
	STAMP_CORE_NAMESPACE::threadsafe_ptr<STAMP_GRAPHICS_GL_NAMESPACE::FrameBuffer> frameBuffer;
	std::atomic_bool visible = true;
	std::atomic<float> windowRatio{};

	void InitFrameBuffer() {
		if (frameBuffer != nullptr) return;
		if (!STAMP_NAMESPACE::IsRenderThread()) {
			auto co = [this]() -> STAMP_CORE_NAMESPACE::coroutine<void> {
				InitFrameBuffer();
			}
			return;
		}
		frameBuffer = STAMP_CORE_NAMESPACE::make_threadsafe<STAMP_GRAPHICS_GL_NAMESPACE::FrameBuffer>();
	}
public:
	WindowScene(STAMP_CORE_NAMESPACE::threadsafe_ptr<STAMP_GRAPHICS_NAMESPACE::Window> window) : window(window) {
		AttachWindowListener(window);
	}

	void Render(int attachment = 0) {
		STAMPASSERT(STAMP_NAMESPACE::IsRenderThread(), "stamp::engine::WindowScene::Render - Render can only be called from the render thread");
		if (!visible) return;

		if (quad == nullptr) {
			quad = STAMP_GRAPHICS_GL_NAMESPACE::proto_mesh::Quad();
		}
		if (!shaderProgram) {
			if (shaderProgram_w.expired()) {
				std::istringstream sstream{ WindowScene_shader };
				shaderProgram = STAMP_GRAPHICS_GL_NAMESPACE::RenderShaderProgram::ParseStream_glsl(sstream, 0);
				shaderProgram_w = shaderProgram;
			}
			else {
				shaderProgram = shaderProgram_w.lock();
			}
		}

		window.get()->BindDisplayContext();
		GLenum buf[] = { GL_FRONT_LEFT };
		glNamedFramebufferDrawBuffers(0, 1, buf);
		shaderProgram->Bind();
		float ratio1, ratio2;

		ratio1 = windowRatio.load();
		{
			auto tex = frameBuffer.get()->Attachment(attachment).get_readonly();
			ratio2 = static_cast<float>(tex->Width()) / static_cast<float>(tex->Height());
			shaderProgram->Uniform(0, *tex);
		}

		if(ratio1 > ratio2)	shaderProgram->Uniform(1, STAMP_MATH_NAMESPACE::vector4f(ratio2 / ratio1, 1.0f, 1.0f, 1.0f));
		else				shaderProgram->Uniform(1, STAMP_MATH_NAMESPACE::vector4f(1.0f, ratio1 / ratio2, 1.0f, 1.0f));

		quad->Bind();

		glEnableVertexArrayAttrib(quad->VertexArray(), STAMPGL_VERTEX_POSITION);
		glEnableVertexArrayAttrib(quad->VertexArray(), STAMPGL_VERTEX_UV);

		glDrawArrays(quad->RenderMode(), 0, quad->VertexCount());
	}
	const STAMP_CORE_NAMESPACE::threadsafe_ptr<STAMP_GRAPHICS_GL_NAMESPACE::FrameBuffer>& FrameBuffer() {
		InitFrameBuffer();
		return frameBuffer;
	}
};

STAMP_ENGINE_NAMESPACE_END

#endif