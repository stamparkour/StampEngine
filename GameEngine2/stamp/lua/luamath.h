//stamp/lua/luamath.h

#pragma once
#ifndef STAMP_LUA_LUAMATH_H
#define STAMP_LUA_LUAMATH_H

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

STAMP_LUA_NAMESPACE_BEGIN

//implement vector2, 3, 4
//quat
//matrix

void Lua_Mathlib(sol::state& lua);



STAMP_LUA_NAMESPACE_END

#endif
#endif
