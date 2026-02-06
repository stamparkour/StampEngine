#ifndef STAMP_MATH_TUPLE_BASE_H
#define STAMP_MATH_TUPLE_BASE_H

namespace stamp::math {
	namespace detail {
		template<typename ValT, unsigned Dim>
		struct tuple_base_generic {
			using value_type = ValT;
			static constexpr unsigned dimensions = Dim;
		};
	}

	template<typename ValT, unsigned Dim>
	struct tuple_base : detail::tuple_base_generic<ValT, Dim> {
		union {
			value_type i[dimensions];
			struct {
				value_type x, y, z, w, u, v;
			};
		};
	};
	template<typename ValT>
	struct tuple_base<ValT, 6> : detail::tuple_base_generic<ValT, 6> {
		union {
			value_type i[dimensions];
			struct {
				value_type x, y, z, w, u, v;
			};
		};
	};
	template<typename ValT>
	struct tuple_base<ValT, 5> : detail::tuple_base_generic<ValT, 5> {
		union {
			value_type i[dimensions];
			struct {
				value_type x, y, z, w, u;
			};
		};
	};
	template<typename ValT>
	struct tuple_base<ValT, 4> : detail::tuple_base_generic<ValT, 4> {
		union {
			value_type i[dimensions];
			struct {
				value_type x, y, z, w;
			};
		};
	};
	template<typename ValT>
	struct tuple_base<ValT, 3> : detail::tuple_base_generic<ValT, 3> {
		union {
			value_type i[dimensions];
			struct {
				value_type x, y, z;
			};
		};
	};
	template<typename ValT>
	struct tuple_base<ValT, 2> : detail::tuple_base_generic<ValT, 2> {
		union {
			value_type i[dimensions];
			struct {
				value_type x, y;
			};
		};
	};
	template<typename ValT>
	struct tuple_base<ValT, 1> : detail::tuple_base_generic<ValT, 1> {
		union {
			value_type i[dimensions];
			struct {
				value_type x;
			};
		};
	};
	template<typename ValT>
	struct tuple_base<ValT, 0> : detail::tuple_base_generic<ValT, 0> {
		static_assert(false, "dimensions must be greater than 0");
	};
}

#endif // STAMP_MATH_TUPLE_BASE_H