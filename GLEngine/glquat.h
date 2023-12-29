#pragma once
#include <math.h>

namespace gl_math {
	struct Quat {
		float w;
		float x;
		float y;
		float z;

		Quat Conjugate() const noexcept {
			return { w,-x,-y,-z };
		}

		float NormSquared() const noexcept {
			return w * w + x * x + y * y + z * z;
		}

		float Norm() const noexcept {
			return sqrtf(NormSquared());
		}

		Quat Unit() const noexcept {
			return (*this) / Norm();
		}

		Quat Inverse() const noexcept {
			return Conjugate() / NormSquared();
		}

		Mat4 ToRotationMatrix() const noexcept {
			return { 1 - 2 * (y * y + z * z), 2 * (x * y + z * w), 2 * (x * z - y * w), 0,2 * (x * y - z * w), 1 - 2 * (x * x + z * z), 2 * (y * z + x * w), 0,2 * (x * z + y * w), 2 * (y * z - x * w), 1 - 2 * (x * x + y * y), 0,0,0,0,1 };
		}

		Quat operator +(const Quat& b) const noexcept {
			return { w + b.w,x + b.x,y + b.y,z + b.z };
		}
		Quat operator -(const Quat& b) const noexcept {
			return { w - b.w,x - b.x,y - b.y,z - b.z };
		}
		Quat operator *(float b) const noexcept {
			return { w * b,x * b,y * b,z * b };
		}
		Quat operator *(const Quat& b) const noexcept {
			return { w * b.w - x * b.x - y * b.y - z * b.z,w * b.x + x * b.w + y * b.z - z * b.y,w * b.y - x * b.z + y * b.w + z * b.x,w * b.z + x * b.y - y * b.x + z * b.w };
		}
		Vec3 operator *(const Vec3& b) const noexcept {
			Quat v = *this * Quat{ 0,-b.x,-b.y,-b.z } * this->Inverse();
			return {v.x,v.y,v.z};
		}
		Quat operator /(float b) const noexcept {
			return { w / b,x / b,y / b,z / b };
		}
		Quat operator /(const Quat& b) const noexcept {
			return (*this) * b.Inverse();
		}

		Quat operator *=(const Quat& b) noexcept {
			*this = *this * b;
		}

		Quat operator *=(float b) noexcept {
			*this = *this * b;
		}

		static Quat RotationX(float v) noexcept {
			return { cosf(v / 2),sinf(v / 2),0,0 };
		}
		static Quat RotationY(float v) noexcept {
			return { cosf(v / 2),0,sinf(v / 2),0 };
		}
		static Quat RotationZ(float v) noexcept {
			return { cosf(v / 2),0,0,sinf(v / 2) };
		}
		
		static Quat RotationAxis(float r, const Vec3& axis) noexcept {
			Vec3 a = axis.Normal();
			return { cosf(r/2),a.x * sinf(r / 2),a.y * sinf(r / 2),a.z * sinf(r / 2) };
		}

		static Quat RotationZXY(float x, float y, float z) noexcept {
			return RotationZ(z) * RotationX(x) * RotationY(y);
		}
	} const Quat_Identity{ 1,0,0,0 };
}