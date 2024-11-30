
export module engine;

import std;

import gamerender;
import swm;
import math;

enum struct State {
	Creating,
	Running,
	Destroying
};

enum struct EnableState {
	Enabling,
	Enabled,
	Disabling,
	Disabled
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
	//screen alignment, local pivot alignment
	//
	//lua construction
	
	class GameObject;
	class Component;
	class Scene;

	class Component : public std::enable_shared_from_this<Component> {
		friend class GameObject;
		State state = State::Creating;
		EnableState enable = EnableState::Enabling;
		std::shared_ptr<GameObject> gameObject;
	protected:
		//sync safe
		virtual void Start() = 0;
		//unsafe
		virtual void Update() = 0;
		//gl context safe
		virtual void Render(int phase) = 0;
		//sync safe
		virtual void SyncUpdate() = 0;
		//sync safe
		virtual void OnEnable() = 0;
		//sync safe
		virtual void OnDisable() = 0;
		//sync safe
		virtual void OnDestroy() = 0;
		Component() {}
	public:
		std::shared_ptr<GameObject> GameObject() {
			return gameObject;
		}
		void Enable() {
			if (enable == EnableState::Disabled || enable == EnableState::Disabling) {
				enable = EnableState::Enabling;
			}
		}
		void Disable() {
			if (enable == EnableState::Enabled || enable == EnableState::Enabling) {
				enable = EnableState::Disabling;
			}
		}
		bool IsEnabled() {
			return enable == EnableState::Enabled;
		}
		virtual ~Component() {}
	};

	class GameObject final : public std::enable_shared_from_this<GameObject> {
		friend class Scene;
		bool destroying = false;
		bool tranformUpdated = false;
		math::Mat4f transformMat;
		EnableState enable = EnableState::Enabling;
		std::vector<std::shared_ptr<GameObject>> children{};
		std::shared_ptr<GameObject> parent{};
		std::vector<std::shared_ptr<Component>> components{};
		void Update() {
			tranformUpdated = false;
			for (int i = 0; i < components.size(); i++) {
				if (components[i]->IsEnabled() && components[i]->state == State::Running) {
					components[i]->Update();
				}
			}
		}
		void Render(int phase) {
			for (int i = 0; i < components.size(); i++) {
				if (components[i]->IsEnabled() && components[i]->state == State::Running) {
					components[i]->Render(phase);
				}
			}
		}
		void SyncUpdate() {
			for (int i = 0; i < components.size(); i++) {
				if ((components[i]->enable == EnableState::Enabled || components[i]->enable == EnableState::Enabling) && components[i]->state == State::Creating) {
					components[i]->state = State::Running;
					components[i]->Start();
				}
			}
			for (int i = 0; i < components.size(); i++) {
				if (components[i]->enable == EnableState::Enabling && components[i]->state == State::Running) {
					components[i]->enable = EnableState::Enabled;
					components[i]->OnEnable();
				}
				else if (components[i]->enable == EnableState::Disabling && components[i]->state == State::Running) {
					components[i]->enable = EnableState::Disabled;
					components[i]->OnDisable();
				}

				if (components[i]->enable == EnableState::Enabled && components[i]->state == State::Running) {
					components[i]->SyncUpdate();
				}
			}
			for (int i = 0; i < components.size(); i++) {
				if (components[i]->state == State::Destroying) {
					components[i]->OnDestroy();
					components.erase(components.begin() + i);
					i--;
				}
			}
			QuerySyncTransform();
		}
		void OnDestroy() {
			if (components.size() > 0) {
				for (int i = 0; i < components.size(); i++) {
					components[i]->OnDestroy();
				}
				components.resize(0);
			}
			SetParent();
		}
		math::Mat4f QuerySyncTransform() {
			if (tranformUpdated) return transformMat;
			math::Mat4f mat = transform.toMatrix();
			if (parent) {
				mat = mat * QuerySyncTransform();
			}
			else {
				transformMat = mat;
			}
			tranformUpdated = true;
			return transformMat;
		}
	protected:
		GameObject() {}
	public:
		//only change in sync update, onenable, ondisable.
		std::string name;
		render::Transform transform;
		template<typename T, typename... P>
		std::shared_ptr<T> AddComponent(P... param) {
			std::shared_ptr<T> component = std::static_pointer_cast<T>((new T(param...))->shared_from_this());
			component->gameObject = shared_from_this();
			components.push_back(component);
			return component;
		}
		template<typename T>
		bool RemoveComponent() {
			for (int i = 0; i < components.size(); i++) {
				if (typeid(T) == typeid(components[i])) {
					components.erase(components.begin() + i);
					return true;
				}
			}
			return false;
		}
		template<typename T>
		std::unique_ptr<T> GetComponent() {
			for (auto& comp : components) {
				if (typeid(T) == typeid(comp)) {
					return (std::unique_ptr<T>)comp;
				}
			}
			return nullptr;
		}
		void SetParent(std::shared_ptr<GameObject> parent = nullptr) {
			if (!this->parent.get()) {
				int index = -1;
				for (int i = 0; i < this->parent->children.size(); i++) {
					if (this->parent->children[i].get() == this) {
						index = i;
						break;
					}
				}
				this->parent->children.erase(this->parent->children.begin() + index);
			}
			this->parent = parent;
			if (this->parent) {
				this->parent->children.push_back(shared_from_this());
			}
		}
		std::shared_ptr<GameObject> Parent() {
			return parent;
		}
		const std::vector<std::shared_ptr<GameObject>> GetChildren() {
			return children;
		}
		void Destroy() {
			destroying = true;
			if (children.size() > 0) {
				for (int i = 0; i < children.size(); i++) {
					children[i]->Destroy();
					children[i]->parent = 0;
				}
				children.resize(0);
			}
		}
		~GameObject() { }

