module;

#include <windows.h>
#include <windowsx.h>
#include <hidusage.h>

export module swm;

import std;
import "debug.h";
import "glm.h";

//remove the time parameter to the scene
//add delta time function

void setScene(void* (*scene)());

export namespace swm {
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
	class SceneBase {
	protected:
		SceneBase() {}
	public:
		virtual void Start() = 0;
		virtual void End() = 0;
		virtual void Update() = 0;
		virtual void SyncUpdate() = 0;
		virtual void Render() = 0;
		virtual void Resize(long width, long height) = 0;
		virtual ~SceneBase() {}
	};
	//stamp window descriptor flag
	struct SWDF {
		enum {
			//ignores window width and height
			Borderless = 0x1,
			Vsync = 0x2,
			StencilBuffer = 0x4,
			DepthBuffer = 0x8,
			RunInBackground = 0x10,
			RenderInBackground = 0x20,
			XAudio = 0x40,
			TitleBar = 0x80,
			//ignored if "NoTitleBar" flag
			Maximizable = 0x100,
			ThrowExceptions = 0x200,
			DynamicAttributes = 0x400,
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
	};

	SceneBase* getCurrentScene();
	template<typename T>
	void initScene() {
		setScene([]() -> void* {
				return new T();
			});
	}
	void setVsync(bool v);
	bool getVsync();
	double getTime();
	double DeltaTime();
	void processWinEvents();
	void sleepUntilWindowTerminate();
	void sleepUntilGLContext();
	void terminateWindow();
	bool isWindowValid();
	bool isWindowActive();
	long getCursorDeltaX();
	long getCursorDeltaY();
	long getCursorX();
	long getCursorY();
	long getCursorDeltaScroll();
	void setCursorVisibility(bool visible);
	bool getCursorVisibility();
	void setCursorConstraint(CursorConstraintState state);
	CursorConstraintState getCursorConstraint();

	bool isKeyDown(VertKey key);
	bool isKeyHold(VertKey key);
	bool isKeyUp(VertKey key);
	bool isKeyRelease(VertKey key);
	WinPoint getCursorAbsolutePos();
	int getWindowWidth();
	int getWindowHeight();
	void getDesktopResolution(int& horizontal, int& vertical);
	bool isRenderThread();
	GLenum getScreenDrawBuffer();

	//resize window function
	void setWindowResolution(int width, int height);
	//get ratio function
	double getWindowRatio();

