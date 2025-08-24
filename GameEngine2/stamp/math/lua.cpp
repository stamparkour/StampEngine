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

#include <stamp/math/lua.h>

using namespace STAMP_LUA_NAMESPACE;
using namespace STAMP_MATH_NAMESPACE;

void STAMP_LUA_NAMESPACE::Lua_Mathlib(sol::state* lua, sol::table* target) {
	auto math = lua->create_table();
	(*target)["math"] = math;

	auto vector2 = math.new_usertype<lua_Vector2>("Vector2", sol::constructors<
		lua_Vector2(),
		lua_Vector2(lua_number_t),
		lua_Vector2(lua_number_t, lua_number_t)
	>());

	math["Vector2"] = vector2;

	vector2["x"] = &lua_Vector2::x;
	vector2["y"] = &lua_Vector2::y;

	using operator_vv2_t = lua_Vector2(*)(const lua_Vector2&);
	using operator_vvv2_t = lua_Vector2(*)(const lua_Vector2&, const lua_Vector2&);
	using operator_vnv2_t = lua_Vector2(*)(lua_number_t, const lua_Vector2&);
	using operator_vvn2_t = lua_Vector2(*)(const lua_Vector2&, lua_number_t);
	using operator_nvv2_t = lua_number_t(*)(const lua_Vector2&, const lua_Vector2&);
	using operator_bvv2_t = bool(*)(const lua_Vector2&, const lua_Vector2&);
	
	vector2[sol::meta_function::addition] = sol::overload(
		static_cast<operator_vvv2_t>(STAMP_MATH_NAMESPACE::operator+),
		static_cast<operator_vnv2_t>(STAMP_MATH_NAMESPACE::operator+),
		static_cast<operator_vvn2_t>(STAMP_MATH_NAMESPACE::operator+)
	);
	vector2[sol::meta_function::subtraction] = sol::overload(
		static_cast<operator_vvv2_t>(STAMP_MATH_NAMESPACE::operator-),
		static_cast<operator_vnv2_t>(STAMP_MATH_NAMESPACE::operator-),
		static_cast<operator_vvn2_t>(STAMP_MATH_NAMESPACE::operator-)
	);
	vector2[sol::meta_function::multiplication] = sol::overload(
		static_cast<operator_vvv2_t>(STAMP_MATH_NAMESPACE::operator*),
		static_cast<operator_vnv2_t>(STAMP_MATH_NAMESPACE::operator*),
		static_cast<operator_vvn2_t>(STAMP_MATH_NAMESPACE::operator*)
	);
	vector2[sol::meta_function::division] = sol::overload(
		static_cast<operator_vvv2_t>(STAMP_MATH_NAMESPACE::operator/),
		static_cast<operator_vnv2_t>(STAMP_MATH_NAMESPACE::operator/),
		static_cast<operator_vvn2_t>(STAMP_MATH_NAMESPACE::operator/)
	);
	vector2[sol::meta_function::division] = sol::overload(
		static_cast<operator_vvv2_t>(STAMP_MATH_NAMESPACE::operator/),
		static_cast<operator_vnv2_t>(STAMP_MATH_NAMESPACE::operator/),
		static_cast<operator_vvn2_t>(STAMP_MATH_NAMESPACE::operator/)
	);
	vector2[sol::meta_function::equal_to] = sol::overload(
		[](const lua_Vector2& a, const lua_Vector2& b) -> bool { return (bool)(a == b); },
		[](const lua_Vector2& a, lua_number_t b) -> bool { return (bool)(a == b); },
		[](lua_number_t a, const lua_Vector2& b) -> bool { return (bool)(a == b); }
	);
	vector2[sol::meta_function::less_than] = sol::overload(
		[](const lua_Vector2& a, const lua_Vector2& b) -> bool { return (bool)(a < b); },
		[](const lua_Vector2& a, lua_number_t b) -> bool { return (bool)(a < b); },
		[](lua_number_t a, const lua_Vector2& b) -> bool { return (bool)(a < b); }
	);
	vector2[sol::meta_function::less_than_or_equal_to] = sol::overload(
		[](const lua_Vector2& a, const lua_Vector2& b) -> bool { return (bool)(a <= b); },
		[](const lua_Vector2& a, lua_number_t b) -> bool { return (bool)(a <= b); },
		[](lua_number_t a, const lua_Vector2& b) -> bool { return (bool)(a <= b); }
	);
	vector2[sol::meta_function::unary_minus] = static_cast<operator_vv2_t>(STAMP_MATH_NAMESPACE::operator-);
	vector2[sol::meta_function::length] = [](const lua_Vector2& a) -> int { return 2; };

	math["cross"] = sol::overload(
		static_cast<operator_nvv2_t>(STAMP_MATH_NAMESPACE::cross)
	);
	math["dot"] = sol::overload(
		static_cast<operator_nvv2_t>(STAMP_MATH_NAMESPACE::dot)
	);
}

#endif