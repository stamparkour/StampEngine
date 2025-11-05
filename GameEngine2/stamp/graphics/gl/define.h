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
#include <gl/glm.h>
#endif

#include <stamp/define.h>

#ifndef STAMP_GRAPHICS_GL_DEFINE_H
#define STAMP_GRAPHICS_GL_DEFINE_H

#define STAMP_GRAPHICS_GL_NAMESPACE					STAMP_GRAPHICS_NAMESPACE::gl
#define STAMP_GRAPHICS_GL_NAMESPACE_BEGIN			namespace STAMP_GRAPHICS_GL_NAMESPACE {
#define STAMP_GRAPHICS_GL_NAMESPACE_END				}

#define STAMPGL_VERTEX_POSITION 1
#define STAMPGL_VERTEX_COLOR 2
#define STAMPGL_VERTEX_UV 3
#define STAMPGL_VERTEX_NORMAL 4
#define STAMPGL_VERTEX_TANGENT 5
#define STAMPGL_VERTEX_BITANGENT 6

STAMP_GRAPHICS_GL_NAMESPACE_BEGIN

bool checkOpenGLErrors();

STAMP_GRAPHICS_GL_NAMESPACE_END

#endif