#pragma once

#include "glrender.h"

namespace game::resources {
	void Initizialize();


	int materialIndex(const char* v);
	std::shared_ptr<game::render::Material> material(int index);
	int textureIndex(const char* v);
	std::shared_ptr<game::render::Texture> texture(int index);
	int meshIndex(const char* v);
	std::shared_ptr<game::render::Mesh> mesh(int index);
	int fontIndex(const char* v);
	std::shared_ptr<game::render::FontMap> font(int index);
	bool setLoc(const char* v);
	char* loc(const char* v);
	int dataIndex(const char* v);
	std::shared_ptr<char> data(int index);
}