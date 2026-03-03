#pragma once
#ifndef STAMP_REFLECT_OPERATOR_H
#define STAMP_REFLECT_OPERATOR_H

// need to add overloads for lvalue and rvalue stuff

#include<tuple>
#include<type_traits>
#include<stamp/reflect/string_literal.h>
#include "function.h"

namespace stamp::reflect {


	template<typename O>
	struct function_operator_attrib {
		using operator_type = O;
		static constexpr string_literal name = tag::to_string_v<O>;
	};

	namespace tag {
		struct operator_generic_tag_t : function_generic_tag_t {
			template<typename T>
			using attrib_type = function_operator_attrib<T>;
		};

		struct addition_operator_tag_t : operator_generic_tag_t {} addition_rf;
		struct subtraction_operator_tag_t : operator_generic_tag_t {} subtraction_rf;
		struct multiplication_operator_tag_t : operator_generic_tag_t {} multiplication_rf;
		struct division_operator_tag_t : operator_generic_tag_t {} division_rf;
		struct modulo_operator_tag_t : operator_generic_tag_t {} modulo_rf;
		struct post_increment_operator_tag_t : operator_generic_tag_t {} post_increment_rf;
		struct post_decrement_operator_tag_t : operator_generic_tag_t {} post_decrement_rf;
		struct pre_increment_operator_tag_t : operator_generic_tag_t {} pre_increment_rf;
		struct pre_decrement_operator_tag_t : operator_generic_tag_t {} pre_decrement_rf;
		struct logical_not_operator_tag_t : operator_generic_tag_t {} logical_not_rf;
		struct bitwise_not_operator_tag_t : operator_generic_tag_t {} bitwise_not_rf;
		struct unary_plus_operator_tag_t : operator_generic_tag_t {} unary_plus_rf;
		struct unary_minus_operator_tag_t : operator_generic_tag_t {} unary_minus_rf;
		struct dereference_operator_tag_t : operator_generic_tag_t {} dereference_rf;
		struct address_of_operator_tag_t : operator_generic_tag_t {} address_of_rf;
		struct member_access_through_pointer_operator_tag_t : operator_generic_tag_t {} member_access_through_pointer_rf;
		struct function_call_operator_tag_t : operator_generic_tag_t {} function_call_rf;
		struct subscript_operator_tag_t : operator_generic_tag_t {} subscript_rf;
		struct comma_operator_tag_t : operator_generic_tag_t {} comma_rf;
		struct new_operator_operator_tag_t : operator_generic_tag_t {} new_operator_rf;
		struct delete_operator_operator_tag_t : operator_generic_tag_t {} delete_operator_rf;

		template<> constexpr string_literal to_string_v<addition_operator_tag_t> = "operator +";
		template<> constexpr string_literal to_string_v<subtraction_operator_tag_t> = "operator -";
		template<> constexpr string_literal to_string_v<multiplication_operator_tag_t> = "operator *";
		template<> constexpr string_literal to_string_v<division_operator_tag_t> = "operator /";
		template<> constexpr string_literal to_string_v<modulo_operator_tag_t> = "operator %";
		template<> constexpr string_literal to_string_v<post_increment_operator_tag_t> = "operator ++";
		template<> constexpr string_literal to_string_v<post_decrement_operator_tag_t> = "operator --";
		template<> constexpr string_literal to_string_v<pre_increment_operator_tag_t> = "operator ++";
		template<> constexpr string_literal to_string_v<pre_decrement_operator_tag_t> = "operator --";
		template<> constexpr string_literal to_string_v<logical_not_operator_tag_t> = "operator !";
		template<> constexpr string_literal to_string_v<bitwise_not_operator_tag_t> = "operator ~";
		template<> constexpr string_literal to_string_v<unary_plus_operator_tag_t> = "operator +";
		template<> constexpr string_literal to_string_v<unary_minus_operator_tag_t> = "operator -";
		template<> constexpr string_literal to_string_v<dereference_operator_tag_t> = "operator *";
		template<> constexpr string_literal to_string_v<address_of_operator_tag_t> = "operator &";
		template<> constexpr string_literal to_string_v<member_access_through_pointer_operator_tag_t> = "operator ->";
		template<> constexpr string_literal to_string_v<function_call_operator_tag_t> = "operator ()";
		template<> constexpr string_literal to_string_v<subscript_operator_tag_t> = "operator []";
		template<> constexpr string_literal to_string_v<comma_operator_tag_t> = "operator ,";
		template<> constexpr string_literal to_string_v<new_operator_operator_tag_t> = "operator new";
		template<> constexpr string_literal to_string_v<delete_operator_operator_tag_t> = "operator delete";
	}


	template<typename T>
	constexpr bool is_function_operator_attrib_v = false;
	template<typename O>
	constexpr bool is_function_operator_attrib_v<function_operator_attrib<O>> = true;


	template<typename T>
	struct is_function_operator_attrib : std::bool_constant<is_function_operator_attrib_v<T>> {};

	namespace concepts {
		template<typename T>
		concept function_operator_attrib_c = is_function_operator_attrib_v<T>;
	}
}

#endif // STAMP_REFLECT_OPERATOR_H
