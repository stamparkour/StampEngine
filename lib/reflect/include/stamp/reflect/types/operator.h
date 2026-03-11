#pragma once
#ifndef STAMP_REFLECT_OPERATOR_H
#define STAMP_REFLECT_OPERATOR_H

// need to add overloads for lvalue and rvalue stuff

#include<tuple>
#include<type_traits>
#include<stamp/reflect/string_literal.h>
#include "function.h"

namespace stamp::reflect {


	template<typename O>
	struct function_operator_attrib {
		using operator_type = O;
		static constexpr string_literal name = tag::to_string_v<O>;
	};


	template<typename T>
	constexpr bool is_function_operator_attrib_v = false;
	template<typename O>
	constexpr bool is_function_operator_attrib_v<function_operator_attrib<O>> = true;


	template<typename T>
	struct is_function_operator_attrib : std::bool_constant<is_function_operator_attrib_v<T>> {};

	namespace concepts {
		template<typename T>
		concept function_operator_attrib_c = is_function_operator_attrib_v<T>;
	}
}

#endif // STAMP_REFLECT_OPERATOR_H
