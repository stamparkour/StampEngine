#include <memory>
export module engine;

import <vector>;
import <utility>;
import <string>;

import render;
import swm;
import math;

enum struct State {
	Creating,
	Running,
	Destroying
};

export namespace engine {
	//uimanager
	//	--main uielement: screen
	//	--camera
	//		--varrying width or height
	//	--render function
	
	//dictionary of name, id
	//dictionary of id, element
	//virtual: uielement
	//	--id
	//	--child elements
	//	--disable/enable (pass to children)
	//	--virtual onclick
	//	--virtual onmouserelease
	//	--virtual render function
	//  --onenabled/ondisabled
	//	--transform
	//	--up/right/down/left id for joystick/arrow key identification.

	//alignment: 
	// +--+--+
	// |  |  |
	// +--+--+ 
	// |  |  |
	// +--+--+
	// stretch/fixed width and height
	//x1, x2
	//y1, y2
	//
	//lua construction
	
	class GameObject;
	class Component;

	class Scene : swm::SceneBase {
		static inline Scene* currentScene;
		std::vector<std::shared_ptr<GameObject>> objects{};
		virtual void Start() {
			currentScene = this;
			Initialize();
		}
		virtual void End() {
			if (currentScene == this) currentScene = 0;
		}
		virtual void Update() {}
		virtual void SyncUpdate() {}
		virtual void Render() {}
		virtual void Resize(long width, long height) {}
	public:
		Scene() {}
		virtual void Initialize() = 0;
		static void AddObject() {

		}
		static std::shared_ptr<GameObject> GetObjectByName(std::string name) {
			for (auto obj : currentScene->objects) {
				if (name == obj->name) {
					return obj;
				}
			}
			return nullptr;
		}
	};

	class GameObject {
		State state = State::Creating;
		bool enabled = true;
		std::vector<std::shared_ptr<Component>> components{};
	public:
		std::string name;
		void AddComponent(std::shared_ptr<Component> component) {
			components.push_back(component);
		}
		template<typename T>
		void RemoveComponent() {
			for (int i = 0; i < components.size(); i++) {
				if (typeid(T) == typeid(components[i])) {
					components.erase(components.begin() + i);
					return;
				}
			}
		}
		template<typename T>
		std::shared_ptr<T> GetComponent() {
			for (auto comp : components) {
				if (typeid(T) == typeid(comp)) {
					return (std::shared_ptr<T>)comp;
				}
			}
			return nullptr;
		}
	};
	
	class Component {
		State state = State::Creating;
		bool enabled = true;
	protected:
		virtual void Start() = 0;
		virtual void Update() = 0;
		virtual void Render() = 0;
		virtual void SyncUpdate() = 0;
		virtual void OnEnable() = 0;
		virtual void OnDisable() = 0;
		virtual void OnDestroy() = 0;
		Component() {}
	public:

		~Component() {}
	};
}