#include <stamp/graphics/gl/texture.h>

using namespace STAMP_GRAPHICS_NAMESPACE;
using namespace STAMP_GRAPHICS_GL_NAMESPACE;

std::vector<Texture*> textureBindings{};


void verifyTextureBindingArray() {
	if (!textureBindings.empty()) return;

	GLint p;
	glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &p);
	textureBindings.resize(p);
}
int getEmptyTextureBindingIndex() {
	static int index = 0;

	verifyTextureBindingArray();
	int i = index;
	while (textureBindings[i] != 0) {
		if (++i >= textureBindings.size()) i = 1;
		if (index == i) return 0;
	}

	return index = i;
}

TextureBinding::TextureBinding(Texture* texture) {
	this->texture = texture;
	if (texture == nullptr) return;
	if (texture->desc.bindingLocation != 0) return;

	int i = getEmptyTextureBindingIndex();
	STAMPASSERT(i != 0, "stamp::graphics::gl::TextureBinding - texture binding buffer is full.");

	glBindTextureUnit(i, texture->TextureBuffer());
	texture->desc.bindingLocation = i;
	textureBindings[i] = texture;

}
size_t TextureBinding::BindingLocation() const {
	if (texture->desc.bindingLocation == 0) return 0;
	return texture->desc.bindingLocation;
}

TextureBinding::~TextureBinding() {
	if (texture->desc.bindingLocation == 0) return;
	textureBindings[texture->desc.bindingLocation] = nullptr;
	texture->desc.bindingLocation = 0;
}

void Texture::Set(RawTexture& tex, size_t mipmapLevel) {
	tex.SetTexture(this, &desc, mipmapLevel);
}