#pragma once
#include "dll.h"
#include <vector>
#include <exception>
#include "../math.hpp"
#include "../GLM/glm.h"
#include <utility>
#include <istream>

#define ATTRIBPOINTER_POSITION 0
#define ATTRIBPOINTER_NORMAL 1
#define ATTRIBPOINTER_UV 2
#define ATTRIBPOINTER_COLOR 3

namespace render {
	template<class P>
	struct RawMeshBase;

	struct PointPNUC final {
		math::Vec3f pos;
		math::Vec3f normal;
		math::Vec2f uv;
		math::Vec4f color;

		//function to descibe vertex attributes
		static void bindAttrib() {
			glVertexAttribPointer(ATTRIBPOINTER_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(PointPNUC), (void*)offsetof(PointPNUC, pos));
			glVertexAttribPointer(ATTRIBPOINTER_NORMAL, 3, GL_FLOAT, GL_TRUE, sizeof(PointPNUC), (void*)offsetof(PointPNUC, normal));
			glVertexAttribPointer(ATTRIBPOINTER_UV, 2, GL_FLOAT, GL_FALSE, sizeof(PointPNUC), (void*)offsetof(PointPNUC, uv));
			glVertexAttribPointer(ATTRIBPOINTER_COLOR, 4, GL_FLOAT, GL_FALSE, sizeof(PointPNUC), (void*)offsetof(PointPNUC, color));
		}
		static std::vector<PointPNUC> ParseStream_obj(std::istream data) {
			auto spos = data.tellg();
			std::vector<math::Vec3f> pos{};
			std::vector<math::Vec3f> normal{};
			std::vector<math::Vec4f> color{};
			std::vector<math::Vec2f> uv{};
			bool k = false;
			char line[1024];
			while ((bool)data) {
				data.getline(line, sizeof(line));
				float x;
				float y;
				float z;
				float w;
				float r;
				float g;
				float b;
				int i = sscanf_s(line, "v %f %f %f %f %f %f %f", &x, &y, &z, &w, &r, &g, &b);
				if (i >= 3) {
					k = true;
					pos.push_back({ x,y,z });
					if (i == 7)
						color.push_back({ r,g,b,1 });
					else
						color.push_back({ 1,1,1,1 });
				}
				else if (sscanf_s(line, "vt %f %f", &x, &y) == 2) {
					k = true;
					uv.push_back({ x,y });
				}
				else if (sscanf_s(line, "vn %f %f %f", &x, &y, &z) == 3) {
					k = true;
					normal.push_back({ x,y,z });
				}
			}
			data.seekg(spos);
			std::vector<PointPNUC> mesh{};
			std::vector<PointPNUC> points{};
			while ((bool)data) {
				data.getline(line, sizeof(line));
				points.clear();
				if (line[0] != 'f') continue;

				int p;
				int t;
				int n;
				int c;
				char* d = line + 1;
				while (sscanf_s(d, " %d/%d/%d%n", &p, &t, &n, &c) == 3) {
					d += c;
					PointPNUC point{};
					point.pos = pos[p - 1];
					point.color = color[p - 1];
					point.uv = uv[t - 1];
					point.normal = normal[n - 1];
					points.push_back(point);
				}
				while (sscanf_s(d, " %d//%d%n", &p, &n, &c) == 2) {
					d += c;
					PointPNUC point{};
					point.pos = pos[p - 1];
					point.color = color[p - 1];
					point.normal = normal[n - 1];
					points.push_back(point);
				}
				while (sscanf_s(d, " %d/%d%n", &p, &t, &c) == 2) {
					d += c;
					PointPNUC point{};
					point.pos = pos[p - 1];
					point.color = color[p - 1];
					point.uv = uv[t - 1];
					points.push_back(point);
				}
				while (sscanf_s(d, " %d%n", &p, &c) == 1) {
					d += c;
					PointPNUC point{};
					point.pos = pos[p - 1];
					point.color = color[p - 1];
					points.push_back(point);
				}
				for (int i = 1; i < points.size() - 1; i++) {
					mesh.push_back(points[0]);
					mesh.push_back(points[i]);
					mesh.push_back(points[i+1]);
				}
			}

			return mesh;
		}
	};


	
	class Mesh final {
		GLuint vbo = 0;
		GLuint ibo = 0;
	public:
		Mesh() {}
		Mesh(const Mesh& other) {
			if (!other.isValid()) return;
			GLint i;
			glGenBuffers(1, &vbo);
			glGenBuffers(1, &ibo);
			glBindBuffer(GL_COPY_READ_BUFFER, other.vbo);
			glGetBufferParameteriv(GL_COPY_READ_BUFFER, GL_BUFFER_SIZE, &i);
			glBindBuffer(GL_COPY_WRITE_BUFFER, vbo);
			glCopyBufferSubData(GL_COPY_READ_BUFFER, GL_COPY_WRITE_BUFFER, 0, 0, i);
			glBindBuffer(GL_COPY_READ_BUFFER, other.ibo);
			glGetBufferParameteriv(GL_COPY_READ_BUFFER, GL_BUFFER_SIZE, &i);
			glBindBuffer(GL_COPY_WRITE_BUFFER, ibo);
			glCopyBufferSubData(GL_COPY_READ_BUFFER, GL_COPY_WRITE_BUFFER, 0, 0, i);
		}

