export module math;

import std;

export namespace math {
	constexpr double PI = 3.141592653589793;
	constexpr double DEGTORAD = PI / 180;
	constexpr double E = 2.718281828459045;
	template<typename T>
	concept Quantity = requires(T a, T b) {
		a = b;
		a + b;
		a - b;
		a * b;
		a / b;
		a += b;
		a -= b;
		a *= b;
		a /= b;
	};

	template<Quantity T>
	struct Vec2;
	template<Quantity T>
	struct Vec3;
	template<Quantity T>
	struct Vec4;
	template<Quantity T>
	struct Quat;
	template<Quantity T>
	struct Mat4;

	using Vec2f = Vec2<float>;
	using Vec3f = Vec3<float>;
	using Vec4f = Vec4<float>;
	using Quatf = Quat<float>;
	using Mat4f = Mat4<float>;
	using Vec2d = Vec2<double>;
	using Vec3d = Vec3<double>;
	using Vec4d = Vec4<double>;
	using Quatd = Quat<double>;
	using Mat4d = Mat4<double>;
	using Vec2i = Vec2<int>;
	using Vec3i = Vec3<int>;
	using Vec4i = Vec4<int>;
	using Quati = Quat<int>;
	using Mat4i = Mat4<int>;
	using Vec2ui = Vec2<unsigned int>;
	using Vec3ui = Vec3<unsigned int>;
	using Vec4ui = Vec4<unsigned int>;
	using Quatui = Quat<unsigned int>;
	using Mat4ui = Mat4<unsigned int>;

	template<Quantity T>
	struct Vec2 {
		T x = 0;
		T y = 0;

		Vec2() noexcept {}
		Vec2(T x, T y) noexcept : x(x), y(y) {}

		Vec2<T> operator +(const Vec2<T>& b) const noexcept;
		Vec2<T>& operator +=(const Vec2<T>& b) noexcept;
		Vec2<T> operator -(const Vec2<T>& b) const noexcept;
		Vec2<T>& operator -=(const Vec2<T>& b) noexcept;
		Vec2<T> operator -() const noexcept;
		Vec2<T> operator *(Vec2<T> b) const noexcept;
		Vec2<T>& operator *=(Vec2<T> b) noexcept;
		Vec2<T> operator *(T b) const noexcept;
		Vec2<T>& operator *=(T b) noexcept;
		Vec2<T> operator /(T b) const noexcept;
		Vec2<T>& operator /=(T b) noexcept;
		bool operator ==(const Vec2& b) const noexcept;
		bool operator !=(const Vec2& b) const noexcept;
		template<Quantity T1>
		explicit operator Vec2<T1>() const noexcept;
		explicit operator Vec3<T>() const noexcept;
		explicit operator Vec4<T>() const noexcept;
		explicit operator const T* () const noexcept;
		float MagnitudeSquared() const noexcept;
		float Magnitude() const noexcept;
		Vec2<T> Normal() const noexcept;
		inline static const Vec2<T>& Unit() {
			static Vec2<T> value{ 1,1 };
			return value; 
		}
		inline friend std::ostream& operator << (std::ostream& o, Vec2<T> v) {
			o << "(" << v.x << "," << v.y << ")";
			return o;
		}
	};
	template<Quantity T>
	struct Vec3 {
		T x = 0;
		T y = 0;
		T z = 0;

		Vec3() noexcept {}
		Vec3(T x, T y, T z) noexcept : x(x), y(y), z(z) {}

		Vec3<T> operator +(const Vec3<T>& b) const noexcept;
		Vec3<T>& operator +=(const Vec3<T>& b) noexcept;
		Vec3<T> operator -(const Vec3<T>& b) const noexcept;
		Vec3<T>& operator -=(const Vec3<T>& b) noexcept;
		Vec3<T> operator -() const noexcept;
		Vec3<T> operator *(T b) const noexcept;
		Vec3<T>& operator *=(T b) noexcept;
		Vec3<T>& operator *=(const Quat<T>& b) noexcept;
		Vec3<T> operator /(T b) const noexcept;
		Vec3<T>& operator /=(T b) noexcept;
		bool operator ==(const Vec3<T>& b) const noexcept;
		bool operator !=(const Vec3<T>& b) const noexcept;
		explicit operator const T* () const noexcept;
		template<Quantity T1>
		explicit operator Vec3<T1>() const noexcept;
		explicit operator Vec4<T>() const noexcept;
		explicit operator Vec2<T>() const noexcept;
		float MagnitudeSquared() const noexcept;
		float Magnitude() const noexcept;
		Vec3<T> Normal() const noexcept;
		inline static const Vec3<T>& Unit() {
			static Vec3<T> value{ 1,1,1 };
			return value;
		}
	};
	template<Quantity T>
	struct Vec4 {
		T x = 0;
		T y = 0;
		T z = 0;
		T w = 0;

