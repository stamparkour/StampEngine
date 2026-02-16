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
		static constexpr auto& space = "std";
		static constexpr auto& name = "array";
		static constexpr auto members = std::tuple{
			member_function{"other", static_cast<void (type::*)(int, int (type::*)(short, short))>(nullptr)},
			member_operator{operator_type::subscript, static_cast<typename type::reference(type::*)(typename type::size_type)>(&type::operator[])},
			member_function{"front", static_cast<typename type::reference(type::*)()>(&type::front)},
			member_function{"front", static_cast<typename type::const_reference(type::*)() const>(&type::front)},
			member_function{"back", static_cast<typename type::reference(type::*)()>(&type::back)},
			member_function{"back", static_cast<typename type::const_reference(type::*)() const>(&type::back)},
		};
	};
}

#endif // STAMP_REFLECT_STD_REFLECT_ARRAY_H