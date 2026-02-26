#pragma once
#ifndef STAMP_REFLECT_PROPERTY_H
#define STAMP_REFLECT_MEMBER_H

#include<tuple>
#include <stamp/reflect/string_literal.h>
#include<type_traits>

namespace stamp::reflect {
	template<typename B, typename T, std::size_t N, typename... Arg>
	struct member_property_t {
		using class_type = B;
		using value_type = T;
		using ptr_type = T B::*;
		using attrib_type = std::tuple<Arg...>;

		string_literal<N> name;
		ptr_type ptr;
		attrib_type attributes;

		constexpr member_property_t(string_literal<N> name, ptr_type ptr, Arg... attributes) :
			name(name),
			ptr(ptr),
			attributes(attributes...) {
		}
		constexpr member_property_t(const char (&name)[N], ptr_type ptr, Arg... attributes) :
			name(name),
			ptr(ptr),
			attributes(attributes...) {
		}
	};

	template<>
	constexpr auto reflect() 
}

#endif // STAMP_REFLECT_MEMBER_H