		Vec4() noexcept {}
		Vec4(T x, T y, T z, T w) noexcept : x(x), y(y), z(z), w(w) {}
		Vec4<T> operator +(const Vec4<T>& b) const noexcept;
		Vec4<T>& operator +=(const Vec4<T>& b) noexcept;
		Vec4<T> operator -(const Vec4<T>& b) const noexcept;
		Vec4<T>& operator -=(const Vec4<T>& b) noexcept;
		Vec4<T> operator -() const noexcept;
		Vec4<T> operator *(T b) const noexcept;
		Vec4<T>& operator *=(T b) noexcept;
		Vec4<T> operator /(T b) const noexcept;
		Vec4<T>& operator /=(T b) noexcept;
		explicit operator const T* () const noexcept;
		template<Quantity T1>
		explicit operator Vec4<T1>() const noexcept;
		explicit operator Vec2<T>() const noexcept;
		explicit operator Vec3<T>() const noexcept;
		float MagnitudeSquared() const noexcept;
		float Magnitude() const noexcept;
		Vec4<T> Normal() const noexcept; 
		inline static const Vec4<T>& Unit() {
			static Vec4<T> value{ 1,1,1,1 };
			return value;
		}
	};

	template<Quantity T>
	T Dot(const Vec2<T>& A, const Vec2<T>& B) noexcept;
	template<Quantity T>
	T Cross(const Vec2<T>& A, const Vec2<T>& B) noexcept;
	template<Quantity T>
	T Dot(const Vec3<T>& A, const Vec3<T>& B) noexcept;
	template<Quantity T>
	Vec3<T> Cross(const Vec3<T>& A, const Vec3<T>& B) noexcept;
	template<Quantity T>
	T Dot(const Vec4<T>& A, const Vec4<T>& B) noexcept;

	//column-major
	template<Quantity T>
	struct Mat4 {
		T v1 = 0;
		T v2 = 0;
		T v3 = 0;
		T v4 = 0;
		T v5 = 0;
		T v6 = 0;
		T v7 = 0;
		T v8 = 0;
		T v9 = 0;
		T v10 = 0;
		T v11 = 0;
		T v12 = 0;
		T v13 = 0;
		T v14 = 0;
		T v15 = 0;
		T v16 = 0;
		Mat4() {};
		Mat4(Vec4<T>& v1, Vec4<T>& v2, Vec4<T>& v3, Vec4<T>& v4);
		Mat4(Vec4<T>(&v)[4]);
		Mat4(T(&v)[16]);
		Mat4(T v1, T v2, T v3, T v4, T v5, T v6, T v7, T v8, T v9, T v10, T v11, T v12, T v13, T v14, T v15, T v16);

		Mat4<T> operator +(const Mat4<T>& b) const;
		Mat4<T>& operator +=(const Mat4<T>& b);
		Mat4<T> operator -(const Mat4<T>& b) const;
		Mat4<T>& operator -=(const Mat4<T>& b);
		Mat4<T> operator -() const;
		Mat4<T> operator *(T v) const;
		Mat4<T>& operator *=(T b);
		Mat4<T> operator /(T v) const;
		Mat4<T>& operator /=(T b);
		Mat4<T> operator *(const Mat4<T>& b) const;
		Mat4<T>& operator *=(const Mat4<T>& b);
		Vec4<T> operator *(const Vec4<T>& b) const;
		Vec4<T> operator *(const Vec3<T>& b) const;
		Vec4<T> operator *(const Vec2<T>& b) const;
		operator const T* () const;
		static Mat4<T> Perspective(T right, T left, T top, T bottom, T nearPlane, T farPlane);
		//ratio : y / x
		static Mat4<T> Perspective(T rightRad, T leftRad, T topRad, T bottomRad, T ratio, T nearPlane, T farPlane);
		//ratio : y / x
		static Mat4<T> Perspective(T fovx, T ratio, T nearPlane, T farPlane);
		//ratio : y / x
		static Mat4<T> Orthographic(T scaleX, T ratio, T nearPlane, T farPlane);
		static Mat4<T> Scale(T x, T y, T z);
		static Mat4<T> Translate(T x, T y, T z);
		static Mat4<T> RotationX(T v);
		static Mat4<T> RotationY(T v);
		static Mat4<T> RotationZ(T v);
		static Mat4<T> RotationZXY(T x, T y, T z);

		inline static const Mat4<T>& Identity() { 
			static Mat4<T> value{ 1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1 };
			return value;
		}
	};

	template<Quantity T>
	struct Quat {
		T w;
		T x;
		T y;
		T z;

		Quat() noexcept : w(1), x(0), y(0), z(0) {}
		Quat(T w, T x, T y, T z) noexcept : w(w), x(x), y(y), z(z) {}