	//internal functions
	//user must call once before creating SWHWND 
	void initializeSWM(StampWindowDesc* desc, HINSTANCE hInstance);
	bool checkOpenGLErrors();
}

module : private;

struct UpdateWin {
	enum {
		Cursor = 1,
		vSync = 2,
		WindowMode = 4,
	};
	unsigned int _value;
};
enum struct SceneState {
	Init,
	Loop,
	End,
};
struct SWindowHandle {
	std::thread managementThread{};
	HWND winHandle = 0;
	swm::StampWindowDesc desc{};
	double screenRatio;
	bool initialized = false;
	bool active = false;
	bool vSync = false;
	bool currentCursorVisible = true;
	bool cursorVisble = false;
	bool borderless = false;
	swm::CursorConstraintState cursorContraint{};
	bool canUpdateWin = false;
	UpdateWin updateWinAttrib{};
	int deltaMouseX = 0;
	int deltaMouseY = 0;
	int cursorX = 0;
	int cursorY = 0;
	int deltaScroll = 0;
	long long pauseTime = 0;
	long long startTime = 0;
	long long prevTime = 0;
	double deltaTime = 0;
	swm::WinPos winPos{};
	HINSTANCE hInstance = 0;
	swm::SceneBase* scene;
	swm::SceneBase* (*nextScene)();
	SceneState SceneState = SceneState::End;
	std::mutex glContextMutex{};
};
SWindowHandle* localWindow = 0;

struct {
	uint8_t down[256 / 8]{};
	uint8_t hold[256 / 8]{};
} KeyboardManagerState;

void InternalKeyDown(int key) {
	int index = key / 8;
	if (index >= 256 / 8) return;
	int shift = key % 8;
	KeyboardManagerState.down[index] |= 1 << shift;
}
void InternalKeyUp(int key) {
	int index = key / 8;
	if (index >= 256 / 8) return;
	int shift = key % 8;
	KeyboardManagerState.down[index] &= ~(1 << shift);
}
bool InternalGetKeyStateDown(int key) {
	int index = key / 8;
	if (index >= 256 / 8) return false;
	int shift = key % 8;
	return (KeyboardManagerState.down[index] & 1 << shift) && !(KeyboardManagerState.hold[index] & 1 << shift);
}
bool InternalGetKeyStateHold(int key) {
	int index = key / 8;
	if (index >= 256 / 8) return false;
	int shift = key % 8;
	return KeyboardManagerState.down[index] & 1 << shift;
}
bool InternalGetKeyStateRelease(int key) {
	int index = key / 8;
	if (index >= 256 / 8) return false;
	int shift = key % 8;
	return !(KeyboardManagerState.down[index] & 1 << shift) && !(KeyboardManagerState.hold[index] & 1 << shift);
}
bool InternalGetKeyStateUp(int key) {
	int index = key / 8;
	if (index >= 256 / 8) return false;
	int shift = key % 8;
	return !(KeyboardManagerState.down[index] & 1 << shift);
}
void UpdateKeyManager() {
	for (int i = 0; i < sizeof(KeyboardManagerState.down); i++) {
		KeyboardManagerState.hold[i] = KeyboardManagerState.down[i];
	}
}
void ResetKeyManager() {
	for (int i = 0; i < sizeof(KeyboardManagerState.down); i++) {
		KeyboardManagerState.down[i] = 0;
	}
}

//timer management
double tickTimeLength = []() -> double {
	LARGE_INTEGER largeInt{};
	QueryPerformanceFrequency(&largeInt);
	return 1.0 / largeInt.QuadPart;
}();
static long long getTimeRaw() {
	LARGE_INTEGER largeInt{};
	QueryPerformanceCounter(&largeInt);
	return (largeInt.QuadPart);
}

static void PauseTimer() {
	long long t = getTimeRaw();
	if (localWindow->pauseTime != 0) {
		localWindow->startTime += t - localWindow->pauseTime;
	}
	localWindow->pauseTime = t;
}

static bool InternalCursorConstraint(swm::CursorConstraintState constraint) {
	RECT rect{};
	switch (constraint) {
	case(swm::CursorConstraintState::Free):
		return ClipCursor(NULL);
	case(swm::CursorConstraintState::Confined): {
		auto v = localWindow->winPos;
		rect.left = v.left;
		rect.top = v.top;
		rect.bottom = v.top + v.height;
		rect.right = v.left + v.width;
		return ClipCursor(&rect);
	}
	case(swm::CursorConstraintState::Frozen): {
		auto v = localWindow->winPos;
		rect.left = v.left + v.width / 2;
		rect.top = v.top + v.height / 2;
		rect.right = v.left + v.width / 2 + 1;
		rect.bottom = v.top + v.height / 2 + 1;
		return ClipCursor(&rect);
	}
	}
	return false;
}
static bool InternalShowCursor(bool visible) {
	if (localWindow->currentCursorVisible && !visible) {
		localWindow->currentCursorVisible = false;
		return ShowCursor(false);
	}
	else if (!localWindow->currentCursorVisible && visible) {
		localWindow->currentCursorVisible = true;
		return ShowCursor(true);
	}
	return 0;
}

static void OnCreate(HWND hwnd, CREATESTRUCT* create) {
	localWindow->winHandle = hwnd;
	HDC displayContext = GetDC(hwnd);
	PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR), 1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 8, PFD_MAIN_PLANE, 0, 0, 0, 0
	};
	PIXELFORMATDESCRIPTOR pfd2;
	int iPixelFormat = ChoosePixelFormat(displayContext, &pfd);
	int maxFormatIndex = DescribePixelFormat(displayContext, iPixelFormat, sizeof(PIXELFORMATDESCRIPTOR), &pfd2);
	if (SetPixelFormat(displayContext, iPixelFormat, &pfd2) == FALSE)
		return;
	HGLRC glContext = wglCreateContext(displayContext);
	STAMPERROR(wglMakeCurrent(displayContext, glContext) == FALSE, "Wndproc -> OnCreate - failed to opengl context");
	std::cout << "[opengl] max version: " << glGetString(GL_VERSION) << std::endl;
	GLMInit();
	int value;
	glGetIntegerv(GL_STENCIL_BITS, &value);
	wglSwapIntervalEXT(1);
	//if (localWindow->vSync) {
	//	glDrawBuffer(GL_BACK_LEFT);
	//}
	//else {
	//	glDrawBuffer(GL_FRONT_LEFT);
	//}
	RAWINPUTDEVICE Rid[1]{} ;
	Rid[0].usUsagePage = HID_USAGE_PAGE_GENERIC;
	Rid[0].usUsage = HID_USAGE_GENERIC_MOUSE;
	Rid[0].dwFlags = RIDEV_INPUTSINK;
	Rid[0].hwndTarget = hwnd;
	RegisterRawInputDevices(Rid, 1, sizeof(Rid[0]));
	
	std::cout << "[window] created" << std::endl;
}

