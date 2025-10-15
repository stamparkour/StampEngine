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
#include <atomic>
#include <map>
#include <stamp/math/alignment.h>
#include <stamp/core/os/windows/win32hid.h>
#include <stamp/state.h>
#include <stamp/graphics/window.h>
#include <stamp/graphics/windowgl.h>

#define WM_STAMP_FULLSCREEN (WM_USER+0)

using namespace STAMP_GRAPHICS_NAMESPACE;
using namespace STAMP_MATH_NAMESPACE;

STAMP_GRAPHICS_NAMESPACE_BEGIN

using window_update_t = size_t;


struct Window_internal {
	//thread
	//is allive
	bool isAlive = true;
	bool inputEnabled = true;
	bool active = true;

	std::promise<void> windowClosePromise{};

	std::thread windowThread;
	Window* window = nullptr;
	HWND hWnd = NULL;
	HWND zDepthhWnd = NULL;
	window::CreationSettings settings;

	STAMP_NAMESPACE::sstring title{};

	STAMP_MATH_NAMESPACE::Vector2f alignment{ -1,1 };
	STAMP_MATH_NAMESPACE::Recti parentRect{};
	STAMP_MATH_NAMESPACE::Recti rawRect{};
	STAMP_MATH_NAMESPACE::Recti previousRawRect{};

	STAMP_MATH_NAMESPACE::Recti rect{};
	STAMP_MATH_NAMESPACE::Rectf relativeRect{};
	STAMP_MATH_NAMESPACE::Recti previousRect{};
	STAMP_MATH_NAMESPACE::Rectf relativePreviousRect{};

	STAMP_MATH_NAMESPACE::Recti clientRect{};
	STAMP_MATH_NAMESPACE::Rectf relativeClientRect{};

	STAMP_MATH_NAMESPACE::Recti rectBound{0,0,0xFFFF,0xFFFF};

	bool isBorderless = false;
	window::visibility_t visibility = window::visibility::Visible;

	Window_internal() = default;

	void CloseWindow() {
		if (!isAlive) return;
		isAlive = false;
		windowClosePromise.set_value();
	}

	void Print() {
		std::cout << "Window Internal Data:" << std::endl;
		std::cout << " Title: " << title << std::endl;
		std::cout << " Rect: " << rect << std::endl;
		std::cout << " Previous Rect: " << previousRect << std::endl;
		std::cout << " Relative Previous Rect: " << relativePreviousRect << std::endl;
		std::cout << " Relative Rect: " << relativeRect << std::endl;
		std::cout << " Client Rect: " << clientRect << std::endl;
		std::cout << " Relative Client Rect: " << relativeClientRect << std::endl;
		std::cout << " Parent Rect: " << parentRect << std::endl;
		std::cout << " Alignment: " << alignment << std::endl;
		std::cout << " Rect Bound: " << rectBound << std::endl;
		std::cout << " Visibility: " << stamp::graphics::window::visibility::to_string(visibility) << std::endl;
		std::cout << " Active: " << (active ? "true": "false") << std::endl;
		std::cout << " Input Enabled: " << (inputEnabled ? "true" : "false") << std::endl;
		std::cout << " Is Borderless: " << (isBorderless ? "true" : "false") << std::endl;
	}
};

STAMP_GRAPHICS_NAMESPACE_END

struct MonitorDetail {
	STAMP_MATH_NAMESPACE::Recti rect{};
	STAMP_MATH_NAMESPACE::Recti workAreaRect{};
	bool isPrimary;
};

static std::map<HMONITOR, MonitorDetail> monitorMap;

static HINSTANCE hInst;
static HINSTANCE hPrevInst;
static PWSTR pCmdLine;
static int nCmdShow;
static ATOM parentClassAtom;
static ATOM classAtom;

HWND parentHwnd = NULL;

BOOL MonitorEnumProc(HMONITOR monitor, HDC hdc, LPRECT rectPtr, LPARAM data) {
	std::map<HMONITOR, MonitorDetail>& m = *(std::map<HMONITOR, MonitorDetail>*)data;

	MONITORINFO info;
	info.cbSize = sizeof(MONITORINFO);
	GetMonitorInfo(monitor, &info);

	auto& i = m[monitor];
	i.rect = { info.rcMonitor.left, info.rcMonitor.top, info.rcMonitor.right, info.rcMonitor.bottom };
	i.workAreaRect = { info.rcWork.left, info.rcWork.top, info.rcWork.right, info.rcWork.bottom };
	i.isPrimary = info.dwFlags & MONITORINFOF_PRIMARY;

	return TRUE;
}

