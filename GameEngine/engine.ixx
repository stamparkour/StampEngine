module;

#include <stdint.h>
#include "debug.h"
#include "lua/lua.hpp"

#define luaS_registermetatable(L, l, tname) (luaL_newmetatable(L, tname),luaL_setfuncs(L, l, 0),lua_setglobal(L, tname))
#define luaS2_registermetatable(L, _class) (luaL_newmetatable((L), _class::TypeID.c_str()),luaL_setfuncs(L, _class::LuaReg, 0),lua_setglobal(L, _class::TypeID.c_str()))

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

constexpr auto BITMASK(auto i) {
	return (1 << (int)i);
}

export namespace lua {
	class LuaManager final {
		static inline LuaManager* instance = 0;

		LuaManager() {
			instance = this;
			L = luaL_newstate();
			luaL_openlibs(L);
			void* p = lua_getextraspace(L);
			p = this;
		}
		void LoadFile(const char* filename) {
			int error = luaL_dofile(L, filename);
			if (error) {
				STAMPSTACK();
				STAMPDMSG("lua::luamanager::loadfile - error : " << lua_tostring(L, -1));
				lua_pop(L, 1);
			}
		}
	public:
		lua_State* L = nullptr;

		static LuaManager* Instance() {
			if (!instance) {
				instance = new LuaManager();
			}
			return instance;
		}

		LuaManager(LuaManager& other) = delete;
		LuaManager& operator =(const LuaManager& other) = delete;
		LuaManager(LuaManager&& other) noexcept {
			using std::swap;
			swap(*this, other);
		}
		LuaManager& operator =(LuaManager&& other) noexcept {
			using std::swap;
			swap(*this, other);
		}
		friend void swap(LuaManager& a, LuaManager& b) noexcept {
			using std::swap;
			swap(a.L, b.L);
		}

		void LoadDefaultFiles() {
			if (!std::filesystem::exists("./script/")) {
				std::cout << "[LUA] lua script folder does not exist" << std::endl;
				return;
			}
			for (auto const& entry : std::filesystem::directory_iterator("./script/")) {
				if (entry.path().extension() == ".lua") {
					std::cout << "[LUA] Loading lua file: " << entry.path().string() << std::endl;
					LoadFile(entry.path().string().c_str());
				}
			}
		}
		void RegisterFunction(const std::string& name, lua_CFunction func) {
			lua_register(L, name.c_str(), func);
		}
		~LuaManager() {
			if (L) {
				lua_close(L);
				L = 0;
			}
		}
	};
}

export namespace engine::resource {
	class TextureResource {

		std::weak_ptr<render::SamplerBase> tex{};
		std::weak_ptr<render::RawTexture2d4f> rawTex{};
	public:
		static inline const std::string typeID = "Texture";
		std::filesystem::path path{};
		render::TextureMinFilter minFilter = render::TextureMinFilter::Linear;
		render::TextureMagFilter magFilter = render::TextureMagFilter::Linear;

		bool setValue(const std::string& key, const std::string& value) {
			if (key == "path") {
				path = value;
				return true;
			}
			else if (key == "minFilter") {
				if (value == "nearest") minFilter = render::TextureMinFilter::Nearest;
				else if (value == "linear") minFilter = render::TextureMinFilter::Linear;
				else if (value == "nearest mipmap nearest") minFilter = render::TextureMinFilter::NearestMipmapNearest;
				else if (value == "linear mipmap nearest") minFilter = render::TextureMinFilter::LinearMipmapNearest;
				else if (value == "nearest mipmap linear") minFilter = render::TextureMinFilter::NearestMipmapLinear;
				else if (value == "linear mipmap linear") minFilter = render::TextureMinFilter::LinearMipmapLinear;
				return true;
			}
			else if (key == "magFilter") {
				if (value == "nearest") magFilter = render::TextureMagFilter::Nearest;
				else if (value == "linear") magFilter = render::TextureMagFilter::Linear;
				return true;
			}
			return false;
		}

