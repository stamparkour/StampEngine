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
	for(int j = 0; j < 12; j++)
		for (int i = 0; i < scene->gameObjects.size(); i++) 
			scene->gameObjects[i]->OnRender(j);
}
void game_core::GameManager::Resize(int x, int y) {
	screenX = x;
	screenY = y;
	resized = true;
}
void game_core::GameManager::KeyDown(char virtualKey) {
	controls.KeyDown(virtualKey);
}
void game_core::GameManager::KeyUp(char virtualKey) {
	controls.KeyUp(virtualKey);
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
		scene->gameObjects[i]->SyncUpdate();
	}
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
game_core::GameObject* game_core::Scene::getGameObjectByName(std::string name) {
	for (int i = 0; i < gameObjects.size(); i++) {
		if (!gameObjects[i]->name.compare(name)) return gameObjects[i];
	}
	return NULL;
}
game_core::GameObject::GameObject() {
	components = {};
	transform = {};
	state = game_core::GameObjectState::Created;
	name = "";
	layerMask = 1;
	transformMatrix = {};
	parent = NULL;
}
game_core::GameObject::GameObject(const game_core::GameObject& v) {
	components = {v.components.size(), 0};
	transform = v.transform;
	transformMatrix = v.transformMatrix;
	for (int i = 0; i < v.components.size(); i++) {
		components[i] = (Component*)malloc(v.components[i]->Size());
		memcpy(components[i], v.components[i], v.components[i]->Size());
	}
	state = v.state;
	name = v.name;
	layerMask = v.layerMask;
	parent = v.parent;
}
game_core::GameObject::GameObject(std::string name) {
	components = {};
	transform = {};
	transformMatrix = {};
	state = game_core::GameObjectState::Created;
	this->name = name;
	layerMask = 1;
	parent = NULL;
}
game_core::GameObject::GameObject(std::string name, int groupMask) {
	components = {};
	transform = {};
	transformMatrix = {};
	state = game_core::GameObjectState::Created;
	this->name = name;
	this->layerMask = groupMask;
	parent = NULL;
}
game_core::GameObject::GameObject(GameObject&& v) noexcept {
	using std::swap;
	components = {};
	transform = {};
	transformMatrix = {};
	state = game_core::GameObjectState::Created;
	name = "";
	layerMask = 1;
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
	layerMask = v.layerMask;
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
	swap(a.layerMask, b.layerMask);
	swap(a.parent, b.parent);
	swap(a.transformMatrix, b.transformMatrix);
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
gl_math::Mat4 game_core::GameObject::getTransform() {
	if (parent == NULL) return transform.ToMatrix();
	return transform.ToMatrix(); *parent->getTransform();
}
gl_math::Mat4 game_core::GameObject::getPrevTransform() const {
	return transformMatrix;
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
void game_core::GameObject::OnRender(int phase) {
	if (state != GameObjectState::Enabled) return;
	for (int i = 0; i < components.size(); i++) {
		components[i]->OnRender(*this, phase);
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
void game_core::ControlsManager::KeyDown(char virtualKey) {
	int index = virtualKey >> 3;// divide by 8
	int shift = virtualKey % 8;
	char mask = 0b1 << shift;
	keyBits[index] |= mask;
}
void game_core::ControlsManager::KeyUp(char virtualKey) {
	int index = virtualKey >> 3;// divide by 8
	int shift = virtualKey % 8;
	char mask = 0xFF ^ (0b1 << shift);
	keyBits[index] &= mask;
}
bool game_core::ControlsManager::isKeyDown(char virtualKey) {
	int index = virtualKey >> 3;// divide by 8
	int shift = virtualKey % 8;
	char mask = 0b1 << shift;
	return GameManager::Current()->controls.keyBits[index] & mask;
}
bool game_core::ControlsManager::isKeyUp(char virtualKey) {
	return !isKeyDown(virtualKey);
}
void game_core::GameObject::SyncUpdate()
{
	this->transformMatrix = getTransform();
}