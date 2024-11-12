#pragma once
#include "glm.h"
#include <vector>
#include <stacktrace>
#include <iostream>

#define STAMPSTACK() std::cout << std::to_string(std::stacktrace::current()) << std::endl
#define STAMPDMSG(msg) std::cout << msg << std::endl
#define STAMPERROR(con,msg) if(con) {STAMPSTACK(); std::cout << msg << std::endl; }

namespace swm {
	struct SWHWND;
	struct SWHWND_d;
	//labeled virtual keycode
	enum struct VertKey {
		LeftMouse = 0x01,
		RightMouse = 0x02,
		MiddleMouse = 0x04,
		X1Mouse = 0x05,
		X2Mouse = 0x06,
		Backspace = 0x08,
		Tab = 0x09,
		Enter = 0x0D,
		Shift = 0x10,
		Control = 0x11,
		Alt = 0x12,
		Capslock = 0x14,
		Escape = 0x1b,
		Space = 0x20,
		PageUp = 0x21,
		PageDown = 0x22,
		End = 0x23,
		Home = 0x24,
		LeftArrow = 0x25,
		UpArrow = 0x26,
		RightArrow = 0x27,
		DownArrow = 0x28,
		Select = 0x29,
		Print = 0x2a,
		PrintScreen = 0x2c,
		Insert = 0x2d,
		Delete = 0x2e,
		Help = 0x2f,
		Zero = '0',
		One = '1',
		Two = '2',
		Three = '3',
		Four = '4',
		Five = '5',
		Six = '6',
		Seven = '7',
		Eight = '8',
		Nine = '9',
		A = 'A',
		B = 'B',
		C = 'C',
		D = 'D',
		E = 'E',
		F = 'F',
		G = 'G',
		H = 'H',
		I = 'I',
		J = 'J',
		K = 'K',
		L = 'L',
		M = 'M',
		N = 'N',
		O = 'O',
		P = 'P',
		Q = 'Q',
		R = 'R',
		S = 'S',
		T = 'T',
		U = 'U',
		V = 'V',
		W = 'W',
		X = 'X',
		Y = 'Y',
		Z = 'Z',
		LeftWindowsKey = 0x5B,
		RightWindowsKey = 0x5C,
		NumpadZero = 0x60,
		NumpadOne = 0x61,
		NumpadTwo = 0x62,
		NumpadThree = 0x63,
		NumpadFour = 0x64,
		NumpadFive = 0x65,
		NumpadSix = 0x66,
		NumpadSeven = 0x67,
		NumpadEight = 0x68,
		NumpadNine = 0x69,
		Multiply = 0x6a,
		Add = 0x6b,
		Subtract = 0x6c,
		Decimal = 0x6e,
		Divide = 0x6f,
		F1 = 0x70,
		F2 = 0x71,
		F3 = 0x72,
		F4 = 0x73,
		F5 = 0x74,
		F6 = 0x75,
		F7 = 0x76,
		F8 = 0x77,
		F9 = 0x78,
		F10 = 0x79,
		F11 = 0x7a,
		F12 = 0x7b,
		F13 = 0x7c,
		F14 = 0x7d,
		F15 = 0x7e,
		F16 = 0x7f,
		Numlock = 0x90,
		ScrollLock = 0x91,
		OEM_Comma = 0xbc,
		OEM_Period = 0xbe,
	};
	//window position
	struct WinPos {
		int width;
		int height;
		int left;
		int top;
	};
	//window point
	struct WinPoint {
		int x;
		int y;
	};
	//window cursor contraint state
	enum struct CursorConstraintState {
		Free,
		Confined,
		Frozen,
	};
	//window event proc
	struct WinEvent {
		//proc called directly after window initialization (opengl accessable)
		void (*Start_proc)(double time);
		//REQUIRED: proc called async with render proc 
		void (*Update_proc)(double time);
		//REQUIRED: proc called after update and render proc synchronously
		void (*SyncUpdate_proc)(double time);
		//REQUIRED: proc called on management thread async with update proc
		void (*Render_proc)(double time);
		//proc called before window closes (opengl accessable)
		void (*End_proc)(double time);
		//proc called when resizing window
		void (*Resize_proc)(double time, long width, long height);
		//proc called once when a key is down
		void (*Keydown_proc)(VertKey key);
		//proc called once when a key is up
		void (*Keyup_proc)(VertKey key);
	};
	//stamp window descriptor flag
	struct SWDF {
		enum {
			//ignores window width and height
			Borderless = 1,
			Vsync = 2,
			StencilBuffer = 4,
			DepthBuffer = 8,
			RunInBackground = 16,
			RenderInBackground = 32,
			XAudio = 64,
			NoTitleBar = 128,
			//ignored if "NoTitleBar" flag
			NoResize = 256,
			//ignored if "NoTitleBar" flag
			NoMaximize = 512,
			ThrowExceptions = 1024,
			DynamicAttributes = 2048,
		};
		unsigned int _value;
	};
	//stamp window initialization flag
	struct SWIF {
		enum {
			//creates new console window for debug output
			Debug = 1,
		};
		unsigned int _value;
	};
	//stamp window descriptor
	struct StampWindowDesc {
		const wchar_t* name = 0;
		//swdf flags
		SWDF flags{};
		//set to 0 for default
		unsigned long width = 0;
		//set to 0 for default
		unsigned long height = 0;
		WinEvent winevent;
	};

