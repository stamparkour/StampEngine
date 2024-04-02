#pragma once
#include <vector>
#include <string>
#include <xaudio2.h>
#include "glmath.h"
#include <memory>
#define LayerMask_Main 1
#define Component_Requirements(class_name) size_t Size() override { return sizeof(class_name);} void AssignSelf(const Component& other) override { *this = (class_name&)other; }

namespace game_core {
	std::shared_ptr<char> readFile(const char* path, size_t* out_Size, bool isBinary);

	struct Transform {
		gl_math::Vec3 position{};
		gl_math::Vec3 scale{ 1,1,1 };
		gl_math::Quat rotation = gl_math::Quat_Identity;

		void Rotate(float x, float y, float z);
		gl_math::Mat4 ToMatrix() const;
		gl_math::Mat4 ToMatrixInverse() const;
		gl_math::Vec3 forward() const;
		gl_math::Vec3 back() const;
		gl_math::Vec3 left() const;
		gl_math::Vec3 right() const;
		gl_math::Vec3 up() const;
		gl_math::Vec3 down() const;
	};

	enum struct GameObjectState {
		Created,
		Enabling,
		Enabled,
		Disabling,
		Disabled,
		Destroying,
	};
	enum struct ComponentState {
		Created,
		Active,
		Destroying,
	};

	struct Component;
	struct Scene;

	struct GameObject final {
		friend struct Component;
		friend struct Scene;
		friend struct GameManager;
	private:
		std::vector<Component*> components;
		GameObjectState state;
		gl_math::Mat4 transformMatrix;
	public:
		game_core::Transform transform;
		std::string name;
		int layerMask;
		GameObject* parent;

		GameObject();
		GameObject(std::string name);
		GameObject(std::string name, int layerMask);
		GameObject(const GameObject& v);
		GameObject(GameObject&& v) noexcept;
		GameObject& operator =(const GameObject& v);
		GameObject& operator =(GameObject&& v) noexcept;
		~GameObject();
		friend void swap(GameObject& a, GameObject& b);
		void Destroy();

		bool exsists();
		std::vector<GameObject*> getChildren();
		gl_math::Mat4 getTransform();
		gl_math::Mat4 getPrevTransform() const;
		template <typename T>
		void AddComponent(T& component);
		template <typename T>
		void AddComponent(T&& component);
		template <typename T>
		T* GetComponent();
		template <typename T >
		bool RemoveComponent();
		void Disable();
		void Enable();
	protected:
		void Awake();
		void Update();
		void SyncUpdate();
		void FixedUpdate();
		void OnRender(int phase);
		void OnResize();
	};
	
	struct Component {
		friend struct GameObject;
		friend struct GameManager;
		friend void game_core::swap(game_core::GameObject& a, game_core::GameObject& b);
		ComponentState state { ComponentState::Created};
		Component() {}
	private:
		GameObject* gameObject{};
	protected:
		virtual void Awake() {}
		virtual void OnDisabled() {}
		virtual void OnEnabled() {}
		virtual void Start() {}
		virtual void OnDestroy() {}
		virtual void Update() {}
		virtual void FixedUpdate() {}
		virtual void OnRender(int phase) {}
		virtual void OnResize() {}
		virtual size_t Size() = 0;
		virtual void AssignSelf(const Component& other) = 0;
		GameObject* selfObject() const;
	}; 
	
	struct Scene final {
		friend struct GameManager;
		friend struct GameObject;
	private:
		std::vector<GameObject*> gameObjects;
	public:
		GameObject& AddObject(const GameObject& object);
		void AddObject(GameObject&& object);

		GameObject* getGameObjectByName(std::string name);
	};

	struct TimeManager final {
		friend struct GameManager;
	private:
		double deltaTime;
		double time;
		double fixedDeltaTime;
		double fixedTime;

		void NextTimestep(double time);
		void NextFixedTimestep(double time);
	public:
		static double Time(); 
		static double DeltaTime(); 
		static double FixedTime(); 
		static double FixedDeltaTime(); 
	};

	struct ControlsManager final {
		friend struct GameManager;
	private:
		char keyBits[256 / 8];
		void KeyDown(char virtualKey);
		void KeyUp(char virtualKey);
	public:
		static bool isKeyDown(char virtualKey);
		static bool isKeyUp(char virtualKey);
	}; 

	struct AudioClip final : IXAudio2VoiceCallback {
	private:
		WAVEFORMATEX fmt{};
		XAUDIO2_BUFFER data{};
		std::shared_ptr<IXAudio2SourceVoice> pSourceVoice = nullptr;
		std::shared_ptr<char> ptr = nullptr;
		HANDLE hBufferEndEvent;
		bool playing = false;
	public:
		AudioClip() : hBufferEndEvent(CreateEvent(NULL, FALSE, FALSE, NULL)) {}
		template<size_t length>
		AudioClip(const char (&buffer)[length]);
		~AudioClip();
		bool Play(float volume);
		void OnStreamEnd();
		void OnVoiceProcessingPassEnd() { }
		void OnVoiceProcessingPassStart(UINT32 SamplesRequired) {    }
		void OnBufferEnd(void* pBufferContext) { }
		void OnBufferStart(void* pBufferContext) {    }
		void OnLoopEnd(void* pBufferContext) {    }
		void OnVoiceError(void* pBufferContext, HRESULT Error) { }
		bool isPlaying() const;
	};

	struct AudioManager final {
		friend struct GameManager;
		friend struct AudioClip;
	private:
		bool Initialize();
		IXAudio2* pXAudio2;
	public:
	};

	struct GameManager final {
	private:
		int screenX;
		int screenY;
		bool resized;
		static GameManager* current;
	public:
		TimeManager time;
		ControlsManager controls;
		AudioManager audio;
		Scene* scene = 0;

		inline int ScreenX() const noexcept { return screenX; }
		inline int ScreenY() const noexcept { return screenY;  }

		void Initialize();
		void Update(double time);
		void FixedUpdate(double time);
		void SyncUpdate();
		void Resize(int x, int y);
		void Render();
		void KeyDown(char virtualKey);
		void KeyUp(char virtualKey);

		static GameManager* Current() noexcept;
	};
}

template <typename T>
void game_core::GameObject::AddComponent(T& component) {
	game_core::Component* __dummy = static_cast<T*>(0);
	T* v = new T(component);
	v->gameObject = this;
	components.push_back(v);
}
template <typename T>
void game_core::GameObject::AddComponent(T&& component) {
	game_core::Component* __dummy = static_cast<T*>(0);
	T* v = new T(component);
	v->gameObject = this;
	components.push_back(v);
}
template <typename T>
T* game_core::GameObject::GetComponent() {
	game_core::Component* __dummy = static_cast<T*>(0);
	for (int i = 0; i < components.size(); i++) {
		if ((typeid (*components[i])) == typeid(T)) {
			return (T*)components[i];
		}
	}
	return NULL;
}
template <typename T>
bool game_core::GameObject::RemoveComponent() {
	game_core::Component* __dummy = static_cast<T*>(0);
	for (int i = 0; i < components.size(); i++) {
		if ((typeid (*components[i])) == typeid(T)) {
			components[i]->state = game_core::ComponentState::Destroying;
			return true;
		}
	}
	return false;
}