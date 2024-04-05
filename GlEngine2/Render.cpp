#include <windows.h>
#include "glrender.h"
#include <memory>
#include <bit>

int currentLightIndex = 0;

const char* nextLine(const char* v) {
	do {
		if (!*v) return 0;
		v++;
	} while (v[-1] != '\n');
	return v;
}

void game_component::RectTransform::Update() {

}
game_render::FontMap game_render::FontMap::ParseMap(const char* txt, Texture& ref) {
	std::shared_ptr<gl_math::Rect> v = std::shared_ptr<gl_math::Rect>{ new gl_math::Rect[256] };
	for (const char* t = txt; t && *t; t = nextLine(t)) {
		int x;
		int y;
		int w;
		int h;
		int ox = 0;
		int oy;
		int c;
		int k = sscanf_s(t, "\\%d %d %d %d %d %d", &c, &x, &y, &w, &h, &oy);
		y = ref.Height() - y - h;
		if (k == 5) {
			v.get()[c] = gl_math::Rect{ (float)x / ref.Width(),(float)y / ref.Height(),(float)w / ref.Width(),(float)h / ref.Height() };
		}
		else if (k == 6) {
			v.get()[c] = gl_math::Rect{ (float)x / ref.Width(),(float)y / ref.Height(),(float)w / ref.Width(),(float)h / ref.Height(), (float)ox / ref.Width(), (float)oy / ref.Height() };
		}
		k = sscanf_s(t, "%1c %d %d %d %d %d", (char*)&c, 1, &x, &y, &w, &h, &oy);
		y = ref.Height() - y - h;
		if (k == 5) {
			v.get()[c] = gl_math::Rect{ (float)x/ref.Width(),(float)y / ref.Height(),(float)w / ref.Width(),(float)h / ref.Height() };
		}
		else if (k == 6) {
			v.get()[c] = gl_math::Rect{ (float)x / ref.Width(),(float)y / ref.Height(),(float)w / ref.Width(),(float)h / ref.Height(), (float)ox / ref.Width(), (float)oy / ref.Height() };
		}
	}
	return {v,256};
}
void game_render::TextMesh::setText(const char* txt, float scale, float horizGap, float vertGap, TextAlignment alignment) {
	std::vector<gl_math::Rect> rects{};
	float sx = scale / map.positions.get()['M'].w;
	float sy = scale / map.positions.get()['M'].h;
	for (const char* t = txt; *t; t++) {
		if (*t >= map.length) continue;
		auto v = map.positions.get()[*t];
		rects.push_back(v);
	}
	gl_math::Vec3 v{0,0,0};

	vertices_length = rects.size() * 6;
	vert_positions = std::shared_ptr<gl_math::Vec3>{ new gl_math::Vec3[rects.size() * 6] };
	vert_uvs = std::shared_ptr<gl_math::Vec2>{ new gl_math::Vec2[rects.size() * 6] };
	vert_normals = std::shared_ptr<gl_math::Vec3>{ new gl_math::Vec3[rects.size() * 6] };
	for (int i = 0; i < rects.size(); i++) {
		float w = rects[i].w*sx;
		float h = rects[i].h*sy;
		float x = rects[i].x;
		float y = rects[i].y;
		float oy = rects[i].oy * sy;
		vert_positions.get()[i * 6 + 0] = v + gl_math::Vec3{ 0,-oy,0};
		vert_positions.get()[i * 6 + 1] = v + gl_math::Vec3{ w,-oy,0 };
		vert_positions.get()[i * 6 + 2] = v + gl_math::Vec3{w,h-oy,0};
		vert_positions.get()[i * 6 + 3] = v + gl_math::Vec3{ 0,-oy,0 };
		vert_positions.get()[i * 6 + 4] = v + gl_math::Vec3{ w,h - oy,0 };
		vert_positions.get()[i * 6 + 5] = v + gl_math::Vec3{ 0,h - oy,0 };
		vert_normals.get()[i * 6 + 0] = { 0,1,0 };
		vert_normals.get()[i * 6 + 1] = { 0,1,0 };
		vert_normals.get()[i * 6 + 2] = { 0,1,0 };
		vert_normals.get()[i * 6 + 3] = { 0,1,0 };
		vert_normals.get()[i * 6 + 4] = { 0,1,0 };
		vert_normals.get()[i * 6 + 5] = { 0,1,0 };
		vert_uvs.get()[i * 6 + 0] = { x,y };
		vert_uvs.get()[i * 6 + 1] = { x + rects[i].w,y };
		vert_uvs.get()[i * 6 + 2] = { x + rects[i].w,y + rects[i].h };
		vert_uvs.get()[i * 6 + 3] = { x,y };
		vert_uvs.get()[i * 6 + 4] = { x + rects[i].w,y + rects[i].h };
		vert_uvs.get()[i * 6 + 5] = { x,y + rects[i].h };
		v += {w+ horizGap, 0, 0};
	}
}
void game_render::TextMesh::Render(const gl_math::Mat4& transform) const {
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(transform);
	if (vert_positions) {
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, sizeof(gl_math::Vec3), (const void*)vert_positions.get());
	}
	else glDisableClientState(GL_VERTEX_ARRAY);
	if (vert_normals) {
		glEnableClientState(GL_NORMAL_ARRAY);
		glNormalPointer(GL_FLOAT, sizeof(gl_math::Vec3), (const void*)vert_normals.get());
	}
	else glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
	if (vert_uvs) {
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glTexCoordPointer(2, GL_FLOAT, sizeof(gl_math::Vec2), (const void*)vert_uvs.get());
	}
	else glDisableClientState(GL_TEXTURE_COORD_ARRAY);

	glDrawArrays(GL_TRIANGLES, 0, (GLsizei)vertices_length);
}
game_render::Texture::Texture() {
	this->width = 0;
	this->height = 0;
	this->id = {};
}
game_render::Texture::Texture(size_t width, size_t height, int elementSize, GLenum type, const void* pixels) {
	this->id = std::shared_ptr<GLuint>{new GLuint(0)};
	glGenTextures(1, id.get());
	Bind();
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	this->width = width;
	this->height = height;
	setPixels(elementSize, type, pixels);
}
game_render::Texture::Texture(const Texture& v) {
	width = v.width;
	height = v.height;
	id = v.id;
}
game_render::Texture::Texture(Texture&& v) noexcept  {
	this->width = 0;
	this->height = 0;
	this->id = id;
	swap(*this, v);
}
game_render::Texture& game_render::Texture::operator=(const Texture& v) {
	width = v.width;
	height = v.height;
	id = v.id;
	return *this;
}
game_render::Texture& game_render::Texture::operator=(Texture&& v) noexcept {
	swap(*this, v);
	return *this;
}
inline void game_render::swap(Texture& a, Texture& b) {
	using std::swap;
	swap(a.width, b.width);
	swap(a.height, b.height);
	swap(a.id, b.id);
}
size_t game_render::Texture::Width() const {
	return width;
}
size_t game_render::Texture::Height() const {
	return height;
}
void game_render::Texture::setPixels(int elementSize, GLenum type, const void* pixels) {
	GLenum v[] = { GL_LUMINANCE, GL_LUMINANCE_ALPHA, GL_RGB, GL_RGBA };
	Bind();
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei)width, (GLsizei)height, 0, v[elementSize - 1], type, pixels);
}
game_render::Texture::operator bool() const
{
	return (width != 0 || height != 0) && id.get() != 0;
}
static long SwapBigEndian(long v) {
	if (std::endian::native == std::endian::big) {//big endian
		return v;
	}
	else {
		char* c = (char*)&v;
		std::swap(c[0], c[3]);
		std::swap(c[1], c[2]);
		return v;
	}
}
game_render::Texture game_render::Texture::BmpTexture(const char* d)
{
	const uint8_t* data = (const uint8_t*)d;
	if (!data || data[0] != 'B' || data[1] != 'M') return {};
	uint32_t bmpSize = *(uint32_t*)(data + 2);
	const uint8_t* pixelArray = (uint8_t*)data + *(uint32_t*)(data + 10);
	uint32_t headerSize = *(uint32_t*)(data + 14);
	const uint8_t* palleteArray = data + headerSize + 14;
	uint32_t width = 0, height = 0, bpp = 0, compression = 0, imageSize = 0, paletteCount = 0;
	if (headerSize == 40 || headerSize == 52 || headerSize == 124) {
		width = *(uint32_t*)(data + 18);
		height = *(uint32_t*)(data + 22);
		bpp = *(uint16_t*)(data + 28);
		compression = *(uint32_t*)(data + 30);
		imageSize = *(uint32_t*)(data + 34);
		paletteCount = *(uint32_t*)(data + 46);
	}
	else return {};
	uint32_t maskA = 0;
	uint32_t maskR = 0xFF;
	uint32_t maskG = 0xFF;
	uint32_t maskB = 0xFF;
	int shiftA = 0;
	int shiftR = 0;
	int shiftG = 8;
	int shiftB = 16;
	if (compression != 0) {
		if (compression == 3) {
			maskR = SwapBigEndian(*(uint32_t*)(data + 54 + 0));
			maskG = SwapBigEndian(*(uint32_t*)(data + 54 + 4));
			maskB = SwapBigEndian(*(uint32_t*)(data + 54 + 8));
			maskA = SwapBigEndian(*(uint32_t*)(data + 54 + 12));
		}
		else if (compression == 6) {
			maskR = SwapBigEndian(*(uint32_t*)(data + 54 + 0));
			maskG = SwapBigEndian(*(uint32_t*)(data + 54 + 4));
			maskB = SwapBigEndian(*(uint32_t*)(data + 54 + 8));
			maskA = SwapBigEndian(*(uint32_t*)(data + 54 + 12));
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

	gl_math::Vec4* pixels = new gl_math::Vec4[width * height];
	int rowSize = ((bpp * width + 31) / 32) * 4;
	if (bpp == 8) {
		std::vector<gl_math::Vec4> pallete = {};
	}
	else if (bpp == 16) {
		for (uint32_t y = 0; y < height; y++) {
			const uint8_t* pix = pixelArray;
			for (uint32_t x = 0; x < width; x++) {
				uint32_t v = (*(pix++)) << 8 | (*(pix++));
				float r = maskR ? (float)((v >> shiftR) & maskR) / maskR : 0;
				float g = maskG ? (float)((v >> shiftG) & maskG) / maskG : 0;
				float b = maskB ? (float)((v >> shiftB) & maskB) / maskB : 0;
				float a = maskA ? (float)((v >> shiftA) & maskA) / maskA : 1;
				pixels[width * y + x] = {r,g,b,a};
			}
			pixelArray += rowSize;
		}
	}
	else if (bpp == 24) {
		for (uint32_t y = 0; y < height; y++) {
			const uint8_t* pix = pixelArray;
			for (uint32_t x = 0; x < width; x++) {
				uint32_t v = ((*(pix + 0)) << 16) | ((*(pix + 1)) << 8) | (*(pix + 2));
				pix += 3;
				float r = maskR ? (float)((v >> shiftR) & maskR) / maskR : 0;
				float g = maskG ? (float)((v >> shiftG) & maskG) / maskG : 0;
				float b = maskB ? (float)((v >> shiftB) & maskB) / maskB : 0;
				float a = maskA ? (float)((v >> shiftA) & maskA) / maskA : 1;
				pixels[width * y + x] = { r,g,b,a };
			}
			pixelArray += rowSize;
		}
	}
	else if (bpp == 32) {
		for (uint32_t y = 0; y < height; y++) {
			const uint8_t* pix = pixelArray;
			for (uint32_t x = 0; x < width; x++) {
				uint32_t v = ((*(pix++)) << 24) | ((*(pix++)) << 16) | ((*(pix++)) << 8) | (*(pix++));
				float r = maskR ? (float)((v >> shiftR) & maskR) / maskR : 0;
				float g = maskG ? (float)((v >> shiftG) & maskG) / maskG : 0;
				float b = maskB ? (float)((v >> shiftB) & maskB) / maskB : 0;
				float a = maskA ? (float)((v >> shiftA) & maskA) / maskA : 1;
				pixels[width * y + x] = { r,g,b,a };
			}
			pixelArray += rowSize;
		}
	}

	Texture t = Texture(width, height, 4, GL_FLOAT, pixels);
	delete [] pixels;
	return t;
}
void game_render::Texture::Bind() const {
	glBindTexture(GL_TEXTURE_2D, *id.get());
}
void game_render::Material::Bind() const {
	if (useVertexColor) {
		glEnable(GL_COLOR_MATERIAL);
		glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	}
	else {
		glDisable(GL_COLOR_MATERIAL);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, (float*)&ambientColor);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, (float*)&diffuseColor);
	}
	if (useTexture && texture.id.get() != 0) {
		texture.Bind();
		glEnable(GL_TEXTURE_2D);
	}
	else {
		glDisable(GL_TEXTURE_2D);
	}
	if (transparent) {
		glDisable(GL_DEPTH_TEST);
	}
	else {
		glEnable(GL_DEPTH_TEST);
	}
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, (float*)&specularColor);
	glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, (int)(specularHighlight * 128));
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, (float*)&emissiveColor);
}
void game_render::Mesh::Render(const gl_math::Mat4& transform) const {
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(transform);
	if (vert_positions) {
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, sizeof(gl_math::Vec3), (const void*)vert_positions.get());
	}
	else glDisableClientState(GL_VERTEX_ARRAY);
	if (vert_normals) {
		glEnableClientState(GL_NORMAL_ARRAY);
		glNormalPointer(GL_FLOAT, sizeof(gl_math::Vec3), (const void*)vert_normals.get());
	}
	else glDisableClientState(GL_NORMAL_ARRAY);
	if (vert_colors) {
		glEnableClientState(GL_COLOR_ARRAY);
		glColorPointer(4, GL_FLOAT, sizeof(gl_math::Vec4), (const void*)vert_colors.get());
	}
	else glDisableClientState(GL_COLOR_ARRAY);
	if (vert_uvs) {
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glTexCoordPointer(2, GL_FLOAT, sizeof(gl_math::Vec2), (const void*)vert_uvs.get());
	}
	else glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	
	glDrawArrays(GL_TRIANGLES, 0, (GLsizei)vertices_length);
}
void game_render::Mesh::GenNormals() {
	for (size_t i = 0; i < vertices_length; i += 3) { 
		gl_math::Vec3 a = vert_positions.get()[i + 1] - vert_positions.get()[i];
		gl_math::Vec3 b = vert_positions.get()[i + 2] - vert_positions.get()[i];
		gl_math::Vec3 c = gl_math::Vec3::Cross(a, b).Normal();
		vert_normals.get()[i] = c;
		vert_normals.get()[i + 1] = c;
		vert_normals.get()[i + 2] = c;
	}
}

