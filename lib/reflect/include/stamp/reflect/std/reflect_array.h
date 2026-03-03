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
		using type = std::array<T, N>;
		static constexpr string_literal space = "std::";
		static constexpr string_literal name = concat_cstring_v<"array<", reflect_name_v<T>, ",", integral_to_string_literal_v<std::size_t, N>, ">">;
		static constexpr string_literal basic_name = "array";
		static constexpr string_literal full_name = concat_cstring_v<"std::array<",reflect_full_name_v<T>,",", integral_to_string_literal_v<std::size_t, N>,">">;
		static constexpr auto functions = std::tuple{
			// Element Access
			reflect(tag::none_rf, "at"_rf, &type::at),
			reflect(tag::const_rf, "at"_rf, &type::at),

			reflect(tag::none_rf,tag::subscript_rf, &type::operator[]),
			reflect(tag::const_rf,tag::subscript_rf, &type::operator[]),

			reflect(tag::none_rf, "front"_rf, &type::front),
			reflect(tag::const_rf, "front"_rf, &type::front),

			reflect(tag::none_rf, "back"_rf, &type::back),
			reflect(tag::const_rf, "back"_rf, &type::back),

			reflect(tag::none_rf, "data"_rf, &type::data),
			reflect(tag::const_rf, "data"_rf, &type::data),

			// Capacity
			reflect("empty"_rf, &type::empty),
			reflect("size"_rf, &type::size),
			reflect("max_size"_rf, &type::max_size),

			// Operations
			reflect("fill"_rf, &type::fill),
			reflect("swap"_rf, &type::swap),

			// Iterators
			reflect(tag::none_rf, tag::begin_rf, &type::begin),
			reflect(tag::const_rf, tag::begin_rf, &type::begin),

			reflect(tag::none_rf, tag::end_rf, &type::end),
			reflect(tag::const_rf, tag::end_rf, &type::end),

			reflect(tag::cbegin_rf, &type::cbegin),
			reflect(tag::cend_rf, &type::cend),

			reflect(tag::none_rf, tag::rbegin_rf, &type::rbegin),
			reflect(tag::const_rf, tag::rbegin_rf, &type::rbegin),

			reflect(tag::none_rf, tag::rend_rf, &type::rend),
			reflect(tag::const_rf, tag::rend_rf, &type::rend),

			reflect(tag::crbegin_rf, &type::crbegin),
			reflect(tag::crend_rf, &type::crend),
		};

		static constexpr auto constructors = std::tuple{
			reflect_constructor<type>()
		};
	};
}

#endif // STAMP_REFLECT_STD_REFLECT_ARRAY_H