void ScanMonitors() {
	using std::swap;
	std::map<HMONITOR, MonitorDetail> m{};
	EnumDisplayMonitors(NULL, NULL, MonitorEnumProc, (LPARAM)&m);
	swap(monitorMap, m);
}

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
	case WM_DISPLAYCHANGE: {
		ScanMonitors();
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
		if (winData->isBorderless) {
			m->ptMaxSize.x = winData->parentRect.B.x - winData->parentRect.A.x;
			m->ptMaxSize.y = winData->parentRect.B.y - winData->parentRect.A.y;
		}
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

		if (winData->isBorderless) {
			if (active) {
				//make window borderless fullscreen
				Recti newRect = winData->parentRect;
				newRect.A -= winData->rect.A - winData->clientRect.A;
				newRect.B += winData->rect.B - winData->clientRect.B;
				SetWindowPos(hWnd, HWND_TOPMOST, newRect.A.x, newRect.A.y, newRect.B.x, newRect.B.y, SWP_NOACTIVATE);
			}
			else {
				ShowWindow(hWnd, SW_MINIMIZE);
			}
		}
	} return 0;
	case WM_WINDOWPOSCHANGING: {
		WINDOWPOS* position = (WINDOWPOS*)lParam;

		bool minimized = IsIconic(hWnd);
		bool maximized = IsZoomed(hWnd);

		if (maximized || minimized) return 0;

		if (!(position->flags & SWP_NOSIZE)) {
			if (winData->rectBound.A.x != winData->rectBound.B.x) {
				position->cx = max(winData->rectBound.A.x, min(winData->rectBound.B.x, position->cx));
				position->cy = max(winData->rectBound.A.y, min(winData->rectBound.B.y, position->cy));
			}
			else {
				position->cx = winData->rectBound.A.x;
				position->cy = winData->rectBound.A.y;
			}
		}
	} return 0;
	case WM_WINDOWPOSCHANGED: {
		bool minimized = IsIconic(hWnd);
		bool maximized = IsZoomed(hWnd);

		WINDOWPOS* position = (WINDOWPOS*)lParam;

		auto& monitor = monitorMap[MonitorFromWindow(hWnd, MONITOR_DEFAULTTONEAREST)];
		auto monitorOrigin = monitor.rect.A;
		auto monitorSize = monitor.rect.size();

		winData->parentRect = monitor.rect;

		RECT winRectRaw;
		GetWindowRect(hWnd, &winRectRaw);

		POINT clientTopLeft = { 0, 0 };
		ClientToScreen(hWnd, &clientTopLeft);
		RECT clientRectRaw;
		GetClientRect(hWnd, &clientRectRaw);
		Rect<int> clientRect;
		clientRect.left = clientRectRaw.left + clientTopLeft.x;
		clientRect.right = clientRectRaw.right + clientTopLeft.x;
		clientRect.top = clientRectRaw.top + clientTopLeft.y;
		clientRect.bottom = clientRectRaw.bottom + clientTopLeft.y;

		auto prevVis = winData->visibility;
		
		if (maximized) {
			if (winData->isBorderless) {
				winData->visibility = window::visibility::Borderless;
			}
			else {
				winData->visibility = window::visibility::Maximized;
			}
		}
		else if(minimized) {
			if (winData->isBorderless) {
				winData->visibility = window::visibility::BorderlessMinimized;
				std::cout << "Minimized" << std::endl;
			}
			else {
				winData->visibility = window::visibility::Minimized;
				std::cout << "Minimized" << std::endl;
			}
			return 0;
		}
		else {
			winData->visibility = window::visibility::Visible;
		}

		winData->zDepthhWnd = position->hwndInsertAfter;

		winData->clientRect.A = ConvertAlignment(alignment::TopLeft<int>, winData->alignment, clientRect.A - monitorOrigin, monitorSize);
		winData->clientRect.B = ConvertAlignment(alignment::TopLeft<int>, winData->alignment, clientRect.B - monitorOrigin, monitorSize);
		
		winData->relativeClientRect.A = (clientRect.A - monitorOrigin) / monitorSize;
		winData->relativeClientRect.B = (clientRect.B - monitorOrigin) / monitorSize;

		winData->rawRect = { winRectRaw.left, winRectRaw.top, winRectRaw.right, winRectRaw.bottom };

		winData->rect.A = ConvertAlignment(alignment::TopLeft<int>, winData->alignment, winData->rawRect.A - monitorOrigin, monitorSize);
		winData->rect.B = ConvertAlignment(alignment::TopLeft<int>, winData->alignment, winData->rawRect.B - monitorOrigin, monitorSize);

		winData->relativeRect.A = (winData->rect.A - monitorOrigin) / monitorSize;
		winData->relativeRect.B = (winData->rect.B - monitorOrigin) / monitorSize;

		if (winData->visibility == window::visibility::Visible) {
			winData->previousRect = winData->rect;
			winData->relativePreviousRect = winData->relativeRect;
			winData->previousRawRect = winData->rawRect;
		}
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
	HWND hwnd;
	windowData->hWnd = hwnd = CreateWindowExW(
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

	ShowWindow(hwnd, nCmdShow);

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
STAMP_NAMESPACE::sstring Window::Title() const noexcept {
	return windowData->title;
}
STAMP_MATH_NAMESPACE::Recti Window::ParentRect() const noexcept {
	return windowData->parentRect;
}
void Window::Rect(const STAMP_MATH_NAMESPACE::Recti& rect) noexcept {
	Recti r;
	r.A = ConvertAlignment(windowData->alignment, alignment::TopLeft<int>, rect.A, windowData->parentRect.size()) + windowData->parentRect.A;
	r.B = ConvertAlignment(windowData->alignment, alignment::TopLeft<int>, rect.B, windowData->parentRect.size()) + windowData->parentRect.A;
	
	SetWindowPos(windowData->hWnd, nullptr, r.A.x, r.A.y, r.B.x - r.A.x, r.B.y - r.A.y, SWP_NOACTIVATE | SWP_NOZORDER | SWP_SHOWWINDOW);
}
STAMP_MATH_NAMESPACE::Recti Window::Rect() const noexcept {
	return windowData->rect;
}
void Window::RelativeRect(const STAMP_MATH_NAMESPACE::Rectf& rrect) noexcept {
	Recti rect { (Vector2i)(rrect.A * (windowData->parentRect.size())), (Vector2i)(rrect.B * (windowData->parentRect.size())) };
	Recti r;
	r.A = ConvertAlignment(windowData->alignment, alignment::TopLeft<int>, rect.A, windowData->parentRect.size()) + windowData->parentRect.A;
	r.B = ConvertAlignment(windowData->alignment, alignment::TopLeft<int>, rect.B, windowData->parentRect.size()) + windowData->parentRect.A;
	
	SetWindowPos(windowData->hWnd, nullptr, r.A.x, r.A.y, r.B.x - r.A.x, r.B.y - r.A.y, SWP_NOACTIVATE | SWP_NOZORDER | SWP_SHOWWINDOW);
}
STAMP_MATH_NAMESPACE::Rectf Window::RelativeRect() const noexcept {
	return windowData->relativeRect;
}
void Window::Alignment(const STAMP_MATH_NAMESPACE::Vector2f& alignment) noexcept {
	windowData->alignment = alignment;
	SetWindowPos(windowData->hWnd, nullptr, 0, 0, 0, 0, SWP_NOACTIVATE | SWP_NOZORDER | SWP_NOMOVE | SWP_NOSIZE);
}
STAMP_MATH_NAMESPACE::Vector2f Window::Alignment() const noexcept {
	return windowData->alignment;
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
void Window::Visibility(window::visibility_t visibility) noexcept {
	if (visibility == windowData->visibility) return;
	bool prevIsBorderless = stamp::graphics::window::visibility::IsBorderlessVisibility(windowData->visibility);
	bool isBorderless = stamp::graphics::window::visibility::IsBorderlessVisibility(visibility);
	if (isBorderless && !prevIsBorderless) {
		SetWindowPos(windowData->hWnd, HWND_NOTOPMOST, windowData->previousRawRect.A.x, windowData->previousRawRect.A.y, windowData->previousRawRect.B.x - windowData->previousRawRect.A.x, windowData->previousRawRect.B.y - windowData->previousRawRect.A.y, SWP_NOACTIVATE | SWP_SHOWWINDOW);
		SetWindowLongPtrW(windowData->hWnd, GWL_STYLE, WS_POPUP | WS_VISIBLE);
		windowData->isBorderless = true;
	}
	else if (!isBorderless && prevIsBorderless) {
		windowData->isBorderless = false;
		SetWindowLongPtrW(windowData->hWnd, GWL_STYLE, WS_OVERLAPPEDWINDOW | WS_VISIBLE);
		SetWindowPos(windowData->hWnd, HWND_NOTOPMOST, windowData->previousRawRect.A.x, windowData->previousRawRect.A.y, windowData->previousRawRect.B.x - windowData->previousRawRect.A.x, windowData->previousRawRect.B.y - windowData->previousRawRect.A.y, SWP_NOACTIVATE | SWP_SHOWWINDOW);
	}

	switch (visibility) {
	case window::visibility::Hidden: {
		ShowWindow(windowData->hWnd, SW_HIDE);
	} break;
	case window::visibility::Visible: {
		ShowWindow(windowData->hWnd, SW_SHOWNORMAL);
	} break;
	case window::visibility::Minimized:
	case window::visibility::BorderlessMinimized: {
		if (!IsIconic(windowData->hWnd)) ShowWindow(windowData->hWnd, SW_MINIMIZE);
	} break;
	case window::visibility::Borderless:
	case window::visibility::Maximized: {
		if(!IsZoomed(windowData->hWnd)) ShowWindow(windowData->hWnd, SW_MAXIMIZE);
	} break;
	}
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
void Window::Close() noexcept {
	PostMessage(windowData->hWnd, WM_CLOSE, 0, 0);
}
bool Window::IsAlive() const noexcept {
	return windowData->isAlive;
}
std::future<void> Window::WindowClosePromise() const noexcept {
	return windowData->windowClosePromise.get_future();
}

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PWSTR pCmdLine, _In_ int nCmdShow) {
	::hInst = hInstance;
	::hPrevInst = hPrevInstance;
	::pCmdLine = pCmdLine;
	::nCmdShow = nCmdShow;

	Win32CreateConsole();
	ScanMonitors();

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