void OnPaint() {
	HDC hdc = wglGetCurrentDC();
	HGLRC glc = wglGetCurrentContext();
	//glStencilMask(0xFF);
	//glDepthMask(GL_TRUE);
	//glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	if (localWindow->scene && localWindow->SceneState == SceneState::Loop) localWindow->scene->Render();

	if (localWindow->vSync) {
		if (!SwapBuffers(hdc)) std::cout << "FAILED SWAP BUFFER!" << std::endl;
	}
	else {
		glFinish();//glFlush();
	}
}

static LRESULT __stdcall Wndproc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
	case WM_DESTROY:
		if (localWindow->scene) {
			localWindow->scene->End();
			delete localWindow->scene;
			localWindow->scene = 0;
		}
		PostQuitMessage(0);
		FreeConsole();
		break;
	case WM_KEYDOWN:
	case WM_SYSKEYDOWN:
		if (!(lParam & 0x40000000)) InternalKeyDown((int)wParam);
		break;
	case WM_KEYUP://https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
	case WM_SYSKEYUP:
		InternalKeyUp((int)wParam);
		break;
	case WM_CREATE:
		OnCreate(hwnd, (CREATESTRUCT*)lParam);
		break;
	case WM_PAINT: {
		//static thread_local int count = 0;
		//if (++count > 256) {
		//	OnPaint();
		//	count = 0;
		//}
	} break;
	case WM_WINDOWPOSCHANGED: {
		WINDOWPOS* winpos = (WINDOWPOS*)lParam;
		if (localWindow->active || !localWindow->initialized) {
			InternalCursorConstraint(localWindow->cursorContraint);
			InternalShowCursor(localWindow->cursorVisble);
			localWindow->active = true;
			if (localWindow->screenRatio == 0) {
				localWindow->screenRatio = (double)winpos->cy / winpos->cx;
				localWindow->winPos.width = winpos->cx;
				localWindow->winPos.height = winpos->cy;
			}
		}
		if (!(winpos->flags & SWP_NOMOVE)) {
			localWindow->winPos.left = winpos->x;
			localWindow->winPos.top = winpos->y;
		}
		if (!(winpos->flags & SWP_NOSIZE)) {
			localWindow->screenRatio = (double)winpos->cy / winpos->cx;
			localWindow->winPos.width = winpos->cx;
			localWindow->winPos.height = winpos->cy;
		}
		if (!localWindow->initialized) {
			localWindow->initialized = true;
		}
		if (localWindow->scene && localWindow->SceneState == SceneState::Loop) localWindow->scene->Resize(winpos->cx, winpos->cy);
		//glViewport(0, 0, winpos->cx, winpos->cy);
	} break;
	case WM_ACTIVATE:
		if (wParam == WA_INACTIVE) {
			localWindow->active = false;
			InternalShowCursor(true);
			InternalCursorConstraint(swm::CursorConstraintState::Free);
			if (localWindow->borderless) {
				ShowWindow(hwnd, SW_MINIMIZE);
			}
			ResetKeyManager();
		}
		else if (localWindow->borderless) {
			InternalCursorConstraint(localWindow->cursorContraint);
			InternalShowCursor(localWindow->cursorVisble);
			localWindow->active = true;
		}
		break;
	case WM_LBUTTONDOWN:
		if (!localWindow->active) {
			InternalCursorConstraint(localWindow->cursorContraint);
			InternalShowCursor(localWindow->cursorVisble);
			localWindow->active = true;
		}
		break;
	case WM_INPUT:
		if (localWindow->active) {
			UINT dwSize = sizeof(RAWINPUT);
			static thread_local BYTE lpb[sizeof(RAWINPUT)];

			GetRawInputData((HRAWINPUT)lParam, RID_INPUT, lpb, &dwSize, sizeof(RAWINPUTHEADER));

			RAWINPUT* raw = (RAWINPUT*)lpb;

			if (raw->header.dwType == RIM_TYPEMOUSE)
			{
				localWindow->deltaMouseX += raw->data.mouse.lLastX;
				localWindow->deltaMouseY += raw->data.mouse.lLastY;
			}
		}
		break;
	case WM_MOUSEMOVE:
		if (localWindow->active) {
			localWindow->cursorX = GET_X_LPARAM(lParam);
			localWindow->cursorY = GET_Y_LPARAM(lParam);
		}
		break;
	case WM_MOUSEWHEEL:
		if (localWindow->active) {
			localWindow->deltaScroll += GET_WHEEL_DELTA_WPARAM(wParam);
			localWindow->cursorX = GET_X_LPARAM(lParam);
			localWindow->cursorY = GET_Y_LPARAM(lParam);
		}
		break;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

