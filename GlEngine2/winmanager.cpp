#include <iostream>
#include <chrono>
#include <thread>
#include <Windows.h>
#include <windowsx.h>
#include <hidusage.h>
#include "gl.h"
#include "wincore.h"
#pragma comment(lib,"xaudio2.lib")

#define GLWINMODE_ACTIVE_BIT 1
#define GLWINMODE_BORDERLESS_BIT 2
#define GLWINMODE_HOVER_CURSOR_BIT 4
#define GLWINMODE_INITIALIZE_BIT 8
#define GLWINMODE_DEBUG 32
#define GLWINMODE_VSYNC 64
long long GLWinBitMask = 0;

double timerTickLength = 0;
long long timerStart = 0;
long long pauseTime = 0;
HWND windowHandle;
unsigned int defaultWidth = 640;
unsigned int defaultHeight = 480;

unsigned int width = 0;
unsigned int height = 0;
unsigned int top = 0;
unsigned int left = 0;

int cursorDeltaX = 0;
int cursorDeltaY = 0;
int scrollDelta = 0;
int cursorX = 0;
int cursorY = 0;

double fixedUpdateInverval = 0.04;

win::input::CursorConstraintState cursorConstraint = win::input::CursorConstraintState::Free;


bool updateGraphics = false;
bool cursorVisible = true;
bool currentCursorVisible = true;

int getTitlebarHeight() {
	return GetSystemMetrics(SM_CYCAPTION);
}

bool InternalCursorConstraint(win::input::CursorConstraintState constraint) {
	RECT rect;
	switch (constraint) {
	case(win::input::CursorConstraintState::Free):
		return ClipCursor(NULL);
	case(win::input::CursorConstraintState::Confined):
		rect.left = left;
		rect.top = top;
		rect.bottom = top + height;
		rect.right = left + width;
		return ClipCursor(&rect);
	case(win::input::CursorConstraintState::Frozen):
		rect.left = left + width / 2;
		rect.top = top + height / 2;
		rect.right = left + width / 2 + 1;
		rect.bottom = top + height / 2 + 1;
		return ClipCursor(&rect);
	}
}

bool InternalShowCursor(bool visible) {
	if (currentCursorVisible && !visible) {
		currentCursorVisible = false;
		return ShowCursor(false);
	}
	else if(!currentCursorVisible && visible) {
		currentCursorVisible = true;
		return ShowCursor(true);
	}
}

void InitTimer() {
	LARGE_INTEGER largeInt{};
	QueryPerformanceFrequency(&largeInt);
	timerTickLength = 1.0 / largeInt.QuadPart;
	QueryPerformanceCounter(&largeInt);
	timerStart = largeInt.QuadPart;
}

double GetTimeRaw() {
	LARGE_INTEGER largeInt{};
	QueryPerformanceCounter(&largeInt);
	return largeInt.QuadPart;
}

double win::state::GetTime() {
	return timerTickLength * (GetTimeRaw() - timerStart);
}

void PauseTimer() {
	long long t = GetTimeRaw();
	if (pauseTime != 0) {
		timerStart += t - pauseTime;
	}
	pauseTime = t;
}

void GetDesktopResolution(int& horizontal, int& vertical)
{
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
	horizontal = desktop.right;
	vertical = desktop.bottom;
}

void OnCreate(HWND hwnd) {
	HDC displayContext = GetDC(hwnd);
	PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR), 1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 8, PFD_MAIN_PLANE, 0, 0, 0, 0
	};
	int iPixelFormat = ChoosePixelFormat(displayContext, &pfd);
	DescribePixelFormat(displayContext, iPixelFormat, sizeof(PIXELFORMATDESCRIPTOR), &pfd);
	if (SetPixelFormat(displayContext, iPixelFormat, &pfd) == FALSE)
		return;
	HGLRC glContext = exglCreateContext(displayContext);
	int value;
	glGetIntegerv(GL_STENCIL_BITS, &value);
	wglSwapIntervalEXT(1);
	glDrawBuffer(GLWinBitMask & GLWINMODE_VSYNC ? GL_BACK : GL_FRONT);

	RAWINPUTDEVICE Rid[1];
	Rid[0].usUsagePage = HID_USAGE_PAGE_GENERIC;
	Rid[0].usUsage = HID_USAGE_GENERIC_MOUSE;
	Rid[0].dwFlags = RIDEV_INPUTSINK;
	Rid[0].hwndTarget = hwnd;
	RegisterRawInputDevices(Rid, 1, sizeof(Rid[0]));
}

