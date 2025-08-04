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


// provides short names for v types and functions
// #define STAMP_MATH_MATRIX_SHORT_NAMES

// makes all comparison operators prefer equal_aprox
// #define STAMP_MATH_VECTOR_EQUAL_APROX

//optional headers: <iostream> <string>
#include <stamp/math/define.h>
#include <stdexcept>
#include <stamp/math/vector.h>
#include <stamp/math/rect.h>

STAMP_MATH_NAMESPACE_BEGIN

template<Quantity T = STAMP_DEFAULT_FLOATINGPOINT, size_t Rows = 2, size_t Cols = Rows>
struct Matrix;
STAMP_TEMPLATE_ALL_QUANTITY_TEMPLATED(Matrix, template<size_t Rows COMMA size_t Cols = Rows>, COMMA Rows COMMA Cols);
template<Quantity T>
using Matrix2 = Matrix<T,2>;
STAMP_TEMPLATE_ALL_QUANTITY(Matrix2);
template<Quantity T>
using Matrix3 = Matrix<T, 3>;
STAMP_TEMPLATE_ALL_QUANTITY(Matrix3);
template<Quantity T>
using Matrix4 = Matrix<T, 4>;
STAMP_TEMPLATE_ALL_QUANTITY(Matrix4);

#ifdef STAMP_MATH_MATRIX_SHORT_NAMES
template<Quantity T = STAMP_DEFAULT_FLOATINGPOINT, size_t Rows = 2, size_t Cols = Rows>
using Mat = Matrix<T, Rows, Cols>;
STAMP_TEMPLATE_ALL_QUANTITY_TEMPLATED(Mat, template<size_t Rows COMMA size_t Cols = Rows>, COMMA Rows COMMA Cols);
template<Quantity T>
using Mat2 = Mat<T, 2>;
STAMP_TEMPLATE_ALL_QUANTITY(Matrix2);
template<Quantity T>
using Mat3 = Mat<T, 3>;
STAMP_TEMPLATE_ALL_QUANTITY(Matrix3);
template<Quantity T>
using Mat4 = Mat<T, 4>;
STAMP_TEMPLATE_ALL_QUANTITY(Matrix4);
#endif

template<Quantity T, size_t Rows, size_t Cols>
struct Matrix;

template<typename M, typename T, size_t Rows, size_t Cols>
struct Matrix_Base {
	operator const T* () const noexcept;
	operator T* () noexcept;
	Vector<T, Rows>& operator [] (size_t i) const noexcept;
	template<Quantity T1, size_t R1, size_t C1> explicit operator Matrix<T1, R1, C1>();
};

template<Quantity T, size_t Rows, size_t Cols>
struct Matrix : Matrix_Base<Matrix<T, Rows, Cols>, T, Rows, Cols> {
	T m[Rows][Cols] = {};
	Matrix() = default;
	Matrix(const T(&values)[Rows][Cols]) noexcept : m(values) {}
	Matrix(std::initializer_list<T> values) { 
		if (values.size() != Cols * Rows) 
			throw new std::length_error("Requires Cols * Rows elements."); 
		std::copy(values.begin(), values.end(), (T*)&m); 
	}

	const static Matrix<T, Rows, Cols> IDENTITY;
};

template<Quantity T, size_t Rows>
struct Matrix<T, Rows, 1> : Matrix_Base<Matrix<T, Rows, 1>, T, Rows, 1> {
	constexpr static size_t Cols = 1;
	union {
		T m[Rows][Cols] = {};
		Vector<T, Rows> v;
	};
	Matrix() = default;
	Matrix(const T(&values)[Rows][Cols]) noexcept : m(values) {}
	Matrix(std::initializer_list<T> values) {
		if (values.size() != Cols * Rows) 
			throw new std::length_error("Requires Cols * Rows elements.");
		std::copy(values.begin(), values.end(), (T*)&m);
	}
	explicit Matrix(const Vector<T, Rows>& m) noexcept;

	const static Matrix<T, Rows, 1> IDENTITY;
};

template<Quantity T, size_t Cols>
struct Matrix<T, 1, Cols> : Matrix_Base<Matrix<T, 1, Cols>, T, 1, Cols> {
	constexpr static size_t Rows = 1;
	union {
		T m[Rows][Cols] = {};
		Vector<T, Cols> v;
	};
	Matrix() = default;
	Matrix(const T(&values)[Rows][Cols]) noexcept : m(values) {}
	Matrix(std::initializer_list<T> values) {
		if (values.size() != Cols * Rows) 
			throw new std::length_error("Requires Cols * Rows elements.");
		std::copy(values.begin(), values.end(), (T*)&m);
	}
	explicit Matrix(const Vector<T, Cols>& m) noexcept;