		Quat<T> Conjugate() const noexcept;
		T NormSquared() const noexcept;
		T Norm() const noexcept;
		Quat<T> Unit() const noexcept;
		Quat<T> Inverse() const noexcept;
		Mat4<T> ToRotationMatrix() const noexcept;

		Quat<T> operator +(const Quat<T>& b) const noexcept;
		Quat<T>& operator +=(const Quat<T>& b) noexcept;
		Quat<T> operator -(const Quat<T>& b) const noexcept;
		Quat<T>& operator -=(const Quat<T>& b) noexcept;
		Quat<T> operator *(T b) const noexcept;
		Quat<T>& operator *=(T b) noexcept;
		Quat<T> operator *(const Quat<T>& b) const noexcept;
		Quat<T>& operator *=(const Quat<T>& b) noexcept;
		Vec3<T> operator *(const Vec3<T>& b) const noexcept;
		Quat<T> operator /(T b) const noexcept;
		Quat<T>& operator /=(T b) noexcept;
		Quat<T> operator /(const Quat<T>& b) const noexcept;
		Quat<T>& operator /=(const Quat<T>& b) noexcept;

		static Quat<T> RotationX(T v) noexcept;
		static Quat<T> RotationY(T v) noexcept;
		static Quat<T> RotationZ(T v) noexcept;
		static Quat<T> RotationAxis(T r, const Vec3<T>& axis) noexcept;
		static Quat<T> RotationZXY(T x, T y, T z) noexcept;
		static Quat<T> RotationZYX(T x, T y, T z) noexcept;
		static Quat<T> LookAt(T x, T y, T z) noexcept;
		explicit operator T* () const noexcept;
		inline static const Quat<T>& Identity() { 
			static Quat<T> value{ 1,0,0,0 };
			return value;
		}
	};

	struct alignas(sizeof(Vec2f)) GLvec2 : Vec2f {
		GLvec2() : Vec2f() {}
		GLvec2(const Vec2f& o) {
			*((Vec2f*)this) = o;
		}
		GLvec2& operator =(const Vec2f& o) {
			*((Vec2f*)this) = o;
			return *this;
		}
	};
	struct alignas(sizeof(Vec4f)) GLvec3 : Vec3f {
		GLvec3() : Vec3f() {}
		GLvec3(const Vec3f& o) {
			*((Vec3f*)this) = o;
		}
		GLvec3& operator =(const Vec3f& o) {
			*((Vec3f*)this) = o;
			return *this;
		}
	};
	struct alignas(sizeof(Vec4f)) GLvec4 : Vec4f {
		GLvec4() : Vec4f() {}
		GLvec4(const Vec4f& o) {
			*((Vec4f*)this) = o;
		}
		GLvec4& operator =(const Vec4f& o) {
			*((Vec4f*)this) = o;
			return *this;
		}
	};
	struct alignas(sizeof(Vec4f)) GLmat4 : Mat4f {
		GLmat4() : Mat4f() {}
		GLmat4(const Mat4f& o) {
			*((Mat4f*)this) =o;
		}
		GLmat4& operator =(const Mat4f& o) {
			*((Mat4f*)this) = o;
			return *this;
		}
	};

