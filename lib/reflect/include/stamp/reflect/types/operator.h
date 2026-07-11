// stamp/reflect/types/operator.h
#pragma once
#ifndef STAMP_REFLECT_OPERATOR_H
#define STAMP_REFLECT_OPERATOR_H

// need to add overloads for lvalue and rvalue stuff

#include<tuple>
#include<type_traits>
#include<stamp/reflect/string_literal.h>
#include <stamp/reflect/types/function.h>
#include <stamp/reflect/reflect_helpers.h>

namespace stamp::reflect {
	template<typename T>
	struct function_operator_attrib;
	namespace tag {
		struct operator_generic_tag_t : member_function_generic_tag_t {
			template<typename T>
			using attrib_type = function_operator_attrib<T>;
		};

		inline struct assign_operator_tag_t : operator_generic_tag_t {} assign_rf;
		inline struct addition_operator_tag_t : operator_generic_tag_t {} addition_rf;
		inline struct subtraction_operator_tag_t : operator_generic_tag_t {} subtraction_rf;
		inline struct multiplication_operator_tag_t : operator_generic_tag_t {} multiplication_rf;
		inline struct division_operator_tag_t : operator_generic_tag_t {} division_rf;
		inline struct modulo_operator_tag_t : operator_generic_tag_t {} modulo_rf;
		inline struct post_increment_operator_tag_t : operator_generic_tag_t {} post_increment_rf;
		inline struct post_decrement_operator_tag_t : operator_generic_tag_t {} post_decrement_rf;
		inline struct pre_increment_operator_tag_t : operator_generic_tag_t {} pre_increment_rf;
		inline struct pre_decrement_operator_tag_t : operator_generic_tag_t {} pre_decrement_rf;
		inline struct logical_not_operator_tag_t : operator_generic_tag_t {} logical_not_rf;
		inline struct bitwise_not_operator_tag_t : operator_generic_tag_t {} bitwise_not_rf;
		inline struct unary_plus_operator_tag_t : operator_generic_tag_t {} unary_plus_rf;
		inline struct unary_minus_operator_tag_t : operator_generic_tag_t {} unary_minus_rf;
		inline struct dereference_operator_tag_t : operator_generic_tag_t {} dereference_rf;
		inline struct address_of_operator_tag_t : operator_generic_tag_t {} address_of_rf;
		inline struct member_access_through_pointer_operator_tag_t : operator_generic_tag_t {} member_access_through_pointer_rf;
		inline struct function_call_operator_tag_t : operator_generic_tag_t {} function_call_rf;
		inline struct subscript_operator_tag_t : operator_generic_tag_t {} subscript_rf;
		inline struct comma_operator_tag_t : operator_generic_tag_t {} comma_rf;
		inline struct new_operator_operator_tag_t : operator_generic_tag_t {} new_operator_rf;
		inline struct delete_operator_operator_tag_t : operator_generic_tag_t {} delete_operator_rf;
		template<typename To>
		struct cast_operator_generic_tag_t : operator_generic_tag_t {};
		template<typename To>
		constexpr auto cast_operator_rf = tag::cast_operator_generic_tag_t<To>{};

		template<> constexpr string_literal to_string_v<assign_operator_tag_t> = "operator =";
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
		template<typename To> constexpr string_literal to_string_v<cast_operator_generic_tag_t<To>> = concat_cstring_v<"operator ", traits::full_name_v<To>>;

		//template<typename T, typename Tag>
		//constexpr auto to_member_ptr_v = nullptr;
		//template<typename T>
		//constexpr auto to_member_ptr_v<T,addition_operator_tag_t> = T::operator+;
	}

	template<typename O>
	struct function_operator_attrib {
		using operator_type = O;
		static constexpr string_literal name = tag::to_string_v<O>;
	};


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
