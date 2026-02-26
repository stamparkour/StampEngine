#pragma once
#ifndef STAMP_REFLECT_ITERATOR_H
#define STAMP_REFLECT_ITERATOR_H

#include<tuple>
#include<type_traits>
#include<stamp/reflect/string_literal.h>
#include "function.h"

namespace stamp::reflect {
	struct 

	template<typename B, typename... Attr>
	constexpr auto reflect(Attr... attr) {
		auto member_ptr = &B::begin;
		using traits = member_function_traits<decltype(member_ptr)>;
		using iterator_type = typename traits::result_type;
		return member_function("begin", member_ptr, function_begin_attrib<iterator_type>(), attr...);
	}
	template<typename B, typename... Attr>
	constexpr auto reflect (Attr... attr) {
		auto member_ptr = &B::begin;
		using traits = member_function_traits<decltype(member_ptr)>;
		using iterator_type = typename traits::result_type;
		return member_function("begin", member_ptr, function_begin_attrib<iterator_type>(), attr...);
	}
}

#endif // STAMP_REFLECT_ITERATOR_H
