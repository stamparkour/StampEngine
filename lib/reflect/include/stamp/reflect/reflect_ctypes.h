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
		static constexpr string_literal name = "void";
	};
	template<>
	struct reflect_traits<int> {
		using type = int;
		static constexpr string_literal name = "int";
	};
	template<>
	struct reflect_traits<short> {
		using type = short;
		static constexpr string_literal name = "short";
	};
	template<>
	struct reflect_traits<char> {
		using type = char;
		static constexpr string_literal name = "char";
	};
	template<>
	struct reflect_traits<long> {
		using type = long;
		static constexpr string_literal name = "long";
	};
	template<>
	struct reflect_traits<long long> {
		using type = long long;
		static constexpr string_literal name = "long long";
	};

	template<>
	struct reflect_traits<unsigned int> {
		using type = unsigned int;
		static constexpr string_literal name = "unsigned int";
	};
	template<>
	struct reflect_traits<unsigned short> {
		using type = unsigned short;
		static constexpr string_literal name = "unsigned short";
	};
	template<>
	struct reflect_traits<unsigned char> {
		using type = unsigned char;
		static constexpr string_literal name = "unsigned char";
	};
	template<>
	struct reflect_traits<unsigned long> {
		using type = unsigned long;
		static constexpr string_literal name = "unsigned long";
	};
	template<>
	struct reflect_traits<unsigned long long> {
		using type = unsigned long long;
		static constexpr string_literal name = "unsigned long long";
	};
	template<>
	struct reflect_traits<float> {
		using type = float;
		static constexpr string_literal name = "float";
	};
	template<>
	struct reflect_traits<double> {
		using type = double;
		static constexpr string_literal name = "double";
	};
	template<>
	struct reflect_traits<long double> {
		using type = long double;
		static constexpr string_literal name = "long double";
	};

	template<typename T>
	struct reflect_traits<T const> {
		using type = const T;
		static constexpr string_literal space = reflect_space_v<T>;
		static constexpr string_literal name = concat_cstring_v<reflect_full_name_v<T>, " const">;
		static constexpr string_literal full_name = concat_cstring_v<reflect_full_name_v<T>, " const">;
	};

	template<typename T>
	struct reflect_traits<T&> {
		using type = T&;
		static constexpr string_literal space = reflect_space_v<T>;
		static constexpr string_literal name = concat_cstring_v<reflect_name_v<T>, "&">;
		static constexpr string_literal full_name = concat_cstring_v<reflect_full_name_v<T>, "&">;
		static constexpr auto properties = reflect_properties_v<T>;
		static constexpr auto functions = reflect_functions_v<T>;
		static constexpr auto constructors = reflect_constructors_v<T>;
		static constexpr auto static_functions = reflect_static_functions_v<T>;
		static constexpr auto static_properties = reflect_static_properties_v<T>;
	};

	template<typename T>
	struct reflect_traits<T*> {
		using type = T*;
		static constexpr string_literal space = reflect_space_v<T>;
		static constexpr string_literal name = concat_cstring_v<reflect_name_v<T>, "*">;
		static constexpr string_literal full_name = concat_cstring_v<reflect_full_name_v<T>, "*">;
	};
	template<typename R, typename B>
	struct reflect_traits<R B::*> {
		using type = R B::*;
		static constexpr string_literal space = reflect_space_v<B>;
		static constexpr string_literal name = concat_cstring_v<reflect_name_v<R>, " ", reflect_name_v<B>, "::*">;
		static constexpr string_literal full_name = concat_cstring_v<reflect_full_name_v<R>, " ", reflect_full_name_v<B>, "::*">;
	};
	template<typename R, typename B, typename... Arg>
	struct reflect_traits<R(B::*)(Arg...) const> {
		using type = R(B::*)(Arg...) const;
		static constexpr string_literal space = reflect_space_v<B>;
		static constexpr auto name = concat_cstring_v<
			reflect_name_v<R>,
			" (",
			reflect_name_v<B>,
			"::*)(",
			comma_list_string_literals_v<reflect_name_v<Arg>...>,
			") const"
		>;
		static constexpr auto full_name = concat_cstring_v<
			reflect_full_name_v<R>,
			" (",
			reflect_full_name_v<B>,
			"::*)(",
			comma_list_string_literals_v<reflect_full_name_v<Arg>...>,
			") const"
		>;
	};
	template<typename R, typename B, typename... Arg>
	struct reflect_traits<R (B::*)(Arg...)> {
		using type = R (B::*)(Arg...);
		static constexpr string_literal space = reflect_space_v<B>;
		static constexpr auto name = concat_cstring_v<
			reflect_name_v<R>,
			" (",
			reflect_name_v<B>,
			"::*)(",
			comma_list_string_literals_v<reflect_name_v<Arg>...>,
			")"
		>;
		static constexpr auto full_name = concat_cstring_v<
			reflect_full_name_v<R>,
			" (",
			reflect_full_name_v<B>,
			"::*)(",
			comma_list_string_literals_v<reflect_full_name_v<Arg>...>,
			")"
		>;
	};
	template<typename R, typename... Arg>
	struct reflect_traits<R (*)(Arg...)> {
		using type = R(*)(Arg...);
		static constexpr auto name = concat_cstring_v<
			reflect_name_v<R>,
			" (*)(",
			comma_list_string_literals_v<reflect_name_v<Arg>...>,
			")"
		>;
		static constexpr auto full_name = concat_cstring_v<
			reflect_full_name_v<R>,
			" (*)(",
			comma_list_string_literals_v<reflect_full_name_v<Arg>...>,
			")"
		>;
	};
}

#endif // STAMP_REFLECT_REFLECT_CTYPES_H