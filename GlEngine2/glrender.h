#pragma once
#include <Windows.h>
#include "gl.h"
#include "glvec.h"
#include "glmat.h"
#include "glquat.h"
#include "gamecore.h"
#include "xptr.h"

namespace game_component {
	struct MeshRenderer;
	struct ShadowRenderer;
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
		static Material shadowMaterial;

		void Bind() const;
	};

	struct MeshBase {
	public:
		virtual void Render(const gl_math::Mat4& transform) const = 0;
	};

	struct Mesh final : MeshBase {
		friend struct game_component::MeshRenderer;
		friend struct game_component::ShadowRenderer;
		xptr<gl_math::Vec3> vert_positions{};
		xptr<gl_math::Vec3> vert_normals{};
		xptr<gl_math::Vec4> vert_colors{};
		xptr<gl_math::Vec2> vert_uvs{};
		size_t vertices_length = 0;
		Mesh() {}
		Mesh(xptr<gl_math::Vec3> vert_positions, xptr<gl_math::Vec3> vert_normals, xptr<gl_math::Vec4> vert_colors, xptr<gl_math::Vec2> vert_uvs, size_t vertices_length) :
			vert_positions(vert_positions), vert_normals(vert_normals), vert_colors(vert_colors), vert_uvs(vert_uvs), vertices_length(vertices_length)
		{}
		void GenNormals();
		static Mesh cubePrimative;
		static Mesh ObjMesh(const char* data);
	private:
		void Render(const gl_math::Mat4& transform) const override;
	};
}
namespace game_component {
	struct MeshRenderer final : game_core::Component {
		Component_Requirements(MeshRenderer)
		MeshRenderer() : game_core::Component() {}
		bool applyShadow{};
		game_render::MeshBase* mesh{};
		game_render::Material material{};
		void OnRender(int phase) override;
	};

	struct ShadowRenderer final : game_core::Component {
		Component_Requirements(ShadowRenderer)
	private:
		game_render::Material* material = &game_render::Material::shadowMaterial;
	public:
		ShadowRenderer() : game_core::Component() {}
		game_render::Mesh* mesh{};
		void OnRender(int phase) override;
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
		void OnResize() override;
		void OnRender(int phase) override;
	};

	struct SunLight final : game_core::Component {
		Component_Requirements(SunLight)
	private:
		int index;
	public:
		gl_math::Vec4 ambientColor;
		gl_math::Vec4 diffuseColor;
		gl_math::Vec4 specularColor;
		bool isShadowLight;
		SunLight();
		SunLight(gl_math::Vec4 color);
		SunLight(gl_math::Vec4 ambientColor, gl_math::Vec4 diffuseColor, gl_math::Vec4 specularColor);
		void OnRender(int phase) override;
		void OnEnabled() override;
		void OnDisabled() override;
	};
}