		std::shared_ptr<render::RawTexture2d4f> getRawTexture2d4f() {
			if (rawTex.expired()) {
				std::fstream file{ path, std::ios::in | std::ios::binary };
				auto rTex = std::make_shared<render::RawTexture2d4f>();
				if (path.extension() == ".bmp") *rTex = render::RawTexture2d4f::ParseStream_bmp(file);
				else return {};
				rawTex = rTex;
				return rTex;
			}
			return rawTex.lock();
		}
		std::shared_ptr<render::SamplerTexture2d> getSamplerTexture2d() {
			if (tex.expired()) {
				auto rTex = getRawTexture2d4f();
				if (!rTex) return {};
				auto sTex = std::make_shared<render::SamplerTexture2d>(rTex->Width(), rTex->Height());
				sTex->SetImage(*rTex);
				sTex->SetMinFilter(minFilter);
				sTex->SetMagFilter(magFilter);
				tex = sTex;
				return sTex;
			}
			return std::static_pointer_cast<render::SamplerTexture2d>(tex.lock());
		}
	};

	class MeshResource {
		std::weak_ptr<std::vector<render::PointP3NTBUC>> rawmesh{};
		std::weak_ptr<render::Mesh> mesh{};
	public:
		static inline const std::string typeID = "Mesh";
		std::filesystem::path path{};
		std::string material{};

		bool setValue(const std::string& key, const std::string& value) {
			if (key == "path") {
				path = value;
				return true;
			}
			else if (key == "material") {
				material = value;
				return true;
			}
			return false;
		}
		std::shared_ptr<std::vector<render::PointP3NTBUC>> getRawMesh() {
			if (rawmesh.expired()) {
				std::fstream file{ path, std::ios::in };
				auto rMesh = std::make_shared<std::vector<render::PointP3NTBUC>>();
				if (path.extension() == ".obj" || path.extension() == ".mesh") *rMesh = render::PointP3NTBUC::ParseStream_obj(file);
				else return {};
				rawmesh = rMesh;
				return rMesh;
			}
			return rawmesh.lock();
		}
		std::shared_ptr<render::Mesh> GetMesh() {
			if (mesh.expired()) {
				auto m = std::make_shared<render::Mesh>();
				auto rMesh = getRawMesh();
				if (!rMesh) return {};
				m->set(*rMesh);
				mesh = m;
				return m;
			}
			return mesh.lock();
		}
	};

	class MaterialResource {
		std::weak_ptr<render::MaterialBase> material{};
	public:
	};

	class EntityBaseResource;

	class ResourceManager {
		static inline std::map<std::string, MeshResource> meshes;
		static inline std::map<std::string, TextureResource> textures;
		static inline std::map<std::string, EntityBaseResource*> entities;
		static inline std::map<std::string, std::filesystem::path> shaders;
		static inline std::map<std::string, std::filesystem::path> materials;
		static inline std::map<std::string, std::filesystem::path> fontMaps;

