#pragma once
#ifndef STAMP_REFLECT_REFLECT_CTYPES_H
#define STAMP_REFLECT_REFLECT_CTYPES_H

#include "reflect_helpers.h"
#include "reflect_traits.h"
#include "reflect_types.h"
#include <concepts>
#include <string>
#include <tuple>

namespace stamp::reflect {
	template<>
	struct reflect_traits<void> {
		using type = void;
		static constexpr auto& name = "void";
		static constexpr auto members = std::tuple{};
	};
	template<>
	struct reflect_traits<int> {
		using type = int;
		static constexpr auto& name = "int";
		static constexpr auto members = std::tuple{};
	};
	template<>
	struct reflect_traits<short> {
		using type = short;
		static constexpr auto& name = "short";
		static constexpr auto members = std::tuple{};
	};

	template<typename T>
	struct reflect_traits<T const> {
		static_assert(concepts::reflect_traits_c<T>, "must have valid reflection definition of T");
		using type = const T;
		static constexpr auto name = concat_cstring_v<reflect_traits_space_name_v<T>, " const">;
		static constexpr auto members = reflect_traits<T>::members;
	};

	template<typename T>
	struct reflect_traits<T&> {
		static_assert(concepts::reflect_traits_c<T>, "must have valid reflection definition of T");
		using type = T&;
		static constexpr auto name = concat_cstring_v<reflect_traits_space_name_v<T>, "&">;
		static constexpr auto members = reflect_traits<T>::members;
	};

	template<typename T>
	struct reflect_traits<T*> {
		static_assert(concepts::reflect_traits_c<T>, "must have valid reflection definition of T");
		using type = T*;
		static constexpr auto name = concat_cstring_v<reflect_traits_space_name_v<T>, "*">;
		static constexpr auto members = std::tuple{};
	};
	template<typename R, typename B>
	struct reflect_traits<R B::*> {
		static_assert(concepts::reflect_traits_c<R>, "must have valid reflection definition of R");
		static_assert(concepts::reflect_traits_c<B>, "must have valid reflection definition of B");
		using type = R B::*;
		static constexpr auto name = concat_cstring_v<reflect_traits_space_name_v<R>, " ", reflect_traits_space_name_v<B>, "::*">;
		static constexpr auto members = std::tuple{};
	};
	template<typename R, typename B, typename... Arg>
	struct reflect_traits<R (B::*)(Arg...)> {
		static_assert(concepts::reflect_traits_c<R>, "must have valid reflection definition of R");
		static_assert(concepts::reflect_traits_c<B>, "must have valid reflection definition of B");
		static_assert((concepts::reflect_traits_c<Arg>&&...), "must have valid reflection definition of Arg");

		using type = R (B::*)(Arg...);
		static constexpr auto name = concat_cstring_v< reflect_traits_space_name_v<R>, " (", reflect_traits_space_name_v<B>, "::*)(", comma_list_string_literals_v<reflect_traits_space_name_v<Arg>...>, ")">;
		static constexpr auto members = std::tuple{};
	};
	template<typename R, typename B, typename... Arg>
	struct reflect_traits<R(B::*)(Arg...) const> {
		static_assert(concepts::reflect_traits_c<R>, "must have valid reflection definition of R");
		static_assert(concepts::reflect_traits_c<B>, "must have valid reflection definition of B");
		static_assert((concepts::reflect_traits_c<Arg>&&...), "must have valid reflection definition of Arg");

		using type = R(B::*)(Arg...) const;
		static constexpr auto name = concat_cstring_v<reflect_traits_space_name_v<R>, " (", reflect_traits_space_name_v<B>, "::*)(", comma_list_string_literals_v<reflect_traits_space_name_v<Arg>...>, ") const">;
		static constexpr auto members = std::tuple{};
	};
	template<typename R, typename... Arg>
	struct reflect_traits<R (*)(Arg...)> {
		static_assert(concepts::reflect_traits_c<R>, "must have valid reflection definition of R");
		static_assert((concepts::reflect_traits_c<Arg>&&...), "must have valid reflection definition of Arg");

		using type = R(*)(Arg...);
		static constexpr auto name = concat_cstring_v<reflect_traits_space_name_v<R>, " (*)(", comma_list_string_literals_v<reflect_traits_space_name_v<Arg>...>, ")">;
		static constexpr auto members = std::tuple{};
	};
}

#endif // STAMP_REFLECT_REFLECT_CTYPES_H