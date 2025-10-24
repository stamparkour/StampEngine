//stamp/math/matrix.h

#pragma once
#ifndef STAMP_MATH_MATRIX_H
#define STAMP_MATH_MATRIX_H

// Copyright 2025 Elijah Clark, Stamparkour
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


// provides short names for types and functions
// #define STAMP_MATH_MATRIX_SHORT_NAMES

// makes all comparison operators prefer equal_aprox
// #define STAMP_MATH_VECTOR_EQUAL_APROX

//optional headers: <iostream> <string>
#include <stamp/math/define.h>
#include <initializer_list>
#include <stamp/math/vector.h>

STAMP_MATH_NAMESPACE_BEGIN

template<typename T = STAMP_DEFAULT_FLOATINGPOINT, size_t R = 2, size_t C = R>
struct Matrix;
STAMP_TEMPLATE_ALL_QUANTITY_TEMPLATED(Matrix, template<size_t Rows COMMA size_t Cols = Rows>, COMMA Rows COMMA Cols);
template<typename T = STAMP_DEFAULT_FLOATINGPOINT>
using Matrix2 = Matrix<T,2>;
STAMP_TEMPLATE_ALL_QUANTITY(Matrix2);
template<typename T = STAMP_DEFAULT_FLOATINGPOINT>
using Matrix3 = Matrix<T, 3>;
STAMP_TEMPLATE_ALL_QUANTITY(Matrix3);
template<typename T = STAMP_DEFAULT_FLOATINGPOINT>
using Matrix4 = Matrix<T, 4>;
STAMP_TEMPLATE_ALL_QUANTITY(Matrix4);

#ifdef STAMP_MATH_MATRIX_SHORT_NAMES
template<typename T = STAMP_DEFAULT_FLOATINGPOINT, size_t Rows = 2, size_t Cols = Rows>
using Mat = Matrix<T, Rows, Cols>;
STAMP_TEMPLATE_ALL_QUANTITY_TEMPLATED(Mat, template<size_t Rows COMMA size_t Cols = Rows>, COMMA Rows COMMA Cols);
template<typename T = STAMP_DEFAULT_FLOATINGPOINT>
using Mat2 = Mat<T, 2>;
STAMP_TEMPLATE_ALL_QUANTITY(Matrix2);
template<typename T = STAMP_DEFAULT_FLOATINGPOINT>
using Mat3 = Mat<T, 3>;
STAMP_TEMPLATE_ALL_QUANTITY(Matrix3);
template<typename T = STAMP_DEFAULT_FLOATINGPOINT>
using Mat4 = Mat<T, 4>;
STAMP_TEMPLATE_ALL_QUANTITY(Matrix4);
#endif

template<typename T, size_t Rows, size_t Cols>
struct Matrix;

template<typename M, typename T, size_t Rows, size_t Cols>
struct Matrix_Base {
	operator const T* () const noexcept;
	operator T* () noexcept;
	const Vector<T, Rows>& operator [] (size_t i) const noexcept;
	Vector<T, Rows>& operator [] (size_t i) noexcept;
	const T& operator [] (size_t i, size_t j) const noexcept;
	T& operator [] (size_t i, size_t j) noexcept;
	template<typename T1, size_t R1, size_t C1> explicit operator Matrix<T1, R1, C1>();

	Matrix_Base() requires Field<T> {}
};

template<typename T, size_t R, size_t C>
struct Matrix : Matrix_Base<Matrix<T, R, C>, T, R, C> {
	constexpr static size_t Cols = C;
	constexpr static size_t Rows = R;

	T m[Rows][Cols] = {};
	Matrix() = default;
	Matrix(const T(&values)[Rows][Cols]) noexcept : m(values) {}
	Matrix(const std::initializer_list<T> values) { 
		static_assert(values.size() == Cols * Rows && "Requires Cols * Rows elements.");
		std::copy(values.begin(), values.end(), (T*)&m); 
	}