		math::Vec3f Forward() {
			return (math::Vec3f)(transformMat * math::Vec4f(0, 0, 1, 1));
		}
		math::Vec3f Back() {
			return (math::Vec3f)(transformMat * math::Vec4f(0, 0, -1, 1));
		}
		math::Vec3f Right() {
			return (math::Vec3f)(transformMat * math::Vec4f(1, 0, 0, 1));
		}
		math::Vec3f Left() {
			return (math::Vec3f)(transformMat * math::Vec4f(-1, 0, 0, 1));
		}
		math::Vec3f Up() {
			return (math::Vec3f)(transformMat * math::Vec4f(0, 1, 0, 1));
		}
		math::Vec3f Down() {
			return (math::Vec3f)(transformMat * math::Vec4f(0, -1, 0, 1));
		}
	};

	class Scene : swm::SceneBase {
		static inline Scene* currentScene;
		render::UniformBufferObject lightBuffer;
		int maxPhases = 9;
		std::vector<std::shared_ptr<GameObject>> objects{};
		virtual void Start() {
			currentScene = this;
			Initialize();
		}
		virtual void End() {
			if (currentScene == this) currentScene = 0;
			for (int i = 0; i < objects.size(); i++) {
				objects[i]->OnDestroy();
			}
			objects.resize(0);
		}
		virtual void Update() {
			for (int i = 0; i < objects.size(); i++) {
				objects[i]->Update();
			}
			for (int i = 0; i < objects.size(); i++) {
				if (objects[i]->destroying) {
					objects[i]->OnDestroy();
					objects.erase(objects.begin() + i);
					i--;
				}
			}
		}
		virtual void SyncUpdate() {
			for (int i = 0; i < objects.size(); i++) {
				objects[i]->SyncUpdate();
			}
		}
		virtual void Render() {
			for (int p = 0; p < maxPhases; p++) {
				PreRender(p);
				for (int i = 0; i < objects.size(); i++) {
					objects[i]->Render(p);
				}
				PostRender(p);
			}
		}
	public:
		Scene() {
			objects.reserve(4096);
		}
		virtual void Initialize();
		virtual void PreRender(int phase);
		virtual void PostRender(int phase);
		virtual void Resize(long width, long height) {
		
		}
		static std::shared_ptr<GameObject> CreateObject(std::string name, std::shared_ptr<GameObject> parent = nullptr) {
			std::shared_ptr<GameObject> obj(new GameObject());
			obj->name = name;
			obj->SetParent(parent);
			currentScene->objects.push_back(obj);
			return obj;
		}
		static std::shared_ptr<GameObject> GetObject(std::string name) {
			for (int i = 0; i < currentScene->objects.size(); i++) {
				if (currentScene->objects[i] && name == currentScene->objects[i]->name) {
					return currentScene->objects[i];
				}
			}
		}
		static Scene* CurrentScene() {
			return currentScene;
		}
		static render::UniformBufferObject* LightBuffer() {
			return &(currentScene->lightBuffer);
		}
	};
}

struct Light_t {
	math::Vec3f position;
	// direction x,y,z = 0 : point light
	// direction x,y,z = vector : spot light, radius = spot light radius
	// direction x,y,z = vector, radius = 0 : sun light
	math::Vec3f direction;
	float radius;
	math::Vec3f color;
	// distance for point and spot light
	// brightness for sunlight
	float magnitude;
};
struct LightSupply {
	int length;
	Light_t lights[0];
};

