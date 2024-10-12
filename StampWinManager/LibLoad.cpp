#include "libload.h"
#include "SWM.hpp"
#include <vector>
#include <cstring>
#include <iostream>
using namespace swm;

std::vector<libload::LibProcStruct*> lps{};
void libload::LoadLibraries(swm::SWHWND* hwnd) {
	libload::EngineProc engineProc = {
		sizeof(libload::EngineProc),
		1,
		GLM_struct,
		libload::LIBLOAD_struct,
		swm::SWM_struct
	};

	lps.clear();
	std::cout << "[libload] Started" << std::endl;
	std::filesystem::path libPath = { ".\\lib" };
	if (!(std::filesystem::exists(libPath) && std::filesystem::is_directory(libPath))) {
		std::filesystem::create_directory(libPath);
	}
	for (const auto& entry : std::filesystem::directory_iterator(libPath)) {
		std::filesystem::path p = entry.path();
		if (p.extension().string() != ".dll") continue;
		HMODULE m = LoadLibrary(p.c_str());
		if (m == 0) continue;
		libLoadProc proc = (libLoadProc)GetProcAddress(m, "LibLoad");
		if (proc == nullptr) continue;
		std::cout << "[libload] loading: " << p.filename().string() << std::endl;
		libload::LibProcStruct* l = proc(&engineProc);
		if (l->engineVersion > engineProc.engineVersion) continue;
		std::cout << "[libload] loaded: " << l->name << std::endl;
		lps.push_back(l);
		hwnd->AddListener(*l->winEvent);
	}

}

void libload::LibloadInit() {
	delete LIBLOAD_struct;
	LIBLOAD_struct = new libload::LIBLOAD_struct_t();
	LIBLOAD_struct->getLibrary_proc = [](char* libName, short majorVersion, short minorVersion) -> libload::LibProcStruct* {
		for (int i = 0; i < lps.size(); i++) {
			if (!strcmp(libName, lps[i]->name)) {
				if (lps[i]->majorVersion != majorVersion) continue;
				if (lps[i]->minorVersion < minorVersion) continue;
				return lps[i];
			}
		}
		return nullptr;
	};
}