	const static Matrix<T, Rows, Cols> IDENTITY;
};

template<typename T, size_t R>
struct Matrix<T, R, 1> : Matrix_Base<Matrix<T, R, 1>, T, R, 1> {
	constexpr static size_t Cols = 1;
	constexpr static size_t Rows = R;

	union {
		T m[Rows][Cols] = {};
		Vector<T, Rows> v;
	};
	Matrix() = default;
	Matrix(const T(&values)[Rows][Cols]) noexcept : m(values) {}
	Matrix(const std::initializer_list<T> values) {
		static_assert(values.size() == Cols * Rows && "Requires Cols * Rows elements.");
		std::copy(values.begin(), values.end(), (T*)&m);
	}
	explicit Matrix(const Vector<T, Rows>& m) noexcept;

	const static Matrix<T, Rows, 1> IDENTITY;
};

template<typename T, size_t C>
struct Matrix<T, 1, C> : Matrix_Base<Matrix<T, 1, C>, T, 1, C> {
	constexpr static size_t Cols = C;
	constexpr static size_t Rows = 1;

	union {
		T m[Rows][Cols] = {};
		Vector<T, Cols> v;
	};
	Matrix() = default;
	Matrix(const T(&values)[Rows][Cols]) noexcept : m(values) {}
	Matrix(const std::initializer_list<T> values) {
		static_assert(values.size() == Cols * Rows && "Requires Cols * Rows elements.");
		std::copy(values.begin(), values.end(), (T*)&m);
	}
	explicit Matrix(const Vector<T, Cols>& m) noexcept;

	const static Matrix<T, 1, Cols> IDENTITY;
};

template<typename T>
struct Matrix<T, 1, 1> : Matrix_Base<Matrix<T, 1, 1>, T, 1, 1> {
	constexpr static size_t Cols = 1;
	constexpr static size_t Rows = 1;

	union {
		T m[Rows][Cols] = {};
		T x;
	};

	Matrix() = default;
	Matrix(const T(&values)[Rows][Cols]) noexcept : m(values) {}
	Matrix(const std::initializer_list<T> values) {
		static_assert(values.size() == Cols * Rows && "Requires Cols * Rows elements.");
		std::copy(values.begin(), values.end(), (T*)&m);
	}

	const static Matrix<T, 1, 1> IDENTITY;
};

template<size_t Rows, size_t Cols, size_t C, typename T1, typename T2, typename TR = std::common_type_t<T1, T2>>	Matrix<TR, Rows, C>		operator *	(const Matrix<T1, Rows, Cols>& a, const Matrix<T2, Cols, C>& b)		noexcept;
template<size_t Rows, size_t Cols, typename T1, typename T2, typename TR = std::common_type_t<T1, T2>>				Vector<TR, Rows>			operator *	(const Matrix<T1, Rows, Cols>& a, const Vector<T2, Cols>& b)	noexcept;
template<size_t Rows, size_t Cols, typename T1, typename T2, typename TR = std::common_type_t<T1, T2>>				Vector<TR, Cols>			operator *	(const Vector<T1, Rows>& b, const Matrix<T2, Rows, Cols>& a)	noexcept;
template<size_t Rows, size_t Cols, typename T1, typename T2, typename TR = std::common_type_t<T1, T2>>				Matrix<TR, Rows, Cols>	operator +	(const Matrix<T1, Cols, Rows>& a, const Matrix<T2, Cols, Rows>& b)	noexcept;
template<size_t Rows, size_t Cols, typename T1, typename T2, typename TR = std::common_type_t<T1, T2>>				Matrix<TR, Rows, Cols>	operator -	(const Matrix<T1, Rows, Cols>& a, const Matrix<T2, Rows, Cols>& b)	noexcept;
template<size_t Rows, size_t Cols, typename T1, typename T2, typename TR = std::common_type_t<T1, T2>>				Matrix<TR, Rows, Cols>	operator -	(const Matrix<T1, Rows, Cols>& a)									noexcept;
template<size_t Rows, size_t Cols, typename T1, typename T2>				Matrix<T1, Rows, Cols>& operator -=	(Matrix<T1, Rows, Cols>& a, const Matrix<T2, Rows, Cols>& b)	noexcept;
template<size_t Rows, size_t Cols, typename T1, typename T2>				Matrix<T1, Rows, Cols>& operator +=	(Matrix<T1, Rows, Cols>& a, const Matrix<T2, Rows, Cols>& b)	noexcept;
template<size_t Q, typename T1, typename T2>								Matrix<T1, Q>&			operator *=	(Matrix<T1, Q>& a, const Matrix<T2, Q>& b)						noexcept;

