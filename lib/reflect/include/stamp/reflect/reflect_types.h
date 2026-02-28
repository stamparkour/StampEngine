#pragma once
#ifndef STAMP_REFLECT_REFLECT_TYPES_H
#define STAMP_REFLECT_REFLECT_TYPES_H

#include "types/property.h"
#include "types/function.h"
#include "types/operator.h"
#include "types/constructor.h"
#include "types/iterator.h"

namespace stamp::reflect::type {
	template<typename T, std::size_t N = T::name_length>
	inline string_literal<N> name(const T& t) {
		return t.name();
	}
	template<typename T, typename P = typename T::ptr_type>
	inline P member_ptr(const T& t) {
		return t.member_ptr();
	}
	template<typename T, typename A = typename T::attrib_type>
	inline A attributes(const T& t) {
		return t.attributes();
	}
}

#endif // STAMP_REFLECT_REFLECT_TYPES_H