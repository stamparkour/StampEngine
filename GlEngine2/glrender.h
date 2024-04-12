#pragma once
#include <Windows.h>
#include "gl.h"
#include "glvec.h"
#include "glmat.h"
#include "glquat.h"
#include "gamecore.h"
#include <memory>

namespace game::component {
	struct MeshRenderer;
	struct ShadowRenderer;
	struct Camera;
}

namespace game::render {

	struct Material;

	struct TextureBase {
	private:
		friend Material;
		virtual GLuint Id() const = 0;
	public:
		friend Material;
		virtual void Bind() const = 0;
		virtual size_t Width() const = 0;
		virtual size_t Height() const = 0;
		virtual ~TextureBase() {}
	};

	class Texture final : public TextureBase {
		size_t width;
		size_t height;
		GLuint id;
		GLuint Id() const override;
	public:
		Texture();
		Texture(size_t width, size_t height, int elementSize, GLenum type, const void* pixels);
		size_t Width() const override;
		size_t Height() const override;
		void Bind() const override;
		void setPixels(int elementSize, GLenum type, const void* pixels);
		static std::shared_ptr <Texture> BmpTexture(const char* data);
		~Texture() override;
	};

	class AnimatedTexture final : public TextureBase {
		size_t width;
		size_t height;
		int frames;
		double delay;
		std::unique_ptr<GLuint> id;
		void Bind() const override;
		GLuint Id() const override;
	public:
		AnimatedTexture();
		size_t Width() const override;
		size_t Height() const override;
		void setPixels(int elementSize, GLenum type, const void* pixels);
		static std::shared_ptr <Texture> BmpTexture(const char* data);
	};

	struct Material final {
		bool useVertexColor;
		bool useTexture;
		bool applyShadow{};
		bool transparent;
		game::math::Vec4 ambientColor;
		game::math::Vec4 diffuseColor;
		game::math::Vec4 specularColor;
		float specularHighlight;
		game::math::Vec4 emissiveColor;
		std::shared_ptr<TextureBase> texture;
		static Material defaultMaterial;
		static Material shadowMaterial;
		static Material fontMaterial;

		static std::shared_ptr<Material> ParseMaterial(std::istream& stream);

		void Bind() const;
	};

	struct MeshBase {
	public:
		virtual void Render(const game::math::Mat4& transform) const = 0;
	};

	struct Mesh final : MeshBase {
		friend struct game::component::MeshRenderer;
		friend struct game::component::ShadowRenderer;
		std::shared_ptr<game::math::Vec3> vert_positions{};
		std::shared_ptr<game::math::Vec3> vert_normals{};
		std::shared_ptr<game::math::Vec4> vert_colors{};
		std::shared_ptr<game::math::Vec2> vert_uvs{};
		size_t vertices_length = 0;
		Mesh() {}
		Mesh(std::shared_ptr<game::math::Vec3> vert_positions, std::shared_ptr<game::math::Vec3> vert_normals, std::shared_ptr<game::math::Vec4> vert_colors, std::shared_ptr<game::math::Vec2> vert_uvs, size_t vertices_length) :
			vert_positions(vert_positions), vert_normals(vert_normals), vert_colors(vert_colors), vert_uvs(vert_uvs), vertices_length(vertices_length)
		{}
		void GenNormals();
		static std::shared_ptr< game::render::Mesh> cubePrimative;
		static std::shared_ptr<game::render::Mesh> ObjMesh(const char* data);
	private:
		void Render(const game::math::Mat4& transform) const override;
	};
	struct FontMap {
		std::shared_ptr<game::math::Rect> positions;
		size_t length;
		std::shared_ptr<game::render::TextureBase> textures;

		static std::shared_ptr<FontMap> ParseMap(const char* txt, std::shared_ptr<game::render::TextureBase> ref);
	};

	enum struct TextAlignment {
		TopLeft,
	};
}
namespace game::component {
	struct MeshRenderer final : game::core::Component {
		Component_Requirements(MeshRenderer)
		MeshRenderer() : game::core::Component() {}
		std::shared_ptr<game::render::MeshBase> mesh{};
		std::shared_ptr<game::render::Material> material{};
		void OnRender(int phase) override;
	};
	class TextRenderer final : public game::core::Component {
		Component_Requirements(TextRenderer)
		std::shared_ptr<game::math::Vec3> vert_positions{};
		std::shared_ptr<game::math::Vec3> vert_normals{};
		std::shared_ptr<game::math::Vec2> vert_uvs{};
		size_t vertices_length = 0;
		game::render::Material material = game::render::Material::fontMaterial;
	public:
		std::shared_ptr<game::render::FontMap> map;
		TextRenderer() : game::core::Component() {}
		void setText(const char* txt, float scale = 1, float horizGap = 0, float vertGap = 2, game::render::TextAlignment alignment = game::render::TextAlignment::TopLeft);
		void OnRender(int phase) override;
	};
	struct UIRenderer final : game::core::Component {
		Component_Requirements(UIRenderer)
			UIRenderer() : game::core::Component() {}
		bool applyShadow{};
		std::shared_ptr<game::render::MeshBase> mesh{};
		game::render::Material material{};
		void OnRender(int phase) override;
	};
	struct RectTransform final : game::core::Component {
		Component_Requirements(RectTransform)
	public:
		game::math::Vec2 alignment;
		float left;
		float right;
		void Update() override;
	};

	struct ShadowRenderer final : game::core::Component {
		Component_Requirements(ShadowRenderer)
	private:
		game::render::Material* material = &game::render::Material::shadowMaterial;
	public:
		ShadowRenderer() : game::core::Component() {}
		game::render::Mesh* mesh{};
		void OnRender(int phase) override;
	};

	struct Camera final : game::core::Component {
		Component_Requirements(Camera)
	private:
		game::math::Mat4 camera;
	public:
		float fovy;
		float nearPlane;
		float farPlane;
		Camera() noexcept;
		Camera(float fovy, float nearPlane, float farPlane) noexcept;
		void OnResize() override;
		void OnRender(int phase) override;
	};

	struct SunLight final : game::core::Component {
		Component_Requirements(SunLight)
	private:
		int index;
	public:
		game::math::Vec4 ambientColor;
		game::math::Vec4 diffuseColor;
		game::math::Vec4 specularColor;
		bool isShadowLight;
		SunLight();
		SunLight(game::math::Vec4 color);
		SunLight(game::math::Vec4 ambientColor, game::math::Vec4 diffuseColor, game::math::Vec4 specularColor);
		void OnRender(int phase) override;
		void OnEnabled() override;
		void OnDisabled() override;
	};
}