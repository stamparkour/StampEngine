#include <math.h>
#include <vector>
#include "glcore.h"
#include "glvec.h"
#include "glmat.h"
#include "glquat.h"
#include "glmesh.h"
#include "physics.h"

using namespace GLCore;
using namespace gl_math;

#define PI 3.141592653

struct Camera {
	Vec3 position{};
	Vec3 rotation{};
	Mat4 camera;

	Mat4 ToMatrix() {
		return camera * Mat4::RotationX(-rotation.x) * Mat4::RotationY(-rotation.y) * Mat4::Translate(-position.x, -position.y, -position.z);
	}

	Mat4 ToTransformMatrix() {
		return Mat4::Translate(-position.x, -position.y, -position.z) * Mat4::RotationZXY(rotation.x, rotation.y, rotation.z);
	}

	void Bind() {
		glMatrixMode(GL_PROJECTION);
		glLoadMatrixf(ToMatrix());
	}

	Vec3 forward() {
		Vec4 v = Mat4::RotationZXY(rotation.x, rotation.y, rotation.z) * Vec3(0, 0, 1);
		return Vec3(v.x, v.y, v.z);
	}

	Vec3 back() {
		Vec4 v = Mat4::RotationZXY(rotation.x, rotation.y, rotation.z) * Vec3(0, 0, -1);
		return Vec3(v.x, v.y, v.z);
	}

	Vec3 left() {
		Vec4 v = Mat4::RotationZXY(rotation.x, rotation.y, rotation.z) * Vec3(-1, 0, 0);
		return Vec3(v.x, v.y, v.z);
	}

	Vec3 right() {
		Vec4 v = Mat4::RotationZXY(rotation.x, rotation.y, rotation.z) * Vec3(1, 0, 0);
		return Vec3(v.x, v.y, v.z);
	}

	Vec3 up() {
		Vec4 v = Mat4::RotationZXY(rotation.x, rotation.y, rotation.z) * Vec3(0, 1, 0);
		return Vec3(v.x, v.y, v.z);
	}

	Vec3 down() {
		Vec4 v = Mat4::RotationZXY(rotation.x, rotation.y, rotation.z) * Vec3(0, -1, 0);
		return Vec3(v.x, v.y, v.z);
	}

	Vec3 planarForward() {
		Vec4 v = Mat4::RotationY(rotation.y) * Vec3(0, 0, 1);
		return Vec3(v.x, v.y, v.z);
	}

	Vec3 planarBack() {
		Vec4 v = Mat4::RotationY(rotation.y) * Vec3(0, 0, -1);
		return Vec3(v.x, v.y, v.z);
	}

	Vec3 planarRight() {
		Vec4 v = Mat4::RotationY(rotation.y) * Vec3(1, 0, 0);
		return Vec3(v.x, v.y, v.z);
	}

	Vec3 planarLeft() {
		Vec4 v = Mat4::RotationY(rotation.y) * Vec3(-1, 0, 0);
		return Vec3(v.x, v.y, v.z);
	}
};

struct LightSource {
	Vec4 ambientColor;
	Vec4 diffuseColor;
	Vec4 specularColor;

	virtual void Bind(int index) {
		glLightfv(GL_LIGHT0 + index, GL_AMBIENT, (float*)&ambientColor);
		glLightfv(GL_LIGHT0 + index, GL_DIFFUSE, (float*)&diffuseColor);
		glLightfv(GL_LIGHT0 + index, GL_SPECULAR, (float*)&specularColor);
		glEnable(GL_LIGHT0 + index);
	}

	static void Disable(int index) {
		glDisable(GL_LIGHT0 + index);
	}
};

struct SunLightSource final : LightSource {
	Vec3 direction;

	SunLightSource(Vec3 direction, Vec4 color) {
		this->direction = direction;
		ambientColor = {0,0,0,1};
		diffuseColor = color;
		specularColor = { 1,1,1,1 };
	}
	SunLightSource(Vec3 direction, Vec4 ambientColor, Vec4 diffuseColor, Vec4 specularColor) {
		this->direction = direction;
		this->ambientColor = ambientColor;
		this->diffuseColor = diffuseColor;
		this->specularColor = specularColor;
	}
	void Bind(int index) override {
		Vec4 v{direction.x, direction.y, direction.z, 0};
		Vec4 n = -v;
		glLightfv(GL_LIGHT0 + index, GL_POSITION, (float*)&(v));
		glLightfv(GL_LIGHT0 + index, GL_SPOT_DIRECTION, (float*)&n);
		LightSource::Bind(index);
	}
};