		template<typename T>
		static bool parseResource(T& outT, const std::string& body) {
			enum State {
				None,
				Comment,
				Key,
				Value,
			};
			std::string key = {};
			std::string value = {};
			State state = None;
			int i = 0;
			while (i < body.size()) {
				switch (state) {
				case None:
					if (body[i] == '#') state = Comment;
					else if (body[i] == '\n' || body[i] == '\t' || body[i] == ' ') {
						i++;
					}
					else state = Key;
					break;
				case Comment:
					if (body[i] == '\n') state = None;
					i++;
					break;
				case Key:
					for (; i < body.size(); i++) {
						if (body[i] == '=') {
							state = Value;
							i++;
							break;
						}
						if (body[i] == ' ' || body[i] == '\t') continue;
						key += body[i];
					}
					break;
				case Value:
					for (; i < body.size(); i++) {
						if (body[i] == ';' || body[i] == '\n') {
							state = None;
							break;
						}
						value += body[i];
					}
					for (; i < body.size() && (body[i] == ' ' || body[i] == '\t' || body[i] == '\n' || body[i] == ';'); i++);
					value = std::regex_replace(value, std::regex("^ +| +$|( ) +"), "$1");
					outT.setValue(key, value);
					key.clear();
					value.clear();
					break;
				}
			}
			return true;
		}
		static bool ParseBody(const std::string& type, const std::string& typeID, const std::string& body) {
			if (type == TextureResource::typeID) {
				TextureResource v;
				if (!parseResource<TextureResource>(v, body)) {
					STAMPSTACK();
					STAMPDMSG("resource::ResourceManager::Initialize - failed to parse item: " << type);
					return false;
				}
				std::string t = typeID;
				textures[t] = v;
			}
			else if (type == MeshResource::typeID) {
				MeshResource v;
				if (!parseResource<MeshResource>(v, body)) {
					STAMPSTACK();
					STAMPDMSG("resource::ResourceManager::Initialize - failed to parse item: " << type);
					return false;
				}
				std::string t = typeID;
				meshes[t] = v;
			}
			else {
				STAMPSTACK();
				STAMPDMSG("resource::ResourceManager::Initialize - failed to parse item: " << type);
			}

			return true;
		}
		static void LoadFile(std::string& file) {
			enum State {
				None,
				Comment,
				Type,
				TypeID,
				Body,
			};

			std::string body = {};
			std::string type{};
			std::string typeID{};
			State state = None;
			int i = 0;
			while (i < file.size()) {
				switch (state) {
				case None:
					if (file[i] == '#') state = Comment;
					else if (file[i] == '\n' || file[i] == '\t' || file[i] == ' ') {
						i++;
					}
					else state = Type;
					break;
				case Comment:
					if (file[i] == '\n') state = None;
					i++;
					break;
				case Type:
					for (; i < file.size(); i++) {
						if (file[i] == ' ' || file[i] == '\t') {
							state = TypeID;
							break;
						}
						type += file[i];
					}
					for (; i < file.size() && (file[i] == ' ' || file[i] == '\t'); i++);
					break;
				case TypeID:
					for (; i < file.size(); i++) {
						if (file[i] == ' ' || file[i] == '\t') {
							state = Body;
							break;
						}
						typeID += file[i];
					}
					for (; i < file.size() && (file[i] == ' ' || file[i] == '\t' || file[i] == '\n' || file[i] == '{'); i++);
					break;
				case Body: {
					int nesting = 1;
					for (; i < file.size(); i++) {
						if (file[i] == '{') {
							nesting++;
						}
						else if (file[i] == '}') {
							nesting--;
							if (nesting == 0) {
								state = None;
								i++;
								break;
							}
						}
						body += file[i];
					}
					if (!ParseBody(type, typeID, body)) return;
					type = {};
					typeID = {};
					body = {};
				} break;
				}
			}
		}
	public:
		static void Initialize() {
			if (!std::filesystem::exists("./resources/")) {
				std::cout << "[RESOURCE] resource script folder does not exist" << std::endl;
				return;
			}
			std::string buffer;
			for (auto const& entry : std::filesystem::recursive_directory_iterator("./resources/")) {
				if (entry.path().extension() == ".txt") {
					std::cout << "[RESOURCE] Loading resource file: " << entry.path().string() << std::endl;
					{
						std::fstream stream(entry.path().string(), std::ios::in);
						if (!stream) continue;
						stream.seekg(0, std::ios::end);
						size_t size = stream.tellg();
						buffer = std::string(size, ' ');
						stream.seekg(0, std::ios::beg);
						stream.read(&buffer[0], size);
					}
					LoadFile(buffer);
				}
			}
		}
		static inline TextureResource* GetTexture(const std::string& typeID) {
			TextureResource* tex = nullptr;
			for (auto& texture : textures) {
				if (texture.first == typeID) {
					tex = &texture.second;
					break;
				}
			}
			STAMPERROR(tex == nullptr, "resource::ResourceManager::GetTexture - texture not found.");
			return tex;
		}
		template<typename T>
		static inline T* GetEntity(const std::string& typeID) {
			EntityBaseResource* entity = nullptr;
			for (auto& v : entities) {
				if (v.first == typeID) {
					entity = v.second;
					break;
				}
			}
			STAMPERROR(entity == nullptr, "resource::ResourceManager::GetEntity - entity not found.");
			return (T*)entity;
		}
		template<typename T>
		static inline T* RegisterEntity(const std::string& typeID) {
			T* entity = nullptr;
			for (auto& v : entities) {
				if (v.first == typeID) {
					entity = (T*)v.second;
					break;
				}
			}
			if (entity == nullptr) {
				entity = (T*)(entities[typeID] = new T(typeID));
			}
			return entity;
		}
		static inline MeshResource* GetMesh(const std::string& typeID) {
			MeshResource* mesh = nullptr;
			for (auto& v : meshes) {
				if (v.first == typeID) {
					mesh = &v.second;
					break;
				}
			}
			STAMPERROR(mesh == nullptr, "resource::ResourceManager::GetMesh - texture not found.");
			return mesh;
		}
		static std::shared_ptr<render::ShaderProgramBase> GetShader(const std::string& typeID);
		static std::shared_ptr<render::FontMap> GetFontMap(const std::string& typeID);
	};

