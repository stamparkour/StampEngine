// stamp/reflect/function_traits.h
#ifndef STAMP_REFLECT_FUNCTION_TRAITS_H
#define STAMP_REFLECT_FUNCTION_TRAITS_H

#include <stamp/reflect/member_function_traits.h>

namespace stamp::reflect {
	template<typename T>
	struct function_traits;

	template<typename T> requires is_member_function_c<T>
	struct function_traits {
		using class_type = typename member_function_traits<T>::class_type;
		using return_type = typename member_function_traits<T>::return_type;
		using ptr_type = typename member_function_traits<T>::ptr_type;
		using arg_type = typename member_function_traits<T>::arg_type;
		using arg_ref_type = typename member_function_traits<T>::arg_ref_type;
		static constexpr bool is_member_function = true;
		static constexpr bool is_const = member_function_traits<T>::is_const;
		static constexpr bool is_noexcept = member_function_traits<T>::is_noexcept;
		static constexpr bool is_ref_qual_lvalue = member_function_traits<T>::is_ref_qual_lvalue;
		static constexpr bool is_ref_qual_rvalue = member_function_traits<T>::is_ref_qual_rvalue;
		using overload_tag_type = typename member_function_traits<T>::overload_tag_type;
	};

	template<typename R, typename... Args>
	struct function_traits<R(Args...)> {
		using class_type = void;
		using return_type = R;
		using ptr_type = R(*)(Args...);
		using arg_type = std::tuple<Args...>;
		using arg_ref_type = std::tuple<Args&...>;
		static constexpr bool is_member_function = false;
		static constexpr bool is_const = false;
		static constexpr bool is_noexcept = false;
		static constexpr bool is_ref_qual_lvalue = false;
		static constexpr bool is_ref_qual_rvalue = false;
		using overload_tag_type = stamp::reflect::tag::none_overload_tag_t;
	};
	template<typename R, typename... Args>
	struct function_traits<R(Args...) const> {
		using class_type = void;
		using return_type = R;
		using ptr_type = R(*)(Args...) const;
		using arg_type = std::tuple<Args...>;
		using arg_ref_type = std::tuple<Args&...>;
		static constexpr bool is_member_function = false;
		static constexpr bool is_const = true;
		static constexpr bool is_noexcept = false;
		static constexpr bool is_ref_qual_lvalue = false;
		static constexpr bool is_ref_qual_rvalue = false;
		using overload_tag_type = stamp::reflect::tag::const_overload_tag_t;
	};
	template<typename R, typename... Args>
	struct function_traits<R(Args...) noexcept> {
		using class_type = void;
		using return_type = R;
		using ptr_type = R(*)(Args...) noexcept;
		using arg_type = std::tuple<Args...>;
		using arg_ref_type = std::tuple<Args&...>;
		static constexpr bool is_member_function = false;
		static constexpr bool is_const = false;
		static constexpr bool is_noexcept = true;
		static constexpr bool is_ref_qual_lvalue = false;
		static constexpr bool is_ref_qual_rvalue = false;
		using overload_tag_type = stamp::reflect::tag::noexcept_overload_tag_t;
	};
	template<typename R, typename... Args>
	struct function_traits<R(Args...) const noexcept> {
		using class_type = void;
		using return_type = R;
		using ptr_type = R(*)(Args...) const noexcept;
		using arg_type = std::tuple<Args...>;
		using arg_ref_type = std::tuple<Args&...>;
		static constexpr bool is_member_function = false;
		static constexpr bool is_const = true;
		static constexpr bool is_noexcept = true;
		static constexpr bool is_ref_qual_lvalue = false;
		static constexpr bool is_ref_qual_rvalue = false;
		using overload_tag_type = stamp::reflect::tag::noexcept_overload_tag_t;
	};
}

#endif // STAMP_REFLECT_FUNCTION_TRAITS_H
