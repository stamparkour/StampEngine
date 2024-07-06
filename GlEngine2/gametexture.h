#pragma once
#include "gl.h"

namespace game::render {
	struct TextureBase {
		friend struct Material;
	private:
		virtual GLuint Id() const = 0;
	public:
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
		void setPixels(int x, int y, int w, int h, int elementSize, GLenum type, const void* pixels);
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
}