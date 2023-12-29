#pragma once
#include "gltransform.h"
#include <vector>
#include <string>

#define Component_Requirements(class_name) size_t Size() override { return sizeof(class_name);}

namespace game_core {
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
		GameObject* parent;
	public:
		game_core::Transform transform;
		std::string name;
		int groupMask;

		GameObject();
		GameObject(std::string name);
		GameObject(std::string name, int groupMask);
		GameObject(const GameObject& v);
		GameObject(GameObject&& v) noexcept;
		GameObject& operator =(const GameObject& v);
		GameObject& operator =(GameObject&& v) noexcept;
		~GameObject();
		friend void swap(GameObject& a, GameObject& b);
		void Destroy();

		gl_math::Mat4 getTransform();
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
		void FixedUpdate();
		void OnRender();
		void OnResize();
	};
	
	struct Component {
		friend struct GameObject;
		friend struct GameManager;
		ComponentState state { ComponentState::Created};
		Component() {}
	protected:
		virtual void Awake(GameObject& gameObject) {}
		virtual void OnDisabled(GameObject& gameObject) {}
		virtual void OnEnabled(GameObject& gameObject) {}
		virtual void Start(GameObject& gameObject) {}
		virtual void OnDestroy(GameObject& gameObject) {}
		virtual void Update(GameObject& gameObject) {}
		virtual void FixedUpdate(GameObject& gameObject) {}
		virtual void OnRender(GameObject& gameObject) {}
		virtual void OnResize(GameObject& gameObject) {}
		virtual size_t Size() = 0;
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
		static inline double Time() { return game_core::GameManager::Current()->time.time; }
		static inline double DeltaTime() { return game_core::GameManager::Current()->time.deltaTime; }
		static inline double FixedTime() { return game_core::GameManager::Current()->time.fixedTime; }
		static inline double FixedDeltaTime() { return game_core::GameManager::Current()->time.fixedDeltaTime; }
	};

	struct Scene final {
		friend struct GameManager;
	private:
		std::vector<GameObject*> gameobjects;
	public:
		void AddObject(const GameObject& object);
		void AddObject(GameObject&& object);
	};

	struct GameManager final {
	private:
		int screenX;
		int screenY;
		bool resized;
		static GameManager* current;
	public:
		TimeManager time;
		Scene* scene;

		inline int ScreenX() const noexcept { return screenX; }
		inline int ScreenY() const noexcept { return screenY;  }

		void Initialize();
		void Update(double time);
		void FixedUpdate(double time);
		void SyncUpdate();
		void Resize(int x, int y);
		void Render();

		static GameManager* Current() noexcept;
	};
}

template <typename T>
void game_core::GameObject::AddComponent(T& component) {
	game_core::Component* __dummy = static_cast<T*>(0);
	T* v = new T(component);
	components.push_back(v);
}
template <typename T>
void game_core::GameObject::AddComponent(T&& component) {
	game_core::Component* __dummy = static_cast<T*>(0);
	T* v = new T(component);
	components.push_back(v);
}
template <typename T>
T* game_core::GameObject::GetComponent() {
	game_core::Component* __dummy = static_cast<T*>(0);
	for (int i = 0; i < components.size(); i++) {
		if ((typeid (*components[i])) == T) {
			return components[i];
		}
	}
	return NULL;
}
template <typename T>
bool game_core::GameObject::RemoveComponent() {
	game_core::Component* __dummy = static_cast<T*>(0);
	for (int i = 0; i < components.size(); i++) {
		if ((typeid (*components[i])) == T) {
			components[i]->state = game_core::ComponentState::Destroying;
			return true;
		}
	}
	return false;
}