#pragma once
#ifndef STAMP_REFLECT_REFLECT_TYPES_H
#define STAMP_REFLECT_REFLECT_TYPES_H

#include "types/property.h"
#include "types/function.h"
#include "types/operator.h"
#include "types/constructor.h"

namespace stamp::reflect {
	template<typename T>
	struct is_const_type : std::bool_constant<T::is_const> {};
}

#endif // STAMP_REFLECT_REFLECT_TYPES_H