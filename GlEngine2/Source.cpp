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

struct DestroyComponent final : game_core::Component {
	Component_Requirements(DestroyComponent)
public:
	float t = 0;
	void Start(game_core::GameObject& gameObject) override {
		t = game_core::TimeManager::Time() + 5;
	}
	void Update(game_core::GameObject& gameObject) override {
		if (t < game_core::TimeManager::Time()) {
			gameObject.Destroy();
		}
	}
};

struct TestComponent final : game_core::Component {
	Component_Requirements(TestComponent)
public:
	float test = 0;
	void Update(game_core::GameObject& gameObject) override {
		gameObject.transform.Rotate(game_core::TimeManager::DeltaTime() * 0.7f, game_core::TimeManager::DeltaTime() *2, 0);
		float mag = 5;
		if (game_core::ControlsManager::isKeyDown('W'))
			gameObject.transform.position += gl_math::Vec3{ 0,0,1 } *game_core::TimeManager::DeltaTime() * mag;
		if (game_core::ControlsManager::isKeyDown('S'))
			gameObject.transform.position += gl_math::Vec3{ 0,0,-1 } *game_core::TimeManager::DeltaTime() * mag;
		if (game_core::ControlsManager::isKeyDown('D'))
			gameObject.transform.position += gl_math::Vec3{ 1,0,0 } *game_core::TimeManager::DeltaTime() * mag;
		if (game_core::ControlsManager::isKeyDown('A'))
			gameObject.transform.position += gl_math::Vec3{ -1,0,0 } *game_core::TimeManager::DeltaTime() * mag;
		if (game_core::ControlsManager::isKeyDown('R'))
			gameObject.transform.position += gl_math::Vec3{ 0,1,0 } *game_core::TimeManager::DeltaTime() * mag;
		if (game_core::ControlsManager::isKeyDown('F'))
			gameObject.transform.position += gl_math::Vec3{ 0,-1,0 } *game_core::TimeManager::DeltaTime() * mag;

		if (test < game_core::TimeManager::Time()) {
			game_core::GameObject obj{};
			game_component::MeshRenderer meshRenderer = {};
			meshRenderer.mesh = &game_render::Mesh::cubePrimative;
			meshRenderer.applyShadow = true;
			meshRenderer.material = game_render::Material::defaultMaterial;
			obj.AddComponent(meshRenderer);
			obj.transform.position = gameObject.transform.position;
			obj.transform.rotation = gameObject.transform.rotation;
			obj.transform.scale = { 0.2f,0.2f,0.2f };
			obj.AddComponent(DestroyComponent{});
			game_core::GameManager::Current()->scene->AddObject(obj);
			test = game_core::TimeManager::Time() + 0.1;
		}
	}
};

struct TestComponent2 final : game_core::Component {
	Component_Requirements(TestComponent2)
public:
	void Update(game_core::GameObject& gameObject) override {
		gameObject.transform.position.x = sinf(game_core::TimeManager::Time()) * 2;
	}
};

game_core::GameManager manager{};
game_core::Scene scene{};
void win_event::Start(double time) {

	game_core::GameObject cam{};
	cam.AddComponent(game_component::Camera{});
	scene.AddObject(cam);

	game_core::GameObject cube{};
	game_component::MeshRenderer meshRenderer = {};
	meshRenderer.mesh = &game_render::Mesh::cubePrimative;
	meshRenderer.applyShadow = true;
	meshRenderer.material = game_render::Material::defaultMaterial;
	meshRenderer.material.useTexture = true;
	meshRenderer.material.texture = game_render::Texture::BmpTexture(game_core::readFile("C:\\Users\\Stamp\\Downloads\\640-480-sample.bmp", NULL));
	cube.AddComponent(meshRenderer);
	cube.AddComponent(TestComponent{});
	cube.transform.Rotate(0, 0, -10 * AngleToRad);
	cube.transform.position = { 0,-2,4 };
	scene.AddObject(cube);

	game_core::GameObject shadow{};
	game_component::ShadowRenderer shadowRenderer = {};
	shadow.AddComponent(TestComponent2{});
	shadowRenderer.mesh = &game_render::Mesh::cubePrimative;
	shadow.AddComponent(shadowRenderer);
	shadow.transform.position = { 0,-2.1,4 };
	shadow.transform.scale = { 2,0.5f,2 };
	scene.AddObject(shadow);

	game_core::GameObject cube2{};
	cube2.AddComponent(meshRenderer);
	cube2.transform.position = { 0,-1,5 };
	scene.AddObject(cube2);

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