// Copyright 2025 Elijah Clark, Stamparkour
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <stamp/define.h>
#if defined(STAMP_PLATFORM_WINDOWS) && defined(STAMP_DEPLOY)
#include <stamp/core/os/windows/win32hid.h>
#include <iostream>
#include <stamp/state.h>
#include <stamp/graphics/window.h>
#include <stamp/graphics/windowgl.h>
#include <atomic>

using namespace STAMP_GRAPHICS_NAMESPACE;

STAMP_GRAPHICS_NAMESPACE_BEGIN

struct Window_internal {
	//thread
	//is allive
	bool isAlive = true;
	std::promise<void> windowClosePromise{};

	STAMP_NAMESPACE::sstring title{};
	STAMP_MATH_NAMESPACE::Recti rect{};
	STAMP_MATH_NAMESPACE::Recti prevRect{};
	STAMP_MATH_NAMESPACE::Recti rectBound{};
	window::visibility_t visibility = window::visibility::Visible;
	bool vsync = false;
	bool inputEnabled = true;
	bool active = true;

	std::thread windowThread;
	std::thread manageThread;
	Window* window = nullptr;
	HWND hWnd = NULL;
	window::CreationSettings settings;

	Window_internal() = default;

	void CloseWindow() {
		if (!isAlive) return;
		isAlive = false;
		windowClosePromise.set_value();
	}
};

STAMP_GRAPHICS_NAMESPACE_END


static HINSTANCE hInst;
static HINSTANCE hPrevInst;
static PWSTR pCmdLine;
static int nCmdShow;
static ATOM parentClassAtom;
static ATOM classAtom;

HWND parentHwnd = NULL;
std::atomic_int win32_windowsActive = 0;

static void Win32CreateConsole() {
#ifndef STAMP_UNITTEST
	static BOOL console = []()->BOOL {
		BOOL k = AllocConsole();
#pragma warning(suppress : 4996 6031)
		freopen("CONOUT$", "w", stdout);
#pragma warning(suppress : 4996 6031)
		freopen("CONIN$", "r", stdin);
#pragma warning(suppress : 4996 6031)
		freopen("CONOUT$", "w", stderr);

		SetConsoleOutputCP(CP_UTF8);
		return k;
		}();
#endif
}

