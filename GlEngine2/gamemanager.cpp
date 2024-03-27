#include "wincore.h"
#include "gamecore.h"
#include "glmath.h"
using namespace gl_math;

void game_core::Transform::Rotate(float x, float y, float z) {
	rotation = (Quat::RotationZXY(x, y, z) * rotation).Unit();
}

Mat4 game_core::Transform::ToMatrix() const {
	return Mat4::Translate(position.x, position.y, position.z) * rotation.ToRotationMatrix() * Mat4::Scale(scale.x, scale.y, scale.z);
}

Mat4 game_core::Transform::ToMatrixInverse() const {
	return rotation.Inverse().ToRotationMatrix() * Mat4::Translate(-position.x, -position.y, -position.z) * Mat4::Scale(1 / scale.x, 1 / scale.y, 1 / scale.z);
}

Vec3 game_core::Transform::forward() const {
	Vec4 v = rotation.ToRotationMatrix() * Vec3(0, 0, 1);
	return Vec3(v.x, v.y, v.z);
}

Vec3 game_core::Transform::back() const {
	Vec4 v = rotation.ToRotationMatrix() * Vec3(0, 0, -1);
	return Vec3(v.x, v.y, v.z);
}

Vec3 game_core::Transform::left() const {
	Vec4 v = rotation.ToRotationMatrix() * Vec3(-1, 0, 0);
	return Vec3(v.x, v.y, v.z);
}

Vec3 game_core::Transform::right() const {
	Vec4 v = rotation.ToRotationMatrix() * Vec3(1, 0, 0);
	return Vec3(v.x, v.y, v.z);
}

Vec3 game_core::Transform::up() const {
	Vec4 v = rotation.ToRotationMatrix() * Vec3(0, 1, 0);
	return Vec3(v.x, v.y, v.z);
}

Vec3 game_core::Transform::down() const {
	Vec4 v = rotation.ToRotationMatrix() * Vec3(0, -1, 0);
	return Vec3(v.x, v.y, v.z);
}