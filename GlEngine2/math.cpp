#include "glmat.h"
#include "glquat.h"
#include "glvec.h"
#include "glquat.h"
using namespace game::math;
RectI::RectI() noexcept {
	this->x = 0;
	this->y = 0;
	this->w = 0;
	this->h = 0;
	this->ox = 0;
	this->oy = 0;
}
RectI::RectI(int x, int y, int w, int h, int ox, int oy) noexcept {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->ox = ox;
	this->oy = oy;
}
Rect::Rect() noexcept {
	this->x = 0;
	this->y = 0;
	this->w = 0;
	this->h = 0;
	this->ox = 0;
	this->oy = 0;
}
Rect::Rect(float x, float y, float w, float h, float ox, float oy) noexcept {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->ox = ox;
	this->oy = oy;
}
Vec2I::Vec2I() noexcept {
	x = 0;
	y = 0;
}
Vec2I::Vec2I(int x, int y) noexcept {
	this->x = x;
	this->y = y;
}
Vec2I game::math::Vec2I::operator+(const Vec2I& b) const noexcept
{
	return { x + b.x,y + b.y };
}
Vec2I game::math::Vec2I::operator-(const Vec2I& b) const noexcept
{
	return { x - b.x,y - b.y };
}
Vec2I game::math::Vec2I::operator*(int b) const noexcept
{
	return { x * b,y * b };
}
Vec2I game::math::Vec2I::operator/(int b) const noexcept
{
	return { x / b,y / b };
}
Vec2I& game::math::Vec2I::operator+=(const Vec2I& b) noexcept
{
	return *this = *this + b;
}
Vec2I& game::math::Vec2I::operator-=(const Vec2I& b) noexcept
{
	return *this = *this - b;
}
Vec2I& game::math::Vec2I::operator*=(int b) noexcept
{
	return *this = *this * b;
}
Vec2I& game::math::Vec2I::operator/=(int b) noexcept
{
	return *this = *this / b;
}
Vec2I game::math::Vec2I::operator-() const noexcept
{
	return { -x,-y };
}
Vec2::Vec2() noexcept {
	x = 0;
	y = 0;
}
Vec2::Vec2(float x, float y) noexcept { 
	this->x = x;
	this->y = y;
}
Vec2 Vec2::operator +(const Vec2& b) const noexcept {
	return { x + b.x,y + b.y };
}
Vec2 Vec2::operator -(const Vec2& b) const noexcept {
	return { x - b.x,y - b.y };
}
Vec2 Vec2::operator -() const noexcept {
	return { -x, -y };
}
Vec2 Vec2::operator *(float b) const noexcept {
	return { x * b, y * b };
}
Vec2 Vec2::operator /(float b) const noexcept {
	return { x / b, y / b };
}
Vec2::operator Vec4() const noexcept {
	return { x,y,0,0 };
}
Vec2::operator Vec3() const noexcept {
	return { x,y,0 };
}
float Vec2::Dot(const Vec2& a, const Vec2& b) noexcept {
	return a.x * b.x + a.y * b.y;
}
Vec3::Vec3() noexcept {}
Vec3::Vec3(float x, float y, float z) noexcept {
	this->x = x;
	this->y = y;
	this->z = z;
}
Vec3& Vec3::operator +=(const Vec3& b) noexcept {
	x += b.x;
	y += b.y;
	z += b.z;
	return *this;
}
Vec3& Vec3::operator -=(const Vec3& b) noexcept {
	x -= b.x;
	y -= b.y;
	z -= b.z;
	return *this;
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
Vec3 Vec3::Cross(const Vec3& a, const Vec3& b) noexcept {
	return { a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x };
}
float Vec3::Dot(const Vec3& a, const Vec3& b) noexcept {
	return a.x * b.x + a.y * b.y + a.z * b.z;
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
Vec3::operator Vec4() const noexcept {
	return { x,y,z,0 };
}
Vec3::operator Vec2() const noexcept {
	return { x,y };
}
Vec4::Vec4() noexcept {}
Vec4::Vec4(float x, float y, float z, float w) noexcept {
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}
Vec4 Vec4::operator +(const Vec4& b) const noexcept {
	return { x + b.x,y + b.y, z + b.z, w + b.w };
}
Vec4 Vec4::operator -(const Vec4& b) const noexcept {
	return { x - b.x,y - b.y, z - b.z, w - b.w };
}
Vec4 Vec4::operator -() const noexcept {
	return { -x, -y, -z, -w };
}
Vec4 Vec4::operator *(float b) const noexcept {
	return { x * b, y * b, z * b, w / b };
}
Vec4 Vec4::operator /(float b) const noexcept {
	return { x / b, y / b, z / b, w / b };
}
Vec4::operator Vec3() const noexcept {
	return { x,y,z };
}
Vec4::operator Vec2() const noexcept {
	return { x,y };
}
float Vec4::Dot(const Vec4& a, const Vec4& b) noexcept {
	return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

Vec4::operator float* () const noexcept {
	return (float*)this;
}
Quat Quat::Conjugate() const noexcept {
	return { w,-x,-y,-z };
}
float Quat::NormSquared() const noexcept {
	return w * w + x * x + y * y + z * z;
}
float Quat::Norm() const noexcept {
	return sqrtf(NormSquared());
}
Quat Quat::Unit() const noexcept {
	return (*this) / Norm();
}
Quat Quat::Inverse() const noexcept {
	return Conjugate() / NormSquared();
}
Mat4 Quat::ToRotationMatrix() const noexcept {
	return { 1 - 2 * (y * y + z * z), 2 * (x * y + z * w), 2 * (x * z - y * w), 0,2 * (x * y - z * w), 1 - 2 * (x * x + z * z), 2 * (y * z + x * w), 0,2 * (x * z + y * w), 2 * (y * z - x * w), 1 - 2 * (x * x + y * y), 0,0,0,0,1 };
}

Quat Quat::operator +(const Quat& b) const noexcept {
	return { w + b.w,x + b.x,y + b.y,z + b.z };
}
Quat Quat::operator -(const Quat& b) const noexcept {
	return { w - b.w,x - b.x,y - b.y,z - b.z };
}
Quat Quat::operator *(float b) const noexcept {
	return { w * b,x * b,y * b,z * b };
}
Quat Quat::operator *(const Quat& b) const noexcept {
	return { w * b.w - x * b.x - y * b.y - z * b.z,w * b.x + x * b.w + y * b.z - z * b.y,w * b.y - x * b.z + y * b.w + z * b.x,w * b.z + x * b.y - y * b.x + z * b.w };
}
Vec3 Quat::operator *(const Vec3& b) const noexcept {
	Quat v = *this * Quat{ 0,-b.x,-b.y,-b.z } *this->Inverse();
	return { v.x,v.y,v.z };
}
Quat Quat::operator /(float b) const noexcept {
	return { w / b,x / b,y / b,z / b };
}
Quat Quat::operator /(const Quat& b) const noexcept {
	return (*this) * b.Inverse();
}
Quat& Quat::operator *=(const Quat& b) noexcept {
	*this = *this * b;
	return *this;
}
Quat& Quat::operator *=(float b) noexcept {
	*this = *this * b;
	return *this;
}

Quat Quat::RotationX(float v) noexcept {
	return { cosf(v / 2),sinf(v / 2),0,0 };
}
Quat Quat::RotationY(float v) noexcept {
	return { cosf(v / 2),0,sinf(v / 2),0 };
}
Quat Quat::RotationZ(float v) noexcept {
	return { cosf(v / 2),0,0,sinf(v / 2) };
}
Quat Quat::RotationAxis(float r, const Vec3& axis) noexcept {
	Vec3 a = axis.Normal();
	return { cosf(r / 2),a.x * sinf(r / 2),a.y * sinf(r / 2),a.z * sinf(r / 2) };
}

Quat Quat::RotationZXY(float x, float y, float z) noexcept {
	return Quat::RotationZ(z) * Quat::RotationX(x) * Quat::RotationY(y);
}

Quat Quat::RotationZYX(float x, float y, float z) noexcept {
	return Quat::RotationZ(z) * Quat::RotationY(y) * Quat::RotationX(x);
}

Mat4 Mat4::operator +(const Mat4& b) const {
	return { v1 + b.v1,v2 + b.v2,v3 + b.v3,v4 + b.v4,v5 + b.v5,v6 + b.v6,v7 + b.v7,v8 + b.v8,v9 + b.v9,v10 + b.v10,v11 + b.v11,v12 + b.v12,v13 + b.v13,v14 + b.v14,v15 + b.v15,v16 + b.v16 };
}
Mat4 Mat4::operator -(const Mat4& b) const {
	return { v1 - b.v1,v2 - b.v2,v3 - b.v3,v4 - b.v4,v5 - b.v5,v6 - b.v6,v7 - b.v7,v8 - b.v8,v9 - b.v9,v10 - b.v10,v11 - b.v11,v12 - b.v12,v13 - b.v13,v14 - b.v14,v15 - b.v15,v16 - b.v16 };
}
Mat4 Mat4::operator -() const {
	return { -v1,-v2,-v3,-v4,-v5,-v6,-v7,-v8,-v9,-v10,-v11,-v12,-v13,-v14,-v15,-v16 };
}
Mat4 Mat4::operator *(float v) const {
	return { v1 * v,v2 * v,v3 * v,v4 * v,v5 * v,v6 * v,v7 * v,v8 * v,v9 * v,v10 * v,v11 * v,v12 * v,v13 * v,v14 * v,v15 * v,v16 * v };
}
Mat4 Mat4::operator /(float v) const {
	return { v1 / v,v2 / v,v3 / v,v4 / v,v5 / v,v6 / v,v7 / v,v8 / v,v9 / v,v10 / v,v11 / v,v12 / v,v13 / v,v14 / v,v15 / v,v16 / v };
}
Mat4 Mat4::operator *(const Mat4& b) const {
	return {
		v1 * b.v1 + v5 * b.v2 + v9 * b.v3 + v13 * b.v4,v2 * b.v1 + v6 * b.v2 + v10 * b.v3 + v14 * b.v4,v3 * b.v1 + v7 * b.v2 + v11 * b.v3 + v15 * b.v4,v4 * b.v1 + v8 * b.v2 + v12 * b.v3 + v16 * b.v4,
		v1 * b.v5 + v5 * b.v6 + v9 * b.v7 + v13 * b.v8,v2 * b.v5 + v6 * b.v6 + v10 * b.v7 + v14 * b.v8,v3 * b.v5 + v7 * b.v6 + v11 * b.v7 + v15 * b.v8,v4 * b.v5 + v8 * b.v6 + v12 * b.v7 + v16 * b.v8,
		v1 * b.v9 + v5 * b.v10 + v9 * b.v11 + v13 * b.v12,v2 * b.v9 + v6 * b.v10 + v10 * b.v11 + v14 * b.v12,v3 * b.v9 + v7 * b.v10 + v11 * b.v11 + v15 * b.v12,v4 * b.v9 + v8 * b.v10 + v12 * b.v11 + v16 * b.v12,
		v1 * b.v13 + v5 * b.v14 + v9 * b.v15 + v13 * b.v16,v2 * b.v13 + v6 * b.v14 + v10 * b.v15 + v14 * b.v16,v3 * b.v13 + v7 * b.v14 + v11 * b.v15 + v15 * b.v16,v4 * b.v13 + v8 * b.v14 + v12 * b.v15 + v16 * b.v16,
	};
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