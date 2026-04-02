#pragma once
#ifndef STAMP_REFLECT_FUNCTION_H
#define STAMP_REFLECT_FUNCTION_H

// need to add overloads for lvalue and rvalue stuff

#include<tuple>
#include<type_traits>
#include<stamp/reflect/reflect_helpers.h>
#include<stamp/reflect/reflect_ctypes.h>
#include <stamp/reflect/string_literal.h>
#include <stamp/reflect/member_function_traits.h>
#include "tag.h"
#include <string>

namespace stamp::reflect {


	template<typename T, string_literal S, typename... Attr>
	struct member_function_t {
		using base_type = member_function_traits<T>::base_type;
		using return_type = member_function_traits<T>::return_type;
		using ptr_type = T;
		using static_ptr_type = T;
		using arg_type = member_function_traits<T>::arg_type;

		using attrib_type = std::tuple<Attr...>;

		static constexpr std::size_t name_size = S.size();
		using name_type = decltype(S);

		static constexpr name_type _name = S;
		ptr_type _member_ptr;
		attrib_type _attributes;

		constexpr member_function_t(ptr_type member_ptr, Attr... attributes) :
			_member_ptr(member_ptr),
			_attributes(attributes...) {
		}

		consteval static const name_type& name() noexcept {
			return _name;
		}
		const ptr_type& member_ptr() const noexcept {
			return _member_ptr;
		}
		const attrib_type& attributes() const noexcept {
			return _attributes;
		}
	};

	template<typename T>
	constexpr bool is_reflect_member_function_v = false;
	template<typename T, std::size_t N, typename... Arg>
	constexpr bool is_reflect_member_function_v<member_function_t<T, N, Arg...>> = true;

	template<typename T>
	struct is_reflect_member_function : std::bool_constant<is_reflect_member_function_v<T>> {};

	namespace concepts {
		template<typename T>
		concept reflect_member_function_c = is_reflect_member_function_v<T>;
	}

	// string literal reflect
	template<string_literal S, concepts::is_member_function_traits_c T, typename... Attr>
	constexpr member_function_t<T, S, Attr...> reflect_member_function(T member_ptr, Attr... attr) {
		return { member_ptr, attr... };
	}

	// generic reflect member function
	template<concepts::is_tag_c Tag, concepts::is_member_function_traits_c T, typename... Attr>
	constexpr auto reflect(Tag, T member_ptr, Attr... attr) {
		if constexpr (requires { typename Tag::attrib_type; }) {
			using attrib = typename Tag::attrib_type;
			return reflect_member_function<tag::to_string_v<Tag>>(member_ptr, attrib{}, attr...);
		}
		else if constexpr (requires { typename Tag::template attrib_type<Tag>; }) {
			using attrib = typename Tag::template attrib_type<Tag>;
			return reflect_member_function<tag::to_string_v<Tag>>(member_ptr, attrib{}, attr...);
		}
		else {
			return reflect_member_function<tag::to_string_v<Tag>>(member_ptr, attr...);
		}
	}


	// overload none
	template<typename... Arg, concepts::is_tag_c Tag, typename R, typename B, typename... Attr>
	constexpr auto reflect(tag::none_overload_tag_t, Tag t, R(B::* member_ptr)(Arg...), Attr... attr) {
		return reflect(t, member_ptr, attr...);
	}
	template<typename... Arg, concepts::is_tag_c Tag, typename R, typename B, typename... Attr>
	constexpr auto reflect(tag::none_overload_tag_t, Tag t, R(B::* member_ptr)(Arg...) noexcept, Attr... attr) {
		return reflect(t, member_ptr, attr...);
	}


	// overload const
	template<typename... Arg, concepts::is_tag_c Tag, typename R, typename B, typename... Attr>
	constexpr auto reflect(tag::const_overload_tag_t, Tag t, R(B::* member_ptr)(Arg...) const, Attr... attr) {
		return reflect(t, member_ptr, attr...);
	}
	template<typename... Arg, concepts::is_tag_c Tag, typename R, typename B, typename... Attr>
	constexpr auto reflect(tag::const_overload_tag_t, Tag t, R(B::* member_ptr)(Arg...) const noexcept, Attr... attr) {
		return reflect(t, member_ptr, attr...);
	}
}

#endif // STAMP_REFLECT_MEMBER_H