	const static Matrix<T, 1, Cols> IDENTITY;
};

template<Quantity T>
struct Matrix<T, 1, 1> : Matrix_Base<Matrix<T, 1, 1>, T, 1, 1> {
	constexpr static size_t Cols = 1;
	constexpr static size_t Rows = 1;
	union {
		T m[Rows][Cols] = {};
		T x;
	};

	Matrix() = default;
	Matrix(const T(&values)[Rows][Cols]) noexcept : m(values) {}
	Matrix(std::initializer_list<T> values) {
		if (values.size() != Cols * Rows) throw new std::length_error("Requires Cols * Rows elements.");
		std::copy(values.begin(), values.end(), (T*)&m);
	}

	const static Matrix<T, 1, 1> IDENTITY;
};

template<Quantity T, size_t Rows, size_t Cols, size_t C>	Matrix<T, Rows, C>			operator		*	(const Matrix<T, Rows, Cols>& a, const Matrix<T, Cols, C>& b)		noexcept;
template<Quantity T, size_t Q>								Vector<T, Q>				operator		*	(const Matrix<T, Q, Q>& a, const Vector<T, Q>& b)					noexcept;
template<Quantity T, size_t Q>								Vector<T, Q>				operator		*	(const Vector<T, Q>& b, const Matrix<T, Q, Q>& a)					noexcept;
template<Quantity T, size_t Q>								Matrix<T, Q>&				operator		*=	(Matrix<T, Q>& a, const Matrix<T, Q>& b)							noexcept;
template<Quantity T, size_t Rows, size_t Cols>				Matrix<T, Rows, Cols>		operator		+	(const Matrix<T, Cols, Rows>& a, const Matrix<T, Cols, Rows>& b)	noexcept;
template<Quantity T, size_t Rows, size_t Cols>				Matrix<T, Rows, Cols>&		operator		+=	(Matrix<T, Rows, Cols>& a, const Matrix<T, Rows, Cols>& b)			noexcept;
template<Quantity T, size_t Rows, size_t Cols>				Matrix<T, Rows, Cols>		operator		-	(const Matrix<T, Rows, Cols>& a, const Matrix<T, Rows, Cols>& b)	noexcept;
template<Quantity T, size_t Rows, size_t Cols>				Matrix<T, Rows, Cols>&		operator		-=	(Matrix<T, Rows, Cols>& a, const Matrix<T, Rows, Cols>& b)			noexcept;
template<Quantity T, size_t Rows, size_t Cols>				Matrix<T, Rows, Cols>		operator		-	(const Matrix<T, Rows, Cols>& a)									noexcept;

template<Quantity T, size_t Rows, size_t Cols>				Matrix<T, Cols, Rows>		transpose			(const Matrix<T, Rows, Cols>& m)									noexcept;
template<Quantity T, size_t Q>								Matrix<T, Q>				determinant			(const Matrix<T, Q>& m)												noexcept;
template<Quantity T, size_t Rows, size_t Cols>				Matrix<T, Rows, Cols>		toRowEchelonForm	(const Matrix<T, Rows, Cols>& m)									noexcept;
template<Quantity T, size_t Q>								bool						inverse				(const Matrix<T, Q>& m, Matrix<T, Q>* o)							noexcept;

STAMP_MATH_NAMESPACE_END
STAMP_MATH_MATRIX_NAMESPACE_BEGIN
using namespace ::STAMP_MATH_NAMESPACE;

template<Quantity T>										Matrix4<T>					PerspectiveProjection(T right, T left, T top, T bottom, T _near, T _far)				noexcept;
template<Quantity T>										Matrix4<T>					PerspectiveProjection(T right, T left, T top, T bottom, T ratio, T _near, T _far)		noexcept;
template<Quantity T>										Matrix4<T>					PerspectiveProjection(T fovx, T ratio, T _near, T _far)									noexcept;
template<Quantity T>										Matrix4<T>					OrthographicProjection(T scaleX, T ratio, T nearPlane, T farPlane)						noexcept;
template<Quantity T>										Matrix4<T>					Scale				(const Vector3<T>& v)												noexcept;
template<Quantity T>										Matrix4<T>					Translate			(const Vector3<T>& v)												noexcept;
template<Quantity T>										Matrix4<T>					RotationX			(T v)																noexcept;
template<Quantity T>										Matrix4<T>					RotationY			(T v)																noexcept;
template<Quantity T>										Matrix4<T>					RotationZ			(T v)																noexcept;
template<Quantity T>										Matrix4<T>					Rotation(const Vector3<T>& v, RotationOrder order = STAMP_DEFAULT_ROTATION_ORDER)		noexcept;

