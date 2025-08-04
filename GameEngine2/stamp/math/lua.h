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


#include <stamp/lua/lua.h>
#include <stamp/math/define.h>
#include <stamp/math/vector.h>
#include <stamp/math/quaternion.h>
#include <stamp/math/matrix.h>
#include <stamp/math/rect.h>


STAMP_LUA_NAMESPACE_BEGIN


using lua_Vector2 = STAMP_MATH_NAMESPACE::Vector<LUA_NUMBER, 2>;
using lua_Vector3 = STAMP_MATH_NAMESPACE::Vector<LUA_NUMBER, 3>;
using lua_Vector4 = STAMP_MATH_NAMESPACE::Vector<LUA_NUMBER, 4>;

bool lua_isvector2(lua_State* L, int index);
bool lua_isvector3(lua_State* L, int index);
bool lua_isvector4(lua_State* L, int index);

lua_Vector2* lua_pushvector2(lua_State* L);
lua_Vector3* lua_pushvector3(lua_State* L);
lua_Vector4* lua_pushvector4(lua_State* L);
lua_Vector2* lua_pushvector2(lua_State* L, const lua_Vector2& v);
lua_Vector3* lua_pushvector3(lua_State* L, const lua_Vector3& v);
lua_Vector4* lua_pushvector4(lua_State* L, const lua_Vector4& v);

lua_Vector2 lua_tovector2x(lua_State* L, int index, int* isvector);
lua_Vector3 lua_tovector3x(lua_State* L, int index, int* isvector);
lua_Vector4 lua_tovector4x(lua_State* L, int index, int* isvector);
lua_Vector2 lua_tovector2(lua_State* L, int index);
lua_Vector3 lua_tovector3(lua_State* L, int index);
lua_Vector4 lua_tovector4(lua_State* L, int index);

lua_Vector2* luaL_checkvector2(lua_State* L, int index);
lua_Vector3* luaL_checkvector3(lua_State* L, int index);
lua_Vector4* luaL_checkvector4(lua_State* L, int index);

STAMP_LUA_NAMESPACE_END
#endif