Vertex vertices_cube[36] = {
	//back face
	{{-1,-1,-1},{1,0,0}, {0,0}},
	{{1,-1,-1},{1,0,0}, {1,0}},
	{{1,1,-1},{1,0,0}, {1,1}},
	{{-1,-1,-1},{1,0,0}, {0,0}},
	{{1,1,-1},{1,0,0}, {1,1}},
	{{-1,1,-1},{1,0,0}, {0,1}},
	//front face
	{{-1,-1,1},{1,1,0}, {0,0}},
	{{1,1,1},{1,1,0}, {1,1}},
	{{1,-1,1},{1,1,0}, {1,0}},
	{{-1,-1,1},{1,1,0}, {0,0}},
	{{-1,1,1},{1,1,0}, {0,1}},
	{{1,1,1},{1,1,0}, {1,1}},
	//left face
	{{-1,-1,1},{0,1,0}, {0,0}},
	{{-1,-1,-1},{0,1,0}, {1,0}},
	{{-1,1,-1},{0,1,0}, {1,1}},
	{{-1,-1,1},{0,1,0}, {0,0}},
	{{-1,1,-1},{0,1,0}, {1,1}},
	{{-1,1,1},{0,1,0}, {0,1}},
	//right face
	{{1,-1,1},{0,1,1}, {0,1}},
	{{1,1,-1},{0,1,1}, {1,0}},
	{{1,-1,-1},{0,1,1}, {0,0}},
	{{1,-1,1},{0,1,1}, {0,1}},
	{{1,1,1},{0,1,1}, {1,1}},
	{{1,1,-1},{0,1,1}, {1,0}},
	//bottom face
	{{-1,-1,1},{0,0,1}, {0,1}},
	{{1,-1,1},{0,0,1}, {1,1}},
	{{1,-1,-1},{0,0,1}, {1,0}},
	{{-1,-1,1},{0,0,1}, {0,1}},
	{{1,-1,-1},{0,0,1}, {1,0}},
	{{-1,-1,-1},{0,0,1}, {0,0}},
	//top face
	{{-1,1,1},{1,0,1}, {0,1}},
	{{1,1,-1},{1,0,1}, {1,0}},
	{{1,1,1},{1,0,1}, {1,1}},
	{{-1,1,1},{1,0,1}, {0,1}},
	{{-1,1,-1},{1,0,1}, {0,0}},
	{{1,1,-1},{1,0,1}, {1,0}},
};

unsigned char rawTexture[] = {
	255,255,255,0,0,0,255,255,255,100,100,100,
	0,0,0,255,255,255,0,0,0,255,255,255,
	255,255,255,0,0,0,255,255,255,0,0,0,
	0,0,0,255,255,255,0,0,0,255,255,255
};
Mesh mesh{vertices_cube, sizeof(vertices_cube)/sizeof(Vertex)};
Transform t1{ {3,-1,8},{1,1,1},Quat::RotationZXY(0,2,1.3) };
Transform t2{ {-3,-1,8},{1,1,1},Quat::RotationZXY(.2,5,-1.3) };
SunLightSource light{ {0,-1,0}, {1,1,1,0} };
Camera camera{ {0,0,0}, {0,0,0}, Mat4_Identity};
Material material{ true, true, {1,1,1}, {1,1,1}, {1,1,1}, 0.4, {0,0,0}, {} };
Mesh colliderMesh;

void GLCore::Start(double time) {
	new (&material.texture) Texture(4, 4, 3, GL_UNSIGNED_BYTE, rawTexture);
	glClearColor(0.1, 0.3, 0.4, 1.);

	Collider collider{mesh};
	collider.ToMesh(&colliderMesh);

	glClearDepth(1);
	glDepthFunc(GL_LESS);
	glDepthMask(GL_TRUE);
	glDepthRange(0, 1);
	glEnable(GL_CULL_FACE);
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);

	//glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	light.Bind(0);
	mesh.GenNormals();
}

double prevTime = 0;
void GLCore::Update(double time) {
	double deltaTime = time - prevTime;
	t1.Rotate(0.2 * deltaTime, 0.5 * deltaTime, 0.8 * deltaTime);
	prevTime = time;

	float speed = 5 * deltaTime;
	float rotSpeed =60.f / 180 * PI * deltaTime;
	if (GLInput::IsKeyDown('W')) camera.position += camera.planarForward() * speed;
	if (GLInput::IsKeyDown('S')) camera.position += camera.planarBack() * speed;
	if (GLInput::IsKeyDown('D')) camera.position += camera.planarRight() * speed;
	if (GLInput::IsKeyDown('A')) camera.position += camera.planarLeft() * speed;
	if (GLInput::IsKeyDown('E')) camera.position += Vec3(0,1,0) * speed;
	if (GLInput::IsKeyDown('Q')) camera.position += Vec3(0, -1, 0) * speed;
	if (GLInput::IsKeyDown(VK_UP)) camera.rotation.x -= rotSpeed;
	if (GLInput::IsKeyDown(VK_DOWN)) camera.rotation.x += rotSpeed;
	if (GLInput::IsKeyDown(VK_RIGHT)) camera.rotation.y += rotSpeed;
	if (GLInput::IsKeyDown(VK_LEFT)) camera.rotation.y -= rotSpeed;
}

void GLCore::Render(double time) {
	camera.Bind();
	material.Bind();
	mesh.Render(t1.ToMatrix());
	mesh.Render(t2.ToMatrix());
}

void GLCore::Resize(double time, int width, int height) {
	camera.camera = Mat4::Perspective(80.0 / 180 * PI, (double)width / height, 0.5, 500);
}

void GLCore::KeyDown(int keyCode, bool isRepeat) {
	if (keyCode == VK_ESCAPE) {
		TerminateWindow();
	}
}

void GLCore::KeyUp(int keyCode) {

}