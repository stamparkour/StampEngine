#pragma once
#include <math.h>
#include "glvec.h"

namespace gl_math {
	struct Mat4 final {

		float v1;
		float v2;
		float v3;
		float v4;
		float v5;
		float v6;
		float v7;
		float v8;
		float v9;
		float v10;
		float v11;
		float v12;
		float v13;
		float v14;
		float v15;
		float v16;
		//{ v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11,v12,v13,v14,v15,v16 };
		Mat4 operator +(const Mat4& b) const;
		Mat4 operator -(const Mat4& b) const;
		Mat4 operator -() const;
		Mat4 operator *(float v) const;
		Mat4 operator /(float v) const;
		Mat4 operator *(const Mat4& b) const;
		Vec4 operator *(const Vec4& b) const;
		Vec4 operator *(const Vec3& b) const;
		operator const float* () const;

		static Mat4 Perspective(float fovy, float ratio, float nearPlane, float farPlane);
		static Mat4 Orthographic(float scale, float ratio, float nearPlane, float farPlane);
		static Mat4 Scale(float x, float y, float z);
		static Mat4 Translate(float x, float y, float z);
		static Mat4 RotationX(float v);
		static Mat4 RotationY(float v);
		static Mat4 RotationZ(float v);
		static Mat4 RotationZXY(float x, float y, float z);

	} const Mat4_Identity{ 1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1 };
}