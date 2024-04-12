#include "gameresources.h"
#include "gamecore.h"
#include <cstring>
#include <filesystem>
#include <fstream>
#include <vector>

std::vector <char*> textureLabels{};
std::vector <std::shared_ptr<game::render::Texture>> textures{};
std::vector <char*> meshLabels{};
std::vector <std::shared_ptr<game::render::Mesh>> meshes{};
std::vector <char*> materialLabels{};
std::vector <std::shared_ptr<game::render::Material>> materials{};
std::vector <char*> fontlLabels{};
std::vector <std::shared_ptr<game::render::FontMap>> fonts{};

void game::resources::Initizialize() {
	std::filesystem::current_path("resources\\gfx");
	char buffer[256];
	char label[32];
	auto file = std::fstream{ "textures.txt" };
	while (!file.eof()) {
		char path[256];
		file.getline(buffer, 256);
		int v;
		v = sscanf_s(buffer, " %s %s", label, 32, path, 256);
		if (v == 2) {
			size_t length = strlen(label)+1;
			char* l = new char[length];
			memcpy_s(l, length, label, length);
			textureLabels.push_back(l);
			textures.push_back(game::render::Texture::BmpTexture(game::core::readFile(path, NULL, true).get()));
		}
	}
	
	file = std::fstream{ "meshes.txt" };
	while (!file.eof()) {
		char path[256];
		file.getline(buffer, 256);
		int v;
		v = sscanf_s(buffer, " %s %s", label, 32, path, 256);
		if (label[0] == ';') continue;
		if (v == 2) {
			size_t length = strlen(label) + 1;
			char* l = new char[length];
			memcpy_s(l, length, label, length);
			meshLabels.push_back(l);
			meshes.push_back(game::render::Mesh::ObjMesh(game::core::readFile(path, NULL, true).get()));
		}
	}

	file = std::fstream{ "materials.txt" };
	while (!file.eof()) {
		file.getline(buffer, 256);
		int v;
		v = sscanf_s(buffer, " %s", label, 32);
		if (label[0] == ';') continue;
		if (v == 1) {
			size_t length = strlen(label) + 1;
			char* l = new char[length];
			memcpy_s(l, length, label, length);
			materialLabels.push_back(l);
			materials.push_back(game::render::Material::ParseMaterial(file));
		}
	}

	file = std::fstream{ "fonts.txt" };
	while (!file.eof()) {
		char path[256];
		char tex[32];
		file.getline(buffer, 256);
		int v;
		v = sscanf_s(buffer, " %s %s %s", label, 32, tex, 32, path, 256);
		if (label[0] == ';') continue;
		if (v == 3) {
			size_t length = strlen(label) + 1;
			char* l = new char[length];
			memcpy_s(l, length, label, length);
			fontlLabels.push_back(l);
			fonts.push_back(game::render::FontMap::ParseMap(game::core::readFile(path,NULL,false).get(), game::resources::texture(game::resources::textureIndex(tex))));
		}
	}
}

int game::resources::materialIndex(const char* v) {
	for (int i = 0; i < materialLabels.size(); i++) {
		if (!strcmp(v, materialLabels[i])) return i;
	}
	return -1;
}
int game::resources::textureIndex(const char* v) {
	for (int i = 0; i < textureLabels.size(); i++) {
		if (!strcmp(v, textureLabels[i])) return i;
	}
	return -1;
}
int game::resources::meshIndex(const char* v) {
	for (int i = 0; i < meshLabels.size(); i++) {
		if (!strcmp(v, meshLabels[i])) return i;
	}
	return -1;
}
int game::resources::fontIndex(const char* v) {
	for (int i = 0; i < fontlLabels.size(); i++) {
		if (!strcmp(v, fontlLabels[i])) return i;
	}
	return -1;
}
std::shared_ptr<game::render::Material> game::resources::material(int index) {
	if (index < 0) return 0;
	return materials[index];
}
std::shared_ptr<game::render::Texture> game::resources::texture(int index) {
	if (index < 0) return 0;
	return textures[index];
}
std::shared_ptr<game::render::Mesh> game::resources::mesh(int index) {
	if (index < 0) return 0;
	return meshes[index];
}
std::shared_ptr<game::render::FontMap> game::resources::font(int index) {
	if (index < 0) return 0;
	return fonts[index];
}
