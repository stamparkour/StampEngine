#pragma once
#ifndef STAMP_REFLECT_FUNCTION_H
#define STAMP_REFLECT_FUNCTION_H

#include<tuple>
#include<type_traits>
#include<stamp/reflect/reflect_helpers.h>
#include <string>

namespace stamp::reflect {
	template<typename T>
	struct member_function_type;
	template<typename B, typename R, typename... Arg>
	struct member_function_type<R(B::*)(Arg...)> {
		using class_type = B;
		using result_type = R;
		using ptr_type = R (B::*)(Arg...);
		using param_type = std::tuple<Arg...>;
		static constexpr bool is_const = false;
	};
	template<typename B, typename R, typename... Arg>
	struct member_function_type<R(B::*)(Arg...) const> {
		using class_type = B;
		using result_type = R;
		using ptr_type = R (B::*)(Arg...);
		using param_type = std::tuple<Arg...>;
		static constexpr bool is_const = true;
	};

	template<typename T, typename... Arg>
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

		constexpr member_function(const char* name, ptr_type member_ptr, Arg... attributes) :
			name(name),
			member_ptr(member_ptr), 
			attributes(attributes...) {}
	};

	template<typename T>
	struct is_member_function : std::false_type {};
	template<typename T, typename... Arg >
	struct is_member_function <member_function<T, Arg...>> : std::true_type {};
	template<typename T>
	struct is_const_member_function : std::false_type {};
	template<typename T, typename... Arg >
	struct is_const_member_function <member_function<T, Arg...>> : std::bool_constant<member_function<T, Arg...>::is_const>{};

}

#endif // STAMP_REFLECT_MEMBER_H