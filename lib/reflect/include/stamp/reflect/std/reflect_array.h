#pragma once
#ifndef STAMP_REFLECT_STD_REFLECT_ARRAY_H
#define STAMP_REFLECT_STD_REFLECT_ARRAY_H

#include <stamp/reflect/reflect_traits.h>
#include <stamp/reflect/reflect_types.h>
#include <array>
#include "reflect_iterator.h"

namespace stamp::reflect {
	template<typename T, std::size_t N>
	struct reflect_traits<std::array<T, N>> {
		using namespace stamp::reflect::literals
		using type = std::array<T, N>;
		static constexpr string_literal space = "std::";
		static constexpr string_literal name = concat_cstring_v<"array<", reflect_name_v<T>, ",", integral_to_string_literal_v<std::size_t, N>, ">">;
		static constexpr string_literal basic_name = "array";
		static constexpr string_literal full_name = concat_cstring_v<"std::array<",reflect_full_name_v<T>,",", integral_to_string_literal_v<std::size_t, N>,">">;
		static constexpr auto functions = std::tuple{
			// Element Access
			reflect<"at">(tag::rf_none, &type::at),
			reflect<"at">(tag::rf_const, &type::at),

			reflect(tag::rf_none,tag::rf_subscript, &type::operator[]),
			reflect(tag::rf_const,tag::rf_subscript, &type::operator[]),

			reflect<"front">(tag::rf_none, &type::front),
			reflect<"front">(tag::rf_const, &type::front),

			reflect<"back">(tag::rf_none, &type::back),
			reflect<"back">(tag::rf_const, &type::back),

			reflect<"data">(tag::rf_none, &type::data),
			reflect<"data">(tag::rf_const, &type::data),

			// Capacity
			reflect<"empty">(& type::empty),
			reflect<"size">(&type::size),
			reflect<"max_size">(&type::max_size),

			// Operations
			reflect<"fill">(&type::fill),
			reflect<"swap">(&type::swap),

			// Iterators
			reflect(tag::rf_none, tag::rf_begin, &type::begin),
			reflect(tag::rf_const, tag::rf_begin, &type::begin),

			reflect(tag::rf_none, tag::rf_end, &type::end),
			reflect(tag::rf_const, tag::rf_end, &type::end),

			reflect(tag::rf_cbegin, &type::cbegin),
			reflect(tag::rf_cend, &type::cend),

			reflect(tag::rf_none, tag::rf_rbegin, &type::rbegin),
			reflect(tag::rf_const, tag::rf_rbegin, &type::rbegin),

			reflect(tag::rf_none, tag::rf_rend, &type::rend),
			reflect(tag::rf_const, tag::rf_rend, &type::rend),

			reflect(tag::rf_crbegin, &type::crbegin),
			reflect(tag::rf_crend, &type::crend),
		};

		static constexpr auto constructors = std::tuple{
			reflect_constructor<type>()
		};
	};
}

#endif // STAMP_REFLECT_STD_REFLECT_ARRAY_H
