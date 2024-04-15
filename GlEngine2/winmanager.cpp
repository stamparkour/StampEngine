#include <iostream>
#include <chrono>
#include <thread>
#include <Windows.h>
#include "gl.h"
#include "wincore.h"

#define GLWINMODE_ACTIVE_BIT 1
#define GLWINMODE_BORDERLESS_BIT 2
#define GLWINMODE_HOVER_CURSOR_BIT 4
#define GLWINMODE_HIDE_CURSOR_BIT 8
#define GLWINMODE_CONFINE_CURSOR_BIT 16
#define GLWINMODE_DEBUG 32
#define GLWINMODE_VSYNC 64
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

double win::event::GetTime() {
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
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 8, PFD_MAIN_PLANE, 0, 0, 0, 0
	};
	int iPixelFormat = ChoosePixelFormat(displayContext, &pfd);
	DescribePixelFormat(displayContext, iPixelFormat, sizeof(PIXELFORMATDESCRIPTOR), &pfd);
	if (SetPixelFormat(displayContext, iPixelFormat, &pfd) == FALSE)
		return;
	HGLRC glContext = wglCreateContext(displayContext);
	if (wglMakeCurrent(displayContext, glContext) == FALSE)
		return;
	int value;
	glGetIntegerv(GL_STENCIL_BITS, &value);

	InitTimer();
	glDrawBuffer(GLWinBitMask & GLWINMODE_VSYNC ? GL_BACK : GL_FRONT);

	win::event::Start(win::event::GetTime());
}

void OnPaint(HWND hwnd) {
	HDC hdc = wglGetCurrentDC();
	HGLRC glc = wglGetCurrentContext();

	glStencilMask(0xFF);
	glDepthMask(GL_TRUE);
	glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	win::event::Render(win::event::GetTime());
	if (GLWinBitMask & GLWINMODE_VSYNC) {
		//glFinish();
		SwapBuffers(hdc);
	}
	else {
		glFlush();
	}
}


LRESULT Wndproc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {//WM_CLOSE
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
	case WM_SIZE:
		win::event::Resize(win::event::GetTime(), LOWORD(lParam), HIWORD(lParam));
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
	int frames = 0;
	float second = 1;
	while (IsWindow(hwnd)) {
		for (int i = 0; i < 100 && PeekMessage(&msg, hwnd, 0, 0, PM_REMOVE) > 0; i++) {
			if (msg.message == WM_PAINT)
				break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		//if (GLWinBitMask & GLWINMODE_ACTIVE_BIT)

		std::thread update{ win::event::Update, win::event::GetTime() };
		OnPaint(hwnd);
		update.join();
		win::event::SyncUpdate(win::event::GetTime());

		frames++;
		double time = win::event::GetTime();
		if (time > second) {
			second += 1;
			std::cout << "fps: " << frames << std::endl;
			frames = 0;
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

	CoUninitialize();
	return 0;
}

bool win::input::IsKeyDown(int virtualKey) {
	return GetAsyncKeyState(virtualKey) < 0;
}

void win::event::TerminateWindow() {
	DestroyWindow(windowHandle);
}