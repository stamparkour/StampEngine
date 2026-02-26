#pragma once
#ifndef STAMP_REFLECT_FUNCTION_H
#define STAMP_REFLECT_FUNCTION_H

// need to add overloads for lvalue and rvalue stuff

#include<tuple>
#include<type_traits>
#include<stamp/reflect/reflect_helpers.h>
#include <stamp/reflect/string_literal.h>
#include <string>

namespace stamp::reflect {

	namespace tag {
		struct overload_tag_generic_t {};

		struct none_overload_tag_t : overload_tag_generic_t {} rf_none;
		struct const_overload_tag_t : overload_tag_generic_t {} rf_const;
		struct lvalue_overload_tag_t : overload_tag_generic_t {} rf_lvalue;
		struct const_lvalue_overload_tag_t : overload_tag_generic_t {} rf_const_lvalue;
		struct rvalue_overload_tag_t : overload_tag_generic_t {} rf_rvalue;
		struct const_rvalue_overload_tag_t : overload_tag_generic_t {} rf_const_rvalue;
	}

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
		static constexpr bool is_ref_qual_lvalue = false;
		static constexpr bool is_ref_qual_rvalue = false;
		using overload_tag_type = tag::none_overload_tag_t;
	};
	template<typename B, typename R, typename... Arg>
	struct member_function_traits<R(B::*)(Arg...) const> {
		using class_type = B;
		using result_type = R;
		using ptr_type = R(B::*)(Arg...) const;
		using param_type = std::tuple<Arg...>;
		static constexpr bool is_const = true;
		static constexpr bool is_noexcept = false;
		static constexpr bool is_ref_qual_lvalue = false;
		static constexpr bool is_ref_qual_rvalue = false;
		using overload_tag_type = tag::const_overload_tag_t;
	};
	template<typename B, typename R, typename... Arg>
	struct member_function_traits<R(B::*)(Arg...) noexcept> {
		using class_type = B;
		using result_type = R;
		using ptr_type = R(B::*)(Arg...) noexcept;
		using param_type = std::tuple<Arg...>;
		static constexpr bool is_const = false;
		static constexpr bool is_noexcept = true;
		static constexpr bool is_ref_qual_lvalue = false;
		static constexpr bool is_ref_qual_rvalue = false;
		using overload_tag_type = tag::none_overload_tag_t;
	};
	template<typename B, typename R, typename... Arg>
	struct member_function_traits<R(B::*)(Arg...) const noexcept> {
		using class_type = B;
		using result_type = R;
		using ptr_type = R(B::*)(Arg...) const noexcept;
		using param_type = std::tuple<Arg...>;
		static constexpr bool is_const = true;
		static constexpr bool is_noexcept = true;
		static constexpr bool is_ref_qual_lvalue = false;
		static constexpr bool is_ref_qual_rvalue = false;
		using overload_tag_type = tag::const_overload_tag_t;
	};
	template<typename B, typename R, typename... Arg>
	struct member_function_traits<R(B::*)(Arg...) &> {
		using class_type = B;
		using result_type = R;
		using ptr_type = R(B::*)(Arg...) &;
		using param_type = std::tuple<Arg...>;
		static constexpr bool is_const = false;
		static constexpr bool is_noexcept = false;
		static constexpr bool is_ref_qual_lvalue = true;
		static constexpr bool is_ref_qual_rvalue = false;
		using overload_tag_type = tag::lvalue_overload_tag_t;
	};
	template<typename B, typename R, typename... Arg>
	struct member_function_traits<R(B::*)(Arg...) const &> {
		using class_type = B;
		using result_type = R;
		using ptr_type = R(B::*)(Arg...) const &;
		using param_type = std::tuple<Arg...>;
		static constexpr bool is_const = true;
		static constexpr bool is_noexcept = false;
		static constexpr bool is_ref_qual_lvalue = true;
		static constexpr bool is_ref_qual_rvalue = false;
		using overload_tag_type = tag::const_lvalue_overload_tag_t;
	};
	template<typename B, typename R, typename... Arg>
	struct member_function_traits<R(B::*)(Arg...) &&> {
		using class_type = B;
		using result_type = R;
		using ptr_type = R(B::*)(Arg...) &&;
		using param_type = std::tuple<Arg...>;
		static constexpr bool is_const = false;
		static constexpr bool is_noexcept = false;
		static constexpr bool is_ref_qual_lvalue = false;
		static constexpr bool is_ref_qual_rvalue = true;
		using overload_tag_type = tag::rvalue_overload_tag_t;
	};
	template<typename B, typename R, typename... Arg>
	struct member_function_traits<R(B::*)(Arg...) const &&> {
		using class_type = B;
		using result_type = R;
		using ptr_type = R(B::*)(Arg...) const &&;
		using param_type = std::tuple<Arg...>;
		static constexpr bool is_const = true;
		static constexpr bool is_noexcept = false;
		static constexpr bool is_ref_qual_lvalue = false;
		static constexpr bool is_ref_qual_rvalue = true;
		using overload_tag_type = tag::const_rvalue_overload_tag_t;
	};
	

	template<typename T, typename Tag>
	constexpr bool member_function_check_tag_v = std::same_as<Tag, typename member_function_traits<T>::overload_tag_type>;

	namespace concepts {
		template<typename T, typename... Arg>
		concept member_function_with_param_c = std::same_as<typename member_function_traits<T>::param_type, std::tuple<Arg...>>;
		template<typename T>
		concept is_member_function_c = requires {
			member_function_traits<T>{};
		};
		template<typename T, typename Tag>
		concept member_function_with_tag_c = member_function_check_tag_v<T, Tag>;
	}


	template<typename T, std::size_t N, typename... Arg>
	class member_function_t {
	public:
		using class_type = member_function_traits<T>::class_type;
		using result_type = member_function_traits<T>::result_type;
		using ptr_type = T;
		using param_type = member_function_traits<T>::param_type;
		static constexpr bool is_const = member_function_traits<T>::is_const;
		static constexpr bool is_noexcept = member_function_traits<T>::is_noexcept;
		static constexpr bool is_ref_qual_lvalue = member_function_traits<T>::is_ref_qual_lvalue;
		static constexpr bool is_ref_qual_rvalue = member_function_traits<T>::is_ref_qual_rvalue;
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



	// member function variations
	template<typename... Arg, typename B, typename R, std::size_t N, typename... Attr>
	constexpr member_function_t<R(B::*)(Arg...), N, Attr...> reflect(tag::none_overload_tag_t, const string_literal<N>& name, R(B::* member_ptr)(Arg...), Attr... attr) {
		return { name, member_ptr, attr... };
	}
	template<typename... Arg, typename B, typename R, std::size_t N, typename... Attr>
	constexpr member_function_t<R(B::*)(Arg...) const, N, Attr...> reflect(tag::const_overload_tag_t, const string_literal<N>& name, R(B::* member_ptr)(Arg...) const, Attr... attr) {
		return { name, member_ptr, attr... };
	}
	template<typename... Arg, typename B, typename R, std::size_t N, typename... Attr>
	constexpr member_function_t<R(B::*)(Arg...) noexcept, N, Attr...> reflect(tag::none_overload_tag_t, const string_literal<N>& name, R(B::* member_ptr)(Arg...) noexcept, Attr... attr) {
		return { name, member_ptr, attr... };
	}
	template<typename... Arg, typename B, typename R, std::size_t N, typename... Attr>
	constexpr member_function_t<R(B::*)(Arg...) const noexcept, N, Attr...> reflect(tag::const_overload_tag_t, const string_literal<N>& name, R(B::* member_ptr)(Arg...) const noexcept, Attr... attr) {
		return { name, member_ptr, attr... };
	}

	template<typename... Arg, typename B, typename R, std::size_t N, typename... Attr>
	constexpr member_function_t<R(B::*)(Arg...), N, Attr...> reflect(tag::lvalue_overload_tag_t, const string_literal<N>& name, R(B::* member_ptr)(Arg...)&, Attr... attr) {
		return { name, member_ptr, attr... };
	}
	template<typename... Arg, typename B, typename R, std::size_t N, typename... Attr>
	constexpr member_function_t<R(B::*)(Arg...) const, N, Attr...> reflect(tag::const_lvalue_overload_tag_t, const string_literal<N>& name, R(B::* member_ptr)(Arg...) const&, Attr... attr) {
		return { name, member_ptr, attr... };
	}

	template<typename... Arg, typename B, typename R, std::size_t N, typename... Attr>
	constexpr member_function_t<R(B::*)(Arg...), N, Attr...> reflect(tag::rvalue_overload_tag_t, const string_literal<N>& name, R(B::* member_ptr)(Arg...)&&, Attr... attr) {
		return { name, member_ptr, attr... };
	}
	template<typename... Arg, typename B, typename R, std::size_t N, typename... Attr>
	constexpr member_function_t<R(B::*)(Arg...) const, N, Attr...> reflect(tag::const_rvalue_overload_tag_t, const string_literal<N>& name, R(B::* member_ptr)(Arg...) const&&, Attr... attr) {
		return { name, member_ptr, attr... };
	}

	template<typename Arg1, typename... Arg, concepts::member_function_with_param_c<Arg1, Arg...> T, std::size_t N, typename... Attr>
	constexpr member_function_t<T, N, Attr...> reflect(const string_literal<N>& name, T member_ptr, Attr... attr) {
		return { name, member_ptr, attr... };
	}
	template<std::same_as<void> V, concepts::member_function_with_param_c<> T, std::size_t N, typename... Attr>
	constexpr member_function_t<T, N, Attr...> reflect(const string_literal<N>& name, T member_ptr, Attr... attr) {
		return { name, member_ptr, attr... };
	}
	template<concepts::is_member_function_c T, std::size_t N, typename... Attr>
	constexpr member_function_t<T, N, Attr...> reflect(const string_literal<N>& name, T member_ptr, Attr... attr) {
		return { name, member_ptr, attr... };
	}


	// cstring variants

	template<typename... Arg, typename B, typename R, std::size_t N, typename... Attr>
	constexpr auto reflect(tag::none_overload_tag_t, const char(&name)[N], R(B::* member_ptr)(Arg...), Attr... attr) {
		return reflect(string_literal{ name }, member_ptr, attr...);
	}
	template<typename... Arg, typename B, typename R, std::size_t N, typename... Attr>
	constexpr auto reflect(tag::const_overload_tag_t, const char(&name)[N], R(B::* member_ptr)(Arg...) const, Attr... attr) {
		return reflect(string_literal{ name }, member_ptr, attr...);
	}
	template<typename... Arg, typename B, typename R, std::size_t N, typename... Attr>
	constexpr auto reflect(tag::none_overload_tag_t, const char(&name)[N], R(B::* member_ptr)(Arg...) noexcept, Attr... attr) {
		return reflect(string_literal{ name }, member_ptr, attr...);
	}
	template<typename... Arg, typename B, typename R, std::size_t N, typename... Attr>
	constexpr auto reflect(tag::const_overload_tag_t, const char(&name)[N], R(B::* member_ptr)(Arg...) const noexcept, Attr... attr) {
		return reflect(string_literal{ name }, member_ptr, attr...);
	}

	template<typename... Arg, typename B, typename R, std::size_t N, typename... Attr>
	constexpr auto reflect(tag::lvalue_overload_tag_t, const char(&name)[N], R(B::* member_ptr)(Arg...)&, Attr... attr) {
		return reflect(string_literal{ name }, member_ptr, attr...);
	}
	template<typename... Arg, typename B, typename R, std::size_t N, typename... Attr>
	constexpr auto reflect(tag::const_lvalue_overload_tag_t, const char(&name)[N], R(B::* member_ptr)(Arg...) const&, Attr... attr) {
		return reflect(string_literal{ name }, member_ptr, attr...);
	}

	template<typename... Arg, typename B, typename R, std::size_t N, typename... Attr>
	constexpr auto reflect(tag::rvalue_overload_tag_t, const char(&name)[N], R(B::* member_ptr)(Arg...)&&, Attr... attr) {
		return reflect(string_literal{ name }, member_ptr, attr...);
	}
	template<typename... Arg, typename B, typename R, std::size_t N, typename... Attr>
	constexpr auto reflect(tag::const_rvalue_overload_tag_t, const char(&name)[N], R(B::* member_ptr)(Arg...) const&&, Attr... attr) {
		return reflect(string_literal{ name }, member_ptr, attr...);
	}

	template<typename Arg1, typename... Arg, concepts::member_function_with_param_c<Arg1, Arg...> T, std::size_t N, typename... Attr>
	constexpr auto reflect(const char(&name)[N], T member_ptr, Attr... attr) {
		return reflect(string_literal{ name }, member_ptr, attr...);
	}
	template<std::same_as<void> V, concepts::member_function_with_param_c<> T, std::size_t N, typename... Attr>
	constexpr auto reflect(const char(&name)[N], T member_ptr, Attr... attr) {
		return reflect(string_literal{ name }, member_ptr, attr...);
	}
	template<concepts::is_member_function_c T, std::size_t N, typename... Attr>
	constexpr auto reflect(const char(&name)[N], T member_ptr, Attr... attr) {
		return reflect(string_literal{ name }, member_ptr, attr...);
	}

	// member_function_generic 

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