		void setVertices(void* ptr, size_t size, GLenum usageHint = GL_STATIC_DRAW) {
			if (vbo == 0) {
				glGenBuffers(1, &vbo);
			}
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glBufferData(GL_ARRAY_BUFFER, size, ptr, usageHint);
		}
		void setIndices(void* ptr, size_t size, GLenum usageHint = GL_STATIC_DRAW) {
			if (ibo == 0) {
				glGenBuffers(1, &ibo);
			}
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, ptr, usageHint);
		}
		void bind() {
			if (!isValid()) throw new std::exception("render::Mesh::bind - failed to bind mesh: mesh does not have assigned buffers.");
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		}

		bool isValid() const {
			return vbo != 0 && ibo != 0;
		}
		operator bool() {
			return isValid();
		}
		~Mesh() {
			glDeleteBuffers(1, &vbo);
			vbo = 0;
			glDeleteBuffers(1, &ibo);
			ibo = 0;
		}
	};

	class RawShaderComponent final {
		GLuint shader = 0;
	public:
		RawShaderComponent() {}
		void compile(GLenum type, const char* source) {
			shader = glCreateShader(type);
			glShaderSource(shader, 1, &source, NULL);
			GLint compiled;
			GLchar message[1024];
			GLsizei log_length = 0;
			glCompileShader(shader);
			glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
			if (compiled != GL_TRUE) {
				glGetShaderInfoLog(shader, sizeof(message), &log_length, message);
				throw new std::exception(message);
			}
		}
		GLuint getShader() const {
			return shader;
		}

		~RawShaderComponent() {
			if (shader == 0) return;
			glDeleteShader(shader);
		}
	};
	class ShaderBase {
		GLuint program = 0;
	public:
		ShaderBase() {}
		void attachShader(size_t shaderCount, const RawShaderComponent* shaderComponents) {
			GLint compiled;
			GLchar message[1024];
			GLsizei log_length = 0;

			program = glCreateProgram();
			for (int i = 0; i < shaderCount; i++)
				glAttachShader(program, shaderComponents[i].getShader());
			glLinkProgram(program);

			glGetProgramiv(program, GL_LINK_STATUS, &compiled);
			if (compiled != GL_TRUE) {
				glGetProgramInfoLog(program, 1024, &log_length, message);
				throw new std::exception(message);
			}
		}
		void bind() {
			glUseProgram(program);
		}
		bool isValid() {
			return program != 0;
		}
		virtual ~ShaderBase() {
			if (program == 0) return;
			glDeleteProgram(program);
		}
	};
	class RenderShader : public ShaderBase {
		void attachShader(RawShaderComponent& vertexComponent, RawShaderComponent& fragmentComponent) {
			RawShaderComponent arr[2]{ vertexComponent, fragmentComponent };
			ShaderBase::attachShader(2, arr);
		}
	};

	class MaterialBase {
		GLuint vao = 0;
		RenderShader shader{};
	public:
		MaterialBase() {}
		//attributes
		//deconstructor
		template<class P>
		void bindAttrib() {
			if (vao == 0) glGenVertexArrays(1, &vao);
			glBindVertexArray(vao);
			bindGenericAttrib();
			P::bindAttrib();
		}
		virtual void bindGenericAttrib() {
			glVertexAttrib3f(ATTRIBPOINTER_NORMAL, 0, 0, 0);//normal
			glVertexAttrib2f(ATTRIBPOINTER_UV, 0, 0);//uv
			glVertexAttrib4f(ATTRIBPOINTER_COLOR, 1, 1, 1, 1);//color
		}
		void bind() {
			if (!isValid()) throw new std::exception("failed to bind mesh: mesh does not have allocated buffers.");
			glBindVertexArray(vao);
			shader.bind();
		}
		bool isValid() {
			return vao != 0 && shader.isValid();
		}
	};
	class SolidMaterial {
		math::Vec4f color;

		SolidMaterial() {}
		virtual void bindGenericAttrib() {
			glVertexAttrib3f(ATTRIBPOINTER_NORMAL, 0, 0, 0);
			glVertexAttrib2f(ATTRIBPOINTER_UV, 0, 0);
			glVertexAttrib4fv(ATTRIBPOINTER_COLOR, (float*)color);
		}
	};
	
	//https://en.wikipedia.org/wiki/BMP_file_format
	template<typename T, GLenum format, GLenum type>
	class RawTexture2dBase {
		std::vector<T> data{};
		size_t width = 0;
		size_t height = 0;
	public:
		RawTexture2dBase() {}
		RawTexture2dBase(size_t width, size_t height) {
			data = std::vector<T>(width * height);
			this->width = width;
			this->height = height;
		}
		void SetPixel(size_t x, size_t y, const T& v) {
			data[x + y * width] = v;
		}
		T getPixel(size_t x, size_t y) {
			return data[x + y * width];
		}
		void SetImage(size_t length, const T* list) {
			if (length < width * height) throw std::exception("render::RawTextureBase::SetImage - length cant be less than width*height.");
			for (int i = 0; i < width * height; i++) {
				data[i] = list[i];
			}
		}
		void SetSubImage(size_t x, size_t y, size_t width, size_t height, size_t length, const T* list) {
			if (length < width * height) throw std::exception("render::RawTextureBase::SetImage - length cant be less than width*height.");
			for (size_t Y = 0; Y < height; Y++) {
				for (size_t X = 0; X < width; X++) {
					size_t i = X + Y * width;
					size_t j = (X + x) + (Y + y) * this->width;
					data[j] = list[i];
				}
			}
		}
		size_t Width() { return width; }
		size_t Height() { return height; }
		void* GetData() { return &(data[0]); }

		//get subImage
	};

	class RawTexture2d4f : public RawTexture2dBase<math::Vec4f, GL_RGBA, GL_RGBA8> {
	public:
		RawTexture2d4f() : RawTexture2dBase() {}
		RawTexture2d4f(size_t width, size_t height) : RawTexture2dBase(width, height) {}
		static RawTexture2d4f ParseStream_bmp(std::istream data) {
			if (!data || data.get() != 'B' || data.get() != 'M') return {};//0,1
			uint32_t bmpSize;
			data.read((char*)&bmpSize, sizeof(uint32_t));//2-6
			data.seekg(10);
			uint32_t bmpDataOffset;
			data.read((char*)&bmpDataOffset, sizeof(uint32_t));//10-14
			uint32_t headerSize;
			data.read((char*)&headerSize, sizeof(uint32_t));//14-18
			std::streampos palleteArray = headerSize + 14;
			uint32_t width = 0, height = 0, bpp = 0, compression = 0, imageSize = 0, paletteCount = 0;
			if (headerSize == 40 || headerSize == 52 || headerSize == 124) {
				data.read((char*)&width, sizeof(uint32_t));//18-22
				data.read((char*)&height, sizeof(uint32_t));//22-26
				data.seekg(28);
				data.read((char*)&bpp, sizeof(uint16_t));//28-30
				data.read((char*)&compression, sizeof(uint32_t));//30-34
				data.read((char*)&imageSize, sizeof(uint32_t));//34-38
				data.seekg(46);
				data.read((char*)&paletteCount, sizeof(uint32_t));//46-50
			}
			else return {};
			uint32_t maskA = 0;
			uint32_t maskR = 0xFF;
			uint32_t maskG = 0xFF;
			uint32_t maskB = 0xFF;
			int shiftA = 0;
			int shiftR = 16;
			int shiftG = 8;
			int shiftB = 0;
			if (compression != 0) {
				if (compression == 3 || compression == 6) {
					data.seekg(54);
					data.read((char*)&maskR, sizeof(uint32_t));//54-58
					data.read((char*)&maskG, sizeof(uint32_t));//58-62
					data.read((char*)&maskB, sizeof(uint32_t));//62-66
					data.read((char*)&maskA, sizeof(uint32_t));//66-70
				}

				shiftA = 0;
				shiftR = 0;
				shiftG = 0;
				shiftB = 0;

				for (; maskR && !(maskR & 1); maskR >>= 1)shiftR++;
				for (; maskG && !(maskG & 1); maskG >>= 1)shiftG++;
				for (; maskB && !(maskB & 1); maskB >>= 1)shiftB++;
				for (; maskA && !(maskA & 1); maskA >>= 1)shiftA++;
			}

			RawTexture2d4f tex{width,height};
			int rowSize = ((bpp * width + 31) / 32) * 4;
			if (bpp == 8) {
				std::vector<math::Vec4i> pallete = {};
			}
			else if (bpp == 16) {
				for (uint32_t y = 0; y < height; y++) {
					data.seekg(bmpDataOffset);
					for (uint32_t x = 0; x < width; x++) {
						uint32_t v;
						data.read((char*)&v, sizeof(uint16_t));
						float r = maskR ? (float)((v >> shiftR) & maskR) / maskR : 0;
						float g = maskG ? (float)((v >> shiftG) & maskG) / maskG : 0;
						float b = maskB ? (float)((v >> shiftB) & maskB) / maskB : 0;
						float a = maskA ? (float)((v >> shiftA) & maskA) / maskA : 1;
						tex.SetPixel(x,y,{r,g,b,a});
					}
					bmpDataOffset += rowSize;
				}
			}
			else if (bpp == 24) {
				for (uint32_t y = 0; y < height; y++) {
					data.seekg(bmpDataOffset);
					for (uint32_t x = 0; x < width; x++) {
						uint32_t v;
						data.read((char*)&v, sizeof(3));
						float r = maskR ? (float)((v >> shiftR) & maskR) / maskR : 0;
						float g = maskG ? (float)((v >> shiftG) & maskG) / maskG : 0;
						float b = maskB ? (float)((v >> shiftB) & maskB) / maskB : 0;
						float a = maskA ? (float)((v >> shiftA) & maskA) / maskA : 1;
						tex.SetPixel(x, y, { r,g,b,a });
					}
					bmpDataOffset += rowSize;
				}
			}
			else if (bpp == 32) {
				for (uint32_t y = 0; y < height; y++) {
					data.seekg(bmpDataOffset);
					for (uint32_t x = 0; x < width; x++) {
						uint32_t v;
						data.read((char*)&v, sizeof(uint32_t));
						float r = maskR ? (float)((v >> shiftR) & maskR) / maskR : 0;
						float g = maskG ? (float)((v >> shiftG) & maskG) / maskG : 0;
						float b = maskB ? (float)((v >> shiftB) & maskB) / maskB : 0;
						float a = maskA ? (float)((v >> shiftA) & maskA) / maskA : 1;
						tex.SetPixel(x, y, { r,g,b,a });
					}
					bmpDataOffset += rowSize;
				}
			}

			return tex;
		}
	};

	//The texture minifying function is used whenever the level-of-detail function used when sampling from the texture determines that the texture should be minified. There are six defined minifying functions. Two of them use either the nearest texture elements or a weighted average of multiple texture elements to compute the texture value. The other four use mipmaps.
	enum struct TextureMinFilter {
		//Returns the value of the texture element that is nearest (in Manhattan distance) to the specified texture coordinates.
		Nearest = GL_NEAREST,
		//Returns the weighted average of the four texture elements that are closest to the specified texture coordinates. These can include items wrapped or repeated from other parts of a texture, depending on the values of GL_TEXTURE_WRAP_S and GL_TEXTURE_WRAP_T, and on the exact mapping.
		Linear = GL_LINEAR,
		//Chooses the mipmap that most closely matches the size of the pixel being textured and uses the GL_NEAREST criterion (the texture element closest to the specified texture coordinates) to produce a texture value.
		NearestMipmapNearest = GL_NEAREST_MIPMAP_NEAREST,
		//Chooses the mipmap that most closely matches the size of the pixel being textured and uses the GL_LINEAR criterion (a weighted average of the four texture elements that are closest to the specified texture coordinates) to produce a texture value.
		LinearMipmapNearest = GL_LINEAR_MIPMAP_NEAREST,
		//Chooses the two mipmaps that most closely match the size of the pixel being textured and uses the GL_NEAREST criterion (the texture element closest to the specified texture coordinates ) to produce a texture value from each mipmap. The final texture value is a weighted average of those two values.
		NearestMipmapLinear = GL_NEAREST_MIPMAP_LINEAR,
		//Chooses the two mipmaps that most closely match the size of the pixel being textured and uses the GL_LINEAR criterion (a weighted average of the texture elements that are closest to the specified texture coordinates) to produce a texture value from each mipmap. The final texture value is a weighted average of those two values.
		LinearMipmapLinear = GL_LINEAR_MIPMAP_LINEAR,
	};
	//The texture magnification function is used whenever the level-of-detail function used when sampling from the texture determines that the texture should be magified. It sets the texture magnification function to either GL_NEAREST or GL_LINEAR (see below). GL_NEAREST is generally faster than GL_LINEAR, but it can produce textured images with sharper edges because the transition between texture elements is not as smooth. The initial value of GL_TEXTURE_MAG_FILTER is GL_LINEAR.
	enum struct TextureMagFilter {
		//Returns the value of the texture element that is nearest (in Manhattan distance) to the specified texture coordinates.
		Nearest = GL_NEAREST,
		//Returns the weighted average of the texture elements that are closest to the specified texture coordinates. These can include items wrapped or repeated from other parts of a texture, depending on the values of GL_TEXTURE_WRAP_S and GL_TEXTURE_WRAP_T, and on the exact mapping.
		Linear = GL_LINEAR,
	};

	template<GLenum target>
	class TextureBase {
	internal:
		GLuint textureID = 0;
	public:
		//runtime gen object id
		//get atribtues
		//set atributes
		//runtime conversiion between raw and texture
		//copy
		//assignemnt
		TextureBase() {}

		~TextureBase() {
			if (textureID == 0) return;
			glDeleteTextures(1, &textureID);
			textureID = 0;
		}

		void InitTexture() {
			if (textureID == 0) {
				glGenTextures(1, &textureID);
			}
		}

		void Bind() {
			if (textureID == 0) throw new std::exception("render::TextureBase::Bind - uninitialized texture, attempted access failed.");
			glBindTexture(target, textureID);
		}

		void SetMinFilter(TextureMinFilter minFilter) {
			if (textureID == 0) throw new std::exception("render::TextureBase::SetMinFilter - uninitialized texture, attempted modification failed.");
			glBindTexture(target, textureID);
			glTextureParameteri(target, GL_TEXTURE_MIN_FILTER, (int)minFilter);
		}
		void SetMagFilter(TextureMagFilter magFilter) {
			if (textureID == 0) throw new std::exception("render::TextureBase::SetMagFilter - uninitialized texture, attempted modification failed.");
			glBindTexture(target, textureID);F
			glTextureParameteri(target, GL_TEXTURE_MIN_FILTER, (int)magFilter);
		}
		TextureMinFilter GetMinFilter() {
			if (textureID == 0) throw new std::exception("render::TextureBase::GetMinFilter - uninitialized texture, attempted information retrieval failed.");
			int k;
			glGetTexParameteriv(target, GL_TEXTURE_MIN_FILTER, &k);
			return (TextureMinFilter)k;
		}
		TextureMagFilter GetMagFilter() {
			if (textureID == 0) throw new std::exception("render::TextureBase::GetMinFilter - uninitialized texture, attempted information retrieval failed.");
			int k;
			glGetTexParameteriv(target, GL_TEXTURE_MAG_FILTER, &k);
			return (TextureMagFilter)k;
		}
	};
}

//post process shader
//compute shader
//texture
//text texture
//text to mesh
//mesh renderer
//ui mesh renderer