template<typename T, size_t Rows, size_t Cols>	Matrix<T, Cols, Rows>		transpose			(const Matrix<T, Rows, Cols>& m)			noexcept;
template<typename T, size_t Q>					Matrix<T, Q>				determinant			(const Matrix<T, Q>& m)						noexcept;
template<typename T, size_t Rows, size_t Cols>	Matrix<T, Rows, Cols>		toRowEchelonForm	(const Matrix<T, Rows, Cols>& m)			noexcept;
template<typename T, size_t Q>					bool						inverse				(const Matrix<T, Q>& m, Matrix<T, Q>* o)	noexcept;

STAMP_MATH_NAMESPACE_END
STAMP_MATH_MATRIX4_NAMESPACE_BEGIN
using namespace ::STAMP_MATH_NAMESPACE;

template<typename T>										Matrix4<T>					PerspectiveProjection(T right, T left, T top, T bottom, T _near, T _far)				noexcept;
template<typename T>										Matrix4<T>					PerspectiveProjection(T right, T left, T top, T bottom, T ratio, T _near, T _far)		noexcept;
template<typename T>										Matrix4<T>					PerspectiveProjection(T fovx, T ratio, T _near, T _far)									noexcept;
template<typename T>										Matrix4<T>					OrthographicProjection(T scaleX, T ratio, T nearPlane, T farPlane)						noexcept;
template<typename T>										Matrix4<T>					Scale				(const Vector3<T>& v)												noexcept;
template<typename T>										Matrix4<T>					Translate			(const Vector3<T>& v)												noexcept;
template<typename T>										Matrix4<T>					RotationX			(T v)																noexcept;
template<typename T>										Matrix4<T>					RotationY			(T v)																noexcept;
template<typename T>										Matrix4<T>					RotationZ			(T v)																noexcept;
template<typename T>										Matrix4<T>					Rotation(const Vector3<T>& v, RotationOrder order = STAMP_DEFAULT_ROTATION_ORDER)		noexcept;

STAMP_MATH_MATRIX4_NAMESPACE_END
//Definition
STAMP_MATH_NAMESPACE_BEGIN

// Matrix Base Logic
template<typename M, typename T, size_t Rows, size_t Cols>
Matrix_Base<M, T, Rows, Cols>::operator const T* () const noexcept {
	auto self = static_cast<const T*>(this);
	return &(self->m[0][0]);
}
template<typename M, typename T, size_t Rows, size_t Cols>
Matrix_Base<M, T, Rows, Cols>::operator T* () noexcept {
	auto self = static_cast<T*>(this);
	return &(self->m[0][0]);
}
template<typename M, typename T, size_t Rows, size_t Cols>
const Vector<T, Rows>& Matrix_Base<M, T, Rows, Cols>::operator [] (size_t i) const noexcept {
	auto self = static_cast<T*>(this);
	return (const Vector<T, Rows>&)(self->m[i][0]);
}
template<typename M, typename T, size_t Rows, size_t Cols>
Vector<T, Rows>& Matrix_Base<M, T, Rows, Cols>::operator [] (size_t i) noexcept {
	auto self = static_cast<T*>(this);
	return (Vector<T, Rows>&)(self->m[i][0]);
}
template<typename M, typename T, size_t Rows, size_t Cols>
const T& Matrix_Base<M, T, Rows, Cols>::operator [] (size_t i, size_t j) const noexcept {
	auto self = static_cast<T*>(this);
	return (const T&)(self->m[i][j]);
}
template<typename M, typename T, size_t Rows, size_t Cols>
T& Matrix_Base<M, T, Rows, Cols>::operator [] (size_t i, size_t j) noexcept {
	auto self = static_cast<T*>(this);
	return (T&)(self->m[i][j]);
}
template<typename M, typename T, size_t Rows, size_t Cols>
template<typename T1, size_t R1, size_t C1> 
Matrix_Base<M, T, Rows, Cols>::operator Matrix<T1, R1, C1>() {
	auto self = static_cast<T*>(this);
	Matrix<T1, R1, C1> o;
	for (size_t i = 0; i < R1; ++i)
		for (size_t j = 0; j < C1; ++j)
			o.m[i][j] = (i < Rows && j < Cols ? static_cast<T1>(self->m[i][j]) : 0);
	return o;
}

