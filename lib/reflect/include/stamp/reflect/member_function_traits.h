#pragma once
#ifndef STAMP_REFLECT_MEMBER_FUNCTION_TRAITS_H
#define STAMP_REFLECT_MEMBER_FUNCTION_TRAITS_H

#include <concepts>
#include <tuple>
#include <stamp/reflect/types/tag.h>

namespace stamp::reflect {
	namespace tag {
		struct overload_generic_tag_t : generic_tag_t {};
		struct member_function_generic_tag_t : generic_tag_t {};

		struct none_overload_tag_t : overload_generic_tag_t {} none_rf;
		struct const_overload_tag_t : overload_generic_tag_t {} const_rf;
		struct lvalue_overload_tag_t : overload_generic_tag_t {} lvalue_rf;
		struct const_lvalue_overload_tag_t : overload_generic_tag_t {} const_lvalue_rf;
		struct rvalue_overload_tag_t : overload_generic_tag_t {} rvalue_rf;
		struct const_rvalue_overload_tag_t : overload_generic_tag_t {} const_rvalue_rf;
	}
	namespace concepts {
		template<typename T>
		concept is_overload_tag_c = std::derived_from<T, stamp::reflect::tag::overload_generic_tag_t>;
		template<typename T>
		concept is_member_function_generic_tag_c = std::derived_from<T, stamp::reflect::tag::member_function_generic_tag_t>;
	}

	template<typename T>
	struct member_function_traits;
	template<typename B, typename R, typename... Arg>
	struct member_function_traits<R(B::*)(Arg...)> {
		using base_type = B;
		using result_type = R;
		using ptr_type = R(B::*)(Arg...);
		using arg_type = std::tuple<Arg...>;
		static constexpr bool is_const = false;
		static constexpr bool is_noexcept = false;
		static constexpr bool is_ref_qual_lvalue = false;
		static constexpr bool is_ref_qual_rvalue = false;
		using overload_tag_type = tag::none_overload_tag_t;
	};
	template<typename B, typename R, typename... Arg>
	struct member_function_traits<R(B::*)(Arg...) const> {
		using base_type = B;
		using result_type = R;
		using ptr_type = R(B::*)(Arg...) const;
		using arg_type = std::tuple<Arg...>;
		static constexpr bool is_const = true;
		static constexpr bool is_noexcept = false;
		static constexpr bool is_ref_qual_lvalue = false;
		static constexpr bool is_ref_qual_rvalue = false;
		using overload_tag_type = tag::const_overload_tag_t;
	};
	template<typename B, typename R, typename... Arg>
	struct member_function_traits<R(B::*)(Arg...) noexcept> {
		using base_type = B;
		using result_type = R;
		using ptr_type = R(B::*)(Arg...) noexcept;
		using arg_type = std::tuple<Arg...>;
		static constexpr bool is_const = false;
		static constexpr bool is_noexcept = true;
		static constexpr bool is_ref_qual_lvalue = false;
		static constexpr bool is_ref_qual_rvalue = false;
		using overload_tag_type = tag::none_overload_tag_t;
	};
	template<typename B, typename R, typename... Arg>
	struct member_function_traits<R(B::*)(Arg...) const noexcept> {
		using base_type = B;
		using result_type = R;
		using ptr_type = R(B::*)(Arg...) const noexcept;
		using arg_type = std::tuple<Arg...>;
		static constexpr bool is_const = true;
		static constexpr bool is_noexcept = true;
		static constexpr bool is_ref_qual_lvalue = false;
		static constexpr bool is_ref_qual_rvalue = false;
		using overload_tag_type = tag::const_overload_tag_t;
	};
	template<typename B, typename R, typename... Arg>
	struct member_function_traits<R(B::*)(Arg...)&> {
		using base_type = B;
		using result_type = R;
		using ptr_type = R(B::*)(Arg...)&;
		using arg_type = std::tuple<Arg...>;
		static constexpr bool is_const = false;
		static constexpr bool is_noexcept = false;
		static constexpr bool is_ref_qual_lvalue = true;
		static constexpr bool is_ref_qual_rvalue = false;
		using overload_tag_type = tag::lvalue_overload_tag_t;
	};
	template<typename B, typename R, typename... Arg>
	struct member_function_traits<R(B::*)(Arg...) const&> {
		using base_type = B;
		using result_type = R;
		using ptr_type = R(B::*)(Arg...) const&;
		using arg_type = std::tuple<Arg...>;
		static constexpr bool is_const = true;
		static constexpr bool is_noexcept = false;
		static constexpr bool is_ref_qual_lvalue = true;
		static constexpr bool is_ref_qual_rvalue = false;
		using overload_tag_type = tag::const_lvalue_overload_tag_t;
	};
	template<typename B, typename R, typename... Arg>
	struct member_function_traits<R(B::*)(Arg...)&&> {
		using base_type = B;
		using result_type = R;
		using ptr_type = R(B::*)(Arg...)&&;
		using arg_type = std::tuple<Arg...>;
		static constexpr bool is_const = false;
		static constexpr bool is_noexcept = false;
		static constexpr bool is_ref_qual_lvalue = false;
		static constexpr bool is_ref_qual_rvalue = true;
		using overload_tag_type = tag::rvalue_overload_tag_t;
	};
	template<typename B, typename R, typename... Arg>
	struct member_function_traits<R(B::*)(Arg...) const&&> {
		using base_type = B;
		using result_type = R;
		using ptr_type = R(B::*)(Arg...) const&&;
		using arg_type = std::tuple<Arg...>;
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
		concept member_function_with_param_c = std::same_as<typename member_function_traits<T>::arg_type, std::tuple<Arg...>>;
		template<typename T>
		concept is_member_function_traits_c = requires {
			member_function_traits<T>{};
		};
		template<typename T, typename Tag>
		concept member_function_with_tag_c = member_function_check_tag_v<T, Tag>;
	}
	template<typename T>
	constexpr bool is_member_function_traits_v = concepts::is_member_function_traits_c<T>;
}

#endif // STAMP_REFLECT_MEMBER_FUNCTION_TRAITS_H
