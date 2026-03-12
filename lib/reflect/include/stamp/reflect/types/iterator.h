#pragma once
#ifndef STAMP_REFLECT_ITERATOR_H
#define STAMP_REFLECT_ITERATOR_H

#include<tuple>
#include<type_traits>
#include<stamp/reflect/string_literal.h>
#include "function.h"
#include "tag.h"

namespace stamp::reflect {
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

	template<typename T>
	struct function_iterator_attrib {
		using iterator_type = T;
		static constexpr string_literal name = tag::to_string_v<T>;

	};

	template<typename T>
	constexpr bool is_function_iterator_attrib_v = false;
	template<typename O>
	constexpr bool is_function_iterator_attrib_v<function_iterator_attrib<O>> = true;


	template<typename T>
	struct is_function_iterator_attrib : std::bool_constant<is_function_iterator_attrib_v<T>> {};

	namespace concepts {
		template<typename T>
		concept function_iterator_attrib_c = is_function_iterator_attrib_v<T>;
	}
}

#endif // STAMP_REFLECT_ITERATOR_H
