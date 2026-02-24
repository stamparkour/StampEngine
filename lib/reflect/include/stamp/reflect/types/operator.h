#pragma once
#ifndef STAMP_REFLECT_OPERATOR_H
#define STAMP_REFLECT_OPERATOR_H

#include<tuple>
#include<type_traits>
#include<stamp/reflect/string_literal.h>
#include "function.h"

namespace stamp::reflect {
	enum struct operator_t {
		addition,
		subtraction,
		multiplication,
		division,
		modulo,
		post_increment,
		post_decrement,
		pre_increment,
		pre_decrement,
		logical_not,
		bitwise_not,
		unary_plus,
		unary_minus,
		dereference,
		address_of,
		member_access_through_pointer,
		function_call,
		subscript,
		comma,
		new_operator,
		delete_operator
	};

	template<operator_t O> constexpr string_literal operator_to_string_v = "operator unknown";
	template<> constexpr string_literal operator_to_string_v<operator_t::addition> = "operator +";
	template<> constexpr string_literal operator_to_string_v<operator_t::subtraction> = "operator -";
	template<> constexpr string_literal operator_to_string_v<operator_t::multiplication> = "operator *";
	template<> constexpr string_literal operator_to_string_v<operator_t::division> = "operator /";
	template<> constexpr string_literal operator_to_string_v<operator_t::modulo> = "operator %";
	template<> constexpr string_literal operator_to_string_v<operator_t::post_increment> = "operator ++";
	template<> constexpr string_literal operator_to_string_v<operator_t::post_decrement> = "operator --";
	template<> constexpr string_literal operator_to_string_v<operator_t::pre_increment> = "operator ++";
	template<> constexpr string_literal operator_to_string_v<operator_t::pre_decrement> = "operator --";
	template<> constexpr string_literal operator_to_string_v<operator_t::logical_not> = "operator !";
	template<> constexpr string_literal operator_to_string_v<operator_t::bitwise_not> = "operator ~";
	template<> constexpr string_literal operator_to_string_v<operator_t::unary_plus> = "operator +";
	template<> constexpr string_literal operator_to_string_v<operator_t::unary_minus> = "operator -";
	template<> constexpr string_literal operator_to_string_v<operator_t::dereference> = "operator *";
	template<> constexpr string_literal operator_to_string_v<operator_t::address_of> = "operator &";
	template<> constexpr string_literal operator_to_string_v<operator_t::member_access_through_pointer> = "operator ->";
	template<> constexpr string_literal operator_to_string_v<operator_t::function_call> = "operator ()";
	template<> constexpr string_literal operator_to_string_v<operator_t::subscript> = "operator []";
	template<> constexpr string_literal operator_to_string_v<operator_t::comma> = "operator ,";
	template<> constexpr string_literal operator_to_string_v<operator_t::new_operator> = "operator new";
	template<> constexpr string_literal operator_to_string_v<operator_t::delete_operator> = "operator delete";

	template<operator_t O>
	struct operator_attrib {
		static constexpr operator_t operator_type = O;
		static constexpr string_literal operator_name = operator_to_string_v<O>;
		constexpr operator_attrib() {}
	};

	template<operator_t O, typename... Arg, typename R, typename B, typename... Attr>
	constexpr member_function_t<R(B::*)(Arg...), operator_to_string_v<O>.size(), operator_attrib<O>, Attr...> member_operator(R(B::* member_ptr)(Arg...), Attr... attr) {
		return { operator_to_string_v<O>, member_ptr, operator_attrib<O>(), attr... };
	}
	template<operator_t O, typename... Arg, typename R, typename B, typename... Attr>
	constexpr member_function_t<R(B::*)(Arg...) const, operator_to_string_v<O>.size(), operator_attrib<O>, Attr...> member_operator_const(R(B::* member_ptr)(Arg...) const, Attr... attr) {
		return { operator_to_string_v<O>, member_ptr, operator_attrib<O>(), attr... };
	}
	template<operator_t O, typename... Arg, typename R, typename B, typename... Attr>
	constexpr member_function_t<R(B::*)(Arg...) noexcept, operator_to_string_v<O>.size(), operator_attrib<O>, Attr...> member_operator_noexcept(R(B::* member_ptr)(Arg...) noexcept, Attr... attr) {
		return { operator_to_string_v<O>, member_ptr, operator_attrib<O>(), attr...};
	}
	template<operator_t O, typename... Arg, typename R, typename B, typename... Attr>
	constexpr member_function_t<R(B::*)(Arg...) const noexcept, operator_to_string_v<O>.size(), operator_attrib<O>, Attr...> member_operator_const_noexcept(R(B::* member_ptr)(Arg...) const noexcept, Attr... attr) {
		return { operator_to_string_v<O>, member_ptr, operator_attrib<O>(), attr... };
	}

	template<typename T>
	constexpr bool is_operator_attrib_v = false;
	template<operator_t O>
	constexpr bool is_operator_attrib_v<operator_attrib<O>> = true;

	template<typename T>
	struct is_operator_attrib : std::bool_constant<is_operator_attrib_v<T>> {};

	namespace concepts {
		template<typename T>
		concept operator_attrib_c = is_operator_attrib_v<T>;
	}
}

#endif // STAMP_REFLECT_OPERATOR_H