export namespace engine::component{
	class Camera final : public engine::Component {
		friend engine::Scene;
	public:
		enum struct CameraType {
			Main,
		};
	private:
		CameraType type;
		math::Mat4f transform;
		static inline std::shared_ptr<Camera> mainCamera;
		virtual void Start() {
			switch (type) {
			case CameraType::Main: {
				mainCamera = std::static_pointer_cast<Camera>(shared_from_this());
			} break;
			}
		}
		virtual void Update() {}
		virtual void Render(int phase) {}
		virtual void SyncUpdate() {
			transform = GameObject()->transform.toMatrixInverse();
			for (std::shared_ptr<engine::GameObject> p = GameObject()->Parent(); p; p = p->Parent()) {
				transform = p->transform.toMatrixInverse() * transform;
			}
		}
		virtual void OnEnable() {
			cameraUniformObject.BindBuffer();
		}
		virtual void OnDisable() {
			cameraUniformObject.UnbindBuffer();
		}
		virtual void OnDestroy() {}
		static void PreRender(int phase) {
			if (!mainCamera) return;
			struct Data {
				math::Mat4f transform;
				math::Mat4f perspective;
				math::Mat4f UI;
			};
			Data k{};
			k.transform = mainCamera->transform;
			k.perspective = math::Mat4f::Perspective(mainCamera->fov, swm::getWindowRatio(), mainCamera->nearPlane, mainCamera->farPlane);
			k.UI = math::Mat4f::Orthographic(swm::getWindowWidth(), swm::getWindowRatio(), 1, 10);
			mainCamera->cameraUniformObject.Set(&k, sizeof(k), render::BufferUsageHint::StreamDraw);
		}
		static void PostRender(int phase) {
			mainCamera->frameBuffer.CopyContentToScreen();
		}
	public:
		Camera(CameraType type) {
			this->type = type;
		}
		static std::shared_ptr<Camera> MainCamera() {
			return mainCamera;
		}
		render::FrameBuffer2d frameBuffer{8};
		render::UniformBufferObject cameraUniformObject{};
		float fov = 60 * math::PI;
		float nearPlane = 0.1;
		float farPlane = 400;

	};

	class MeshRenderer final : public engine::Component {
		//sync safe
		virtual void Start() {}
		//unsafe
		virtual void Update() {}
		//gl context safe
		virtual void Render(int phase) {
			if(material && mesh) material->Render(mesh.get(), GameObject()->transform.toMatrix(), &(Camera::MainCamera()->cameraUniformObject));
		}
		//sync safe
		virtual void SyncUpdate() {}
		//sync safe
		virtual void OnEnable() {}
		//sync safe
		virtual void OnDisable() {}
		//sync safe
		virtual void OnDestroy() {}
	public:
		std::shared_ptr<render::Mesh> mesh;
		std::shared_ptr<render::MaterialBase> material;
	};

	class UIManager final : public engine::Component {
		//sync safe
		virtual void Start() {}
		//unsafe
		virtual void Update() {}
		//gl context safe
		virtual void Render(int phase) {}
		//sync safe
		virtual void SyncUpdate() {}
		//sync safe
		virtual void OnEnable() {}
		//sync safe
		virtual void OnDisable() {}
		//sync safe
		virtual void OnDestroy() {}
	public:
	};

	class SunLight final : public engine::Component {
		static inline std::vector<std::shared_ptr<SunLight>> sunlights {};

		friend engine::Scene;
		static std::vector<Light_t> GetLights() {
			std::vector<Light_t> lights{};
			for (int i = 0; i < sunlights.size(); i++) {
				Light_t v{};
				v.color = sunlights[i]->color;
				v.direction = sunlights[i]->GameObject()->Forward();
				v.magnitude = sunlights[i]->intensity;
				lights.push_back(v);
			}
			return lights;
		}

		//sync safe
		virtual void Start() {}
		//unsafe
		virtual void Update() {}
		//gl context safe
		virtual void Render(int phase) {}
		//sync safe
		virtual void SyncUpdate() {}
		//sync safe
		virtual void OnEnable() {}
		//sync safe
		virtual void OnDisable() {}
		//sync safe
		virtual void OnDestroy() {}
	public:
		math::Vec3f color;
		float intensity;
	};
}

void engine::Scene::Initialize() {
	
}

void engine::Scene::PreRender(int phase) {
	if (phase == 0) {
		std::vector<Light_t> light{};
		light.append_range(engine::component::SunLight::GetLights());
		size_t lightSize = sizeof(Light_t) * light.size();
		size_t lightSupplySize = sizeof(LightSupply) + lightSize;
		std::unique_ptr<LightSupply> lightSupply{ (LightSupply*)malloc(lightSupplySize) };
		lightSupply->length = light.size();
		memcpy(lightSupply->lights, light.begin()._Ptr, lightSize);
		lightBuffer.Set(lightSupply.get(), lightSupplySize, render::BufferUsageHint::DynamicDraw);

		engine::component::Camera::PreRender(phase);
	}
}
void engine::Scene::PostRender(int phase) {
	if (phase == 1) {
		engine::component::Camera::PostRender(phase);
	}
}