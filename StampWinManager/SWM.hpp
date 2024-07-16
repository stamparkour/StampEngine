#pragma once
#include <Windows.h>

#ifdef STAMPWINMANAGER_EXPORTS
#define __declspec(dllexport)
#else
#define __declspec(dllimport)
#endif

#define SWM_WRONG_THREAD 0x1A0000

namespace swm {
	struct VertKey {
		enum {
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
		int value;
	};
	struct WinPos {
		int width;
		int height;
		int left;
		int top;
	};
	enum struct CursorConstraintState {
		Free,
		Confined,
		Frozen,
	};
	struct winevent {
		void (*Start_proc)(double time);
		void (*Update_proc)(double time);
		void (*SyncUpdate_proc)(double time);
		void (*Resize_proc)(double time, long width, long height);
		void (*Render_proc)(double time);
		void (*Keydown_proc)(VertKey key);
		void (*Keyup_proc)(VertKey key);
	};
	//stamp window descriptor flag
	struct SWDF {
		enum {
			//ignores width and height
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
		unsigned int value;
	};
	//stamp window initialization flag
	struct SWIF {
		enum {
			Debug = 1,
		};
		unsigned int value;
	};
	struct StampWindowDesc {
		const wchar_t* name = 0;
		//swdf flags
		unsigned long flags = 0;
		//set to 0 for default
		unsigned long width = 0;
		//set to 0 for default
		unsigned long height = 0;
		winevent winevent;
	};
	struct SWHWND {
		struct SWHWND_d* data;
		SWHWND(StampWindowDesc* desc, HINSTANCE hInstance);
		SWHWND(const SWHWND&) = delete;
		~SWHWND();

		void setVsync(bool);
		bool getVsync() const;
		void setBorderless(bool);
		bool getBorderless() const;
		double getTime() const;
		void processWinEvents();
		void sleepUntilWindowTerminate();
		void terminateWindow();
		bool isWindow() const;
		bool isWindowActive() const;
		long getCursorDeltaX() const;
		long getCursorDeltaY() const;
		long getCursorX() const;
		long getCursorY() const;
		long getCursorDeltaScroll() const;
		void setCursorVisibility(bool visible);
		bool getCursorVisibility() const;
		void setCursorConstraint(CursorConstraintState state);
		CursorConstraintState getCursorConstraint();
	};

	bool isKeyDown(VertKey key);
	bool isKeyUp(VertKey key);
	POINT getCursorAbsolutePos();
	
	void getDesktopResolution(int& horizontal, int& vertical);

	void initializeSWM(HINSTANCE hInstance, SWIF flags);
}


#ifdef STAMPWINMANAGER_SAFE
namespace win::event {
	void Start(double time);
	void Update(double time);
	void SyncUpdate(double time);
	void Resize(double time);
	void Render(double time);
	stamp::win::StampWindowDesc WIN_DESC;
}
int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PWSTR pCmdLine, _In_ int nCmdShow) {
	auto w = stamp::win::registerWindow(&win::event::WIN_DESC);
	WIN_DESC.
	stamp::win::sleepUntilWindowTerminate(w);
}
#endif

