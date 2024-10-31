#pragma once
#include "dll.h"
#include "math.hpp"
#include "glm.h"
#include <vector>
#include <exception>
#include <utility>
#include <istream>
#include <mutex>
#include <assert.h>
#include "SWM.hpp"

#define ATTRIBPOINTER_POSITION 0
#define ATTRIBPOINTER_NORMAL 1
#define ATTRIBPOINTER_UV 2
#define ATTRIBPOINTER_COLOR 3

namespace render {
	enum struct BufferUsageHint : GLenum {
		StreamDraw = GL_STREAM_DRAW,
		StreamRead = GL_STREAM_READ,
		StreamCopy = GL_STREAM_COPY,
		StaticDraw = GL_STATIC_DRAW,
		StaticRead = GL_STATIC_READ,
		StaticCopy = GL_STATIC_COPY,
		DynamicDraw = GL_DYNAMIC_DRAW,
		DynamicRead = GL_DYNAMIC_READ,
		DynamicCopy = GL_DYNAMIC_COPY,
	};
	class Mesh;
	class RawMeshBase {
		friend class Mesh;
	protected:
		//mutex accessable to mesh to lock.
		//copy constructor use 
		//std::lock_guard
		virtual void setMesh(Mesh& mesh, BufferUsageHint hint) const = 0;
		virtual GLenum glRenderMode() const = 0;
		virtual size_t vertexCount() const = 0;
	public:
		virtual ~RawMeshBase() {}
	};

	//get value not pointer
	//set functions that are mutex controlled
	//
	class RawMeshP3NUC final : public RawMeshBase {
	public:
		struct Point final {
			math::Vec3f pos;
			math::Vec3f normal;
			math::Vec2f uv;
			math::Vec4f color;

			Point() = default;
			Point(const math::Vec3f pos, const math::Vec3f normal, const math::Vec2f uv, const math::Vec4f color)
				: pos(pos), normal(normal), uv(uv), color(color) { }
		};
	private:
		std::vector<RawMeshP3NUC::Point> points{};
	public:

		RawMeshP3NUC() = default;
		RawMeshP3NUC(std::vector<RawMeshP3NUC::Point>& points) { 
			this->points = points;
		}
		void setPoints(std::vector<RawMeshP3NUC::Point>& points) {
			this->points = points;
		}
		RawMeshP3NUC(const RawMeshP3NUC& other);
		RawMeshP3NUC(RawMeshP3NUC&& other);
		RawMeshP3NUC& operator =(const RawMeshP3NUC& other);
		RawMeshP3NUC operator =(RawMeshP3NUC&& other);
		inline friend void swap(RawMeshP3NUC& a, RawMeshP3NUC& b);
		virtual void setMesh(Mesh& mesh, BufferUsageHint hint) const {
			glBufferData(GL_ARRAY_BUFFER, points.size() * sizeof(Point), &(points[0]), (GLenum)hint);
			glVertexAttribPointer(ATTRIBPOINTER_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(Point), (void*)offsetof(Point, pos));
			glVertexAttribPointer(ATTRIBPOINTER_NORMAL, 3, GL_FLOAT, GL_TRUE, sizeof(Point), (void*)offsetof(Point, pos));
			glVertexAttribPointer(ATTRIBPOINTER_UV, 2, GL_FLOAT, GL_FALSE, sizeof(Point), (void*)offsetof(Point, pos));
			glVertexAttribPointer(ATTRIBPOINTER_COLOR, 4, GL_FLOAT, GL_FALSE, sizeof(Point), (void*)offsetof(Point, pos));
		}
		virtual GLenum glRenderMode() const { return GL_TRIANGLES; }
		virtual size_t vertexCount() const { return points.size(); }

