#ifndef STAMP_MATH_CAYLEY_DICKSON_H
#define STAMP_MATH_CAYLEY_DICKSON_H

#include <stamp/math/tuple_base.h>
#include <cmath>

namespace stamp::math {
	namespace detail {
		template<typename ValT, unsigned Dim>
		struct cayley_dickson_construct_generic {
			using value_type = ValT;
			static constexpr unsigned dimensions = dim;
			static constexpr unsigned dim_power_two = ceil(log2(dim));
			static constexpr unsigned full_dimension = 1 << dim_power_two;
			static constexpr unsigned left_dimension = full_dimension / 2;
			static constexpr unsigned right_dimension = dimensions - left_dimension;
		};

		template<typename ValT, unsigned Dim>
		struct cayley_dickson_construct_base : cayley_dickson_construct_generic<ValT, Dim> {
			
		};
	}

	template<typename ValT, unsigned Dim>
	struct cayley_dickson_construct {

	};
}

#endif // STAMP_MATH_CAYLEY_DICKSON_H