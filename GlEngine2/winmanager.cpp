#include <iostream>
#include <chrono>
#include <thread>
#include <Windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include "wincore.h"

#define GLWINMODE_ACTIVE_BIT 1
#define GLWINMODE_BORDERLESS_BIT 2
#define GLWINMODE_HOVER_CURSOR_BIT 4
#define GLWINMODE_HIDE_CURSOR_BIT 8
#define GLWINMODE_CONFINE_CURSOR_BIT 16
long long GLWinBitMask = 0;

double timerTickLength = 0;
long long timerStart = 0;
HWND windowHandle;

void InitTimer() {
	LARGE_INTEGER largeInt{};
	QueryPerformanceFrequency(&largeInt);
	timerTickLength = 1.0 / largeInt.QuadPart;
	QueryPerformanceCounter(&largeInt);
	timerStart = largeInt.QuadPart;
}

double win_event::GetTime() {
	LARGE_INTEGER largeInt{};
	QueryPerformanceCounter(&largeInt);
	return timerTickLength * (largeInt.QuadPart - timerStart);
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
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER | PFD_GENERIC_ACCELERATED,
		PFD_TYPE_RGBA, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 32, 0, 0, PFD_MAIN_PLANE, 0, 0, 0, 0
	};
	int iPixelFormat = ChoosePixelFormat(displayContext, &pfd);
	if (SetPixelFormat(displayContext, iPixelFormat, &pfd) == FALSE)
		return;
	HGLRC glContext = wglCreateContext(displayContext);
	if (wglMakeCurrent(displayContext, glContext) == FALSE)
		return;

	InitTimer();
	glDrawBuffer(GL_BACK);

	win_event::Start(win_event::GetTime());
}

void OnPaint(HWND hwnd) {
	HDC hdc = wglGetCurrentDC();
	HGLRC glc = wglGetCurrentContext();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	win_event::Render(win_event::GetTime());

	glFinish();
	SwapBuffers(hdc);
}


LRESULT Wndproc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {//WM_CLOSE
	switch (msg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
	case WM_SYSKEYDOWN:
		win_input::KeyDown((int)wParam, (lParam & (1 << 30)));
		break;
	case WM_KEYUP://https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
	case WM_SYSKEYUP:
		win_input::KeyUp((int)wParam);
		break;
	case WM_CREATE:
		OnCreate(hwnd);
		break;
	case WM_PAINT:
		break;
	case WM_SIZE:
		win_event::Resize(win_event::GetTime(), LOWORD(lParam), HIWORD(lParam));
		glViewport(0, 0, LOWORD(lParam), HIWORD(lParam));
		break;
	case WM_ACTIVATE:
		if (wParam == WA_INACTIVE) {
			GLWinBitMask &= 0xFFFFFFFF ^ GLWINMODE_ACTIVE_BIT;
			if (GLWinBitMask & GLWINMODE_BORDERLESS_BIT) {
				ShowWindow(hwnd, SW_MINIMIZE);
			}
		}
		else {
			GLWinBitMask |= GLWINMODE_ACTIVE_BIT;
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

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
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
		hwnd = CreateWindowEx(WS_EX_TOPMOST, TEXT("StampClass_GL"), TEXT("Test Window"), WS_POPUP,
			0, 0, width, height, NULL, NULL, hInstance, NULL);
		GLWinBitMask |= GLWINMODE_BORDERLESS_BIT;
	}
	else {
		hwnd = CreateWindow(TEXT("StampClass_GL"), TEXT("Test Window"),
			WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_CAPTION | WS_SYSMENU | WS_VISIBLE | WS_SIZEBOX,
			CW_USEDEFAULT, CW_USEDEFAULT, 640, 480, NULL, NULL, hInstance, NULL);
	}

	if (hwnd == NULL) {
		DWORD error = GetLastError();
		std::cout << "WINDOW CREATION ERROR: " << error;
		return error;
	}
	windowHandle = hwnd;
	ShowWindow(hwnd, nCmdShow);

	MSG msg;

	double prevTime = 0;
	while (IsWindow(hwnd)) {
		while (PeekMessage(&msg, hwnd, 0, 0, PM_REMOVE) > 0) {
			if (msg.message == WM_PAINT)
				break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		std::thread update{ win_event::Update, win_event::GetTime() };
		if (GLWinBitMask & GLWINMODE_ACTIVE_BIT) OnPaint(hwnd);
		update.join();
		win_event::SyncUpdate(win_event::GetTime());

		double time = win_event::GetTime();
		double wait = 1.0 / 65 - (time - prevTime);
		if (wait <= 0) {
			prevTime = time;
		}
		else {
			std::this_thread::sleep_for(std::chrono::milliseconds((int)(wait * 1000)));
			prevTime = win_event::GetTime();
		}
	}

	return 0;
}

bool win_input::IsKeyDown(int virtualKey) {
	return GetAsyncKeyState(virtualKey) < 0;
}

void win_event::TerminateWindow() {
	DestroyWindow(windowHandle);
}