		static RawMeshP3NUC ParseStream_obj(std::istream& data) {
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
			std::vector<RawMeshP3NUC::Point> mesh{};
			std::vector<RawMeshP3NUC::Point> points{};
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
					RawMeshP3NUC::Point point{};
					point.pos = pos[p - 1];
					point.color = color[p - 1];
					point.uv = uv[t - 1];
					point.normal = normal[n - 1];
					points.push_back(point);
				}
				while (sscanf_s(d, " %d//%d%n", &p, &n, &c) == 2) {
					d += c;
					RawMeshP3NUC::Point point{};
					point.pos = pos[p - 1];
					point.color = color[p - 1];
					point.normal = normal[n - 1];
					points.push_back(point);
				}
				while (sscanf_s(d, " %d/%d%n", &p, &t, &c) == 2) {
					d += c;
					RawMeshP3NUC::Point point{};
					point.pos = pos[p - 1];
					point.color = color[p - 1];
					point.uv = uv[t - 1];
					points.push_back(point);
				}
				while (sscanf_s(d, " %d%n", &p, &c) == 1) {
					d += c;
					RawMeshP3NUC::Point point{};
					point.pos = pos[p - 1];
					point.color = color[p - 1];
					points.push_back(point);
				}
				for (int i = 1; i < points.size() - 1; i++) {
					mesh.push_back(points[0]);
					mesh.push_back(points[i]);
					mesh.push_back(points[i + 1]);
				}
			}
			return RawMeshP3NUC{mesh};
		}

	};

	class Mesh final {
		std::atomic_int* refrences = 0;
		GLuint vao = 0;
		GLuint vbo = 0;
		GLenum mode = 0;
		size_t count = 0;

		void DecrementRefrence() {
			if (!refrences) return;
			(*refrences)--;
			if ((*refrences) == 0) {
				delete refrences;
				refrences = 0;
				glDeleteBuffers(1, &vbo);
				vbo = 0;
				glDeleteVertexArrays(1, &vao);
				vao = 0;
			}
		}
	public:
		Mesh() = default;
		Mesh(const Mesh& other) {
			if (!other.isValid()) return;
			vao = other.vao;
			vbo = other.vbo;
			mode = other.mode;
			count = other.count;
			refrences = other.refrences;
			(*refrences)++;
		}
		Mesh(RawMeshBase& meshBase, BufferUsageHint usageHint = BufferUsageHint::StaticDraw) {
			if (vbo == 0) {
				glGenBuffers(1, &vbo);
			}
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			if (vao == 0) {
				glGenVertexArrays(1, &vao);
			}
			glBindVertexArray(vao);
			meshBase.setMesh(*this, usageHint);
			mode = meshBase.glRenderMode();
			count = meshBase.vertexCount();
			refrences = new std::atomic_int(1);
		}
		Mesh(Mesh&& other) noexcept {
			using std::swap;
			*this = {};
			swap(*this, other);
		}
		Mesh& operator=(const Mesh& other) {
			if (!other.isValid()) return *this;
			if (refrences) {
				DecrementRefrence();
			}
			vao = other.vao;
			vbo = other.vbo;
			mode = other.mode;
			count = other.count;
			refrences = other.refrences;
			(*refrences)++;
			return *this;
		}
		Mesh& operator=(Mesh&& other) noexcept {
			using std::swap;
			swap(*this, other);
			return *this;
		}
		void bind() {
			if (!isValid()) throw std::runtime_error("render::Mesh::bind - failed to bind mesh: mesh does not have assigned buffers.");
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glBindVertexArray(vao);
		}
		void draw(GLenum mode = 0) {
			if (!isValid()) throw std::runtime_error("render::Mesh::draw - failed to render mesh: invalid state");
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glBindVertexArray(vao);
			if (mode == 0) {
				glDrawArrays(this->mode, 0, count);
			}
			else {
				glDrawArrays(mode, 0, count);
			}
		}
		void drawInstances(size_t instanceCount, GLenum mode = 0) {
			if (!isValid()) throw std::runtime_error("render::Mesh::draw - failed to render mesh: invalid state");
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glBindVertexArray(vao);
			if (mode == 0) {
				glDrawArraysInstanced(this->mode, 0, count, instanceCount);
			}
			else {
				glDrawArraysInstanced(mode, 0, count, instanceCount);
			}
		}

		bool isValid() const {
			return refrences && vbo != 0 && vao != 0;
		}
		explicit operator bool() {
			return isValid();
		}
		bool operator!() {
			return !isValid();
		}
		friend inline void swap(Mesh& a, Mesh& b) {
			using std::swap;
			swap(a.vao, b.vao);
			swap(a.vbo, b.vbo);
		}
		~Mesh() {
			DecrementRefrence();
		}
	};

	class UniformBufferObject final {
		friend class ShaderProgramBase;
		std::atomic_int* refrences = 0;
		GLuint ubo = 0;

		void DecrementRefrence() {
			if (!refrences) return;
			(*refrences)--;
			if ((*refrences) == 0) {
				delete refrences;
				refrences = 0;
				glDeleteBuffers(1, &ubo);
				ubo = 0;
			}
		}
	public:
		UniformBufferObject() = default;
		UniformBufferObject(const UniformBufferObject& other) {
			if (!other.refrences) return;
			refrences = other.refrences;
			ubo = other.ubo;
			(*refrences)++;
		}
		UniformBufferObject(UniformBufferObject&& other) noexcept {
			using std::swap;
			*this = {};
			swap(*this, other);
		}
		UniformBufferObject& operator=(const UniformBufferObject& other) {
			if (refrences) {
				DecrementRefrence();
			}
			ubo = other.ubo;
			refrences = other.refrences;
			(*refrences)++;
		}
		UniformBufferObject& operator=(UniformBufferObject&& other) noexcept {
			using std::swap;
			swap(*this, other);
		}
		void set(const void* ptr, size_t size, GLenum usage) {
			if (ubo == 0) glGenBuffers(1, &ubo);
			bind();
			glBufferData(GL_UNIFORM_BUFFER, size, ptr, usage);
		}
		void bind() {
			if (!isValid()) throw std::runtime_error("render::UniformBufferObject::bind - failed to bind ubo: buffer not initialized.");
			glBindBuffer(GL_UNIFORM_BUFFER, ubo);
		}

		bool isValid() const {
			return ubo != 0;
		}
		explicit operator bool() {
			return isValid();
		}
		bool operator!() {
			return !isValid();
		}
		friend inline void swap(UniformBufferObject& a, UniformBufferObject& b) {
			using std::swap;
			swap(a.ubo, b.ubo);
			swap(a.refrences, b.refrences);
		}
		~UniformBufferObject() {
			DecrementRefrence();
		}
	};
	using UBObject = UniformBufferObject;
	class ShaderComponent final {
	public:
		enum struct ShaderType : GLenum {
			VertexShader = GL_VERTEX_SHADER,
			FragmentShader = GL_FRAGMENT_SHADER,
			GeometryShader = GL_GEOMETRY_SHADER,
			ComputeShader = GL_COMPUTE_SHADER,
			TessControlShader = GL_TESS_CONTROL_SHADER,
			TessEvaluationShader = GL_TESS_EVALUATION_SHADER
		};
	private:
		std::atomic_int* refrences = 0;
		GLuint shader = 0;
	public:
		ShaderComponent() = default;
		ShaderComponent(ShaderType type, const char* source) {
			refrences = new std::atomic_int(0);
			shader = glCreateShader((GLenum)type);
			glShaderSource(shader, 1, &source, NULL);
			GLint compiled;
			GLchar message[1024];
			GLsizei log_length = 0;
			glCompileShader(shader);
			glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
			if (compiled != GL_TRUE) {
				glGetShaderInfoLog(shader, sizeof(message), &log_length, message);
				throw std::runtime_error(message);
			}
		}
		ShaderComponent(const ShaderComponent& other) {
			refrences = other.refrences;
			shader = other.shader;
			(*refrences)++;
		}
		ShaderComponent(ShaderComponent&& other) noexcept {
			using std::swap;
			*this = {};
			swap(*this, other);
		}
		ShaderComponent& operator = (const ShaderComponent& other) = delete;
		ShaderComponent& operator = (ShaderComponent&& other) noexcept {
			using std::swap;
			swap(*this, other);
		}
		inline friend void swap(ShaderComponent& a, ShaderComponent& b) {
			using std::swap;
			swap(a.shader, b.shader);
		}
		GLuint getShader() const {
			return shader;
		}

		~ShaderComponent() {
			if (shader == 0) return;
			glDeleteShader(shader);
			shader = 0;
		}
	};
	class ShaderProgramBase {
	protected:
		GLuint program = 0;
		static inline thread_local GLuint currentProgram = 0;

		void setShader(size_t shaderCount, ShaderComponent** const shaderComponents) {
			GLint compiled;
			GLchar message[1024];
			GLsizei log_length = 0;
			if (program) glDeleteProgram(program);
			program = glCreateProgram();
			for (int i = 0; i < shaderCount; i++)
				glAttachShader(program, shaderComponents[i]->getShader());
			glLinkProgram(program);

			glGetProgramiv(program, GL_LINK_STATUS, &compiled);
			if (compiled != GL_TRUE) {
				glGetProgramInfoLog(program, 1024, &log_length, message);
				throw std::runtime_error(message);
			}
		}
	public:
		ShaderProgramBase() {}
		virtual ~ShaderProgramBase() {
			if (program == 0) return;
			glDeleteProgram(program);
			program = 0;
		}
		void bind() {
			if (currentProgram == 0 || currentProgram != program) {
				glUseProgram(program);
				currentProgram = program;
			}
		}
		bool isValid() const {
			return program != 0;
		}
		void uniform(GLint location, int value) {
			glProgramUniform1i(program, location, value);
		}
		void uniform(GLint location, unsigned int value) {
			glProgramUniform1ui(program, location, value);
		}
		void uniform(GLint location, float value) {
			glProgramUniform1f(program, location, value);
		}
		void uniform(GLint location, double value) {
			glProgramUniform1d(program, location, value);
		}
		void uniform(GLint location, math::Vec2i value) {
			glProgramUniform2iv(program, location, 2, (const int*)value);
		}
		void uniform(GLint location, math::Vec2ui value) {
			glProgramUniform2uiv(program, location, 2, (const unsigned int*)value);
		}
		void uniform(GLint location, math::Vec2f value) {
			glProgramUniform2fv(program, location, 2, (const float*)value);
		}
		void uniform(GLint location, math::Vec2d value) {
			glProgramUniform2dv(program, location, 2, (const double*)value);
		}
		void uniform(GLint location, math::Vec3i value) {
			glProgramUniform3iv(program, location, 3, (const int*)value);
		}
		void uniform(GLint location, math::Vec3ui value) {
			glProgramUniform3uiv(program, location, 3, (const unsigned int*)value);
		}
		void uniform(GLint location, math::Vec3f value) {
			glProgramUniform3fv(program, location, 3, (const float*)value);
		}
		void uniform(GLint location, math::Vec3d value) {
			glProgramUniform3dv(program, location, 3, (const double*)value);
		}
		void uniform(GLint location, math::Vec4i value) {
			glProgramUniform4iv(program, location, 4, (const int*)value);
		}
		void uniform(GLint location, math::Vec4ui value) {
			glProgramUniform4uiv(program, location, 4, (const unsigned int*)value);
		}
		void uniform(GLint location, math::Vec4f value) {
			glProgramUniform4fv(program, location, 4, (const float*)value);
		}
		void uniform(GLint location, math::Vec4d value) {
			glProgramUniform4dv(program, location, 4, (const double*)value);
		}
		void uniform(GLint location, math::Quati value) {
			glProgramUniform4iv(program, location, 4, (const int*)value);
		}
		void uniform(GLint location, math::Quatui value) {
			glProgramUniform4uiv(program, location, 4, (const unsigned int*)value);
		}
		void Uniform(GLint location, math::Quatf value) {
			glProgramUniform4fv(program, location, 4, (const float*)value);
		}
		void uniform(GLint location, math::Quatd value) {
			glProgramUniform4dv(program, location, 4, (const double*)value);
		}
		void Uniform(GLint location, math::Mat4f value) {
			glProgramUniformMatrix4fv(program, location, 16, false, (const float*)value);
		}
		void uniform(GLint location, math::Mat4d value) {
			glProgramUniformMatrix4dv(program, location, 16, false, (const double*)value);
		}
		void uniformBuffer(GLint location, UniformBufferObject& ubo) {
			glUniformBlockBinding(program, location, ubo.ubo);
		}
		GLint getUniformLoc(const char* name) {
			return glGetUniformLocation(program, name);
		}
		GLint getUniformBufferLoc(const char* name) {
			return glGetUniformBlockIndex(program, name);
		}
	};
	class RenderShaderProgram : public ShaderProgramBase {
	public:
		void setShader(ShaderComponent& vertexComponent, ShaderComponent& geometryShader, ShaderComponent& fragmentComponent) {
			ShaderComponent* arr[2]{ &vertexComponent, &fragmentComponent };
			ShaderProgramBase::setShader(2, arr);
		}
		void setShader(ShaderComponent& vertexComponent, ShaderComponent& fragmentComponent) {
			ShaderComponent* arr[2]{ &vertexComponent, &fragmentComponent };
			ShaderProgramBase::setShader(2, arr);
		}
	};

	class MaterialBase {
		GLuint vao = 0;
		RenderShaderProgram shader{};
	public:
		MaterialBase() {}
		//attributes
		//virtual deconstructor
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
			if (!isValid()) throw std::runtime_error("failed to bind mesh: mesh does not have allocated buffers.");
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
			glVertexAttrib4fv(ATTRIBPOINTER_COLOR, (const float*)color);
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
		T GetPixel(size_t x, size_t y) {
			return data[x + y * width];
		}
		void SetImage(size_t length, const T* list) {
			if (length < width * height) throw std::runtime_error("render::RawTextureBase::SetImage - length cant be less than width*height.");
			for (int i = 0; i < width * height; i++) {
				data[i] = list[i];
			}
		}
		void SetSubImage(size_t x, size_t y, size_t width, size_t height, size_t length, const T* list) {
			if (length < width * height) throw std::runtime_error("render::RawTextureBase::SetImage - length cant be less than width*height.");
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
		//thread-unsafe
		T* GetData() { return &(data[0]); }

		//get subImage
	};

	class RawTexture2d4f final : public RawTexture2dBase<math::Vec4f, GL_RGBA, GL_FLOAT> {
	public:
		RawTexture2d4f() : RawTexture2dBase() {}
		RawTexture2d4f(size_t width, size_t height) : RawTexture2dBase(width, height) {}
		static RawTexture2d4f ParseStream_bmp(std::istream data) {
			if (!data || data.get() != 'B' || data.get() != 'M') return {};//0,1
			uint32_t bmpSize = 0;
			data.read((char*)&bmpSize, sizeof(uint32_t));//2-6
			data.seekg(10);
			uint32_t bmpDataOffset = 0;
			data.read((char*)&bmpDataOffset, sizeof(uint32_t));//10-14
			uint32_t headerSize = 0;
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
	protected:
		GLuint textureID = 0;
		void InitTexture() {
			if (textureID == 0) {
				glGenTextures(1, &textureID);
			}
		}
	public:
		//runtime gen object id
		//get atribtues
		//set atributes
		//runtime conversiion between raw and texture
		//copy
		//assignemnt
		TextureBase() {}

		virtual ~TextureBase() {
			if (textureID == 0) return;
			glDeleteTextures(1, &textureID);
			textureID = 0;
		}

		void Bind() {
			if (textureID == 0) throw std::runtime_error("render::TextureBase::Bind - uninitialized texture, attempted access failed.");
			glBindTexture(target, textureID);
		}

		void SetMinFilter(TextureMinFilter minFilter) {
			if (textureID == 0) throw std::runtime_error("render::TextureBase::SetMinFilter - uninitialized texture, attempted modification failed.");
			glBindTexture(target, textureID);
			glTextureParameteri(target, GL_TEXTURE_MIN_FILTER, (int)minFilter);
		}
		void SetMagFilter(TextureMagFilter magFilter) {
			if (textureID == 0) throw std::runtime_error("render::TextureBase::SetMagFilter - uninitialized texture, attempted modification failed.");
			glBindTexture(target, textureID);
			glTextureParameteri(target, GL_TEXTURE_MIN_FILTER, (int)magFilter);
		}
		TextureMinFilter GetMinFilter() {
			if (textureID == 0) throw std::runtime_error("render::TextureBase::GetMinFilter - uninitialized texture, attempted information retrieval failed.");
			int k;
			glBindTexture(target, textureID);
			glGetTexParameteriv(target, GL_TEXTURE_MIN_FILTER, &k);
			return (TextureMinFilter)k;
		}
		TextureMagFilter GetMagFilter() {
			if (textureID == 0) throw std::runtime_error("render::TextureBase::GetMinFilter - uninitialized texture, attempted information retrieval failed.");
			int k;
			glBindTexture(target, textureID);
			glGetTexParameteriv(target, GL_TEXTURE_MAG_FILTER, &k);
			return (TextureMagFilter)k;
		}

		template<GLenum target>
		friend inline void swap(TextureBase< target>& a, TextureBase< target>& b) {
			using std::swap;
			swap(a.textureID, b.textureID);
		}
	};

	template<GLenum internalFormat>
	class ImageTexture2d final : public TextureBase<GL_TEXTURE_2D>{
		size_t width = 0;
		size_t height = 0;
		size_t mipmapLevels = 0;
	public:
		//constructorGL_RGB
		ImageTexture2d() {}
		template<typename T, GLenum format, GLenum type>
		ImageTexture2d(const RawTexture2dBase<T, format, type>& b) {
			glBindTexture(GL_TEXTURE_2D, textureID);
		}
		template<typename T, GLenum format, GLenum type>
		ImageTexture2d(RawTexture2dBase<T, format, type>&& b) {
			using std::swap;
			swap(*this, b);
		}
		//thread-unsafe
		ImageTexture2d(size_t width, size_t height, int mipmaps) {
			InitTexture();
			Bind();
		}
		template<typename T, GLenum format, GLenum type>
		ImageTexture2d(RawTexture2dBase<T, format, type>& base, int scaleMethod, int mipmaps) {
			InitTexture();
			Bind();
		}
		template<typename T, GLenum format, GLenum type>
		ImageTexture2d(RawTexture2dBase<T,format, type>* tex[], size_t length = 1, size_t start_mipmap = 0) {
			InitTexture();
			Bind();
			width = tex[0]->Width();
			height = tex[0]->Height();
			for (int i = 0; i < length; i++) {
				if (tex[i]->Width() != width / (i + 1)) throw std::runtime_error("render::ImageTexture2d - width of mipmap layer not half, rounded down, of previous mipmap layer width");
				if (tex[i]->Height() != height / (i + 1)) throw std::runtime_error("render::ImageTexture2d - height of mipmap layer not half, rounded down, of previous mipmap layer height");
				glTexImage2D(GL_TEXTURE_2D, start_mipmap, internalFormat, tex[i]->Width(), tex[i]->Height(), 0, format, type, tex[i]->GetData());
			}
		}
		template<typename T, GLenum format, GLenum type>
		void SetImage(RawTexture2dBase<T, format, type>& tex, int mipmapLevel = 0) {
			if (tex.Width() != width / (mipmapLevel + 1)) throw std::runtime_error("render::ImageTexture2d::SetImage - width of mipmap layer not half, rounded down, of previous mipmap layer width");
			if (tex.Height() != height / (mipmapLevel + 1)) throw std::runtime_error("render::ImageTexture2d::SetImage - height of mipmap layer not half, rounded down, of previous mipmap layer height");
			Bind();
			glTexSubImage2D(GL_TEXTURE_2D, mipmapLevel, 0, 0, width, height, format, type, tex.GetData());
		}

		ImageTexture2d& operator =(const ImageTexture2d& b) {

		}
		ImageTexture2d& operator =(ImageTexture2d&& b) {
			using std::swap;
		}
		size_t Width(int mipmap = 0) {
			return width / (mipmap + 1);
		}
		size_t Height(int mipmap = 0) {
			return height / (mipmap + 1);
		}

		friend inline void swap(ImageTexture2d< internalFormat>& a, ImageTexture2d< internalFormat>& b) {
			using std::swap;
			swap(a.width, b.width);
			swap(a.height, b.height);
			swap(a.mipmapLevels, b.mipmapLevels);
			swap((TextureBase<GL_TEXTURE_2D>&)a, (TextureBase<GL_TEXTURE_2D>&)b);
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
