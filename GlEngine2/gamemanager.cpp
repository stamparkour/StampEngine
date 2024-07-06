#include "wincore.h"
#include "gamecore.h"
#include "glmath.h"
using namespace game::math;

void game::core::Transform::Rotate(float x, float y, float z) {
	rotation = (Quat::RotationZXY(x, y, z) * rotation).Unit();
}

Mat4 game::core::Transform::ToMatrix() const {
	return Mat4::Translate(position.x, position.y, position.z) * rotation.ToRotationMatrix() * Mat4::Scale(scale.x, scale.y, scale.z);
}

Mat4 game::core::Transform::ToMatrixInverse() const {
	return Mat4::Scale(1 / scale.x, 1 / scale.y, 1 / scale.z) * rotation.Inverse().ToRotationMatrix() * Mat4::Translate(-position.x, -position.y, -position.z);
}

Vec3 game::core::Transform::forward() const {
	Vec4 v = rotation.ToRotationMatrix() * Vec3(0, 0, 1);
	return Vec3(v.x, v.y, v.z);
}

Vec3 game::core::Transform::back() const {
	Vec4 v = rotation.ToRotationMatrix() * Vec3(0, 0, -1);
	return Vec3(v.x, v.y, v.z);
}

Vec3 game::core::Transform::left() const {
	Vec4 v = rotation.ToRotationMatrix() * Vec3(-1, 0, 0);
	return Vec3(v.x, v.y, v.z);
}

Vec3 game::core::Transform::right() const {
	Vec4 v = rotation.ToRotationMatrix() * Vec3(1, 0, 0);
	return Vec3(v.x, v.y, v.z);
}

Vec3 game::core::Transform::up() const {
	Vec4 v = rotation.ToRotationMatrix() * Vec3(0, 1, 0);
	return Vec3(v.x, v.y, v.z);
}

Vec3 game::core::Transform::down() const {
	Vec4 v = rotation.ToRotationMatrix() * Vec3(0, -1, 0);
	return Vec3(v.x, v.y, v.z);
}