static void CreateSWindow() {
	if (localWindow->borderless) {
		int width = CW_USEDEFAULT;
		int height = CW_USEDEFAULT;
		swm::getDesktopResolution(width, height);
		localWindow->winHandle = CreateWindowExW(WS_EX_TOPMOST, L"StampWinManager_CLASS", localWindow->desc.name, WS_POPUP | WS_VISIBLE | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
			0, 0, width, height, NULL, NULL, localWindow->hInstance, nullptr);
	}
	else {
		int defaultWidth = localWindow->desc.width != 0 ? localWindow->desc.width : CW_USEDEFAULT;
		int defaultHeight = localWindow->desc.height != 0 ? localWindow->desc.height : CW_USEDEFAULT;
		localWindow->winHandle = CreateWindowExW(0, L"StampWinManager_CLASS", localWindow->desc.name,
			(localWindow->desc.flags._value & swm::SWDF::Maximizable ? WS_MAXIMIZEBOX : 0) |
			(localWindow->desc.flags._value & swm::SWDF::TitleBar ? WS_CAPTION | WS_SYSMENU : 0) |
			WS_MINIMIZEBOX | WS_VISIBLE | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
			CW_USEDEFAULT, CW_USEDEFAULT, defaultWidth, defaultHeight, NULL, NULL, localWindow->hInstance, nullptr);
	}
	STAMPERROR(localWindow->winHandle == NULL, "swm::SWHWND -> ManageWindow - failed to initialize window: " << GetLastError());
}

