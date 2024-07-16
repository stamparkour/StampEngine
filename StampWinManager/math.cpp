#include "math.hpp"
#include <math.h>
#include <cstring>
using namespace math;
Vec2 Vec2::operator +(const Vec2& b) const noexcept {
	return { x + b.x,y + b.y };
}
Vec2& Vec2::operator +=(const Vec2& b) noexcept {
	return *this = *this + b;
}
Vec2 Vec2::operator -(const Vec2& b) const noexcept {
	return { x - b.x,y - b.y };
}
Vec2& Vec2::operator -=(const Vec2& b) noexcept {
	return *this = *this - b;
}
Vec2 Vec2::operator -() const noexcept {
	return { -x, -y };
}
Vec2 Vec2::operator *(float b) const noexcept {
	return { x * b, y * b };
}
Vec2& Vec2::operator *=(float b) noexcept {
	return *this = *this * b;
}
Vec2 Vec2::operator /(float b) const noexcept {
	return { x / b, y / b };
}
Vec2& Vec2::operator /=(float b) noexcept {
	return *this = *this / b;
}
bool math::Vec2::operator==(const Vec2& b) const noexcept {
	return x == b.x && y == b.y;
}
bool math::Vec2::operator!=(const Vec2& b) const noexcept {
	return x != b.x || y != b.y;
}
Vec2::operator Vec4() const noexcept {
	return { x,y,0,0 };
}
Vec2::operator Vec3() const noexcept {
	return { x,y,0 };
}
math::Vec2::operator const float* () const {
	return (float*)this;
}
float Vec2::MagnitudeSquared() const noexcept {
	return x * x + y * y;
}
float Vec2::Magnitude() const noexcept {
	if (x == 0 && y == 0) return 0;
	return sqrtf(x * x + y * y);
}
Vec2 Vec2::Normal() const noexcept {
	float mag = Magnitude();
	if (mag == 0) return { 0,0 };
	return (*this) / mag;
}
Vec3& Vec3::operator *=(float b) noexcept {
	x *= b;
	y *= b;
	z *= b;
	return *this;
}
Vec3& Vec3::operator /=(float b) noexcept {
	x /= b;
	y /= b;
	z /= b;
	return *this;
}
Vec3 Vec3::operator +(const Vec3& b) const noexcept {
	return { x + b.x,y + b.y, z + b.z };
}
Vec3& Vec3::operator +=(const Vec3& b) noexcept {
	x += b.x;
	y += b.y;
	z += b.z;
	return *this;
}
Vec3 Vec3::operator -(const Vec3& b) const noexcept {
	return { x - b.x,y - b.y, z - b.z };
}
Vec3 Vec3::operator -() const noexcept {
	return { -x, -y, -z };
}
Vec3 Vec3::operator *(float b) const noexcept {
	return { x * b, y * b, z * b };
}
Vec3 Vec3::operator /(float b) const noexcept {
	return { x / b, y / b, z / b };
}
bool Vec3::operator ==(const Vec3& b) const noexcept {
	return this->x == b.x && this->y == b.y && this->z == b.z;
}
bool Vec3::operator !=(const Vec3& b) const noexcept {
	return this->x != b.x || this->y != b.y || this->z != b.z;
}
float Vec3::MagnitudeSquared() const noexcept {
	return x * x + y * y + z * z;
}
float Vec3::Magnitude() const noexcept {
	if (x == 0 && y == 0 && z == 0) return 0;
	return sqrtf(x * x + y * y + z * z);
}
Vec3 Vec3::Normal() const noexcept {
	float mag = Magnitude();
	if (mag == 0) return { 0,0,0 };
	return (*this) / mag;
}
Vec4 Vec4::operator +(const Vec4& b) const noexcept {
	return { x + b.x,y + b.y, z + b.z, w + b.w };
}
Vec4& Vec4::operator +=(const Vec4& b) noexcept {
	return *this = *this + b;
}
Vec4 Vec4::operator -(const Vec4& b) const noexcept {
	return { x - b.x,y - b.y, z - b.z, w - b.w };
}
Vec4& Vec4::operator -=(const Vec4& b) noexcept {
	return *this = *this - b;
}
Vec4 Vec4::operator -() const noexcept {
	return { -x, -y, -z, -w };
}
Vec4 Vec4::operator *(float b) const noexcept {
	return { x * b, y * b, z * b, w / b };
}
Vec4& Vec4::operator *=(float b) noexcept {
	return *this = *this * b;
}
Vec4 Vec4::operator /(float b) const noexcept {
	return { x / b, y / b, z / b, w / b };
}
Vec4& Vec4::operator /=(float b) noexcept {
	return *this = *this / b;
}
Vec4::operator Vec3() const noexcept {
	return { x,y,z };
}
Vec4::operator Vec2() const noexcept {
	return { x,y };
}
float Vec4::MagnitudeSquared() const noexcept {
	return x * x + y * y + z * z + w * w;
}
float Vec4::Magnitude() const noexcept {
	if (x == 0 && y == 0 && z == 0 && w == 0) return 0;
	return sqrtf(x * x + y * y + z * z + w * w);
}
Vec4 Vec4::Normal() const noexcept {
	float mag = Magnitude();
	if (mag == 0) return { 0,0,0,0 };
	return (*this) / mag;
}
float math::Dot(const Vec2& a, const Vec2& b) noexcept {
	return a.x * b.x + a.y * b.y;
}
float math::Cross(const Vec2& a, const Vec2& b) noexcept {
	return a.x * b.y + a.y * b.x;
}
Vec3 math::Cross(const Vec3& a, const Vec3& b) noexcept {
	return { a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x };
}
float math::Dot(const Vec3& a, const Vec3& b) noexcept {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}
float math::Dot(const Vec4& a, const Vec4& b) noexcept {
	return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}
