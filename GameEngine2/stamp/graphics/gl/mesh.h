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
#include <utility>
#include <vector>
#include <iterator>
#include <algorithm>

#include <stamp/graphics/gl/define.h>

#include <stamp/core/memory.h>
#include <stamp/core/noncopyable.h>
#include <stamp/math/vector.h>
#include <stamp/math/matrix.h>
#include <stamp/graphics/color.h>
#include <stamp/debug.h>

STAMP_GRAPHICS_GL_NAMESPACE_BEGIN

using vertex_type_bitmask_t = size_t;
namespace vertex_type_bitmask {
	enum : vertex_type_bitmask_t {
		Position =	1 << STAMPGL_VERTEX_POSITION,
		Color =		1 << STAMPGL_VERTEX_COLOR,
		UV =		1 << STAMPGL_VERTEX_UV,
		Normal =	1 << STAMPGL_VERTEX_NORMAL,
		Tangent =	1 << STAMPGL_VERTEX_TANGENT, //x axis on uv
		Bitangent =	1 << STAMPGL_VERTEX_BITANGENT, //y axis on uv
	};
}

using storage_hint_t = GLenum;
namespace storage_hint {
	enum : storage_hint_t {
		StaticDraw =	GL_STATIC_DRAW,
		StaticRead =	GL_STATIC_READ,
		StaticCopy =	GL_STATIC_COPY,
		DynamicDraw =	GL_DYNAMIC_DRAW,
		DynamicRead =	GL_DYNAMIC_READ,
		DynamicCopy =	GL_DYNAMIC_COPY,
		StreamDraw =	GL_STREAM_DRAW,
		StreamRead =	GL_STREAM_READ,
		StreamCopy =	GL_STREAM_COPY,
	};
}

using render_mode_t = GLenum;
namespace render_mode {
	enum : render_mode_t {
		Triangles = GL_TRIANGLES,
	};
}

struct Vertex {
	STAMP_MATH_NAMESPACE::Vector3f position;
	STAMP_GRAPHICS_NAMESPACE::ColorRGBA<uint8_t> color;
	STAMP_MATH_NAMESPACE::Vector2f uv;
	STAMP_MATH_NAMESPACE::Vector3f normal;
	STAMP_MATH_NAMESPACE::Vector3f tangent;
	STAMP_MATH_NAMESPACE::Vector3f bitangent;

	inline static void InitializeVertexBuffer(vertex_type_bitmask_t type) {
		if (type & vertex_type_bitmask::Position)	glVertexAttribPointer(STAMPGL_VERTEX_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
		if (type & vertex_type_bitmask::Color)		glVertexAttribPointer(STAMPGL_VERTEX_COLOR, 4, GL_UNSIGNED_BYTE, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
		if (type & vertex_type_bitmask::UV)			glVertexAttribPointer(STAMPGL_VERTEX_UV, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));
		if (type & vertex_type_bitmask::Normal)		glVertexAttribPointer(STAMPGL_VERTEX_NORMAL, 3, GL_FLOAT, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
		if (type & vertex_type_bitmask::Tangent)	glVertexAttribPointer(STAMPGL_VERTEX_TANGENT, 3, GL_FLOAT, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, tangent));
		if (type & vertex_type_bitmask::Bitangent)	glVertexAttribPointer(STAMPGL_VERTEX_BITANGENT, 3, GL_FLOAT, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, bitangent));
	}

	void ApplyTransform(const STAMP_MATH_NAMESPACE::Matrix4f& mat) {
		position = static_cast<STAMP_MATH_NAMESPACE::Vector3f>(mat * STAMP_MATH_NAMESPACE::Vector4f(position, 1));
		normal = static_cast<STAMP_MATH_NAMESPACE::Vector3f>(mat * STAMP_MATH_NAMESPACE::Vector4f(normal, 0));
		tangent = static_cast<STAMP_MATH_NAMESPACE::Vector3f>(mat * STAMP_MATH_NAMESPACE::Vector4f(tangent, 0));
		bitangent = static_cast<STAMP_MATH_NAMESPACE::Vector3f>(mat * STAMP_MATH_NAMESPACE::Vector4f(bitangent, 0));
	}
};



