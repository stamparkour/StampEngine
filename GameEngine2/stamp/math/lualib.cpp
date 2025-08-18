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

#include <string>
#include <stamp/define.h>
#ifdef STAMP_LUA_AVAILABLE

#include <stamp/lua/lualib.h>
#include <stamp/math/lua.h>

using namespace STAMP_LUA_NAMESPACE;
using namespace STAMP_MATH_NAMESPACE;

namespace luaVector2 {
	static int _new(lua_State* L) {
		int argc = lua_gettop(L);
		auto p = luaS_pushvector2(L);
		//constructor
		if (argc == 1) {
			*p = lua_Vector2();
		}
		else if (argc == 2) {
			if (luaS_isvector2(L, 2)) {
				*p = lua_Vector2(luaS_tovector2(L, 2));
			}
			else {
				LUA_NUMBER x = luaL_checknumber(L, 2);
				*p = lua_Vector2(x);
			}
		}
		else if (argc == 3) {
			LUA_NUMBER x = luaL_checknumber(L, 2);
			LUA_NUMBER y = luaL_checknumber(L, 3);
			*p = lua_Vector2(x, y);
		}

		return 1;
	}
	static int index(lua_State* L) {
		lua_Vector2* v = (lua_Vector2*)luaS_checkuobject(L, 1, luaS_vector2id(L));
		const char* key = luaL_checkstring(L, 2);
		if (strcmp(key, "x") == 0) {
			lua_pushnumber(L, v->x);
			return 1;
		}
		else if (strcmp(key, "y") == 0) {
			lua_pushnumber(L, v->y);
			return 1;
		}
		else {
			return luaL_error(L, "Invalid key '%s' for Vector2", key);
		}
	}
	static int newindex(lua_State* L) {
		lua_Vector2* v = (lua_Vector2*)luaL_checkudata(L, 1, STAMP_LUA_VECTOR2NAME);
		const char* key = luaL_checkstring(L, 2);
		if (strcmp(key, "x") == 0) {
			LUA_NUMBER x = luaL_checknumber(L, 3);
			v->x = x;
			return 0;
		}
		else if (strcmp(key, "y") == 0) {
			LUA_NUMBER y = luaL_checknumber(L, 3);
			v->y = y;
			return 0;
		}
		else {
			return luaL_error(L, "Invalid key '%s' for Vector2", key);
		}
	}
	static int tostring(lua_State* L) {
		auto a = luaS_tovector2(L, 1);
		auto s = to_string(a);
		lua_pushstring(L, s.c_str());
		return 1;
	}
	static int add(lua_State* L) {
		auto a = luaS_tovector2(L, 1);
		auto b = luaS_tovector2(L, 2);
		auto o = a + b;
		luaS_pushvector2(L, o);
		return 1;
	}
	static int sub(lua_State* L) {
		auto a = luaS_tovector2(L, 1);
		auto b = luaS_tovector2(L, 2);
		auto o = a - b;
		luaS_pushvector2(L, o);
		return 1;
	}
	static int mul(lua_State* L) {
		auto a = luaS_tovector2(L, 1);
		auto b = luaS_tovector2(L, 2);
		auto o = a * b;
		luaS_pushvector2(L, o);
		return 1;
	}
	static int div(lua_State* L) {
		auto a = luaS_tovector2(L, 1);
		auto b = luaS_tovector2(L, 2);
		auto o = a / b;
		luaS_pushvector2(L, o);
		return 1;
	}
	static int unm(lua_State* L) {
		auto a = luaS_tovector2(L, 1);
		auto o = -a;
		luaS_pushvector2(L, o);
		return 1;
	}
	static int idiv(lua_State* L) {
		auto a = luaS_tovector2(L, 1);
		auto b = luaS_tovector2(L, 2);
		auto o = a / b;
		o.x = floor(o.x);
		o.y = floor(o.y);
		//o.z = floor(o.z);
		//o.w = floor(o.w);
		luaS_pushvector2(L, o);
		return 1;
	}
	static int band(lua_State* L) {
		auto a = luaS_tovector2(L, 1);
		auto b = luaS_tovector2(L, 2);
		auto o = a && b;
		luaS_pushvector2(L, (lua_Vector2)o);
		return 1;
	}
	static int bor(lua_State* L) {
		auto a = luaS_tovector2(L, 1);
		auto b = luaS_tovector2(L, 2);
		auto o = a || b;
		luaS_pushvector2(L, (lua_Vector2)o);
		return 1;
	}
	static int bxor(lua_State* L) {
		auto a = luaS_tovector2(L, 1);
		auto b = luaS_tovector2(L, 2);
		auto o = a != b;
		luaS_pushvector2(L, (lua_Vector2)o);
		return 1;
	}
	static int bnot(lua_State* L) {
		auto a = luaS_tovector2(L, 1);
		lua_pushboolean(L, !a);
		return 1;
	}
	static int eq(lua_State* L) {
		auto a = luaS_tovector2(L, 1);
		auto b = luaS_tovector2(L, 2);
		auto o = a == b;
		lua_pushboolean(L, (bool)o);
		return 1;
	}