	template<Quantity T>
	Vec2<T> Vec2<T>::operator +(const Vec2<T>& b) const noexcept {
		return { x + b.x,y + b.y };
	}
	template<Quantity T>
	Vec2<T>& Vec2<T>::operator +=(const Vec2<T>& b) noexcept {
		return *this = *this + b;
	}
	template<Quantity T>
	Vec2<T> Vec2<T>::operator -(const Vec2<T>& b) const noexcept {
		return { x - b.x,y - b.y };
	}
	template<Quantity T>
	Vec2<T>& Vec2<T>::operator -=(const Vec2<T>& b) noexcept {
		return *this = *this - b;
	}
	template<Quantity T>
	Vec2<T> Vec2<T>::operator -() const noexcept {
		return { -x, -y };
	}
	template<Quantity T>
	Vec2<T> math::Vec2<T>::operator*(Vec2<T> b) const noexcept {
		return { x * b.x, y * b.y };
	}
	template<Quantity T>
	Vec2<T>& math::Vec2<T>::operator*=(Vec2<T> b) noexcept {
		return *this = *this * b;
	}
	template<Quantity T>
	Vec2<T> Vec2<T>::operator *(T b) const noexcept {
		return { x * b, y * b };
	}
	template<Quantity T>
	Vec2<T>& Vec2<T>::operator *=(T b) noexcept {
		return *this = *this * b;
	}
	template<Quantity T>
	Vec2<T> Vec2<T>::operator /(T b) const noexcept {
		return { x / b, y / b };
	}
	template<Quantity T>
	Vec2<T>& Vec2<T>::operator /=(T b) noexcept {
		return *this = *this / b;
	}
	template<Quantity T>
	bool Vec2<T>::operator==(const Vec2<T>& b) const noexcept {
		return x == b.x && y == b.y;
	}
	template<Quantity T>
	bool Vec2<T>::operator!=(const Vec2<T>& b) const noexcept {
		return x != b.x || y != b.y;
	}
	template<Quantity T>
	template<Quantity T1>
	math::Vec2<T>::operator Vec2<T1>() const noexcept {
		return { (T1)x, (T1)y };
	}
	template<Quantity T>
	Vec2<T>::operator Vec4<T>() const noexcept {
		return { x,y,0,0 };
	}
	template<Quantity T>
	Vec2<T>::operator Vec3<T>() const noexcept {
		return { x,y,0 };
	}
	template<Quantity T>
	Vec2<T>::operator const T* () const noexcept {
		return (T*)this;
	}
	template<Quantity T>
	float Vec2<T>::MagnitudeSquared() const noexcept {
		return x * x + y * y;
	}
	template<Quantity T>
	float Vec2<T>::Magnitude() const noexcept {
		if (x == 0 && y == 0) return 0;
		return sqrt(x * x + y * y);
	}
	template<Quantity T>
	Vec2<T> Vec2<T>::Normal() const noexcept {
		float mag = Magnitude();
		if (mag == 0) return { 0,0 };
		return (*this) / mag;
	}
	template<Quantity T>
	Vec3<T>& Vec3<T>::operator *=(T b) noexcept {
		x *= b;
		y *= b;
		z *= b;
		return *this;
	}
	template<Quantity T>
	Vec3<T>& Vec3<T>::operator*=(const Quat<T>& b) noexcept {
		return *this = b * *this;
	}
	template<Quantity T>
	Vec3<T>& Vec3<T>::operator /=(T b) noexcept {
		x /= b;
		y /= b;
		z /= b;
		return *this;
	}
	template<Quantity T>
	Vec3<T> Vec3<T>::operator +(const Vec3<T>& b) const noexcept {
		return { x + b.x,y + b.y, z + b.z };
	}
	template<Quantity T>
	Vec3<T>& Vec3<T>::operator +=(const Vec3<T>& b) noexcept {
		x += b.x;
		y += b.y;
		z += b.z;
		return *this;
	}
	template<Quantity T>
	Vec3<T> Vec3<T>::operator -(const Vec3<T>& b) const noexcept {
		return { x - b.x,y - b.y, z - b.z };
	}
	template<Quantity T>
	Vec3<T> Vec3<T>::operator -() const noexcept {
		return { -x, -y, -z };
	}
	template<Quantity T>
	Vec3<T> Vec3<T>::operator *(T b) const noexcept {
		return { x * b, y * b, z * b };
	}
	template<Quantity T>
	Vec3<T> Vec3<T>::operator /(T b) const noexcept {
		return { x / b, y / b, z / b };
	}
	template<Quantity T>
	bool Vec3<T>::operator ==(const Vec3<T>& b) const noexcept {
		return this->x == b.x && this->y == b.y && this->z == b.z;
	}
	template<Quantity T>
	bool Vec3<T>::operator !=(const Vec3<T>& b) const noexcept {
		return this->x != b.x || this->y != b.y || this->z != b.z;
	}
	template<Quantity T>
	Vec3<T>::operator const T* () const noexcept {
		return (const T*)this;
	}
	template<Quantity T>
	template<Quantity T1>
	Vec3<T>::operator Vec3<T1>() const noexcept {
		return { (T1)x,(T1)y ,(T1)z};
	}
	template<Quantity T>
	Vec3<T>::operator Vec2<T>() const noexcept {
		return { x,y,0,0 };
	}
	template<Quantity T>
	Vec3<T>::operator Vec4<T>() const noexcept {
		return { x,y,z,0 };
	}
	template<Quantity T>
	float Vec3<T>::MagnitudeSquared() const noexcept {
		return x * x + y * y + z * z;
	}
	template<Quantity T>
	float Vec3<T>::Magnitude() const noexcept {
		if (x == 0 && y == 0 && z == 0) return 0;
		return (T)sqrt(x * x + y * y + z * z);
	}
	template<Quantity T>
	Vec3<T> Vec3<T>::Normal() const noexcept {
		float mag = Magnitude();
		if (mag == 0) return { 0,0,0 };
		return (*this) / mag;
	}
	template<Quantity T>
	Vec4<T> Vec4<T>::operator +(const Vec4<T>& b) const noexcept {
		return { x + b.x,y + b.y, z + b.z, w + b.w };
	}
	template<Quantity T>
	Vec4<T>& Vec4<T>::operator +=(const Vec4<T>& b) noexcept {
		return *this = *this + b;
	}
	template<Quantity T>
	Vec4<T> Vec4<T>::operator -(const Vec4<T>& b) const noexcept {
		return { x - b.x,y - b.y, z - b.z, w - b.w };
	}
	template<Quantity T>
	Vec4<T>& Vec4<T>::operator -=(const Vec4<T>& b) noexcept {
		return *this = *this - b;
	}
	template<Quantity T>
	Vec4<T> Vec4<T>::operator -() const noexcept {
		return { -x, -y, -z, -w };
	}
	template<Quantity T>
	Vec4<T> Vec4<T>::operator *(T b) const noexcept {
		return { x * b, y * b, z * b, w / b };
	}
	template<Quantity T>
	Vec4<T>& Vec4<T>::operator *=(T b) noexcept {
		return *this = *this * b;
	}
	template<Quantity T>
	Vec4<T> Vec4<T>::operator /(T b) const noexcept {
		return { x / b, y / b, z / b, w / b };
	}
	template<Quantity T>
	Vec4<T>& Vec4<T>::operator /=(T b) noexcept {
		return *this = *this / b;
	}
	template<Quantity T>
	math::Vec4<T>::operator const T* () const noexcept {
		return (const T*)this;
	}
	template<Quantity T>
	Vec4<T>::operator Vec3<T>() const noexcept {
		return { x,y,z };
	}
	template<Quantity T>
	Vec4<T>::operator Vec2<T>() const noexcept {
		return { x,y };
	}
	template<Quantity T>
	template<Quantity T1>
	Vec4<T>::operator Vec4<T1>() const noexcept {
		return { (T1)x,(T1)y ,(T1)z ,(T1)w };
	}
	template<Quantity T>
	float Vec4<T>::MagnitudeSquared() const noexcept {
		return x * x + y * y + z * z + w * w;
	}
	template<Quantity T>
	float Vec4<T>::Magnitude() const noexcept {
		using namespace std;
		if (x == 0 && y == 0 && z == 0 && w == 0) return 0;
		return sqrt(x * x + y * y + z * z + w * w);
	}
	template<Quantity T>
	Vec4<T> Vec4<T>::Normal() const noexcept {
		float mag = Magnitude();
		if (mag == 0) return { 0,0,0,0 };
		return (*this) / mag;
	}
	template<Quantity T>
	T Dot(const Vec2<T>& a, const Vec2<T>& b) noexcept {
		return a.x * b.x + a.y * b.y;
	}
	template<Quantity T>
	T Cross(const Vec2<T>& a, const Vec2<T>& b) noexcept {
		return a.x * b.y + a.y * b.x;
	}
	template<Quantity T>
	Vec3<T> Cross(const Vec3<T>& a, const Vec3<T>& b) noexcept {
		return { a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x };
	}
	template<Quantity T>
	T Dot(const Vec3<T>& a, const Vec3<T>& b) noexcept {
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}
	template<Quantity T>
	T Dot(const Vec4<T>& a, const Vec4<T>& b) noexcept {
		return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
	}
	template<Quantity T>
	Mat4<T>::Mat4(T(&v)[16]) {
		memcpy_s(this, sizeof(Mat4<T>), v, sizeof(T) * 16);
	}
	template<Quantity T>
	Mat4<T>::Mat4(Vec4<T>& v1, Vec4<T>& v2, Vec4<T>& v3, Vec4<T>& v4) {
		this->v1 = v1.x;
		this->v2 = v1.y;
		this->v3 = v1.z;
		this->v4 = v1.w;
		this->v5 = v2.x;
		this->v6 = v2.y;
		this->v7 = v2.z;
		this->v8 = v2.w;
		this->v9 = v3.x;
		this->v10 = v3.y;
		this->v11 = v3.z;
		this->v12 = v3.w;
		this->v13 = v4.x;
		this->v14 = v4.y;
		this->v15 = v4.z;
		this->v16 = v4.w;
	}
	template<Quantity T>
	Mat4<T>::Mat4(Vec4<T>(&v)[4]) {
		this->v1 = v[0].x;
		this->v2 = v[0].y;
		this->v3 = v[0].z;
		this->v4 = v[0].w;
		this->v5 = v[1].x;
		this->v6 = v[1].y;
		this->v7 = v[1].z;
		this->v8 = v[1].w;
		this->v9 = v[2].x;
		this->v10 = v[2].y;
		this->v11 = v[2].z;
		this->v12 = v[2].w;
		this->v13 = v[3].x;
		this->v14 = v[3].y;
		this->v15 = v[3].z;
		this->v16 = v[3].w;
	}
	template<Quantity T>
	Mat4<T>::Mat4(T v1, T v2, T v3, T v4, T v5, T v6, T v7, T v8, T v9, T v10, T v11, T v12, T v13, T v14, T v15, T v16) {
		this->v1 = v1;
		this->v2 = v2;
		this->v3 = v3;
		this->v4 = v4;
		this->v5 = v5;
		this->v6 = v6;
		this->v7 = v7;
		this->v8 = v8;
		this->v9 = v9;
		this->v10 = v10;
		this->v11 = v11;
		this->v12 = v12;
		this->v13 = v13;
		this->v14 = v14;
		this->v15 = v15;
		this->v16 = v16;
	}
	template<Quantity T>
	Mat4<T> Mat4<T>::operator +(const Mat4<T>& b) const {
		return { v1 + b.v1,v2 + b.v2,v3 + b.v3,v4 + b.v4,v5 + b.v5,v6 + b.v6,v7 + b.v7,v8 + b.v8,v9 + b.v9,v10 + b.v10,v11 + b.v11,v12 + b.v12,v13 + b.v13,v14 + b.v14,v15 + b.v15,v16 + b.v16 };
	}
	template<Quantity T>
	Mat4<T>& Mat4<T>::operator +=(const Mat4<T>& b) {
		return *this = *this + b;
	}
	template<Quantity T>
	Mat4<T> Mat4<T>::operator -(const Mat4<T>& b) const {
		return { v1 - b.v1,v2 - b.v2,v3 - b.v3,v4 - b.v4,v5 - b.v5,v6 - b.v6,v7 - b.v7,v8 - b.v8,v9 - b.v9,v10 - b.v10,v11 - b.v11,v12 - b.v12,v13 - b.v13,v14 - b.v14,v15 - b.v15,v16 - b.v16 };
	}
	template<Quantity T>
	Mat4<T>& Mat4<T>::operator -=(const Mat4<T>& b) {
		return *this = *this - b;
	}
	template<Quantity T>
	Mat4<T> Mat4<T>::operator -() const {
		return { -v1,-v2,-v3,-v4,-v5,-v6,-v7,-v8,-v9,-v10,-v11,-v12,-v13,-v14,-v15,-v16 };
	}
	template<Quantity T>
	Mat4<T> Mat4<T>::operator *(T v) const {
		return { v1 * v,v2 * v,v3 * v,v4 * v,v5 * v,v6 * v,v7 * v,v8 * v,v9 * v,v10 * v,v11 * v,v12 * v,v13 * v,v14 * v,v15 * v,v16 * v };
	}
	template<Quantity T>
	Mat4<T>& Mat4<T>::operator *=(T b) {
		return *this = *this * b;
	}
	template<Quantity T>
	Mat4<T> Mat4<T>::operator /(T v) const {
		return { v1 / v,v2 / v,v3 / v,v4 / v,v5 / v,v6 / v,v7 / v,v8 / v,v9 / v,v10 / v,v11 / v,v12 / v,v13 / v,v14 / v,v15 / v,v16 / v };
	}
	template<Quantity T>
	Mat4<T>& Mat4<T>::operator /=(T b) {
		return *this = *this / b;
	}
	template<Quantity T>
	Mat4<T> Mat4<T>::operator *(const Mat4<T>& b) const {
		return {
			v1 * b.v1 + v5 * b.v2 + v9 * b.v3 + v13 * b.v4,v2 * b.v1 + v6 * b.v2 + v10 * b.v3 + v14 * b.v4,v3 * b.v1 + v7 * b.v2 + v11 * b.v3 + v15 * b.v4,v4 * b.v1 + v8 * b.v2 + v12 * b.v3 + v16 * b.v4,
			v1 * b.v5 + v5 * b.v6 + v9 * b.v7 + v13 * b.v8,v2 * b.v5 + v6 * b.v6 + v10 * b.v7 + v14 * b.v8,v3 * b.v5 + v7 * b.v6 + v11 * b.v7 + v15 * b.v8,v4 * b.v5 + v8 * b.v6 + v12 * b.v7 + v16 * b.v8,
			v1 * b.v9 + v5 * b.v10 + v9 * b.v11 + v13 * b.v12,v2 * b.v9 + v6 * b.v10 + v10 * b.v11 + v14 * b.v12,v3 * b.v9 + v7 * b.v10 + v11 * b.v11 + v15 * b.v12,v4 * b.v9 + v8 * b.v10 + v12 * b.v11 + v16 * b.v12,
			v1 * b.v13 + v5 * b.v14 + v9 * b.v15 + v13 * b.v16,v2 * b.v13 + v6 * b.v14 + v10 * b.v15 + v14 * b.v16,v3 * b.v13 + v7 * b.v14 + v11 * b.v15 + v15 * b.v16,v4 * b.v13 + v8 * b.v14 + v12 * b.v15 + v16 * b.v16,
		};
	}
	template<Quantity T>
	Mat4<T>& Mat4<T>::operator *=(const Mat4<T>& b) {
		return *this = *this * b;
	}
	template<Quantity T>
	Vec4<T> Mat4<T>::operator *(const Vec4<T>& b) const {
		return {
			b.x * v1 + b.y * v5 + b.z * v9 + b.w * v13,
			b.x * v2 + b.y * v6 + b.z * v10 + b.w * v14,
			b.x * v3 + b.y * v7 + b.z * v11 + b.w * v15,
			b.x * v4 + b.y * v8 + b.z * v12 + b.w * v16,
		};
	}
	template<Quantity T>
	Vec4<T> Mat4<T>::operator *(const Vec3<T>& b) const {
		return {
			b.x * v1 + b.y * v5 + b.z * v9 + v13,
			b.x * v2 + b.y * v6 + b.z * v10 + v14,
			b.x * v3 + b.y * v7 + b.z * v11 + v15,
			b.x * v4 + b.y * v8 + b.z * v12 + v16,
		};
	}
	template<Quantity T>
	Vec4<T> math::Mat4<T>::operator*(const Vec2<T>& b) const {
		return {
			b.x * v1 + b.y * v5 + v13,
			b.x * v2 + b.y * v6 + v14,
			b.x * v3 + b.y * v7 + v15,
			b.x * v4 + b.y * v8 + v16,
		};
	}
	template<Quantity T>
	Mat4<T>::operator const T* () const {
		return (T*)this;
	}
	template<Quantity T>
	Mat4<T> math::Mat4<T>::Perspective(T right, T left, T top, T bottom, T near, T far) {
		return { 2 * near / (right - left),0,(right + left) / (right - left),0,0,2 * near / (top - bottom),(top + bottom) / (top - bottom),0,0,0,-(far + near) / (far - near),1,0,0,2 * far * near / (far - near),0 };
	}
	template<Quantity T>
	Mat4<T> math::Mat4<T>::Perspective(T right, T left, T top, T bottom, T ratio, T near, T far) {
		right = tan(right);
		left = tan(left);
		top = tan(top) * ratio;
		bottom = tan(bottom) * ratio;
		return { 2 / (right - left),0,(right + left) / (right - left),0,0,2 / (top - bottom),(top + bottom) / (top - bottom),0,0,0,-(far + near) / (far - near),1,0,0,2 * far * near / (far - near),0 };
	}
	template<Quantity T>
	Mat4<T> Mat4<T>::Perspective(T fovx, T ratio, T near, T far) {
		T tangent = tan(fovx / 2);
		return { ratio / tangent,0,0,0,0,1 / tangent,0,0,0,0,-(near + far) / (far - near),1,0,0,2 * near * far / (far - near),0 };
	}
	template<Quantity T>
	Mat4<T> Mat4<T>::Orthographic(T scaleX, T ratio, T nearPlane, T farPlane) {
		return { ratio / scaleX,0,0,0,0,1 / scaleX,0,0,0,0,-2 / (farPlane - nearPlane),0,0,0,(farPlane + nearPlane) / (farPlane - nearPlane),1 };
	}
	template<Quantity T>
	Mat4<T> Mat4<T>::Scale(T x, T y, T z) {
		return { x,0,0,0,0,y,0,0,0,0,z,0,0,0,0,1 };
	}
	template<Quantity T>
	Mat4<T> Mat4<T>::Translate(T x, T y, T z) {
		return { 1,0,0,0,0,1,0,0,0,0,1,0,x,y,z,1 };
	}
	template<Quantity T>
	Mat4<T> Mat4<T>::RotationX(T v) {
		return { 1,0,0,0,0,cosf(v),sinf(v),0,0,-sinf(v),cosf(v),0,0,0,0,1 };
	}
	template<Quantity T>
	Mat4<T> Mat4<T>::RotationY(T v) {
		using namespace std;
		return { cos(v),0,-sin(v),0,0,1,0,0,sin(v),0,cos(v),0,0,0,0,1 };
	}
	template<Quantity T>
	Mat4<T> Mat4<T>::RotationZ(T v) {
		using namespace std;
		return { cos(v),sin(v),0,0,-sin(v),cos(v),0,0,0,0,1,0,0,0,0,1 };
	}
	template<Quantity T>
	Mat4<T> Mat4<T>::RotationZXY(T x, T y, T z) {
		return RotationY(y) * RotationX(x) * RotationZ(z);
	}
	template<Quantity T>
	Quat<T> Quat<T>::Conjugate() const noexcept {
		return { w,-x,-y,-z };
	}
	template<Quantity T>
	T Quat<T>::NormSquared() const noexcept {
		return w * w + x * x + y * y + z * z;
	}
	template<Quantity T>
	T Quat<T>::Norm() const noexcept {
		return sqrtf(NormSquared());
	}
	template<Quantity T>
	Quat<T> Quat<T>::Unit() const noexcept {
		return (*this) / Norm();
	}
	template<Quantity T>
	Quat<T> Quat<T>::Inverse() const noexcept {
		return Conjugate() / NormSquared();
	}
	template<Quantity T>
	Mat4<T> Quat<T>::ToRotationMatrix() const noexcept {
		return { 1 - 2 * (y * y + z * z), 2 * (x * y + z * w), 2 * (x * z - y * w), 0,2 * (x * y - z * w), 1 - 2 * (x * x + z * z), 2 * (y * z + x * w), 0,2 * (x * z + y * w), 2 * (y * z - x * w), 1 - 2 * (x * x + y * y), 0,0,0,0,1 };
	}
	template<Quantity T>
	Quat<T> Quat<T>::operator +(const Quat<T>& b) const noexcept {
		return { w + b.w,x + b.x,y + b.y,z + b.z };
	}
	template<Quantity T>
	Quat<T>& Quat<T>::operator +=(const Quat<T>& b) noexcept {
		return *this = *this + b;
	}
	template<Quantity T>
	Quat<T> Quat<T>::operator -(const Quat<T>& b) const noexcept {
		return { w - b.w,x - b.x,y - b.y,z - b.z };
	}
	template<Quantity T>
	Quat<T>& Quat<T>::operator -=(const Quat<T>& b) noexcept {
		return *this = *this - b;
	}
	template<Quantity T>
	Quat<T> Quat<T>::operator *(T b) const noexcept {
		return { w * b,x * b,y * b,z * b };
	}
	template<Quantity T>
	Quat<T>& Quat<T>::operator *=(T b) noexcept {
		*this = *this * b;
		return *this;
	}
	template<Quantity T>
	Quat<T> Quat<T>::operator *(const Quat<T>& b) const noexcept {
		return { w * b.w - x * b.x - y * b.y - z * b.z,w * b.x + x * b.w + y * b.z - z * b.y,w * b.y - x * b.z + y * b.w + z * b.x,w * b.z + x * b.y - y * b.x + z * b.w };
	}
	template<Quantity T>
	Quat<T>& Quat<T>::operator *=(const Quat<T>& b) noexcept {

		return *this = *this * b;
	}
	template<Quantity T>
	Vec3<T> Quat<T>::operator *(const Vec3<T>& b) const noexcept {
		Quat<T> v = *this * Quat<T>{ 0,-b.x,-b.y,-b.z } * this->Inverse();
		return { v.x,v.y,v.z };
	}
	template<Quantity T>
	Quat<T> Quat<T>::operator /(T b) const noexcept {
		return { w / b,x / b,y / b,z / b };
	}
	template<Quantity T>
	Quat<T>& Quat<T>::operator /=(T b) noexcept {
		return *this = *this / b;
	}
	template<Quantity T>
	Quat<T> Quat<T>::operator /(const Quat<T>& b) const noexcept {
		return (*this) * b.Inverse();
	}
	template<Quantity T>
	Quat<T>& Quat<T>::operator /=(const Quat<T>& b) noexcept {
		return *this = *this / b;
	}
	template<Quantity T>
	Quat<T> Quat<T>::RotationX(T v) noexcept {
		return { (T)cos(v / 2),(T)sin(v / 2),0,0 };
	}
	template<Quantity T>
	Quat<T> Quat<T>::RotationY(T v) noexcept {
		return { (T)cos(v / 2),0,(T)sin(v / 2),0 };
	}
	template<Quantity T>
	Quat<T> Quat<T>::RotationZ(T v) noexcept {
		return { (T)cos(v / 2),0,0,(T)sin(v / 2) };
	}
	template<Quantity T>
	Quat<T> Quat<T>::RotationAxis(T r, const Vec3<T>& axis) noexcept {
		Vec3<T> a = axis.Normal();
		return { (T)cos(r / 2),a.x * (T)sin(r / 2),a.y * (T)sin(r / 2),a.z * (T)sin(r / 2) };
	}
	template<Quantity T>
	Quat<T> Quat<T>::RotationZXY(T x, T y, T z) noexcept {
		return  Quat<T>::RotationY(y) * Quat<T>::RotationX(x) * Quat<T>::RotationZ(z);
	}
	template<Quantity T>
	Quat<T> Quat<T>::RotationZYX(T x, T y, T z) noexcept {
		return Quat<T>::RotationX(x) * Quat<T>::RotationY(y) * Quat<T>::RotationZ(z);
	}
	template<Quantity T>
	Quat<T> math::Quat<T>::LookAt(T x, T y, T z) noexcept
	{
		T thetaY = atan2(x, z);
		T thetaX = atan2(y, sqrt(x*x+z*z));
		return RotationX(thetaY) * RotationY(thetaX);
	}
	template<Quantity T>
	inline Quat<T>::operator T* () const noexcept {
		return (T*)this;
	}
};