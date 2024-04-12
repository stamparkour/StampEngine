#pragma once
#include <math.h>

namespace game::math {
	struct Quat {
		float w;
		float x;
		float y;
		float z;

		Quat Conjugate() const noexcept;
		float NormSquared() const noexcept;
		float Norm() const noexcept;
		Quat Unit() const noexcept;
		Quat Inverse() const noexcept;
		Mat4 ToRotationMatrix() const noexcept;

		Quat operator +(const Quat& b) const noexcept;
		Quat operator -(const Quat& b) const noexcept;
		Quat operator *(float b) const noexcept;
		Quat operator *(const Quat& b) const noexcept;
		Vec3 operator *(const Vec3& b) const noexcept;
		Quat operator /(float b) const noexcept;
		Quat operator /(const Quat& b) const noexcept;
		Quat& operator *=(const Quat& b) noexcept;
		Quat& operator *=(float b) noexcept;

		static Quat RotationX(float v) noexcept;
		static Quat RotationY(float v) noexcept;
		static Quat RotationZ(float v) noexcept;
		static Quat RotationAxis(float r, const Vec3& axis) noexcept;
		static Quat RotationZXY(float x, float y, float z) noexcept;
		static Quat RotationZYX(float x, float y, float z) noexcept;
	} const Quat_Identity{ 1,0,0,0 };
}