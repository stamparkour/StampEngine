#pragma once
#ifndef STAMP_REFLECT_MEMBER_FUNCTION_TRAITS_H
#define STAMP_REFLECT_MEMBER_FUNCTION_TRAITS_H

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
		using class_type = B;
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
		using class_type = B;
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
		using class_type = B;
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
		using class_type = B;
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
		using class_type = B;
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
		using class_type = B;
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
		using class_type = B;
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
		concept is_member_function_c = requires {
			member_function_traits<T>{};
		};
		template<typename T, typename Tag>
		concept member_function_with_tag_c = member_function_check_tag_v<T, Tag>;
	}

}

#endif // STAMP_REFLECT_MEMBER_FUNCTION_TRAITS_H