STAMP_MATH_MATRIX_NAMESPACE_END
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
Vector<T, Rows>& Matrix_Base<M, T, Rows, Cols>::operator [] (size_t i) const noexcept {
	auto self = static_cast<T*>(this);
	return (Vector<T, Rows>&)(self->m[i][0]);
}
template<typename M, typename T, size_t Rows, size_t Cols>
template<Quantity T1, size_t R1, size_t C1> 
Matrix_Base<M, T, Rows, Cols>::operator Matrix<T1, R1, C1>() {
	auto self = static_cast<T*>(this);
	Matrix<T1, R1, C1> o;
	for (size_t i = 0; i < R1; ++i)
		for (size_t j = 0; j < C1; ++j)
			o.m[i][j] = (i < Rows && j < Cols ? static_cast<T1>(self->m[i][j]) : 0);
	return o;
}

// Vertical 1D Matrix Logic
template<Quantity T, size_t Rows>
inline Matrix<T, Rows, 1>::Matrix(const Vector<T, Rows>& m) noexcept {
	for (size_t i = 0; i < Rows; ++i) {
		this->m[i][0] = m.V[i];
	}
}
// Horizontal 1D Matrix Logic
template<Quantity T, size_t Cols>
inline Matrix<T, 1, Cols>::Matrix(const Vector<T, Cols>& m) noexcept {
	for (size_t i = 0; i < Cols; ++i) {
		this->m[0][i] = m.V[i];
	}
}
// Generic Logic
template<Quantity T, size_t Rows, size_t Cols, size_t C>
inline Matrix<T, Rows, C> operator*(const Matrix<T, Rows, Cols>& a, const Matrix<T, Cols, C>& b) noexcept {
	Matrix<T, Rows, C> o;
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < C; j++) {
			T v = 0;
			for (int k = 0; k < Cols; k++) v += a.m[i][k] * b.m[k][j];
			o.m[i][j] = v;
		}
	}
	return o;
}
template<Quantity T, size_t Rows, size_t Cols>
inline Matrix<T, Rows, Cols> operator+(const Matrix<T, Rows, Cols>& a, const Matrix<T, Cols, Rows>& b)  noexcept {
	Matrix<T, Rows, Cols> result;
	for (size_t i = 0; i < Rows; ++i) {
		for (size_t j = 0; j < Cols; ++j) {
			result.m[i][j] = a.m[i][j] + b.m[i][j];
		}
	}
	return result;
}
template<Quantity T, size_t Rows, size_t Cols>
inline Matrix<T, Rows, Cols>& operator+=(Matrix<T, Rows, Cols>& a, const Matrix<T, Cols, Rows>& b) noexcept {
	return a = a + b;
}
template<Quantity T, size_t Rows, size_t Cols>
inline Matrix<T, Rows, Cols> operator-(const Matrix<T, Rows, Cols>& a, const Matrix<T, Cols, Rows>& b) noexcept {
	Matrix<T, Rows, Cols> result;
	for (size_t i = 0; i < Rows; ++i) {
		for (size_t j = 0; j < Cols; ++j) {
			result.m[i][j] = a.m[i][j] - b.m[i][j];
		}
	}
	return result;
}
template<Quantity T, size_t Rows, size_t Cols>
inline Matrix<T, Rows, Cols>& operator-=(Matrix<T, Rows, Cols>& a, const Matrix<T, Cols, Rows>& b) noexcept {
	return a = a - b;
}
template<Quantity T, size_t Rows, size_t Cols>
inline Matrix<T, Rows, Cols> operator-(const Matrix<T, Rows, Cols>& a) noexcept {
	Matrix<T, Rows, Cols> result;
	for (size_t i = 0; i < Rows; ++i) {
		for (size_t j = 0; j < Cols; ++j) {
			result.m[i][j] =  -a.m[i][j];
		}
	}
	return result;
}
template<Quantity T, size_t Q>
inline Vector<T, Q> operator*(const Matrix<T, Q, Q>& a, const Vector<T, Q>& b) noexcept {
	Matrix<T, Q, 1> B{ b };
	Matrix<T, Q, 1> result = a * B;
	return result.v;
}
template<Quantity T, size_t Q>
inline Vector<T, Q> operator*(const Vector<T, Q>& b, const Matrix<T, Q, Q>& a) noexcept {
	Matrix<T, 1, Q> B{ b };
	Matrix<T, 1, Q> result = B * a;
	return result.v;
}
template<Quantity T, size_t Q>
inline Matrix<T, Q>& operator*=(Matrix<T, Q>& a, const Matrix<T, Q>& b) noexcept {
	return a = a * b;
}

