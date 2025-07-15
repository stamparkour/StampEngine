module;

#include "debug.h"

export module VirtualDrive;

import std;

std::vector<std::filesystem::path> directories = std::vector<std::filesystem::path>{
	{ std::filesystem::current_path() }  // Default to current path
};

export namespace virtualdrive {
	void AddDirectory(const std::filesystem::path& dir) {
		if (std::filesystem::exists(dir) && std::filesystem::is_directory(dir)) {
			directories.push_back(dir);
		}
		else {
			std::cerr << "[VirtualDrive] Directory does not exist or is not a directory: " << dir.string() << std::endl;
		}
	}

	std::filesystem::path GetAbsolutePath(const std::filesystem::path& relativePath) {
		if (relativePath.is_absolute()) {
			STAMPSTACK();
			STAMPDMSG("[VERTDRIVE] path given is absolute when relative required.");
			return {};
		}
		for (int i = directories.size() - 1; i >= 0; i--) {
			std::filesystem::path testPath = directories[i] / relativePath;
			if (!std::filesystem::exists(testPath)) continue;
			return testPath;
		}
		STAMPSTACK();
		STAMPDMSG("[VERTDRIVE] no item with given path.");
	}
}


//combine a bunch of folders into one "virtual" folder. for mods and resource files