module;

#include <stdint.h>
#include "debug.h"

export module engine;

import "glm.h";

import std;

import gamerender;
import winmanager;
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
	constexpr auto FloatToUN8(float value) { return (uint8_t)(value * 256); }

	int GetGameScreenWidth();
	int GetGameScreenHeight();
	int GetGameScreenRatio();

	enum struct RenderLayer {
		MainScene,
		GUI,
		Max,
	};

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
	class SceneBase;

	class Component : public std::enable_shared_from_this<Component> {
		friend class GameObject;
		State state = State::Creating;
		EnableState enableState = EnableState::Enabling;
		bool enable = true;
		bool cascadeEnable = true;
		std::shared_ptr<GameObject> gameObject{};
	protected:
		//sync safe
		virtual void Start() = 0;
		//unsafe
		virtual void Update() = 0;
		//gl context safe
		virtual void Render(RenderLayer renderLayer) = 0;
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
			if (!enable) {
				enable = true;
				if (cascadeEnable && (enableState == EnableState::Disabled || enableState == EnableState::Disabling)) {
					enableState = EnableState::Enabling;
				}
			}
		}
		void Disable() {
			if (enable) {
				enable = false;
				if (cascadeEnable && (enableState == EnableState::Enabled || enableState == EnableState::Enabling)) {
					enableState = EnableState::Disabling;
				}
			}
		}
		bool IsEnabled() {
			return enable && cascadeEnable && state != State::Destroying && state != State::Creating;
		}
		bool IsDestroyed() {
			return state == State::Destroying;
		}
		virtual ~Component() {}
	};

	class GameObject final : public std::enable_shared_from_this<GameObject> {
		friend class SceneBase;
		bool destroying = false;
		bool tranformUpdated = false;
		math::Mat4f transformMat{};
		bool enable = true;
		bool cascadeEnable = true;
		std::vector<std::shared_ptr<GameObject>> children{};
		std::shared_ptr<GameObject> parent{};
		std::vector<std::shared_ptr<Component>> components{};
		void Update() {
			if (!IsEnabled()) return;
			for (int i = 0; i < components.size(); i++) {
				if (components[i]->IsEnabled() && components[i]->state == State::Running) {
					components[i]->Update();
				}
			}
		}
		void Render(RenderLayer renderLayer) {
			tranformUpdated = false;
			if (!IsEnabled()) return;
			for (int i = 0; i < components.size(); i++) {
				if (components[i]->IsEnabled()) {
					components[i]->Render(renderLayer);
				}
			}
		}
		void SyncUpdate() {
			for (int i = 0; i < components.size(); i++) {
				if (components[i]->state == State::Creating) {
					components[i]->state = State::Running;
					components[i]->Start();
				}
			}
			for (int i = 0; i < components.size(); i++) {
				if (components[i]->enableState == EnableState::Enabling && components[i]->state == State::Running) {
					components[i]->enableState = EnableState::Enabled;
					components[i]->OnEnable();
				}
				else if (components[i]->enableState == EnableState::Disabling && components[i]->state == State::Running) {
					components[i]->enableState = EnableState::Disabled;
					components[i]->OnDisable();
				}
			}
			if (IsEnabled()) {
				for (int i = 0; i < components.size(); i++) {
					if (components[i]->IsEnabled()) {
						components[i]->SyncUpdate();
					}
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
				transformMat = mat * parent->QuerySyncTransform();
			}
			else {
				transformMat = mat;
			}
			tranformUpdated = true;
			return transformMat;
		}

		void CascadeEnable() {
			for (int i = 0; i < components.size(); i++) {
				components[i]->cascadeEnable = true;
				if (components[i]->enable)
					components[i]->enableState = EnableState::Enabling;
			}
			for (int i = 0; i < children.size(); i++) {
				children[i]->cascadeEnable = true;
				if (!children[i]->enable) 
					children[i]->CascadeEnable();
			}
		}
		void CascadeDisable() {
			for (int i = 0; i < components.size(); i++) {
				components[i]->cascadeEnable = false;
				if (components[i]->enable)
					components[i]->enableState = EnableState::Disabling;
			}
			for (int i = 0; i < children.size(); i++) {
				children[i]->cascadeEnable = false;
				if(!children[i]->enable) 
					children[i]->CascadeDisable();
			}
		}

	protected:
		GameObject() {}
	public:
		//only change in sync update, onenable, ondisable.
		std::string name{};
		render::Transform transform;
		template<typename T, typename... P>
		std::shared_ptr<T> AddComponent(P... param) {
			std::shared_ptr<T> component{ new T(param...) };
			component->gameObject = std::shared_ptr<GameObject>{ shared_from_this()};
			components.push_back(component);
			if (!IsEnabled()) {
				component->cascadeEnable = false;
				component->enableState = EnableState::Disabling;
			}
			return component;
		}
		//remake function
		template<typename T>
		bool RemoveComponent() {
			for (int i = 0; i < components.size(); i++) {
				if (typeid(T) == typeid(components[i])) {
					components[i]->state = State::Destroying;
					return true;
				}
			}
			return false;
		}
		template<typename T>
		std::shared_ptr<T> GetComponent() {
			for (auto& comp : components) {
				if (typeid(T) == typeid(*comp)) {
					return std::dynamic_pointer_cast<T>(comp);
				}
			}
			return nullptr;
		}
		void SetParent(std::shared_ptr<GameObject> parent = nullptr) {
			if (this->parent == parent) return;
			if (this->parent) {
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
				if (cascadeEnable && (!this->parent->cascadeEnable || !this->parent->enable)) {
					cascadeEnable = false;
					if (enable) CascadeDisable();
				}
				else if(!cascadeEnable && this->parent->cascadeEnable && this->parent->enable) {
					cascadeEnable = true;
					if (!enable) CascadeEnable();
				}
			}
			else if (!cascadeEnable) {
				cascadeEnable = true;
				if (!enable) CascadeEnable();
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
		}
		void Enable() {
			if (!enable) {
				enable = true;
				if (cascadeEnable) CascadeEnable();
			}
		}
		void Disable() {
			if (enable) {
				enable = false;
				if(cascadeEnable) CascadeDisable();
			}
		}
		bool IsEnabled() {
			return enable && cascadeEnable && !destroying;
		}
		bool IsDestroyed() {
			return destroying;
		}

		math::Mat4f Transform() {
			return transformMat;
		}
		math::Vec3f Forward() {
			return (math::Vec3f)(transformMat * math::Vec4f(0, 0, 1, 0)).Normal();
		}
		math::Vec3f Back() {
			return (math::Vec3f)(transformMat * math::Vec4f(0, 0, -1, 0)).Normal();
		}
		math::Vec3f Right() {
			return (math::Vec3f)(transformMat * math::Vec4f(1, 0, 0, 0)).Normal();
		}
		math::Vec3f Left() {
			return (math::Vec3f)(transformMat * math::Vec4f(-1, 0, 0, 0)).Normal();
		}
		math::Vec3f Up() {
			return (math::Vec3f)(transformMat * math::Vec4f(0, 1, 0, 0)).Normal();
		}
		math::Vec3f Down() {
			return (math::Vec3f)(transformMat * math::Vec4f(0, -1, 0, 0)).Normal();
		}
		math::Vec3f globalPosition() {
			return (math::Vec3f)(transformMat * math::Vec4f(0, 0, 0, 1));
		}

		~GameObject() {}

		//add function for disable and enable
		//fix update method to include it
	};

	class SceneBase : wm::RawSceneBase {
		static thread_local inline SceneBase* currentScene{};
		render::UniformBufferObject lightBuffer{};
		int maxrenderLayers = (int)RenderLayer::Max;
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
			currentScene = this;
			for (int i = 0; i < objects.size(); i++) {
				if (!objects[i]->destroying) {
					objects[i]->Update();
				}
			}
			Iterate();
		}
		virtual void SyncUpdate() {
			currentScene = this;
			for (int i = 0; i < objects.size(); i++) {
				objects[i]->SyncUpdate();
			}
			for (int i = 0; i < objects.size(); i++) {
				if (objects[i]->destroying) {
					objects[i]->OnDestroy();
					objects.erase(objects.begin() + i);
					i--;
				}
			}

			//on object destroy
		}
		virtual void Render() {
			currentScene = this;
			for (int p = 0; p < maxrenderLayers; p++) {
				PreRender((RenderLayer)p);
				for (int i = 0; i < objects.size(); i++) {
					objects[i]->Render((RenderLayer)p);
				}
				PostRender((RenderLayer)p);
			}
		}
	public:
		SceneBase(wm::Window* window) : wm::RawSceneBase(window) {
			objects.reserve(4096);
		}
		virtual void Initialize();
		virtual void Iterate() = 0;
		virtual void PreRender(RenderLayer renderLayer);
		virtual void PostRender(RenderLayer renderLayer);
		virtual void Resize(long width, long height);
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
		static SceneBase* CurrentScene() {
			return currentScene;
		}
		static render::UniformBufferObject* LightBuffer() {
			return &(currentScene->lightBuffer);
		}
	};

	std::shared_ptr<render::Mesh> getUIMesh() {
		static std::weak_ptr<render::Mesh> UIMesh{ };
		std::shared_ptr<render::Mesh> mesh;
		if (UIMesh.expired()) {
			mesh = std::shared_ptr<render::Mesh>{ new render::Mesh() };
			std::vector<render::PointP3NUC> points{};
			points.push_back(render::PointP3NUC{
				math::Vec3f{-0.5,-0.5,0},
				math::Vec3f{0,0,-1},
				math::Vec2f{0,0},
				math::Vec4f{1,1,1,1},
				});
			points.push_back(render::PointP3NUC{
				math::Vec3f{0.5,0.5,0},
				math::Vec3f{0,0,-1},
				math::Vec2f{1,1},
				math::Vec4f{1,1,1,1},
				});
			points.push_back(render::PointP3NUC{
				math::Vec3f{0.5,-0.5,0},
				math::Vec3f{0,0,-1},
				math::Vec2f{1,0},
				math::Vec4f{1,1,1,1},
				});
			points.push_back(render::PointP3NUC{
				math::Vec3f{-0.5,-0.5,0},
				math::Vec3f{0,0,-1},
				math::Vec2f{0,0},
				math::Vec4f{1,1,1,1},
				});
			points.push_back(render::PointP3NUC{
				math::Vec3f{-0.5,0.5,0},
				math::Vec3f{0,0,-1},
				math::Vec2f{0,1},
				math::Vec4f{1,1,1,1},
				});
			points.push_back(render::PointP3NUC{
				math::Vec3f{0.5,0.5,0},
				math::Vec3f{0,0,-1},
				math::Vec2f{1,1},
				math::Vec4f{1,1,1,1},
				});
			mesh->set(points);
			UIMesh = mesh;
		}
		
		return UIMesh.lock();
	}
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

export namespace engine::UI {
	
}

export namespace engine::component{
	class Camera final : public engine::Component {
		friend engine::SceneBase;
	public:
		enum struct CameraType {
			Main,
		};
	private:
		CameraType type{};
		math::Mat4f transform{};
		static inline std::shared_ptr<Camera> mainCamera{};
		virtual void Start() {
			switch (type) {
			case CameraType::Main: {
				mainCamera = std::static_pointer_cast<Camera>(shared_from_this());
			} break;
			}

			GLSTAMPERROR;
			frameBuffer.ResizeToScreen(scalePercent);
			GLSTAMPERROR;
		}
		virtual void Update() {}
		virtual void Render(engine::RenderLayer renderLayer) {}
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
		virtual void OnDestroy() {
			if (mainCamera.get() == this) {
				mainCamera = {};
			}
		}
		static void PreRender(RenderLayer renderLayer) {
			if (renderLayer != engine::RenderLayer::MainScene) return;
			if (!mainCamera || !mainCamera->IsEnabled()) return;

			struct Data {
				math::GLmat4 transform{};
				math::GLmat4 perspective{};
				math::GLmat4 UI{};
				math::GLvec4 pos{};
			};
			Data k{};
			k.pos = (math::Vec4f)(mainCamera->GameObject()->globalPosition());
			k.transform = mainCamera->transform;
			if (mainCamera->isPerspective)
				k.perspective = math::Mat4f::Perspective(mainCamera->fov, GameRatio(), mainCamera->nearPlane, mainCamera->farPlane);
			else
				k.perspective = math::Mat4f::Orthographic(mainCamera->fov, GameRatio(), mainCamera->nearPlane, mainCamera->farPlane);
			k.UI = math::Mat4f::Orthographic(1, 1, 0, 10);
			mainCamera->cameraUniformObject.Set(&k, sizeof(k), render::BufferUsageHint::StreamDraw);
			GLSTAMPERROR;
		}
		static void PostRender(RenderLayer renderLayer) {
			if (!mainCamera || !mainCamera->IsEnabled()) return;
			mainCamera->frameBuffer.CopyContentToScreen();
			GLSTAMPERROR;
		}
		static void OnResize(int width, int height) {
		}
	public:
		render::FrameBuffer2d frameBuffer{ {GL_RGBA8}, -1, -1 };
		render::UniformBufferObject cameraUniformObject{};
		float fov = 60.0 * math::DEGTORAD;
		float nearPlane = 0.1;
		float farPlane = 5000;
		float scalePercent = 1.2;
		bool isPerspective = true;

		Camera(CameraType type) {
			this->type = type;
		}
		static std::shared_ptr<Camera> MainCamera() {
			return mainCamera;
		}

		static int GameWidth() {
			return mainCamera->frameBuffer.colorAttachments[0].Width();
		}
		static int GameHeight() {
			return mainCamera->frameBuffer.colorAttachments[0].Height();
		}
		static float GameRatio() {
			float height = GameHeight();
			float width = GameWidth();
			return (float)height / width;
		}
		static void ResizeScreen(int width, int height) {
			GLSTAMPERROR;
			mainCamera->frameBuffer.Resize(width * mainCamera->scalePercent, height * mainCamera->scalePercent);
			swm::setClientResolution(width, height, true);
			GLSTAMPERROR;
		}
		void ResizeDrawToScreen() {
			GLSTAMPERROR;
			frameBuffer.ResizeToScreen(scalePercent);
			GLSTAMPERROR;
		}
	};

	class MeshRenderer final : public engine::Component {
		//sync safe
		virtual void Start() {
			UpdateRenderer();
		}
		//unsafe
		virtual void Update() {}
		//gl context safe
		virtual void Render(engine::RenderLayer renderLayer) {
			if (renderLayer != engine::RenderLayer::MainScene) return;
			if (material && mesh) {
				material->Render(mesh.get(), GameObject()->Transform(), &(Camera::MainCamera()->cameraUniformObject));
			}
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
		void UpdateRenderer() {
			material->UpdateMeshAttrib(mesh.get());
		}
	};
	class OceanRenderer final : public engine::Component {
		//sync safe
		virtual void Start() {
			ocean.UpdateRenderer();
		}
		//unsafe
		virtual void Update() {}
		//gl context safe
		virtual void Render(engine::RenderLayer renderLayer) {
			if (renderLayer != engine::RenderLayer::MainScene) return;

			ocean.Render(GameObject()->Transform(), Camera::MainCamera()->cameraUniformObject);
		}
		//sync safe
		virtual void SyncUpdate() {}
		//sync safe
		virtual void OnEnable() {
			ocean.OceanObj.BindBuffer();
		}
		//sync safe
		virtual void OnDisable() {
			ocean.OceanObj.UnbindBuffer();
		}
		//sync safe
		virtual void OnDestroy() {}
	public:
		render::OceanRenderObject ocean;
	};

	class BillboardRenderer final : public engine::Component {
		std::shared_ptr<render::Mesh> mesh{};
		render::UBObject billboardUBO{};
		//sync safe
		virtual void Start() {
			mesh = engine::getUIMesh();
			UpdateAttrib();
		}
		//unsafe
		virtual void Update() {}
		//gl context safe
		virtual void Render(engine::RenderLayer renderLayer) {}
		//sync safe
		virtual void SyncUpdate() {}
		//sync safe
		virtual void OnEnable() {}
		//sync safe
		virtual void OnDisable() {}
		//sync safe
		virtual void OnDestroy() {}
	public:
		std::shared_ptr< render::SamplerTexture2d> texture;
		std::shared_ptr<render::MaterialBase> material{};
		//true: can look up and down
		bool vertAlign = true;
		//mask depth
		bool maskDepth = true;
		//scale with Depth
		bool scaleDepth = true;
		//write the const depth instead of actual depth
		bool constDepth = true;
		float depthLayer = 0;
		float width = 1;
		float height = 1;

		void UpdateMaterial() {

		}
		void UpdateAttrib() {
			struct Billboard_t {
				GLfloat depthLayer;
			};
			Billboard_t billboard{};

			billboardUBO.Set(&billboard, sizeof(Billboard_t), render::BufferUsageHint::DynamicDraw);
		}
	};

	class TransformUI final : public engine::Component {
		bool calculated = false;
		//sync safe
		virtual void Start() {}
		//unsafe
		virtual void Update() {
			CalcTransform();
		}
		//gl context safe
		virtual void Render(engine::RenderLayer renderLayer) {}
		//sync safe
		virtual void SyncUpdate() {
			calculated = false;
		}
		//sync safe
		virtual void OnEnable() {}
		//sync safe
		virtual void OnDisable() {}
		//sync safe
		virtual void OnDestroy() {}

		math::Vec2f CalcTransform() {
			if (calculated) {
				return {height / 2, width / 2};
			}
			calculated = true;
			float top, bottom, right, left;
			std::shared_ptr<TransformUI> p;
			if (GameObject()->Parent() && (p = GameObject()->Parent()->GetComponent<TransformUI>())) {
				auto v = p->CalcTransform();
				top = v.x;
				bottom = -top;
				right = v.y;
				left = -right;
			}
			else {
				top = engine::GetGameScreenHeight() / 2;
				bottom = -top;
				right = engine::GetGameScreenWidth() / 2;
				left = -right;
			}
			float X = alignX;
			float Y = alignY;
			X += (offsetX + width / 2 - (pivotX + 1) / 2 * width) / (right - left);
			Y += (offsetY + height / 2 - (pivotY + 1) / 2 * height) / (top - bottom);
			GameObject()->transform.position = { X,Y,0.01 };
			GameObject()->transform.scale = { width / (right - left) , height / (top - bottom), 1 };

			return { height / 2, width / 2 };
		}
	public:
		float width = 256;
		float height = 256;
		//percent [-1,1]
		float alignX = 0;
		//percent [-1,1]
		float alignY = 0;
		//percent [-1,1]
		float pivotX = 0;
		//percent [-1,1]
		float pivotY = 0;
		//pixels
		float offsetX = 0;
		//pixels
		float offsetY = 0;

	};

	class ImageRendererUI final : public engine::Component {
		std::shared_ptr<render::Mesh> mesh{};
		//sync safe
		virtual void Start() {
			mesh = engine::getUIMesh();
			UpdateRenderer();
		}
		//unsafe
		virtual void Update() {}
		//gl context safe
		virtual void Render(engine::RenderLayer renderLayer) {
			if (renderLayer != engine::RenderLayer::GUI) return;
			if (material && mesh) {
				material->Render(mesh.get(), GameObject()->Transform(), &(Camera::MainCamera()->cameraUniformObject));
			}
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
		std::shared_ptr<render::MaterialBase> material{};
		void UpdateRenderer() {
			material->UpdateMeshAttrib(mesh.get());
		}
	};

	class TextRendererUI final : public engine::Component {
		render::Mesh mesh{};
		std::shared_ptr<TransformUI> transform;
		//sync safe
		virtual void Start() {
			transform = GameObject()->GetComponent<TransformUI>();
			UpdateRenderer();
		}
		//unsafe
		virtual void Update() {}
		//gl context safe
		virtual void Render(engine::RenderLayer renderLayer) {
			if (renderLayer != engine::RenderLayer::GUI) return;
			if (material && mesh) {
				glEnable(GL_BLEND);
				material->Render(&mesh, GameObject()->Transform(), &(Camera::MainCamera()->cameraUniformObject));
				glDisable(GL_BLEND);
			}
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

		std::shared_ptr<render::UIMaterial> material{};
		std::u8string text = u8"UI Textij!\n012345678901234";
		std::shared_ptr<render::FontMap> fontMap{};
		int textAlign;
		float scale = 2;
		int lineHoriGap = 0;
		int lineVertGap = 2;
		float horiAlign = 0;
		float vertAlign = 1;
		void UpdateRenderer() {
			material->texture = fontMap->texture;
			fontMap->texture->BindActive();
			std::vector<render::PointP3NUC> points{};
			size_t index = 0;
			float lineHeight = (lineVertGap + fontMap->LineHeight()) * scale;
			int linePointStart = 0;
			float lineWidth = 0;
			float lineY = lineHeight;
			while (index < text.size()) {
				unsigned int character = render::FontMap::ParseUTF8Char((char*)text.data(), index, text.size());
				if (character == '\n') {
					for (int i = linePointStart; i < points.size(); i++) {
						points[i].pos.x += (transform->width - lineWidth) * (horiAlign + 1) / 2 / transform->width;
					}
					lineWidth = 0;
					lineY += lineHeight;
					linePointStart = points.size();
					continue;
				}

				render::FontMap::FontMapItem item = fontMap->getCharData(character);

				if (lineWidth + (item.width + lineHoriGap) * scale >= transform->width) {
					for (int i = linePointStart; i < points.size(); i++) {
						points[i].pos.x += (transform->width - lineWidth) * (horiAlign + 1) / 2 / transform->width;
					}
					lineWidth = 0;
					lineY += lineHeight;
					linePointStart = points.size();
				}

				float x = (lineWidth - transform->width / 2) / transform->width;
				float y = (transform->height / 2 - lineY - item.yOffset * scale) / transform->height;
				float w = item.width / transform->width * scale;
				float h = item.height / transform->height * scale;
				points.push_back(render::PointP3NUC{
					math::Vec3f{x,y,0},
					math::Vec3f{0,0,0},
					math::Vec2f{item.uvTL},
					math::Vec4f{1,1,1,1},
					});
				points.push_back(render::PointP3NUC{
					math::Vec3f{x + w,y + h,0},
					math::Vec3f{0,0,0},
					math::Vec2f{item.uvBR},
					math::Vec4f{1,1,1,1},
					});
				points.push_back(render::PointP3NUC{
					math::Vec3f{x + w,y,0},
					math::Vec3f{0,0,0},
					math::Vec2f{item.uvTR},
					math::Vec4f{1,1,1,1},
					});
				points.push_back(render::PointP3NUC{
					math::Vec3f{x,y,0},
					math::Vec3f{0,0,0},
					math::Vec2f{item.uvTL},
					math::Vec4f{1,1,1,1},
					});
				points.push_back(render::PointP3NUC{
					math::Vec3f{x,y + h,0},
					math::Vec3f{0,0,0},
					math::Vec2f{item.uvBL},
					math::Vec4f{1,1,1,1},
					});
				points.push_back(render::PointP3NUC{
					math::Vec3f{x + w,y + h,0},
					math::Vec3f{0,0,0},
					math::Vec2f{item.uvBR},
					math::Vec4f{1,1,1,1},
					});
				lineWidth += (item.width + lineHoriGap) * scale;
			}

			for (int i = linePointStart; i < points.size(); i++) {
				points[i].pos.x += std::floor((transform->width - lineWidth) * (horiAlign + 1) / 2) / transform->width;
			}
			lineY += lineVertGap * scale;

			for (int i = 0; i < points.size(); i++) {
				points[i].pos.y -= std::floor(((transform->height - lineY) * (1 - vertAlign) / 2)) / transform->height;
			}

			mesh.set(points, render::BufferUsageHint::DynamicDraw);
			material->UpdateMeshAttrib(&mesh);
		}
	};

	class SunLight final : public engine::Component {
		static inline std::vector<std::shared_ptr<SunLight>> sunlights {};

		friend engine::SceneBase;
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
		virtual void Render(engine::RenderLayer renderLayer) {}
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

int engine::GetGameScreenWidth() {
	return engine::component::Camera::GameWidth();
}
int engine::GetGameScreenHeight() {
	return engine::component::Camera::GameHeight();
}
int engine::GetGameScreenRatio() {
	return engine::component::Camera::GameRatio();
}

void engine::SceneBase::Initialize() {
	
}

void engine::SceneBase::PreRender(engine::RenderLayer renderLayer) {
	if (renderLayer == engine::RenderLayer::MainScene) {

		std::vector<Light_t> light{};
		light.append_range(engine::component::SunLight::GetLights());
		size_t lightSize = sizeof(Light_t) * light.size();
		size_t lightSupplySize = sizeof(LightSupply) + lightSize;
		std::unique_ptr<LightSupply> lightSupply{ (LightSupply*)malloc(lightSupplySize) };
		lightSupply->length = light.size();
		memcpy(lightSupply->lights, light.begin()._Ptr, lightSize);
		lightBuffer.Set(lightSupply.get(), lightSupplySize, render::BufferUsageHint::DynamicDraw);
	}
	else if (renderLayer == engine::RenderLayer::GUI) {
		glClear(GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	}

	engine::component::Camera::PreRender(renderLayer);
}
void engine::SceneBase::PostRender(engine::RenderLayer renderLayer) {
	if (renderLayer == (engine::RenderLayer)((int)engine::RenderLayer::Max - 1)) {
		engine::component::Camera::PostRender(renderLayer);
	}
}
void engine::SceneBase::Resize(long width, long height) {
	engine::component::Camera::OnResize(width, height);
}