void OnPaint(HWND hwnd) {
	HDC hdc = wglGetCurrentDC();
	HGLRC glc = wglGetCurrentContext();

	glStencilMask(0xFF);
	glDepthMask(GL_TRUE);
	glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	win::event::Render(win::state::GetTime());
	if (GLWinBitMask & GLWINMODE_VSYNC) {
		glFinish();
		SwapBuffers(hdc);
	}
	else {
		glFlush();
	}
}


LRESULT Wndproc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {//WM_CLOSE
	//std::cout << msg << std::endl;
	switch (msg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		FreeConsole();
		break;
	case WM_KEYDOWN:
	case WM_SYSKEYDOWN:
		win::input::KeyDown((int)wParam, ((int)lParam & (1 << 30)));
		break;
	case WM_KEYUP://https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
	case WM_SYSKEYUP:
		win::input::KeyUp((int)wParam);
		break;
	case WM_CREATE:
		OnCreate(hwnd);
		break;
	case WM_PAINT:
		break;
	case WM_WINDOWPOSCHANGED: {
		WINDOWPOS* winpos = (WINDOWPOS*)lParam;
		width = winpos->cx;
		height = winpos->cy;
		left = winpos->x;
		top = winpos->y;
		if ((GLWinBitMask & GLWINMODE_ACTIVE_BIT) || !(GLWinBitMask & GLWINMODE_INITIALIZE_BIT)) {
			InternalCursorConstraint(cursorConstraint);
			InternalShowCursor(cursorVisible);
			GLWinBitMask |= GLWINMODE_ACTIVE_BIT;
		}
		if (!(GLWinBitMask & GLWINMODE_INITIALIZE_BIT)) {
			GLWinBitMask |= GLWINMODE_INITIALIZE_BIT;
		}
		win::event::Resize(win::state::GetTime(), width, height);
		glViewport(0, 0, width, height);
		PauseTimer();
	} break;
	case WM_ACTIVATE:
		if (wParam == WA_INACTIVE) {
			GLWinBitMask &= ~GLWINMODE_ACTIVE_BIT;
			InternalShowCursor(true);
			InternalCursorConstraint(win::input::CursorConstraintState::Free);
			if (GLWinBitMask & GLWINMODE_BORDERLESS_BIT) {
				ShowWindow(hwnd, SW_MINIMIZE);
			}
		}
		else if (GLWinBitMask & GLWINMODE_BORDERLESS_BIT) {
			InternalShowCursor(cursorVisible);
			InternalCursorConstraint(cursorConstraint);
			GLWinBitMask |= GLWINMODE_ACTIVE_BIT; 
		}
		break;
	case WM_LBUTTONDOWN:
		if (!(GLWinBitMask & GLWINMODE_ACTIVE_BIT)) {
			InternalShowCursor(cursorVisible);
			InternalCursorConstraint(cursorConstraint);
			GLWinBitMask |= GLWINMODE_ACTIVE_BIT;
		}
		break;
	case WM_INPUT:
		if (GLWinBitMask & GLWINMODE_ACTIVE_BIT) {
			UINT dwSize = sizeof(RAWINPUT);
			static BYTE lpb[sizeof(RAWINPUT)];

			GetRawInputData((HRAWINPUT)lParam, RID_INPUT, lpb, &dwSize, sizeof(RAWINPUTHEADER));

			RAWINPUT* raw = (RAWINPUT*)lpb;

			if (raw->header.dwType == RIM_TYPEMOUSE)
			{
				cursorDeltaX += raw->data.mouse.lLastX;
				cursorDeltaY += raw->data.mouse.lLastY;
			}
		}
		break;
	case WM_MOUSEWHEEL:
		if (GLWinBitMask & GLWINMODE_ACTIVE_BIT) {

			scrollDelta += GET_WHEEL_DELTA_WPARAM(wParam);
			cursorX = GET_X_LPARAM(lParam);
			cursorY = GET_Y_LPARAM(lParam);
		}
		break;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}

bool ContainsCmdLineFlag(PWSTR args, WCHAR flag) {
	bool dashed = false;
	for (int i = 0; args[i]; i++) {
		if (dashed) {
			if (args[i] == L' ') return false;
			else if (args[i] == flag) return true;
		}
		else if (args[i] == L'-') dashed = true;
	}

	return false;
}

std::atomic_bool fixedUpdateControl = true;
void FixedUpdate() {
	static double time = win::state::GetTime();
	static double prevTime = time;
	while (true) {
		while (fixedUpdateInverval - (win::state::GetTime() - prevTime) > 0) {
			std::this_thread::sleep_for(std::chrono::microseconds(1000));
			if(!fixedUpdateControl)return;
		}
		prevTime = time;
		time = win::state::GetTime();
		win::event::FixedUpdate(time);
		if (!fixedUpdateControl)return;
		
	}
}

int WINAPI wWinMain( _In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PWSTR pCmdLine, _In_ int nCmdShow) {

	if (ContainsCmdLineFlag(pCmdLine, L'd')) {
		GLWinBitMask |= GLWINMODE_DEBUG;
		AllocConsole();
#pragma warning(suppress : 4996)
		freopen("CONOUT$", "w", stdout);
#pragma warning(suppress : 4996)
		freopen("CONIN$", "r", stdin);
	}
	if (ContainsCmdLineFlag(pCmdLine, L'v')) {
		GLWinBitMask |= GLWINMODE_VSYNC;
	}

	HRESULT hr;
	hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	if (FAILED(hr))
		return hr;
	
	WNDCLASS windowClass = {
		CS_HREDRAW | CS_VREDRAW | CS_CLASSDC,
		Wndproc,
		0,
		0,
		hInstance,
		NULL,//icon
		NULL,//cursor
		NULL,
		NULL,
		TEXT("StampClass_GL")
	};

	ATOM classID = RegisterClass(&windowClass);
	if (classID == NULL) {
		DWORD error = GetLastError();
		std::cout << "CLASS CREATION ERROR: " << error;
		return error;
	}
	HWND hwnd;
	if (ContainsCmdLineFlag(pCmdLine, L'b')) {
		int width = CW_USEDEFAULT;
		int height = CW_USEDEFAULT;
		GetDesktopResolution(width, height);
		hwnd = CreateWindowEx(WS_EX_TOPMOST, TEXT("StampClass_GL"), WIN_NAME, WS_POPUP,
			0, 0, width, height, NULL, NULL, hInstance, NULL);
		GLWinBitMask |= GLWINMODE_BORDERLESS_BIT;
	}
	else {
		hwnd = CreateWindow(TEXT("StampClass_GL"), WIN_NAME,
			WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_CAPTION | WS_SYSMENU | WS_VISIBLE | WS_SIZEBOX | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
			CW_USEDEFAULT, CW_USEDEFAULT, defaultWidth, defaultHeight, NULL, NULL, hInstance, NULL);
	}

	if (hwnd == NULL) {
		DWORD error = GetLastError();
		std::cout << "WINDOW CREATION ERROR: " << error;
		return error;
	}
	windowHandle = hwnd;
	ShowWindow(hwnd, nCmdShow);



	double prevTime = 0;
	int frames = 0;
	float second = 1;

	InitTimer();

	try {
		win::event::Start(win::state::GetTime());
		std::thread* fixed{};
		MSG msg;
		while (IsWindow(hwnd)) {
			pauseTime = 0;
			for (int i = 0; i < 500 && PeekMessage(&msg, windowHandle, 0, 0, PM_REMOVE) > 0; i++) {
				if (msg.message == WM_PAINT)
					break;
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}

			//if (GLWinBitMask & GLWINMODE_ACTIVE_BIT)

			std::thread update{ win::event::Update, win::state::GetTime() };
			OnPaint(hwnd);
			update.join();
			if (fixed) {
				fixedUpdateControl = false;
				fixed->join();
				delete fixed;
				fixedUpdateControl = true;
			}
			win::event::SyncUpdate(win::state::GetTime());
			//fixed = new std::thread{ FixedUpdate };

			frames++;
			double time = win::state::GetTime();
			if (time > second) {
				second += 1;
				std::cout << "fps: " << frames << std::endl;
				frames = 0;
			}

			cursorDeltaX = 0;
			cursorDeltaY = 0;
			scrollDelta = 0;

			if (updateGraphics) {
				glDrawBuffer(GLWinBitMask & GLWINMODE_VSYNC ? GL_BACK : GL_FRONT);
				if (GLWinBitMask & GLWINMODE_BORDERLESS_BIT) {
					int width = CW_USEDEFAULT;
					int height = CW_USEDEFAULT;
					GetDesktopResolution(width, height);
					SetWindowPos(windowHandle, HWND_TOPMOST, 0, 0, width, height, SWP_ASYNCWINDOWPOS | SWP_SHOWWINDOW);
					SetWindowLongPtrA(windowHandle, GWL_EXSTYLE, WS_POPUP);
				}
				else {
					SetWindowLongPtrA(windowHandle, GWL_EXSTYLE, WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU | WS_VISIBLE | WS_SIZEBOX | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_EX_APPWINDOW);
					SetWindowPos(windowHandle, HWND_TOP, CW_USEDEFAULT, CW_USEDEFAULT, defaultWidth, defaultHeight, SWP_ASYNCWINDOWPOS | SWP_SHOWWINDOW | SWP_NOMOVE);
				}
				updateGraphics = false;
			}

			/*double wait = 1.0 / 20 - (time - prevTime);
			if (wait <= 0) {
				prevTime = time;
			}
			else {
				std::this_thread::sleep_for(std::chrono::microseconds((int)(wait * 1000000)));
				prevTime = win::event::GetTime();
			}*/
		}
	}
	catch (std::exception e){
		std::cout << "ERROR : " << e.what() << std::endl;
	}

	CoUninitialize();
	return 0;
}

bool win::input::IsKeyDown(int virtualKey) {
	return GetAsyncKeyState(virtualKey) < 0;
}

void win::state::TerminateWindow() {
	DestroyWindow(windowHandle);
}

bool win::state::isWindowActive() {
	return GLWinBitMask & GLWINMODE_BORDERLESS_BIT;
}

void win::state::SetWindowState(WindowStyle style, unsigned int width, unsigned int height) {
	switch (style) {
	case(win::state::WindowStyle::Normal): {
		if (width != 0) {
			defaultWidth = width;
			defaultHeight = height;
		}
		GLWinBitMask &= ~GLWINMODE_BORDERLESS_BIT;
	} break;	
	case(win::state::WindowStyle::Borderless): {
		GLWinBitMask |= GLWINMODE_BORDERLESS_BIT;
	} break;
	}
	updateGraphics = true;
}

void win::state::vSync(bool enable) {
	if (enable) {
		GLWinBitMask |= GLWINMODE_VSYNC;
	}
	else {
		GLWinBitMask &= ~GLWINMODE_VSYNC;
	}
	updateGraphics = true;
}

bool win::state::vSync() {
	return GLWinBitMask & GLWINMODE_VSYNC;
}

void win::input::CursorVisibility(bool visible) {
	cursorVisible = visible;
	if (GLWinBitMask & GLWINMODE_ACTIVE_BIT) {
		InternalShowCursor(cursorVisible);
	}
}

void win::input::CursorConstraint(win::input::CursorConstraintState constraint) {
	cursorConstraint = constraint;
	if (GLWinBitMask & GLWINMODE_ACTIVE_BIT) {
		InternalCursorConstraint(constraint);
	}
}

int win::input::GetCursorDeltaX() {
	return cursorDeltaX;
}
int win::input::GetCursorDeltaY() {
	return cursorDeltaY;
}
int win::input::GetCursorDeltaScroll() {
	return scrollDelta;
}
int win::input::GetCursorAbsoluteX() {
	return cursorX;
}
int win::input::GetCursorAbsoluteY() {
	return cursorY;
}
int win::input::GetCursorX() {
	return cursorX - left;
}
int win::input::GetCursorY() {
	return cursorY - top;
}

void win::state::ProcessWinEvents() {
	MSG msg;
	while(PeekMessage(&msg, windowHandle, 0, 0, PM_REMOVE) > 0) {
		if (msg.message == WM_PAINT)
			break;
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}