game_render::Mesh* game_render::Mesh::ObjMesh(const char* data) {
	std::vector<gl_math::Vec3> pos{};
	std::vector<gl_math::Vec3> normal{};
	std::vector<gl_math::Vec4> vert_colors{};
	std::vector<gl_math::Vec2> uv{};
	for (const char* d = data; *d; d = nextLine(d)) {
		float x;
		float y;
		float z;
		float w;
		float r;
		float g;
		float b;
		int i = sscanf_s(d, "v %f %f %f %f %f %f %f", &x, &y, &z, &w, &r, &g, &b);
		if (i >= 3) {
			pos.push_back({ x,y,z });
			if (i == 7)
				vert_colors.push_back({ r,g,b,1 });
			else
				vert_colors.push_back({ 1,1,1,1 });
		}

	}
	for (const char* d = data; *d; d = nextLine(d)) {
		float x;
		float y;
		if (sscanf_s(d, "vt %f %f", &x, &y) == 2) {
			uv.push_back({ x,y });
		}
	}
	for (const char* d = data; *d; d = nextLine(d)) {
		float x;
		float y;
		float z;
		if (sscanf_s(d, "vn %f %f %f", &x, &y, &z) == 3) {
			normal.push_back({ x,y,z });
		}
	}
	std::vector<gl_math::Vec3> posArr{};
	std::vector<gl_math::Vec3> normalArr{};
	std::vector<gl_math::Vec4> vert_colorsArr{};
	std::vector<gl_math::Vec2> uvArr{};
	std::vector<int> posI{};
	std::vector<int> normalI{};
	std::vector<int> uvI{};
	for (const char* d = data; *d; d = nextLine(d)) {
		if (*d == 'f') {
			d++;
			posI.clear();
			normalI.clear();
			uvI.clear();
			int p;
			int t;
			int n;
			int c;
			while (sscanf_s(d, " %d/%d/%d%n", &p, &t, &n, &c) == 3) {
				d += c;
				posI.push_back(p - 1);
				uvI.push_back(t - 1);
				normalI.push_back(n - 1);
			}
			while (sscanf_s(d, " %d//%d%n", &p, &n, &c) == 2) {
				d += c;
				posI.push_back(p - 1);
				uvI.push_back(-1);
				normalI.push_back(n - 1);
			}
			while (sscanf_s(d, " %d/%d%n", &p, &t, &c) == 2) {
				d += c;
				posI.push_back(p - 1);
				uvI.push_back(t - 1);
				normalI.push_back(-1);
			}
			while (sscanf_s(d, " %d%n", &p, &c) == 1) {
				d += c;
				posI.push_back(p - 1);
				uvI.push_back(-1);
				normalI.push_back(-1);
			}
			for (int i = 1; i < posI.size() - 1; i++) {
				posArr.push_back(posI[0] == -1 ? gl_math::Vec3{ 0, 0, 0 } : pos[posI[0]]);
				vert_colorsArr.push_back(posI[0] == -1 ? gl_math::Vec4{ 1,1,1,1 } : vert_colors[posI[0]]);
				normalArr.push_back(normalI[0] == -1 ? gl_math::Vec3{ 0, 0, 0 } : normal[normalI[0]]);
				uvArr.push_back(uvI[0] == -1 ? gl_math::Vec2{ 0, 0 } : uv[uvI[0]]);
				posArr.push_back(posI[i + 1] == -1 ? gl_math::Vec3{ 0, 0, 0 } : pos[posI[i + 1]]);
				vert_colorsArr.push_back(posI[i + 1] == -1 ? gl_math::Vec4{ 1,1,1,1 } : vert_colors[posI[i + 1]]);
				normalArr.push_back(normalI[i + 1] == -1 ? gl_math::Vec3{ 0, 0, 0 } : normal[normalI[i + 1]]);
				uvArr.push_back(uvI[i + 1] == -1 ? gl_math::Vec2{ 0, 0 } : uv[uvI[i + 1]]);
				posArr.push_back(posI[i] == -1 ? gl_math::Vec3{ 0, 0, 0 } : pos[posI[i]]);
				vert_colorsArr.push_back(posI[i] == -1 ? gl_math::Vec4{ 1,1,1,1 } : vert_colors[posI[i]]);
				normalArr.push_back(normalI[i] == -1 ? gl_math::Vec3{ 0, 0, 0 } : normal[normalI[i]]);
				uvArr.push_back(uvI[i] == -1 ? gl_math::Vec2{ 0, 0 } : uv[uvI[i]]);
			}
		}
	}

	std::shared_ptr<gl_math::Vec3> xpos = std::shared_ptr<gl_math::Vec3>{ new gl_math::Vec3[posArr.size()] };
	std::copy(posArr.begin(), posArr.end(), (gl_math::Vec3*)xpos.get());
	std::shared_ptr<gl_math::Vec3> xnorm = std::shared_ptr<gl_math::Vec3>{ new gl_math::Vec3[posArr.size()] };
	std::copy(normalArr.begin(), normalArr.end(), (gl_math::Vec3*)xnorm.get());
	std::shared_ptr<gl_math::Vec4> xcolor = std::shared_ptr<gl_math::Vec4>{ new gl_math::Vec4[posArr.size()] };
	std::copy(vert_colorsArr.begin(), vert_colorsArr.end(), (gl_math::Vec4*)xcolor.get());
	std::shared_ptr<gl_math::Vec2> xuv = std::shared_ptr<gl_math::Vec2>{ new gl_math::Vec2[posArr.size()] };
	std::copy(uvArr.begin(), uvArr.end(), (gl_math::Vec2*)xuv.get());
	return new game_render::Mesh{ xpos, xnorm, xcolor, xuv, posArr.size()};
}
#define cube_vertices (sizeof(cube_positions)/sizeof(cube_positions[0]))
gl_math::Vec3 cube_positions[] = {
	//back
	{-1,-1,-1},{1,-1,-1},{1,1,-1},
	{-1,-1,-1},{1,1,-1},{-1,1,-1},
	//right
	{1,-1,-1},{1,-1,1},{1,1,1},
	{1,-1,-1},{1,1,1},{1,1,-1},
	//forward
	{1,-1,1},{-1,-1,1},{-1,1,1},
	{1,-1,1},{-1,1,1 },{1,1,1},
	//left
	{-1,-1,1},{-1,-1,-1},{-1,1,-1},
	{-1,-1,1},{-1,1,-1},{-1,1,1},
	//top
	{-1,1,-1},{1,1,-1},{1,1,1},
	{-1,1,-1},{1,1,1},{-1,1,1},
	//bottom
	{-1,-1,-1},{1,-1,1},{1,-1,-1},
	{-1,-1,-1},{-1,-1,1},{1,-1,1},
};
gl_math::Vec3 cube_normals[] = {
	{0,0,-1},{0,0,-1},{0,0,-1},{0,0,-1},{0,0,-1},{0,0,-1},
	{1,0,0},{1,0,0},{1,0,0},{1,0,0},{1,0,0},{1,0,0},
	{0,0,1},{0,0,1},{0,0,1},{0,0,1},{0,0,1},{0,0,1},
	{-1,0,0},{-1,0,0},{-1,0,0},{-1,0,0},{-1,0,0},{-1,0,0},
	{0,1,0},{0,1,0},{0,1,0},{0,1,0},{0,1,0},{0,1,0},
	{0,-1,0},{0,-1,0},{0,-1,0},{0,-1,0},{0,-1,0},{0,-1,0},
};
gl_math::Vec4 cube_color[] = {
	{0,0,-1,1},{0,0,-1,1},{0,0,-1,1},{0,0,-1,1},{0,0,-1,1},{0,0,-1,1},
	{1,0,0,1},{1,0,0,1},{1,0,0,1},{1,0,0,1},{1,0,0,1},{1,0,0,1},
	{0,0,1,1},{0,0,1,1},{0,0,1,1},{0,0,1,1},{0,0,1,1},{0,0,1,1},
	{-1,0,0,1},{-1,0,0,1},{-1,0,0,1},{-1,0,0,1},{-1,0,0,1},{-1,0,0,1},
	{0,1,0,1},{0,1,0,1},{0,1,0,1},{0,1,0,1},{0,1,0,1},{0,1,0,1},
	{0,-1,0,1},{0,-1,0,1},{0,-1,0,1},{0,-1,0,1},{0,-1,0,1},{0,-1,0,1},
};
gl_math::Vec2 cube_uv[] = {
	{0,0},{1,0},{1,1},{0,0},{1,1},{0,1},
	{0,0},{1,0},{1,1},{0,0},{1,1},{0,1},
	{0,0},{1,0},{1,1},{0,0},{1,1},{0,1},
	{0,0},{1,0},{1,1},{0,0},{1,1},{0,1},
	{0,0},{1,0},{1,1},{0,0},{1,1},{0,1},
	{0,0},{1,0},{1,1},{0,0},{1,1},{0,1},
};
std::shared_ptr< game_render::Mesh> game_render::Mesh::cubePrimative = std::shared_ptr< game_render::Mesh>{ new game_render::Mesh{ std::shared_ptr<gl_math::Vec3>{cube_positions},std::shared_ptr<gl_math::Vec3>{cube_normals},
std::shared_ptr<gl_math::Vec4>{cube_color},std::shared_ptr<gl_math::Vec2>{cube_uv},cube_vertices } };
game_render::Material game_render::Material::defaultMaterial = { false, true, false, false, {0.7f,0.85f,0.85f,1},{0.85f,0.85f,0.85f,1}, {0.9f,0.9f,0.9f,1}, 1, {0,0,0,1}, {} };
game_render::Material game_render::Material::shadowMaterial = { false, false, false, false, {}, {}, {}, 0, {} };

