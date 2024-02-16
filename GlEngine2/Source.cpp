#include <Windows.h>
#include <fstream>
#include "gl.h"
#include "wincore.h"
#include "gamecore.h"
#include "glrender.h"
#include "audio.h"

//mouse pos https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-setcursorpos?redirectedfrom=MSDN
//hide mouse https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-showcursor
//change cursor https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-setcursor
#define AngleToRad 0.0174532925199f

class CameraController final : public game_core::Component {
	Component_Requirements(CameraController)
public:
	float rx = 0;
	float ry = 0;
	void Update(game_core::GameObject& gameObject) override {
		float mag = 5 * game_core::TimeManager::DeltaTime();
		float rag = 110 * AngleToRad * game_core::TimeManager::DeltaTime();
		if (game_core::ControlsManager::isKeyDown('W'))
			gameObject.transform.position += gameObject.transform.forward() * mag;
		if (game_core::ControlsManager::isKeyDown('S'))
			gameObject.transform.position += gameObject.transform.back() * mag;
		if (game_core::ControlsManager::isKeyDown('D'))
			gameObject.transform.position += gameObject.transform.right() * mag;
		if (game_core::ControlsManager::isKeyDown('A'))
			gameObject.transform.position += gameObject.transform.left() * mag;
		if (game_core::ControlsManager::isKeyDown('R'))
			gameObject.transform.position += gl_math::Vec3{0,1,0} *mag;
		if (game_core::ControlsManager::isKeyDown('F'))
			gameObject.transform.position += gl_math::Vec3{0,-1,0} *mag;
		if (game_core::ControlsManager::isKeyDown(VK_UP))
			ry += rag;
		if (game_core::ControlsManager::isKeyDown(VK_DOWN))
			ry -= rag;
		if (game_core::ControlsManager::isKeyDown(VK_RIGHT))
			rx += rag;
		if (game_core::ControlsManager::isKeyDown(VK_LEFT))
			rx -= rag;

		gameObject.transform.rotation = gl_math::Quat::RotationZYX(-ry, rx, 0);
	}
};

#define GRAV_MASS 1.f
#define GRAV_RADIUS 1.f
class Gravity;
std::vector<Gravity*>* gravity;
class Gravity final : public game_core::Component {
	Component_Requirements(Gravity)
private:
	
	size_t index = -1;
	gl_math::Vec3 pos = {};
	gl_math::Vec3 vel = {};
public:
	void Start(game_core::GameObject& gameObject) {
		if (!gravity) gravity = new std::vector<Gravity*>();
		index = gravity->size();
		gravity->push_back(this);
		float range = 100;
		pos = { ((float)rand() / RAND_MAX) * range - range/2,((float)rand() / RAND_MAX) * range - range / 2 ,((float)rand() / RAND_MAX) * range - range / 2 };
		
	}
	void Update(game_core::GameObject& gameObject) override {
		if (index == 0) {
			for (size_t i = 0; i < gravity->size(); i++) {
				(*gravity)[i]->pos += (*gravity)[i]->vel * game_core::TimeManager::DeltaTime();
			}
		}

		for (size_t i = 0; i < index; i++) {
			gl_math::Vec3 offset = (*gravity)[i]->pos - pos;
			float distSqrd = offset.MagnitudeSquared();
			if (distSqrd == 0) continue;
			float d = sqrt(distSqrd);
			gl_math::Vec3 norm = offset / d;
			float f = 0;
			gl_math::Vec3 force = { 0,0,0 };
			if (d < GRAV_RADIUS) {
				f = GRAV_MASS * 100 / GRAV_RADIUS * d - GRAV_MASS * 100;
				gl_math::Vec3 v = (*gravity)[i]->vel - vel;
				force += v * 0.1 * game_core::TimeManager::DeltaTime();;
			}
			else {
				f = GRAV_MASS / distSqrd;
			}
			force += norm * f * game_core::TimeManager::DeltaTime();
			vel += force;
			(*gravity)[i]->vel -= force;
		}

		gameObject.transform.position = pos;
	}
};

game_core::GameManager manager{};
game_core::Scene scene{};
void win_event::Start(double time) {

	game_core::GameObject cam{};
	cam.AddComponent(game_component::Camera{});
	cam.AddComponent(CameraController{});
	cam.transform.position.z = -100;
	scene.AddObject(cam);

	for (int i = 0; i < 500; i++) {
		game_core::GameObject cube{};
		game_component::MeshRenderer meshRenderer = {};
		meshRenderer.mesh = &game_render::Mesh::cubePrimative;
		meshRenderer.applyShadow = true;
		meshRenderer.material = game_render::Material::defaultMaterial;
		meshRenderer.material.useTexture = true;
		meshRenderer.material.texture = game_render::Texture::BmpTexture(game_core::readFile("C:\\Users\\Stamp\\Downloads\\640-480-sample.bmp", NULL));
		cube.AddComponent(meshRenderer);
		cube.transform.scale = gl_math::Vec3{ 1,1,1 } * 0.5f;
		cube.AddComponent(Gravity{});
		scene.AddObject(cube);
	}

	game_core::GameObject sun{};
	sun.transform.Rotate(-120 * AngleToRad, 0, 0);
	auto sunlight = game_component::SunLight{ {0.05f, 0.05f, 0.05f,0}, {0.95f,0.95f,0.95f,0},{0,0,0,0} };
	sunlight.isShadowLight = false;
	sun.AddComponent(sunlight);
	scene.AddObject(sun);

	manager.scene = &scene;

	glClearColor(0.1f, 0.3f, 0.4f, 1.f);
	glClearStencil(0);
	glClearDepth(1);
	glDepthFunc(GL_LEQUAL);
	glDepthRange(0, 1);
	glEnable(GL_STENCIL_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glFogi(GL_FOG_MODE, GL_LINEAR);
	glFogf(GL_FOG_START, 0.5);
	glFogf(GL_FOG_END, 1.);
	glFogfv(GL_FOG_COLOR, (float*)gl_math::Vec4{0,0,0,0});

	manager.Initialize();
}

void win_event::Update(double time) {
	manager.Update(time);
}

void win_event::SyncUpdate(double time) {
	manager.SyncUpdate();
}

void win_event::Resize(double time, int width, int height) {
	manager.Resize(width, height);
}

void win_event::Render(double time) {
	manager.Render();
}

void win_input::KeyDown(int keyCode, bool isRepeat) {//https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
	manager.KeyDown(keyCode);
}

void win_input::KeyUp(int keyCode) {
	manager.KeyUp(keyCode);
}