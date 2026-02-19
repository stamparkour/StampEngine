#pragma once 
#ifndef STAMP_REFLECT_REFLECT_HELPERS_H
#define STAMP_REFLECT_REFLECT_HELPERS_H

#include"reflect_traits.h"
#include"meta_tuple.h"
#include"string_literal.h"
#include<tuple>

namespace stamp::reflect {

	template<typename T>
	constexpr auto& reflect_space_v = "";
	template<concepts::reflect_traits_c T> requires requires { reflect_traits<T>::space; }
	constexpr auto& reflect_space_v<T> = reflect_traits<T>::space;
	template<typename T>
	constexpr auto& reflect_name_v = "unknown";
	template<concepts::reflect_traits_c T> requires requires { reflect_traits<T>::name; }
	constexpr auto& reflect_name_v<T> = reflect_traits<T>::name;
	template<typename T>
	constexpr auto& reflect_full_name_v = concat_cstring_v<reflect_space_v<T>, reflect_name_v<T>>;
	template<concepts::reflect_traits_c T> requires requires { reflect_traits<T>::full_name; }
	constexpr auto& reflect_full_name_v<T> = reflect_traits<T>::full_name;
	template<typename T>
	constexpr auto reflect_base_v = std::tuple{};
	template<concepts::reflect_traits_c T> requires requires { reflect_traits<T>::base; }
	constexpr auto reflect_base_v<T> = reflect_traits<T>::base;
	template<typename T>
	constexpr auto reflect_properties_v = std::tuple{};
	template<concepts::reflect_traits_c T> requires requires { reflect_traits<T>::properties; }
	constexpr auto reflect_properties_v<T> = reflect_traits<T>::properties;
	template<typename T>
	constexpr auto reflect_functions_v = std::tuple{};
	template<concepts::reflect_traits_c T> requires requires { reflect_traits<T>::functions; }
	constexpr auto reflect_functions_v<T> = reflect_traits<T>::functions;
	template<typename T>
	constexpr auto reflect_constructors_v = std::tuple{};
	template<concepts::reflect_traits_c T> requires requires { reflect_traits<T>::constructors; }
	constexpr auto reflect_constructors_v<T> = reflect_traits<T>::constructors;
	template<typename T>
	constexpr auto reflect_static_functions_v = std::tuple{};
	template<concepts::reflect_traits_c T> requires requires { reflect_traits<T>::static_functions; }
	constexpr auto reflect_static_functions_v<T> = reflect_traits<T>::static_functions;
	template<typename T>
	constexpr auto reflect_static_properties_v = std::tuple{};
	template<concepts::reflect_traits_c T> requires requires { reflect_traits<T>::static_properties; }
	constexpr auto reflect_static_properties_v<T> = reflect_traits<T>::static_properties;

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