	class EntityBaseResource {
	public:
		static inline const std::string TypeID = "EntityBase";
		float mass = 1;
		bool isDynamic = true;
		std::string meshID{};
		std::string typeID{};

		EntityBaseResource(const std::string& typeID) : typeID(typeID) { }
	
		virtual int Index(lua_State* L) {
			std::string arg{ lua_tostring(L, 2) };
			if (arg == "mass") lua_pushnumber(L, mass);
			else if (arg == "isDynamic") lua_pushboolean(L, isDynamic);
			else if (arg == "mesh") lua_pushstring(L, meshID.c_str());
			else if (arg == "typeID") lua_pushstring(L, typeID.c_str());
			else return 0;
			return 1;
		}
		virtual int NewIndex(lua_State* L) {
			std::string arg{ lua_tostring(L, 2) };
			if (arg == "mass") mass = lua_tonumber(L, -1);
			else if (arg == "isDynamic") isDynamic = lua_toboolean(L, -1);
			else if (arg == "mesh") meshID = lua_tostring(L, -1);
			else return 0;
			return 1;
		}

		static inline int Register(lua_State* L) {
			if (lua_gettop(L) != 2) {
				luaL_error(L, "EntityBaseResource::Register - invalid number of arguments");
				return 0;
			}
			std::string arg{ lua_tostring(L, 2) };

			auto obj = (EntityBaseResource**)lua_newuserdata(L, sizeof(void*));
			*obj = ResourceManager::RegisterEntity<EntityBaseResource>(arg);
			lua_pushvalue(L, 1);
			lua_setmetatable(L, -2);
			return 1;
		}
		static inline int __index(lua_State* L) {
			if (lua_gettop(L) != 2) {
				luaL_error(L, "EntityBaseResource::__index - invalid number of arguments");
				return 0;
			}
			auto obj = (EntityBaseResource**)lua_touserdata(L, 1);

			if (!obj) {
				luaL_error(L, "EntityBaseResource::__index - invalid object");
				return 0;
			}
			return (*obj)->Index(L);
		}
		static inline int __newindex(lua_State* L) {
			if (lua_gettop(L) != 3) {
				luaL_error(L, "EntityBaseResource::__newindex - invalid number of arguments");
				return 0;
			}
			auto obj = (EntityBaseResource**)lua_touserdata(L, 1);

			if (!obj) {
				luaL_error(L, "EntityBaseResource::__newindex - invalid object");
				return 0;
			}
			return (*obj)->NewIndex(L);
		}

		static inline const luaL_Reg LuaReg[] = {
			{ "register", engine::resource::EntityBaseResource::Register},
			{ "__index", engine::resource::EntityBaseResource::__index},
			{ "__newindex", engine::resource::EntityBaseResource::__newindex},
			{ 0, 0 }
		};

		std::shared_ptr<render::Mesh> GetMesh() {
			auto ptr = engine::resource::ResourceManager::GetMesh(typeID);
			if (!ptr) return 0;
			return ptr->GetMesh();
		}
	};
}

export namespace engine {
	constexpr auto FloatToUN8(float value) { return (uint8_t)(value * 256); }

	int GetGameScreenWidth();
	int GetGameScreenHeight();
	int GetGameScreenRatio();