static void ManageWindow() {
	localWindow->glContextMutex.lock();
	localWindow->startTime = getTimeRaw();

	CreateSWindow();

	MSG msg;
	localWindow->glContextMutex.unlock();

	std::cout << "[window] start running loop" << std::endl;
	while (IsWindow(localWindow->winHandle)) {
		for (int i = 0; i < 500 && PeekMessage(&msg, localWindow->winHandle, 0, 0, PM_REMOVE) != 0; i++) {
			if (msg.message == WM_PAINT)
				break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		localWindow->pauseTime = 0;

		//scene sync updates
		if (localWindow->SceneState == SceneState::End) {
			if (localWindow->scene) {
				localWindow->scene->End();
				delete localWindow->scene;
			}
			localWindow->SceneState = SceneState::Init;
			localWindow->scene = localWindow->nextScene();
		}
		if (localWindow->scene) {
			if (localWindow->SceneState == SceneState::Loop) localWindow->scene->SyncUpdate();
			else if (localWindow->SceneState == SceneState::Init) {
				localWindow->scene->Start();
				localWindow->SceneState = SceneState::Loop;
				localWindow->scene->SyncUpdate();
			}
		}

		std::thread update{ []() {
			if (localWindow->scene && localWindow->SceneState == SceneState::Loop) localWindow->scene->Update();
		} };

		OnPaint();
		update.join();

		localWindow->deltaMouseX = 0;
		localWindow->deltaMouseY = 0;
		localWindow->deltaScroll = 0;
		UpdateKeyManager();

		if (localWindow->updateWinAttrib._value) {
			if (localWindow->updateWinAttrib._value & UpdateWin::Cursor) {
				InternalCursorConstraint(localWindow->cursorContraint);
				InternalShowCursor(localWindow->cursorVisble);
			}
			if (localWindow->updateWinAttrib._value & UpdateWin::vSync) {
				//glDrawBuffer(localWindow->vSync ? GL_BACK_LEFT : GL_FRONT_LEFT);
			}
			if (localWindow->updateWinAttrib._value & UpdateWin::WindowMode) {
				//borderless
			}
			localWindow->updateWinAttrib._value = 0;
		}
		long long pt = getTimeRaw();
		localWindow->deltaTime = (pt-localWindow->prevTime) * tickTimeLength;
		localWindow->prevTime = pt;
	}
}

void swm::initializeSWM(StampWindowDesc* desc, HINSTANCE hInstance) {
	static bool hasInit = false;
	if (hasInit) return;
	hasInit = true;

#ifdef SWM_DEBUG
	AllocConsole();
#pragma warning(suppress : 4996 6031)
	freopen("CONOUT$", "w", stdout);
#pragma warning(suppress : 4996 6031)
	freopen("CONIN$", "r", stdin);
#pragma warning(suppress : 4996 6031)
	freopen("CONOUT$", "w", stderr);
#endif

	HRESULT hr;
	hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	if (FAILED(hr)) {
		STAMPSTACK();
		STAMPDMSG("swm::initializeSWM - failed to start \"CoInitializerEx\": " << hr);
		return;
	}

	//creates window class

	WNDCLASSEXW windowClass = {
		sizeof(WNDCLASSEXW),
		CS_HREDRAW | CS_VREDRAW | CS_CLASSDC,
		Wndproc,
		0,
		sizeof(void*),
		hInstance,
		NULL,//icon
		NULL,//cursor
		NULL,
		NULL,
		L"StampWinManager_CLASS",
		NULL
	};

	ATOM windowClassAtom = RegisterClassExW(&windowClass);
	if (windowClassAtom == NULL) {
		DWORD error = GetLastError();
		STAMPSTACK();
		STAMPDMSG("swm::initializeSWM - failed to start \"CoInitializerEx\": " << error);
		return;
	}

	if (desc == NULL) return;

	localWindow = new SWindowHandle();
	if(desc->height != 0 && desc->width != 0) localWindow->screenRatio = (double)desc->height / desc->width;
	localWindow->updateWinAttrib._value = 0;
	localWindow->desc = *desc;
	localWindow->borderless = desc->flags._value & SWDF::Borderless;
	localWindow->vSync = desc->flags._value & SWDF::Vsync;
	localWindow->cursorContraint = swm::CursorConstraintState::Free;
	localWindow->hInstance = hInstance;
	localWindow->canUpdateWin = desc->flags._value & SWDF::DynamicAttributes;
	localWindow->managementThread = std::thread{ ManageWindow };
}


bool swm::checkOpenGLErrors() {
	GLenum error = glGetError();
	bool k = false;
	while (error != GL_NO_ERROR) {
		k = true;
		// Handle the error appropriately
		std::cout << "OpenGL error: (" << error << ") ";
		switch (error) {
		case GL_INVALID_ENUM:
			std::cout << "invalid enum";
			break;
		case GL_INVALID_VALUE:
			std::cout << "invalid value";
			break;
		case GL_INVALID_OPERATION:
			std::cout << "invalid operation";
			break;
		case GL_STACK_OVERFLOW:
			std::cout << "stack overflow";
			break;
		case GL_STACK_UNDERFLOW:
			std::cout << "stack underflow";
			break;
		case GL_OUT_OF_MEMORY:
			std::cout << "out of memory";
			break;
		case GL_INVALID_FRAMEBUFFER_OPERATION:
			std::cout << "invalid framebuffer operation";
			break;
		case GL_CONTEXT_LOST:
			std::cout << "context lost";
			break;
		case GL_TABLE_TOO_LARGE:
			std::cout << "table too large";
			break;
		}
		std::cout << std::endl;
		error = glGetError();
	}
	return k;
}

void swm::setVsync(bool v) {
	STAMPERROR(!localWindow->canUpdateWin, "swm::SWHWND::setVsync - cannot update window in current configuration.");
	localWindow->vSync = v;
	localWindow->updateWinAttrib._value |= UpdateWin::vSync;
};
bool swm::getVsync() {
	return localWindow->vSync;
}
swm::WinPoint swm::getCursorAbsolutePos() {
	POINT p;
	GetCursorPos(&p);
	swm::WinPoint k{};
	k.x = p.x;
	k.y = p.y;
	return k;
}
double swm::getTime()  {
	return (getTimeRaw() - localWindow->startTime) * tickTimeLength;
}
double swm::DeltaTime() {
	return localWindow->deltaTime;
}
int swm::getWindowWidth() {
	return localWindow->winPos.width;
}
int swm::getWindowHeight() {
	return localWindow->winPos.height;
}
void swm::getDesktopResolution(int& horizontal, int& vertical) {
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
	horizontal = desktop.right;
	vertical = desktop.bottom;
}
bool swm::isKeyDown(swm::VertKey key) {
	return InternalGetKeyStateDown((int)key);
}
bool swm::isKeyHold(swm::VertKey key) {
	return InternalGetKeyStateHold((int)key);
}
bool swm::isKeyUp(swm::VertKey key) {
	return InternalGetKeyStateUp((int)key);
}
bool swm::isKeyRelease(swm::VertKey key) {
	return InternalGetKeyStateRelease((int)key);
}
long swm::getCursorDeltaScroll() {
	return localWindow->deltaScroll;
}
long swm::getCursorDeltaX() {
	return localWindow->deltaMouseX;
}
long swm::getCursorDeltaY() {
	return localWindow->deltaMouseY;
}
long swm::getCursorX() {
	return localWindow->cursorX;
}
long swm::getCursorY() {
	return localWindow->cursorY;
}
void swm::setCursorVisibility(bool visible) {
	localWindow->cursorVisble = visible;
	localWindow->updateWinAttrib._value |= UpdateWin::Cursor;
}
bool swm::getCursorVisibility() {
	return localWindow->cursorVisble;
}
void swm::setCursorConstraint(swm::CursorConstraintState state) {
	localWindow->cursorContraint = state;
	localWindow->updateWinAttrib._value |= UpdateWin::Cursor;
}
swm::CursorConstraintState swm::getCursorConstraint() {
	return localWindow->cursorContraint;
}
void swm::terminateWindow() {
	DestroyWindow(localWindow->winHandle);
}
bool swm::isWindowValid() {
	return IsWindow(localWindow->winHandle);
}
bool swm::isWindowActive() {
	return localWindow->active;
}
void swm::sleepUntilWindowTerminate() {
	STAMPERROR(std::this_thread::get_id() == localWindow->managementThread.get_id(),
		"swm::SWHWND::sleepUntilWindowTerminate - wrong thread, thread required is not management thread");
	localWindow->managementThread.join();
}
void swm::sleepUntilGLContext() {
	STAMPERROR(!localWindow || std::this_thread::get_id() == localWindow->managementThread.get_id(),
		"swm::SWHWND::sleepUntilGLContext - wrong thread, thread required is not management thread");
	localWindow->glContextMutex.lock();
	localWindow->glContextMutex.unlock();
}
void swm::processWinEvents() {
	STAMPERROR(std::this_thread::get_id() != localWindow->managementThread.get_id(),
		"swm::SWHWND::processWinEvents - wrong thread, thread required is management thread");
	MSG msg;
	while (PeekMessage(&msg, localWindow->winHandle, 0, 0, PM_REMOVE) > 0) {
		if (msg.message == WM_PAINT)
			break;
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}
bool swm::isRenderThread() {
	return std::this_thread::get_id() == localWindow->managementThread.get_id();
}
GLenum swm::getScreenDrawBuffer() {
	return localWindow->vSync ? GL_BACK_LEFT : GL_FRONT_LEFT;
}
swm::SceneBase* swm::getCurrentScene()
{
	return localWindow->scene;
}
void swm::setWindowResolution(int width, int height) {
	SetWindowPos(localWindow->winHandle, NULL, 0, 0, width, height, SWP_NOMOVE);
}
double swm::getWindowRatio() {
	return localWindow->screenRatio;
}
void setScene(void* (*scene)()) {
	localWindow->SceneState = SceneState::End;
	localWindow->nextScene = (swm::SceneBase* (*)())scene;
}