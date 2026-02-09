#ifndef STAMP_MATH_TUPLE_BASE_H
#define STAMP_MATH_TUPLE_BASE_H

namespace stamp::math::detail {
	template<typename ValT, unsigned Dim>
	struct tuple_base {
		using value_type = ValT;
		static constexpr unsigned dimensions = Dim;
		union {
			value_type _array[dimensions];
			struct {
				value_type x, y, z, w, u, v, t;
			};
		};
	};
	template<typename ValT>
	struct tuple_base<ValT, 6> {
		using value_type = ValT;
		static constexpr unsigned dimensions = 6;
		union {
			value_type _array[dimensions];
			struct {
				value_type x, y, z, w, u, v;
			};
		};
	};
	template<typename ValT>
	struct tuple_base<ValT, 5> {
		using value_type = ValT;
		static constexpr unsigned dimensions = 5;
		union {
			value_type _array[dimensions];
			struct {
				value_type x, y, z, w, u;
			};
		};
	};
	template<typename ValT>
	struct tuple_base<ValT, 4> {
		using value_type = ValT;
		static constexpr unsigned dimensions = 4;
		union {
			value_type _array[dimensions];
			struct {
				value_type x, y, z, w;
			};
		};
	};
	template<typename ValT>
	struct tuple_base<ValT, 3> {
		using value_type = ValT;
		static constexpr unsigned dimensions = 3;
		union {
			value_type _array[dimensions];
			struct {
				value_type x, y, z;
			};
		};
	};
	template<typename ValT>
	struct tuple_base<ValT, 2> {
		using value_type = ValT;
		static constexpr unsigned dimensions = 2;
		union {
			value_type _array[dimensions];
			struct {
				value_type x, y;
			};
		};
	};
	template<typename ValT>
	struct tuple_base<ValT, 1> {
		using value_type = ValT;
		static constexpr unsigned dimensions = 1;
		union {
			value_type _array[dimensions];
			struct {
				value_type x;
			};
		};
	};
	template<typename ValT>
	struct tuple_base<ValT, 0> {
		using value_type = ValT;
		static constexpr unsigned dimensions = 0;
		static_assert(false, "dimensions must be greater than 0");
	};

	template<typename DstT, typename ValT>
	struct tuple_comma_constructor {
		DstT* dst;
		int index = 0;
		tuple_comma_constructor(DstT& dst, int start = 0) {
			this->dst = &dst;
			this->index = start;
		}
		tuple_comma_constructor& operator,(const ValT& v) {
			(*dst)[index] = v;
			index++;
			return *this;
		}
	};
}

#endif // STAMP_MATH_TUPLE_BASE_H