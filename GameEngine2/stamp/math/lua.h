//stamp/math/lua.h

#pragma once
#ifndef STAMP_MATH_LUA_H
#define STAMP_MATH_LUA_H

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


#include <stamp/define.h>
#ifdef STAMP_LUA_AVAILABLE
#include <stamp/lua/define.h>

#include <stamp/math/vector.h>
#include <stamp/math/matrix.h>
#include <stamp/math/quaternion.h>

STAMP_LUA_NAMESPACE_BEGIN

//implement vector2, 3, 4
//quat
//matrix

using lua_number_t = LUA_NUMBER;
using lua_Vector2 = STAMP_MATH_NAMESPACE::vector<lua_number_t, 2>;
using lua_Vector3 = STAMP_MATH_NAMESPACE::vector<lua_number_t, 3>;
using lua_Vector4 = STAMP_MATH_NAMESPACE::vector<lua_number_t, 4>;
using lua_Matrix2 = STAMP_MATH_NAMESPACE::Matrix<lua_number_t, 2>;
using lua_Matrix3 = STAMP_MATH_NAMESPACE::Matrix<lua_number_t, 3>;
using lua_Matrix4 = STAMP_MATH_NAMESPACE::Matrix<lua_number_t, 4>;
using lua_Quaternion = STAMP_MATH_NAMESPACE::Quaternion<lua_number_t>;

void Lua_Mathlib(sol::state* lua, sol::table* target);

STAMP_LUA_NAMESPACE_END

#endif
#endif
