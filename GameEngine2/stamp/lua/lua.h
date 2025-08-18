//stamp/lua/lua.h

#pragma once
#ifndef STAMP_LUA_LUA_H
#define STAMP_LUA_LUA_H

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


// provides short names for vector types and functions
// #define STAMP_MATH_VECTOR_SHORT_NAMES

// makes all comparison operators prefer equal_aprox
// #define STAMP_MATH_VECTOR_EQUAL_APROX

//optional headers: <iostream> <string>
#include <stamp/define.h>
#ifdef STAMP_LUA_AVAILABLE

#include <stamp/lua/define.h>
#include <stamp/lua/lualib.h>

STAMP_LUA_NAMESPACE_BEGIN

lua_State* InitializeLua();

//all files are run in ./resources/scripts/
// 
//phase 0 preload (library phase)
//		all returned outputs of files are set into package.loaded
//		cannot have duplicate file names
//		runs in parallel since no dependencies
//phase 1 operational
//		files can have same name with newer files having precidence
//phases:
//	0 - preload / library
//	1 - load
void luaS_setphasef(int phase, void(*func)(lua_State* L));
void luaS_runphase(lua_State* L, int phase);

const char* luaS_geterror(lua_State* L, int errorCode);

STAMP_LUA_NAMESPACE_END

#endif
#endif