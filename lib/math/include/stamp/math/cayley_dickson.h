#ifndef STAMP_MATH_CAYLEY_DICKSON_H
#define STAMP_MATH_CAYLEY_DICKSON_H

#include <stamp/math/tuple_base.h>
#include <cmath>
#include <array>
#include <type_traits>
#include <initializer_list>

namespace stamp::math {
	namespace detail {
		template<typename ValT, unsigned Dim>
		struct cayley_dickson_construct_base {
			using value_type = ValT;
			static constexpr unsigned dimensions = Dim;
			union {
				value_type _array[dimensions];
				struct {
					value_type r, x, y, z, w, u, v, t;
				};
			};
			cayley_dickson_construct_base() : _array{} {}
		};
		template<typename ValT>
		struct cayley_dickson_construct_base<ValT, 7> {
			using value_type = ValT;
			static constexpr unsigned dimensions = 7;
			union {
				value_type _array[dimensions];
				struct {
					value_type r, x, y, z, w, u, v;
				};
			};
			cayley_dickson_construct_base() : _array{} {}
		};
		template<typename ValT>
		struct cayley_dickson_construct_base<ValT, 6> {
			using value_type = ValT;
			static constexpr unsigned dimensions = 6;
			union {
				value_type _array[dimensions];
				struct {
					value_type r, x, y, z, w, u;
				};
			};
			cayley_dickson_construct_base() : _array{} {}
		};
		template<typename ValT>
		struct cayley_dickson_construct_base<ValT, 5> {
			using value_type = ValT;
			static constexpr unsigned dimensions = 5;
			union {
				value_type _array[dimensions];
				struct {
					value_type r, x, y, z, w;
				};
			};
			cayley_dickson_construct_base() : _array{} {}
		};
		template<typename ValT>
		struct cayley_dickson_construct_base<ValT, 4> {
			using value_type = ValT;
			static constexpr unsigned dimensions = 4;
			union {
				value_type _array[dimensions];
				struct {
					value_type r, x, y, z;
				};
			};
			cayley_dickson_construct_base() : _array{} {}
		};
		template<typename ValT>
		struct cayley_dickson_construct_base<ValT, 3> {
			using value_type = ValT;
			static constexpr unsigned dimensions = 3;
			union {
				value_type _array[dimensions];
				struct {
					value_type r, x, y;
				};
			};
			cayley_dickson_construct_base() : _array{} {}
		};
		template<typename ValT>
		struct cayley_dickson_construct_base<ValT, 2> {
			using value_type = ValT;
			static constexpr unsigned dimensions = 2;
			union {
				value_type _array[dimensions];
				struct {
					value_type r, x;
				};
			};
			cayley_dickson_construct_base() : _array{} {}
		};
		template<typename ValT>
		struct cayley_dickson_construct_base<ValT, 1> {
			using value_type = ValT;
			static constexpr unsigned dimensions = 1;
			union {
				value_type _array[dimensions];
				struct {
					value_type r;
				};
			};
			cayley_dickson_construct_base() : _array{} {}
		};
		template<typename ValT>
		struct cayley_dickson_construct_base<ValT, 0> {
			using value_type = ValT;
			static constexpr unsigned dimensions = 0;
			static_assert(false, "dimensions must be greater than 0");
		};
	}

	template<typename ValT, unsigned Dim>
	struct cayley_dickson_construct : detail::cayley_dickson_construct_base<ValT, Dim> {
		using value_type = ValT;
		static constexpr unsigned dimensions = Dim;
		static constexpr unsigned dim_power_two = std::ceil(std::log2(dimensions));
		static constexpr unsigned full_dimension = 1 << dim_power_two;
		static constexpr unsigned left_dimension = full_dimension / 2;
		static constexpr unsigned right_dimension = dimensions - left_dimension;

