#pragma once
#include "glcore.h"
#include "glvec.h"
#include "glmat.h"
#include "glquat.h"
#include <vector>
using namespace gl_math;

struct Collision {
	bool collided;
	Vec3 pos;
	Vec3 norm;
};

struct ColliderFace {
	int A;
	int B;
	int C;

	bool operator ==(const ColliderFace& b) const {//abc bca cab acb cba bac
		if (A == b.A && B == b.B && C == b.C) return true;
		if (A == b.B && B == b.C && C == b.A) return true;
		if (A == b.B && B == b.C && C == b.A) return true;
		if (A == b.C && B == b.A && C == b.B) return true;
		if (A == b.A && B == b.C && C == b.B) return true;
		if (A == b.C && B == b.B && C == b.A) return true;
		if (A == b.B && B == b.A && C == b.C) return true;

		return false;
	}

	bool operator ==(int b) const {//abc bca cab acb cba bac
		if (A == b) return true;
		if (B == b) return true;
		if (C == b) return true;

		return false;
	}
};

struct Collider {
	std::vector<ColliderFace> faces{};
	std::vector<Vec3> points{};

	Collider(const Mesh& mesh) {
		SetPoints(mesh);
		SetFacesToSimplex();
		int v = 0;
		for (int i = 0; i < points.size(); i++) {
			for (int j = 0; j < faces.size(); j++) {
				TryAddPoint(j, i);
			}
		}
	}

	void ToMesh(Mesh* mesh) {
		size_t v = faces.size();
		Vertex* vert = new Vertex[v * 3];
		for (int i = 0; i < v*3; i+=3) {
			Vec3 color = { (rand() & 255) / 255.f,(rand() & 255) / 255.f ,(rand() & 255) / 255.f };
			vert[i] = { points[faces[i].A], color, {0,0}, {0,0,0} };
			vert[i + 1] = { points[faces[i].C], color, {0,0}, {0,0,0} };
			vert[i + 2] = { points[faces[i].B], color, {0,0}, {0,0,0} };
		}
		*mesh = { vert, v * 3 };
		mesh->GenNormals();
	}

	Collision IsCollided(const Collider& other, const Transform& A, const Transform& B) const {
		Mat4 m1 = A.ToMatrix();
		Mat4 m2 = B.ToMatrix();
		for (int i = 0; i < other.points.size(); i++) {
			if (IsPointInside((Vec3)(m2 * other.points[i]), A)) {
				return { true, (Vec3)(m2 * other.points[i]), {0,0,0} };
			}
		}
		for (int i = 0; i < points.size(); i++) {
			if (other.IsPointInside((Vec3)(m1 * points[i]), A)) {
				return { true, (Vec3)(m1 * points[i]), {0,0,0} };
			}
		}
		return { false, {0,0,0}, {0,0,0} };
	}

private:
	void SetPoints(const Mesh& mesh) {
		new (&points) std::vector<Vec3>{};
		for (int i = 0; i < mesh.vertices_length; i++) {
			bool v = true;
			for (int j = 0; j < points.size(); j++) {
				if (points[j] == mesh.vertices[i].position) {
					v = false;
					break;
				}
			}
			if (v) points.push_back(mesh.vertices[i].position);
		}
	}

	int CanAddFace(const ColliderFace& face) {
		for (int j = 0; j < faces.size(); j++) {
			if (faces[j] == face)
				return j;
		}
		return -1;
	}

	bool IsPointInside(const Vec3& p, const Transform& t) const  {
		Mat4 m = t.ToMatrix();
		for (int i = 0; i < faces.size(); i++) {
			if (GetDistanceFromPlane((Vec3)(m * points[faces[i].A]), (Vec3)(m * points[faces[i].B]), (Vec3)(m * points[faces[i].C]), p) > 0)
				return false;
		}
		return true;
	}

	bool IsLineInside(const Vec3& a, const Vec3& b, const Transform& t) const {
		Mat4 m = t.ToMatrix();
		for (int i = 0; i < faces.size(); i++) {
			if (GetDistanceFromPlane((Vec3)(m * points[faces[i].A]), (Vec3)(m * points[faces[i].B]), (Vec3)(m * points[faces[i].C]), a) > 0 &&
				GetDistanceFromPlane((Vec3)(m * points[faces[i].A]), (Vec3)(m * points[faces[i].B]), (Vec3)(m * points[faces[i].C]), b) > 0)
				return false;
		}
		return true;
	}

