#pragma once

namespace gl_math {
	struct Vec2;
	struct Vec3;
	struct Vec4;

	struct Vec2 {
		float x;
		float y;

		Vec2() noexcept;
		Vec2(float x, float y) noexcept;

		Vec2 operator +(const Vec2& b) const noexcept;
		Vec2 operator -(const Vec2& b) const noexcept;
		Vec2 operator -() const noexcept;
		Vec2 operator *(float b) const noexcept;
		Vec2 operator /(float b) const noexcept;
		explicit operator Vec3() const noexcept;
		explicit operator Vec4() const noexcept;

		static float Dot(const Vec2& A, const Vec2& B) noexcept;
	};

	struct Vec2I {
		int x;
		int y;

		Vec2I() noexcept;
		Vec2I(int x, int y) noexcept;

		Vec2I operator +(const Vec2I& b) const noexcept;
		Vec2I operator -(const Vec2I& b) const noexcept;
		Vec2I operator *(int b) const noexcept;
		Vec2I operator /(int b) const noexcept;
		Vec2I& operator +=(const Vec2I& b) noexcept;
		Vec2I& operator -=(const Vec2I& b) noexcept;
		Vec2I& operator *=(int b) noexcept;
		Vec2I& operator /=(int b) noexcept;
		Vec2I operator -() const noexcept;
	};

	struct Vec3 {
		float x = 0;
		float y = 0;
		float z = 0;

		Vec3() noexcept;
		Vec3(float x, float y, float z) noexcept;

		Vec3& operator +=(const Vec3& b) noexcept;
		Vec3& operator -=(const Vec3& b) noexcept;
		Vec3& operator *=(float b) noexcept;
		Vec3& operator /=(float b) noexcept;
		Vec3 operator +(const Vec3& b) const noexcept;
		Vec3 operator -(const Vec3& b) const noexcept;
		Vec3 operator -() const noexcept;
		Vec3 operator *(float b) const noexcept;
		Vec3 operator /(float b) const noexcept;
		bool operator ==(const Vec3& b) const noexcept;
		bool operator !=(const Vec3& b) const noexcept;
		explicit operator Vec4() const noexcept;
		explicit operator Vec2() const noexcept;

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

		static float Dot(const Vec4& A, const Vec4& B) noexcept;
	};
}