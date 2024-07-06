#include <Windows.h>
#include <fstream>
#include "gl.h"
#include "wincore.h"
#include "gamecore.h"
#include "gamerender.h"
#include "gameui.h"
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

class ChargedParticle : public game::core::Component {
	Component_Requirements(ChargedParticle)
		inline static std::vector<ChargedParticle*> particles;
public:
	float charge;
	game::math::Vec3 velocity;

	ChargedParticle(float charge = 0) {
		this->charge = charge;
	}
	void Awake() override {
		particles.push_back(this);
	}
	void OnDestroy() override {
		int index = -1;
		for (int i = 0; i < particles.size(); i++) {
			if (particles[i] == this) {
				index = i;
			}
		}
		if (index != -1) particles.erase(particles.begin() + index);
	}
	void Update() override {
		game::math::Vec3 force = {};
		for (int i = 0; i < particles.size(); i++) {
			if (particles[i] == this) continue;
			game::math::Vec3 elec = particles[i]->getElecticField(selfObject()->transform.position);
			game::math::Vec3 mag = particles[i]->ElectricToMagnetic(elec, selfObject()->transform.position);
			force += elec + game::math::Vec3::Cross(velocity, mag);
		}
		force *= charge;
		velocity += force * game::core::TimeManager::DeltaTime();
		selfObject()->transform.position += velocity * game::core::TimeManager::DeltaTime();

		for (int i = 0; i < particles.size(); i++) {
			if (particles[i] == this) continue;
			auto vec = particles[i]->selfObject()->transform.position - selfObject()->transform.position;
			float mag = vec.Magnitude();
			auto norm = vec / mag;
			if (mag > 0.1 && mag < 2) {
				float dist = (2 - mag) / 2;
				particles[i]->selfObject()->transform.position += vec * dist;
				selfObject()->transform.position -= vec * dist;
				auto ine = (velocity + particles[i]->velocity) / 2;
				auto velo = particles[i]->velocity - velocity;
				auto ela = norm * game::math::Vec3::Dot(norm, velo);
				float elastisity = 0.9;
				velocity = ine + (ela + velocity - ine) * elastisity;
				particles[i]->velocity = ine + (-ela + particles[i]->velocity - ine) * elastisity;
				particles[i]->charge = particles[i]->charge + game::core::TimeManager::DeltaTime() * ((particles[i]->charge + charge) / 2 - particles[i]->charge);
				charge = charge + game::core::TimeManager::DeltaTime() * ( (particles[i]->charge + charge) / 2 - charge);
			}
		}
	}

	game::math::Vec3 getElecticField(game::math::Vec3 pos) {
		float SpeedOfLight = 299792458;
		float vacuumPermittivity = 8.854187818814e-12;
		pos = selfObject()->transform.position - pos;
		float dist = pos.Magnitude();
		if (dist < 0.1) return {};
		float c = -charge / (4 * PI * vacuumPermittivity);
		float d3 = pow(dist, 3);
		float d5 = pow(dist, 5);
		float d7 = pow(dist, 7);
		auto A = pos / d3;
		auto B = (game::math::Vec3{ 1 / d3 - 3 * (float)pow(pos.x,2) / d5, 1 / d3 - 3 * (float)pow(pos.y,2) / d5, 1 / d3 - 3 * (float)pow(pos.z,2) / d5 }) * dist / SpeedOfLight;
		auto C = (game::math::Vec3{ 3 * pos.x * (5 * (float)pow(pos.x,2) / d7 - 3 / d5),3 * pos.y * (5 * (float)pow(pos.y,2) / d7 - 3 / d5),3 * pos.z * (5 * (float)pow(pos.z,2) / d7 - 3 / d5) }) * dist / SpeedOfLight;
		return (A + B + C) * c;
	}
	game::math::Vec3 ElectricToMagnetic(game::math::Vec3 elec, game::math::Vec3 pos) {
		pos = selfObject()->transform.position - pos;
		float SpeedOfLight = 299792458;
		return game::math::Vec3::Cross(-pos.Normal(), elec / SpeedOfLight);
	}
};

game::core::GameManager manager{};
game::core::Scene scene{};
game::audio::AudioPlayback playback;
void win::event::Start(double time) {
	manager.Initialize();
	manager.BlankScreen(game::render::Texture::BmpTexture(game::core::readFile("resources\\blanking.bmp", NULL, true).get()).get(), 2, game::math::Vec3(0.2f,0.23f,0.25f));
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

	game::core::GameObject monke{};
	game::component::MeshRenderer meshRenderer = {};
	meshRenderer.mesh = mesh2;
	meshRenderer.material = game::resources::material(game::resources::materialIndex("sky"));
	//monke.AddComponent(meshRenderer);
	//scene.AddObject(monke, "monke basic");
	monke.AddComponent(CameraController{});

	game::core::GameObject monke2{};
	monke2.transform.position = { 0,3,0 };
	monke2.AddComponent(meshRenderer);
	monke2.AddComponent(ChargedParticle{});
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			for (int z = 0; z < 5; z++) {
				auto* c = monke2.GetComponent<ChargedParticle>();
				c->charge = RandRange(-0.0001, 0.0001);
				monke2.transform.position = game::math::Vec3{ (float)x,(float)y,(float)z } * 10;
				scene.AddObject(monke2);
			}
		}
	}

	game::core::GameObject cam{"camera"};
	cam.AddComponent(game::component::Camera{});
	cam.transform.position = { 0,0,-10 };
	monke.AddChild(&cam);
	scene.AddObject(monke, "monke");

	game::core::GameObject textObj{};
	textObj.AddComponent(textTest);
	textObj.AddComponent(TextTest{});
	textObj.AddComponent(game::component::RectTransform{ game::render::RectAlignment::Top,{0.5,5},5, {1,1} });
	textObj.transform.position = { 0,0,0 };
	scene.AddObject(textObj, "textbox");

	game::core::GameObject sun{};
	sun.transform.Rotate(-120 * AngleToRad, 0, 0);
	auto sunlight = game::component::SunLight{ game::math::Vec4{ .11f, .16f, .18f, 1 }, game::math::Vec4{0.99f,0.98f,0.83f,0},{0,0,0,0} };
	sunlight.isShadowLight = false;
	sun.AddComponent(sunlight);
	sun.AddComponent(LightingTest{});
	scene.AddObject(sun, "sun");

	manager.ClearColor({ .53f, .81f, .92f });
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
}

void win::event::FixedUpdate(double time) {
	manager.FixedUpdate(time);
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