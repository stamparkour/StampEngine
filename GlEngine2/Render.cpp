#include "glrender.h"
#include "xptr.h"

int currentLightIndex = 0;

game_render::Texture::Texture()  {
	this->width = 0;
	this->height = 0;
}
game_render::Texture::Texture(size_t width, size_t height, int elementSize, GLenum type, const void* pixels) : xptr_base<GLuint>() {
	glGenTextures(1, &ptr);
	Bind();
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	setPixels(elementSize, type, pixels);
	this->width = width;
	this->height = height;
}
game_render::Texture::Texture(const Texture& v) : xptr_base<GLuint>((const xptr_base<GLuint>&)v) {
	width = v.width;
	height = v.height;
	xptr_base<GLuint>::operator=(v);
}
game_render::Texture::Texture(Texture&& v) noexcept : xptr_base<GLuint>() {
	this->width = 0;
	this->height = 0;
	swap(*this, v);
}
inline void game_render::swap(Texture& a, Texture& b) {
	using std::swap;
	swap(a.width, b.width);
	swap(a.height, b.height);
	swap((xptr_base<GLuint>&)a, (xptr_base<GLuint>&)b);
}
size_t game_render::Texture::Width() {
	return width;
}
size_t game_render::Texture::Height() {
	return height;
}
game_render::Texture& game_render::Texture::operator=(const Texture& v) {
	width = v.width;
	height = v.height;
	xptr_base<GLuint>::operator=(v);
	return *this;
}
game_render::Texture& game_render::Texture::operator=(Texture&& v) noexcept {
	swap(*this, v);
	return *this;
}
void game_render::Texture::setPixels(int elementSize, GLenum type, const void* pixels) {
	GLenum v[] = { GL_LUMINANCE, GL_LUMINANCE_ALPHA, GL_RGB, GL_RGBA };
	Bind();
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei)width, (GLsizei)height, 0, v[elementSize - 1], type, pixels);
}
game_render::Texture::~Texture() {
	if ((xptr_base<GLuint>::count) == NULL) return;
	if (*(xptr_base<GLuint>::count) == 1) {
		glDeleteTextures(1,  &(xptr_base<GLuint>::ptr));
	}
}
void game_render::Texture::Bind() const {
	glBindTexture(GL_TEXTURE_2D, xptr_base<GLuint>::ptr);
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
	if (useTexture && texture.ptr != 0) {
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
void game_render::Mesh::Render(const gl_math::Mat4& transform) const {
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(transform);
	if (vert_positions) {
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, sizeof(gl_math::Vec3), vert_positions);
	}
	else glDisableClientState(GL_VERTEX_ARRAY);
	if (vert_normals) {
		glEnableClientState(GL_NORMAL_ARRAY);
		glNormalPointer(GL_FLOAT, sizeof(gl_math::Vec3), vert_normals);
	}
	else glDisableClientState(GL_NORMAL_ARRAY);
	if (vert_colors) {
		glEnableClientState(GL_COLOR_ARRAY);
		glColorPointer(4, GL_FLOAT, sizeof(gl_math::Vec4), vert_colors);
	}
	else glDisableClientState(GL_COLOR_ARRAY);
	if (vert_uvs) {
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glTexCoordPointer(2, GL_FLOAT, sizeof(gl_math::Vec2), vert_uvs);
	}
	else glDisableClientState(GL_TEXTURE_COORD_ARRAY);

	glDrawArrays(GL_TRIANGLES, 0, (GLsizei)vertices_length);
}
void game_render::Mesh::GenNormals() {
	for (int i = 0; i < vertices_length; i += 3) { 
		gl_math::Vec3 a = vert_positions[i + 1] - vert_positions[i];
		gl_math::Vec3 b = vert_positions[i + 2] - vert_positions[i];
		gl_math::Vec3 c = gl_math::Vec3::Cross(a, b).Normal();
		vert_normals[i] = c;
		vert_normals[i + 1] = c;
		vert_normals[i + 2] = c;
	}
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
game_render::Mesh game_render::Mesh::cubePrimative = { cube_positions,cube_normals,cube_color,cube_uv,cube_vertices };
game_render::Material game_render::Material::defaultMaterial = { false, false, {0.7,0.85,0.85,1},{0.85,0.85,0.85,1}, {0.9,0.9,0.9,1}, 4, {0,0,0,1}, {} };
void game_component::MeshRenderer::OnRender(game_core::GameObject& gameObject) {
	material->Bind();
	mesh->Render(gameObject.getTransform());
}
game_component::Camera::Camera() noexcept {
	fovy = 40;
	nearPlane = 0.1f;
	farPlane = 100;
	camera = gl_math::Mat4_Identity;
}
game_component::Camera::Camera(float fovy, float nearPlane, float farPlane) noexcept {
	this->fovy = fovy;
	this->nearPlane = nearPlane;
	this->farPlane = farPlane;
	camera = gl_math::Mat4_Identity;
}
void game_component::Camera::OnResize(game_core::GameObject& gameObject) {
	float ratio = (float)game_core::GameManager::Current()->ScreenX() / game_core::GameManager::Current()->ScreenY();
	camera = gl_math::Mat4::Perspective(fovy, ratio, nearPlane, farPlane);
}
void game_component::Camera::OnRender(game_core::GameObject& gameObject) {
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(camera * gameObject.transform.ToMatrixInverse());
}
game_component::SunLight::SunLight() {
	index = currentLightIndex++;
	ambientColor = { 0,0,0,1 };
	diffuseColor = { 1,1,1,1 };
	specularColor = { 1,1,1,1 };
}
game_component::SunLight::SunLight(gl_math::Vec4 color) {
	index = currentLightIndex++;
	ambientColor = { 0,0,0,1 };
	diffuseColor = color;
	specularColor = { 1,1,1,1 };
}
game_component::SunLight::SunLight(gl_math::Vec4 ambientColor, gl_math::Vec4 diffuseColor, gl_math::Vec4 specularColor) {
	index = currentLightIndex++;
	this->ambientColor = ambientColor;
	this->diffuseColor = diffuseColor;
	this->specularColor = specularColor;
}
void game_component::SunLight::SunLight::OnRender(game_core::GameObject& gameObject) {
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(gl_math::Mat4_Identity);
	gl_math::Vec4 v = (gl_math::Vec4)gameObject.transform.forward();
	gl_math::Vec4 n = -v;
	glEnable(GL_LIGHT0 + index);
	glLightfv(GL_LIGHT0 + index, GL_POSITION, (float*)&v);
	glLightfv(GL_LIGHT0 + index, GL_SPOT_DIRECTION, (float*)&n);
	glLightfv(GL_LIGHT0 + index, GL_AMBIENT, (float*)&ambientColor);
	glLightfv(GL_LIGHT0 + index, GL_DIFFUSE, (float*)&diffuseColor);
	glLightfv(GL_LIGHT0 + index, GL_SPECULAR, (float*)&specularColor);
}
void game_component::SunLight::SunLight::OnEnabled(game_core::GameObject& gameObject) {
	glEnable(GL_LIGHT0 + index);
}
void game_component::SunLight::SunLight::OnDisabled(game_core::GameObject& gameObject) {
	glDisable(GL_LIGHT0 + index);
}
