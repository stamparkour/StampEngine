#include <Windows.h>
#include <fstream>
#include "gl.h"
#include "wincore.h"
#include "gamecore.h"
#include "glrender.h"
#include "audio.h"
#include "gameresources.h"

//mouse pos https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-setcursorpos?redirectedfrom=MSDN
//hide mouse https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-showcursor
//change cursor https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-setcursor
#define AngleToRad 0.0174532925199f

class CameraController final : public game::core::Component {
	Component_Requirements(CameraController)
public:
	float rx = 0;
	float ry = 0;
	void Update() override {
		float mag = 10 * game::core::TimeManager::DeltaTime();
		float rag = 110 * AngleToRad * game::core::TimeManager::DeltaTime();
		if (game::core::ControlsManager::isKeyDown('W'))
			selfObject()->transform.position += selfObject()->transform.forward() * mag;
		if (game::core::ControlsManager::isKeyDown('S'))
			selfObject()->transform.position += selfObject()->transform.back() * mag;
		if (game::core::ControlsManager::isKeyDown('D'))
			selfObject()->transform.position += selfObject()->transform.right() * mag;
		if (game::core::ControlsManager::isKeyDown('A'))
			selfObject()->transform.position += selfObject()->transform.left() * mag;
		if (game::core::ControlsManager::isKeyDown('R'))
			selfObject()->transform.position += game::math::Vec3{ 0,1,0 } *mag;
		if (game::core::ControlsManager::isKeyDown('F'))
			selfObject()->transform.position += game::math::Vec3{ 0,-1,0 } *mag;
		if (game::core::ControlsManager::isKeyDown(VK_UP))
			ry += rag;
		if (game::core::ControlsManager::isKeyDown(VK_DOWN))
			ry -= rag;
		if (game::core::ControlsManager::isKeyDown(VK_RIGHT))
			rx += rag;
		if (game::core::ControlsManager::isKeyDown(VK_LEFT))
			rx -= rag;

		selfObject()->transform.rotation = game::math::Quat::RotationZYX(-ry, rx, 0);
	}
};

#define GRAV_MASS 1.f
#define GRAV_RADIUS 2.0f
class Gravity;
std::vector<Gravity*>* gravity;
class Gravity final : public game::core::Component {
	Component_Requirements(Gravity)
private:

	size_t index = -1;
	game::math::Vec3 pos = {};
	game::math::Vec3 ppos = {};
	game::math::Vec3 vel = {};
	float temp = 0;
	game::component::MeshRenderer* renderer;
public:
	game::math::Vec3 orig;
	void Start() override {
		if (!gravity) gravity = new std::vector<Gravity*>();
		index = gravity->size();
		gravity->push_back(this);
		float range = 200;
		pos = orig + game::math::Vec3{ ((float)rand() / RAND_MAX) * range - range / 2,((float)rand() / RAND_MAX) * range - range / 2, 0};
		renderer = selfObject()->GetComponent<game::component::MeshRenderer>();

	}
	void Update() override {
		if (index == 0) {
			for (size_t i = 0; i < gravity->size(); i++) {
				(*gravity)[i]->pos += (*gravity)[i]->vel * game::core::TimeManager::DeltaTime();
				//(*gravity)[i]->ppos = (*gravity)[i]->pos + (*gravity)[i]->vel * game::core::TimeManager::DeltaTime();
			}
		}

		for (size_t i = 0; i < index; i++) {
			game::math::Vec3 offset = (*gravity)[i]->pos - pos;
			float distSqrd = offset.MagnitudeSquared();
			if (distSqrd == 0) continue;
			float d = sqrt(distSqrd);
			game::math::Vec3 norm = offset / d;
			float f = 0;
			game::math::Vec3 force = { 0,0,0 };
			if (d < GRAV_RADIUS) {
				float t = (temp + (*gravity)[i]->temp) / 2;
				f = GRAV_MASS * 10 * t / distSqrd * (d / GRAV_RADIUS - 1);
				game::math::Vec3 v = (*gravity)[i]->vel - vel;
				force += v * 0.2f * game::core::TimeManager::DeltaTime();
				temp += 1 / distSqrd * 0.02;
				(*gravity)[i]->temp += 1 / distSqrd * 0.02;
			}
			else {
				f = GRAV_MASS / distSqrd;
			}
			force += norm * f * game::core::TimeManager::DeltaTime();
			vel += force;
			(*gravity)[i]->vel -= force;
		}

		selfObject()->transform.position = pos;
		temp *= 1 - 0.02 * game::core::TimeManager::DeltaTime();
		renderer->material.get()->diffuseColor = game::math::Vec4{1,1,1,0} *min(1, temp / 40);
	}
};

