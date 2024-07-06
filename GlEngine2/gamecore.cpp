#include "gamecore.h"
#include "gamerender.h"
#include "gameui.h"
#include "wincore.h"
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
void game::core::GameManager::BlankScreen(game::render::Texture* texture, float scale, game::math::Vec3 color) {
	glClearColor(color.x, color.y, color.z, 1);
	glClear(GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	glDisable(GL_LIGHTING);
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(game::math::Mat4::Orthographic(game::core::GameManager::ScreenX() / 2,
		(float)game::core::GameManager::ScreenX() / game::core::GameManager::ScreenY(), 0, 100));
	if (texture) {
		std::shared_ptr<game::render::Mesh> mesh = game::render::Mesh::plainPrimative;
		game::component::RectTransform trans{};
		trans.alignment = game::render::RectAlignment::Center;
		trans.scale = game::math::Vec2{ texture->Width() / 2.0f, texture->Height() / 2.0f } *scale;
		game::render::Material mat{};
		mat.diffuseColor = { 1,1,1,1 };
		mat.texture = std::shared_ptr<game::render::TextureBase>{ texture,  [](auto* v) {} };
		mat.useTexture = true;
		mat.Bind();
		mesh.get()->Render(trans.getMatrix());
	}

	HDC hdc = wglGetCurrentDC();
	if (win::state::vSync()) {
		glFinish();
		SwapBuffers(hdc);
	}
	else {
		glFlush();
	}

	win::state::ProcessWinEvents();
	glClearColor(this->clearColor.x, this->clearColor.y, this->clearColor.z, 0);
}
void game::core::GameManager::ClearColor(game::math::Vec3 color) {
	clearColor = color;
	glClearColor(color.x, color.y, color.z, 0);
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
void game::core::GameManager::FixedUpdate(double time)
{
	this->time.NextFixedTimestep(time);
	for (int i = 0; i < scene->gameObjects.size(); i++) {
		scene->gameObjects[i]->FixedUpdate();
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
	if(this->time != -1) deltaTime = time - this->time;
	this->time = time;
}
void game::core::TimeManager::NextFixedTimestep(double time) {
	if (this->fixedTime != -1) fixedDeltaTime = time - this->fixedTime;
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
		if(other.gameObjects[i]->parent == NULL) AddObject(*other.gameObjects[i]);
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
void game::core::__AddObject_children(game::core::Scene& scene, game::core::GameObject& obj) {
	scene.gameObjects.push_back(&obj);
	for (int i = 0; i < obj.children.size(); i++) {
		__AddObject_children(scene, *obj.children[i]);
	}
}
game::core::GameObject& game::core::Scene::AddObject(const game::core::GameObject& object, std::string name) {
	game::core::GameObject* o = new game::core::GameObject(object);
	__AddObject_children(*this, *o);
	if (name.length() != 0) o->name = name;
	return *o;
}
game::core::GameObject& game::core::Scene::AddObject(game::core::GameObject&& object, std::string name) {
	game::core::GameObject* o = new game::core::GameObject(object);
	__AddObject_children(*this, *o);
	if (name.length() != 0) o->name = name;
	return *o;
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
		AddChild(new GameObject(*v.children[i]));
	}
	state = v.state;
	name = v.name;
	layerMask = v.layerMask;
	parent = NULL;
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
	new(this)GameObject(v);
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
	return parent->getTransform() * transform.ToMatrix();
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
	if (enableState == GameObjectEnableState::Enabled) {
		for (int i = 0; i < components.size(); i++) {
			components[i]->SyncUpdate();
		}
	}
	this->transformMatrix = getTransform();
}


game::core::GameObject* game::core::Component::selfObject() const {
	return this->gameObject;
}