template<Quantity T, size_t Rows, size_t Cols>
inline const Matrix<T, Rows, Cols> Matrix<T, Rows, Cols>::IDENTITY = []() {
	Matrix<T, Rows, Cols> o;
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			o.m[i][j] = (i == j) ? 1 : 0;
		}
	}
	return o;
};

template<Quantity T, size_t Rows, size_t Cols>
inline Matrix<T, Cols, Rows> transpose(const Matrix<T, Rows, Cols>& m) noexcept {
	Matrix<T, Cols, Rows> result;
	for (size_t i = 0; i < Rows; ++i) {
		for (size_t j = 0; j < Cols; ++j) {
			result.m[j][i] = m.m[i][j];
		}
	}
	return result;
}
template<Quantity T, size_t Q>
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
template<Quantity T, size_t Q>
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
STAMP_MATH_MATRIX_NAMESPACE_BEGIN
using namespace ::STAMP_MATH_NAMESPACE;

template<Quantity T>
inline Matrix4<T> PerspectiveProjection(T right, T left, T top, T bottom, T _near, T _far) noexcept {
	return { 2 * _near / (right - left),0,(right + left) / (right - left),0,0,2 * _near / (top - bottom),(top + bottom) / (top - bottom),0,0,0,-(_far + _near) / (_far - _near),1,0,0,2 * _far * _near / (_far - _near),0 };
}
template<Quantity T>
inline Matrix4<T> PerspectiveProjection(T right, T left, T top, T bottom, T ratio, T _near, T _far) noexcept {
	right = tan(right);
	left = tan(left);
	top = tan(top) * ratio;
	bottom = tan(bottom) * ratio;
	return { 2 / (right - left),0,(right + left) / (right - left),0,0,2 / (top - bottom),(top + bottom) / (top - bottom),0,0,0,-(_far + _near) / (_far - _near),1,0,0,2 * _far * _near / (_far - _near),0 };
}
template<Quantity T>
inline Matrix4<T> PerspectiveProjection(T fovx, T ratio, T _near, T _far) noexcept {
	T tangent = tan(fovx / 2);
	return { ratio / tangent,0,0,0,0,1 / tangent,0,0,0,0,-(_near + _far) / (_far - _near),1,0,0,2 * _near * _far / (_far - _near),0 };
}
template<Quantity T>
inline Matrix4<T> OrthographicProjection(T scaleX, T ratio, T _nearPlane, T _farPlane) noexcept {
	return { ratio / scaleX,0,0,0,0,1 / scaleX,0,0,0,0,-2 / (_farPlane - _nearPlane),0,0,0,(_farPlane + _nearPlane) / (_farPlane - _nearPlane),1 };
}
template<Quantity T>
inline Matrix4<T> Scale(const Vector3<T>& v) noexcept {
	return { v.x,0,0,0,0,v.y,0,0,0,0,v.z,0,0,0,0,1 };
}
template<Quantity T>
inline Matrix4<T> Translate(const Vector3<T>& v) noexcept {
	return { 1,0,0,0,0,1,0,0,0,0,1,0,v.x,v.y,v.z,1 };
}
template<Quantity T>
inline Matrix4<T> RotationX(T v) noexcept {
	return { 1,0,0,0,0,cosf(v),sinf(v),0,0,-sinf(v),cosf(v),0,0,0,0,1 };
}
template<Quantity T>
inline Matrix4<T> RotationY(T v) noexcept {
	using namespace std;
	return { cos(v),0,-sin(v),0,0,1,0,0,sin(v),0,cos(v),0,0,0,0,1 };
}
template<Quantity T>
inline Matrix4<T> RotationZ(T v) noexcept {
	using namespace std;
	return { cos(v),sin(v),0,0,-sin(v),cos(v),0,0,0,0,1,0,0,0,0,1 };
}
template<Quantity T>
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

STAMP_MATH_MATRIX_NAMESPACE_END

#endif