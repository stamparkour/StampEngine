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
		static constexpr auto& name = concat_cstring_v<reflect_traits<T>::name, " const">;
		static constexpr auto members = reflect_traits<T>::members;
	};

	template<typename T>
	struct reflect_traits<T&> {
		static_assert(concepts::reflect_traits_c<T>, "must have valid reflection definition of T");
		using type = T&;
		static constexpr auto& name = concat_cstring_v<reflect_traits<T>::name, "&">;
		static constexpr auto members = reflect_traits<T>::members;
	};

	template<typename T>
	struct reflect_traits<T*> {
		static_assert(concepts::reflect_traits_c<T>, "must have valid reflection definition of T");
		using type = T*;
		static constexpr auto& name = concat_cstring_v<reflect_traits<T>::name, "*">;
		static constexpr auto members = std::tuple{};
	};
	template<typename R, typename B>
	struct reflect_traits<R B::*> {
		static_assert(concepts::reflect_traits_c<R>, "must have valid reflection definition of R");
		static_assert(concepts::reflect_traits_c<B>, "must have valid reflection definition of B");
		using type = R B::*;
		static constexpr auto& name = concat_cstring_v<reflect_traits<R>::name, " ", reflect_traits<B>::name, "::*">;
		static constexpr auto members = std::tuple{};
	};
	template<typename R, typename B>
	struct reflect_traits<R (B::*)()> {
		static_assert(concepts::reflect_traits_c<R>, "must have valid reflection definition of R");
		static_assert(concepts::reflect_traits_c<B>, "must have valid reflection definition of B");

		using type = R (B::*)();
		static constexpr auto& name = concat_cstring_v<
			reflect_traits<R>::name, " (", reflect_traits<B>::name, "::*)()"
		>;
		static constexpr auto members = std::tuple{};
	};
	template<typename R, typename B, typename Arg1, typename... Arg>
	struct reflect_traits<R (B::*)(Arg1, Arg...)> {
		static_assert(concepts::reflect_traits_c<R>, "must have valid reflection definition of R");
		static_assert(concepts::reflect_traits_c<B>, "must have valid reflection definition of B");
		static_assert(concepts::reflect_traits_c<Arg1>, "must have valid reflection definition of Arg1");
		static_assert((concepts::reflect_traits_c<Arg>&&...), "must have valid reflection definition of Arg");

		using type = R (B::*)(Arg1, Arg...);
		static constexpr auto& name = concat_cstring_v<
			reflect_traits<R>::name, " (", reflect_traits<B>::name, "::*)(",
			reflect_traits<Arg1>::name,
			concat_cstring_v<", ",reflect_traits_space_name_v<Arg>>...,
			")"
		>;
		static constexpr auto members = std::tuple{};
	};
	template<typename R, typename B>
	struct reflect_traits<R(B::*)() const> {
		static_assert(concepts::reflect_traits_c<R>, "must have valid reflection definition of R");
		static_assert(concepts::reflect_traits_c<B>, "must have valid reflection definition of B");

		using type = R(B::*)() const;
		static constexpr auto& name = concat_cstring_v<
			reflect_traits<R>::name, " (", reflect_traits<B>::name, "::*)() const"
		>;
		static constexpr auto members = std::tuple{};
	};
	template<typename R, typename B, typename Arg1, typename... Arg>
	struct reflect_traits<R(B::*)(Arg1, Arg...) const> {
		static_assert(concepts::reflect_traits_c<R>, "must have valid reflection definition of R");
		static_assert(concepts::reflect_traits_c<B>, "must have valid reflection definition of B");
		static_assert(concepts::reflect_traits_c<Arg1>, "must have valid reflection definition of Arg1");
		static_assert((concepts::reflect_traits_c<Arg>&&...), "must have valid reflection definition of Arg");

		using type = R(B::*)(Arg1, Arg...) const;
		static constexpr auto& name = concat_cstring_v<
			reflect_traits<R>::name, " (", reflect_traits<B>::name, "::*)(",
			reflect_traits<Arg1>::name,
			concat_cstring_v<", ",reflect_traits_space_name_v<Arg>>...,
			") const"
		>;
		static constexpr auto members = std::tuple{};
	};
	template<typename R>
	struct reflect_traits<R (*)()> {
		static_assert(concepts::reflect_traits_c<R>, "must have valid reflection definition of R");

		using type = R(*)();
		static constexpr auto& name = concat_cstring_v<
			reflect_traits<R>::name, " (*)()"
		>;
		static constexpr auto members = std::tuple{};
	};
	template<typename R, typename Arg1, typename... Arg>
	struct reflect_traits<R (*)(Arg1, Arg...)> {
		static_assert(concepts::reflect_traits_c<R>, "must have valid reflection definition of R");
		static_assert(concepts::reflect_traits_c<Arg1>, "must have valid reflection definition of Arg1");
		static_assert((concepts::reflect_traits_c<Arg>&&...), "must have valid reflection definition of Arg");

		using type = R(*)(Arg1, Arg...);
		static constexpr auto& name = concat_cstring_v<
			reflect_traits<R>::name, " (*)(",
			reflect_traits<Arg1>::name,
			concat_cstring_v<", ", reflect_traits_space_name_v<Arg>>...,
			")"
		>;
		static constexpr auto members = std::tuple{};
	};
}

#endif // STAMP_REFLECT_REFLECT_CTYPES_H