		cayley_dickson_construct() {}
		cayley_dickson_construct(ValT v) : detail::cayley_dickson_construct_base<ValT, Dim>::_array{ v } {}
		cayley_dickson_construct(std::initializer_list<ValT> l) requires(l.size() <= dimensions) {
			auto lb = l.begin();
			auto b = this->_array.begin();
			for (; lb != l.end() && b != this->_array.end(); ++lb, ++b) {
				*b = *lb;
			}
		}
		template<typename... ArgT> requires (sizeof...(args) <= dimensions)
		cayley_dickson_construct(ArgT... args) : detail::cayley_dickson_construct_base<ValT, Dim>::_array { static_cast<ValT>(args)... } {}
		template<typename ValT2, unsigned Dim2> requires std::is_convertible_v<ValT2, ValT> && (Dim2 <= dimensions)
		cayley_dickson_construct(const cayley_dickson_construct<ValT2, dimensions>& q) : detail::cayley_dickson_construct_base<ValT, Dim>::_array{} {
			for (unsigned i = 0; i < std::min(dimensions, Dim2); ++i) {
				this->_array[i] = static_cast<ValT>(q[i]);
			}
		}

		template<typename ValTO>
		explicit operator cayley_dickson_construct<ValTO, dimensions>() const {
			cayley_dickson_construct<ValTO, dimensions> o;
			for (unsigned i = 0; i < dimensions; ++i) {
				o[i] = static_cast<ValTO>(this->_array[i]);
			}
			return o;
		}
		template<typename ValTO>
		explicit operator ValTO() const {
			return static_cast<ValTO>(this->_array[0]);
		}


		const value_type& operator[](unsigned index) const {
			return this->_array[index];
		}
		value_type& operator[](unsigned index) {
			
			return this->_array[index];
		}
		template<unsigned Index>
		const value_type& get() const {
			return std::get<Index>(this->array);
		}
		template<unsigned Index>
		value_type& get() {
			return std::get<Index>(this->array);
		}
		auto begin() {
			return std::begin(this->_array);
		}
		auto end() {
			return std::end(this->_array);
		}

		const cayley_dickson_construct<value_type, left_dimension>& left() const {
			return *static_cast<const cayley_dickson_construct<value_type, left_dimension>*>(&this->array[0]);
		}
		cayley_dickson_construct<value_type, left_dimension>& left() {
			return *static_cast<cayley_dickson_construct<value_type, left_dimension>*>(&this->array[0]);
		}
		const cayley_dickson_construct<value_type, right_dimension>& right() const {
			return *static_cast<cayley_dickson_construct<value_type, right_dimension>*>(&this->array[left_dimension]);
		}
		cayley_dickson_construct<value_type, right_dimension>& right() {
			return *static_cast<cayley_dickson_construct<value_type, right_dimension>*>(&this->array[left_dimension]);
		}

		stamp::math::detail::tuple_comma_constructor<cayley_dickson_construct<value_type, dimensions>, ValT> operator<<(ValT) {
			return {*this};
		}

		cayley_dickson_construct<ValT, Dim> operator~() const;
		cayley_dickson_construct<ValT, Dim> operator-() const {
			cayley_dickson_construct<value_type, dimensions> o;
			for (auto oi = o.begin(), i = begin(); oi != o.end() && i != end(); ++oi, ++i) {
				*oi = *i;
			}
			return o;
		}
		cayley_dickson_construct<ValT, Dim> operator+() const {
			return *this;
		}

		template<typename ValT2, unsigned Dim2> requires (Dim2 <= dimensions)
		cayley_dickson_construct<ValT, Dim>& operator+=(const cayley_dickson_construct<ValT2, Dim2>& q) {
			for (auto qi = q.begin(), i = begin(); qi != q.end(); ++qi, ++i) {
				*i += *qi;
			}
			return *this;
		}
		template<typename ValT2, unsigned Dim2> requires (Dim2 <= dimensions)
		cayley_dickson_construct<ValT, Dim>& operator-=(const cayley_dickson_construct<ValT2, Dim2>& q) {
			for (auto qi = q.begin(), i = begin(); qi != q.end(); ++qi, ++i) {
				*i -= *qi;
			}
			return *this;
		}
		template<typename ValT2, unsigned Dim2> requires (Dim2 <= Dim)
		cayley_dickson_construct<ValT, Dim>& operator*=(const cayley_dickson_construct<ValT2, Dim2>&);
		template<typename ValT2, unsigned Dim2> requires (Dim2 <= Dim)
		cayley_dickson_construct<ValT, Dim>& operator/=(const cayley_dickson_construct<ValT2, Dim2>&);
	};

	template<typename T>
	using quaternion = cayley_dickson_construct<T, 4>;
	template<typename T>
	using complex = cayley_dickson_construct<T, 2>;

