#pragma once
namespace math {
	struct Vec2;
	struct Vec3;
	struct Vec4;

	struct Vec2 final {
		float x = 0;
		float y = 0;

		Vec2() noexcept {}
		Vec2(float x, float y) noexcept : x(x), y(y){}

		Vec2 operator +(const Vec2& b) const noexcept;
		Vec2& operator +=(const Vec2& b) noexcept;
		Vec2 operator -(const Vec2& b) const noexcept;
		Vec2& operator -=(const Vec2& b) noexcept;
		Vec2 operator -() const noexcept;
		Vec2 operator *(float b) const noexcept;
		Vec2& operator *=(float b) noexcept;
		Vec2 operator /(float b) const noexcept;
		Vec2& operator /=(float b) noexcept;
		bool operator ==(const Vec2& b) const noexcept;
		bool operator !=(const Vec2& b) const noexcept;
		explicit operator Vec3() const noexcept;
		explicit operator Vec4() const noexcept;
		operator const float* () const;
		float MagnitudeSquared() const noexcept;
		float Magnitude() const noexcept;
		Vec2 Normal() const noexcept;
	};
	struct Vec3 final {
		float x = 0;
		float y = 0;
		float z = 0;

		Vec3() noexcept {}
		Vec3(float x, float y, float z) noexcept : x(x), y(y), z(z) {}

		Vec3 operator +(const Vec3& b) const noexcept;
		Vec3& operator +=(const Vec3& b) noexcept;
		Vec3 operator -(const Vec3& b) const noexcept;
		Vec3& operator -=(const Vec3& b) noexcept;
		Vec3 operator -() const noexcept;
		Vec3 operator *(float b) const noexcept;
		Vec3& operator *=(float b) noexcept;
		Vec3 operator /(float b) const noexcept;
		Vec3& operator /=(float b) noexcept;
		bool operator ==(const Vec3& b) const noexcept;
		bool operator !=(const Vec3& b) const noexcept;
		explicit operator Vec4() const noexcept;
		explicit operator Vec2() const noexcept;
		float MagnitudeSquared() const noexcept;
		float Magnitude() const noexcept;
		Vec3 Normal() const noexcept;
	};
	struct Vec4 final {
		float x = 0;
		float y = 0;
		float z = 0;
		float w = 0;

		Vec4() noexcept {}
		Vec4(float x, float y, float z, float w) noexcept : x(x), y(y), z(z), w(w) {}
		Vec4 operator +(const Vec4& b) const noexcept;
		Vec4& operator +=(const Vec4& b) noexcept;
		Vec4 operator -(const Vec4& b) const noexcept;
		Vec4& operator -=(const Vec4& b) noexcept;
		Vec4 operator -() const noexcept;
		Vec4 operator *(float b) const noexcept;
		Vec4& operator *=(float b) noexcept;
		Vec4 operator /(float b) const noexcept;
		Vec4& operator /=(float b) noexcept;
		explicit operator float* () const noexcept;
		explicit operator Vec3() const noexcept;
		explicit operator Vec2() const noexcept;
		float MagnitudeSquared() const noexcept;
		float Magnitude() const noexcept;
		Vec4 Normal() const noexcept;

	};

	float Dot(const Vec2& A, const Vec2& B) noexcept;
	float Cross(const Vec2& A, const Vec2& B) noexcept;
	float Dot(const Vec3& A, const Vec3& B) noexcept;
	Vec3 Cross(const Vec3& A, const Vec3& B) noexcept;
	float Dot(const Vec4& A, const Vec4& B) noexcept;

	//colum-major
	struct Mat4 final {
		float v1 = 0;
		float v2 = 0;
		float v3 = 0;
		float v4 = 0;
		float v5 = 0;
		float v6 = 0;
		float v7 = 0;
		float v8 = 0;
		float v9 = 0;
		float v10 = 0;
		float v11 = 0;
		float v12 = 0;
		float v13 = 0;
		float v14 = 0;
		float v15 = 0;
		float v16 = 0;
		//{ v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11,v12,v13,v14,v15,v16 };
		Mat4() {};
		Mat4(Vec4& v1, Vec4& v2, Vec4& v3, Vec4& v4);
		Mat4(Vec4(&v)[4]);
		Mat4(float (&v)[16]);
		Mat4(float v1, float v2, float v3, float v4, float v5, float v6, float v7, float v8, float v9, float v10, float v11, float v12, float v13, float v14, float v15, float v16);

		Mat4 operator +(const Mat4& b) const;
		Mat4& operator +=(const Mat4& b);
		Mat4 operator -(const Mat4& b) const;
		Mat4& operator -=(const Mat4& b);
		Mat4 operator -() const;
		Mat4 operator *(float v) const;
		Mat4& operator *=(float b);
		Mat4 operator /(float v) const;
		Mat4& operator /=(float b);
		Mat4 operator *(const Mat4& b) const;
		Mat4& operator *=(const Mat4& b);
		Vec4 operator *(const Vec4& b) const;
		Vec4 operator *(const Vec3& b) const;
		operator const float* () const;

		//ratio : y / x
		static Mat4 Perspective(float fovy, float ratio, float nearPlane, float farPlane);
		//ratio : y / x
		static Mat4 Orthographic(float scale, float ratio, float nearPlane, float farPlane);
		static Mat4 Scale(float x, float y, float z);
		static Mat4 Translate(float x, float y, float z);
		static Mat4 RotationX(float v);
		static Mat4 RotationY(float v);
		static Mat4 RotationZ(float v);
		static Mat4 RotationZXY(float x, float y, float z);

	} const Mat4_Identity{ 1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1 };

}

