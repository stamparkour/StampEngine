#include <Windows.h>
#include <fstream>
#include "gl.h"
#include "wincore.h"
#include "gamecore.h"
#include "gamerender.h"
#include "audio.h"
#include "gameresources.h"
#include <iostream>
#define RandRange(min,max) ((float)rand()/RAND_MAX*((max)-(min))+(min))
const WIN_CHAR* WIN_NAME = TEXT("my window");

//mouse pos https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-setcursorpos?redirectedfrom=MSDN
//hide mouse https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-showcursor
//change cursor https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-setcursor

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

		ry += -win::input::GetCursorDeltaY() / 600.0f;
		rx += win::input::GetCursorDeltaX() / 600.0f;

		selfObject()->transform.rotation = game::math::Quat::RotationZYX(-ry, rx, 0);
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

class TextTest final : public game::core::Component {
	Component_Requirements(TextTest)
private:
public:
	void Update() override {
		game::component::RectTransform* rect = selfObject()->GetComponent<game::component::RectTransform>();
		if(rect->position.y < 400) rect->position.y += 1;
	}
};




game::core::GameManager manager{};
game::core::Scene scene{};
game::audio::AudioPlayback playback;
void win::event::Start(double time) {
	manager.Initialize();
	game::resources::Initizialize();
	game::resources::setLoc("en");

	win::input::CursorVisibility(false);
	win::input::CursorConstraint(win::input::CursorConstraintState::Frozen);
	//playback = game::resources::audio(game::resources::audioIndex("mySong")).get()->play();
	//scene.AddObject(game::component::AudioSource::PlayClip());

	auto map = game::resources::font(game::resources::fontIndex("ariel_24"));
	game::component::TextRendererUI textTest = {};
	textTest.map = map;
	textTest.scale = 10;
	textTest.vertGap = 0;
	textTest.horizGap = 2;
	textTest.alignment = game::render::RectAlignment::BottomRight;
	textTest.setText(game::resources::loc("test_msg"));

	std::shared_ptr<game::render::Mesh> mesh = game::resources::mesh(game::resources::meshIndex("sphere"));
	std::shared_ptr<game::render::Mesh> mesh2 = game::resources::mesh(game::resources::meshIndex("testmesh"));

	game::core::GameObject cam{};
	cam.AddComponent(game::component::Camera{});
	cam.AddComponent(CameraController{});
	cam.transform.position = { 0,0,-5};
	scene.AddObject(cam);

	game::core::GameObject monke{};
	game::component::MeshRenderer meshRenderer = {};
	meshRenderer.mesh = mesh2;
	meshRenderer.material = game::resources::material(game::resources::materialIndex("sky"));
	monke.AddComponent(meshRenderer);
	scene.AddObject(monke);

	game::core::GameObject textObj{};
	textObj.AddComponent(textTest);
	textObj.AddComponent(TextTest{});
	textObj.AddComponent(game::component::RectTransform{ game::render::RectAlignment::Top,{0.5,5},5, {1,1} });
	textObj.transform.position = { 0,0,0 };
	scene.AddObject(textObj);

	game::core::GameObject sun{};
	sun.transform.Rotate(-120 * AngleToRad, 0, 0);
	auto sunlight = game::component::SunLight{ {0.05f, 0.05f, 0.05f,0}, {0.95f,0.95f,0.95f,0},{0,0,0,0} };
	sunlight.isShadowLight = false;
	sun.AddComponent(sunlight);
	sun.AddComponent(LightingTest{});
	scene.AddObject(sun);

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


	manager.scene = new game::core::Scene{ scene };
}

void win::event::Update(double time) {
	manager.Update(time);
	if (game::core::ControlsManager::isKeyPressed('K')) {
		win::event::vSync(!win::event::vSync());
		//win::event::SetWindowState(win::event::WindowStyle::Borderless,500,400);
	}
}

void win::event::SyncUpdate(double time) {
	if (game::core::ControlsManager::isKeyPressed(VK_F1)) {
		std::cout << "reset" << std::endl;
		delete manager.scene;
		manager.scene = new game::core::Scene{ scene };
		game::resources::Initizialize();
	}
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