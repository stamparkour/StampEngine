#include "gamecore.h"
#include <filesystem>
#include <fstream>
#include <xaudio2.h>
#include <memory>
game::core::GameManager* game::core::GameManager::current = NULL;

void game::core::GameManager::Initialize() {
	audio.Initialize();

	game::core::GameManager::current = this;
	for (int i = 0; i < scene->gameObjects.size(); i++) {
		scene->gameObjects[i]->Awake();
	}
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
game::core::GameObject& game::core::Scene::AddObject(const game::core::GameObject& object) {
	game::core::GameObject* o = new game::core::GameObject(object);
	gameObjects.push_back(o);
	return *o;
}
void game::core::Scene::AddObject(game::core::GameObject&& object) {
	game::core::GameObject* o = new game::core::GameObject(object);
	gameObjects.push_back(o);
}
game::core::GameObject* game::core::Scene::getGameObjectByName(std::string name) {
	for (int i = 0; i < gameObjects.size(); i++) {
		if (!gameObjects[i]->name.compare(name)) return gameObjects[i];
	}
	return NULL;
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
	using std::swap;
	components = {};
	transform = {};
	transformMatrix = {};
	state = game::core::GameObjectState::Created;
	name = "";
	layerMask = 1;
	parent = NULL;
	swap(*this, v);
}
game::core::GameObject& game::core::GameObject::operator=(const GameObject& v) {
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
	for (int i = 0; i < components.size(); i++) {
		components[i]->Awake();
	}
}
void game::core::GameObject::Update() {
	if (state == GameObjectState::Created) {
		state = GameObjectState::Enabling;
		for (int i = 0; i < components.size(); i++) {
			components[i]->Start();
		}
	}
	if (state == GameObjectState::Enabling) {
		state = GameObjectState::Enabled;
		for (int i = 0; i < components.size(); i++) {
			components[i]->OnEnabled();
		}
	}
	if (state == GameObjectState::Enabled) {
		for (int i = 0; i < components.size(); i++) {
			components[i]->Update();
		}
	}
	if (state == GameObjectState::Disabling) {
		state = GameObjectState::Disabled;
		for (int i = 0; i < components.size(); i++) {
			components[i]->OnDisabled();
		}
	}
}
void game::core::GameObject::FixedUpdate() {
	if (state != GameObjectState::Enabled) return;
	for (int i = 0; i < components.size(); i++) {
		components[i]->FixedUpdate();
	}
}
void game::core::GameObject::OnRender(int phase) {
	if (state != GameObjectState::Enabled) return;
	for (int i = 0; i < components.size(); i++) {
		components[i]->OnRender(phase);
	}
}
void game::core::GameObject::OnResize() {
	if (state != GameObjectState::Enabled) return;
	for (int i = 0; i < components.size(); i++) {
		components[i]->OnResize();
	}
}
void game::core::GameObject::Destroy() {
	state = GameObjectState::Destroying;
}
void game::core::GameObject::Enable() {
	if (state == game::core::GameObjectState::Enabled) return;
	state = game::core::GameObjectState::Enabling;
}
void game::core::GameObject::Disable() {
	if (state == game::core::GameObjectState::Disabled) return;
	state = game::core::GameObjectState::Disabling;
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
	char mask = 0xFF ^ (0b1 << shift);
	keyBits[index] &= mask;
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
void game::core::GameObject::SyncUpdate()
{
	this->transformMatrix = getTransform();
}
//https://learn.microsoft.com/en-us/windows/win32/xaudio2/how-to--play-a-sound-with-xaudio2
bool game::core::AudioManager::Initialize() {
	HRESULT hr;
	pXAudio2 = nullptr;
	if (FAILED(hr = XAudio2Create(&pXAudio2, 0, XAUDIO2_DEFAULT_PROCESSOR)))
		return true;
	IXAudio2MasteringVoice* pMasterVoice = nullptr;
	if (FAILED(hr = pXAudio2->CreateMasteringVoice(&pMasterVoice)))
		return true;

	return false;
}
template<size_t length>
bool getChunk(long fourcc, const char(&data)[length], size_t& index, size_t& size) {
	for (size_t i = 12; i < length;) {
		if (*(long*)(data + i) != fourcc) {
			i += 4;
			size = *(uint32_t*)(data + i);
			i += 4;
			index = ((i + 1) / 2) * 2;
			return true;
		}
		else {
			i += 4;
			i += *(uint32_t*)(data + i) + 4;
			i = ((i + 1) / 2) * 2;
		}
	}
	return false;
}

template<size_t length>
inline game::core::AudioClip::AudioClip(const char(&buffer)[length]) : hBufferEndEvent(CreateEvent(NULL, FALSE, FALSE, NULL)) {
	ptr = new char[length];
	memcpy_s(ptr.get(), length, buffer, length);
	//little endian
	if (*(long*)(ptr.get() + 0) != 'FFIR') return;
	long fileSize = *(long*)(ptr.get() + 4) + 8;
	if (*(long*)(ptr.get() + 8) != 'EVAW') return;
	size_t fmtIndex = 0;
	size_t fmtLength = 0;
	if(!getChunk<length>(' tmf', ptr.get(), fmtIndex, fmtLength)) return;
	size_t dataIndex = 0;
	size_t dataSize = 0;
	if (!getChunk<length>('atad', ptr.get(), dataIndex, dataSize)) return;
	memcpy_s(&fmt, sizeof(WAVEFORMATEX), (char*)ptr.get() + fmtIndex, fmtLength);
	data.pAudioData = ptr.get() + dataIndex;
	data.AudioBytes = dataSize;
	data.PlayBegin = 0;
	data.PlayLength = 0;
	data.Flags = XAUDIO2_END_OF_STREAM;
	data.pContext = this;

	auto pXAudio2 = GameManager::Current()->audio.pXAudio2;
	HRESULT hr;
	if (FAILED(hr = pXAudio2->CreateSourceVoice(&pSourceVoice.get(), (WAVEFORMATEX*)&fmt, 0, XAUDIO2_DEFAULT_FREQ_RATIO, this, NULL, NULL)))
		throw hr;
	if (FAILED(hr = pSourceVoice->SubmitSourceBuffer(&data)))
		throw hr;
}
std::shared_ptr<char> game::core::readFile(const char* path, size_t* out_Size, bool isBinary = false) {
	std::fstream stream = std::fstream(path, (isBinary ? std::ios::binary: 0) | std::ios::in);
	if (!stream) return nullptr;
	stream.seekg(0, stream.end);
	size_t length = stream.tellg();
	stream.seekg(0, stream.beg);
	if (out_Size) *out_Size = length;
	char* c = new char[length+1];
	stream.read(c, length);
	c[length] = 0;
	return std::shared_ptr<char>{c};
}
game::core::AudioClip::~AudioClip() {
	CloseHandle(hBufferEndEvent);
}
void game::core::AudioClip::OnStreamEnd() {
	SetEvent(hBufferEndEvent);
	playing = false;
}
bool game::core::AudioClip::isPlaying() const {
	return playing;
}
bool game::core::AudioClip::Play(float volume) {
	playing = true;
	HRESULT hr;
	if (FAILED(hr = pSourceVoice->Start(0)))
		return true;
	return false;
}

game::core::GameObject* game::core::Component::selfObject() const
{
	return this->gameObject;
}