	namespace literals {
		cayley_dickson_construct<long double, 2> operator ""i(long double v) {
			return { 0, v };
		}
		cayley_dickson_construct<long double, 3> operator ""j(long double v) {
			return { 0, 0, v };
		}
		cayley_dickson_construct<long double, 4> operator ""k(long double v) {
			return { 0, 0, 0, v };
		}
	}

	template<typename ValT1, unsigned Dim1, typename ValT2, unsigned Dim2, typename ValTO = std::common_type_t<ValT1, ValT2>, unsigned DimO = std::max(Dim1, Dim2)>
	cayley_dickson_construct<ValTO, DimO> operator+(const cayley_dickson_construct<ValT1, Dim1>&, const cayley_dickson_construct<ValT2, Dim2>&);
	template<typename ValT1, unsigned Dim1, typename ValT2, unsigned Dim2, typename ValTO = std::common_type_t<ValT1, ValT2>, unsigned DimO = std::max(Dim1, Dim2)>
	cayley_dickson_construct<ValTO, DimO> operator-(const cayley_dickson_construct<ValT1, Dim1>&, const cayley_dickson_construct<ValT2, Dim2>&);
	template<typename ValT1, unsigned Dim1, typename ValT2, unsigned Dim2, typename ValTO = std::common_type_t<ValT1, ValT2>, unsigned DimO = std::max(Dim1, Dim2)>
	cayley_dickson_construct<ValTO, DimO> operator*(const cayley_dickson_construct<ValT1, Dim1>&, const cayley_dickson_construct<ValT2, Dim2>&);
	template<typename ValT1, unsigned Dim1, typename ValT2, unsigned Dim2, typename ValTO = std::common_type_t<ValT1, ValT2>, unsigned DimO = std::max(Dim1, Dim2)>
	cayley_dickson_construct<ValTO, DimO> operator/(const cayley_dickson_construct<ValT1, Dim1>&, const cayley_dickson_construct<ValT2, Dim2>&);

	template<typename ValT1, unsigned Dim, typename ValT2, typename ValTO = std::common_type_t<ValT1, ValT2>>
	cayley_dickson_construct<ValTO, Dim> operator+(const cayley_dickson_construct<ValT1, Dim>&, ValT2);
	template<typename ValT1, unsigned Dim, typename ValT2, typename ValTO = std::common_type_t<ValT1, ValT2>>
	cayley_dickson_construct<ValTO, Dim> operator-(const cayley_dickson_construct<ValT1, Dim>&, ValT2);
	template<typename ValT1, unsigned Dim, typename ValT2, typename ValTO = std::common_type_t<ValT1, ValT2>>
	cayley_dickson_construct<ValTO, Dim> operator*(const cayley_dickson_construct<ValT1, Dim>&, ValT2);
	template<typename ValT1, unsigned Dim, typename ValT2, typename ValTO = std::common_type_t<ValT1, ValT2>>
	cayley_dickson_construct<ValTO, Dim> operator/(const cayley_dickson_construct<ValT1, Dim>&, ValT2);

	template<typename ValT1, typename ValT2, unsigned Dim, typename ValTO = std::common_type_t<ValT1, ValT2>>
	cayley_dickson_construct<ValTO, Dim> operator+(ValT1, const cayley_dickson_construct<ValT2, Dim>&);
	template<typename ValT1, typename ValT2, unsigned Dim, typename ValTO = std::common_type_t<ValT1, ValT2>>
	cayley_dickson_construct<ValTO, Dim> operator-(ValT1, const cayley_dickson_construct<ValT2, Dim>&);
	template<typename ValT1, typename ValT2, unsigned Dim, typename ValTO = std::common_type_t<ValT1, ValT2>>
	cayley_dickson_construct<ValTO, Dim> operator*(ValT1, const cayley_dickson_construct<ValT2, Dim>&);
	template<typename ValT1, typename ValT2, unsigned Dim, typename ValTO = std::common_type_t<ValT1, ValT2>>
	cayley_dickson_construct<ValTO, Dim> operator/(ValT1, const cayley_dickson_construct<ValT2, Dim>&);

