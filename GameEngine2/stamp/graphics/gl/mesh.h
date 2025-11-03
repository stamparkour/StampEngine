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


#include <stdint.h>
#include <cstddef>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <stamp/graphics/gl/define.h>
#include <stamp/memory.h>
#include <stamp/noncopyable.h>
#include <stamp/math/vector.h>
#include <stamp/math/matrix.h>
#include <stamp/graphics/color.h>
#include <stamp/debug.h>

STAMP_GRAPHICS_GL_NAMESPACE_BEGIN

using storage_hint_t = GLenum;
namespace storage_hint {
	enum {
		StaticDraw = GL_STATIC_DRAW,
		StaticRead = GL_STATIC_READ,
		StaticCopy = GL_STATIC_COPY,
	};
}

struct Vertex {
	STAMP_MATH_NAMESPACE::Vector3f position;
	STAMP_GRAPHICS_NAMESPACE::ColorRGBA<uint8_t> color;
	STAMP_MATH_NAMESPACE::Vector2f uv;
	STAMP_MATH_NAMESPACE::Vector3f normal;
	STAMP_MATH_NAMESPACE::Vector3f tangent;
	STAMP_MATH_NAMESPACE::Vector3f bitangent;

	inline static void InitializeVertexBuffer() {
		glVertexAttribPointer(STAMPGL_VERTEX_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
		glVertexAttribPointer(STAMPGL_VERTEX_COLOR, 4, GL_UNSIGNED_BYTE, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
		glVertexAttribPointer(STAMPGL_VERTEX_UV, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));
		glVertexAttribPointer(STAMPGL_VERTEX_NORMAL, 3, GL_FLOAT, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
		glVertexAttribPointer(STAMPGL_VERTEX_TANGENT, 3, GL_FLOAT, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, tangent));
		glVertexAttribPointer(STAMPGL_VERTEX_BITANGENT, 3, GL_FLOAT, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, bitangent));
	}

	void ApplyTransform(const STAMP_MATH_NAMESPACE::Matrix4f& mat) {
		position = static_cast<STAMP_MATH_NAMESPACE::Vector3f>(mat * STAMP_MATH_NAMESPACE::Vector4f(position, 1));
		normal = static_cast<STAMP_MATH_NAMESPACE::Vector3f>(mat * STAMP_MATH_NAMESPACE::Vector4f(normal, 0));
		tangent = static_cast<STAMP_MATH_NAMESPACE::Vector3f>(mat * STAMP_MATH_NAMESPACE::Vector4f(tangent, 0));
		bitangent = static_cast<STAMP_MATH_NAMESPACE::Vector3f>(mat * STAMP_MATH_NAMESPACE::Vector4f(bitangent, 0));
	}
};

class IMesh : public STAMP_NAMESPACE::enable_threadsafe_from_this<IMesh> {
private:
	GLint vertexBuffer = 0;
public:	
	void Bind() {
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	}

	template<typename V, STAMP_NAMESPACE::forward_iterator_derefrence_to<V> Iter>
	void SetVertices(Iter begin, Iter end, storage_hint_t hint = storage_hint::StaticDraw) {
		std::vector<std::iter_value_t<Iter>> vector{};
		for (auto it = begin; it != end; it++) vector.push_back(*it);
		SetVertices(std::begin(vector), std::end(vector), hint);
	}
	template<typename V, STAMP_NAMESPACE::contiguous_iterator_derefrence_to<V> Iter>
	void SetVertices(Iter begin, Iter end, storage_hint_t hint = storage_hint::StaticDraw) {
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		glBufferData(GL_ARRAY_BUFFER, end - begin, begin, hint);

	}
};

STAMP_GRAPHICS_GL_NAMESPACE_END
#endif