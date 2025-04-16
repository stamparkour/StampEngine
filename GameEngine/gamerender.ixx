export module gamerender;

import std;

import "getset.h";
import "glm.h";
import "debug.h";

import winmanager;
import math;

namespace render {
	class SamplerBase;
	class UniformBufferObject;
	class ShaderStorageBufferObject;
}
static render::UniformBufferObject** uniformBlockBinds = 0;
static render::ShaderStorageBufferObject** shaderBlockBinds = 0;
static render::SamplerBase** textureBinds = 0;
int maxTextureUnits = 0;
int maxBlockUnits = 0;
int initFBO = -1;

export namespace render {

	void TriangleFill() {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		GLSTAMPERROR;
	}
	void TriangleOutline() {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		GLSTAMPERROR;
	}

	constexpr auto ATTRIBPOINTER_POSITION = 1;
	constexpr auto ATTRIBPOINTER_NORMAL = 2;
	constexpr auto ATTRIBPOINTER_UV = 3;
	constexpr auto ATTRIBPOINTER_COLOR = 4;
	constexpr auto UNIFORM_TRANSFORM = 1;
	constexpr auto UNIFORM_NORMALMAP = 10;
	constexpr auto UNIFORM_TEXTURE0 = 20;

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

	class MaterialBase;

	struct PointP3NUC final {
		math::Vec3f pos;
		math::Vec3f normal;
		math::Vec2f uv;
		math::Vec4f color;

		PointP3NUC() = default;
		PointP3NUC(const math::Vec3f pos, const math::Vec3f normal, const math::Vec2f uv, const math::Vec4f color)
			: pos(pos), normal(normal), uv(uv), color(color) {
		}
		static void setMaterial(MaterialBase& material) {
			glVertexAttribPointer(ATTRIBPOINTER_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(PointP3NUC), (void*)offsetof(PointP3NUC, pos));
			glVertexAttribPointer(ATTRIBPOINTER_NORMAL, 3, GL_FLOAT, GL_TRUE, sizeof(PointP3NUC), (void*)offsetof(PointP3NUC, normal));
			glVertexAttribPointer(ATTRIBPOINTER_UV, 2, GL_FLOAT, GL_FALSE, sizeof(PointP3NUC), (void*)offsetof(PointP3NUC, uv));
			glVertexAttribPointer(ATTRIBPOINTER_COLOR, 4, GL_FLOAT, GL_FALSE, sizeof(PointP3NUC), (void*)offsetof(PointP3NUC, color));
		}
		static const GLenum renderMode = GL_TRIANGLES;

		void Tranform(const math::Mat4f& transform) {
			pos = (math::Vec3f)(transform * math::Vec4f(pos.x, pos.y, pos.z, 1));
			normal = (math::Vec3f)(transform * math::Vec4f(normal.x, normal.y, normal.z, 0).Normal());
		}

		//text stream
		static std::vector<PointP3NUC> ParseStream_obj(std::istream& data, const math::Mat4f* transform = 0) {
			STAMPERROR(data.fail(), "PointP3NUC::ParseStream_obj - data stream is invalid.");
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
			data.clear();
			data.seekg(spos);
			std::vector<PointP3NUC> mesh{};
			std::vector<PointP3NUC> points{};
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
					PointP3NUC point{};
					point.pos = pos[p - 1];
					point.color = color[p - 1];
					point.uv = uv[t - 1];
					point.normal = normal[n - 1];
					points.push_back(point);
				}
				while (sscanf_s(d, " %d//%d%n", &p, &n, &c) == 2) {
					d += c;
					PointP3NUC point{};
					point.pos = pos[p - 1];
					point.color = color[p - 1];
					point.normal = normal[n - 1];
					points.push_back(point);
				}
				while (sscanf_s(d, " %d/%d%n", &p, &t, &c) == 2) {
					d += c;
					PointP3NUC point{};
					point.pos = pos[p - 1];
					point.color = color[p - 1];
					point.uv = uv[t - 1];
					points.push_back(point);
				}
				while (sscanf_s(d, " %d%n", &p, &c) == 1) {
					d += c;
					PointP3NUC point{};
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

			if (transform) {
				for (int i = 0; i < mesh.size(); i++) {
					mesh[i].Tranform(*transform);
				}
			}

			return mesh;
		}
	};

	class Mesh final : public std::enable_shared_from_this<Mesh> {
		friend class MaterialBase;
		GLuint vbo = 0;
		size_t count = 0;
		GLenum renderMode = 0;
		void (*setMaterial)(MaterialBase& material);
	public:
		Mesh(const Mesh& other) = delete;
		Mesh() {
			STAMPERROR(!wm::CurrentWindow()->isControlThread(), "render::Mesh - can only construct mesh in management thread.");
			glGenBuffers(1, &vbo);
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
		void Bind() {
			STAMPERROR(!wm::CurrentWindow()->isControlThread(),"render::Mesh::Bind - can only Bind mesh in management thread.");
			STAMPERROR(!isValid(),"render::Mesh::Bind - failed to Bind mesh: mesh does not have assigned buffers.");
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
		}
		template<typename T>
		void set(const std::vector<T>& meshPoints, BufferUsageHint usageHint = BufferUsageHint::StaticDraw) {
			if (meshPoints.size() == 0) return;
			STAMPERROR(!wm::CurrentWindow()->isControlThread(), "render::Mesh::set - can only Bind mesh in management thread.");
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			GLSTAMPERROR;
			setMaterial = T::setMaterial;
			glBufferData(GL_ARRAY_BUFFER, meshPoints.size() * sizeof(T), &(meshPoints[0]), (GLenum)usageHint);
			GLSTAMPERROR;
			count = meshPoints.size();
			renderMode = T::renderMode;
		}
		void RenderArray() {
			glDrawArrays(renderMode, 0, count);
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
			swap(a.renderMode, b.renderMode);
			swap(a.setMaterial, b.setMaterial);
		}
		~Mesh() {
			STAMPERROR(!wm::CurrentWindow()->isControlThread(),"render::Mesh::~Mesh - can only Bind mesh in management thread.");
			glDeleteBuffers(1, &vbo);
			vbo = 0;
		}
	};
	
