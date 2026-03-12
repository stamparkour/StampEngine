#pragma once
#ifndef STAMP_REFLECT_PROPERTY_H
#define STAMP_REFLECT_MEMBER_H

#include<tuple>
#include <stamp/reflect/string_literal.h>
#include "tag.h"
#include<type_traits>

namespace stamp::reflect {
	template<typename T>
	constexpr bool is_member_property_v = false;
	template<typename T, typename B>
	constexpr bool is_member_property_v<T B::*> = true;
	namespace concepts {
		template<typename T>
		concept is_member_property_c = is_member_property_v<T>;
	}

	template<typename B, typename T, string_literal S, typename... Arg>
	struct member_property_t {
		using class_type = B;
		using value_type = T;
		using ptr_type = T B::*;
		using attrib_type = std::tuple<Arg...>;
		using name_type = decltype(S);
		static constexpr std::size_t name_size = S.size();

		static constexpr name_type _name = S;
		ptr_type _ptr;
		attrib_type _attributes;

		constexpr member_property_t(ptr_type ptr, Arg... attributes) :
			_ptr(ptr),
			_attributes(attributes...) {
		}

		consteval static name_type name() noexcept {
			return _name;
		}
		const ptr_type& member_ptr() const noexcept {
			return _ptr;
		}
		const attrib_type& attributes() const noexcept {
			return _attributes;
		}
	};

	template<string_literal S, typename B, typename T, typename... Attr>
	constexpr member_property_t<B, T, S, Attr...> reflect_property(T B::* member_ptr, Attr... attr) {
		return { member_ptr, attr... };
	}

	template<concepts::is_tag_c O, typename B, typename T, typename... Attr>
	constexpr auto reflect(O, T B::* member_ptr, Attr... attr) {
		if constexpr (requires { typename O::attrib_type; }) {
			using attrib = typename O::attrib_type;
			return reflect_property<tag::to_string_v<O>>(member_ptr, attrib{}, attr...);
		}
		else if constexpr (requires { typename O::template attrib_type<O>; }) {
			using attrib = typename O::template attrib_type<O>;
			return reflect_property<tag::to_string_v<O>>(member_ptr, attrib{}, attr...);
		}
		else {
			return reflect_property<tag::to_string_v<O>>(member_ptr, attr...);
		}
	}
}

#endif // STAMP_REFLECT_MEMBER_H