void game_component::MeshRenderer::OnRender(int phase) {
	if (phase == 1 || phase == 7 && material.applyShadow || phase == 9 && !material.applyShadow) {
		material.Bind();
		mesh->Render(selfObject()->getPrevTransform());
	}
}
void game_component::ShadowRenderer::OnRender(int phase) {
	if (phase == 3 || phase == 5) {
		material->Bind();
		mesh->Render(selfObject()->getPrevTransform());
	}
}
game_component::Camera::Camera() noexcept {
	fovy =  80 * 0.0174532925199f;
	nearPlane = 0.2f;
	farPlane = 500;
	camera = gl_math::Mat4_Identity;
}
game_component::Camera::Camera(float fovy, float nearPlane, float farPlane) noexcept {
	this->fovy = fovy;
	this->nearPlane = nearPlane;
	this->farPlane = farPlane;
	camera = gl_math::Mat4_Identity;
}
void game_component::Camera::OnResize() {
	float ratio = (float)game_core::GameManager::Current()->ScreenX() / game_core::GameManager::Current()->ScreenY();
	camera = gl_math::Mat4::Perspective(fovy, ratio, nearPlane, farPlane);
}
void game_component::Camera::OnRender(int phase) {
	if (phase == 0) {//no light render
		glEnable(GL_LIGHTING);
		glMatrixMode(GL_PROJECTION);
		glLoadMatrixf(camera * selfObject()->transform.ToMatrixInverse());
		glCullFace(GL_BACK);
		glStencilMask(GL_FALSE);
		glDepthMask(GL_TRUE);
		glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
		glStencilFunc(GL_ALWAYS, 0, 0xFF);
	}
	else if (phase == 2) {//shadow front render
		glCullFace(GL_FRONT);
		glStencilOp(GL_KEEP, GL_INCR, GL_KEEP);
		glStencilMask(0xFF);
		glDepthMask(GL_FALSE);
		glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
	}
	else if (phase == 4) {//shadow back render
		glCullFace(GL_BACK);
		glStencilOp(GL_KEEP, GL_DECR, GL_KEEP);
	}
	else if (phase == 6) {//shadows lighting and color
		glStencilFunc(GL_EQUAL, 0, 0xff);
		glStencilMask(0);
		glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
	}
	else if (phase == 8) {//lighting and color
		glStencilFunc(GL_ALWAYS, 0, 0xff);
		glDepthMask(GL_TRUE);
	}
	else if (phase == 10) {//ui
		glClear(GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
		glDisable(GL_LIGHTING);
		glMatrixMode(GL_PROJECTION);
		glLoadMatrixf(gl_math::Mat4::Orthographic(game_core::GameManager::ScreenX(), 
			(float)game_core::GameManager::ScreenY() / game_core::GameManager::ScreenX(), 0, 100));
	}
}
game_component::SunLight::SunLight() {
	index = currentLightIndex++;
	ambientColor = { 0,0,0,1 };
	diffuseColor = { 1,1,1,1 };
	specularColor = { 1,1,1,1 };
	isShadowLight = false;
}
game_component::SunLight::SunLight(gl_math::Vec4 color) {
	index = currentLightIndex++;
	ambientColor = { 0,0,0,1 };
	diffuseColor = color;
	specularColor = { 1,1,1,1 };
	isShadowLight = false;
}
game_component::SunLight::SunLight(gl_math::Vec4 ambientColor, gl_math::Vec4 diffuseColor, gl_math::Vec4 specularColor) {
	index = currentLightIndex++;
	this->ambientColor = ambientColor;
	this->diffuseColor = diffuseColor;
	this->specularColor = specularColor;
	isShadowLight = false;
}
void game_component::SunLight::SunLight::OnRender(int phase) {
	
	if (phase == 6 || isShadowLight && phase == 0) {
		glEnable(GL_LIGHT0 + index);
		glMatrixMode(GL_MODELVIEW);
		glLoadMatrixf(gl_math::Mat4_Identity);
		gl_math::Vec4 v = (gl_math::Vec4)selfObject()->transform.forward();
		gl_math::Vec4 n = -v;
		glLightfv(GL_LIGHT0 + index, GL_POSITION, (float*)&v);
		glLightfv(GL_LIGHT0 + index, GL_SPOT_DIRECTION, (float*)&n);
		glLightfv(GL_LIGHT0 + index, GL_AMBIENT, (float*)&ambientColor);
		glLightfv(GL_LIGHT0 + index, GL_DIFFUSE, (float*)&diffuseColor);
		glLightfv(GL_LIGHT0 + index, GL_SPECULAR, (float*)&specularColor);
	}
	else if (phase == 0 || phase == 10) {
		glDisable(GL_LIGHT0 + index);
	}
}
	
void game_component::SunLight::SunLight::OnEnabled() {
	glEnable(GL_LIGHT0 + index);
}
void game_component::SunLight::SunLight::OnDisabled() {
	glDisable(GL_LIGHT0 + index);
}