	bool TryAddPoint(int& face, int& point) {
		if (faces[face] == point) return -1;
		float v = GetDistanceFromPlane(points[faces[face].A], points[faces[face].B], points[faces[face].C], points[point]);
		if (v <= 0)
			return false;

		ColliderFace a = { faces[face].B, faces[face].C, point };
		ColliderFace b = { faces[face].C,faces[face].A, point };
		ColliderFace c = { faces[face].A,faces[face].B, point };

		int i;
		bool j = false;
		if ((i = CanAddFace(a)) >= 0) {
			if (i < face) face--;
			faces.erase(faces.begin() + i);
		}
		else {
			if (j) faces.push_back(a);
			else {
				faces[face] = a;
				j = true;
			}
		}
		if ((i = CanAddFace(b)) >= 0) {
			if (i < face) face--;
			faces.erase(faces.begin() + i);
		}
		else {
			if (j) faces.push_back(b);
			else {
				faces[face] = b;
				j = true;
			}
		}
		if ((i = CanAddFace(c)) >= 0) {
			if (i < face) face--;
			faces.erase(faces.begin() + i);
		}
		else {
			if (j) faces.push_back(c);
			else {
				faces[face] = c;
				j = true;
			}
		}

		return true;
	}

	static float GetDistanceFromLine(const Vec3& a, const Vec3& b, const Vec3& x) {
		Vec3 norm = (b - a).Normal();
		Vec3 off = x - a;
		float t = Vec3::Dot(off, norm);
		Vec3 p = norm * t + a;
		return (p - x).Magnitude();
	}

	static float GetDistanceFromPlane(const Vec3& a, const Vec3& b, const Vec3& c, const Vec3& x) {
		Vec3 n = Vec3::Cross(b - a, c - a).Normal();
		return  Vec3::Dot(n, x) - Vec3::Dot(n, a);
	}

	bool SetFacesToSimplex() {
		int maxX = 0;
		int minX = 0;
		int maxY = 0;
		int minY = 0;
		int maxZ = 0;
		int minZ = 0;
		for (int i = 0; i < points.size(); i++) {
			if (points[i].x < points[minX].x) minX = i;
			if (points[i].x > points[maxX].x) maxX = i;
			if (points[i].y < points[minY].y) minY = i;
			if (points[i].y > points[maxY].y) maxY = i;
			if (points[i].z < points[minZ].z) minZ = i;
			if (points[i].z > points[maxZ].z) maxZ = i;
		}
		if (maxX == minX) return false;
		if (maxY == minY) return false;
		if (maxZ == minZ) return false;


		int maxDistLine = 0;
		float dist = 0;
		for (int i = 0; i < points.size(); i++) {
			if (i == maxX || i == minX) continue;
			float d = GetDistanceFromLine(points[0], points[1], points[i]);
			if (d > dist) {
				dist = d;
				maxDistLine = i;
			}
		}
		if (dist == 0) return false;

		int maxDistPlane = 0;
		dist = 0;
		for (int i = 0; i < points.size(); i++) {
			if (i == maxX || i == minX || i == maxDistLine) continue;
			float d = GetDistanceFromPlane(points[0], points[1], points[maxDistLine], points[i]);
			if (dist >= 0 && d > dist || dist <= 0 && d < dist) {
				dist = d;
				maxDistPlane = i;
			}
		}
		if (dist == 0) return false;

		new (&faces) std::vector<Vec3>{};
		if (dist < 0) {
			faces.push_back({ minX,maxX,maxDistLine });
			faces.push_back({ minX,maxDistPlane,maxX });
			faces.push_back({ maxX,maxDistPlane,maxDistLine });
			faces.push_back({ maxDistLine,maxDistPlane,minX });
		}
		else {
			faces.push_back({ minX,maxDistLine,maxX });
			faces.push_back({ minX,maxX,maxDistPlane });
			faces.push_back({ maxX,maxDistLine,maxDistPlane });
			faces.push_back({ maxDistLine,minX,maxDistPlane });
		}

		return true;
	}
};

struct RigidBody {
	Collider* collider;
	Transform* transform;
	Vec3 velocity;
	Quat angularVelocity;
	float weight;

	void AddForce(const Vec3& force, const Vec3& offset) {
		float l;
		if (offset.Magnitude() == 0) l = 1;
		else {
			l = Vec3::Dot(offset, force);
		}

		if (l < 0) {
			velocity += force * -l / weight;
			angularVelocity *= Quat::RotationAxis(-force.Magnitude() * (1 - l) / weight, Vec3::Cross(offset, velocity));
		}
		else { 
			velocity += force * l / weight; 
			angularVelocity *= Quat::RotationAxis(force.Magnitude() * (1 - l) / weight, Vec3::Cross(offset, velocity));
		}
	}

	void AddForce(const Vec3& force) {
		velocity += force / weight;
	}

	void ApplyVelocity(float deltaTime) {
		transform->position += velocity * deltaTime;
		transform->rotation *= angularVelocity * deltaTime;
	}
private:
	

	Transform GetInterpTransform(float v, float deltaTime) {
		Transform t = *transform;
		t.position += velocity * deltaTime * v;
		t.rotation *= angularVelocity * deltaTime * v;
		return t;
	}

	Vec3 GetForceAtPoint(const Vec3& pos) {
		Vec3 a = velocity + (pos - angularVelocity * pos);
		return a * weight;
	}
};
