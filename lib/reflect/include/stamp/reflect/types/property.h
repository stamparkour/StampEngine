#pragma once
#ifndef STAMP_REFLECT_PROPERTY_H
#define STAMP_REFLECT_MEMBER_H

#include<tuple>
#include <stamp/reflect/string_literal.h>
#include<type_traits>

namespace stamp::reflect {
	template<typename B, typename T, std::size_t N, typename... Arg>
	struct member_property_t {
		using class_type = B;
		using value_type = T;
		using ptr_type = T B::*;
		using attrib_type = std::tuple<Arg...>;
		static constexpr std::size_t name_length = N;
		using name_type = string_literal<N>;
	private:
		name_type _name;
		ptr_type _ptr;
		attrib_type _attributes;
	public:

		constexpr member_property_t(string_literal<N> name, ptr_type ptr, Arg... attributes) :
			_name(name),
			_ptr(ptr),
			_attributes(attributes...) {
		}
		constexpr member_property_t(const char (&name)[N], ptr_type ptr, Arg... attributes) :
			_name(name),
			_ptr(ptr),
			_attributes(attributes...) {
		}

		const name_type& name() const noexcept {
			return _name;
		}
		const ptr_type& member_ptr() const noexcept {
			return _ptr;
		}
		const attrib_type& attributes() const noexcept {
			return _attributes;
		}
	};

	template<typename B, typename T, std::size_t N, typename... Attr>
	constexpr member_property_t<B, T, N, Attr...> reflect(const string_literal<N>& name, T B::* member_ptr, Attr... attr) {
		return { name, member_ptr, attr... };
	}
	template<typename B, typename T, std::size_t N, typename... Attr>
	constexpr auto reflect(const char (&name)[N], T B::* member_ptr, Attr... attr) {
		return reflect(string_literal{ name }, member_ptr, attr...);
	}
}

#endif // STAMP_REFLECT_MEMBER_H
