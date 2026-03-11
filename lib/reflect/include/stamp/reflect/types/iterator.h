#pragma once
#ifndef STAMP_REFLECT_ITERATOR_H
#define STAMP_REFLECT_ITERATOR_H

#include<tuple>
#include<type_traits>
#include<stamp/reflect/string_literal.h>
#include "function.h"
#include "tag.h"

namespace stamp::reflect {
	template<typename T>
	struct function_iterator_attrib {
		using iterator_type = T;
		static constexpr string_literal name = tag::to_string_v<T>;

	};

	template<typename T>
	constexpr bool is_function_iterator_attrib_v = false;
	template<typename O>
	constexpr bool is_function_iterator_attrib_v<function_iterator_attrib<O>> = true;


	template<typename T>
	struct is_function_iterator_attrib : std::bool_constant<is_function_iterator_attrib_v<T>> {};

	namespace concepts {
		template<typename T>
		concept function_iterator_attrib_c = is_function_iterator_attrib_v<T>;
	}
}

#endif // STAMP_REFLECT_ITERATOR_H
