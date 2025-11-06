//stamp/graphics/gl/mesh.h

#pragma once
#ifndef STAMP_GRAPHICS_GL_MESH_H
#define STAMP_GRAPHICS_GL_MESH_H

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


#include <cstdint>
#include <stamp/graphics/gl/define.h>

STAMP_GRAPHICS_GL_NAMESPACE_BEGIN

class pixel_rgba8 {
	uint8_t r = 0, g = 0, b = 0, a = 0;
public:
	static constexpr GLenum format = GL_RGBA;
	static constexpr GLenum type = GL_UNSIGNED_BYTE;

	pixel_rgba8() {}
	pixel_rgba8(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0, uint8_t a = 0) : r(r), g(g), b(b), a(a) {}

	uint8_t red() const { return r; }
	uint8_t green() const { return g; }
	uint8_t blue() const { return b; }
	uint8_t alpha() const { return a; }

	void red(uint8_t v) { r = v; }
	void green(uint8_t v) { g = v; }
	void blue(uint8_t v) { b = v; }
	void alpha(uint8_t v) { a = v; }
};

STAMP_GRAPHICS_GL_NAMESPACE_END
#endif