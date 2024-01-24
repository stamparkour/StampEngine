#pragma once
#include <Windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include "glvec.h"
#include "glmat.h"
#include "glquat.h"
#include "gamecore.h"
#include "xptr.h"

namespace game_component {
	struct MeshRenderer;
	struct Camera;
}

namespace game_render {

	struct Material;

	class Texture final: private xptr_base<GLuint> {
		size_t width;
		size_t height;
		friend Material;
		void Bind() const;
	public:
		Texture();
		Texture(size_t width, size_t height, int elementSize, GLenum type, const void* pixels);
		Texture(const Texture& v);
		Texture(Texture&& v) noexcept;
		Texture& operator =(const Texture& v);
		Texture& operator =(Texture&& v) noexcept;
		operator bool() const;
		friend void swap(Texture& a, Texture& b);
		size_t Width() const;
		size_t Height() const;
		void setPixels(int elementSize, GLenum type, const void* pixels);
		~Texture();
		static Texture BmpTexture(const char* data);
	};

	struct Material final {
		bool useVertexColor;
		bool useTexture;
		gl_math::Vec4 ambientColor;
		gl_math::Vec4 diffuseColor;
		gl_math::Vec4 specularColor;
		float specularHighlight;
		gl_math::Vec4 emissiveColor;
		Texture texture;
		static Material defaultMaterial;

		void Bind() const;
	};

	struct Mesh final {
		friend struct game_component::MeshRenderer;
		xptr<gl_math::Vec3> vert_positions;
		xptr<gl_math::Vec3> vert_normals;
		xptr<gl_math::Vec4> vert_colors;
		xptr<gl_math::Vec2> vert_uvs;
		size_t vertices_length;
		void GenNormals();
		static Mesh cubePrimative;
	private:
		void Render(const gl_math::Mat4& transform) const;
	};
}
namespace game_component {
	struct MeshRenderer final : game_core::Component {
		Component_Requirements(MeshRenderer)
		MeshRenderer() : game_core::Component() {}
		game_render::Mesh* mesh{};
		game_render::Material* material{};
		void OnRender(game_core::GameObject& gameObject) override;
	};

	struct Camera final : game_core::Component {
		Component_Requirements(Camera)
	private:
		gl_math::Mat4 camera;
	public:
		float fovy;
		float nearPlane;
		float farPlane;
		Camera() noexcept;
		Camera(float fovy, float nearPlane, float farPlane) noexcept;
		void OnResize(game_core::GameObject& gameObject) override;
		void OnRender(game_core::GameObject& gameObject) override;
	};

	struct SunLight final : game_core::Component {
		Component_Requirements(SunLight)
	private:
		int index;
	public:
		gl_math::Vec4 ambientColor;
		gl_math::Vec4 diffuseColor;
		gl_math::Vec4 specularColor;
		SunLight();
		SunLight(gl_math::Vec4 color);
		SunLight(gl_math::Vec4 ambientColor, gl_math::Vec4 diffuseColor, gl_math::Vec4 specularColor);
		void OnRender(game_core::GameObject& gameObject) override;
		void OnEnabled(game_core::GameObject& gameObject) override;
		void OnDisabled(game_core::GameObject& gameObject) override;
	};
}