	enum struct RenderLayer {
		MainScene,
		GUI,
		Debug,
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
		bool IsActive() {
			return state == State::Running;
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
			if (IsEnabled()) {
				for (int i = 0; i < components.size(); i++) {
					if ((components[i]->enableState == EnableState::Enabling || components[i]->enableState == EnableState::Enabled) && components[i]->state == State::Running) {
						components[i]->OnDisable();
					}
				}
			}
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
			std::shared_ptr<T> component = std::make_shared<T>(param...);
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

	class SceneBase : public wm::RawSceneBase {
		static thread_local inline SceneBase* currentScene{};
		render::UniformBufferObject lightBuffer{};
		int maxRenderLayers = (int)RenderLayer::Max;
		std::vector<std::shared_ptr<GameObject>> objects{};
		std::shared_ptr<render::MaterialBase> blitMat{};
		std::shared_ptr<render::SamplerBase> whiteTex{};
		std::shared_ptr<render::SamplerBase> normTex{};
		render::UniformBufferObject blitCamera;
		render::UniformBufferObject blitObject;


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
		virtual void Render();
	protected:
		SceneBase(wm::Window* window) : wm::RawSceneBase(window) {
			objects.reserve(4096);
		}
		virtual void Initialize();
		virtual void Iterate() = 0;
		virtual void PreRender(RenderLayer renderLayer);
		virtual void PostRender(RenderLayer renderLayer);
		virtual void Resize(long width, long height);
		static std::shared_ptr<GameObject> CreateObject(std::string name, std::shared_ptr<GameObject> parent = nullptr) {
			std::shared_ptr<GameObject> obj{ new GameObject()};
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

		static inline render::UniformBufferObject* LightBuffer() {
			return &(currentScene->lightBuffer);
		}

		void SetPostProcessShader();
		void SetBlitMaterial(std::shared_ptr<render::MaterialBase> material) {
			blitMat = material;
		}

		friend SceneBase* CurrentScene();
		//friend wm::Window* CurrentWindow();
	};

	SceneBase* CurrentScene() {
		return SceneBase::currentScene;
	}

	std::shared_ptr<render::Mesh> getUIMesh() {
		static thread_local std::weak_ptr<render::Mesh> UIMesh{ };
		std::shared_ptr<render::Mesh> mesh;
		if (UIMesh.expired()) {
			mesh = std::make_shared<render::Mesh>();
			std::vector<render::PointP3NTBUC> points{};
			points.push_back(render::PointP3NTBUC{
				math::Vec3f{-1,-1,0},
				math::Vec3f{0,0,-1},
				math::Vec2f{0,0},
				math::Vec4f{1,1,1,1},
				});
			points.push_back(render::PointP3NTBUC{
				math::Vec3f{1,1,0},
				math::Vec3f{0,0,-1},
				math::Vec2f{1,1},
				math::Vec4f{1,1,1,1},
				});
			points.push_back(render::PointP3NTBUC{
				math::Vec3f{1,-1,0},
				math::Vec3f{0,0,-1},
				math::Vec2f{1,0},
				math::Vec4f{1,1,1,1},
				});
			points.push_back(render::PointP3NTBUC{
				math::Vec3f{-1,-1,0},
				math::Vec3f{0,0,-1},
				math::Vec2f{0,0},
				math::Vec4f{1,1,1,1},
				});
			points.push_back(render::PointP3NTBUC{
				math::Vec3f{-1,1,0},
				math::Vec3f{0,0,-1},
				math::Vec2f{0,1},
				math::Vec4f{1,1,1,1},
				});
			points.push_back(render::PointP3NTBUC{
				math::Vec3f{1,1,0},
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
			Secondary,
			Main,
			Editor,
		};
	private:
		CameraType type = CameraType::Secondary;
		math::Mat4f transform{};
		static inline std::vector<std::weak_ptr<Camera>> cameras {};
		static inline int currentCameraIndex = 0;
		static inline std::weak_ptr<Camera> mainCamera = {};
		int renderLayerBitMask = BITMASK(engine::RenderLayer::MainScene) | BITMASK(engine::RenderLayer::Debug) | BITMASK(engine::RenderLayer::GUI);
		int cameraIndex = -1;

		virtual void Start() {
			GLSTAMPERROR;
			frameBuffer.ResizeToScreen(scalePercent);
			GLSTAMPERROR;
			if (!mainCamera.lock()) {
				SetMainCamera();
			}
		}
		virtual void Update() {}
		virtual void Render(engine::RenderLayer renderLayer) {}
		virtual void SyncUpdate() {
			transform = GameObject()->transform.toMatrixInverse();
			for (std::shared_ptr<engine::GameObject> p = GameObject()->Parent(); p; p = p->Parent()) {
				transform = p->transform.toMatrixInverse() * transform;
			}

			auto c = mainCamera.lock();
			if (type == CameraType::Main && c.get() != this) {
				if (c) {
					c->type = CameraType::Secondary;
				}
				c = std::static_pointer_cast<Camera>(shared_from_this());
				engine::CurrentScene()->SetFramebuffer(frameBuffer.getId(),
					frameBuffer.colorAttachments[0].Width(),
					frameBuffer.colorAttachments[0].Height()
				);
				mainCamera = c;
			}
		}
		virtual void OnEnable() {
			cameraIndex = cameras.size();
			cameras.push_back(std::static_pointer_cast<Camera>(shared_from_this()));
		}
		virtual void OnDisable() {
			for (int i = 0; i < cameras.size(); i++) {
				if (cameras[i].lock().get() == this) {
					cameras.erase(cameras.begin() + i);
					break;
				}
			}
			cameraIndex = -1;
		}
		virtual void OnDestroy() {
			auto c = mainCamera.lock();
			if (c.get() == this) {
				mainCamera = {};
			}
		}
		void PreRender(RenderLayer renderLayer) {
			if (renderLayer != engine::RenderLayer::MainScene) return;
			if (!IsEnabled()) return;

			struct Data {
				math::GLmat4 transform{};
				math::GLmat4 perspective{};
				math::GLmat4 UI{};
				math::GLvec4 pos{};
			};
			Data k{};
			k.pos = (math::Vec4f)(GameObject()->globalPosition());
			k.transform = transform;
			if (isPerspective)
				k.perspective = math::Mat4f::Perspective(fov, GameRatio(), nearPlane, farPlane);
			else
				k.perspective = math::Mat4f::Orthographic(fov, GameRatio(), nearPlane, farPlane);
			k.UI = math::Mat4f::Orthographic(1, 1, 0, 10);
			cameraUniformObject.Set(&k, sizeof(k), render::BufferUsageHint::StreamDraw);
			cameraUniformObject.BindBuffer(render::UBO_CAMERA);
			frameBuffer.Bind();
			GLSTAMPERROR;
		}
		static void OnResize(int width, int height) {
		}
		static void PostRender(RenderLayer renderLayer) {

		}
	public:
		render::FrameBuffer2d frameBuffer{ {GL_RGBA8}};
		render::UniformBufferObject cameraUniformObject{};
		float fov = 60.0 * math::DEGTORAD;
		float nearPlane = 0.1;
		float farPlane = 5000;
		float scalePercent = 1.2;
		bool isPerspective = true;

		Camera() {
		}
		static std::shared_ptr<Camera> CurrentCamera() {
			return cameras[currentCameraIndex].lock();
		}
		static std::shared_ptr<Camera> MainCamera() {
			return mainCamera.lock();
		}
		static int GameWidth() {
			return CurrentCamera()->frameBuffer.colorAttachments[0].Width();
		}
		static int GameHeight() {
			return CurrentCamera()->frameBuffer.colorAttachments[0].Height();
		}
		static float GameRatio() {
			float height = GameHeight();
			float width = GameWidth();
			return (float)height / width;
		}
		static void ResizeScreen(int width, int height) {
			GLSTAMPERROR;
			CurrentCamera()->frameBuffer.Resize(width * CurrentCamera()->scalePercent, height * CurrentCamera()->scalePercent);
			wm::CurrentWindow()->SetClientSize(width, height);
			engine::CurrentScene()->SetFramebuffer(
				CurrentCamera()->frameBuffer.getId(),
				CurrentCamera()->frameBuffer.colorAttachments[0].Width(),
				CurrentCamera()->frameBuffer.colorAttachments[0].Height()
			);
			GLSTAMPERROR;
		}
		void ResizeDrawToScreen() {
			GLSTAMPERROR;
			frameBuffer.ResizeToScreen(scalePercent);
			GLSTAMPERROR;
		}
		void SetMainCamera() {
			type = CameraType::Main;
		}
	};

	class MeshRenderer final : public engine::Component {
		render::UBObject renderObject{};
		//sync safe
		virtual void Start() {
			UpdateRenderer();
		}
		//unsafe
		virtual void Update() {}
		//gl context safe
		virtual void Render(engine::RenderLayer renderLayer) {
			if (renderLayer != engine::RenderLayer::MainScene) return;
			GLSTAMPERROR
			if (material && mesh) {
				renderObject.BindBuffer(render::UBO_OBJECT);
				material->Render(mesh.get());
			}
		}
		//sync safe
		virtual void SyncUpdate() {
			struct MeshRenderer_t {
				math::GLmat4 transform;
			} mr;
			mr.transform = GameObject()->Transform();
			renderObject.Set(&mr, sizeof(mr));
		}
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
			renderObject.BindBuffer(render::UBO_OBJECT);
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

			ocean.Render(GameObject()->Transform());
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
		render::OceanRenderObject ocean;
	};

	class BillboardRenderer final : public engine::Component {
		std::shared_ptr<render::Mesh> mesh{};
		render::UBObject renderObject{};
		//sync safe
		virtual void Start() {
			mesh = engine::getUIMesh();
			UpdateRenderer();
		}
		//unsafe
		virtual void Update() {}
		//gl context safe
		virtual void Render(engine::RenderLayer renderLayer) {}
		//sync safe
		virtual void SyncUpdate() {
			struct Billboard_t {
				GLfloat depthLayer;
			};
			Billboard_t billboard{};

			renderObject.Set(&billboard, sizeof(Billboard_t), render::BufferUsageHint::DynamicDraw);
		}
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

		void UpdateRenderer() {
			material->UpdateMeshAttrib(mesh.get());
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
			X += (offsetX + width / 2 - (pivotX + 1) / 2 * width) / (right - left) * 2;
			Y += (offsetY + height / 2 - (pivotY + 1) / 2 * height) / (top - bottom) * 2;
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
		render::UBObject renderObject{};
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
				renderObject.BindBuffer(render::UBO_OBJECT);
				material->Render(mesh.get());
			}
		}
		//sync safe
		virtual void SyncUpdate() {
			struct MeshRenderer_t {
				math::GLmat4 transform;
			} mr;
			mr.transform = GameObject()->Transform();
			renderObject.Set(&mr, sizeof(mr));
		}
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
		render::UBObject renderObject{};
		//sync safe
		virtual void Start() {
			transform = GameObject()->GetComponent<TransformUI>();
			UpdateText();
		}
		//unsafe
		virtual void Update() {}
		//gl context safe
		virtual void Render(engine::RenderLayer renderLayer) {
			if (renderLayer != engine::RenderLayer::GUI) return;
			if (material && mesh) {
				renderObject.BindBuffer(render::UBO_OBJECT);
				glEnable(GL_BLEND);
				material->Render(&mesh);
				glDisable(GL_BLEND);
			}
		}
		//sync safe
		//sync safe
		virtual void SyncUpdate() {
			struct MeshRenderer_t {
				math::GLmat4 transform;
			} mr;
			mr.transform = GameObject()->Transform();
			renderObject.Set(&mr, sizeof(mr));
		}
		//sync safe
		virtual void OnEnable() {}
		//sync safe
		virtual void OnDisable() {}
		//sync safe
		virtual void OnDestroy() {}
	public:

		std::shared_ptr<render::UIMaterial> material{};
		std::string text = (const char*)u8"Test message.";
		std::shared_ptr<render::FontMap> fontMap{};
		int textAlign;
		float scale = 1;
		int lineHoriGap = 0;
		int lineVertGap = 2;
		float horiAlign = 0;
		float vertAlign = 1;
		void UpdateText() {
			if (!this->IsActive()) return;
			material->texture = fontMap->texture;
			std::vector<render::PointP3NTBUC> points{};
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
				points.push_back(render::PointP3NTBUC{
					math::Vec3f{x,y,0},
					math::Vec3f{0,0,0},
					math::Vec2f{item.uvTL},
					math::Vec4f{1,1,1,1},
					});
				points.push_back(render::PointP3NTBUC{
					math::Vec3f{x + w,y + h,0},
					math::Vec3f{0,0,0},
					math::Vec2f{item.uvBR},
					math::Vec4f{1,1,1,1},
					});
				points.push_back(render::PointP3NTBUC{
					math::Vec3f{x + w,y,0},
					math::Vec3f{0,0,0},
					math::Vec2f{item.uvTR},
					math::Vec4f{1,1,1,1},
					});
				points.push_back(render::PointP3NTBUC{
					math::Vec3f{x,y,0},
					math::Vec3f{0,0,0},
					math::Vec2f{item.uvTL},
					math::Vec4f{1,1,1,1},
					});
				points.push_back(render::PointP3NTBUC{
					math::Vec3f{x,y + h,0},
					math::Vec3f{0,0,0},
					math::Vec2f{item.uvBL},
					math::Vec4f{1,1,1,1},
					});
				points.push_back(render::PointP3NTBUC{
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
			for (int i = 0; i < points.size(); i++) {
				points[i].pos *= 2;
			}
			mesh.set(points, render::BufferUsageHint::DynamicDraw);
			material->UpdateMeshAttrib(&mesh);
		}
	};

	class SunLight final : public engine::Component {
		static inline std::vector<std::weak_ptr<SunLight>> sunlights {};

		friend engine::SceneBase;
		static std::vector<Light_t> GetLights() {
			/*std::vector<Light_t> lights{};
			for (int i = 0; i < sunlights.size(); i++) {
				Light_t v{};
				v.color = sunlights[i]->color;
				v.direction = sunlights[i]->GameObject()->Forward();
				v.magnitude = sunlights[i]->intensity;
				lights.push_back(v);
			}
			return lights;*/
			return {};
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

void engine::SceneBase::Render() {
	currentScene = this;
	GLSTAMPERROR;
	for (int c = 0; c < engine::component::Camera::cameras.size(); c++) {
		engine::component::Camera::currentCameraIndex = c;
		for (int p = 0; p < maxRenderLayers; p++) {
			if (!(engine::component::Camera::CurrentCamera()->renderLayerBitMask & BITMASK(p)))
				continue;

			PreRender((RenderLayer)p);
			for (int i = 0; i < objects.size(); i++) {
				objects[i]->Render((RenderLayer)p);
			}
			PostRender((RenderLayer)p);
		}
	}
	GLSTAMPERROR;
	engine::component::Camera::currentCameraIndex = engine::component::Camera::MainCamera()->cameraIndex;


	auto m = engine::getUIMesh();
	auto rect = this->Window()->GetNormalizedGameRect();
	math::Mat4f mat = math::Mat4f::Scale(rect.width, rect.height, 1);
	math::Mat4f cam = math::Mat4f::Identity();


	wm::RawSceneBase::Render();
}

void engine::SceneBase::Initialize() {
	resource::ResourceManager::Initialize();
	lua::LuaManager::Instance();

	bool init = []() -> bool {
		auto L = lua::LuaManager::Instance()->L;

		const luaL_Reg engineReg[] = {
			{ "DeltaTime", [](lua_State* L) -> int {
				lua_pushnumber(L, wm::CurrentWindow()->DeltaTime());
				return 1;
			}},
			{ 0, 0}
		};
		luaL_newlib(L, engineReg);
		lua_setglobal(L, "Engine");

		
		luaS2_registermetatable(L, engine::resource::EntityBaseResource);

		lua::LuaManager::Instance()->LoadDefaultFiles();
		return true;
	}();

	whiteTex = render::SamplerTexture2d::GetDefaultTexture();
	normTex = render::SamplerTexture2d::GetDefaultNormalMap();
}

void engine::SceneBase::PreRender(engine::RenderLayer renderLayer) {
	engine::component::Camera::CurrentCamera()->PreRender(renderLayer);

	GLSTAMPERROR;
	if (renderLayer == engine::RenderLayer::MainScene) {
		glClear(GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
		GLSTAMPERROR;
		std::vector<Light_t> light{};
		light.append_range(engine::component::SunLight::GetLights());
		size_t lightSize = sizeof(Light_t) * light.size();
		size_t lightSupplySize = sizeof(LightSupply) + lightSize;
		std::unique_ptr<LightSupply> lightSupply{ (LightSupply*)malloc(lightSupplySize) };
		lightSupply->length = light.size();
		memcpy(lightSupply->lights, light.begin()._Ptr, lightSize);
		lightBuffer.Set(lightSupply.get(), lightSupplySize, render::BufferUsageHint::DynamicDraw);
	}
	else if (renderLayer == engine::RenderLayer::Debug) {
		glClear(GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	}
	else if (renderLayer == engine::RenderLayer::GUI) {
		glClear(GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	}

}
void engine::SceneBase::PostRender(engine::RenderLayer renderLayer) {
	if (renderLayer == (engine::RenderLayer)((int)engine::RenderLayer::Max - 1)) {
		engine::component::Camera::PostRender(renderLayer);
	}
}
void engine::SceneBase::Resize(long width, long height) {
	engine::component::Camera::OnResize(width, height);
}