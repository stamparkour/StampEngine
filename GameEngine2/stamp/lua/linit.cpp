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


#include <stamp/lua/define.h>
#include <stamp/lua/lualib.h>
#include <stdexcept>

using namespace STAMP_LUA_NAMESPACE;
 
static const luaL_Reg loadedlibs[] = {
  {STAMP_LUA_VECTOR2NAME, luaopen_vector2},
  {NULL, NULL}
};

void STAMP_LUA_NAMESPACE::luaL_openstamplibs(lua_State* L) {
    lua_stampOpenBasicFunctions(L);
    /* "require" functions from 'loadedlibs' and set results to global table */
    for (const luaL_Reg* lib = loadedlibs; lib->func; lib++) {
        luaL_requiref(L, lib->name, lib->func, 1);
        lua_pop(L, 1);  /* remove lib */
    }
}