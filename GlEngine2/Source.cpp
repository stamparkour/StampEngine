#include <Windows.h>
#include <fstream>
#include "gl.h"
#include "wincore.h"
#include "gamecore.h"
#include "glrender.h"

//mouse pos https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-setcursorpos?redirectedfrom=MSDN
//hide mouse https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-showcursor
//change cursor https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-setcursor
#define AngleToRad 0.0174532925199f



struct TestComponent final : game_core::Component {
	Component_Requirements(TestComponent)
public:
	void Update(game_core::GameObject& gameObject) override {
		gameObject.transform.Rotate(game_core::TimeManager::DeltaTime() * 0.7f, game_core::TimeManager::DeltaTime() *2, 0);
	}
};

struct TestComponent2 final : game_core::Component {
	Component_Requirements(TestComponent)
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
	shadow.transform.position = { 0,-2,4 };
	shadow.transform.scale = { 2,0.5f,2 };
	scene.AddObject(shadow);

	game_core::GameObject shadow2{};
	shadow2.AddComponent(TestComponent2{});
	shadow2.AddComponent(shadowRenderer);
	shadow2.transform.position = { 0,-2,4 };
	shadow2.transform.scale = { 0.1,3,3 };
	scene.AddObject(shadow2);

	game_core::GameObject cube2{};
	cube2.AddComponent(meshRenderer);
	cube2.transform.position = { 0,-1,4.5 };
	scene.AddObject(cube2);

	game_core::GameObject sun{};
	sun.transform.Rotate(-120 * AngleToRad, 0, 0);
	sun.AddComponent(game_component::SunLight{ {0.05f, 0.05f, 0.05f,0}, {0.95f,0.95f,0.95f,0},{0,0,0,0} });
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