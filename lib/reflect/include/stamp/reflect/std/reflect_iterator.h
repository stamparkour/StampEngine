#pragma once
#ifndef STAMP_REFLECT_STD_REFLECT_ITERATOR_H
#define STAMP_REFLECT_STD_REFLECT_ITERATOR_H

#include <stamp/reflect/reflect_traits.h>
#include <stamp/reflect/reflect_types.h>
#include <iterator>

namespace stamp::reflect {
	template<std::forward_iterator T>
	struct reflect_traits<T> {
		using type = T;
		using value_type = typename std::iterator_traits<T>::value_type;
		static constexpr string_literal space = "std::";
		static constexpr string_literal name = concat_cstring_v<"forward_iterator<", traits::name_v<value_type>, ">">;
		static constexpr string_literal full_name = concat_cstring_v<"std::forward_iterator<", traits::full_name_v<value_type>, ">">;
	};
	template<std::contiguous_iterator T>
	struct reflect_traits<T> { 
		using type = T;
		using value_type = typename std::iterator_traits<T>::value_type;
		static constexpr string_literal space = "std::";
		static constexpr string_literal name = concat_cstring_v<"contiguous_iterator<", traits::name_v<value_type>, ">">;
		static constexpr string_literal full_name = concat_cstring_v<"std::contiguous_iterator<", traits::full_name_v<value_type>, ">">;
	};
}

#endif // STAMP_REFLECT_STD_REFLECT_ITERATOR_H
