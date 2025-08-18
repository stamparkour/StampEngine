//stamp/lua/lualib.h

#pragma once
#ifndef STAMP_LUA_LUALIB_H
#define STAMP_LUA_LUALIB_H

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

//returns the instance id of the object at index.
int luaS_instance(lua_State* L, int index);
//returns the type of the id.
const char* luaS_instancename(lua_State* L, int id);

int luaS_getmaxmetaobjectid(lua_State* L);
// returns the id of the new metaobject, pushes new table onto stack
int luaS_newmetaobject(lua_State* L, const char* name);
// pushes the metaobject at id onto the stack, return 1 or 0 if it exists or not
int luaS_pushmetaobject(lua_State* L, int id);
// pushes the metaobject at id onto the stack, return 1 or 0 if it exists or not
int luaS_pushmetaobject(lua_State* L, const char* name);

void* luaS_testuobject(lua_State* L, int arg, int id);
void* luaS_checkuobject(lua_State* L, int arg, int id);

//returns 1 if the object is a table, or userdata and has a metatable with __index
int luaS_isindexable(lua_State* L, int index);


#define STAMP_LUA_LIBNAME "stamp"

#define STAMP_LUA_VECTOR2NAME "Vector2"
int luaS_vector2id(lua_State* L);
int luaopen_vector2(lua_State* L);
#define STAMP_LUA_VECTOR3NAME "Vector3"
int luaS_vector3id(lua_State* L);
int luaopen_vector3(lua_State* L);
#define STAMP_LUA_VECTOR4NAME "Vector4"
int luaS_vector4id(lua_State* L);
int luaopen_vector4(lua_State* L);
#define STAMP_LUA_KEYBOARD "HID"
int luaS_hidid(lua_State* L);
int luaopen_hid(lua_State* L);

void lua_stampOpenBasicFunctions(lua_State* L);
void luaS_openstamplibs(lua_State* L);

STAMP_LUA_NAMESPACE_END

#endif
#endif