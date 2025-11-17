#include <stamp/graphics/gl/texture.h>

using namespace STAMP_GRAPHICS_NAMESPACE;
using namespace STAMP_GRAPHICS_GL_NAMESPACE;

bool texture_format::IsFormatFloatingPoint(texture_format_t format) {
	switch (format) {
	case texture_format::Red:
	case texture_format::RG:
	case texture_format::RGB:
	case texture_format::RGBA:
		return true;
	default:
		return false;
	}
}

void Texture::InitBuffer() {
	if (desc.textureBuffer != 0) return;
	glGenTextures(1, &desc.textureBuffer);
}

Texture::Texture(texture_format_t format = texture_format::RGBA) {
	desc.format = format;
	InitBuffer();
}
Texture::Texture(texture_format_t format, size_t width, size_t height) {
	desc.format = format;
	desc.width = width;
	desc.height = height;
	InitBuffer();
}
Texture::~Texture() {
	Clear();
}

int Texture::Width(size_t mipmapLevel = 0) const {
	if (desc.width == 0) return 0;
	return std::max(desc.width >> mipmapLevel, 1ull);
}
int Texture::Height(size_t mipmapLevel = 0) const {
	if (desc.height == 0) return 0;
	return std::max(desc.height >> mipmapLevel, 1ull);
}
int Texture::Depth(size_t mipmapLevel = 0) const {
	return std::max(desc.depth >> mipmapLevel, 1ull);
}
int Texture::MaxMipmapLevel() {
	return desc.maxMipmapLevel;
}

GLuint Texture::InternalTextureBuffer() const {
	return desc.textureBuffer;
}
texture_type_t Texture::Type() const {
	return desc.type;
}
texture_format_t Texture::Format() const {
	return desc.format;
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
void Texture::Clear() {
	if (desc.textureBuffer == 0) return;
	glDeleteTextures(1, &desc.textureBuffer);
	desc.textureBuffer = 0;
	desc.type = 0;
}

void Texture::Set(const RawTexture& tex, size_t mipmapLevel) {
	auto t = desc.type;
	tex.SetTexture(this, &desc, mipmapLevel);
	if (t == 0) {
		int max = 0;
		for (size_t w = desc.width, h = desc.height, d = desc.depth; w > 1 || h > 1 || d > 1; w >>= 1, h >>= 1, d >>= 1) max++;
		desc.maxMipmapLevel = max;
	}
}