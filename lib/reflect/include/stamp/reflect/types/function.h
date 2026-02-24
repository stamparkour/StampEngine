#pragma once
#ifndef STAMP_REFLECT_FUNCTION_H
#define STAMP_REFLECT_FUNCTION_H

#include<tuple>
#include<type_traits>
#include<stamp/reflect/reflect_helpers.h>
#include <stamp/reflect/string_literal.h>
#include <string>

namespace stamp::reflect {
	template<typename T>
	struct member_function_traits;
	template<typename B, typename R, typename... Arg>
	struct member_function_traits<R(B::*)(Arg...)> {
		using class_type = B;
		using result_type = R;
		using ptr_type = R (B::*)(Arg...);
		using param_type = std::tuple<Arg...>;
		static constexpr bool is_const = false;
		static constexpr bool is_noexcept = false;
	};
	template<typename B, typename R, typename... Arg>
	struct member_function_traits<R(B::*)(Arg...) const> {
		using class_type = B;
		using result_type = R;
		using ptr_type = R(B::*)(Arg...) const;
		using param_type = std::tuple<Arg...>;
		static constexpr bool is_const = true;
		static constexpr bool is_noexcept = false;
	};
	template<typename B, typename R, typename... Arg>
	struct member_function_traits<R(B::*)(Arg...) noexcept> {
		using class_type = B;
		using result_type = R;
		using ptr_type = R(B::*)(Arg...) noexcept;
		using param_type = std::tuple<Arg...>;
		static constexpr bool is_const = false;
		static constexpr bool is_noexcept = true;
	};
	template<typename B, typename R, typename... Arg>
	struct member_function_traits<R(B::*)(Arg...) const noexcept> {
		using class_type = B;
		using result_type = R;
		using ptr_type = R(B::*)(Arg...) const noexcept;
		using param_type = std::tuple<Arg...>;
		static constexpr bool is_const = true;
		static constexpr bool is_noexcept = true;
	};

	template<typename T, std::size_t N, typename... Arg>
	class member_function_t {
	public:
		using class_type = member_function_traits<T>::class_type;
		using result_type = member_function_traits<T>::result_type;
		using ptr_type = T;
		using param_type = member_function_traits<T>::param_type;
		static constexpr bool is_const = member_function_traits<T>::is_const;
		static constexpr bool is_noexcept = member_function_traits<T>::is_noexcept;
		using attrib_type = std::tuple<Arg...>;

		string_literal<N> name;
		ptr_type member_ptr;
		attrib_type attributes;

		constexpr member_function_t(const string_literal<N>& name, ptr_type member_ptr, Arg... attributes) :
			name(name),
			member_ptr(member_ptr),
			attributes(attributes...) {
		}
		constexpr member_function_t(const char(&name)[N], ptr_type member_ptr, Arg... attributes) :
			name(name),
			member_ptr(member_ptr),
			attributes(attributes...) {
		}
	};

	template<typename... Arg, std::size_t N, typename R, typename B, typename... Attr>
	constexpr member_function_t<R(B::*)(Arg...), N, Attr...> member_function(const string_literal<N>& name, R(B::* member_ptr)(Arg...), Attr... attr) {
		return { name, member_ptr, attr... };
	}
	template<typename... Arg, std::size_t N, typename R, typename B, typename... Attr>
	constexpr member_function_t<R(B::*)(Arg...) const, N, Attr...> member_function_const(const string_literal<N>& name, R(B::* member_ptr)(Arg...) const, Attr... attr) {
		return { name, member_ptr, attr... };
	}
	template<typename... Arg, std::size_t N, typename R, typename B, typename... Attr>
	constexpr member_function_t<R(B::*)(Arg...) noexcept, N, Attr...> member_function_noexcept(const string_literal<N>& name, R(B::* member_ptr)(Arg...) noexcept, Attr... attr) {
		return { name, member_ptr, attr... };
	}
	template<typename... Arg, std::size_t N, typename R, typename B, typename... Attr>
	constexpr member_function_t<R(B::*)(Arg...) const noexcept, N, Attr...> member_function_const_noexcept(const string_literal<N>& name, R(B::* member_ptr)(Arg...) const noexcept, Attr... attr) {
		return { name, member_ptr, attr... };
	}

	template<typename... Arg, std::size_t N, typename R, typename B, typename... Attr>
	constexpr member_function_t<R(B::*)(Arg...), N, Attr...> member_function(const char(&name)[N], R(B::* member_ptr)(Arg...), Attr... attr) {
		return { name, member_ptr, attr... };
	}
	template<typename... Arg, std::size_t N, typename R, typename B, typename... Attr>
	constexpr member_function_t<R(B::*)(Arg...) const, N, Attr...> member_function_const(const char(&name)[N], R(B::* member_ptr)(Arg...) const, Attr... attr) {
		return { name, member_ptr, attr... };
	}
	template<typename... Arg, std::size_t N, typename R, typename B, typename... Attr>
	constexpr member_function_t<R(B::*)(Arg...) noexcept, N, Attr...> member_function_noexcept(const char(&name)[N], R(B::* member_ptr)(Arg...) noexcept, Attr... attr) {
		return { name, member_ptr, attr... };
	}
	template<typename... Arg, std::size_t N, typename R, typename B, typename... Attr>
	constexpr member_function_t<R(B::*)(Arg...) const noexcept, N, Attr...> member_function_const_noexcept(const char(&name)[N], R(B::* member_ptr)(Arg...) const noexcept, Attr... attr) {
		return { name, member_ptr, attr... };
	}

	/*template<typename... Arg, std::size_t N, typename R, typename B, typename... Attr>
	constexpr member_function_t<R(B::*)(Arg...), N, Attr...> member_function_generic(const string_literal<N>& name, R(B::* member_ptr)(Arg...), Attr... attr) {
		return { name, member_ptr, attr... };
	}*/

	template<typename T>
	constexpr bool is_member_function_v = false;
	template<typename T, std::size_t N, typename... Arg>
	constexpr bool is_member_function_v<member_function_t<T, N, Arg...>> = true;

	template<typename T>
	struct is_member_function : std::bool_constant<is_member_function_v<T>> {};

	namespace concepts {
		template<typename T>
		concept member_function_c = is_member_function_v<T>;
	}
}

#endif // STAMP_REFLECT_MEMBER_H