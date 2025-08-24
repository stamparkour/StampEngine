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

#include <stamp/lua/lua.h>

using namespace STAMP_LUA_NAMESPACE;

static std::string instance(const sol::object& obj) {
	lua_State* L = obj.lua_state();
	if (obj.get_type() == sol::type::userdata) {
		const sol::userdata& u = obj.as<const sol::userdata&>();
		// get metatable
		sol::metatable meta = u[sol::metatable_key];
		if (!meta.valid()) return sol::type_name(L, sol::type::userdata);
		// get instance type
		auto type = meta[sol::meta_function::type];
		if (!type.valid()) return sol::type_name(L, sol::type::userdata);
		std::string instance_type = type["name"];
		return instance_type;
	}
	else {
		return sol::type_name(L, obj.get_type());
	}
}
static bool instanceof(const sol::object& obj, const sol::object& type) {
	lua_State* L = obj.lua_state();

	if (type.get_type() == sol::type::string) {
		std::string type_str = type.as<std::string>();
		return instance(obj) == type_str;
	}
	else if (type.get_type() != sol::type::table) {
		return false;
	}
	sol::table type_table = type.as<sol::table>();

	auto t = type_table[sol::meta_function::type];
	if (!t.valid()) return false;
	auto is = t["is"];
	if (!is.valid()) return false;

	sol::function is_func = is;
	return is_func(obj);
}

sol::state STAMP_LUA_NAMESPACE::InitializeLua() {
	sol::state lua;
	// open some common libraries
	lua.open_libraries();

	lua[STAMP_LUA_INSTANCEOF_FUNCTION] = instanceof;
	lua[STAMP_LUA_INSTANCE_FUNCTION] = instance;

	sol::table root = lua.create_table();
	lua[STAMP_LUA_ROOT_OBJECT] = root;
	Lua_Mathlib(&lua, &root);
	return lua;
}

#endif