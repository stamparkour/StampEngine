#include <stamp/graphics/gl/texture.h>

using namespace STAMP_GRAPHICS_NAMESPACE;
using namespace STAMP_GRAPHICS_GL_NAMESPACE;

void Texture::InitBuffer() {
	if (desc.textureBuffer != 0) return;
	glGenTextures(1, &desc.textureBuffer);
}

Texture::Texture(texture_format_t format = texture_format::RGBA) {
	desc.format = format;
	InitBuffer();
}
Texture::~Texture() {
	Clear();
}

int Texture::Width(size_t mipmapLevel = 0) const {
	return std::max(desc.width >> mipmapLevel, 1ull);
}
int Texture::Height(size_t mipmapLevel = 0) const {
	return std::max(desc.height >> mipmapLevel, 1ull);
}
int Texture::Depth(size_t mipmapLevel = 0) const {
	return std::max(desc.depth >> mipmapLevel, 1ull);
}
int Texture::MaxMipmapLevel() {
	return desc.maxMipmapLevel;
}

GLuint Texture::TextureBuffer() const {
	return desc.textureBuffer;
}
texture_type_t Texture::Type() const {
	return desc.type;
}
void Texture::Bind(size_t bindingIndex) {
	desc.bindingIndex = bindingIndex;
	glBindTextureUnit(bindingIndex, desc.textureBuffer);
}
size_t Texture::Binding() const {
	return desc.bindingIndex;
}
void Texture::GenMipmap() {
	glGenerateTextureMipmap(desc.textureBuffer);
}
void Clear() {
	if (desc.textureBuffer == 0) return;
	glDeleteTextures(1, &desc.textureBuffer);
	desc.textureBuffer = 0;
	desc.type = 0;
}

void Texture::Set(RawTexture& tex, size_t mipmapLevel) {
	tex.SetTexture(this, &desc, mipmapLevel);
}