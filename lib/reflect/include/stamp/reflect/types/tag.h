#pragma once
#ifndef STAMP_REFLECT_TAG_H
#define STAMP_REFLECT_TAG_H

#include <stamp/reflect/string_literal.h>
#include <concepts>

namespace stamp::reflect {
	namespace tag {
		struct generic_tag_t {};
		struct named_generic_tag_t : generic_tag_t{};
		template<string_literal S>
		struct named_tag_t : named_generic_tag_t {
			static constexpr auto name = S;
		};

		template<typename T>
		constexpr string_literal to_string_v = "unknown tag";
		template<std::derived_from<named_generic_tag_t> T>
		constexpr string_literal to_string_v<T> = T::name;
	}
	template<string_literal S>
	constexpr tag::named_tag_t<S> operator ""_rf() {
		return {};
	}

	namespace concepts {
		template<typename T>
		concept is_tag_c = std::derived_from<T, stamp::reflect::tag::generic_tag_t>;
	}

	namespace tag {
		struct overload_generic_tag_t : generic_tag_t {};
		struct member_function_generic_tag_t : generic_tag_t {};

		struct none_overload_tag_t : overload_generic_tag_t {} none_rf;
		struct const_overload_tag_t : overload_generic_tag_t {} const_rf;
		struct lvalue_overload_tag_t : overload_generic_tag_t {} lvalue_rf;
		struct const_lvalue_overload_tag_t : overload_generic_tag_t {} const_lvalue_rf;
		struct rvalue_overload_tag_t : overload_generic_tag_t {} rvalue_rf;
		struct const_rvalue_overload_tag_t : overload_generic_tag_t {} const_rvalue_rf;
	}

	namespace concepts {
		template<typename T>
		concept is_overload_tag_c = std::derived_from<T, stamp::reflect::tag::overload_generic_tag_t>;
		template<typename T>
		concept is_member_function_generic_tag_c = std::derived_from<T, stamp::reflect::tag::member_function_generic_tag_t>;
	}

	template<typename T>
	struct function_operator_attrib;
	namespace tag {
		struct operator_generic_tag_t : member_function_generic_tag_t {
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

		//template<typename T, typename Tag>
		//constexpr auto to_member_ptr_v = nullptr;
		//template<typename T>
		//constexpr auto to_member_ptr_v<T,addition_operator_tag_t> = T::operator+;
	}



	template<typename T>
	struct function_iterator_attrib;
	namespace tag {
		struct iterator_generic_tag_t : member_function_generic_tag_t {
			template<typename T>
			using attrib_type = function_iterator_attrib<T>;
		};

		struct begin_iterator_tag_t : iterator_generic_tag_t {} begin_rf;
		struct end_iterator_tag_t : iterator_generic_tag_t {} end_rf;
		struct cbegin_iterator_tag_t : iterator_generic_tag_t {} cbegin_rf;
		struct cend_iterator_tag_t : iterator_generic_tag_t {} cend_rf;
		struct rbegin_iterator_tag_t : iterator_generic_tag_t {} rbegin_rf;
		struct rend_iterator_tag_t : iterator_generic_tag_t {} rend_rf;
		struct crbegin_iterator_tag_t : iterator_generic_tag_t {} crbegin_rf;
		struct crend_iterator_tag_t : iterator_generic_tag_t {} crend_rf;

		template<> constexpr string_literal to_string_v<begin_iterator_tag_t> = "begin";
		template<> constexpr string_literal to_string_v<end_iterator_tag_t> = "end";
		template<> constexpr string_literal to_string_v<cbegin_iterator_tag_t> = "cbegin";
		template<> constexpr string_literal to_string_v<cend_iterator_tag_t> = "cend";
		template<> constexpr string_literal to_string_v<rbegin_iterator_tag_t> = "rbegin";
		template<> constexpr string_literal to_string_v<rend_iterator_tag_t> = "rend";
		template<> constexpr string_literal to_string_v<crbegin_iterator_tag_t> = "crbegin";
		template<> constexpr string_literal to_string_v<crend_iterator_tag_t> = "crend";
	}
}

#endif // STAMP_REFLECT_TAG_H
