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

	template<typename B, typename T, std::size_t N, typename... Attr>
	constexpr member_property_t<B, T, N, Attr...> reflect(const string_literal<N>& name, T B::* member_ptr, Attr... attr) {
		return { name, member_ptr, attr... };
	}
	template<typename B, typename T, std::size_t N, typename... Attr>
	constexpr auto reflect(const char (&name), T B::* member_ptr, Attr... attr) {
		return reflect(string_literal{ name }, member_ptr, attr)
	}
}

#endif // STAMP_REFLECT_MEMBER_H