LRESULT WndprocParent(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	//std::cout << "Parent Window Message: hex " << std::hex << uMsg << " " << (int)wParam << " " << (int)lParam << std::endl;

	switch (uMsg) {
	case WM_CREATE: {
		parentHwnd = hWnd;
		WinIntitializeHID();
	} return 0;
	case WM_INPUT: {
		WinInput(wParam, lParam);
	} return 0;
	case WM_INPUT_DEVICE_CHANGE: {
		WinInputDeviceChange(wParam, lParam);
	} return 0;
	// is input accepted
	case WM_ENABLE: {
		std::cout << "Parent Window Enable: " << (wParam != 0) << std::endl;
	} return 0;
	// is top-level window
	case WM_ACTIVATE: {
		std::cout << "Parent Window Activate: " << (wParam != WA_INACTIVE) << std::endl;
	} return 0;
	case WM_DESTROY: {
		PostQuitMessage(0);
	} return 0;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
}

LRESULT Wndproc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	Window_internal* winData = (Window_internal*)GetWindowLongPtrW(hWnd, 0);
	Window* window = winData ? winData->window : 0;

	//std::cout << "Child Window Message: hex " << std::hex << uMsg << " " << (int)wParam << " " << (int)lParam << std::endl;

	if(!winData && uMsg != WM_CREATE) {
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}

	switch (uMsg) {
	case WM_CREATE: {
		CREATESTRUCTW* c = (CREATESTRUCTW*)lParam;
		winData = (Window_internal*)(c->lpCreateParams);
		SetWindowLongPtrW(hWnd, 0, (LONG_PTR)winData);
	} return 0;
	case WM_GETMINMAXINFO: {
		MINMAXINFO* m = (MINMAXINFO*)lParam;
	} return 0;
	// is input accepted
	case WM_ENABLE: {
		bool enabled = (wParam != 0);
		winData->inputEnabled = enabled;
	} return 0;
	// is top-level window
	case WM_ACTIVATE: {
		bool active = (LOWORD(wParam) != WA_INACTIVE);
		winData->active = active;

		if (active) win32_windowsActive++;
		else win32_windowsActive--;
	} return 0;
	case WM_SIZING: {

	} return TRUE;
	case WM_MOVING: {

	} return TRUE;
	case WM_SIZE: {
		int width = LOWORD(lParam);
		int height = HIWORD(lParam);
		int type = (int)wParam; // SIZE_RESTORED, SIZE_MINIMIZED, SIZE_MAXIMIZED, SIZE_MAXSHOW, SIZE_MAXHIDE
		//std::cout << "SIZE: " << width << ", " << height << ", " << type << std::endl;

		if (type == SIZE_MINIMIZED) {
			winData->visibility = window::visibility::Minimized;
			winData->prevRect = winData->rect;
			winData->rect.Size({ width, height });
		}
		else if( type == SIZE_MAXIMIZED) {
			winData->visibility = window::visibility::Maximized;
			winData->prevRect = winData->rect;
			winData->rect.Size({ width, height });
		}
		else if(type == SIZE_RESTORED) {
			winData->visibility = window::visibility::Visible;
			winData->rect.Size({ width, height });
		}
	} return 0;
	case WM_SHOWWINDOW: {
		bool show = (wParam != 0);
		if (!show) {
			winData->visibility = window::visibility::Hidden;
		}
	} return 0;
	case WM_MOVE: {
		int x = LOWORD(lParam);
		int y = HIWORD(lParam);
		//std::cout << "MOVE: " << x << ", " << y << std::endl;

		winData->rect.TopLeft({ x, y });
	} return 0;
	case WM_STYLECHANGED: {

	} return 0;
	case WM_DESTROY: {
		if (winData) {
			winData->CloseWindow();
			winData->windowThread.detach();
		}
		PostQuitMessage(0);
	} return 0;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
}

void ParentWindowLoop(std::promise<void>* promise) {
	parentHwnd = CreateWindowExW(
		WS_EX_APPWINDOW,                // Optional window styles.
		(LPCWSTR)parentClassAtom,       // Window class
		L"StampEngine",					// Window text
		0,								// Window style

		// Size and position
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

		NULL,       // Parent window    
		NULL,       // Menu
		hInst,  // Instance handle
		NULL        // Additional application data
	);

	promise->set_value();

	if (parentHwnd == NULL) {
		return;
	}


	MSG msg;
	while (GetMessageW(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}
}

void WindowLoop(Window_internal* windowData, std::promise<void>* promise) {
	Window* window = windowData->window;
	std::u16string wtitle = STAMP_NAMESPACE::to_utf16(windowData->settings.title);
	HWND hwnd = CreateWindowExW(
		WS_EX_APPWINDOW,					// Optional window styles.
		(LPCWSTR)classAtom,					// Window class
		(LPCWSTR)wtitle.c_str(),			// Window text
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,	// Window style

		// Size and position
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

		parentHwnd, // Parent window    
		NULL,       // Menu
		hInst,		// Instance handle
		(void*)windowData   // Additional application data
	);

	promise->set_value();

	if (hwnd == NULL) {
		return;
	}

	MSG msg;
	while (GetMessageW(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}
}

Window::Window(const window::CreationSettings& settings) {
	windowData = new Window_internal();
	windowData->title = settings.title;
	windowData->window = this;
	windowData->settings = settings;

	std::promise<void> windowPromise{};
	windowData->windowThread = std::thread{ WindowLoop, this->windowData, &windowPromise };
	windowPromise.get_future().wait();
}

Window::~Window() {
	if (!this->windowData) return;
	STAMP_GRAPHICS_NAMESPACE::Window_internal* winData = this->windowData;
	windowData = nullptr;
	winData->isAlive = false;

	::DestroyWindow(winData->hWnd);

	delete winData;
}

void Window::Title(const STAMP_NAMESPACE::sstring& title) noexcept {
	windowData->title = title;
	//if (this->windowData && this->windowData->hWnd) {
	//	std::u16string wtitle = STAMP_NAMESPACE::to_utf16(title);
	//	SetWindowTextW(this->windowData->hWnd, (LPCWSTR)wtitle.c_str());
	//}
}
void Window::Rect(const STAMP_MATH_NAMESPACE::Recti& rect) noexcept {
	windowData->rect = rect;
	MoveWindow(windowData->hWnd, rect.A.x, rect.A.y, rect.B.x, rect.B.y, TRUE);
}
STAMP_MATH_NAMESPACE::Recti Window::Rect() const noexcept {
	return windowData->rect;
}
void Window::RectBound(const STAMP_MATH_NAMESPACE::Vector2i& fixedSize) noexcept {
	windowData->rectBound = { fixedSize, fixedSize };
}
void Window::RectBound(const STAMP_MATH_NAMESPACE::Recti& rect) noexcept {
	windowData->rectBound = rect;
}
STAMP_MATH_NAMESPACE::Recti Window::RectBound() const noexcept {
	return windowData->rectBound;
}
STAMP_NAMESPACE::sstring Window::Title() const noexcept {
	return windowData->title;
}
void Window::VSync(bool enabled) noexcept {
	windowData->vsync = enabled;
}
bool Window::VSync() const noexcept {
	return windowData->vsync;
}
void Window::Visibility(window::visibility_t visibility) noexcept {
	windowData->visibility = visibility;
	//if (this->windowData && this->windowData->hWnd) {
	//	//expand for min and max and fullscreen
	//	ShowWindow(this->windowData->hWnd, visibility == window::visibility::Visible ? SW_SHOW : SW_HIDE);
	//}
}
window::visibility_t Window::Visibility() const noexcept {
	return windowData->visibility;
}
void Window::Active(bool active) noexcept {
	if (active && !windowData->active) {
		SetForegroundWindow(windowData->hWnd);
	}
	windowData->active = active;
}
bool Window::Active() const noexcept {
	return windowData->active;
}

//void Window::InputEnabled(bool inputEnabled) noexcept {
//	if(inputEnabled != windowData->inputEnabled) {
//		EnableWindow(windowData->hWnd, inputEnabled);
//	}
//	windowData->inputEnabled = inputEnabled;
//}
//bool Window::InputEnabled() const noexcept {
//	return windowData->inputEnabled;
//}

std::future<void> Window::WaitForWindowClose() const noexcept {
	return windowData->windowClosePromise.get_future();
}

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PWSTR pCmdLine, _In_ int nCmdShow) {
	::hInst = hInstance;
	::hPrevInst = hPrevInstance;
	::pCmdLine = pCmdLine;
	::nCmdShow = nCmdShow;

	Win32CreateConsole();

	const wchar_t PCLASS_NAME[] = L"Stamp Parent Window Class";
	WNDCLASSEXW  wc = { };
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WndprocParent;
	wc.lpszClassName = PCLASS_NAME;

	parentClassAtom = RegisterClassExW(&wc);

	const wchar_t CLASS_NAME[] = L"Stamp Window Class";

	wc.lpfnWndProc = Wndproc;
	wc.lpszClassName = CLASS_NAME;
	wc.cbWndExtra = sizeof(void*) * 1;

	classAtom = RegisterClassExW(&wc);

	std::promise<void> parentWindowPromise;
	std::thread parentThread{ ParentWindowLoop, &parentWindowPromise };
	parentThread.detach();
	parentWindowPromise.get_future().wait();

	//need to enter stuff in here
	int returnValue = StampEngineInit(0, 0);

	DestroyWindow(parentHwnd);
	return returnValue;
}


#endif