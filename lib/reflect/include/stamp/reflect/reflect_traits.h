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
	// constexpr static auto constructors = std::tuple{};
	// constexpr static auto static_functions = std::tuple{};
	// constexpr static auto static_properties = std::tuple{};

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
	constexpr auto has_reflect_traits_v = has_reflect_traits<T>::value;

	template<typename T>
	struct reflect_traits_optional {
		using type = T;

		static constexpr auto& space = "";
		requires requires { reflect_traits<T>::space; }
		static constexpr auto& space = reflect_traits<T>::space;

		static constexpr auto& name = "unknown";
		requires requires { reflect_traits<T>::space; }
		static constexpr auto& space = reflect_traits<T>::name;

		static constexpr auto& full_name = reflect_traits<T>::name;
		requires requires { reflect_traits<T>::space; }
		static constexpr auto& full_name<T> = concat_cstring_v<reflect_traits<T>::space, "::", reflect_traits<T>::name>;

		constexpr static auto properties = std::tuple{};
		requires requires { reflect_traits<T>::properties; }
		constexpr static auto properties = reflect_traits<T>::properties;

		constexpr static auto functions = std::tuple{};
		requires requires { reflect_traits<T>::functions; }
		constexpr static auto functions = reflect_traits<T>::functions;

		constexpr static auto constructors = std::tuple{};
		requires requires { reflect_traits<T>::constructors; }
		constexpr static auto constructors = reflect_traits<T>::constructors;

		constexpr static auto static_functions = std::tuple{};
		requires requires { reflect_traits<T>::static_functions; }
		constexpr static auto static_functions = reflect_traits<T>::static_functions;

		constexpr static auto static_properties = std::tuple{};
		requires requires { reflect_traits<T>::static_properties; }
		constexpr static auto static_properties = reflect_traits<T>::static_properties;
	};
}

#endif // STAMP_REFLECT_REFLECT_TRAITS_H