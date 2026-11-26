// stamp/reflect/types/iterator.h
#pragma once
#ifndef STAMP_REFLECT_TYPES_ITERATOR_H
#define STAMP_REFLECT_TYPES_ITERATOR_H

#include <tuple>
#include <type_traits>
#include <stamp/reflect/string_literal.h>
#include <stamp/reflect/types/function.h>
#include <stamp/reflect/types/tag.h>

namespace stamp::reflect {
	namespace tag {
		struct generic_iterator_attrib_t : generic_function_attrib_t {};
		struct iterator_generic_tag_t : member_function_tag_t {};

		struct begin_iterator_attrib_t : generic_iterator_attrib_t {};
		struct end_iterator_attrib_t : generic_iterator_attrib_t {};
		struct cbegin_iterator_attrib_t : generic_iterator_attrib_t {};
		struct cend_iterator_attrib_t : generic_iterator_attrib_t {};
		struct rbegin_iterator_attrib_t : generic_iterator_attrib_t {};
		struct rend_iterator_attrib_t : generic_iterator_attrib_t {};
		struct crbegin_iterator_attrib_t : generic_iterator_attrib_t {};
		struct crend_iterator_attrib_t : generic_iterator_attrib_t {};

		inline struct begin_iterator_tag_t : iterator_generic_tag_t {
			using attrib_type = begin_iterator_attrib_t;
		} begin_rf;
		inline struct end_iterator_tag_t : iterator_generic_tag_t {
			using attrib_type = end_iterator_attrib_t;
		} end_rf;
		inline struct cbegin_iterator_tag_t : iterator_generic_tag_t {
			using attrib_type = cbegin_iterator_attrib_t;
		} cbegin_rf;
		inline struct cend_iterator_tag_t : iterator_generic_tag_t {
			using attrib_type = cend_iterator_attrib_t;
		} cend_rf;
		inline struct rbegin_iterator_tag_t : iterator_generic_tag_t {
			using attrib_type = rbegin_iterator_attrib_t;
		} rbegin_rf;
		inline struct rend_iterator_tag_t : iterator_generic_tag_t {
			using attrib_type = rend_iterator_attrib_t;
		} rend_rf;
		inline struct crbegin_iterator_tag_t : iterator_generic_tag_t {
			using attrib_type = crbegin_iterator_attrib_t;
		} crbegin_rf;
		inline struct crend_iterator_tag_t : iterator_generic_tag_t {
			using attrib_type = crend_iterator_attrib_t;
		} crend_rf;

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
	concept iterator_attrib_c = std::derived_from<T, tag::generic_iterator_attrib_t>;

	template<typename T>
	concept begin_iterator_attrib_c = std::derived_from<T, tag::begin_iterator_attrib_t>;
	template<typename T>
	concept end_iterator_attrib_c = std::derived_from<T, tag::end_iterator_attrib_t>;
	template<typename T>
	concept cbegin_iterator_attrib_c = std::derived_from<T, tag::cbegin_iterator_attrib_t>;
	template<typename T>
	concept cend_iterator_attrib_c = std::derived_from<T, tag::cend_iterator_attrib_t>;
	template<typename T>
	concept rbegin_iterator_attrib_c = std::derived_from<T, tag::rbegin_iterator_attrib_t>;
	template<typename T>
	concept rend_iterator_attrib_c = std::derived_from<T, tag::rend_iterator_attrib_t>;
	template<typename T>
	concept crbegin_iterator_attrib_c = std::derived_from<T, tag::crbegin_iterator_attrib_t>;
	template<typename T>
	concept crend_iterator_attrib_c = std::derived_from<T, tag::crend_iterator_attrib_t>;
}

#endif // STAMP_REFLECT_TYPES_ITERATOR_H
