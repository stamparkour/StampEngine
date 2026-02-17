#pragma once 
#ifndef STAMP_REFLECT_REFLECT_HELPERS_H
#define STAMP_REFLECT_REFLECT_HELPERS_H

#include"reflect_traits.h"
#include"meta_tuple.h"
#include"string_literal.h"
#include<tuple>

namespace stamp::reflect {
	

	// runs the Func on all members of T’s reflect traits
	template<typename T, typename Func>
	constexpr void for_each_reflect(Func func) {
		for_each(reflect_traits<T>::members, func);
	}

	// runs the Func on all members of T’s reflect traits that match Pred
	template<template<typename> typename Pred, typename T, typename Func>
	constexpr void for_each_of_reflect(Func func) {
		for_each_of<Pred>(reflect_traits<T>::members, func);
	}
	
	template<template<typename> typename Pred, typename T>
	consteval std::size_t count_of_reflect() {
		return count_of<Pred>(reflect_traits<T>::members);
	}

	template<string_literal... Other>
	struct comma_list_string_literals;
	template<string_literal A, string_literal... Other>
	struct comma_list_string_literals<A, Other...> {
		constexpr static auto value = concat_cstring_v<A, concat_cstring_v<", ", Other>...>;
	};
	template<>
	struct comma_list_string_literals<> {
		constexpr static auto value = string_literal{""};
	};
	template<string_literal... Arg>
	constexpr auto comma_list_string_literals_v = comma_list_string_literals< Arg...>::value;
}

#endif // STAMP_REFLECT_REFLECT_HELPERS_H