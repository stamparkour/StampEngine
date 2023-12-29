#include <Windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include "wincore.h"
#include "gamecore.h"
#include "glrender.h"

#define AngleToRad 0.0174532925199



struct TestComponent final : game_core::Component {
	Component_Requirements(TestComponent)
public:
	void Update(game_core::GameObject& gameObject) override {
		gameObject.transform.Rotate(game_core::TimeManager::DeltaTime() * 0.7, game_core::TimeManager::DeltaTime() *2, 0);
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
	meshRenderer.material = &game_render::Material::defaultMaterial;
	cube.AddComponent(meshRenderer);
	cube.AddComponent(TestComponent{});
	cube.transform.Rotate(0, 0, -10 * AngleToRad);
	cube.transform.position = { 0,-2,4 };
	scene.AddObject(cube);
	game_core::GameObject sun{};
	sun.transform.Rotate(-120 * AngleToRad, 0, 0);
	sun.AddComponent(game_component::SunLight{ {0.003f, 0.008f, 0.1f,0}, {1,1,0.9,0},{1,0,0,0} });
	scene.AddObject(sun);

	manager.scene = &scene;
	glClearColor(0.1f, 0.3f, 0.4f, 1.f);
	glClearDepth(1);
	glDepthFunc(GL_LESS);
	glDepthMask(GL_TRUE);
	glDepthRange(0, 1);
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

void win_input::KeyDown(int keyCode, bool isRepeat) {

}

void win_input::KeyUp(int keyCode) {

}