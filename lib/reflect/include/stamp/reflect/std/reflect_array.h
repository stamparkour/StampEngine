#pragma once
#ifndef STAMP_REFLECT_STD_REFLECT_ARRAY_H
#define STAMP_REFLECT_STD_REFLECT_ARRAY_H

#include <stamp/reflect/reflect_traits.h>
#include <stamp/reflect/reflect_types.h>
#include <array>

namespace stamp::reflect {
	template<typename T, std::size_t N>
	struct reflect_traits<std::array<T, N>> {
		using type = std::array<T, N>;
		static constexpr string_literal space = "std::";
		static constexpr string_literal name = concat_cstring_v<"array<", reflect_name_v<T>, ",", integral_to_string_literal_v<std::size_t, N>, ">">;
		static constexpr string_literal full_name = concat_cstring_v<"std::array<",reflect_full_name_v<T>,",", integral_to_string_literal_v<std::size_t, N>,">">;
		static constexpr auto functions = std::tuple{
			// Element Access
			reflect(tag::rf_none,"at", &type::at),
			
			reflect(tag::rf_const,"at", &type::at),

			reflect(tag::rf_none,tag::rf_subscript, &type::operator[]),
			reflect(tag::rf_const,tag::rf_subscript, &type::operator[]),

			reflect(tag::rf_none,"front", &type::front),
			reflect(tag::rf_const,"front", &type::front),

			reflect(tag::rf_none,"back", &type::back),
			reflect(tag::rf_const,"back", &type::back),

			reflect(tag::rf_none,"data", &type::data),
			reflect(tag::rf_const,"data", &type::data),

			// Capacity
			reflect("empty",& type::empty),
			reflect("size", &type::size),
			reflect("max_size", &type::max_size),

			// Operations
			reflect("fill", &type::fill),
			reflect("swap", &type::swap),
		};

		static constexpr auto constructors = std::tuple{

		};
	};
}

#endif // STAMP_REFLECT_STD_REFLECT_ARRAY_H