// Vertical 1D Matrix Logic
template<typename T, size_t Rows>
inline Matrix<T, Rows, 1>::Matrix(const Vector<T, Rows>& m) noexcept {
	for (size_t i = 0; i < Rows; ++i) {
		this->m[i][0] = m.V[i];
	}
}
// Horizontal 1D Matrix Logic
template<typename T, size_t Cols>
inline Matrix<T, 1, Cols>::Matrix(const Vector<T, Cols>& m) noexcept {
	for (size_t i = 0; i < Cols; ++i) {
		this->m[0][i] = m.V[i];
	}
}
// Generic Logic
template<size_t Rows, size_t Cols, size_t C, typename T1, typename T2, typename TR>
inline Matrix<TR, Rows, C> operator*(const Matrix<T1, Rows, Cols>& a, const Matrix<T2, Cols, C>& b) noexcept {
	Matrix<TR, Rows, C> o;
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < C; j++) {
			TR v = 0;
			for (int k = 0; k < Cols; k++) v += (TR)(a.m[i][k] * b.m[k][j]);
			o.m[i][j] = v;
		}
	}
	return o;
}
template<size_t Rows, size_t Cols, typename T1, typename T2, typename TR>
inline Matrix<TR, Rows, Cols> operator+(const Matrix<T1, Rows, Cols>& a, const Matrix<T2, Cols, Rows>& b)  noexcept {
	Matrix<TR, Rows, Cols> result;
	for (size_t i = 0; i < Rows; ++i) {
		for (size_t j = 0; j < Cols; ++j) {
			result.m[i][j] = (TR)(a.m[i][j] + b.m[i][j]);
		}
	}
	return result;
}
template<size_t Rows, size_t Cols, typename T1, typename T2>
inline Matrix<T1, Rows, Cols>& operator+=(Matrix<T1, Rows, Cols>& a, const Matrix<T2, Cols, Rows>& b) noexcept {
	return a = a + b;
}
template<size_t Rows, size_t Cols, typename T1, typename T2, typename TR>
inline Matrix<TR, Rows, Cols> operator-(const Matrix<T1, Rows, Cols>& a, const Matrix<T2, Cols, Rows>& b) noexcept {
	Matrix<TR, Rows, Cols> result;
	for (size_t i = 0; i < Rows; ++i) {
		for (size_t j = 0; j < Cols; ++j) {
			result.m[i][j] = a.m[i][j] - b.m[i][j];
		}
	}
	return result;
}
template<size_t Rows, size_t Cols, typename T1, typename T2>
inline Matrix<T1, Rows, Cols>& operator-=(Matrix<T1, Rows, Cols>& a, const Matrix<T2, Cols, Rows>& b) noexcept {
	return a = a - b;
}
template<typename T, size_t Rows, size_t Cols>
inline Matrix<T, Rows, Cols> operator-(const Matrix<T, Rows, Cols>& a) noexcept {
	Matrix<T, Rows, Cols> result;
	for (size_t i = 0; i < Rows; ++i) {
		for (size_t j = 0; j < Cols; ++j) {
			result.m[i][j] =  -a.m[i][j];
		}
	}
	return result;
}
template<size_t Rows, size_t Cols, typename T1, typename T2, typename TR> 
inline Vector<TR, Rows> operator *(const Matrix<T1, Rows, Cols>& a, const Vector<T2, Cols>& b) noexcept {
	Matrix<T2, Cols, 1> B{ b };
	Matrix<TR, Rows, 1> result = a * B;
	return result.v;
}
template<size_t Rows, size_t Cols, typename T1, typename T2, typename TR>
inline Vector<TR, Cols> operator *(const Vector<T2, Rows>& a, const Matrix<T1, Rows, Cols>& b) noexcept {
	Matrix<T1, 1, Rows> B{ b };
	Matrix<TR, 1, Cols> result = B * a;
	return result.v;
}
template<size_t Q, typename T1, typename T2>
inline Matrix<T1, Q>& operator*=(Matrix<T1, Q>& a, const Matrix<T2, Q>& b) noexcept {
	return a = a * b;
}

