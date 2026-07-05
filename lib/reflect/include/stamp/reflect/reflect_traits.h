#pragma once
#ifndef STAMP_REFLECT_REFLECT_TRAITS_H
#define STAMP_REFLECT_REFLECT_TRAITS_H

#include <type_traits>

namespace stamp::reflect {
	template<typename T>
	struct reflect_traits;
	// using type = T;
	// constexpr static string_literal space = "";
	// constexpr static string_literal name = "";
	// constexpr static auto base = std::tuple{};
	// constexpr static auto properties = std::tuple{};
	// constexpr static auto functions = std::tuple{};
	// constexpr static auto constructors = std::tuple{};
	// constexpr static auto static_functions = std::tuple{};
	// constexpr static auto static_properties = std::tuple{};

	namespace concepts {
		template<typename T>
		concept reflect_traits_c = 
			requires {
				reflect_traits<T>{};
				typename reflect_traits<T>::type;
			};
		template<typename T>
		concept reflect_traits_class_c =
			reflect_traits_c<T> &&
			std::is_class_v<T>;
		template<typename T>
		concept reflect_traits_enum_c =
			reflect_traits_c<T> &&
			std::is_enum_v<T>;
		template<typename T>
		concept reflect_traits_union_c =
			reflect_traits_c<T> &&
			std::is_union_v<T>;
		template<typename T>
		concept reflect_traits_usertype_c =
			reflect_traits_class_c<T> || 
			reflect_traits_enum_c<T> || 
			reflect_traits_union_c<T>;

	}
	template<typename T>
	constexpr auto has_reflect_traits_v = false;
	template<concepts::reflect_traits_c T>
	constexpr auto has_reflect_traits_v<T> = true;
	template<typename T>
	struct has_reflect_traits : std::bool_constant<has_reflect_traits_v<T>> {};
}

#endif // STAMP_REFLECT_REFLECT_TRAITS_H