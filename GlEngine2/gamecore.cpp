#include "gamecore.h"
#include <filesystem>
#include <fstream>
#include <memory>
game::core::GameManager* game::core::GameManager::current = NULL;

std::shared_ptr<char> game::core::readFile(const char* path, size_t* out_Size, bool isBinary = false) {
	std::fstream stream = std::fstream(path, (isBinary ? std::ios::binary : 0) | std::ios::in);
	if (!stream) return nullptr;
	stream.seekg(0, stream.end);
	size_t length = stream.tellg();
	stream.seekg(0, stream.beg);
	if (out_Size) *out_Size = length;
	char* c = new char[length + 1];
	stream.read(c, length);
	c[length] = 0;
	return std::shared_ptr<char>{c};
}
void game::core::GameManager::Initialize() {
	if (audio.Initialize())
		throw 1;

	game::core::GameManager::current = this;
}
game::core::GameManager* game::core::GameManager::Current() noexcept {
	return current;
}
void game::core::GameManager::Render() {
	for(int j = 0; j < 12; j++)
		for (int i = 0; i < scene->gameObjects.size(); i++) 
			scene->gameObjects[i]->OnRender(j);
}
void game::core::GameManager::Resize(int x, int y) {
	screenX = x;
	screenY = y;
	resized = true;
}
void game::core::GameManager::KeyDown(char virtualKey) {
	controls.KeyDown(virtualKey);
}
void game::core::GameManager::KeyUp(char virtualKey) {
	controls.KeyUp(virtualKey);
}
void game::core::GameManager::Update(double time) {
	this->time.NextTimestep(time);
	for (int i = 0; i < scene->gameObjects.size(); i++) {
		scene->gameObjects[i]->Awake();
	}
	for (int i = 0; i < scene->gameObjects.size(); i++) {
		scene->gameObjects[i]->Update();
	}
	if (resized) {
		for (int i = 0; i < scene->gameObjects.size(); i++) {
			scene->gameObjects[i]->OnResize();
		}
	}
}
void game::core::GameManager::SyncUpdate() {
	for (int i = 0; i < scene->gameObjects.size(); i++) {
		scene->gameObjects[i]->SyncUpdate();
	}
	for (int i = 0; i < scene->gameObjects.size(); i++) {
		if (scene->gameObjects[i]->state == GameObjectState::Destroying) {
			for (int j = 0; j < scene->gameObjects[i]->components.size(); j++) {
				scene->gameObjects[i]->components[j]->OnDestroy();
			}
			delete scene->gameObjects[i];
			scene->gameObjects.erase(scene->gameObjects.begin() + i);
			i--;
		}
	}
	for (int i = 0; i < scene->gameObjects.size(); i++) {
		for (int j = 0; j < scene->gameObjects[i]->components.size(); j++) {
			if (scene->gameObjects[i]->components[j]->state == ComponentState::Destroying) {
				scene->gameObjects[i]->components[j]->OnDestroy();
				delete scene->gameObjects[i]->components[j];
				scene->gameObjects[i]->components.erase(scene->gameObjects[i]->components.begin() + j);
				j--;
			}
		}
	}
	controls.Update();
}
void game::core::TimeManager::NextTimestep(double time) {
	deltaTime = time - this->time;
	this->time = time;
}
void game::core::TimeManager::NextFixedTimestep(double time) {
	fixedDeltaTime = time - this->fixedTime;
	this->fixedTime = time;
}
double game::core::TimeManager::Time() {
	return game::core::GameManager::Current()->time.time;
}
double game::core::TimeManager::DeltaTime() { 
	return game::core::GameManager::Current()->time.deltaTime;
}
double game::core::TimeManager::FixedTime() {
	return game::core::GameManager::Current()->time.fixedTime;
}
double game::core::TimeManager::FixedDeltaTime() { 
	return game::core::GameManager::Current()->time.fixedDeltaTime;
}
game::core::Scene::Scene(Scene& other) {
	for (int i = 0; i < other.gameObjects.size(); i++) {
		AddObject(*other.gameObjects[i]);
	}
}
game::core::Scene& game::core::Scene::operator=(game::core::Scene& other) {
	for (int i = 0; i < other.gameObjects.size(); i++) {
		GameObject* v = gameObjects[i];
		gameObjects[i] = 0;
		delete v;
	}
	gameObjects = {};
	for (int i = 0; i < other.gameObjects.size(); i++) {
		AddObject(*other.gameObjects[i]);
	}
	return *this;
}
game::core::GameObject& game::core::Scene::AddObject(const game::core::GameObject& object, std::string name) {
	game::core::GameObject* o = new game::core::GameObject(object);
	gameObjects.push_back(o);
	for (int i = 0; i < o->children.size(); i++) {
		gameObjects.push_back(o->children[i]);
	}
	if (name.length() != 0) o->name = name;
	return *o;
}
void game::core::Scene::AddObject(game::core::GameObject&& object, std::string name) {
	game::core::GameObject* o = new game::core::GameObject(object);
	for (int i = 0; i < o->children.size(); i++) {
		gameObjects.push_back(o->children[i]);
	}
	if (name.length() != 0) o->name = name;
	gameObjects.push_back(o);
}
game::core::GameObject* game::core::Scene::getGameObjectByName(std::string name) {
	int j = -1;
	for (int i = 0; i < gameObjects.size(); i++) {
		if (!gameObjects[i]->name.compare(name)) {
			if (!gameObjects[i]->parent) return gameObjects[i];
			else if(j != -1) j = i;
		}
	}
	if (j != -1) return gameObjects[j];
	return NULL;
}
game::core::Scene::~Scene()
{
	for (int i = 0; i < gameObjects.size(); i++) {
		GameObject* v = gameObjects[i];
		gameObjects[i] = 0;
		delete v;
	}
	gameObjects.clear();
}
game::core::GameObject::GameObject() {
	components = {};
	transform = {};
	state = game::core::GameObjectState::Created;
	name = "";
	layerMask = 1;
	transformMatrix = {};
	parent = NULL;
}
game::core::GameObject::GameObject(const game::core::GameObject& v) {
	components = {v.components.size(), 0};
	transform = v.transform;
	transformMatrix = v.transformMatrix;
	for (int i = 0; i < v.components.size(); i++) {
		components[i] = (Component*)malloc(v.components[i]->Size());
		memset(components[i], 0, v.components[i]->Size());
		memcpy(components[i], v.components[i], sizeof(Component));
		components[i]->AssignSelf(*v.components[i]);
		components[i]->gameObject = this;
	}
	for (int i = 0; i < v.children.size(); i++) {
		children.push_back(new GameObject(*children[i]));
	}
	state = v.state;
	name = v.name;
	layerMask = v.layerMask;
	parent = v.parent;
}
game::core::GameObject::GameObject(std::string name) {
	components = {};
	transform = {};
	transformMatrix = {};
	state = game::core::GameObjectState::Created;
	this->name = name;
	layerMask = 1;
	parent = NULL;
}
game::core::GameObject::GameObject(std::string name, int groupMask) {
	components = {};
	transform = {};
	transformMatrix = {};
	state = game::core::GameObjectState::Created;
	this->name = name;
	this->layerMask = groupMask;
	parent = NULL;
}
game::core::GameObject::GameObject(GameObject&& v) noexcept {
	components = {};
	children = {};
	transform = {};
	transformMatrix = {};
	state = game::core::GameObjectState::Created;
	name = "";
	layerMask = 1;
	parent = NULL;
	using std::swap;
	swap(*this, v);
}
game::core::GameObject& game::core::GameObject::operator=(const GameObject& v) {
	*this = GameObject(v);
	return *this;
}
game::core::GameObject& game::core::GameObject::operator=(GameObject&& v) noexcept {
	using std::swap;
	swap(*this, v);
	return *this;
}
inline void game::core::swap(game::core::GameObject& a, game::core::GameObject& b) {
	using std::swap;
	swap(a.components, b.components);
	for (int i = 0; i < a.components.size(); i++) {
		a.components[i]->gameObject = &a;
	}
	for (int i = 0; i < b.components.size(); i++) {
		b.components[i]->gameObject = &b;
	}
	swap(a.transform, b.transform);
	swap(a.state, b.state);
	swap(a.name, b.name);
	swap(a.layerMask, b.layerMask);
	swap(a.parent, b.parent);
	swap(a.transformMatrix, b.transformMatrix);
}
game::core::GameObject::~GameObject() {
	for (int i = 0; i < components.size(); i++) {
		delete components[i];
		components[i] = 0;
	}
	state = GameObjectState::Destroying;
}
bool game::core::GameObject::exsists() {
	if (this == 0) return false;
	for (int i = 0; i < GameManager::Current()->scene->gameObjects.size(); i++) {
		if (GameManager::Current()->scene->gameObjects[i] == this) return true;
	}
	return false;
}
game::math::Mat4 game::core::GameObject::getTransform() {
	if (parent == NULL) return transform.ToMatrix();
	return transform.ToMatrix(); *parent->getTransform();
}
game::math::Mat4 game::core::GameObject::getPrevTransform() const {
	return transformMatrix;
}
void game::core::GameObject::Awake() {
	if (state == GameObjectState::Created) {
		state = GameObjectState::Initialized;
		for (int i = 0; i < components.size(); i++) {
			components[i]->Awake();
		}
	}
}
void game::core::GameObject::Update() {
	if (state == GameObjectState::Created) return;
	if (state == GameObjectState::Initializing) {
		state = GameObjectState::Initialized;
		for (int i = 0; i < components.size(); i++) {
			components[i]->Start();
		}
	}
	if (enableState == GameObjectEnableState::Enabling) {
		enableState = GameObjectEnableState::Enabled;
		for (int i = 0; i < components.size(); i++) {
			components[i]->OnEnabled();
		}
	}
	if (enableState == GameObjectEnableState::Enabled) {
		for (int i = 0; i < components.size(); i++) {
			components[i]->Update();
		}
	}
	if (enableState == GameObjectEnableState::Disabling) {
		enableState = GameObjectEnableState::Disabled;
		for (int i = 0; i < components.size(); i++) {
			components[i]->OnDisabled();
		}
	}
}
void game::core::GameObject::FixedUpdate() {
	if (enableState != GameObjectEnableState::Enabled) return;
	for (int i = 0; i < components.size(); i++) {
		components[i]->FixedUpdate();
	}
}
void game::core::GameObject::OnRender(int phase) {
	if (enableState != GameObjectEnableState::Enabled) return;
	for (int i = 0; i < components.size(); i++) {
		components[i]->OnRender(phase);
	}
}
void game::core::GameObject::OnResize() {
	if (enableState != GameObjectEnableState::Enabled) return;
	for (int i = 0; i < components.size(); i++) {
		components[i]->OnResize();
	}
}
void game::core::GameObject::Destroy() {
	state = GameObjectState::Destroying;
	for (int i = 0; i < children.size(); i++) {
		children[i]->state = GameObjectState::Destroying;
	}
}
void game::core::GameObject::Enable() {
	if (enableState == GameObjectEnableState::Enabled) return;
	enableState = game::core::GameObjectEnableState::Enabling;
}
void game::core::GameObject::Disable() {
	if (enableState == GameObjectEnableState::Enabled) return;
	enableState = game::core::GameObjectEnableState::Disabling;
}
void game::core::GameObject::AddChild(GameObject* obj) {
	if (!obj) return;
	for (auto& c : children) {
		if (c == obj) return;
	}
	if (obj->parent)obj->parent->RemoveChild(obj);
	obj->parent = this;
	children.push_back(obj);
}
bool game::core::GameObject::RemoveChild(GameObject* obj) {
	if (!obj || !obj->parent) return false;
	for (int i = 0; i < children.size(); i++) {
		if (children[i] == obj) {
			children.erase(children.begin()+i);
			obj->parent = NULL;
			return true;
		}
	}
	return false;
}
game::core::GameObject* game::core::GameObject::getChildByName(std::string name) {
	for (int i = 0; i < children.size(); i++) {
		if (children[i]->name == name) {
			return children[i];
		}
	}
	return NULL;
}
void game::core::ControlsManager::KeyDown(char virtualKey) {
	int index = virtualKey >> 3;// divide by 8
	int shift = virtualKey % 8;
	char mask = 0b1 << shift;
	keyBits[index] |= mask;
}
void game::core::ControlsManager::KeyUp(char virtualKey) {
	int index = virtualKey >> 3;// divide by 8
	int shift = virtualKey % 8;
	char mask = ~(0b1 << shift);
	keyBits[index] &= mask;
}
void game::core::ControlsManager::Update() {
	for (int i = 0; i < sizeof(keyBits); i++) {
		repeatKeyBits[i] = keyBits[i];
	}
}
bool game::core::ControlsManager::isKeyPressed(char virtualKey) {
	int index = virtualKey >> 3;// divide by 8
	int shift = virtualKey % 8;
	char mask = 0b1 << shift;
	return (GameManager::Current()->controls.keyBits[index] & mask) && !(GameManager::Current()->controls.repeatKeyBits[index] & mask);
}
bool game::core::ControlsManager::isKeyDown(char virtualKey) {
	int index = virtualKey >> 3;// divide by 8
	int shift = virtualKey % 8;
	char mask = 0b1 << shift;
	return GameManager::Current()->controls.keyBits[index] & mask;
}
bool game::core::ControlsManager::isKeyUp(char virtualKey) {
	return !isKeyDown(virtualKey);
}
void game::core::GameObject::SyncUpdate() {
	if (enableState != GameObjectEnableState::Enabled) {
		for (int i = 0; i < components.size(); i++) {
			components[i]->SyncUpdate();
		}
	}
	this->transformMatrix = getTransform();
}


game::core::GameObject* game::core::Component::selfObject() const {
	return this->gameObject;
}
