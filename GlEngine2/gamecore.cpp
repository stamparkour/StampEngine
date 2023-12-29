#include "gamecore.h"

game_core::GameManager* game_core::GameManager::current = NULL;

void game_core::GameManager::Initialize() {
	game_core::GameManager::current = this;
	for (int i = 0; i < scene->gameobjects.size(); i++) {
		scene->gameobjects[i]->Awake();
	}
}
game_core::GameManager* game_core::GameManager::Current() noexcept {
	return current;
}
void game_core::GameManager::Render() {
	for (int i = 0; i < scene->gameobjects.size(); i++) {
		scene->gameobjects[i]->OnRender();
	}
}
void game_core::GameManager::Resize(int x, int y) {
	screenX = x;
	screenY = y;
	resized = true;
}
void game_core::GameManager::Update(double time) {
	this->time.NextTimestep(time);
	for (int i = 0; i < scene->gameobjects.size(); i++) {
		scene->gameobjects[i]->Update();
	}
	if (resized) {
		for (int i = 0; i < scene->gameobjects.size(); i++) {
			scene->gameobjects[i]->OnResize();
		}
	}
}
void game_core::GameManager::SyncUpdate() {
	for (int i = 0; i < scene->gameobjects.size(); i++) {
		if (scene->gameobjects[i]->state == GameObjectState::Destroying) {
			for (int j = 0; j < scene->gameobjects[i]->components.size(); j++) {
				scene->gameobjects[i]->components[j]->OnDestroy(*scene->gameobjects[i]);
			}
			delete scene->gameobjects[i];
			scene->gameobjects.erase(scene->gameobjects.begin() + i);
			i--;
		}
	}
	for (int i = 0; i < scene->gameobjects.size(); i++) {
		for (int j = 0; j < scene->gameobjects[i]->components.size(); j++) {
			if (scene->gameobjects[i]->components[j]->state == ComponentState::Destroying) {
				scene->gameobjects[i]->components[j]->OnDestroy(*scene->gameobjects[i]);
				delete scene->gameobjects[i]->components[j];
				scene->gameobjects[i]->components.erase(scene->gameobjects[i]->components.begin() + j);
				j--;
			}
		}
	}
}
void game_core::TimeManager::NextTimestep(double time) {
	deltaTime = time - this->time;
	this->time = time;
}
void game_core::TimeManager::NextFixedTimestep(double time) {
	fixedDeltaTime = time - this->fixedTime;
	this->fixedTime = time;
}
double game_core::TimeManager::Time() {
	return game_core::GameManager::Current()->time.time;
}
double game_core::TimeManager::DeltaTime() { 
	return game_core::GameManager::Current()->time.deltaTime;
}
double game_core::TimeManager::FixedTime() {
	return game_core::GameManager::Current()->time.fixedTime;
}
double game_core::TimeManager::FixedDeltaTime() { 
	return game_core::GameManager::Current()->time.fixedDeltaTime;
}
void game_core::Scene::AddObject(const game_core::GameObject& object) {
	game_core::GameObject* o = new game_core::GameObject(object);
	gameobjects.push_back(o);
}
void game_core::Scene::AddObject(game_core::GameObject&& object) {
	game_core::GameObject* o = new game_core::GameObject(object);
	gameobjects.push_back(o);
}
game_core::GameObject::GameObject() {
	components = {};
	transform = {};
	state = game_core::GameObjectState::Created;
	name = "";
	groupMask = 1;
}
game_core::GameObject::GameObject(const game_core::GameObject& v) {
	components = {v.components.size(), 0};
	transform = v.transform;
	for (int i = 0; i < v.components.size(); i++) {
		components[i] = (Component*)malloc(v.components[i]->Size());
		memcpy(components[i], v.components[i], v.components[i]->Size());
	}
	state = v.state;
	name = v.name;
	groupMask = v.groupMask;
}
game_core::GameObject::GameObject(GameObject&& v) noexcept {
	using std::swap;
	components = {};
	transform = {};
	state = game_core::GameObjectState::Created;
	name = "";
	groupMask = 1;
	swap(*this, v);
}
game_core::GameObject& game_core::GameObject::operator=(const GameObject& v) {
	components = { v.components.size(), 0 };
	transform = v.transform;
	for (int i = 0; i < v.components.size(); i++) {
		components[i] = (Component*)malloc(v.components[i]->Size());
		memcpy(components[i], v.components[i], v.components[i]->Size());
	}
	state = v.state;
	name = v.name;
	groupMask = v.groupMask;
	return *this;
}
game_core::GameObject& game_core::GameObject::operator=(GameObject&& v) noexcept {
	using std::swap;
	swap(*this, v);
	return *this;
}
inline void game_core::swap(game_core::GameObject& a, game_core::GameObject& b) {
	using std::swap;
	swap(a.components, b.components);
	swap(a.transform, b.transform);
	swap(a.state, b.state);
	swap(a.name, b.name);
	swap(a.groupMask, b.groupMask);
}
game_core::GameObject::~GameObject() {
	for (int i = 0; i < components.size(); i++) {
		delete components[i];
		components[i] = 0;
	}
	state = GameObjectState::Destroying;
}
void game_core::GameObject::Awake() {
	for (int i = 0; i < components.size(); i++) {
		components[i]->Awake(*this);
	}
}
void game_core::GameObject::Update() {
	if (state == GameObjectState::Created) {
		state = GameObjectState::Enabling;
		for (int i = 0; i < components.size(); i++) {
			components[i]->Start(*this);
		}
	}
	if (state == GameObjectState::Enabling) {
		state = GameObjectState::Enabled;
		for (int i = 0; i < components.size(); i++) {
			components[i]->OnEnabled(*this);
		}
	}
	if (state == GameObjectState::Enabled) {
		for (int i = 0; i < components.size(); i++) {
			components[i]->Update(*this);
		}
	}
	if (state == GameObjectState::Disabling) {
		state = GameObjectState::Disabled;
		for (int i = 0; i < components.size(); i++) {
			components[i]->OnDisabled(*this);
		}
	}
}
void game_core::GameObject::FixedUpdate() {
	if (state != GameObjectState::Enabled) return;
	for (int i = 0; i < components.size(); i++) {
		components[i]->FixedUpdate(*this);
	}
}
void game_core::GameObject::OnRender() {
	if (state != GameObjectState::Enabled) return;
	for (int i = 0; i < components.size(); i++) {
		components[i]->OnRender(*this);
	}
}
void game_core::GameObject::OnResize() {
	if (state != GameObjectState::Enabled) return;
	for (int i = 0; i < components.size(); i++) {
		components[i]->OnResize(*this);
	}
}
void game_core::GameObject::Destroy() {
	state = GameObjectState::Destroying;
}
void game_core::GameObject::Enable() {
	if (state == game_core::GameObjectState::Enabled) return;
	state = game_core::GameObjectState::Enabling;
}
void game_core::GameObject::Disable() {
	if (state == game_core::GameObjectState::Disabled) return;
	state = game_core::GameObjectState::Disabling;
}