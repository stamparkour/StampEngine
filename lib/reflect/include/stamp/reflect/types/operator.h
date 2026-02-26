#pragma once
#ifndef STAMP_REFLECT_OPERATOR_H
#define STAMP_REFLECT_OPERATOR_H

// need to add overloads for lvalue and rvalue stuff

#include<tuple>
#include<type_traits>
#include<stamp/reflect/string_literal.h>
#include "function.h"

namespace stamp::reflect {

	namespace tag {
		struct operator_generic_tag_t {};

		struct addition_operator_tag_t : operator_generic_tag_t {} rf_addition;
		struct subtraction_operator_tag_t : operator_generic_tag_t {} rf_subtraction;
		struct multiplication_operator_tag_t : operator_generic_tag_t {} rf_multiplication;
		struct division_operator_tag_t : operator_generic_tag_t {} rf_division;
		struct modulo_operator_tag_t : operator_generic_tag_t {} rf_modulo;
		struct post_increment_operator_tag_t : operator_generic_tag_t {} rf_post_increment;
		struct post_decrement_operator_tag_t : operator_generic_tag_t {} rf_post_decrement;
		struct pre_increment_operator_tag_t : operator_generic_tag_t {} rf_pre_increment;
		struct pre_decrement_operator_tag_t : operator_generic_tag_t {} rf_pre_decrement;
		struct logical_not_operator_tag_t : operator_generic_tag_t {} rf_logical_not;
		struct bitwise_not_operator_tag_t : operator_generic_tag_t {} rf_bitwise_not;
		struct unary_plus_operator_tag_t : operator_generic_tag_t {} rf_unary_plus;
		struct unary_minus_operator_tag_t : operator_generic_tag_t {} rf_unary_minus;
		struct dereference_operator_tag_t : operator_generic_tag_t {} rf_dereference;
		struct address_of_operator_tag_t : operator_generic_tag_t {} rf_address_of;
		struct member_access_through_pointer_operator_tag_t : operator_generic_tag_t {} rf_member_access_through_pointer;
		struct function_call_operator_tag_t : operator_generic_tag_t {} rf_function_call;
		struct subscript_operator_tag_t : operator_generic_tag_t {} rf_subscript;
		struct comma_operator_tag_t : operator_generic_tag_t {} rf_comma;
		struct new_operator_operator_tag_t : operator_generic_tag_t {} rf_new_operator;
		struct delete_operator_operator_tag_t : operator_generic_tag_t {} rf_delete_operator;
	}

	template<typename O> constexpr string_literal operator_to_string_v = "operator unknown";
	template<> constexpr string_literal operator_to_string_v<tag::addition_operator_tag_t> = "operator +";
	template<> constexpr string_literal operator_to_string_v<tag::subtraction_operator_tag_t> = "operator -";
	template<> constexpr string_literal operator_to_string_v<tag::multiplication_operator_tag_t> = "operator *";
	template<> constexpr string_literal operator_to_string_v<tag::division_operator_tag_t> = "operator /";
	template<> constexpr string_literal operator_to_string_v<tag::modulo_operator_tag_t> = "operator %";
	template<> constexpr string_literal operator_to_string_v<tag::post_increment_operator_tag_t> = "operator ++";
	template<> constexpr string_literal operator_to_string_v<tag::post_decrement_operator_tag_t> = "operator --";
	template<> constexpr string_literal operator_to_string_v<tag::pre_increment_operator_tag_t> = "operator ++";
	template<> constexpr string_literal operator_to_string_v<tag::pre_decrement_operator_tag_t> = "operator --";
	template<> constexpr string_literal operator_to_string_v<tag::logical_not_operator_tag_t> = "operator !";
	template<> constexpr string_literal operator_to_string_v<tag::bitwise_not_operator_tag_t> = "operator ~";
	template<> constexpr string_literal operator_to_string_v<tag::unary_plus_operator_tag_t> = "operator +";
	template<> constexpr string_literal operator_to_string_v<tag::unary_minus_operator_tag_t> = "operator -";
	template<> constexpr string_literal operator_to_string_v<tag::dereference_operator_tag_t> = "operator *";
	template<> constexpr string_literal operator_to_string_v<tag::address_of_operator_tag_t> = "operator &";
	template<> constexpr string_literal operator_to_string_v<tag::member_access_through_pointer_operator_tag_t> = "operator ->";
	template<> constexpr string_literal operator_to_string_v<tag::function_call_operator_tag_t> = "operator ()";
	template<> constexpr string_literal operator_to_string_v<tag::subscript_operator_tag_t> = "operator []";
	template<> constexpr string_literal operator_to_string_v<tag::comma_operator_tag_t> = "operator ,";
	template<> constexpr string_literal operator_to_string_v<tag::new_operator_operator_tag_t> = "operator new";
	template<> constexpr string_literal operator_to_string_v<tag::delete_operator_operator_tag_t> = "operator delete";

	template<typename O>
	struct function_operator_attrib {
		using operator_type = O;
		static constexpr string_literal operator_name = operator_to_string_v<O>;
	};


	template<typename... Arg, std::derived_from<tag::operator_generic_tag_t> O, typename B, typename R, typename... Attr>
	constexpr auto reflect(tag::none_overload_tag_t, O, R(B::* member_ptr)(Arg...), Attr... attr) {
		return reflect(operator_to_string_v<O>, member_ptr, function_operator_attrib<O>{}, attr...);
	}
	template<typename... Arg, std::derived_from<tag::operator_generic_tag_t> O, typename B, typename R, typename... Attr>
	constexpr auto reflect(tag::const_overload_tag_t, O, R(B::* member_ptr)(Arg...) const, Attr... attr) {
		return reflect(operator_to_string_v<O>, member_ptr, function_operator_attrib<O>{}, attr...);
	}
	template<typename... Arg, std::derived_from<tag::operator_generic_tag_t> O, typename B, typename R, typename... Attr>
	constexpr auto reflect(tag::none_overload_tag_t, O, R(B::* member_ptr)(Arg...) noexcept, Attr... attr) {
		return reflect(operator_to_string_v<O>, member_ptr, function_operator_attrib<O>{}, attr...);
	}
	template<typename... Arg, std::derived_from<tag::operator_generic_tag_t> O, typename B, typename R, typename... Attr>
	constexpr auto reflect(tag::const_overload_tag_t, O, R(B::* member_ptr)(Arg...) const noexcept, Attr... attr) {
		return reflect(operator_to_string_v<O>, member_ptr, function_operator_attrib<O>{}, attr...);
	}

	template<typename Arg1, typename... Arg, std::derived_from<tag::operator_generic_tag_t> O, concepts::member_function_with_param_c<Arg1, Arg...> T, typename... Attr>
	constexpr auto reflect(O, T member_ptr, Attr... attr) {
		return reflect(operator_to_string_v<O>, member_ptr, function_operator_attrib<O>{}, attr...);
	}
	template<std::same_as<void> Arg, std::derived_from<tag::operator_generic_tag_t> O, concepts::member_function_with_param_c<> T, typename... Attr>
	constexpr auto reflect(O, T member_ptr, Attr... attr) {
		return reflect(operator_to_string_v<O>, member_ptr, function_operator_attrib<O>{}, attr...);
	}
	template<std::derived_from<tag::operator_generic_tag_t> O, concepts::is_member_function_c T, typename... Attr>
	constexpr auto reflect(O, T member_ptr, Attr... attr) {
		return reflect(operator_to_string_v<O>, member_ptr, function_operator_attrib<O>{}, attr...);
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
