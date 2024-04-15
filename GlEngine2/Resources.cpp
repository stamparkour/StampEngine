#include "gameresources.h"
#include "gamecore.h"
#include <cstring>
#include <filesystem>
#include <fstream>
#include <vector>


struct LocKeyValue {
	char* key;
	char* value;
};

struct Localization {
	char* name;
	std::vector< LocKeyValue> loc{};
};

std::vector <char*> textureLabels{};
std::vector <std::shared_ptr<game::render::Texture>> textures{};
std::vector <char*> meshLabels{};
std::vector <std::shared_ptr<game::render::Mesh>> meshes{};
std::vector <char*> materialLabels{};
std::vector <std::shared_ptr<game::render::Material>> materials{};
std::vector <char*> fontlLabels{};
std::vector <std::shared_ptr<game::render::FontMap>> fonts{};
std::vector <Localization> localizations{};
int localizationIndex = 0;

template<class T>
void clearVector(std::vector<T>& vec) {
	for (T v : vec) {
		delete v;
	}
	vec.clear();
}
template<class T>
void clearVector(std::vector<std::shared_ptr<T>>& vec) {
	for (auto v : vec) {
		v.reset();
	}
	vec.clear();
}

void reset() {
	clearVector(textureLabels);
	clearVector(textures);
	clearVector(meshLabels);
	clearVector(meshes);
	clearVector(materialLabels);
	clearVector(materials);
	clearVector(fontlLabels);
	clearVector(fonts);
}

void game::resources::Initizialize() {
	reset();

	auto basePath = std::filesystem::current_path();
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

	std::filesystem::current_path(basePath);
	std::filesystem::current_path("resources\\loc");
	for (auto entry : std::filesystem::directory_iterator{ ".\\" }) {
		if (!entry.is_directory()) continue;
		auto path = entry.path().filename().string();
		char* loc = new char[path.length()+1];
		memcpy_s(loc, path.length() + 1, path.c_str(), path.length() + 1);
		Localization l{ loc };
		for (auto e : std::filesystem::directory_iterator{ entry.path() }) {
			file = std::fstream{ e.path() };
			while (file && !file.eof()) {
				char line[2048];
				file.getline(line, 2048);
				if (line[0] == ';') continue;
				int split = 0;
				for (; line[split] && line[split] != ':'; split++);
				if (line[split] == 0) continue;
				split++;
				char* key = new char[split];
				memcpy_s(key, split, line, split);
				key[split - 1] = 0;
				int length = strlen(line) - split + 1;
				char* value = new char[length];
				memcpy_s(value, length, line + split, length);
				l.loc.push_back({ key, value });
			}
		}
		localizations.push_back(l);
	}
	std::filesystem::current_path(basePath);
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

char* game::resources::loc(const char* v)
{
	for (int i = 0; i < localizations[localizationIndex].loc.size(); i++) {
		if (!strcmp(v, localizations[localizationIndex].loc[i].key)) {
			return localizations[localizationIndex].loc[i].value;
		}
	}
	return 0;
}
bool game::resources::setLoc(const char* v) {
	for (int i = 0; i < localizations.size(); i++) {
		if (!strcmp(v, localizations[i].name)) {
			localizationIndex = i;
			return true;
		}
	}
	return false;
}