	template<typename ValT>
	ValT conjugate(const ValT& v) {
		return v;
	}
	template<typename ValT, unsigned Dim>
	cayley_dickson_construct<ValT, Dim> conjugate(const cayley_dickson_construct<ValT, Dim>& q) {
		cayley_dickson_construct<ValT, Dim> o;
		o[0] = q[0];
		for (unsigned i = 1; i < Dim; ++i) {
			o[i] = -q[i]
		}
		return q;
	}
	template<typename ValT>
	ValT norm2(const ValT& v) {
		return v * conjugate(v);
	}
	template<typename ValT, unsigned Dim>
	ValT norm2(const cayley_dickson_construct<ValT, Dim>& q) {
		return q * conjugate(q);
	}
	template<typename ValT>
	ValT norm(const ValT& v) {
		return std::sqrt(norm2(v));
	}
	template<typename ValT, unsigned Dim>
	ValT norm(const cayley_dickson_construct<ValT, Dim>& q) {
		return std::sqrt(norm2(q));
	}
	template<typename ValT> requires requires(ValT v) { std::abs(v); }
	ValT norm(const ValT& v) {
		return std::abs(v);
	}
	template<typename ValT>
	ValT normal(const ValT& v) {
		return v / norm(v);
	}
	template<typename ValT> requires std::is_integral_v<ValT> || std::is_floating_point_v<ValT>
	ValT normal(const ValT& v) {
		return 1;
	}
	template<typename ValT>
	ValT inverse(const ValT& v) {
		return 1 / v;
	}
	template<typename ValT, unsigned Dim>
	cayley_dickson_construct<ValT, Dim> inverse(const cayley_dickson_construct<ValT, Dim>& q) {
		return q / norm2(q);
	}
	template<typename ValT> requires requires(ValT v) { std::exp(v); }
	ValT exp(const ValT& v) {
		return std::exp(v);
	}
	template<typename ValT, unsigned Dim>
	cayley_dickson_construct<ValT, Dim> exp(const cayley_dickson_construct<ValT, Dim>& q) {
		cayley_dickson_construct<ValT, Dim> v = q;
		v[0] = 0;
		auto n = norm(v);
		return exp(q[0]) * (std::cos(n) + v * std::sin(n) / n);
	}
	template<typename ValT> requires requires(ValT v) { std::log(v); }
	ValT log(const ValT& v) {
		return std::log(v);
	}
	template<typename ValT, unsigned Dim>
	cayley_dickson_construct<ValT, Dim> log(const cayley_dickson_construct<ValT, Dim>& v) {
		cayley_dickson_construct<ValT, Dim> v = q;
		v[0] = 0;
		auto qn = norm(q);
		auto n = norm(n);
		return log(qn) + n * std::acos(v[0] / qn);
	}

	
}

template<typename ValT, unsigned Dim>
inline cayley_dickson_construct<ValT, Dim> stamp::math::cayley_dickson_construct<ValT, Dim>::operator~() const {
	return conjugate(*this);
}
template<typename ValT, unsigned Dim>
template<typename ValT2, unsigned Dim2> requires (Dim2 <= Dim)
inline cayley_dickson_construct<ValT, Dim>& stamp::math::cayley_dickson_construct<ValT, Dim>::operator*=(const cayley_dickson_construct<ValT2, Dim2>& q) {
	if constexpr (Dim == 1) {
		(*this)[0] *= q[0];
	}
	else if constexpr (Dim == 2) {
		auto l = (*this)[0];
		(*this)[0] = (*this)[0] * q[0] - (*this)[1] * q[1];
		(*this)[1] = (*this)[1] * q[0] + l * q[1];
	}
	else {
		auto l = left();
		left() *= q.left();
		left() -= ~q.right() * right();
		right() *= ~q.left();
		right += d * l;
	}
	return *this;
}
template<typename ValT, unsigned Dim>
template<typename ValT2, unsigned Dim2> requires (Dim2 <= Dim)
inline cayley_dickson_construct<ValT, Dim>& stamp::math::cayley_dickson_construct<ValT, Dim>::operator/=(const cayley_dickson_construct<ValT2, Dim2>&) {
	*this *= inverse(q);
	return *this;
}

template<typename ValT1, unsigned Dim1, typename ValT2, unsigned Dim2, typename ValTO, unsigned DimO>
cayley_dickson_construct<ValTO, DimO> stamp::math::operator*(const cayley_dickson_construct<ValT1, Dim1>& a, const cayley_dickson_construct<ValT2, Dim2>& b) {
	auto o = a;
	o *= b;
	return o;
}

#endif // STAMP_MATH_CAYLEY_DICKSON_H