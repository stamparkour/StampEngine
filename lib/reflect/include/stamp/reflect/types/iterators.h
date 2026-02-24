#pragma once
#ifndef STAMP_REFLECT_ITERATOR_H
#define STAMP_REFLECT_ITERATOR_H

#include<tuple>
#include<type_traits>
#include<stamp/reflect/string_literal.h>
#include "function.h"

namespace stamp::reflect {
	struct function_begin_attrib {};
	struct function_end_attrib {};
	struct function_cbegin_attrib {};
	struct function_cend_attrib {};
	struct function_rbegin_attrib {};
	struct function_rend_attrib {};
	struct function_crbegin_attrib {};
	struct function_crend_attrib {};
}

#endif // STAMP_REFLECT_ITERATOR_H