	typedef void (*SWHWND_setVsyncProc)(SWHWND*, bool);
	typedef bool (*SWHWND_getVsyncProc)(const SWHWND*);
	typedef void (*SWHWND_setBorderlessProc)(SWHWND*, bool);
	typedef bool (*SWHWND_getBorderlessProc)(const SWHWND*);
	typedef double (*SWHWND_getTimeProc)(const SWHWND*);
	typedef void (*SWHWND_processWinEventsProc)(SWHWND*);
	typedef void (*SWHWND_sleepUntilWindowTerminateProc)(SWHWND*);
	typedef void (*SWHWND_terminateWindowProc)(SWHWND*);
	typedef bool (*SWHWND_isWindowProc)(const SWHWND*);
	typedef bool (*SWHWND_isWindowActiveProc)(const SWHWND*);
	typedef long (*SWHWND_getCursorDeltaXProc)(const SWHWND*);
	typedef long (*SWHWND_getCursorDeltaYProc)(const SWHWND*);
	typedef long (*SWHWND_getCursorXProc)(const SWHWND*);
	typedef long (*SWHWND_getCursorYProc)(const SWHWND*);
	typedef long (*SWHWND_getCursorDeltaScrollProc)(const SWHWND*);
	typedef void (*SWHWND_setCursorVisibilityProc)(SWHWND*, bool visible);
	typedef bool (*SWHWND_getCursorVisibilityProc)(const SWHWND*);
	typedef void (*SWHWND_setCursorConstraintProc)(SWHWND*, CursorConstraintState state);
	typedef CursorConstraintState(*SWHWND_getCursorConstraintProc)(const SWHWND*);
	typedef void (*SWHWND_AddListenerProc)(SWHWND*, WinEvent& e);
	typedef bool (*isKeyDownProc)(VertKey key);
	typedef bool (*isKeyUpProc)(VertKey key);
	typedef WinPoint(*getCursorAbsolutePosProc)();
	typedef void (*getDesktopResolutionProc)(int& horizontal, int& vertical);
	typedef bool (*isRenderThreadProc)();
	typedef SWHWND* (*getWindowProc)();
	struct SWM_struct_t {
		SWHWND_setVsyncProc SWHWND_setVsync_proc;
		SWHWND_getVsyncProc SWHWND_getVsync_proc;
		SWHWND_setBorderlessProc SWHWND_setBorderless_proc;
		SWHWND_getBorderlessProc SWHWND_getBorderless_proc;
		SWHWND_getTimeProc SWHWND_getTime_proc;
		SWHWND_processWinEventsProc SWHWND_processWinEvents_proc;
		SWHWND_sleepUntilWindowTerminateProc SWHWND_sleepUntilWindowTerminate_proc;
		SWHWND_terminateWindowProc SWHWND_terminateWindow_proc;
		SWHWND_isWindowProc SWHWND_isWindow_proc;
		SWHWND_isWindowActiveProc SWHWND_isWindowActive_proc;
		SWHWND_getCursorDeltaXProc SWHWND_getCursorDeltaX_proc;
		SWHWND_getCursorDeltaYProc SWHWND_getCursorDeltaY_proc;
		SWHWND_getCursorXProc SWHWND_getCursorX_proc;
		SWHWND_getCursorYProc SWHWND_getCursorY_proc;
		SWHWND_getCursorDeltaScrollProc SWHWND_getCursorDeltaScroll_proc;
		SWHWND_setCursorVisibilityProc SWHWND_setCursorVisibility_proc;
		SWHWND_getCursorVisibilityProc SWHWND_getCursorVisibility_proc;
		SWHWND_setCursorConstraintProc SWHWND_setCursorConstraint_proc;
		SWHWND_getCursorConstraintProc SWHWND_getCursorConstraint_proc;
		isKeyDownProc isKeyDown_proc;
		isKeyUpProc isKeyUp_proc;
		getCursorAbsolutePosProc getCursorAbsolutePos_proc;
		getDesktopResolutionProc getDesktopResolution_proc;
		isRenderThreadProc isRenderThread_proc;
		getWindowProc getWindow_proc;
	} inline* SWM_struct = 0;

