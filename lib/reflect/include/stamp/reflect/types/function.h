// stamp/reflect/types/reflect_function.h
#pragma once
#ifndef STAMP_REFLECT_TYPES_FUNCTION_H
#define STAMP_REFLECT_TYPES_FUNCTION_H

// need to add overloads for lvalue and rvalue stuff

#include<tuple>
#include<type_traits>
#include<stamp/reflect/reflect_helpers.h>
#include <stamp/reflect/string_literal.h>
#include <stamp/reflect/function_traits.h>
#include <stamp/reflect/types/tag.h>
#include <string>

namespace stamp::reflect {

	// TODO: implement getter setter attrib/tag traits for functions to act as member properties

	namespace tag {
		struct generic_function_attrib_t {};
		struct member_function_tag_t : generic_tag_t {};

		//struct swap_function_attrib_t : generic_function_attrib_t {};

		//inline struct swap_iterator_tag_t : member_function_tag_t {
		//	using attrib_type = swap_function_attrib_t;
		//} swap_rf;

		//template<> constexpr string_literal to_string_v<swap_iterator_tag_t> = "swap";
	}

	template<typename T, string_literal S, typename... Attr>
	struct member_function_t {
		using base_type = member_function_traits<T>::base_type;
		using return_type = member_function_traits<T>::return_type;
		using ptr_type = T;
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

		constexpr static const name_type& name() noexcept {
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
	template<typename T, string_literal S, typename... Arg>
	constexpr bool is_reflect_member_function_v<member_function_t<T, S, Arg...>> = true;

	template<typename T>
	struct is_reflect_member_function : std::bool_constant<is_reflect_member_function_v<T>> {};

	namespace concepts {
		template<typename T>
		concept reflect_member_function_c = is_reflect_member_function_v<T>;
	}

	// string literal reflect
	template<string_literal S, is_member_function_c T, typename... Attr>
	constexpr member_function_t<T, S, Attr...> reflect_member_function(T member_ptr, Attr... attr) {
		return { member_ptr, attr... };
	}

	// generic reflect member function
	template<is_tag_c Tag, is_member_function_c T, typename... Attr>
	constexpr auto reflect(Tag, T member_ptr, Attr... attr) {
		if constexpr (requires { typename Tag::attrib_type; }) {
			using attrib = typename Tag::attrib_type;
			return reflect_member_function<tag::to_string_v<Tag>>(member_ptr, attrib{}, attr...);
		}
		// TODO: check if i really need this case
		else if constexpr (requires { typename Tag::template attrib_type<Tag>; }) {
			using attrib = typename Tag::template attrib_type<Tag>;
			return reflect_member_function<tag::to_string_v<Tag>>(member_ptr, attrib{}, attr...);
		}
		else {
			return reflect_member_function<tag::to_string_v<Tag>>(member_ptr, attr...);
		}
	}


	// overload none
	template<typename... Arg, is_tag_c Tag, typename R, typename B, typename... Attr>
	constexpr auto reflect(tag::none_overload_tag_t, Tag t, R(B::* member_ptr)(Arg...), Attr... attr) {
		return reflect(t, member_ptr, attr...);
	}
	template<typename... Arg, is_tag_c Tag, typename R, typename B, typename... Attr>
	constexpr auto reflect(tag::none_overload_tag_t, Tag t, R(B::* member_ptr)(Arg...) noexcept, Attr... attr) {
		return reflect(t, member_ptr, attr...);
	}


	// overload const
	template<typename... Arg, is_tag_c Tag, typename R, typename B, typename... Attr>
	constexpr auto reflect(tag::const_overload_tag_t, Tag t, R(B::* member_ptr)(Arg...) const, Attr... attr) {
		return reflect(t, member_ptr, attr...);
	}
	template<typename... Arg, is_tag_c Tag, typename R, typename B, typename... Attr>
	constexpr auto reflect(tag::const_overload_tag_t, Tag t, R(B::* member_ptr)(Arg...) const noexcept, Attr... attr) {
		return reflect(t, member_ptr, attr...);
	}

	// TODO: add lvalue and rvalue overloads


	template<typename T, string_literal S, typename... Attr>
	struct free_function_t {
		using return_type = function_traits<T>::return_type;
		using ptr_type = T;
		using arg_type = function_traits<T>::arg_type;

		using attrib_type = std::tuple<Attr...>;

		static constexpr std::size_t name_size = S.size();
		using name_type = decltype(S);

		static constexpr name_type _name = S;
		ptr_type _member_ptr;
		attrib_type _attributes;

		constexpr free_function_t(ptr_type member_ptr, Attr... attributes) :
			_member_ptr(member_ptr),
			_attributes(attributes...) {
		}

		constexpr static const name_type& name() noexcept {
			return _name;
		}
		const ptr_type& member_ptr() const noexcept {
			return _member_ptr;
		}
		const attrib_type& attributes() const noexcept {
			return _attributes;
		}
	};

	template<string_literal S, is_free_function_c T, typename... Attr>
	constexpr free_function_t<T, S, Attr...> reflect_free_function(T free_ptr, Attr... attr) {
		return {free_ptr, attr...};
	}

	// generic reflect member function
	template<is_tag_c Tag, is_free_function_c T, typename... Attr>
	constexpr auto reflect(Tag, T free_ptr, Attr... attr) {
		if constexpr (requires { typename Tag::attrib_type; }) {
			using attrib = typename Tag::attrib_type;
			return reflect_free_function<tag::to_string_v<Tag>>(free_ptr, attrib{}, attr...);
		}
		// TODO: check if i really need this case
		else if constexpr (requires { typename Tag::template attrib_type<Tag>; }) {
			using attrib = typename Tag::template attrib_type<Tag>;
			return reflect_free_function<tag::to_string_v<Tag>>(free_ptr, attrib{}, attr...);
		}
		else {
			return reflect_free_function<tag::to_string_v<Tag>>(free_ptr, attr...);
		}
	}
}

#endif // STAMP_REFLECT_TYPES_FUNCTION_H
