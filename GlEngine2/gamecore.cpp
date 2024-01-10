#include "gamecore.h"

game_core::GameManager* game_core::GameManager::current = NULL;

void game_core::GameManager::Initialize() {
	game_core::GameManager::current = this;
	for (int i = 0; i < scene->gameObjects.size(); i++) {
		scene->gameObjects[i]->Awake();
	}
}
game_core::GameManager* game_core::GameManager::Current() noexcept {
	return current;
}
void game_core::GameManager::Render() {
	for (int i = 0; i < scene->gameObjects.size(); i++) {
		scene->gameObjects[i]->OnRender();
	}
}
void game_core::GameManager::Resize(int x, int y) {
	screenX = x;
	screenY = y;
	resized = true;
}
void game_core::GameManager::Update(double time) {
	this->time.NextTimestep(time);
	for (int i = 0; i < scene->gameObjects.size(); i++) {
		scene->gameObjects[i]->Update();
	}
	if (resized) {
		for (int i = 0; i < scene->gameObjects.size(); i++) {
			scene->gameObjects[i]->OnResize();
		}
	}
}
void game_core::GameManager::SyncUpdate() {
	for (int i = 0; i < scene->gameObjects.size(); i++) {
		if (scene->gameObjects[i]->state == GameObjectState::Destroying) {
			for (int j = 0; j < scene->gameObjects[i]->components.size(); j++) {
				scene->gameObjects[i]->components[j]->OnDestroy(*scene->gameObjects[i]);
			}
			delete scene->gameObjects[i];
			scene->gameObjects.erase(scene->gameObjects.begin() + i);
			i--;
		}
	}
	for (int i = 0; i < scene->gameObjects.size(); i++) {
		for (int j = 0; j < scene->gameObjects[i]->components.size(); j++) {
			if (scene->gameObjects[i]->components[j]->state == ComponentState::Destroying) {
				scene->gameObjects[i]->components[j]->OnDestroy(*scene->gameObjects[i]);
				delete scene->gameObjects[i]->components[j];
				scene->gameObjects[i]->components.erase(scene->gameObjects[i]->components.begin() + j);
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
	gameObjects.push_back(o);
}
void game_core::Scene::AddObject(game_core::GameObject&& object) {
	game_core::GameObject* o = new game_core::GameObject(object);
	gameObjects.push_back(o);
}
game_core::GameObject::GameObject() {
	components = {};
	transform = {};
	state = game_core::GameObjectState::Created;
	name = "";
	groupMask = 1;
	parent = NULL;
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
	parent = v.parent;
}
game_core::GameObject::GameObject(GameObject&& v) noexcept {
	using std::swap;
	components = {};
	transform = {};
	state = game_core::GameObjectState::Created;
	name = "";
	groupMask = 1;
	parent = NULL;
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
	parent = v.parent;
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
	swap(a.parent, b.parent);
}
game_core::GameObject::~GameObject() {
	for (int i = 0; i < components.size(); i++) {
		delete components[i];
		components[i] = 0;
	}
	state = GameObjectState::Destroying;
}
bool game_core::GameObject::exsists() {
	if (this == 0) return false;
	for (int i = 0; i < GameManager::Current()->scene->gameObjects.size(); i++) {
		if (GameManager::Current()->scene->gameObjects[i] == this) return true;
	}
	return false;
}
gl_math::Mat4 game_core::GameObject::getTransform(){
	if (parent == NULL) return transform.ToMatrix();
	return transform.ToMatrix(); * parent->getTransform();
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