	//stamp window handle
	struct SWHWND {
		SWHWND_d* data;
		SWHWND(StampWindowDesc* desc, HINSTANCE hInstance);
		SWHWND(const SWHWND&) = delete;
		~SWHWND();

		void setVsync(bool v) { SWM_struct->SWHWND_setVsync_proc(this, v); }
		bool getVsync() const { return SWM_struct->SWHWND_getVsync_proc(this); }
		void setBorderless(bool v) { SWM_struct->SWHWND_setBorderless_proc(this, v); }
		bool getBorderless() const { return SWM_struct->SWHWND_getBorderless_proc(this); }
		double getTime() const { return SWM_struct->SWHWND_getTime_proc(this); }
		void processWinEvents() { SWM_struct->SWHWND_processWinEvents_proc(this); }
		void sleepUntilWindowTerminate() { SWM_struct->SWHWND_sleepUntilWindowTerminate_proc(this); }
		void terminateWindow() { SWM_struct->SWHWND_terminateWindow_proc(this); }
		bool isWindow() const { return SWM_struct->SWHWND_isWindow_proc(this); }
		bool isWindowActive() const { return SWM_struct->SWHWND_isWindowActive_proc(this); }
		long getCursorDeltaX() const { return SWM_struct->SWHWND_getCursorDeltaX_proc(this); }
		long getCursorDeltaY() const { return SWM_struct->SWHWND_getCursorDeltaY_proc(this); }
		long getCursorX() const { return SWM_struct->SWHWND_getCursorX_proc(this); }
		long getCursorY() const { return SWM_struct->SWHWND_getCursorY_proc(this); }
		long getCursorDeltaScroll() const { return SWM_struct->SWHWND_getCursorDeltaScroll_proc(this); }
		void setCursorVisibility(bool visible) { SWM_struct->SWHWND_setCursorVisibility_proc(this, visible); }
		bool getCursorVisibility() const { return SWM_struct->SWHWND_getCursorVisibility_proc(this); }
		void setCursorConstraint(CursorConstraintState state) { SWM_struct->SWHWND_setCursorConstraint_proc(this, state); }
		CursorConstraintState getCursorConstraint() const { return SWM_struct->SWHWND_getCursorConstraint_proc(this); }
		void AddListener(WinEvent& e);
	};

	inline bool isKeyDown(VertKey key) { return SWM_struct->isKeyDown_proc(key); }
	inline bool isKeyUp(VertKey key) { return SWM_struct->isKeyDown_proc(key); }
	inline WinPoint getCursorAbsolutePos() { return SWM_struct->getCursorAbsolutePos_proc(); }
	inline void getDesktopResolution(int& horizontal, int& vertical) { return SWM_struct->getDesktopResolution_proc(horizontal, vertical); }
	inline bool isRenderThread() { return SWM_struct->isRenderThread_proc(); }
	inline SWHWND* getWindow() { return SWM_struct->getWindow_proc(); }
}