	//https://en.wikipedia.org/wiki/BMP_file_format
	template<typename T, GLenum format, GLenum type>
	class RawTexture2dBase : public std::enable_shared_from_this<RawTexture2dBase<T,format,type>> {
		std::vector<T> data{};
		size_t width = 0;
		size_t height = 0;
	protected:
		RawTexture2dBase() {}
		void Initialize(size_t width, size_t height) {
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
		void SetImage(const T* list, size_t length) {
			STAMPERROR(length < width * height,"render::RawTexture2dBase::SetImage - length cant be less than width*height.");
			for (int i = 0; i < width * height; i++) {
				data[i] = list[i];
			}
		}
		void SetSubImage(size_t x, size_t y, size_t width, size_t height, const T* list, size_t length) {
			STAMPERROR(length < width * height,"render::RawTexture2dBase::SetImage - length cant be less than width*height.");
			STAMPERROR(width > this->width,"render::RawTexture2dBase::SetImage - width cannot be greater than texture width.");
			STAMPERROR(height > this->height,"render::RawTextureBase::SetImage - height cannot be greater than texture height.");
			STAMPERROR(x < 0 || x >= this->width,"render::RawTexture2dBase::SetImage - x out of bounds.");
			STAMPERROR(y < 0 || y >= this->width,"render::RawTexture2dBase::SetImage - y out of bounds.");
			
			for (size_t Y = 0; Y < height; Y++) {
				for (size_t X = 0; X < width; X++) {
					size_t i = X + Y * width;
					size_t j = (X + x) + (Y + y) * this->width;
					data[j] = list[i];
				}
			}
		}
		RawTexture2dBase<T, format, type> GetSubImage(size_t x, size_t y, size_t width, size_t height) {
			STAMPERROR(width > this->width,"render::RawTexture2dBase::SetImage - width cannot be greater than texture width.");
			STAMPERROR(height > this->height,"render::RawTexture2dBase::SetImage - height cannot be greater than texture height.");
			STAMPERROR(x < 0 || x >= this->width,"render::RawTexture2dBase::SetImage - x out of bounds.");
			STAMPERROR(y < 0 || y >= this->width,"render::RawTexture2dBase::SetImage - y out of bounds.");
			RawTexture2dBase<T, format, type> o{width,height};
			for (size_t Y = 0; Y < height; Y++) {
				for (size_t X = 0; X < width; X++) {
					size_t i = X + Y * width;
					size_t j = (X + x) + (Y + y) * this->width;
					o.data[i] = data[j];
				}
			}
			return o;
		}
		size_t Width() const { return width; }
		size_t Height() const { return height; }
		//thread-unsafe
		const T* GetData() const { return &(data[0]); }

		//get subImage
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

	class SamplerBase : public std::enable_shared_from_this<SamplerBase> {
	protected:
		GLuint textureID = 0;
		int activeIndex = 0;
		GLenum target = GL_TEXTURE_2D;
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
		SamplerBase() {
			if (textureBinds == 0) {
				glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &maxTextureUnits);
				textureBinds = new SamplerBase * [maxTextureUnits];
				memset(textureBinds, 0, sizeof(void*) * maxTextureUnits);
			}
		}

		virtual ~SamplerBase() {
			if (textureID != 0) {
				glDeleteTextures(1, &textureID);
				textureID = 0;
			}
			if(activeIndex) {
				textureBinds[activeIndex] = nullptr;
				activeIndex = 0;
			}
		}
		void BindActive() {
			if (activeIndex != 0) return;
			STAMPERROR(textureID == 0,"render::TextureBase::BindActive - uninitialized texture, attempted access failed.");
			int index = -1;
			for(int i = 1; i < maxTextureUnits; i++) {
				if (textureBinds[i] == 0) {
					index = i;
					break;
				}
			}
			if(index == -1) {
				STAMPERROR(textureID == 0,"render::TextureBase::BindActive - no open texture locations.");
				return;
			}
			glActiveTexture(GL_TEXTURE0 + index);
			glBindTexture(target, textureID);
			glActiveTexture(GL_TEXTURE0);
			if(textureBinds[index]) textureBinds[index]->activeIndex = 0;
			textureBinds[index] = this;
			activeIndex = index;
		}
		void UnbindActive() {
			if(textureBinds == 0 || textureID == 0) return;
			//only need to uncomment to force texture to unload instead of replacing later.
			//glActiveTexture(GL_TEXTURE0 + textureID);
			//glBindTexture(target, 0);
			//glActiveTexture(GL_TEXTURE0);
			textureBinds[textureID] = nullptr;
			textureID = 0;
		}
		int GetTextureId() const {
			return textureID;
		}
		int GetTarget() const {
			return target;
		}
		int GetActiveTextureIndex() const {
			return activeIndex;
		}
		void Bind() const {
			STAMPERROR(textureID == 0,"render::TextureBase::Bind - uninitialized texture, attempted access failed.");
			glBindTexture(target, textureID);
		}
		bool isActive() const {
			if (!isValid() || textureBinds == 0 || activeIndex == 0) return false;
			return textureBinds[activeIndex] == this;
		}

		void SetMinFilter(TextureMinFilter minFilter) {
			STAMPERROR(textureID == 0,"render::TextureBase::SetMinFilter - uninitialized texture, attempted modification failed.");
			glBindTexture(target, textureID);
			glTexParameteri(target, GL_TEXTURE_MIN_FILTER, (int)minFilter);
		}
		void SetMagFilter(TextureMagFilter magFilter) {
			STAMPERROR(textureID == 0,"render::TextureBase::SetMagFilter - uninitialized texture, attempted modification failed.");
			GLSTAMPERROR;
			glBindTexture(target, textureID);
			GLSTAMPERROR;
			glTexParameteri(target, GL_TEXTURE_MAG_FILTER, (int)magFilter);
			GLSTAMPERROR;
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

		inline friend void swap(SamplerBase& a, SamplerBase& b) {
			using std::swap;
			swap(a.textureID, b.textureID);
			swap(a.activeIndex, b.activeIndex);
			swap(a.target, b.target);
		}
	};
	class SamplerTexture2d final : public SamplerBase {
		size_t width = 0;
		size_t height = 0;
		size_t mipmapLevels = 0;
		GLenum internalFormat = 0;
	protected:
		void Initialize(size_t width, size_t height, int mipmaps = 1, GLenum internalFormat = GL_RGBA8) {
			InitTexture();
			this->width = width;
			this->height = height;
			this->internalFormat = internalFormat;
			this->mipmapLevels = mipmaps;
			this->target = GL_TEXTURE_2D;
			Bind();
			glTexStorage2D(GL_TEXTURE_2D, mipmapLevels, internalFormat, width, height);
		}
	public:
		SamplerTexture2d() { }
		SamplerTexture2d(size_t width, size_t height,int mipmaps = 1, GLenum internalFormat = GL_RGBA8) {
			Initialize(width, height, mipmaps, internalFormat);
		}
		SamplerTexture2d(const SamplerTexture2d& b) = delete;
		SamplerTexture2d(SamplerTexture2d&& b) noexcept {
			using std::swap;
			swap(*this, b);
		}
		SamplerTexture2d& operator =(const SamplerTexture2d& b) = delete;
		SamplerTexture2d& operator =(SamplerTexture2d&& b) noexcept {
			using std::swap;
			swap(*this, b);
			return *this;
		}
		template<typename T, GLenum format, GLenum type>
		void SetImage(RawTexture2dBase<T, format, type>& tex, int mipmapLevel = 0) {
			STAMPERROR(mipmapLevel >= this->mipmapLevels, "render::ImageTexture2d::SetImage - mipmap above max value assigned");
			STAMPERROR(tex.Width() != Width(mipmapLevel),"render::ImageTexture2d::SetImage - width of mipmap layer not half, rounded down, of previous mipmap layer width");
			STAMPERROR(tex.Height() != Height(mipmapLevel),"render::ImageTexture2d::SetImage - height of mipmap layer not half, rounded down, of previous mipmap layer height");
			Bind();
			GLSTAMPERROR;
			glTexSubImage2D(GL_TEXTURE_2D, mipmapLevel, 0, 0, tex.Width(), tex.Height(), format, type, tex.GetData());
			GLSTAMPERROR;
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
		void Clear() {

		}

		inline friend void swap(SamplerTexture2d& a, SamplerTexture2d& b) {
			using std::swap;
			swap(a.width, b.width);
			swap(a.height, b.height);
			swap(a.mipmapLevels, b.mipmapLevels);
			swap(a.internalFormat, b.internalFormat);
			swap((SamplerBase&)a, (SamplerBase&)b);
		}
	};
	class RawTexture2d4f final : public RawTexture2dBase<math::Vec4f, GL_RGBA, GL_FLOAT> {
	public:
		RawTexture2d4f() : RawTexture2dBase() {}
		RawTexture2d4f(size_t width, size_t height) {
			RawTexture2dBase::Initialize(width, height);
		}
		RawTexture2d4f(const SamplerTexture2d* tex, int mipmap = 0) {
			if(tex == 0) return;
			tex->Bind();
			RawTexture2dBase::Initialize(tex->Width(mipmap), tex->Height(mipmap));
			glGetTexImage(GL_TEXTURE_2D, mipmap, GL_RGBA, GL_FLOAT, (void*)GetData());
		}
		static RawTexture2d4f Screenshot() {
			int x = GetSystemMetrics(SM_XVIRTUALSCREEN);
			int y = GetSystemMetrics(SM_YVIRTUALSCREEN);
			int cx = GetSystemMetrics(SM_CXVIRTUALSCREEN);
			int cy = GetSystemMetrics(SM_CYVIRTUALSCREEN);
			HDC dcScreen = GetDC(0);
			HDC dcTarget = CreateCompatibleDC(dcScreen);
			HBITMAP bmpTarget = CreateCompatibleBitmap(dcScreen, cx, cy);
			HGDIOBJ oldBmp = SelectObject(dcTarget, bmpTarget);
			BitBlt(dcTarget, 0, 0, cx, cy, dcScreen, x, y, SRCCOPY | CAPTUREBLT);
			SelectObject(dcTarget, oldBmp);

			BITMAPINFO MyBMInfo = { 0 };
			MyBMInfo.bmiHeader.biSize = sizeof(MyBMInfo.bmiHeader);

			if (0 == GetDIBits(dcScreen, bmpTarget, 0, 0, NULL, &MyBMInfo, DIB_RGB_COLORS)) {
				std::cout << "render::RawTexture2d4f::Screenshot - error1" << std::endl;
			}

			// create the bitmap buffer
			BYTE* lpPixels = new BYTE[MyBMInfo.bmiHeader.biSizeImage];

			// Better do this here - the original bitmap might have BI_BITFILEDS, which makes it
			// necessary to read the color table - you might not want this.
			MyBMInfo.bmiHeader.biCompression = BI_RGB;

			// get the actual bitmap buffer
			if (0 == GetDIBits(dcScreen, bmpTarget, 0, MyBMInfo.bmiHeader.biHeight, (LPVOID)lpPixels, &MyBMInfo, DIB_RGB_COLORS)) {
				std::cout << "render::RawTexture2d4f::Screenshot - error2" << std::endl;
			}

			DeleteDC(dcTarget);
			ReleaseDC(0,dcScreen);

			uint32_t headerSize = MyBMInfo.bmiHeader.biSize;
			uint32_t bmpDataOffset = 0;
			uint32_t width = 0, height = 0, bpp = 0, compression = 0, imageSize = 0, paletteCount = 0;
			if (headerSize == 40 || headerSize == 52 || headerSize == 124) {
				width = MyBMInfo.bmiHeader.biWidth;
				height = MyBMInfo.bmiHeader.biHeight;
				bpp = MyBMInfo.bmiHeader.biBitCount;
				compression = MyBMInfo.bmiHeader.biCompression;
				imageSize = MyBMInfo.bmiHeader.biSizeImage;
				paletteCount = MyBMInfo.bmiHeader.biClrUsed;
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
					return {};
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

			RawTexture2d4f tex{ width,height };
			int rowSize = ((bpp * width + 31) / 32) * 4;
			if (bpp == 8) {
				std::vector<math::Vec4i> pallete = {};
			}
			else if (bpp == 16) {
				for (uint32_t y = 0; y < height; y++) {
					for (uint32_t x = 0; x < width; x++) {
						uint32_t v = *(uint32_t*)(lpPixels + bmpDataOffset);
						float r = maskR ? (float)((v >> shiftR) & maskR) / maskR : 0;
						float g = maskG ? (float)((v >> shiftG) & maskG) / maskG : 0;
						float b = maskB ? (float)((v >> shiftB) & maskB) / maskB : 0;
						float a = maskA ? (float)((v >> shiftA) & maskA) / maskA : 1;
						tex.SetPixel(x, y, { r,g,b,a });
						bmpDataOffset += sizeof(uint16_t);
					}
					bmpDataOffset += rowSize;
				}
			}
			else if (bpp == 24) {
				for (uint32_t y = 0; y < height; y++) {
					for (uint32_t x = 0; x < width; x++) {
						uint32_t v = *(uint32_t*)(lpPixels + bmpDataOffset);
						float r = maskR ? (float)((v >> shiftR) & maskR) / maskR : 0;
						float g = maskG ? (float)((v >> shiftG) & maskG) / maskG : 0;
						float b = maskB ? (float)((v >> shiftB) & maskB) / maskB : 0;
						float a = maskA ? (float)((v >> shiftA) & maskA) / maskA : 1;
						tex.SetPixel(x, y, { r,g,b,a });
						bmpDataOffset += 3;
					}
					bmpDataOffset += rowSize;
				}
			}
			else if (bpp == 32) {
				for (uint32_t y = 0; y < height; y++) {
					for (uint32_t x = 0; x < width; x++) {
						uint32_t v = *(uint32_t*)(lpPixels + bmpDataOffset);
						float r = maskR ? (float)((v >> shiftR) & maskR) / maskR : 0;
						float g = maskG ? (float)((v >> shiftG) & maskG) / maskG : 0;
						float b = maskB ? (float)((v >> shiftB) & maskB) / maskB : 0;
						float a = maskA ? (float)((v >> shiftA) & maskA) / maskA : 1;
						tex.SetPixel(x, y, { r,g,b,a });
						bmpDataOffset += sizeof(uint32_t);
					}
					bmpDataOffset += rowSize;
				}
			}

			delete[] lpPixels;
			return tex;
		}
		//binary filetype
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
			if (headerSize == 40 || headerSize == 52 || headerSize == 56 || headerSize == 124) {
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
						data.read((char*)&v, 3);
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

	//generic buffer object
	//ubo
	//shader storage buffer (atomic and slower than ubo)
	//transform feedback buffer
	//atomic counter buffer
	class UniformBufferObject : public std::enable_shared_from_this<UniformBufferObject> {
		friend class ShaderProgramBase;
		GLuint ubo = 0;
		int blockIndex = 0;
	protected:
	public:
		void Set(const void* ptr, size_t size, BufferUsageHint usage = BufferUsageHint::StaticDraw) {
			Bind();
			glBufferData(GL_UNIFORM_BUFFER, size, ptr, (GLenum)usage);
		}
		void BindBuffer() {
			if (blockIndex != 0) return;
			STAMPERROR(ubo == 0,"render::UniformBufferObject::BindBuffer - buffer unitialized.");
			int index = -1;
			for(int i = 1; i < maxBlockUnits; i++) {
				if (uniformBlockBinds[i] == 0) {
					index = i;
					break;
				}
			}
			if(index == -1) {
				STAMPERROR(blockIndex == 0,"render::UniformBufferObject::BindBuffer - no free buffer.");
				return;
			}
			glBindBufferBase(GL_UNIFORM_BUFFER, index, ubo);
			if(uniformBlockBinds[index]) uniformBlockBinds[index]->blockIndex = 0;
			uniformBlockBinds[index] = this;
			blockIndex = index;
		}
		void UnbindBuffer() {
			if(uniformBlockBinds == 0 || blockIndex == 0) return;
			//only need to uncomment to force texture to unload instead of replacing later.
			//glBindBufferBase(GL_UNIFORM_BUFFER, blockIndex, 0);
			uniformBlockBinds[blockIndex] = nullptr;
			blockIndex = 0;
		}
		UniformBufferObject() {
			if (uniformBlockBinds == 0) {
				glGetIntegerv(GL_MAX_UNIFORM_BUFFER_BINDINGS, &maxBlockUnits);
				uniformBlockBinds = new UniformBufferObject * [maxBlockUnits];
				memset(uniformBlockBinds, 0, sizeof(void*) * maxBlockUnits);
			}

			glGenBuffers(1, &ubo);
		}
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
		void Bind() {
			STAMPERROR(!isValid(),"render::UniformBufferObject::Bind - failed to Bind ubo: buffer not initialized.");
			glBindBuffer(GL_UNIFORM_BUFFER, ubo);
		}
		bool isActive() const {
			if (!isValid() || uniformBlockBinds == 0 || blockIndex == 0) return false;
			return uniformBlockBinds[blockIndex] == this;
		}
		int getUniformBlockId() {
			return blockIndex;
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
			if(ubo) {
				glDeleteBuffers(1, &ubo);
				ubo = 0;
			}
			if(textureBinds && blockIndex) {
				uniformBlockBinds[blockIndex] = nullptr;
				blockIndex = 0;
			}
		}
	};
	using UBObject = UniformBufferObject;

	class ShaderStorageBufferObject : public std::enable_shared_from_this<ShaderStorageBufferObject> {
		friend class ShaderProgramBase;
		GLuint ssbo = 0;
		int blockIndex = 0;
	protected:
	public:
		void Set(const void* ptr, size_t size, BufferUsageHint usage = BufferUsageHint::StaticDraw) {
			Bind();
			glBufferData(GL_SHADER_STORAGE_BUFFER, size, ptr, (GLenum)usage);
		}
		void BindBuffer() {
			if (blockIndex != 0) return;
			STAMPERROR(ssbo == 0, "render::ShaderStorageBufferObject::BindBuffer - buffer unitialized.");
			int index = -1;
			for (int i = 1; i < maxBlockUnits; i++) {
				if (shaderBlockBinds[i] == 0) {
					index = i;
					break;
				}
			}
			if (index == -1) {
				STAMPERROR(blockIndex == 0, "render::ShaderStorageBufferObject::BindBuffer - no free buffer.");
				return;
			}
			glBindBufferBase(GL_SHADER_STORAGE_BUFFER, index, ssbo);
			if (shaderBlockBinds[index]) shaderBlockBinds[index]->blockIndex = 0;
			shaderBlockBinds[index] = this;
			blockIndex = index;
		}
		void UnbindBuffer() {
			if (shaderBlockBinds == 0 || blockIndex == 0) return;
			//only need to uncomment to force texture to unload instead of replacing later.
			//glBindBufferBase(GL_UNIFORM_BUFFER, blockIndex, 0);
			shaderBlockBinds[blockIndex] = nullptr;
			blockIndex = 0;
		}
		ShaderStorageBufferObject() {
			if (shaderBlockBinds == 0) {
				glGetIntegerv(GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS, &maxBlockUnits);
				shaderBlockBinds = new ShaderStorageBufferObject * [maxBlockUnits];
				memset(shaderBlockBinds, 0, sizeof(void*) * maxBlockUnits);
			}

			glGenBuffers(1, &ssbo);
		}
		ShaderStorageBufferObject(const ShaderStorageBufferObject& other) = delete;
		ShaderStorageBufferObject(ShaderStorageBufferObject&& other) noexcept {
			using std::swap;
			swap(*this, other);
		}
		ShaderStorageBufferObject& operator=(const ShaderStorageBufferObject& other) = delete;
		ShaderStorageBufferObject& operator=(ShaderStorageBufferObject&& other) noexcept {
			using std::swap;
			swap(*this, other);
		}
		void Bind() {
			STAMPERROR(!isValid(), "render::ShaderStorageBufferObject::Bind - failed to Bind ubo: buffer not initialized.");
			glBindBuffer(GL_SHADER_STORAGE_BUFFER, ssbo);
		}
		bool isActive() const {
			if (!isValid() || shaderBlockBinds == 0 || blockIndex == 0) return false;
			return shaderBlockBinds[blockIndex] == this;
		}
		int getUniformBlockId() {
			return blockIndex;
		}

		bool isValid() const {
			return ssbo != 0;
		}
		explicit operator bool() {
			return isValid();
		}
		bool operator!() {
			return !isValid();
		}
		inline friend void swap(ShaderStorageBufferObject& a, ShaderStorageBufferObject& b) {
			using std::swap;
			swap(a.ssbo, b.ssbo);
			swap(a.blockIndex, b.blockIndex);
		}
		~ShaderStorageBufferObject() {
			if (ssbo) {
				glDeleteBuffers(1, &ssbo);
				ssbo = 0;
			}
			if (textureBinds && blockIndex) {
				shaderBlockBinds[blockIndex] = nullptr;
				blockIndex = 0;
			}
		}
	};
	//layout(Binding=0) uniform sampler2D diffuseTex; // set sampler to target texture without assigning uniform
	//layout(location=0) uniform int val; // Bind at location 0
	class ShaderProgramBase : public std::enable_shared_from_this<ShaderProgramBase> {
	public:
		struct ShaderType {
			enum {
				VertexShader = 1,
				TessControlShader = 2,
				TessEvaluationShader = 4,
				GeometryShader = 8,
				FragmentShader = 16,
				ComputeShader = 32,
			};
			int _value;
		};
		inline static const GLenum shaderTypeEnum[]{
			GL_VERTEX_SHADER,  GL_TESS_CONTROL_SHADER, GL_TESS_EVALUATION_SHADER, GL_GEOMETRY_SHADER, GL_FRAGMENT_SHADER, GL_COMPUTE_SHADER
		};
		inline static const std::string shaderDefineScript[]{
			"VERTEX_SHADER\n", "TESS_CONTROL_SHADER\n", "TESS_EVALUATION_SHADER\n", "GEOMETRY_SHADER\n", "FRAGMENT_SHADER\n","COMPUTE_SHADER\n"
		};
	private:
		GLuint program = 0;
		static inline thread_local GLuint currentProgram = 0;

		GLenum ToShaderComp(std::string& version, std::string& progTxt, int index) {
			static GLint compiled = 0;
			static GLchar message[1024]{};
			static GLsizei log_length = 0;
			GLuint comp = glCreateShader(shaderTypeEnum[index]);
			std::string p = version + std::string("#define ") + shaderDefineScript[index] + progTxt;
			
			const char* c = p.c_str();
			glShaderSource(comp, 1, &c, 0);

			glCompileShader(comp);
			glGetShaderiv(comp, GL_COMPILE_STATUS, &compiled);
			if (compiled != GL_TRUE) {
				glGetShaderInfoLog(comp, sizeof(message), &log_length, message);
				STAMPSTACK();
				STAMPDMSG("render::ShaderProgramBase::set - compilation error" << std::endl << message << std::endl << p);
			}
			return comp;
		}
	protected:
		ShaderProgramBase() {}
		void set(std::istream& prog, ShaderType type, const std::vector<std::string>& defines = {}) {
			if (program) glDeleteProgram(program);
			program = glCreateProgram();
			//reseve size of strings?
			std::string version{};
			version.reserve(32);
			std::string progTxt{};
			progTxt.reserve(4096);
			while((bool)prog) {//get version
				char c = prog.get();
				if(c == '\r') continue;
				version += c;
				if(c == '\n') break;
			}
			while((bool)prog) {//get text
				char c = prog.get();
				if(c == '\r' || c == -1) continue;
				progTxt += c;
			}
			for (int i = 0; i < defines.size(); i++) {
				progTxt = std::string("#define ") + defines[i] + std::string("\n") + progTxt;
			}
			static GLint compiled = 0;
			static GLchar message[1024]{};
			static GLsizei log_length = 0;
			std::vector<GLuint> shaderComp{};
			if(type._value & ShaderType::VertexShader) {
				GLenum comp = ToShaderComp(version, progTxt, 0);	
				shaderComp.push_back(comp);
				glAttachShader(program, comp);
			}
			if(type._value & ShaderType::TessControlShader) {
				GLenum comp = ToShaderComp(version, progTxt, 1);	
				shaderComp.push_back(comp);
				glAttachShader(program, comp);
			}
			if(type._value & ShaderType::TessEvaluationShader) {
				GLenum comp = ToShaderComp(version, progTxt, 2);	
				shaderComp.push_back(comp);
				glAttachShader(program, comp);
			}
			if(type._value & ShaderType::GeometryShader) {
				GLenum comp = ToShaderComp(version, progTxt, 3);	
				shaderComp.push_back(comp);
				glAttachShader(program, comp);
			}
			if(type._value & ShaderType::FragmentShader) {
				GLenum comp = ToShaderComp(version, progTxt, 4);	
				shaderComp.push_back(comp);
				glAttachShader(program, comp);
			}
			if(type._value & ShaderType::ComputeShader) {
				GLenum comp = ToShaderComp(version, progTxt, 5);	
				shaderComp.push_back(comp);
				glAttachShader(program, comp);
			}
			glLinkProgram(program);
			glGetProgramiv(program, GL_LINK_STATUS, &compiled);
			if (compiled != GL_TRUE) {
				glGetProgramInfoLog(program, 1024, &log_length, message);
				STAMPSTACK();
				STAMPDMSG("render::ShaderProgramBase::setShader::set - compilation error");
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
		int ProgramID() {
			return program;
		}
		void Bind() {
			if (currentProgram == 0 || currentProgram != program) {
				glUseProgram(program);
				currentProgram = program;
			}
		}
		bool isValid() const {
			return program != 0;
		}
		void Uniform(GLint location, const SamplerBase* value) {
			STAMPERROR(!value->isActive(), "render::ShaderProgramBase::uniform - texture is not active");
			glProgramUniform1i(program, location, value->GetActiveTextureIndex());
		}
		void Uniform(GLint location, int value) {
			glProgramUniform1i(program, location, value);
		}
		void Uniform(GLint location, unsigned int value) {
			glProgramUniform1ui(program, location, value);
		}
		void Uniform(GLint location, float value) {
			glProgramUniform1f(program, location, value);
		}
		void Uniform(GLint location, double value) {
			glProgramUniform1d(program, location, value);
		}
		void Uniform(GLint location, const math::Vec2i& value) {
			glProgramUniform2iv(program, location, 1, (const int*)value);
		}
		void Uniform(GLint location, const math::Vec2ui& value) {
			glProgramUniform2uiv(program, location, 1, (const unsigned int*)value);
		}
		void Uniform(GLint location, const math::Vec2f& value) {
			glProgramUniform2fv(program, location, 1, (const float*)value);
		}
		void Uniform(GLint location, const math::Vec2d& value) {
			glProgramUniform2dv(program, location, 1, (const double*)value);
		}
		void Uniform(GLint location, const math::Vec3i& value) {
			glProgramUniform3iv(program, location, 1, (const int*)value);
		}
		void Uniform(GLint location, const math::Vec3ui& value) {
			glProgramUniform3uiv(program, location, 1, (const unsigned int*)value);
		}
		void Uniform(GLint location, const math::Vec3f& value) {
			glProgramUniform3fv(program, location, 1, (const float*)value);
		}
		void Uniform(GLint location, const math::Vec3d& value) {
			glProgramUniform3dv(program, location, 1, (const double*)value);
		}
		void Uniform(GLint location, const math::Vec4i& value) {
			glProgramUniform4iv(program, location, 1, (const int*)value);
		}
		void Uniform(GLint location, const math::Vec4ui& value) {
			glProgramUniform4uiv(program, location, 1, (const unsigned int*)value);
		}
		void Uniform(GLint location, const math::Vec4f& value) {
			glProgramUniform4fv(program, location, 1, (const float*)value);
		}
		void Uniform(GLint location, const math::Vec4d& value) {
			glProgramUniform4dv(program, location, 1, (const double*)value);
		}
		void Uniform(GLint location, const math::Quati& value) {
			glProgramUniform4iv(program, location, 1, (const int*)value);
		}
		void Uniform(GLint location, const math::Quatui& value) {
			glProgramUniform4uiv(program, location, 1, (const unsigned int*)value);
		}
		void Uniform(GLint location, const math::Quatf& value) {
			glProgramUniform4fv(program, location, 1, (const float*)value);
		}
		void Uniform(GLint location, const math::Quatd& value) {
			glProgramUniform4dv(program, location, 1, (const double*)value);
		}
		void Uniform(GLint location, const math::Mat4f& value) {
			glProgramUniformMatrix4fv(program, location, 1, false, (const float*)value);
		}
		void Uniform(GLint location, const math::Mat4d& value) {
			glProgramUniformMatrix4dv(program, location, 1, false, (const double*)value);
		}
		void Uniform(GLint location, const int* value, GLsizei count) {
			glProgramUniform1iv(program, location, count, value);
		}
		void Uniform(GLint location, const unsigned int* value, int count) {
			glProgramUniform1uiv(program, location, count, value);
		}
		void Uniform(GLint location, const float* value, int count) {
			glProgramUniform1fv(program, location, count, value);
		}
		void Uniform(GLint location, const double* value, int count) {
			glProgramUniform1dv(program, location, count, value);
		}
		void Uniform(GLint location, const math::Vec2i* value, int count) {
			glProgramUniform2iv(program, location, count, (const int*)value);
		}
		void Uniform(GLint location, const math::Vec2ui* value, int count) {
			glProgramUniform2uiv(program, location, count, (const unsigned int*)value);
		}
		void Uniform(GLint location, const math::Vec2f* value, int count) {
			glProgramUniform2fv(program, location, count, (const float*)value);
		}
		void Uniform(GLint location, const math::Vec2d* value, int count) {
			glProgramUniform2dv(program, location, count, (const double*)value);
		}
		void Uniform(GLint location, const math::Vec3i* value, int count) {
			glProgramUniform3iv(program, location, count, (const int*)value);
		}
		void Uniform(GLint location, const math::Vec3ui* value, int count) {
			glProgramUniform3uiv(program, location, count, (const unsigned int*)value);
		}
		void Uniform(GLint location, const math::Vec3f* value, int count) {
			glProgramUniform3fv(program, location, count, (const float*)value);
		}
		void Uniform(GLint location, const math::Vec3d* value, int count) {
			glProgramUniform3dv(program, location, count, (const double*)value);
		}
		void Uniform(GLint location, const math::Vec4i* value, int count) {
			glProgramUniform4iv(program, location, count, (const int*)value);
		}
		void Uniform(GLint location, const math::Vec4ui* value, int count) {
			glProgramUniform4uiv(program, location, count, (const unsigned int*)value);
		}
		void Uniform(GLint location, const math::Vec4f* value, int count) {
			glProgramUniform4fv(program, location, count, (const float*)value);
		}
		void Uniform(GLint location, const math::Vec4d* value, int count) {
			glProgramUniform4dv(program, location, count, (const double*)value);
		}
		void Uniform(GLint location, const math::Quati* value, int count) {
			glProgramUniform4iv(program, location, count, (const int*)value);
		}
		void Uniform(GLint location, const math::Quatui* value, int count) {
			glProgramUniform4uiv(program, location, count, (const unsigned int*)value);
		}
		void Uniform(GLint location, const math::Quatf* value, int count) {
			glProgramUniform4fv(program, location, count, (const float*)value);
		}
		void Uniform(GLint location, const math::Quatd* value, int count) {
			glProgramUniform4dv(program, location, count, (const double*)value);
		}
		void Uniform(GLint location, const math::Mat4f* value, int count) {
			glProgramUniformMatrix4fv(program, location, count, false, (const float*)value);
		}
		void Uniform(GLint location, const math::Mat4d* value, int count) {
			glProgramUniformMatrix4dv(program, location, count, false, (const double*)value);
		}
		void UniformBuffer(GLint location, const UniformBufferObject& value) {
			STAMPERROR(!value.isActive(), "render::ShaderProgramBase::uniformBuffer - UBO is not active");
			glUniformBlockBinding(program, location, value.blockIndex);
		}
		//void ShaderStorageBuffer(GLint location, const ShaderStorageBufferObject& value) {
		//	STAMPERROR(value.isActive(), "render::ShaderProgramBase::uniformBuffer - UBO is not active");
		//	glShaderStorageBlockBinding(program, location, value.blockIndex);
		//}
		void UniformBuffer(GLint location, int index) {
			glUniformBlockBinding(program, location, index);
		}
		void ShaderStorageBuffer(GLint location, int index) {
			glShaderStorageBlockBinding(program, location, index);
		}
		GLint GetUniformLocation(const char* name) {
			return glGetUniformLocation(program, name);
		}
		GLint GetUniformBufferLocation(const char* name) {
			return glGetUniformBlockIndex(program, name);
		}
		GLint GetUniformIndex(const char* name) {
			return glGetProgramResourceIndex(program, GL_UNIFORM, name);
		}
		GLint GetUniformBlockIndex(const char* name) {
			return glGetProgramResourceIndex(program, GL_UNIFORM_BLOCK, name);
		}
		GLint GetShaderStorageIndex(const char* name) {
			return glGetProgramResourceIndex(program, GL_SHADER_STORAGE_BLOCK, name);
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
		inline static std::shared_ptr<RenderShaderProgram> ParseStream_glsl(std::istream& prog, ShaderType type, const std::vector<std::string>& defines = {}) {
			std::shared_ptr<RenderShaderProgram> r{ new RenderShaderProgram ()};
			r->ShaderProgramBase::set(prog, { ShaderType::VertexShader | ShaderType::FragmentShader | type._value }, defines);
			return r;
		}
	};
	class ComputeShaderProgram final : public ShaderProgramBase {
	public:
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
			Bind();
			glDispatchCompute(groupsX, groupsY, groupsZ);
		}
		virtual ~ComputeShaderProgram() { }
		inline static std::shared_ptr<ComputeShaderProgram> ParseStream_glsl(std::istream& prog) {
			std::shared_ptr<ComputeShaderProgram> r{ new ComputeShaderProgram() };
			r->ShaderProgramBase::set(prog, { ShaderType::ComputeShader });
			return r;
		}
	};
	class MaterialBase : public std::enable_shared_from_this<MaterialBase> {
		GLuint vao = 0;
	protected:
		MaterialBase() { 
			glGenVertexArrays(1, &vao);
			glBindVertexArray(vao);
		}
		MaterialBase(const MaterialBase& other) = delete;
		MaterialBase& operator =(const MaterialBase& other) = delete;
		virtual void UpdateMaterial() = 0;
	public:
		std::shared_ptr<ShaderProgramBase> shader{};
		virtual void Render(Mesh* mesh, const math::Mat4f& transform, UniformBufferObject* camera) = 0;
		void UpdateMeshAttrib(Mesh* mesh) {
			if (!mesh) return;
			Bind();
			mesh->Bind();
			mesh->setMaterial(*this);
			UpdateMaterial();
		}
		void Bind() {
			STAMPERROR(!isValid(),"render::MaterialBase::Bind - failed to Bind mesh: mesh does not have allocated buffers.");
			glBindVertexArray(vao);
			shader->Bind();
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
		int blockBindingCamera = -1;

		virtual void UpdateMaterial() {
			glEnableVertexAttribArray(ATTRIBPOINTER_POSITION);
			glEnableVertexAttribArray(ATTRIBPOINTER_NORMAL);
			glEnableVertexAttribArray(ATTRIBPOINTER_UV);
			if (useVertexColorValue) {
				glEnableVertexAttribArray(ATTRIBPOINTER_COLOR);
			}
			else {
				glVertexAttrib4fv(ATTRIBPOINTER_COLOR, (const float*)color);
				glDisableVertexAttribArray(ATTRIBPOINTER_COLOR);
			}

			blockBindingCamera = shader->GetUniformBufferLocation("ST_Camera");
			if (texture != 0) texture->BindActive();
			if (normalMap != 0) normalMap->BindActive();
		}
	public:
		math::Vec4f color{ 0.8f,0.8f,0.8f,1 };
		bool useVertexColorValue = false;
		std::shared_ptr<SamplerTexture2d> texture;
		std::shared_ptr<SamplerTexture2d> normalMap;
		SolidMaterial() {}
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
		virtual void Render(Mesh* mesh, const math::Mat4f& transform, UniformBufferObject* camera) {
			Bind();
			if (texture != 0) shader->Uniform(UNIFORM_TEXTURE0, texture.get());
			if (normalMap != 0) shader->Uniform(UNIFORM_NORMALMAP, normalMap.get());
			shader->UniformBuffer(blockBindingCamera, *camera);
			shader->Uniform(UNIFORM_TRANSFORM, transform);
			mesh->RenderArray();
		}
		inline friend void swap(SolidMaterial& a, SolidMaterial& b) noexcept {
			using std::swap;
			swap((MaterialBase&)a, (MaterialBase&)b);
			swap(a.blockBindingCamera, b.blockBindingCamera);
			swap(a.color, b.color);
			swap(a.useVertexColorValue, b.useVertexColorValue);
			swap(a.texture, b.texture);
			swap(a.normalMap, b.normalMap);
		}
		virtual ~SolidMaterial() {}
	};
	class UIMaterial final : public MaterialBase {
		int blockBindingCamera = -1;
		int blockBindingUIMaterial = -1;
		UniformBufferObject ubo{};

		virtual void UpdateMaterial() {
			GLSTAMPERROR;
			glEnableVertexAttribArray(ATTRIBPOINTER_POSITION);
			glEnableVertexAttribArray(ATTRIBPOINTER_NORMAL);
			glEnableVertexAttribArray(ATTRIBPOINTER_UV);
			glDisableVertexAttribArray(ATTRIBPOINTER_COLOR);

			blockBindingCamera = shader->GetUniformBufferLocation("ST_Camera");
			blockBindingUIMaterial = shader->GetUniformBufferLocation("ST_UIMAT");
			if (texture != 0) texture->BindActive();

			struct UIMaterial_t {
				GLboolean texture0;
			} uimat{};
			uimat.texture0 = texture != 0;
			ubo.Set(&uimat, sizeof(uimat), render::BufferUsageHint::DynamicDraw);
			ubo.BindBuffer();
			GLSTAMPERROR;
		}
	public:
		math::Vec4f color{ 0.8f,0.8f,0.8f,1 };
		std::shared_ptr<SamplerTexture2d> texture;
		UIMaterial() {}
		UIMaterial(const UIMaterial& other) = delete;
		UIMaterial(UIMaterial&& other) noexcept {
			using std::swap;
			swap(*this, other);
		}
		UIMaterial& operator =(const UIMaterial& other) = delete;
		UIMaterial& operator =(UIMaterial&& other) noexcept {
			using std::swap;
			swap(*this, other);
		}
		virtual void Render(Mesh* mesh, const math::Mat4f& transform, UniformBufferObject* camera) {
			GLSTAMPERROR;
			Bind();
			if (texture != 0) shader->Uniform(UNIFORM_TEXTURE0, texture.get());
			shader->UniformBuffer(blockBindingCamera, *camera);
			shader->UniformBuffer(blockBindingUIMaterial, ubo);
			shader->Uniform(UNIFORM_TRANSFORM, transform);
			glVertexAttrib4fv(ATTRIBPOINTER_COLOR, (const float*)color);
			mesh->RenderArray();
			GLSTAMPERROR;
		}
		inline friend void swap(UIMaterial& a, UIMaterial& b) noexcept {
			using std::swap;
			swap((MaterialBase&)a, (MaterialBase&)b);
			swap(a.blockBindingCamera, b.blockBindingCamera);
			swap(a.blockBindingUIMaterial, b.blockBindingUIMaterial);
			swap(a.ubo, b.ubo);
			swap(a.color, b.color);
			swap(a.texture, b.texture);
		}
		virtual ~UIMaterial() {}
	};

	class Transform final : public std::enable_shared_from_this<Transform> {
	public:
		math::Vec3f position {0,0,0};
		math::Vec3f scale { 1,1,1 };
		math::Quatf rotation { 1,0,0,0 };

		void Rotate(float x, float y, float z) {
			rotation = math::Quatf::RotationZXY(x, y, z) * rotation;
		}
		void LookAt(const math::Vec3f& pos) {
			math::Vec3f v = pos - position;
			rotation = math::Quatf::LookAt(v.x, v.y, v.z);
		}

		math::Mat4f toMatrix() {
			return math::Mat4f::Translate(position.x, position.y, position.z) * rotation.ToRotationMatrix() * math::Mat4f::Scale(scale.x, scale.y, scale.z);
		}
		math::Mat4f toMatrixInverse() {
			return rotation.Conjugate().ToRotationMatrix() * math::Mat4f::Translate(-position.x, -position.y, -position.z);
		}
	};

	class FrameBuffer2d final : public std::enable_shared_from_this<FrameBuffer2d> {
		GLuint id = 0;
		std::vector<GLenum> colorAttachmentTypes{};
	public:
		std::vector<SamplerTexture2d> colorAttachments{};
		SamplerTexture2d depthStencil{};
		FrameBuffer2d(std::vector<GLenum> colorAttachmentTypes, int width = 0, int height = 0) {
			getInitId();
			glGenFramebuffers(1, &id);
			this->colorAttachmentTypes = colorAttachmentTypes;
			colorAttachments.resize (colorAttachmentTypes.size());
			if(width != 0 && height != 0) Resize(width, height);
			Bind();//0x8cdd - GL_FRAMEBUFFER_UNSUPPORTED is returned if the combination of internal formats of the attached images violates an implementation-dependent set of restrictions.
			if (width != 0 && height != 0) STAMPERROR(!IsValid(), "render::FrameBuffer2d - failed creation: 0x" << std::hex << glCheckFramebufferStatus(GL_DRAW_FRAMEBUFFER));
		}
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
			swap(a.colorAttachments, b.colorAttachments);
			swap(a.colorAttachmentTypes, b.colorAttachmentTypes);
			swap(a.depthStencil, b.depthStencil);
		}
		~FrameBuffer2d() {
			if (id) glDeleteFramebuffers(1, &id);
			id = 0;
		}
		void ResizeToScreen(float scale = 1) {
			wm::Rect rect = wm::CurrentWindow()->GetGameRect();
			Resize(ceil(rect.width * scale), ceil(rect.height * scale));
		}
		void Resize(size_t width = 0, size_t height = 0) {
			if (width == 0 || height == 0) {
				wm::Rect rect = wm::CurrentWindow()->GetClientRect();
				width = rect.width;
				height = rect.height;
			}
			for (int i = 0; i < colorAttachments.size(); i++) {
				colorAttachments[i] = SamplerTexture2d{width, height, 1, colorAttachmentTypes[i]};
			}
			depthStencil = SamplerTexture2d(width, height, 1, GL_DEPTH24_STENCIL8);

			glBindFramebuffer(GL_FRAMEBUFFER, id);
			for (int i = 0; i < colorAttachments.size(); i++) {
				glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + i, colorAttachments[i].GetTarget(), colorAttachments[i].GetTextureId(), 0);
			}
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, depthStencil.GetTarget(), depthStencil.GetTextureId(), 0);
		}
		void Bind(int colorAttachmentIndex = 0) {
			glBindFramebuffer(GL_FRAMEBUFFER, id);
			std::unique_ptr<GLenum> buffer{ new GLenum[colorAttachments.size()] };
			for (int i = 0; i < colorAttachments.size(); i++) {
				buffer.get()[i] = GL_COLOR_ATTACHMENT0 + i;
			}
			glDrawBuffers(colorAttachments.size(), buffer.get());
			glViewport(0, 0, colorAttachments[colorAttachmentIndex].Width(), colorAttachments[colorAttachmentIndex].Height());
		}
		// void BindActive(int startUniformIndex) {
		//
		// }

		bool IsValid() {
			glBindFramebuffer(GL_FRAMEBUFFER, id);
			return glCheckFramebufferStatus(GL_DRAW_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE;
		}

		static GLuint getInitId() {
			if (initFBO == -1) glGetIntegerv(GL_FRAMEBUFFER_BINDING, &initFBO);
			return initFBO;
		}

		GLuint getId() {
			return id;
		}
	};
	/*class PostProcessManager final : public std::enable_shared_from_this<PostProcessManager> {
	public:
		std::shared_ptr<ComputeShaderProgram> shader{ 0 };
		FrameBuffer2d buffer;
		PostProcessManager(std::shared_ptr<ComputeShaderProgram> shader, int drawBuffers) : buffer{ drawBuffers } {
			this->shader = shader;
		}
		void ResizeToScreen() {
			buffer.ResizeToScreen();
		}
		void Dispatch() {
			shader->Dispatch(32, 32, 1);
			buffer.CopyContentToScreen();
		}
	};*/

	class OceanRenderObject : public std::enable_shared_from_this<OceanRenderObject> {
		int blockBindingCamera = -1;
		int blockBindingOcean = -1;
		GLuint vao = 0;
	public:
		int width = 40;
		int height = 40;
		float scale = 1;
		bool depthTest = true;
		float vertOffset = 0;
		std::shared_ptr<ShaderProgramBase> shader;
		std::shared_ptr<SamplerTexture2d> noiseTex;
		UniformBufferObject OceanObj{};
		OceanRenderObject() {
			glGenVertexArrays(1, &vao);
		}
		void UpdateRenderer() {
			if (blockBindingCamera == -1) blockBindingCamera = shader->GetUniformBufferLocation("ST_Camera");
			if(blockBindingOcean == -1) blockBindingOcean = shader->GetUniformBufferLocation("ST_Ocean");


			if (noiseTex != 0) noiseTex->BindActive();
			glBindVertexArray(vao);
		}

		void Render(const math::Mat4f& transform, UniformBufferObject& camera) {
			struct Data {
				GLfloat time;
				GLint width;
				GLint height;
				GLint Vy;
				GLint count;
				GLfloat scale;
				GLfloat vertOffset;
				math::GLvec3 origin;
			};

			Data d{};
			d.scale = scale;
			d.vertOffset = vertOffset;
			d.time = wm::CurrentWindow()->Time();
			d.width = width;
			d.height = height;
			d.Vy = 4 + 2 * height;
			d.count = d.Vy * width - 1;
			d.origin = (math::Vec3f)(transform * math::Vec3f(0, 0, 0));
			OceanObj.Set(&d, sizeof(Data), BufferUsageHint::StreamDraw);

			glBindVertexArray(vao);
			shader->UniformBuffer(blockBindingCamera, camera);
			shader->UniformBuffer(blockBindingOcean, OceanObj);
			shader->Uniform(UNIFORM_TRANSFORM, transform);
			if (noiseTex != 0) shader->Uniform(UNIFORM_TEXTURE0, noiseTex.get());
			shader->Bind();
			if (!depthTest) {
				glDepthMask(GL_FALSE);
			}
			glEnable(GL_BLEND);
			glDrawArrays(GL_TRIANGLE_STRIP, 0, d.count);//GL_TRIANGLE_STRIP GL_LINE_STRIP
			glDisable(GL_BLEND);
			if (!depthTest) {
				glDepthMask(GL_TRUE);
			}
			GLSTAMPERROR;
		}
		~OceanRenderObject() {
			if (vao != 0) {
				glDeleteVertexArrays(1, &vao);
				vao = 0;
			}
		}
	};

	class FontMap : public std::enable_shared_from_this<FontMap> {
		struct FontMapEntry {
			unsigned short X;
			unsigned short Y;
			unsigned char width;
			unsigned char height;
			unsigned char yOffset;
		};

		std::map<int, FontMapEntry> fontMap{};
		size_t lineHeight;

		static char fromHex(char c) {
			if (c >= '0' && c <= '9') return c - '0';
			else if (c >= 'A' && c <= 'F') return c - 'A';
			else if (c >= 'a' && c <= 'f') return c - 'a';
			return -1;
		}
	public:
		struct FontMapItem {
			math::Vec2f uvTR;
			math::Vec2f uvTL;
			math::Vec2f uvBR;
			math::Vec2f uvBL;
			unsigned char width;
			unsigned char height;
			unsigned char yOffset;
		};

		std::shared_ptr<SamplerTexture2d> texture = 0;

		static unsigned int ParseUTF8Char(char* txt, size_t& index, size_t size) {
			size_t i = index;
			if (size - index >= 1 && (txt[i] & 0x80) == 0) {
				index += 1;
				return txt[i];
			}
			else if (size - index >= 2 && (txt[i] & 0xE0) == 0xC0) {
				index += 2;
				return ((txt[i] & 0x1F) << 6) | (txt[i + 1] & 0x3F);
			}
			else if (size - index >= 3 && (txt[i] & 0xF0) == 0xE0) {
				index += 3;
				return ((txt[i] & 0x0F) << 12) | ((txt[i + 1] & 0x3F) << 6) | (txt[i + 2] & 0x3F);
			}
			else if (size - index >= 4 && (txt[0] & 0xF8) == 0xF0) {
				index += 4;
				return ((txt[i] & 0x07) << 18) | ((txt[i + 1] & 0x3F) << 12) | ((txt[i + 2] & 0x3F) << 6) | (txt[i + 3] & 0x3F);
			}
			else {
				index++;
				return 0xFFFD;
			}
		}

		// text file
		// relative to topleft
		// line height
		// [CHARACTER] X Y width height
		static std::shared_ptr<FontMap> Parse_fmp(std::istream& stream, std::shared_ptr<SamplerTexture2d> texture = 0) {
			std::shared_ptr< FontMap> map = std::shared_ptr< FontMap>{ new FontMap()};
			if (texture) map->texture = texture;

			uint32_t character;
			std::string word{};
			word.reserve(1024);
			uint32_t X, Y, width, height, yOffset;
			stream >> map->lineHeight;
			while (stream.good()) {
				word.clear();
				stream >> word;
				if (!stream.good()) break;
				if (word.size() >= 3 && word[0] == 'U' && word[1] == '+') {
					character = 0;
					for (int i = 2; i < word.size(); i++) {
						character <<= 4;
						character |= fromHex(word[i]);
					}
				}
				else {
					size_t index = 0;
					character = ParseUTF8Char(word.data(), index, word.size());
				}
				stream >> X;
				if (!stream.good()) break;
				stream >> Y;
				if (!stream.good()) break;
				stream >> width;
				if (!stream.good()) break;
				stream >> height;
				if (!stream.good()) break;
				stream >> yOffset;
				if (!stream.good()) break;

				map->fontMap.insert({ character, FontMapEntry{
					(unsigned short)X,
					(unsigned short)Y,
					(unsigned char)width,
					(unsigned char)height,
					(unsigned char)yOffset
				} });
			}
			return map;
		}

		FontMapItem getCharData(int utf8char) {
			if (!texture) return {};
			if (!fontMap.contains(utf8char)) return {};
			FontMapEntry entry = fontMap[utf8char];
			FontMapItem item{};
			item.uvBL = { (float)(entry.X) / texture->Width(), (float)(texture->Height() - entry.Y) / texture->Width() };
			item.uvBR = { (float)(entry.X + entry.width) / texture->Width(), (float)(texture->Height() - entry.Y) / texture->Width() };
			item.uvTL = { (float)(entry.X) / texture->Width(), (float)(texture->Height() - entry.Y - entry.height) / texture->Width() };
			item.uvTR = { (float)(entry.X + entry.width) / texture->Width(), (float)(texture->Height() - entry.Y - entry.height) / texture->Width() };
			item.width = entry.width;
			item.height = entry.height;
			item.yOffset = entry.yOffset;
			return item;
		}

		size_t LineHeight() {
			return lineHeight;
		}
	};
}

//animation 
//post process shader
//compute shader
//texture
//text texture
//text to mesh
//mesh renderer
//ui mesh renderer
