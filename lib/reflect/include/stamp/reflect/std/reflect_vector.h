#pragma once
#ifndef STAMP_REFLECT_STD_REFLECT_VECTOR_H
#define STAMP_REFLECT_STD_REFLECT_VECTOR_H

#include <stamp/reflect/reflect_traits.h>
#include <stamp/reflect/reflect_types.h>
#include <vector>

namespace stamp::reflect {
	template<typename T, typename Alloc>
	struct reflect_traits<std::vector<T, Alloc>> {
		using type = std::vector<T, Alloc>;
		static constexpr string_literal space = "std::";
		static constexpr string_literal name = "vector";
		static constexpr auto members = std::tuple{
			member_operator{operator_type::subscript, static_cast<typename type::reference (type::*)(typename type::size_type)>(&type::operator[])}
		};
	};
}

#endif // STAMP_REFLECT_STD_REFLECT_VECTOR_H