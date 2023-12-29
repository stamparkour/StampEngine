#pragma once

namespace gl_math {
	struct Vec2 {
		float x = 0;
		float y = 0;

		Vec2() noexcept;

		Vec2(float x, float y) noexcept;

		Vec2 operator +(const Vec2& b) const noexcept;

		Vec2 operator -(const Vec2& b) const;

		Vec2 operator -() const noexcept;

		Vec2 operator *(float b) const noexcept;

		Vec2 operator /(float b) const noexcept;
	};

	struct Vec3 {
		float x = 0;
		float y = 0;
		float z = 0;

		Vec3() noexcept;

		Vec3(float x, float y, float z) noexcept;

		void operator +=(const Vec3& b) noexcept {
			*this =  *this + b;
		}

		void operator -=(const Vec3& b) noexcept {
			*this = *this - b;
		}

		Vec3 operator +(const Vec3& b) const noexcept;

		Vec3 operator -(const Vec3& b) const noexcept;

		Vec3 operator -() const noexcept;

		Vec3 operator *(float b) const noexcept;

		Vec3 operator /(float b) const noexcept;

		bool operator ==(const Vec3& b) const noexcept;

		bool operator !=(const Vec3& b) const noexcept;

		static Vec3 Cross(const Vec3& a, const Vec3& b) noexcept;

		static float Dot(const Vec3& a, const Vec3& b) noexcept;

		float MagnitudeSquared() const noexcept;
		float Magnitude() const noexcept;
		Vec3 Normal() const noexcept;
	};

	struct Vec4 {
		float x = 0;
		float y = 0;
		float z = 0;
		float w = 0;

		Vec4() noexcept;

		Vec4(float x, float y, float z, float w) noexcept;

		Vec4 operator +(const Vec4& b) const noexcept;

		Vec4 operator -(const Vec4& b) const noexcept;

		Vec4 operator -() const noexcept;

		Vec4 operator *(float b) const noexcept;

		Vec4 operator /(float b) const noexcept;

		explicit operator float*() const noexcept;

		explicit operator Vec3() const noexcept;

		explicit operator Vec2() const noexcept;
	};
}