template<typename T, size_t Rows, size_t Cols>
inline const Matrix<T, Rows, Cols> Matrix<T, Rows, Cols>::IDENTITY = []() {
	Matrix<T, Rows, Cols> o;
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			o.m[i][j] = (i == j) ? 1 : 0;
		}
	}
	return o;
};

template<typename T, size_t Rows, size_t Cols>
inline Matrix<T, Cols, Rows> transpose(const Matrix<T, Rows, Cols>& m) noexcept {
	Matrix<T, Cols, Rows> result;
	for (size_t i = 0; i < Rows; ++i) {
		for (size_t j = 0; j < Cols; ++j) {
			result.m[j][i] = m.m[i][j];
		}
	}
	return result;
}
template<typename T, size_t Q>
inline Matrix<T, Q> determinant(const Matrix<T, Q>& m) noexcept {
	T det = 0;
	for (int i = 0; i < Q; i++) {
		T q = 1;
		for (int j = 0; j < Q; j++) q *= m.m[(i + j % Q)][j];
		det += q;
	}
	for (int i = 0; i < Q; i++) {
		T q = 1;
		for (int j = 0; j < Q; j++) q *= m.m[(i - j % Q)][j];
		det -= q;
	}
}
template<typename T, size_t Q>
inline bool inverse(const Matrix<T, Q>& m, Matrix<T, Q>* o) noexcept {
	Matrix<T, Q, Q * 2> g;
	for (size_t i = 0; i < Q; i++) {
		for (size_t j = 0; j < Q; j++) {
			g.m[i][j] = m.m[i][j];
			g.m[i][j + Q] = (i == j) ? 1 : 0; // Identity matrix
		}
	}
	// Perform Gaussian elimination to convert to reduced row echelon form
	for (size_t i = 0; i < Q; i++) {
		// Find pivot
		T pivot = g.m[i][i];
		if (pivot == 0) {
			for (size_t j = i + 1; j < Q; j++) {
				if (g.m[j][i] != 0) {
					std::swap(g.m[i], g.m[j]);
					pivot = g.m[i][i];
					break;
				}
			}
		}
		if (pivot == 0) return false;

		// Normalize row
		for (size_t j = 0; j < Q * 2; j++) {
			g.m[i][j] /= pivot;
		}

		// Eliminate other rows
		for (size_t j = 0; j < Q; j++) {
			if (j != i) {
				T factor = g.m[j][i];
				for (size_t k = 0; k < Q * 2; k++) {
					g.m[j][k] -= factor * g.m[i][k];
				}
			}
		}
	}

	// Extract the inverse matrix
	if (o == nullptr) return true;
	for (size_t i = 0; i < Q; i++) {
		for (size_t j = 0; j < Q; j++) {
			o->m[i][j] = g.m[i][j + Q];
		}
	}
	return true;
}