Mat4::Mat4(float(&v)[16]) {
	memcpy_s(this, sizeof(Mat4), v, sizeof(float)*16);
}
math::Mat4::Mat4(Vec4& v1, Vec4& v2, Vec4& v3, Vec4& v4) {
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
Mat4::Mat4(float v1, float v2, float v3, float v4, float v5, float v6, float v7, float v8, float v9, float v10, float v11, float v12, float v13, float v14, float v15, float v16) {
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
Mat4 Mat4::operator +(const Mat4& b) const {
	return { v1 + b.v1,v2 + b.v2,v3 + b.v3,v4 + b.v4,v5 + b.v5,v6 + b.v6,v7 + b.v7,v8 + b.v8,v9 + b.v9,v10 + b.v10,v11 + b.v11,v12 + b.v12,v13 + b.v13,v14 + b.v14,v15 + b.v15,v16 + b.v16 };
}
Mat4& Mat4::operator +=(const Mat4& b) {
	return *this = *this + b;
}
Mat4 Mat4::operator -(const Mat4& b) const {
	return { v1 - b.v1,v2 - b.v2,v3 - b.v3,v4 - b.v4,v5 - b.v5,v6 - b.v6,v7 - b.v7,v8 - b.v8,v9 - b.v9,v10 - b.v10,v11 - b.v11,v12 - b.v12,v13 - b.v13,v14 - b.v14,v15 - b.v15,v16 - b.v16 };
}
Mat4& Mat4::operator -=(const Mat4& b) {
	return *this = *this - b;
}
Mat4 Mat4::operator -() const {
	return { -v1,-v2,-v3,-v4,-v5,-v6,-v7,-v8,-v9,-v10,-v11,-v12,-v13,-v14,-v15,-v16 };
}
Mat4 Mat4::operator *(float v) const {
	return { v1 * v,v2 * v,v3 * v,v4 * v,v5 * v,v6 * v,v7 * v,v8 * v,v9 * v,v10 * v,v11 * v,v12 * v,v13 * v,v14 * v,v15 * v,v16 * v };
}
Mat4& Mat4::operator *=(float b) {
	return *this = *this * b;
}
Mat4 Mat4::operator /(float v) const {
	return { v1 / v,v2 / v,v3 / v,v4 / v,v5 / v,v6 / v,v7 / v,v8 / v,v9 / v,v10 / v,v11 / v,v12 / v,v13 / v,v14 / v,v15 / v,v16 / v };
}
Mat4& Mat4::operator /=(float b) {
	return *this = *this / b;
}
Mat4 Mat4::operator *(const Mat4& b) const {
	return {
		v1 * b.v1 + v5 * b.v2 + v9 * b.v3 + v13 * b.v4,v2 * b.v1 + v6 * b.v2 + v10 * b.v3 + v14 * b.v4,v3 * b.v1 + v7 * b.v2 + v11 * b.v3 + v15 * b.v4,v4 * b.v1 + v8 * b.v2 + v12 * b.v3 + v16 * b.v4,
		v1 * b.v5 + v5 * b.v6 + v9 * b.v7 + v13 * b.v8,v2 * b.v5 + v6 * b.v6 + v10 * b.v7 + v14 * b.v8,v3 * b.v5 + v7 * b.v6 + v11 * b.v7 + v15 * b.v8,v4 * b.v5 + v8 * b.v6 + v12 * b.v7 + v16 * b.v8,
		v1 * b.v9 + v5 * b.v10 + v9 * b.v11 + v13 * b.v12,v2 * b.v9 + v6 * b.v10 + v10 * b.v11 + v14 * b.v12,v3 * b.v9 + v7 * b.v10 + v11 * b.v11 + v15 * b.v12,v4 * b.v9 + v8 * b.v10 + v12 * b.v11 + v16 * b.v12,
		v1 * b.v13 + v5 * b.v14 + v9 * b.v15 + v13 * b.v16,v2 * b.v13 + v6 * b.v14 + v10 * b.v15 + v14 * b.v16,v3 * b.v13 + v7 * b.v14 + v11 * b.v15 + v15 * b.v16,v4 * b.v13 + v8 * b.v14 + v12 * b.v15 + v16 * b.v16,
	};
}
Mat4& Mat4::operator *=(const Mat4& b) {
	return *this = *this * b;
}
Vec4 Mat4::operator *(const Vec4& b) const {
	return {
		b.x * v1 + b.y * v5 + b.z * v9 + b.w * v13,
		b.x * v2 + b.y * v6 + b.z * v10 + b.w * v14,
		b.x * v3 + b.y * v7 + b.z * v11 + b.w * v15,
		b.x * v4 + b.y * v8 + b.z * v12 + b.w * v16,
	};
}
Vec4 Mat4::operator *(const Vec3& b) const {
	return {
		b.x * v1 + b.y * v5 + b.z * v9 + v13,
		b.x * v2 + b.y * v6 + b.z * v10 + v14,
		b.x * v3 + b.y * v7 + b.z * v11 + v15,
		b.x * v4 + b.y * v8 + b.z * v12 + v16,
	};
}
Mat4::operator const float* () const {
	return (float*)this;
}

Mat4 Mat4::Perspective(float fovy, float ratio, float nearPlane, float farPlane) {
	float v = farPlane - nearPlane;
	float t = tanf(fovy / 2);
	return { 1 / t,0,0,0,0,ratio / t,0,0,0,0,farPlane / v,1,0,0,-farPlane * nearPlane / v,0 };
}
Mat4 Mat4::Orthographic(float scale, float ratio, float nearPlane, float farPlane) {
	return { 1 / scale,0,0,0,0,ratio / scale,0,0,0,0,-2 / (farPlane - nearPlane),0,0,0,-(farPlane + nearPlane) / (farPlane - nearPlane),1 };
}

Mat4 Mat4::Scale(float x, float y, float z) {
	return { x,0,0,0,0,y,0,0,0,0,z,0,0,0,0,1 };
}
Mat4 Mat4::Translate(float x, float y, float z) {
	return { 1,0,0,0,0,1,0,0,0,0,1,0,x,y,z,1 };
}
Mat4 Mat4::RotationX(float v) {
	return { 1,0,0,0,0,cosf(v),sinf(v),0,0,-sinf(v),cosf(v),0,0,0,0,1 };
}
Mat4 Mat4::RotationY(float v) {
	return { cosf(v),0,-sinf(v),0,0,1,0,0,sinf(v),0,cosf(v),0,0,0,0,1 };
}
Mat4 Mat4::RotationZ(float v) {
	return { cosf(v),sinf(v),0,0,-sinf(v),cosf(v),0,0,0,0,1,0,0,0,0,1 };
}
Mat4 Mat4::RotationZXY(float x, float y, float z) {
	return RotationY(y) * RotationX(x) * RotationZ(z);
}