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
#include <iostream>
#include <stamp/entry.h>
#include <stamp/graphics/window.h>
#include <stamp/graphics/windowgl.h>

using namespace STAMP_GRAPHICS_NAMESPACE;

STAMP_GRAPHICS_NAMESPACE_BEGIN

struct IWindow_internal {
	//thread
	//is allive
	std::thread windowThread;
	std::thread manageThread;
	IWindow* window = nullptr;
	HWND hWnd = NULL;
	bool isAlive = true;
	bool isVisible = false;
	int winSizeState = 0;
	window::CreationSettings settings;

	IWindow_internal() = default;

	void SetTitle_i(const STAMP_NAMESPACE::sstring& title) {
		window->title = title;
	}

	void SetVisible_i(const STAMP_GRAPHICS_NAMESPACE::window::visibility& visiblity) {
		window->visibility = visiblity;
	}

	void CloseWindow_i() {
		if (!isAlive) return;
		isAlive = false;
		window->SetWindowClosed();
	}
};

STAMP_GRAPHICS_NAMESPACE_END

static HINSTANCE hInst;
static HINSTANCE hPrevInst;
static PWSTR pCmdLine;
static int nCmdShow;
ATOM parentClassAtom;
ATOM classAtom;
HWND parentHwnd = NULL;

inline void StampCreateConsole() {
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
	std::cout << "Parent Window Message: hex " << std::hex << uMsg << " " << (int)wParam << " " << (int)lParam << std::endl;

	switch (uMsg) {
	case WM_CREATE: {

	} return 0;
	case WM_INPUT: {
		bool isInputSink = GET_RAWINPUT_CODE_WPARAM(wParam) == RIM_INPUTSINK;
		RAWINPUT* input = (RAWINPUT*)lParam;
	} return 0;
	case WM_INPUT_DEVICE_CHANGE: {
		//GIDC_ARRIVAL GIDC_REMOVAL
		bool added = (wParam == GIDC_ARRIVAL);
		HANDLE hDevice = (HANDLE)lParam;
	} return 0;
	// is input accepted
	case WM_ENABLE: {

	} return 0;
	// is top-level window
	case WM_ACTIVATE: {

	} return 0;
	case WM_DESTROY: {
		PostQuitMessage(0);
	} return 0;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
}

LRESULT Wndproc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	IWindow_internal* winData = (IWindow_internal*)GetWindowLongPtrW(hWnd, 0);
	IWindow* window = winData ? winData->window : 0;

	std::cout << "Child Window Message: hex " << std::hex << uMsg << " " << (int)wParam << " " << (int)lParam << std::endl;

	switch (uMsg) {
	case WM_CREATE: {
		CREATESTRUCTW* c = (CREATESTRUCTW*)lParam;
		winData = (IWindow_internal*)(c->lpCreateParams);
		SetWindowLongPtrW(hWnd, 0, (LONG_PTR)winData);
	} return 0;
	case WM_GETMINMAXINFO: {
		MINMAXINFO* m = (MINMAXINFO*)lParam;
	} return 0;
	case WM_SHOWWINDOW: {
		bool show = (bool)wParam;
		winData->SetVisible_i(show ? window::visibility::Visible : window::visibility::Hidden);
	} return 0;
	// is input accepted
	case WM_ENABLE: {

	} return 0;
	// is top-level window
	case WM_ACTIVATE: {

	} return 0;
	case WM_WINDOWPOSCHANGING: {

	} return 0;
	case WM_WINDOWPOSCHANGED: {

	} return 0;
	case WM_STYLECHANGED: {

	} return 0;
	case WM_DESTROY: {
		if (winData) {
			winData->CloseWindow_i();
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

	if (parentHwnd == NULL) {
		return;
	}

	promise->set_value();


	MSG msg;
	while (GetMessageW(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}
}

void WindowLoop(IWindow_internal* windowData) {
	IWindow* window = windowData->window;
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


	MSG msg;
	while (GetMessageW(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}
}

IWindow::IWindow(const window::CreationSettings& settings) {
	title = settings.title;
	this->windowData = new IWindow_internal();
	this->windowData->window = this;
	this->windowData->settings = settings;

	windowData->windowThread = std::thread{ WindowLoop, this->windowData };
}

IWindow::~IWindow() {
	if (!this->windowData) return;
	STAMP_GRAPHICS_NAMESPACE::IWindow_internal* winData = this->windowData;
	this->windowData = nullptr;
	winData->isAlive = false;

	::DestroyWindow(winData->hWnd);

	delete winData;
}

void IWindow::Title(const STAMP_NAMESPACE::sstring& title) noexcept {
	this->title = title;
	//if (this->windowData && this->windowData->hWnd) {
	//	std::u16string wtitle = STAMP_NAMESPACE::to_utf16(title);
	//	SetWindowTextW(this->windowData->hWnd, (LPCWSTR)wtitle.c_str());
	//}
}
void IWindow::Rect(const STAMP_MATH_NAMESPACE::Recti& rect) noexcept {
	this->rect = rect;
}
STAMP_MATH_NAMESPACE::Recti IWindow::Rect() const noexcept {
	return this->rect;
}
void IWindow::RectBound(const STAMP_MATH_NAMESPACE::Vector2i& fixedSize) noexcept {
	this->rectBound = { fixedSize, fixedSize };
}
void IWindow::RectBound(const STAMP_MATH_NAMESPACE::Recti& rect) noexcept {
	this->rectBound = rect;
}
STAMP_MATH_NAMESPACE::Recti IWindow::RectBound() const noexcept {
	return this->rectBound;
}
STAMP_NAMESPACE::sstring IWindow::Title() const noexcept {
	return this->title;
}
void IWindow::VSync(bool enabled) noexcept {
	this->vsync = enabled;
}
bool IWindow::VSync() const noexcept {
	return this->vsync;
}
void IWindow::Visibility(window::visibility visibility) noexcept {
	this->visibility = visibility;
	//if (this->windowData && this->windowData->hWnd) {
	//	//expand for min and max and fullscreen
	//	ShowWindow(this->windowData->hWnd, visibility == window::visibility::Visible ? SW_SHOW : SW_HIDE);
	//}
}
window::visibility IWindow::Visibility() const noexcept {
	return this->visibility;
}

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PWSTR pCmdLine, _In_ int nCmdShow) {
	::hInst = hInstance;
	::hPrevInst = hPrevInstance;
	::pCmdLine = pCmdLine;
	::nCmdShow = nCmdShow;

	StampCreateConsole();

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
	int returnValue = StampEngineEntry(0, 0);

	DestroyWindow(parentHwnd);
	return returnValue;
}


#endif