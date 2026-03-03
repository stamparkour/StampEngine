#pragma once
#ifndef STAMP_REFLECT_PROPERTY_H
#define STAMP_REFLECT_MEMBER_H

#include<tuple>
#include <stamp/reflect/string_literal.h>
#include<type_traits>

namespace stamp::reflect {
	template<typename B, typename T, string_literal S, typename... Arg>
	struct member_property_t {
		using class_type = B;
		using value_type = T;
		using ptr_type = T B::*;
		using attrib_type = std::tuple<Arg...>;
		using name_type = decltype(S);
		static constexpr std::size_t name_size = S.size();
	private:
		static constexpr name_type _name = S;
		ptr_type _ptr;
		attrib_type _attributes;
	public:

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
	constexpr member_property_t<B, T, S, Attr...> reflect(T B::* member_ptr, Attr... attr) {
		return { member_ptr, attr... };
	}
}

#endif // STAMP_REFLECT_MEMBER_H
