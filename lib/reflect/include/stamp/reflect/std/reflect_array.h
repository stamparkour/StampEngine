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
			member_function<std::size_t>("at",&type::at),
			member_function_const("at", &type::at),

			member_operator<operator_t::subscript>(&type::operator[]),
			member_operator_const<operator_t::subscript>(&type::operator[]),

			member_function("front", &type::front),
			member_function_const("front", &type::front),

			member_function("back", &type::back),
			member_function_const("back", &type::back),

			member_function("data", &type::data),
			member_function_const("data", &type::data),

			// Capacity
			member_function_const("empty", &type::empty),
			member_function_const("size", &type::size),
			member_function_const("max_size", &type::max_size),

			// Operations
			member_function("fill", &type::fill),
			member_function("swap", &type::swap),


		};

		static constexpr auto constructors = std::tuple{

		};
	};
}

#endif // STAMP_REFLECT_STD_REFLECT_ARRAY_H