STAMP_MATH_NAMESPACE_END
STAMP_MATH_MATRIX4_NAMESPACE_BEGIN
using namespace ::STAMP_MATH_NAMESPACE;

template<typename T>
inline Matrix4<T> PerspectiveProjection(T right, T left, T top, T bottom, T _near, T _far) noexcept {
	return { 2 * _near / (right - left),0,(right + left) / (right - left),0,0,2 * _near / (top - bottom),(top + bottom) / (top - bottom),0,0,0,-(_far + _near) / (_far - _near),1,0,0,2 * _far * _near / (_far - _near),0 };
}
template<typename T>
inline Matrix4<T> PerspectiveProjection(T right, T left, T top, T bottom, T ratio, T _near, T _far) noexcept {
	right = tan(right);
	left = tan(left);
	top = tan(top) * ratio;
	bottom = tan(bottom) * ratio;
	return { 2 / (right - left),0,(right + left) / (right - left),0,0,2 / (top - bottom),(top + bottom) / (top - bottom),0,0,0,-(_far + _near) / (_far - _near),1,0,0,2 * _far * _near / (_far - _near),0 };
}
template<typename T>
inline Matrix4<T> PerspectiveProjection(T fovx, T ratio, T _near, T _far) noexcept {
	T tangent = tan(fovx / 2);
	return { ratio / tangent,0,0,0,0,1 / tangent,0,0,0,0,-(_near + _far) / (_far - _near),1,0,0,2 * _near * _far / (_far - _near),0 };
}
template<typename T>
inline Matrix4<T> OrthographicProjection(T scaleX, T ratio, T _nearPlane, T _farPlane) noexcept {
	return { ratio / scaleX,0,0,0,0,1 / scaleX,0,0,0,0,-2 / (_farPlane - _nearPlane),0,0,0,(_farPlane + _nearPlane) / (_farPlane - _nearPlane),1 };
}
template<typename T>
inline Matrix4<T> Scale(const Vector3<T>& v) noexcept {
	return { v.x,0,0,0,0,v.y,0,0,0,0,v.z,0,0,0,0,1 };
}
template<typename T>
inline Matrix4<T> Translate(const Vector3<T>& v) noexcept {
	return { 1,0,0,0,0,1,0,0,0,0,1,0,v.x,v.y,v.z,1 };
}
template<typename T>
inline Matrix4<T> RotationX(T v) noexcept {
	return { 1,0,0,0,0,cosf(v),sinf(v),0,0,-sinf(v),cosf(v),0,0,0,0,1 };
}
template<typename T>
inline Matrix4<T> RotationY(T v) noexcept {
	using namespace std;
	return { cos(v),0,-sin(v),0,0,1,0,0,sin(v),0,cos(v),0,0,0,0,1 };
}
template<typename T>
inline Matrix4<T> RotationZ(T v) noexcept {
	using namespace std;
	return { cos(v),sin(v),0,0,-sin(v),cos(v),0,0,0,0,1,0,0,0,0,1 };
}
template<typename T>
inline Matrix4<T> Rotation(const Vector3<T>& v, RotationOrder order) noexcept {
	switch (order) {
	case RotationOrder::XYZ:
		return RotationZ(v.z) * RotationY(v.y) * RotationX(v.x);
	case RotationOrder::XZY:
		return RotationY(v.y) * RotationZ(v.z) * RotationX(v.x);
	case RotationOrder::YXZ:
		return RotationZ(v.z) * RotationX(v.x) * RotationY(v.y);
	case RotationOrder::YZX:
		return RotationX(v.x) * RotationZ(v.z) * RotationY(v.y);
	case RotationOrder::ZXY:
		return RotationY(v.y) * RotationX(v.x) * RotationZ(v.z);
	case RotationOrder::ZYX:
		return RotationX(v.x) * RotationY(v.y) * RotationZ(v.z);
	}
}

STAMP_MATH_MATRIX4_NAMESPACE_END

#endif