	//creation functions
	static const luaL_Reg metatable[] = {
		// metatable
		{"new", _new},
		{"__index", index},
		{"__newindex", newindex},
		{"__tostring", tostring},
		{"__add", add},
		{"__sub", sub},
		{"__mul", mul},
		{"__div", div},
		{"__unm", unm},
		{"__idiv", idiv},
		{"__band", band},
		{"__bor", bor},
		{"__bxor", bxor},
		{"__bnot", bnot},
		{"__eq", eq},
		{NULL, NULL}
	};
}



static int vector2MetaObjectId = 0;
int STAMP_LUA_NAMESPACE::luaopen_vector2(lua_State* L) {
	vector2MetaObjectId = luaS_newmetaobject(L, STAMP_LUA_VECTOR2NAME);
	luaL_setfuncs(L, luaVector2::metatable, 0);
	return 1;
}
int STAMP_LUA_NAMESPACE::luaS_vector2id(lua_State* L) {
	return vector2MetaObjectId;
}

int STAMP_LUA_NAMESPACE::luaS_vector3id(lua_State* L) {
	return 0;
}

int STAMP_LUA_NAMESPACE::luaS_vector4id(lua_State* L) {
	return 0;
}

// vector management functions
bool STAMP_LUA_NAMESPACE::luaS_isvector2(lua_State* L, int index) {
	return luaS_instance(L, index) == luaS_vector2id(L);
}
bool STAMP_LUA_NAMESPACE::luaS_isvector3(lua_State* L, int index) {
	return luaS_instance(L, index) == luaS_vector3id(L);
}
bool STAMP_LUA_NAMESPACE::luaS_isvector4(lua_State* L, int index) {
	return luaS_instance(L, index) == luaS_vector4id(L);
}

lua_Vector2* STAMP_LUA_NAMESPACE::luaS_pushvector2(lua_State* L) {
	lua_newuserdatauv(L, sizeof(lua_Vector2), 0);
	luaS_pushmetaobject(L, luaS_vector2id(L));
	lua_setmetatable(L, -2);
	auto p = (lua_Vector2*)lua_touserdata(L, -1);
	return p;
}

lua_Vector3* STAMP_LUA_NAMESPACE::luaS_pushvector3(lua_State* L) {
	lua_newuserdatauv(L, sizeof(lua_Vector2), 0);
	luaS_pushmetaobject(L, luaS_vector3id(L));
	lua_setmetatable(L, -2);
	auto p = (lua_Vector3*)lua_touserdata(L, -1);
	return p;
}

lua_Vector4* STAMP_LUA_NAMESPACE::luaS_pushvector4(lua_State* L) {
	lua_newuserdatauv(L, sizeof(lua_Vector2), 0);
	luaS_pushmetaobject(L, luaS_vector4id(L));
	lua_setmetatable(L, -2);
	auto p = (lua_Vector4*)lua_touserdata(L, -1);
	return p;
}

lua_Vector2* STAMP_LUA_NAMESPACE::luaS_pushvector2(lua_State* L, const lua_Vector2& v) {
	auto p = luaS_pushvector2(L);
	*p = (lua_Vector2)v;
	return p;
}

lua_Vector3* STAMP_LUA_NAMESPACE::luaS_pushvector3(lua_State* L, const lua_Vector3& v) {
	auto p = luaS_pushvector3(L);
	*p = (lua_Vector3)v;
	return p;
}

lua_Vector4* STAMP_LUA_NAMESPACE::luaS_pushvector4(lua_State* L, const lua_Vector4& v) {
	lua_newuserdatauv(L, sizeof(lua_Vector2), 0);
	luaS_pushmetaobject(L, luaS_vector4id(L));
	lua_setmetatable(L, -2);
	auto p = (lua_Vector4*)lua_touserdata(L, -1);
	*p = (lua_Vector4)v;
	return p;
}

lua_Vector2 STAMP_LUA_NAMESPACE::luaS_tovector2x(lua_State* L, int index, int* isvector) {
	if (luaS_isvector2(L, index)) {
		if (isvector) *isvector = 1;
		return *(lua_Vector2*)lua_touserdata(L, index);
	}
	int type = lua_type(L, index);
	if (type == LUA_TNUMBER) {
		if (isvector) *isvector = 1;
		lua_Number v = luaL_checknumber(L, index);
		return lua_Vector2(v);
	}
	if (type != LUA_TTABLE) {
		if (isvector) *isvector = 0;
		return lua_Vector2();
	}
	int isnum = 0;
	lua_getfield(L, index, "x");
	lua_Number x = lua_tonumberx(L, -1, &isnum);
	lua_pop(L, 1);
	if (!isnum) {
		x = 0;
	}
	lua_getfield(L, index, "y");
	lua_Number y = lua_tonumberx(L, -1, &isnum);
	lua_pop(L, 1);
	if (!isnum) {
		y = 0;
	}
	if (isvector) *isvector = 1;
	return lua_Vector2(x, y);
}

