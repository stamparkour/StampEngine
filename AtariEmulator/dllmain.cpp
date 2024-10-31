// dllmain.cpp : Defines the entry point for the DLL application.
#include <windows.h>
#include "libload.h"
#include <iostream>
#include <math.h>

libload::EngineProc* engineProc;

void Start(double time) {
	std::cout << "Hello World - Atari" << std::endl;
	
}
void Update(double time) {
	
}
void Render(double time) {
	glClearColor(sin(time * 17) / 2 + 0.5, sin(time*2) / 2 + 0.5, sin(time * 3.9) / 2 + 0.5, 1.0f);
}
void OnKeyDown(swm::VertKey key) {
	if (key == swm::VertKey::A) {
		std::cout << "A";
	}
}
void OnKeyUp(swm::VertKey key) {

}

const char* Name = "ATARI EMULATOR - Stamparkour - GNU";
extern "C" __declspec(dllexport) inline libload::LibProcStruct* LibLoad(libload::EngineProc* libProc) {
	engineProc = libProc;
	GLM_struct = libProc->GLM;
	libload::LIBLOAD_struct = libProc->libload;
	swm::SWM_struct = libProc->SWM;
	std::cout << "hello" << std::endl;
	libload::LibProcStruct* ptr = new libload::LibProcStruct();
	ptr->engineVersion = 1;
	ptr->majorVersion = 0;
	ptr->minorVersion = 0;
	ptr->name = Name;
	ptr->structSize = sizeof(libload::LibProcStruct);
	ptr->winEvent = new swm::WinEvent();
	ptr->winEvent->Start_proc = Start;
	ptr->winEvent->Update_proc = Update;
	ptr->winEvent->Render_proc = Render;
	ptr->winEvent->Keydown_proc = OnKeyDown;
	ptr->winEvent->Keyup_proc = OnKeyUp;
	return ptr;
}
