#pragma once
#ifndef STAMP_REFLECT_OPERATOR_H
#define STAMP_REFLECT_OPERATOR_H

#include<tuple>
#include<type_traits>
#include<stamp/reflect/string_literal.h>
#include "function.h"

namespace stamp::reflect {
	enum struct operator_type {
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

	template<operator_type O> constexpr auto& operator_to_string_v = "operator unknown";
	template<> constexpr auto& operator_to_string_v<operator_type::addition> = "operator +";
	template<> constexpr auto& operator_to_string_v<operator_type::subtraction> = "operator -";
	template<> constexpr auto& operator_to_string_v<operator_type::multiplication> = "operator *";
	template<> constexpr auto& operator_to_string_v<operator_type::division> = "operator /";
	template<> constexpr auto& operator_to_string_v<operator_type::modulo> = "operator %";
	template<> constexpr auto& operator_to_string_v<operator_type::post_increment> = "operator ++";
	template<> constexpr auto& operator_to_string_v<operator_type::post_decrement> = "operator --";
	template<> constexpr auto& operator_to_string_v<operator_type::pre_increment> = "operator ++";
	template<> constexpr auto& operator_to_string_v<operator_type::pre_decrement> = "operator --";
	template<> constexpr auto& operator_to_string_v<operator_type::logical_not> = "operator !";
	template<> constexpr auto& operator_to_string_v<operator_type::bitwise_not> = "operator ~";
	template<> constexpr auto& operator_to_string_v<operator_type::unary_plus> = "operator +";
	template<> constexpr auto& operator_to_string_v<operator_type::unary_minus> = "operator -";
	template<> constexpr auto& operator_to_string_v<operator_type::dereference> = "operator *";
	template<> constexpr auto& operator_to_string_v<operator_type::address_of> = "operator &";
	template<> constexpr auto& operator_to_string_v<operator_type::member_access_through_pointer> = "operator ->";
	template<> constexpr auto& operator_to_string_v<operator_type::function_call> = "operator ()";
	template<> constexpr auto& operator_to_string_v<operator_type::subscript> = "operator []";
	template<> constexpr auto& operator_to_string_v<operator_type::comma> = "operator ,";
	template<> constexpr auto& operator_to_string_v<operator_type::new_operator> = "operator new";
	template<> constexpr auto& operator_to_string_v<operator_type::delete_operator> = "operator delete";

	template<operator_type O>
	struct operator_attrib {

	};
}

#endif // STAMP_REFLECT_MEMBER_H