lua_Vector3 STAMP_LUA_NAMESPACE::luaS_tovector3x(lua_State* L, int index, int* isvector) {
	if (luaS_isvector3(L, index)) {
		if (isvector) *isvector = 1;
		return *(lua_Vector3*)lua_touserdata(L, index);
	}
	int type = lua_type(L, index);
	if (type == LUA_TNUMBER) {
		if (isvector) *isvector = 1;
		lua_Number v = luaL_checknumber(L, index);
		return lua_Vector3(v);
	}
	if (type != LUA_TTABLE) {
		if (isvector) *isvector = 0;
		return lua_Vector3();
	}
	int isnum = 0;
	lua_getfield(L, index, "x");
	lua_Number x = lua_tonumberx(L, -1, &isnum);
	lua_pop(L, 1);
	if (!isnum) {
		x = 0;
	}
	lua_getfield(L, index, "y");
	lua_Number y = lua_tonumberx(L, -1, &isnum);
	lua_pop(L, 1);
	if (!isnum) {
		y = 0;
	}
	lua_getfield(L, index, "z");
	lua_Number z = lua_tonumberx(L, -1, &isnum);
	lua_pop(L, 1);
	if (!isnum) {
		z = 0;
	}
	if (isvector) *isvector = 1;
	return lua_Vector3(x, y, z);
}

lua_Vector4 STAMP_LUA_NAMESPACE::luaS_tovector4x(lua_State* L, int index, int* isvector) {
	if (luaS_isvector4(L, index)) {
		if (isvector) *isvector = 1;
		return *(lua_Vector4*)lua_touserdata(L, index);
	}
	int type = lua_type(L, index);
	if (type == LUA_TNUMBER) {
		if (isvector) *isvector = 1;
		lua_Number v = luaL_checknumber(L, index);
		return lua_Vector4(v);
	}
	if (type != LUA_TTABLE) {
		if (isvector) *isvector = 0;
		return lua_Vector4();
	}
	int isnum = 0;
	lua_getfield(L, index, "x");
	lua_Number x = lua_tonumberx(L, -1, &isnum);
	lua_pop(L, 1);
	if (!isnum) {
		x = 0;
	}
	lua_getfield(L, index, "y");
	lua_Number y = lua_tonumberx(L, -1, &isnum);
	lua_pop(L, 1);
	if (!isnum) {
		y = 0;
	}
	lua_getfield(L, index, "z");
	lua_Number z = lua_tonumberx(L, -1, &isnum);
	lua_pop(L, 1);
	if (!isnum) {
		z = 0;
	}
	lua_getfield(L, index, "w");
	lua_Number w = lua_tonumberx(L, -1, &isnum);
	lua_pop(L, 1);
	if (!isnum) {
		w = 0;
	}
	if (isvector) *isvector = 1;
	return lua_Vector4(x, y, z, w);
}
lua_Vector2 STAMP_LUA_NAMESPACE::luaS_tovector2(lua_State* L, int index) {
	return luaS_tovector2x(L, index, nullptr);
}
lua_Vector3 STAMP_LUA_NAMESPACE::luaS_tovector3(lua_State* L, int index) {
	return luaS_tovector3x(L, index, nullptr);
}
lua_Vector4 STAMP_LUA_NAMESPACE::luaS_tovector4(lua_State* L, int index) {
	return luaS_tovector4x(L, index, nullptr);
}
lua_Vector2* STAMP_LUA_NAMESPACE::luaS_checkvector2(lua_State* L, int index) {
	if (!luaS_isvector2(L, index)) {
		luaL_argerror(L, index, "Expected a Vector2 object");
		return nullptr;
	}
	return (lua_Vector2*)lua_touserdata(L, index);
}
lua_Vector3* STAMP_LUA_NAMESPACE::luaS_checkvector3(lua_State* L, int index) {
	if (!luaS_isvector3(L, index)) {
		luaL_argerror(L, index, "Expected a Vector3 object");
		return nullptr;
	}
	return (lua_Vector3*)lua_touserdata(L, index);
}
lua_Vector4* STAMP_LUA_NAMESPACE::luaS_checkvector4(lua_State* L, int index) {
	if (!luaS_isvector4(L, index)) {
		luaL_argerror(L, index, "Expected a Vector4 object");
		return nullptr;
	}
	return (lua_Vector4*)lua_touserdata(L, index);
}

#endif