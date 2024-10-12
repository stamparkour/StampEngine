#pragma once
#include <Windows.h>
#include <filesystem>
#include "SWM.hpp"
#include "glm.h"
namespace libload {

	typedef struct LibProcStruct* (*GETLIBRARYPROC)(char* libName, short majorVersion, short minorVersion);

	struct LibProcStruct {
		unsigned short structSize;
		unsigned short majorVersion;
		unsigned short minorVersion;
		unsigned short engineVersion;
		const char* name;
		swm::WinEvent* winEvent;
	};

	struct EngineProc {
		unsigned short structSize;
		unsigned short engineVersion;
		GLM_struct_t* GLM;
		struct LIBLOAD_struct_t* libload;
		swm::SWM_struct_t* SWM;
	};

	typedef struct LibProcStruct* (*libLoadProc)(struct EngineProc* libProc);
	struct LIBLOAD_struct_t {
		GETLIBRARYPROC getLibrary_proc;
	} inline* LIBLOAD_struct = 0;
	

	//must match majorVersion
	//higher or equal number for minorVersion
	inline LibProcStruct* GetLibrary(char* libName, short majorVersion, short minorVersion) { 
		return LIBLOAD_struct->getLibrary_proc(libName, majorVersion, minorVersion); 
	}

	//internal functions
	void LibloadInit();
	void LoadLibraries(swm::SWHWND* hwnd);
}
#define swm_library
#ifdef swm_library 

#endif