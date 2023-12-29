#pragma once
#include <math.h>
#include "glvec.h"

namespace gl_math {
	struct Mat4 {

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
		Mat4 operator +(const Mat4& b) const {
			return { v1 + b.v1,v2 + b.v2,v3 + b.v3,v4 + b.v4,v5 + b.v5,v6 + b.v6,v7 + b.v7,v8 + b.v8,v9 + b.v9,v10 + b.v10,v11 + b.v11,v12 + b.v12,v13 + b.v13,v14 + b.v14,v15 + b.v15,v16 + b.v16 };
		}
		Mat4 operator -(const Mat4& b) const {
			return { v1 - b.v1,v2 - b.v2,v3 - b.v3,v4 - b.v4,v5 - b.v5,v6 - b.v6,v7 - b.v7,v8 - b.v8,v9 - b.v9,v10 - b.v10,v11 - b.v11,v12 - b.v12,v13 - b.v13,v14 - b.v14,v15 - b.v15,v16 - b.v16 };
		}
		Mat4 operator -() const {
			return { -v1,-v2,-v3,-v4,-v5,-v6,-v7,-v8,-v9,-v10,-v11,-v12,-v13,-v14,-v15,-v16 };
		}
		Mat4 operator *(float v) const {
			return { v1 * v,v2 * v,v3 * v,v4 * v,v5 * v,v6 * v,v7 * v,v8 * v,v9 * v,v10 * v,v11 * v,v12 * v,v13 * v,v14 * v,v15 * v,v16 * v };
		}
		Mat4 operator /(float v) const {
			return { v1 / v,v2 / v,v3 / v,v4 / v,v5 / v,v6 / v,v7 / v,v8 / v,v9 / v,v10 / v,v11 / v,v12 / v,v13 / v,v14 / v,v15 / v,v16 / v };
		}
		Mat4 operator *(const Mat4& b) const {
			return {
				v1 * b.v1 + v5 * b.v2 + v9 * b.v3 + v13 * b.v4,v2 * b.v1 + v6 * b.v2 + v10 * b.v3 + v14 * b.v4,v3 * b.v1 + v7 * b.v2 + v11 * b.v3 + v15 * b.v4,v4 * b.v1 + v8 * b.v2 + v12 * b.v3 + v16 * b.v4,
				v1 * b.v5 + v5 * b.v6 + v9 * b.v7 + v13 * b.v8,v2 * b.v5 + v6 * b.v6 + v10 * b.v7 + v14 * b.v8,v3 * b.v5 + v7 * b.v6 + v11 * b.v7 + v15 * b.v8,v4 * b.v5 + v8 * b.v6 + v12 * b.v7 + v16 * b.v8,
				v1 * b.v9 + v5 * b.v10 + v9 * b.v11 + v13 * b.v12,v2 * b.v9 + v6 * b.v10 + v10 * b.v11 + v14 * b.v12,v3 * b.v9 + v7 * b.v10 + v11 * b.v11 + v15 * b.v12,v4 * b.v9 + v8 * b.v10 + v12 * b.v11 + v16 * b.v12,
				v1 * b.v13 + v5 * b.v14 + v9 * b.v15 + v13 * b.v16,v2 * b.v13 + v6 * b.v14 + v10 * b.v15 + v14 * b.v16,v3 * b.v13 + v7 * b.v14 + v11 * b.v15 + v15 * b.v16,v4 * b.v13 + v8 * b.v14 + v12 * b.v15 + v16 * b.v16,
			};
		}
		Vec4 operator *(const Vec4& b) const {
			return {
				b.x * v1 + b.y * v5 + b.z * v9 + b.w * v13,
				b.x * v2 + b.y * v6 + b.z * v10 + b.w * v14,
				b.x * v3 + b.y * v7 + b.z * v11 + b.w * v15,
				b.x * v4 + b.y * v8 + b.z * v12 + b.w * v16,
			};
		}
		Vec4 operator *(const Vec3& b) const {
			return {
				b.x * v1 + b.y * v5 + b.z * v9 + v13,
				b.x * v2 + b.y * v6 + b.z * v10 + v14,
				b.x * v3 + b.y * v7 + b.z * v11 + v15,
				b.x * v4 + b.y * v8 + b.z * v12 + v16,
			};
		}

		operator const float* () const {
			return (float*)this;
		}

		static Mat4 Perspective(float fovy, float ratio, float nearPlane, float farPlane) {
			float v = farPlane - nearPlane;
			float t = tanf(fovy / 2);
			return { 1 / t,0,0,0,0,ratio / t,0,0,0,0,farPlane / v,1,0,0,-farPlane * nearPlane / v,0 };
		}

		static Mat4 Orthographic(float scale, float ratio, float nearPlane, float farPlane) {
			return { 1 / scale,0,0,0,0,ratio / scale,0,0,0,0,-2 / (farPlane - nearPlane),0,0,0,-(farPlane + nearPlane) / (farPlane - nearPlane),1 };
		}

		static Mat4 Scale(float x, float y, float z) {
			return { x,0,0,0,0,y,0,0,0,0,z,0,0,0,0,1 };
		}
		static Mat4 Translate(float x, float y, float z) {
			return { 1,0,0,0,0,1,0,0,0,0,1,0,x,y,z,1 };
		}
		static Mat4 RotationX(float v) {
			return { 1,0,0,0,0,cosf(v),sinf(v),0,0,-sinf(v),cosf(v),0,0,0,0,1 };
		}
		static Mat4 RotationY(float v) {
			return { cosf(v),0,-sinf(v),0,0,1,0,0,sinf(v),0,cosf(v),0,0,0,0,1 };
		}
		static Mat4 RotationZ(float v) {
			return { cosf(v),sinf(v),0,0,-sinf(v),cosf(v),0,0,0,0,1,0,0,0,0,1 };
		}

		static Mat4 RotationZXY(float x, float y, float z) {
			return RotationY(y) * RotationX(x) * RotationZ(z);
		}

	} const Mat4_Identity{ 1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1 };
}