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

	template<operator_t O> constexpr auto& operator_to_string_v = "operator unknown";
	template<> constexpr auto& operator_to_string_v<operator_t::addition> = "operator +";
	template<> constexpr auto& operator_to_string_v<operator_t::subtraction> = "operator -";
	template<> constexpr auto& operator_to_string_v<operator_t::multiplication> = "operator *";
	template<> constexpr auto& operator_to_string_v<operator_t::division> = "operator /";
	template<> constexpr auto& operator_to_string_v<operator_t::modulo> = "operator %";
	template<> constexpr auto& operator_to_string_v<operator_t::post_increment> = "operator ++";
	template<> constexpr auto& operator_to_string_v<operator_t::post_decrement> = "operator --";
	template<> constexpr auto& operator_to_string_v<operator_t::pre_increment> = "operator ++";
	template<> constexpr auto& operator_to_string_v<operator_t::pre_decrement> = "operator --";
	template<> constexpr auto& operator_to_string_v<operator_t::logical_not> = "operator !";
	template<> constexpr auto& operator_to_string_v<operator_t::bitwise_not> = "operator ~";
	template<> constexpr auto& operator_to_string_v<operator_t::unary_plus> = "operator +";
	template<> constexpr auto& operator_to_string_v<operator_t::unary_minus> = "operator -";
	template<> constexpr auto& operator_to_string_v<operator_t::dereference> = "operator *";
	template<> constexpr auto& operator_to_string_v<operator_t::address_of> = "operator &";
	template<> constexpr auto& operator_to_string_v<operator_t::member_access_through_pointer> = "operator ->";
	template<> constexpr auto& operator_to_string_v<operator_t::function_call> = "operator ()";
	template<> constexpr auto& operator_to_string_v<operator_t::subscript> = "operator []";
	template<> constexpr auto& operator_to_string_v<operator_t::comma> = "operator ,";
	template<> constexpr auto& operator_to_string_v<operator_t::new_operator> = "operator new";
	template<> constexpr auto& operator_to_string_v<operator_t::delete_operator> = "operator delete";

	template<operator_t O>
	struct operator_attrib {
		constexpr operator_t operator_type = O;
		constexpr auto& operator_name = operator_to_string_v<O>;
	};


}

#endif // STAMP_REFLECT_MEMBER_H