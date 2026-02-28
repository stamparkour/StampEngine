#pragma once
#ifndef STAMP_REFLECT_CONSTRUCTOR_H
#define STAMP_REFLECT_CONSTRUCTOR_H

#include<tuple>
#include<type_traits>
#include "function.h"

namespace stamp::reflect {

	namespace detail {
		template<typename R, typename... Arg>
		consteval auto expand_tuple_to_constructor_ptr_f(std::tuple<Arg...>) {
			return [](Arg... arg) -> R {
				return R{ arg ... };
			};
		}

		template<typename R, typename Tuple>
		constexpr auto expand_tuple_to_constructor_ptr_v = expand_tuple_to_constructor_ptr_f<R>(Tuple{});
		template<typename R, typename Tuple>
		using expand_tuple_to_constructor_ptr_type_v = decltype(expand_tuple_to_constructor_ptr_v<R, Tuple>);
	}
	template<typename B, typename Arg, typename... Attr>
	struct member_constructor_t {
		using class_type = B;
		using arg_type = Arg;
		using attrib_type = std::tuple<Attr...>;

		using ptr_type = detail::expand_tuple_to_constructor_ptr_type_v<B, arg_type>;
	private:
		attrib_type _attributes;
	public:
		constexpr member_constructor_t(Attr... attributes) :
			_attributes(attributes...) {
		}

		constexpr auto name() const noexcept {
			return reflect_name_v<B>;
		}
		constexpr ptr_type member_ptr() const noexcept {
			return detail::expand_tuple_to_constructor_ptr_v<B, arg_type>;
		}
		const attrib_type& attributes() const noexcept {
			return _attributes;
		}
	};

	template<typename B, typename... Arg, typename... Attr>
	constexpr member_constructor_t<B, std::tuple<Arg...>, Attr...> reflect_constructor(Attr... attr) {
		return { attr... };
	}


}

#endif // STAMP_REFLECT_CONSTRUCTOR_H