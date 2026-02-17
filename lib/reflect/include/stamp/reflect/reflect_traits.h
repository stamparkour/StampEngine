#pragma once
#ifndef STAMP_REFLECT_REFLECT_TRAITS_H
#define STAMP_REFLECT_REFLECT_TRAITS_H

namespace stamp::reflect {
	template<typename T>
	struct reflect_traits;
	// using type = T;
	// constexpr static auto space = "";
	// constexpr static auto name = "";
	// constexpr static auto properties = std::tuple{};
	// constexpr static auto functions = std::tuple{};
	// constexpr static auto operators = std::tuple{};
	// constexpr static auto constructors = std::tuple{};
	// constexpr static auto deconstructors = std::tuple{};

	namespace concepts {
		template<typename T>
		concept reflect_traits_c = requires {
			typename reflect_traits<T>::type;
		};

	}

	template<typename T>
	struct has_reflect_traits : std::false_type {};
	template<concepts::reflect_traits_c T>
	struct has_reflect_traits<T> : std::true_type {};

	template<typename T>
	struct reflect_traits_optional {
		using type = T;
		static constexpr auto space = "";
		static constexpr auto name = "unknown";
		static constexpr auto members = std::tuple{};
	};
	template<concepts::reflect_traits_c T>
	struct reflect_traits_optional<T> : reflect_traits<T> {};
}

#endif // STAMP_REFLECT_REFLECT_TRAITS_H