#pragma once
#ifndef STAMP_REFLECT_OPERATOR_H
#define STAMP_REFLECT_OPERATOR_H

#include<tuple>
#include<type_traits>
#include "function.h"

namespace stamp::reflect {
	enum struct operator_type {
		addition,
		subtraction,
		multiplication,
		division,
		modulo,
		increment,
		decrement,
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

	constexpr const char* to_cstring(operator_type type) {
		switch (type) {
		case operator_type::addition:                       return "operator +";
		case operator_type::subtraction:                    return "operator -";
		case operator_type::multiplication:                 return "operator *";
		case operator_type::division:                       return "operator /";
		case operator_type::modulo:                         return "operator %";
		case operator_type::increment:                      return "operator ++";
		case operator_type::decrement:                      return "operator --";
		case operator_type::logical_not:                    return "operator !";
		case operator_type::bitwise_not:                    return "operator ~";
		case operator_type::unary_plus:                     return "operator +(unary)";
		case operator_type::unary_minus:                    return "operator -(unary)";
		case operator_type::dereference:                    return "operator +";
		case operator_type::address_of:                     return "operator &";
		case operator_type::member_access_through_pointer:  return "operator ->";
		case operator_type::function_call:                  return "operator ()";
		case operator_type::subscript:                      return "operator []";
		case operator_type::comma:                          return "operator ,";
		case operator_type::new_operator:                   return "operator new";
		case operator_type::delete_operator:                return "operator delete";
		default:                                            return "operator unknown";
		}
	}

	template<typename T, typename... Arg>
	struct member_operator {
		using class_type = member_function_type<T>::class_type;
		using result_type = member_function_type<T>::result_type;
		using ptr_type = T;
		using param_type = member_function_type<T>::param_type;
		using attrib_type = std::tuple<Arg...>;

		const char* name;
		operator_type type;
		ptr_type member_ptr;
		attrib_type attributes;

		constexpr member_operator(operator_type type, ptr_type member_ptr, Arg... attributes) :
			name(to_cstring(type)),
			type(type),
			member_ptr(member_ptr),
			attributes(attributes...) {}
	};

	template<typename T>
	struct is_member_operator : std::false_type {};
	template<typename T, typename... Arg >
	struct is_member_operator <member_operator<T, Arg...>> : std::true_type {};

}

#endif // STAMP_REFLECT_MEMBER_H