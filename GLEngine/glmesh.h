#pragma once
#include "glcore.h"
#include "glvec.h"
#include "glmat.h"
#include "glquat.h"

using namespace GLCore;
using namespace gl_math;

struct Material;

struct Transform final {
	Vec3 position {};
	Vec3 scale{ 1,1,1 };
	Quat rotation = Quat_Identity;

	void Rotate(float x, float y, float z) {
		rotation = (rotation * Quat::RotationZXY(x, y, z)).Unit();
	}

	Mat4 ToMatrix() const {
		return Mat4::Translate(position.x, position.y, position.z) * rotation.ToRotationMatrix() * Mat4::Scale(scale.x, scale.y, scale.z);
	}

	Mat4 ToMatrixInverse() const {
		return Mat4::Translate(-position.x, -position.y, -position.z) * rotation.Inverse().ToRotationMatrix() * Mat4::Scale(1 / scale.x, 1 / scale.y, 1 / scale.z);
	}

	Vec3 forward() {
		Vec4 v = rotation.ToRotationMatrix() * Vec3(0, 0, 1);
		return Vec3(v.x, v.y, v.z);
	}

	Vec3 back() {
		Vec4 v = rotation.ToRotationMatrix() * Vec3(0, 0, -1);
		return Vec3(v.x, v.y, v.z);
	}

	Vec3 left() {
		Vec4 v = rotation.ToRotationMatrix() * Vec3(-1, 0, 0);
		return Vec3(v.x, v.y, v.z);
	}

	Vec3 right() {
		Vec4 v = rotation.ToRotationMatrix() * Vec3(1, 0, 0);
		return Vec3(v.x, v.y, v.z);
	}

	Vec3 up() {
		Vec4 v = rotation.ToRotationMatrix() * Vec3(0, 1, 0);
		return Vec3(v.x, v.y, v.z);
	}

	Vec3 down() {
		Vec4 v = rotation.ToRotationMatrix() * Vec3(0, -1, 0);
		return Vec3(v.x, v.y, v.z);
	}
};

struct Texture final {
	friend Material;

private:
	GLuint texture = 0;
	size_t* refrenses = NULL;
public:
	Texture() {}
	Texture(size_t width, size_t height, int elementSize, GLenum type, const void* pixels) {
		GLenum v[] = { GL_LUMINANCE, GL_LUMINANCE_ALPHA, GL_RGB, GL_RGBA };
		glGenTextures(1, &texture);
		Bind();
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, v[elementSize - 1], type, pixels);

		refrenses = new size_t{1};
	}

	Texture(const Texture& v) {
		texture = v.texture;
		refrenses = v.refrenses;
		(*refrenses)++;
	}

	Texture(const Texture&& v) noexcept {
		texture = v.texture;
		refrenses = v.refrenses;
	}

	Texture& operator =(const Texture& v) {
		texture = v.texture;
		refrenses = v.refrenses;
		(*refrenses)++;
		return *this;
	}

	Texture& operator =(const Texture&& v) noexcept {
		texture = v.texture;
		refrenses = v.refrenses;
		return *this;
	}

	void Bind() {
		glBindTexture(GL_TEXTURE_2D, texture);
	}

	~Texture() {
		if (refrenses == NULL) return;
		if(--(*refrenses) == 0) {
			glDeleteTextures(1, &texture);
			texture = 0;
			delete refrenses;
		}
	}
};

struct Material {
	bool useVertexColor;
	bool useTexture;
	Vec3 ambientColor;
	Vec3 diffuseColor;
	Vec3 specularColor;
	float specularHighlight;
	Vec3 emissiveColor;
	Texture texture;

	void Bind() {
		if (useVertexColor) {
			glEnable(GL_COLOR_MATERIAL);
			glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
		}
		else {
			glDisable(GL_COLOR_MATERIAL);
			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, (float*)&ambientColor);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, (float*)&diffuseColor);
		}
		if (useTexture && texture.texture != 0) {
			texture.Bind();
			glEnable(GL_TEXTURE_2D);
		}
		else {
			glDisable(GL_TEXTURE_2D);
		}
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, (float*)&specularColor);
		glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, (int)(specularHighlight * 128));
		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, (float*)&emissiveColor);
	}
};

struct Vertex {
	Vec3 position;
	Vec3 color;
	Vec2 uv;
	Vec3 normal;
};

struct Mesh {
	Vertex* vertices;
	size_t vertices_length;

	void Render(const Mat4& transform) const {
		glMatrixMode(GL_MODELVIEW);
		glLoadMatrixf(transform);
		glVertexPointer(3, GL_FLOAT, sizeof(Vertex), (char*)vertices + offsetof(Vertex, position));
		glColorPointer(3, GL_FLOAT, sizeof(Vertex), (char*)vertices + offsetof(Vertex, color));
		glNormalPointer(GL_FLOAT, sizeof(Vertex), (char*)vertices + offsetof(Vertex, normal));
		glTexCoordPointer(2, GL_FLOAT, sizeof(Vertex), (char*)vertices + offsetof(Vertex, uv));
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glEnableClientState(GL_NORMAL_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glDrawArrays(GL_TRIANGLES, 0, vertices_length);
	}

	void GenNormals() {
		for (int i = 0; i < vertices_length; i += 3) {
			Vec3 a = vertices[i + 1].position - vertices[i].position;
			Vec3 b = vertices[i + 2].position - vertices[i].position;
			Vec3 c = Vec3::Cross(a, b).Normal();
			vertices[i].normal = c;
			vertices[i + 1].normal = c;
			vertices[i + 2].normal = c;
		}
	}
};