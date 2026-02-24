#pragma once
#ifndef STAMP_REFLECT_PROPERTY_H
#define STAMP_REFLECT_MEMBER_H

#include<tuple>
#include <stamp/reflect/string_literal.h>
#include<type_traits>

namespace stamp::reflect {
	template<typename B, typename T, std::size_t N, typename... Arg>
	struct member_property_generic {
		using class_type = B;
		using value_type = T;
		using ptr_type = T B::*;
		using attrib_type = std::tuple<Arg...>;

		string_literal<N> name;
		ptr_type ptr;
		attrib_type attributes;

		constexpr member_property_generic(string_literal<N> name, ptr_type ptr, Arg... attributes) :
			name(name),
			ptr(ptr),
			attributes(attributes...) {
		}
		constexpr member_property_generic(const char (&name)[N], ptr_type ptr, Arg... attributes) :
			name(name),
			ptr(ptr),
			attributes(attributes...) {
		}
	};
}

#endif // STAMP_REFLECT_MEMBER_H