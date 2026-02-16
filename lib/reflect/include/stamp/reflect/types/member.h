#pragma once
#ifndef STAMP_REFLECT_MEMBER_H
#define STAMP_REFLECT_MEMBER_H

#include<tuple>
#include<type_traits>

namespace stamp::reflect {
	template<typename B, typename T, typename... Arg>
	struct member {
		using class_type = B;
		using value_type = T;
		using ptr_type = T B::*;
		using attrib_type = std::tuple<Arg...>;

		const char* name;
		ptr_type member_ptr;
		attrib_type attributes;

		constexpr member(const char* name, ptr_type member_ptr, Arg... attributes) :
			name(name),
			member_ptr(member_ptr), 
			attributes(attributes...) {}

	};
	template<typename T>
	struct is_member : std::false_type {};
	template< typename B, typename T, typename... Arg >
	struct is_member<member<B, T, Arg...>> : std::true_type {};
}

#endif // STAMP_REFLECT_MEMBER_H