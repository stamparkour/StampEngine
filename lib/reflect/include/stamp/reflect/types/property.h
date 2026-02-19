#pragma once
#ifndef STAMP_REFLECT_PROPERTY_H
#define STAMP_REFLECT_MEMBER_H

#include<tuple>
#include<type_traits>

namespace stamp::reflect {
	template<typename B, typename T, typename... Arg>
	struct property {
		using class_type = B;
		using value_type = T;
		using ptr_type = T B::*;
		using attrib_type = std::tuple<Arg...>;

		const char* name;
		ptr_type ptr;
		attrib_type attributes;

		constexpr property(const char* name, ptr_type ptr, Arg... attributes) :
			name(name),
			ptr(ptr), 
			attributes(attributes...) {}

	};
}

#endif // STAMP_REFLECT_MEMBER_H