class Mesh : STAMP_CORE_NAMESPACE::INonCopyable, public STAMP_CORE_NAMESPACE::enable_threadsafe_from_this<Mesh> {
private:
	GLuint vertexAttribBuffer = 0;
	GLuint vertexBuffer = 0;
	int vertexCount = 0;
	render_mode_t renderMode = render_mode::Triangles;

	void InitBuffer() {
		if (vertexBuffer == 0) glCreateBuffers(1, &vertexBuffer);
		if (vertexAttribBuffer == 0) glGenVertexArrays(1, &vertexAttribBuffer);
	}

public:	
	Mesh() {}
	~Mesh() {
		if (vertexBuffer != 0) glDeleteBuffers(1, &vertexBuffer);
		if (vertexAttribBuffer != 0) glDeleteVertexArrays(1, &vertexAttribBuffer);
		vertexBuffer = 0;
		vertexAttribBuffer = 0;
	}

	void Bind() {
		if (vertexAttribBuffer == 0) return;
		glBindVertexArray(vertexAttribBuffer);
	}
	GLuint VertexBuffer() const {
		return vertexBuffer;
	}
	GLuint VertexArray() const {
		return vertexAttribBuffer;
	}
	render_mode_t RenderMode() const {
		return renderMode;
	}
	int VertexCount() const {
		return vertexCount;
	}

	template<std::forward_iterator Iter>
	void SetVertices(Iter begin, Iter end, storage_hint_t hint = storage_hint::StaticDraw) {
		std::vector<std::iter_value_t<Iter>> vector{};
		for (auto it = begin; it != end; it++) vector.push_back(*it);
		SetVertices(std::begin(vector), std::end(vector), hint);
	}
	template<std::contiguous_iterator Iter>
	void SetVertices(Iter begin, Iter end, storage_hint_t hint = storage_hint::StaticDraw) {
		using vertex_type = std::iter_value_t<Iter>;

		InitBuffer();

		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		glBufferData(GL_ARRAY_BUFFER, end - begin, begin, hint);
		glBindVertexArray(vertexAttribBuffer);
		vertex_type::InitializeVertexBuffer(~0);
		vertexCount = static_cast<int>(end - begin);
	}
};

namespace proto_mesh {
	inline const Vertex quadVertices[] = {
		//bottom left
		Vertex{{-1,-1,0},{1,1,1,1},{0,0},{0,0,-1},{0,0,1},{0,1,0}},
		//top left
		Vertex{{-1,1,0},{1,1,1,1},{0,1},{0,0,-1},{0,0,1},{0,1,0}},
		//top right
		Vertex{{1,1,0},{1,1,1,1},{1,1},{0,0,-1},{0,0,1},{0,1,0}},
		//bottom left
		Vertex{{-1,-1,0},{1,1,1,1},{0,0},{0,0,-1},{0,0,1},{0,1,0}},
		//top right
		Vertex{{1,1,0},{1,1,1,1},{1,1},{0,0,-1},{0,0,1},{0,1,0}},
		//bottom right
		Vertex{{1,-1,0},{1,1,1,1},{1,0},{0,0,-1},{0,0,1},{0,1,0}},
	};

	inline std::shared_ptr<Mesh> Quad() {
		static std::weak_ptr<Mesh> mesh{};
		if (!mesh.expired()) return mesh.lock();
		auto m = std::make_shared<Mesh>();
		m->SetVertices(std::begin(quadVertices), std::end(quadVertices));
		mesh = m;
		return m;
	}
}

STAMP_GRAPHICS_GL_NAMESPACE_END
#endif