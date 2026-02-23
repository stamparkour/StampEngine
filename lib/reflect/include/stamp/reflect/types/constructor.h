#pragma once
#ifndef STAMP_REFLECT_OPERATOR_H
#define STAMP_REFLECT_OPERATOR_H

#include<tuple>
#include<type_traits>
#include "function.h"

namespace stamp::reflect {
	template<typename B, typename Param, typename... Arg>
	class member_function {
	public:
		using class_type = member_function_type<T>::class_type;
		using result_type = member_function_type<T>::result_type;
		using ptr_type = T;
		using param_type = member_function_type<T>::param_type;
		static constexpr bool is_const = member_function_type<T>::is_const;
		using attrib_type = std::tuple<Arg...>;
	public:

		const char* name;
		ptr_type member_ptr;
		attrib_type attributes;

		constexpr member_function(Arg... attributes) :
			name(name),
			member_ptr(member_ptr),
			attributes(attributes...) {
		}
	};
}

#endif // STAMP_REFLECT_MEMBER_H