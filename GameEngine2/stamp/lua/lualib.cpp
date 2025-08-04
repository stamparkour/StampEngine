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

#include <stamp/lua/lualib.h>
#include <stamp/lua/lua.h>

using namespace STAMP_LUA_NAMESPACE;

// 0, 0, e
int STAMP_LUA_NAMESPACE::lua_instance(lua_State* L, int index) {
    // if(type(p1) != "table" and type(p1) != "userdata") then return type(p1) end
    int type = lua_type(L, index);
    if (!lua_isindexable(L, index)) {
        return type;
    }
    // if(getmetatable(p1) == nil) then return "nil" end
    lua_getmetatable(L, index);
    if (!lua_isnil(L, -1)) {
        lua_pop(L, 1);
        return type;
    }
    lua_getfield(L, -1, STAMP_LUA_TYPEID_METATABLEKEY);
    // if(getmetatable(p1).__typeid == nil) then return "nil" end
    if (!lua_isnil(L, -1)) {
        lua_pop(L, 2);
        return type;
    }
    lua_remove(L, -2); // remove the metatable from the stack
    // return getmetatable(p1).__typeid 
    return lua_tointeger(L,-1);
}


int STAMP_LUA_NAMESPACE::luaL_newmetaobject(lua_State* L, const char* name) {
	int id = lua_getmaxmetaobjectid(L);
	lua_pushinteger(L, id + 1); // +1
    lua_setfield(L, LUA_REGISTRYINDEX, STAMP_LUA_TYPEIDMAX_REGISTRYKEY); // -1

	lua_newtable(L);// +1

	lua_pushstring(L, name); // +1
    lua_setfield(L, -2, "__name"); // -1, set the name field in the metatable
    lua_pushinteger(L, id); // +1
    lua_setfield(L, -2, STAMP_LUA_TYPEID_METATABLEKEY); // -1, set the typeid field in the metatable

	lua_getfield(L, LUA_REGISTRYINDEX, STAMP_LUA_TYPEID_REGISTRYKEY);// +1
	lua_pushvalue(L, -2);// +1
    lua_seti(L, -2, id);// -1
	lua_pop(L, 1); // -1, pop the registry table

    lua_getfield(L, LUA_REGISTRYINDEX, STAMP_LUA_CLASSES_REGISTRYKEY);// +1
    lua_pushvalue(L, -2);// +1
    lua_setfield(L, -2, name);// -1
    lua_pop(L, 1); // -1, pop the registry table

    return id;
}
int STAMP_LUA_NAMESPACE::luaL_pushmetaobject(lua_State* L, int id) {
    if (id < STAMP_LUA_MIN_TYPEID || id > lua_getmaxmetaobjectid(L)) {
        return 0;
    }
    lua_getfield(L, LUA_REGISTRYINDEX, STAMP_LUA_TYPEID_REGISTRYKEY); // +1
    lua_geti(L, -1, id); // +1, returns metatable for id
    lua_remove(L, -2);
    return 1;
}
int STAMP_LUA_NAMESPACE::luaL_pushmetaobject(lua_State* L, const char* name) {
    lua_getfield(L, LUA_REGISTRYINDEX, STAMP_LUA_CLASSES_REGISTRYKEY); // +1
    lua_getfield(L, -1, name); // +1, returns metatable for id
    if(lua_isnil(L, -1)) {
        lua_pop(L, 2);
        return 0;
	}
    lua_remove(L, -2);
    return 1;
}
const char* STAMP_LUA_NAMESPACE::lua_instancename(lua_State* L, int id) {
    if (id < LUA_NUMTYPES) return lua_typename(L, id);
    if (id < STAMP_LUA_MIN_TYPEID || id > lua_getmaxmetaobjectid(L)) {
        luaL_error(L, "Invalid instance id: %d", id);
        return nullptr;
    }
    lua_getfield(L, LUA_REGISTRYINDEX, STAMP_LUA_TYPEID_REGISTRYKEY); // +1
    lua_geti(L, -1, id); // +1, returns metatable for id
    lua_getfield(L, -1, "__name");// +1
    auto n = lua_tostring(L, -1);
    lua_pop(L, 3); // pop the registry, the metatable, and the name
    return n;
}
int STAMP_LUA_NAMESPACE::lua_getmaxmetaobjectid(lua_State* L) {
	lua_getfield(L, LUA_REGISTRYINDEX, STAMP_LUA_TYPEIDMAX_REGISTRYKEY);
	int max = luaL_checkinteger(L, -1);
	lua_pop(L, 1);
    return max;
}
int STAMP_LUA_NAMESPACE::lua_isindexable(lua_State* L, int index) {
    int type = lua_type(L, index);
	if(type == LUA_TTABLE) return true;
    if(type != LUA_TUSERDATA) return false;
    // type is userdata
	lua_getmetatable(L, index); // +1
    if (lua_isnil(L, -1)) {
        lua_pop(L, 1);
        return false; // no metatable
    }
    lua_getfield(L, -1, "__index"); // +1
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
        return false; // no __index field
    }
    lua_pop(L, 2); // pop the metatable and the __index field
	return true; // is indexable
}

//-------- LUA BASIC FUNCTIONS --------

// returns object's type as a string
static int luaf_instance(lua_State* L) {
    lua_pushstring(L, lua_instancename(L, lua_instance(L, 1)));
    return 1;
}

void STAMP_LUA_NAMESPACE::lua_stampOpenBasicFunctions(lua_State* L) {
    lua_pushcfunction(L, luaf_instance);
    lua_setglobal(L, "instance");

	lua_pushinteger(L, STAMP_LUA_MIN_TYPEID);
    lua_setfield(L, LUA_REGISTRYINDEX, STAMP_LUA_TYPEIDMAX_REGISTRYKEY);
    lua_newtable(L);
    lua_setfield(L, LUA_REGISTRYINDEX, STAMP_LUA_TYPEID_REGISTRYKEY);
    lua_newtable(L);
    lua_setfield(L, LUA_REGISTRYINDEX, STAMP_LUA_CLASSES_REGISTRYKEY);
}