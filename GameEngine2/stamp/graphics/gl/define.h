//stamp/graphics/gl/define.h


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


#ifndef STAMP_GRAPHICS_GL_DEFINE_H
#include <utility> 
#include <gl/glew.h>
#endif

#include <stamp/graphics/define.h>

#ifndef STAMP_GRAPHICS_GL_DEFINE_H
#define STAMP_GRAPHICS_GL_DEFINE_H

#define STAMP_GRAPHICS_GL_NAMESPACE					STAMP_GRAPHICS_NAMESPACE::gl
#define STAMP_GRAPHICS_GL_NAMESPACE_BEGIN			namespace STAMP_GRAPHICS_GL_NAMESPACE {
#define STAMP_GRAPHICS_GL_NAMESPACE_END				}

#define STAMPGL_VERTEX_POSITION 0
#define STAMPGL_VERTEX_COLOR 1
#define STAMPGL_VERTEX_UV 2
#define STAMPGL_VERTEX_NORMAL 3
#define STAMPGL_VERTEX_TANGENT 4
#define STAMPGL_VERTEX_BITANGENT 5


STAMP_GRAPHICS_GL_NAMESPACE_BEGIN

bool CheckOpenGLErrors();

inline const char* default_defines[] = {
	"STAMPGL_VERTEX_POSITION " EXPAND_AND_STRINGIFY(STAMPGL_VERTEX_POSITION),
	"STAMPGL_VERTEX_COLOR " EXPAND_AND_STRINGIFY(STAMPGL_VERTEX_COLOR),
	"STAMPGL_VERTEX_UV " EXPAND_AND_STRINGIFY(STAMPGL_VERTEX_UV),
	"STAMPGL_VERTEX_NORMAL " EXPAND_AND_STRINGIFY(STAMPGL_VERTEX_NORMAL),
	"STAMPGL_VERTEX_TANGENT " EXPAND_AND_STRINGIFY(STAMPGL_VERTEX_TANGENT),
	"STAMPGL_VERTEX_BITANGENT " EXPAND_AND_STRINGIFY(STAMPGL_VERTEX_BITANGENT),
};

STAMP_GRAPHICS_GL_NAMESPACE_END

#endif