class LightingTest final : public game::core::Component {
	Component_Requirements(LightingTest)
private:

public:
	void Update() override {
		selfObject()->transform.Rotate(0, game::core::TimeManager::DeltaTime() * 360 / 4 * AngleToRad, 0);
	}
};


game::core::GameManager manager{};
game::core::Scene scene{};
void win::event::Start(double time) {
	game::resources::Initizialize();

	auto map = game::resources::font(game::resources::fontIndex("ariel_24"));
	game::component::TextRenderer textTest = {};
	textTest.map = map;
	textTest.setText("THE QUICK BROWN FOX JUMPED OVER THE LAZY DOG", 0.5, 0.f);

	std::shared_ptr<game::render::Mesh> mesh = game::resources::mesh(game::resources::meshIndex("testmesh"));

	game::core::GameObject cam{};
	cam.AddComponent(game::component::Camera{});
	cam.AddComponent(CameraController{});
	cam.transform.position = { 0,0,-5};
	scene.AddObject(cam);

	game::core::GameObject monke{};
	game::component::MeshRenderer meshRenderer = {};
	meshRenderer.mesh = mesh;
	meshRenderer.material = game::resources::material(game::resources::materialIndex("sky"));
	monke.AddComponent(meshRenderer);
	scene.AddObject(monke);

	game::core::GameObject cube{};
	game::component::MeshRenderer meshRenderer1 = {};
	meshRenderer1.mesh = game::render::Mesh::cubePrimative;
	meshRenderer1.material = game::resources::material(game::resources::materialIndex("ocean"));
	cube.transform.position = { -5,0,0 };
	cube.AddComponent(meshRenderer1);
	scene.AddObject(cube);

	game::core::GameObject textObj{};
	textObj.AddComponent(textTest);
	textObj.transform.position = { 5,0,0 };
	scene.AddObject(textObj);

	game::core::GameObject sun{};
	sun.transform.Rotate(-120 * AngleToRad, 0, 0);
	auto sunlight = game::component::SunLight{ {0.05f, 0.05f, 0.05f,0}, {0.95f,0.95f,0.95f,0},{0,0,0,0} };
	sunlight.isShadowLight = false;
	sun.AddComponent(sunlight);
	sun.AddComponent(LightingTest{});
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
	glEnable(GL_DEPTH_TEST);
	glFogi(GL_FOG_MODE, GL_LINEAR);
	glFogf(GL_FOG_START, 0.5);
	glFogf(GL_FOG_END, 1.);
	glFogfv(GL_FOG_COLOR, (float*)game::math::Vec4{0,0,0,0});
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	manager.Initialize();
}

void win::event::Update(double time) {
	manager.Update(time);
}

void win::event::SyncUpdate(double time) {
	manager.SyncUpdate();
}

void win::event::Resize(double time, int width, int height) {
	manager.Resize(width, height);
}

void win::event::Render(double time) {
	manager.Render();
}

void win::input::KeyDown(int keyCode, bool isRepeat) {//https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
	manager.KeyDown(keyCode);
}

void win::input::KeyUp(int keyCode) {
	manager.KeyUp(keyCode);
}