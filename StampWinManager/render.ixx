export module render;

import <vector>;
import <exception>;
import <utility>;
import <istream>;
import <mutex>;
import "glm.h";
import "debug.h";

import swm;
import math;

static int* textureBinds = 0;
static int* blockBinds = 0;
static int maxTextureUnits = 0;
static int maxBlockUnits = 0;

export namespace render {

	constexpr auto ATTRIBPOINTER_POSITION = 0;
	constexpr auto ATTRIBPOINTER_NORMAL = 1;
	constexpr auto ATTRIBPOINTER_UV = 2;
	constexpr auto ATTRIBPOINTER_COLOR = 3;
	constexpr auto BLOCKBINDING_CAMERA = 0;
	constexpr auto UNIFORM_CAMERA = 0;
	constexpr auto UNIFORM_TRANSFORM = 1;
	constexpr auto UNIFORM_NORMALMAP = 9;
	constexpr auto UNIFORM_TEXTURE0 = 10;

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
		virtual void setMesh(Mesh& mesh, BufferUsageHint hint) const = 0;
		size_t vertexCount = 0;
		GLenum renderMode = GL_TRIANGLES;
		RawMeshBase() {}
	public:
		inline friend void swap(RawMeshBase& a, RawMeshBase& b) {
			using std::swap;
			swap(a.vertexCount, b.vertexCount);
			swap(a.renderMode, b.renderMode);
		}
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
		virtual void setMesh(Mesh& mesh, BufferUsageHint hint) const {
			size_t k = points.size() * sizeof(Point);
			glBufferData(GL_ARRAY_BUFFER, points.size() * sizeof(Point), &(points[0]), (GLenum)hint);
		}
	public:
		std::vector<RawMeshP3NUC::Point> points{};
		RawMeshP3NUC() = default;
		RawMeshP3NUC(const RawMeshP3NUC& other) = delete;
		RawMeshP3NUC(RawMeshP3NUC&& other) noexcept {
			using std::swap;
			swap(*this, other);
		}
		RawMeshP3NUC& operator =(const RawMeshP3NUC& other) = delete;
		RawMeshP3NUC operator =(RawMeshP3NUC&& other) noexcept {
			using std::swap;
			swap(*this, other);
		}
		inline friend void swap(RawMeshP3NUC& a, RawMeshP3NUC& b) {
			using std::swap;
			swap(a.points, b.points);
			swap((RawMeshBase&)a, (RawMeshBase&)b);
		}

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
			RawMeshP3NUC m{};
			m.points = points;
			return m;
		}

	};

	class Mesh final {
		GLuint vbo = 0;
		size_t count = 0;
		GLenum renderMode = 0;
	public:
		Mesh() { }
		Mesh(const Mesh& other) = delete;
		Mesh(RawMeshBase* meshBase, BufferUsageHint usageHint = BufferUsageHint::StaticDraw) {
			glGenBuffers(1, &vbo);
			set(meshBase, usageHint);
		}
		Mesh(Mesh&& other) noexcept {
			using std::swap;
			swap(*this, other);
		}
		Mesh& operator=(const Mesh& other) = delete;
		Mesh& operator=(Mesh&& other) noexcept {
			using std::swap;
			swap(*this, other);
			return *this;
		}
		void bind() {
			if (!isValid()) throw std::runtime_error("render::Mesh::bind - failed to bind mesh: mesh does not have assigned buffers.");
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
		}
		void set(RawMeshBase* meshBase, BufferUsageHint usageHint = BufferUsageHint::StaticDraw) {
			if (meshBase == NULL) return;
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			meshBase->setMesh(*this, usageHint);
			count = meshBase->vertexCount;
			renderMode = meshBase->renderMode;
		}
		bool isValid() const {
			return vbo != 0;
		}
		explicit operator bool() {
			return isValid();
		}
		bool operator!() {
			return !isValid();
		}
		inline friend void swap(Mesh& a, Mesh& b) {
			using std::swap;
			swap(a.vbo, b.vbo);
			swap(a.count, b.count);
		}
		~Mesh() {
			glDeleteBuffers(1, &vbo);
			vbo = 0;
		}
	};
	
	//https://en.wikipedia.org/wiki/BMP_file_format
	template<typename T, GLenum format, GLenum type>
	class RawTexture2dBase {
		std::vector<T> data{};
		size_t width = 0;
		size_t height = 0;
	protected:
		RawTexture2dBase() {}
		RawTexture2dBase(size_t width, size_t height) {
			data = std::vector<T>(width * height);
			this->width = width;
			this->height = height;
		}
	public:
		void SetPixel(size_t x, size_t y, const T& v) {
			data[x + y * width] = v;
		}
		T GetPixel(size_t x, size_t y) const {
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
		size_t Width() const { return width; }
		size_t Height() const { return height; }
		//thread-unsafe
		const T* GetData() const { return &(data[0]); }

		//get subImage
	};

	class RawTexture2d4f final : public RawTexture2dBase<math::Vec4f, GL_RGBA, GL_FLOAT> {
	public:
		RawTexture2d4f() : RawTexture2dBase() {}
		RawTexture2d4f(size_t width, size_t height) : RawTexture2dBase(width, height) {}
		static RawTexture2d4f ParseStream_bmp(std::istream& data) {
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
		friend class ShaderProgramBase;
	protected:
		GLuint textureID = 0;
		int textureIndex = -1;
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

		void bind() {
			STAMPERROR(textureID == 0,"render::TextureBase::Bind - uninitialized texture, attempted access failed.");
			glBindTexture(target, textureID);
		}
		void bindActive(size_t index) {
			glActiveTexture(GL_TEXTURE0 + index);
			glBindTexture(target, textureID);

			if (textureBinds == 0) {
				glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &maxTextureUnits);
				textureBinds = new int[maxTextureUnits];
			}
			textureBinds[index] = textureID;
			textureIndex = index;
		}
		bool isActive() const {
			if (!isValid() || textureBinds == 0 || textureIndex == -1) return false;
			return textureBinds[textureIndex] == textureID;
		}

		void SetMinFilter(TextureMinFilter minFilter) {
			STAMPERROR(textureID == 0,"render::TextureBase::SetMinFilter - uninitialized texture, attempted modification failed.");
			glBindTexture(target, textureID);
			glTextureParameteri(target, GL_TEXTURE_MIN_FILTER, (int)minFilter);
		}
		void SetMagFilter(TextureMagFilter magFilter) {
			STAMPERROR(textureID == 0,"render::TextureBase::SetMagFilter - uninitialized texture, attempted modification failed.");
			glBindTexture(target, textureID);
			glTextureParameteri(target, GL_TEXTURE_MIN_FILTER, (int)magFilter);
		}
		TextureMinFilter GetMinFilter() const {
			STAMPERROR(textureID == 0,"render::TextureBase::GetMinFilter - uninitialized texture, attempted information retrieval failed.");
			int k;
			glBindTexture(target, textureID);
			glGetTexParameteriv(target, GL_TEXTURE_MIN_FILTER, &k);
			return (TextureMinFilter)k;
		}
		TextureMagFilter GetMagFilter() const {
			STAMPERROR(textureID == 0,"render::TextureBase::GetMinFilter - uninitialized texture, attempted information retrieval failed.");
			int k;
			glBindTexture(target, textureID);
			glGetTexParameteriv(target, GL_TEXTURE_MAG_FILTER, &k);
			return (TextureMagFilter)k;
		}
		bool isValid() const {
			return textureID != 0;
		}
		explicit operator bool() {
			return isValid();
		}
		bool operator!() {
			return !isValid();
		}

		template<GLenum target>
		inline friend void swap(TextureBase< target>& a, TextureBase< target>& b) {
			using std::swap;
			swap(a.textureID, b.textureID);
		}
	};
	class ImageTexture2d : public TextureBase<GL_TEXTURE_2D>{
		size_t width = 0;
		size_t height = 0;
		size_t mipmapLevels = 0;
		GLenum internalFormat = GL_RGBA;
	public:
		ImageTexture2d() {}
		ImageTexture2d(size_t width, size_t height, GLenum internalFormat, int mipmaps = 1) {
			InitTexture();
			this->width = width;
			this->height = height;
			this->internalFormat = internalFormat;
			this->mipmapLevels = mipmaps;
			bind();
			glTextureStorage2D(GL_TEXTURE_2D, mipmapLevels, internalFormat, width, height);
		}
		ImageTexture2d(const ImageTexture2d& b) = delete;
		ImageTexture2d(ImageTexture2d&& b) noexcept {
			using std::swap;
			swap(*this, b);
		}
		ImageTexture2d& operator =(const ImageTexture2d& b) = delete;
		ImageTexture2d& operator =(ImageTexture2d&& b) noexcept {
			using std::swap;
			swap(*this, b);
		}
		template<typename T, GLenum format, GLenum type>//27, 13.5, 14
		void SetImage(RawTexture2dBase<T, format, type>& tex, int mipmapLevel = 0) {
			STAMPERROR(mipmapLevels >= this->mipmapLevels, "render::ImageTexture2d::SetImage - mipmap above max value assigned");
			if (tex.Width() != Width(mipmapLevel)) throw std::runtime_error("render::ImageTexture2d::SetImage - width of mipmap layer not half, rounded down, of previous mipmap layer width");
			if (tex.Height() != Height(mipmapLevel)) throw std::runtime_error("render::ImageTexture2d::SetImage - height of mipmap layer not half, rounded down, of previous mipmap layer height");
			bind();
			glTexImage2D(GL_TEXTURE_2D, mipmapLevel, internalFormat, width, height, 0, format, type, tex.GetData());
		}
		void GenMipmaps() {
			glGenerateTextureMipmap(textureID);
		}
		size_t Width(int mipmap = 0) const {
			return max(1, width / (mipmap + 1));
		}
		size_t Height(int mipmap = 0) const {
			return max(1,height / (mipmap + 1));
		}

		inline friend void swap(ImageTexture2d& a, ImageTexture2d& b) {
			using std::swap;
			swap(a.width, b.width);
			swap(a.height, b.height);
			swap(a.mipmapLevels, b.mipmapLevels);
			swap((TextureBase<GL_TEXTURE_2D>&)a, (TextureBase<GL_TEXTURE_2D>&)b);
		}
	};

	class UniformBufferObject {
		friend class ShaderProgramBase;
		GLuint ubo = 0;
		int blockIndex = -1;
	protected:
	public:
		void set(const void* ptr, size_t size, BufferUsageHint usage = BufferUsageHint::StaticDraw) {
			if (ubo == 0) glGenBuffers(1, &ubo);
			bind();
			glBufferData(GL_UNIFORM_BUFFER, size, ptr, (GLenum)usage);
		}
		UniformBufferObject() = default;
		UniformBufferObject(const UniformBufferObject& other) = delete;
		UniformBufferObject(UniformBufferObject&& other) noexcept {
			using std::swap;
			swap(*this, other);
		}
		UniformBufferObject& operator=(const UniformBufferObject& other) = delete;
		UniformBufferObject& operator=(UniformBufferObject&& other) noexcept {
			using std::swap;
			swap(*this, other);
		}
		void bind() {
			STAMPERROR(!isValid(),"render::UniformBufferObject::bind - failed to bind ubo: buffer not initialized.");
			glBindBuffer(GL_UNIFORM_BUFFER, ubo);
		}
		void bindActive(int index) {
			STAMPERROR(!isValid(),"render::UniformBufferObject::bindActive - failed to bind ubo: buffer not initialized.");
			glBindBufferBase(GL_UNIFORM_BUFFER, index, ubo);

			if (blockBinds == 0) {
				glGetIntegerv(GL_MAX_UNIFORM_BUFFER_BINDINGS, &maxBlockUnits);
				blockBinds = new int[maxBlockUnits];
			}
			blockBinds[index] = ubo;
			blockIndex = index;
		}
		void bindActive(int index, size_t offset, size_t size) {
			STAMPERROR(!isValid(),"render::UniformBufferObject::bindActive - failed to bind ubo: buffer not initialized.");
			glBindBufferRange(GL_UNIFORM_BUFFER, index, ubo, offset, size);
		}
		bool isActive() const {
			if (!isValid() || blockBinds == 0 || blockIndex == -1) return false;
			return blockBinds[blockIndex] == ubo;
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
		inline friend void swap(UniformBufferObject& a, UniformBufferObject& b) {
			using std::swap;
			swap(a.ubo, b.ubo);
		}
		~UniformBufferObject() {
			glDeleteBuffers(1, &ubo);
			ubo = 0;
		}
	};
	using UBObject = UniformBufferObject;
	//layout(binding=0) uniform sampler2D diffuseTex; // set sampler to target texture without assigning uniform
	//layout(location=0) uniform int val; // bind at location 0
	class ShaderProgramBase {
	public:
		enum struct ShaderType {
			VertexShader = 0,
			FragmentShader = 1,
			GeometryShader = 2,
			ComputeShader = 3,
			TessControlShader = 4,
			TessEvaluationShader = 5
		};
		inline static const GLenum shaderTypeEnum[]{
			GL_VERTEX_SHADER, GL_FRAGMENT_SHADER, GL_GEOMETRY_SHADER, GL_COMPUTE_SHADER, GL_TESS_CONTROL_SHADER, GL_TESS_EVALUATION_SHADER
		};
		inline static const std::string shaderDefineScript[]{
			"#define GL_VERTEX_SHADER\n", "#define GL_FRAGMENT_SHADER\n", "#define GL_GEOMETRY_SHADER\n","#define GL_COMPUTE_SHADER\n", "#define GL_TESS_CONTROL_SHADER\n", "#define GL_TESS_EVALUATION_SHADER\n"
		};
	private:
		GLuint program = 0;
		static inline thread_local GLuint currentProgram = 0;
	protected:
		ShaderProgramBase() {}
		void set(std::istream& prog, const std::vector<ShaderType>& types) {
			if (program) glDeleteProgram(program);
			program = glCreateProgram();
			std::string progTxt{ std::istreambuf_iterator<char>(prog), {} };
			GLint compiled;
			GLchar message[1024];
			GLsizei log_length = 0;
			std::vector<GLuint> shaderComp{};
			for (int i = 0; i < types.size(); i++) {
				GLuint comp = glCreateShader(shaderTypeEnum[(size_t)types[i]]);
				std::string p = shaderDefineScript[(size_t)types[i]] + progTxt;
				const char* c = p.c_str();
				glShaderSource(comp, 1, &c, 0);

				glCompileShader(comp);
				glGetShaderiv(comp, GL_COMPILE_STATUS, &compiled);
				if (compiled != GL_TRUE) {
					glGetShaderInfoLog(comp, sizeof(message), &log_length, message);
					STAMPSTACK();
					STAMPDMSG("render::ShaderProgramBase - compilation error");
					STAMPDMSG(message);
				}
				shaderComp.push_back(comp);
				glAttachShader(program, comp);
			}
			glLinkProgram(program);
			glGetProgramiv(program, GL_LINK_STATUS, &compiled);
			if (compiled != GL_TRUE) {
				glGetProgramInfoLog(program, 1024, &log_length, message);
				STAMPSTACK();
				STAMPDMSG("render::ShaderProgramBase::setShader - compilation error");
				STAMPDMSG(message);
			}
			for (int i = 0; i < shaderComp.size(); i++) {
				glDeleteShader(shaderComp[i]);
			}
		}
	public:
		ShaderProgramBase(const ShaderProgramBase& other) = delete;
		ShaderProgramBase(ShaderProgramBase&& other) noexcept {
			using std::swap;
			swap(*this, other);
		}
		ShaderProgramBase& operator =(const ShaderProgramBase& other) = delete;
		ShaderProgramBase& operator =(ShaderProgramBase&& other) noexcept {
			using std::swap;
			swap(*this, other);
		}
		inline friend void swap(ShaderProgramBase& a, ShaderProgramBase& b) noexcept {
			using std::swap;
			swap(a.program, b.program);
		}
		virtual ~ShaderProgramBase() {
			if (program) glDeleteProgram(program);
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
		template<GLenum target>
		void uniform(GLint location, const TextureBase<target>& value) {
			STAMPERROR(value.isActive(), "render::ShaderProgramBase::uniform - texture is not active");
			glProgramUniform1i(program, location, value.textureIndex);
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
		void uniform(GLint location, const math::Vec2i& value) {
			glProgramUniform2iv(program, location, 1, (const int*)value);
		}
		void uniform(GLint location, const math::Vec2ui& value) {
			glProgramUniform2uiv(program, location, 1, (const unsigned int*)value);
		}
		void uniform(GLint location, const math::Vec2f& value) {
			glProgramUniform2fv(program, location, 1, (const float*)value);
		}
		void uniform(GLint location, const math::Vec2d& value) {
			glProgramUniform2dv(program, location, 1, (const double*)value);
		}
		void uniform(GLint location, const math::Vec3i& value) {
			glProgramUniform3iv(program, location, 1, (const int*)value);
		}
		void uniform(GLint location, const math::Vec3ui& value) {
			glProgramUniform3uiv(program, location, 1, (const unsigned int*)value);
		}
		void uniform(GLint location, const math::Vec3f& value) {
			glProgramUniform3fv(program, location, 1, (const float*)value);
		}
		void uniform(GLint location, const math::Vec3d& value) {
			glProgramUniform3dv(program, location, 1, (const double*)value);
		}
		void uniform(GLint location, const math::Vec4i& value) {
			glProgramUniform4iv(program, location, 1, (const int*)value);
		}
		void uniform(GLint location, const math::Vec4ui& value) {
			glProgramUniform4uiv(program, location, 1, (const unsigned int*)value);
		}
		void uniform(GLint location, const math::Vec4f& value) {
			glProgramUniform4fv(program, location, 1, (const float*)value);
		}
		void uniform(GLint location, const math::Vec4d& value) {
			glProgramUniform4dv(program, location, 1, (const double*)value);
		}
		void uniform(GLint location, const math::Quati& value) {
			glProgramUniform4iv(program, location, 1, (const int*)value);
		}
		void uniform(GLint location, const math::Quatui& value) {
			glProgramUniform4uiv(program, location, 1, (const unsigned int*)value);
		}
		void uniform(GLint location, const math::Quatf& value) {
			glProgramUniform4fv(program, location, 1, (const float*)value);
		}
		void uniform(GLint location, const math::Quatd& value) {
			glProgramUniform4dv(program, location, 1, (const double*)value);
		}
		void uniform(GLint location, const math::Mat4f& value) {
			glProgramUniformMatrix4fv(program, location, 1, false, (const float*)value);
		}
		void uniform(GLint location, const math::Mat4d& value) {
			glProgramUniformMatrix4dv(program, location, 1, false, (const double*)value);
		}
		void uniform(GLint location, const int* value, GLsizei count) {
			glProgramUniform1iv(program, location, count, value);
		}
		void uniform(GLint location, const unsigned int* value, int count) {
			glProgramUniform1uiv(program, location, count, value);
		}
		void uniform(GLint location, const float* value, int count) {
			glProgramUniform1fv(program, location, count, value);
		}
		void uniform(GLint location, const double* value, int count) {
			glProgramUniform1dv(program, location, count, value);
		}
		void uniform(GLint location, const math::Vec2i* value, int count) {
			glProgramUniform2iv(program, location, count, (const int*)value);
		}
		void uniform(GLint location, const math::Vec2ui* value, int count) {
			glProgramUniform2uiv(program, location, count, (const unsigned int*)value);
		}
		void uniform(GLint location, const math::Vec2f* value, int count) {
			glProgramUniform2fv(program, location, count, (const float*)value);
		}
		void uniform(GLint location, const math::Vec2d* value, int count) {
			glProgramUniform2dv(program, location, count, (const double*)value);
		}
		void uniform(GLint location, const math::Vec3i* value, int count) {
			glProgramUniform3iv(program, location, count, (const int*)value);
		}
		void uniform(GLint location, const math::Vec3ui* value, int count) {
			glProgramUniform3uiv(program, location, count, (const unsigned int*)value);
		}
		void uniform(GLint location, const math::Vec3f* value, int count) {
			glProgramUniform3fv(program, location, count, (const float*)value);
		}
		void uniform(GLint location, const math::Vec3d* value, int count) {
			glProgramUniform3dv(program, location, count, (const double*)value);
		}
		void uniform(GLint location, const math::Vec4i* value, int count) {
			glProgramUniform4iv(program, location, count, (const int*)value);
		}
		void uniform(GLint location, const math::Vec4ui* value, int count) {
			glProgramUniform4uiv(program, location, count, (const unsigned int*)value);
		}
		void uniform(GLint location, const math::Vec4f* value, int count) {
			glProgramUniform4fv(program, location, count, (const float*)value);
		}
		void uniform(GLint location, const math::Vec4d* value, int count) {
			glProgramUniform4dv(program, location, count, (const double*)value);
		}
		void uniform(GLint location, const math::Quati* value, int count) {
			glProgramUniform4iv(program, location, count, (const int*)value);
		}
		void uniform(GLint location, const math::Quatui* value, int count) {
			glProgramUniform4uiv(program, location, count, (const unsigned int*)value);
		}
		void uniform(GLint location, const math::Quatf* value, int count) {
			glProgramUniform4fv(program, location, count, (const float*)value);
		}
		void uniform(GLint location, const math::Quatd* value, int count) {
			glProgramUniform4dv(program, location, count, (const double*)value);
		}
		void uniform(GLint location, const math::Mat4f* value, int count) {
			glProgramUniformMatrix4fv(program, location, count, false, (const float*)value);
		}
		void uniform(GLint location, const math::Mat4d* value, int count) {
			glProgramUniformMatrix4dv(program, location, count, false, (const double*)value);
		}
		void uniformBuffer(GLint location, const UniformBufferObject& value) {
			STAMPERROR(value.isActive(), "render::ShaderProgramBase::uniformBuffer - UBO is not active");
			glUniformBlockBinding(program, location, value.blockIndex);
		}
		void uniformBuffer(GLint location, int index) {
			glUniformBlockBinding(program, location, index);
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
		RenderShaderProgram() {}
		RenderShaderProgram(const RenderShaderProgram& other) = delete;
		RenderShaderProgram(RenderShaderProgram&& other) noexcept {
			using std::swap;
			swap(*this, other);
		}
		RenderShaderProgram& operator =(const RenderShaderProgram& other) = delete;
		RenderShaderProgram& operator =(RenderShaderProgram&& other) noexcept {
			using std::swap;
			swap(*this, other);
		}
		inline friend void swap(RenderShaderProgram& a, RenderShaderProgram& b) noexcept {
			using std::swap;
			swap((ShaderProgramBase&)a, (ShaderProgramBase&)b);
		}
		virtual ~RenderShaderProgram() { }
		inline static RenderShaderProgram ParseStream_glsl(std::istream& prog) {
			RenderShaderProgram r{};
			r.ShaderProgramBase::set(prog, { {ShaderType::VertexShader, ShaderType::FragmentShader} });
			return r;
		}
	};
	class ComputeShaderProgram : public ShaderProgramBase {
		ComputeShaderProgram() {}
		ComputeShaderProgram(const ComputeShaderProgram& other) = delete;
		ComputeShaderProgram(ComputeShaderProgram&& other) noexcept {
			using std::swap;
			swap(*this, other);
		}
		ComputeShaderProgram& operator =(const ComputeShaderProgram& other) = delete;
		ComputeShaderProgram& operator =(ComputeShaderProgram&& other) noexcept {
			using std::swap;
			swap(*this, other);
		}
		inline friend void swap(ComputeShaderProgram& a, ComputeShaderProgram& b) noexcept {
			using std::swap;
			swap((ShaderProgramBase&)a, (ShaderProgramBase&)b);
		}
		void Dispatch(int groupsX, int groupsY, int groupsZ) {
			bind();
			glDispatchCompute(groupsX, groupsY, groupsZ);
		}
		virtual ~ComputeShaderProgram() { }
		inline static ComputeShaderProgram ParseStream_glsl(std::istream& prog) {
			ComputeShaderProgram r{};
			r.ShaderProgramBase::set(prog, { {ShaderType::ComputeShader} });
			return r;
		}
	};
	class MaterialBase {
		GLuint vao = 0;
	protected:
		MaterialBase() { }
		MaterialBase(std::shared_ptr<ShaderProgramBase> shader) {
			glGenVertexArrays(1, &vao);
			this->shader = shader;
		}
		MaterialBase(const MaterialBase& other) = delete;
		MaterialBase& operator =(const MaterialBase& other) = delete;
	public:
		std::shared_ptr<ShaderProgramBase> shader{};
		virtual void UpdateAttrib() = 0;
		virtual void UpdateUniform() = 0;
		void bind() {
			if (!isValid()) throw std::runtime_error("failed to bind mesh: mesh does not have allocated buffers.");
			glBindVertexArray(vao);
			shader->bind();
		}
		bool isValid() {
			return vao != 0 && shader->isValid();
		}
		inline friend void swap(MaterialBase& a, MaterialBase& b) noexcept {
			using std::swap;
			swap(a.vao, b.vao);
			swap(a.shader, b.shader);
		}
		virtual ~MaterialBase() {
			glDeleteVertexArrays(1, &vao);
			vao = 0;
		}
	};
	class SolidMaterial final : public MaterialBase {
	public:
		math::Vec4f color{ 0.8f,0.8f,0.8f,1 };
		bool useColor = false;
		std::shared_ptr<ImageTexture2d> texture;
		std::shared_ptr<ImageTexture2d> normalMap;
		SolidMaterial() { }
		SolidMaterial(const SolidMaterial& other) = delete;
		SolidMaterial(SolidMaterial&& other) noexcept {
			using std::swap;
			swap(*this, other);
		}
		SolidMaterial& operator =(const SolidMaterial& other) = delete;
		SolidMaterial& operator =(SolidMaterial&& other) noexcept {
			using std::swap;
			swap(*this, other);
		}
		virtual void UpdateAttrib() {
			bind();
			glEnableVertexAttribArray(ATTRIBPOINTER_POSITION);
			glEnableVertexAttribArray(ATTRIBPOINTER_NORMAL);
			glEnableVertexAttribArray(ATTRIBPOINTER_UV);
			if (useColor) {
				glVertexAttrib4fv(ATTRIBPOINTER_COLOR, (const float*)color);
				glEnableVertexAttribArray(ATTRIBPOINTER_COLOR); 
			}
			else  glDisableVertexAttribArray(ATTRIBPOINTER_COLOR);
		}
		virtual void UpdateUniform() {
			shader->uniformBuffer(UNIFORM_CAMERA, BLOCKBINDING_CAMERA);
			if (texture != 0) shader->uniform(UNIFORM_TEXTURE0, *texture);
			if (normalMap != 0) shader->uniform(UNIFORM_NORMALMAP, *normalMap);
		}
		inline friend void swap(SolidMaterial& a, SolidMaterial& b) noexcept {
			using std::swap;
			swap((MaterialBase&)a, (MaterialBase&)b);
		}
		virtual ~SolidMaterial() { }
	};

	class Transform final {
	public:
		math::Vec3f position;
		math::Vec3f scale;
		math::Quatf rotation;

		void Rotate(float x, float y, float z) {
			rotation = math::Quatf::RotationZXY(x, y, z) * rotation;
		}
		void LookAt(const math::Vec3f& pos) {
			math::Vec3f v = pos - position;
			rotation = math::Quatf::LookAt(v.x, v.y, v.z);
		}

		math::Mat4f toMatrix() {
			return math::Mat4f::Scale(scale.x, scale.y, scale.z) * rotation.ToRotationMatrix() * math::Mat4f::Translate(position.x, position.y, position.z);
		}
		void bind(ShaderProgramBase& program, int location = UNIFORM_TRANSFORM) {
			program.uniform(location, toMatrix());
		}
	};

	class CameraPerspective final {
		UBObject ubo{};
	public:
		Transform transform;
		float fovx = 60 * math::PI / 180;
		float ratio = 1;
		float nearPlane = 0.15;
		float farPlane = 1000;
		math::Mat4f toMatrix() {
			return math::Mat4f::Perspective(fovx,ratio,nearPlane,farPlane);
		}
		void Update(int index = BLOCKBINDING_CAMERA) {
			struct cam_t{
				math::Mat4f trans;
				math::Mat4f cam;
			} value;
			ubo.set(&value, sizeof(cam_t), BufferUsageHint::DynamicDraw);
			ubo.bindActive(index);
		}
		//uniform(location) camera {
		//	mat4 camTrans;
		//	mat4 camProj;
		//};
		void bind(ShaderProgramBase& program, int location = UNIFORM_CAMERA) {
			program.uniformBuffer(location, ubo);
		}
	};
	class CameraUI final {
		UBObject ubo{};
	public:
		Transform transform;
		float width = 1920;
		float ratio = 1;
		float nearPlane = 1;
		float farPlane = 1000;
		math::Mat4f toMatrix() {
			return math::Mat4f::Orthographic(width/2, ratio, nearPlane, farPlane);
		}
		void Update(int index = BLOCKBINDING_CAMERA) {
			struct cam_t {
				math::Mat4f trans;
				math::Mat4f cam;
			} value;
			ubo.set(&value, sizeof(cam_t), BufferUsageHint::DynamicDraw);
			ubo.bindActive(index);
		}
		//uniform(location) camera {
		//	mat4 camTrans;
		//	mat4 camProj;
		//};
		void bind(ShaderProgramBase& program, int location = UNIFORM_CAMERA) {
			program.uniformBuffer(location, ubo);
		}
	};

	class FrameBuffer2d final : public ImageTexture2d {
		GLuint id = 0;
		FrameBuffer2d(GLuint id) {
			this->id = id;
		}
	public:
		FrameBuffer2d() {}
		FrameBuffer2d(const FrameBuffer2d& other) = delete;
		FrameBuffer2d(FrameBuffer2d&& other) noexcept {
			using std::swap;
			swap(*this, other);
		}
		FrameBuffer2d& operator =(const FrameBuffer2d& other) = delete;
		FrameBuffer2d& operator =(FrameBuffer2d&& other) noexcept {
			using std::swap;
			swap(*this, other);
		}
		inline friend void swap(FrameBuffer2d& a, FrameBuffer2d& b) {
			using std::swap;
			swap(a.id, b.id);
			swap((ImageTexture2d&)a, (ImageTexture2d&)b);
		}
		~FrameBuffer2d() {
			if (id) glDeleteFramebuffers(1, &id);
			id = 0;
		}

		void Resize(int width, int height) {
			texture = std::move(ImageTexture2d(width, height, GL_RGBA, 1));
		}
		void ResizeScreen() {
			Resize(texture.Width(), texture.Height());
		}
		//bind
		//bind texture
		//static glDrawBuffers array
		static void BindDrawBuffers(const FrameBuffer2d* buffers, size_t length) {
			std::vector<GLenum> arr{};
			arr.reserve(length);
			for (int i = 0; i < length; i++) {
				arr[i] = buffers[i].id;
			}
			glDrawBuffers(length, &(arr[0]));
		}

		void CopyContentToScreen() {
			glBindFramebuffer(GL_READ_FRAMEBUFFER, id);
			glBindFramebuffer(GL_DRAW_FRAMEBUFFER, swm::getVsync() ? GL_BACK_LEFT : GL_FRONT_LEFT);
			glBlitFramebuffer(0, 0, texture.Width(), texture.Height(), 0, 0, swm::getDesktopWidth(), swm::getDesktopHeight(), GL_COLOR_BUFFER_BIT, GL_LINEAR);
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
