#pragma once 
#ifndef STAMP_REFLECT_REFLECT_HELPERS_H
#define STAMP_REFLECT_REFLECT_HELPERS_H

#include"reflect_traits.h"
#include"meta_tuple.h"
#include"string_literal.h"
#include<tuple>

namespace stamp::reflect {
	

	template<typename T>
	constexpr auto& reflect_traits_space_name_v = reflect_traits<T>::name;
	template<typename T> requires requires { reflect_traits<T>::space; }
	constexpr auto& reflect_traits_space_name_v<T> = concat_cstring_v<reflect_traits<T>::space, "::", reflect_traits<T>::name>;

	template<typename T>
	constexpr auto& reflect_traits_optional_space_name_v = "unknown";
	template<typename T> requires concepts::reflect_traits_c<T>
	constexpr auto& reflect_traits_optional_space_name_v<T> = reflect_traits_space_name_v<T>;

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
}

#endif // STAMP_REFLECT_REFLECT_HELPERS_H