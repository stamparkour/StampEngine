#pragma once 
#ifndef STAMP_REFLECT_REFLECT_HELPERS_H
#define STAMP_REFLECT_REFLECT_HELPERS_H

#include"reflect_traits.h"
#include"meta_tuple.h"
#include"string_literal.h"
#include<tuple>
#include<string_view>
#include <type_traits>

namespace stamp::reflect {

	namespace traits {
		namespace detail {
			template<typename T>
			concept has_full_name_c = requires { reflect_traits<T>::full_name; };
			template<typename T>
			concept has_space_c = requires { reflect_traits<T>::space; };
		}

		template<typename T>
		constexpr string_literal space_v = "";
		template<stamp::reflect::concepts::reflect_traits_c T> requires detail::has_space_c<T>
		constexpr string_literal space_v<T> = reflect_traits<T>::space;
		template<typename T>
		constexpr string_literal name_v = "@unknown";
		template<stamp::reflect::concepts::reflect_traits_c T> requires requires { reflect_traits<T>::name; }
		constexpr string_literal name_v<T> = reflect_traits<T>::name;
		template<typename T>
		constexpr string_literal full_name_v = name_v<T>;
		template<stamp::reflect::concepts::reflect_traits_c T> requires detail::has_full_name_c<T>
		constexpr string_literal full_name_v<T> = reflect_traits<T>::full_name;
		template<stamp::reflect::concepts::reflect_traits_c T> requires (!detail::has_full_name_c<T>) && detail::has_space_c<T>
		constexpr string_literal full_name_v<T> = concat_cstring_v<space_v<T>, "::", name_v<T>>;
		template<typename T>
		constexpr string_literal basic_name_v = name_v<T>;
		template<stamp::reflect::concepts::reflect_traits_c T> requires requires { reflect_traits<T>::basic_name; }
		constexpr string_literal basic_name_v<T> = reflect_traits<T>::basic_name;
		template<typename T>
		constexpr auto base_v = std::tuple{};
		template<stamp::reflect::concepts::reflect_traits_c T> requires requires { reflect_traits<T>::base; }
		constexpr auto base_v<T> = reflect_traits<T>::base;
		template<typename T>
		constexpr auto properties_v = std::tuple{};
		template<stamp::reflect::concepts::reflect_traits_c T> requires requires { reflect_traits<T>::properties; }
		constexpr auto properties_v<T> = reflect_traits<T>::properties;
		template<typename T>
		constexpr auto functions_v = std::tuple{};
		template<stamp::reflect::concepts::reflect_traits_c T> requires requires { reflect_traits<T>::functions; }
		constexpr auto functions_v<T> = reflect_traits<T>::functions;
		template<typename T>
		constexpr auto constructors_v = std::tuple{};
		template<stamp::reflect::concepts::reflect_traits_c T> requires requires { reflect_traits<T>::constructors; }
		constexpr auto constructors_v<T> = reflect_traits<T>::constructors;
		template<typename T>
		constexpr auto static_properties_v = std::tuple{};
		template<stamp::reflect::concepts::reflect_traits_c T> requires requires { reflect_traits<T>::static_properties; }
		constexpr auto static_properties_v<T> = reflect_traits<T>::static_properties;
		template<typename T>
		constexpr auto static_functions_v = std::tuple{};
		template<stamp::reflect::concepts::reflect_traits_c T> requires requires { reflect_traits<T>::static_functions; }
		constexpr auto static_functions_v<T> = reflect_traits<T>::static_functions;
	}

	// runs the Func on all member functions of T’s reflect traits
	template<typename T, typename Func>
	constexpr void for_each_reflect_member_functions(Func func) {
		for_each(traits::functions_v<T>, func);
	}
	// runs the Func on all member properties of T’s reflect traits
	template<typename T, typename Func>
	constexpr void for_each_reflect_member_properties(Func func) {
		for_each(traits::properties_v<T>, func);
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

	template<typename... T>
	struct first_argument;
	template<typename T0, typename... T>
	struct first_argument<T0, T...> {
		using type = T0;
	};
	template<>
	struct first_argument<> {
		using type = void;
	};
	template<typename... T>
	using first_argument_v = typename first_argument<T...>::type;


	//type erasure of type for reflect info
	struct reflect_info_t {
		std::string_view name;
		std::size_t hash_code;
		struct {
			bool
				is_void,
				is_integral,
				is_floating_point;
		} type_traits;
	};

	template<typename T>
	inline const reflect_info_t reflect_info_v = {
		.name = traits::name_v<T>,
		.hash_code = typeid(T).hash_code(),
		.type_traits = {
			.is_void = std::is_void_v<T>,
			.is_integral = std::is_integral_v<T>,
			.is_floating_point = std::is_floating_point_v<T>
		}
	};
}

#endif // STAMP_REFLECT_REFLECT_HELPERS_H