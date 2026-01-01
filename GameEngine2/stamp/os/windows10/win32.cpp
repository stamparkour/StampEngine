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

#pragma comment(lib, "Dwmapi.lib")
#pragma comment(lib, "Opengl32.lib")

#include <iostream>
#include <atomic>
#include <map>
#include <dwmapi.h>

#include <stamp/graphics/gl/define.h>

#include <stamp/math/alignment.h>
#include <stamp/os/windows10/win32hid.h>
#include <stamp/stamp.h>
#include <stamp/graphics/window.h>
#include <stamp/debug.h>
#include <set>

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
	bool focus = true;

	std::promise<void> windowClosePromise{};

	std::thread windowThread;
	Window* window = nullptr;
	HWND hWnd = NULL;
	HWND zDepthhWnd = NULL;
	window::CreationSettings settings;
	HDC hDC = NULL;

	STAMP_NAMESPACE::sstring title{};

	STAMP_MATH_NAMESPACE::Recti parentRect{};
	STAMP_MATH_NAMESPACE::Recti parentWorkAreaRect{};

	STAMP_MATH_NAMESPACE::Recti rect{};
	STAMP_MATH_NAMESPACE::Recti previousRect{};

	STAMP_MATH_NAMESPACE::Recti clientRect{};
	STAMP_MATH_NAMESPACE::Recti windowRect{};

	STAMP_MATH_NAMESPACE::Recti rectBound{0,0,0xFFFF,0xFFFF};

	window::displaymode_t displayMode = window::displaymode::Normal;
	window::visibility_t visibility = window::visibility::Visible;

	STAMP_CORE_NAMESPACE::shared_lockable<std::set<STAMP_GRAPHICS_NAMESPACE::IWindowListener*>> listeners{};

	Window_internal() = default;

	void OnResize(const Recti& newRect) {
		auto l = listeners.get_shared_lock();
		for (auto& w : listeners) w->OnResize(newRect);
	}
	void OnVisibility(window::visibility_t newVisibility) {
		auto l = listeners.get_shared_lock();
		for (auto& w : listeners) w->OnVisibility(newVisibility);
	}
	void OnDisplay(window::displaymode_t newDisplayMode) {
		auto l = listeners.get_shared_lock();
		for (auto& w : listeners) w->OnDisplay(newDisplayMode);
	}
	void OnFocus(bool isFocused) {
		auto l = listeners.get_shared_lock();
		for (auto& w : listeners) w->OnFocus(isFocused);
	}
	void OnClose() {
		auto l = listeners.get_shared_lock();
		for (auto& w : listeners) w->OnClose();
	}
	void CloseWindow() {
		if (!isAlive) return;
		isAlive = false;
		windowClosePromise.set_value();
		OnClose();
	}

	void SetBorderlessMaximized() {
		Recti newRect = parentRect;
		newRect.A -= rect.A - clientRect.A;
		newRect.B += rect.B - clientRect.B;
		SetWindowPos(hWnd, HWND_TOPMOST, newRect.A.x, newRect.A.y, newRect.B.x, newRect.B.y, SWP_NOACTIVATE | SWP_SHOWWINDOW);
	}

	void Print() {
		std::cout << "Window Internal Data:" << std::endl;
		std::cout << " Title: " << title << std::endl;
		std::cout << " Rect: " << rect << std::endl;
		std::cout << " Previous Rect: " << previousRect << std::endl;
		std::cout << " Client Rect: " << clientRect << std::endl;
		std::cout << " Parent Rect: " << parentRect << std::endl;
		std::cout << " Work Area Rect: " << parentWorkAreaRect << std::endl;
		std::cout << " Rect Bound: " << rectBound << std::endl;
		std::cout << " Visibility: " << stamp::graphics::window::visibility::to_string(visibility) << std::endl;
		std::cout << " Active: " << (focus ? "true": "false") << std::endl;
		std::cout << " Input Enabled: " << (inputEnabled ? "true" : "false") << std::endl;
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
static int nCmdShow;
static ATOM parentClassAtom;
static ATOM classAtom;

HWND parentHwnd = nullptr;
HGLRC openGlContext = nullptr;
std::thread::id renderThreadId;
PIXELFORMATDESCRIPTOR pfdGlobal = {
	sizeof(PIXELFORMATDESCRIPTOR),   // size of this pfd  
	1,                     // version number  
	PFD_DRAW_TO_WINDOW |   // support window  
	PFD_SUPPORT_OPENGL |   // support OpenGL  
	PFD_DOUBLEBUFFER,      // double buffered  
	PFD_TYPE_RGBA,         // RGBA type  
	24,                    // 24-bit color depth  
	0, 0, 0, 0, 0, 0,      // color bits ignored  
	0,                     // no alpha buffer  
	0,                     // shift bit ignored  
	0,                     // no accumulation buffer  
	0, 0, 0, 0,            // accum bits ignored  
	32,                    // 32-bit z-buffer  
	0,                     // no stencil buffer  
	0,                     // no auxiliary buffer  
	PFD_MAIN_PLANE,        // main layer  
	0,                     // reserved  
	0, 0, 0                // layer masks ignored  
};

//OPEN GL CODE

static void PixelFormat(Window_internal* window) {
	HDC hdc = GetDC(window != nullptr ? window->hWnd : parentHwnd);
	int pixelFormat = ChoosePixelFormat(hdc, &pfdGlobal);
	SetPixelFormat(hdc, pixelFormat, &pfdGlobal);
}

static void InitializedOpenGLContext() {
	STAMPASSERT(!openGlContext, "OpenGL context already initialized.");
	HDC hdc = GetDC(parentHwnd);

	PixelFormat(nullptr);
	openGlContext = wglCreateContext(hdc);
	wglMakeCurrent(hdc, openGlContext);
	GLenum err = glewInit();
	STAMPASSERT(GLEW_OK == err, "Initialization of GLEW failed.");

	renderThreadId = std::this_thread::get_id();
}

static void DestroyOpenGLContext() {
	if (openGlContext) {
		wglMakeCurrent(NULL, NULL);
		wglDeleteContext(openGlContext);
		ReleaseDC(parentHwnd, GetDC(parentHwnd));
		openGlContext = nullptr;
		renderThreadId = {};
	}
}

// MONITOR CODE

static BOOL MonitorEnumProc(HMONITOR monitor, HDC hdc, LPRECT rectPtr, LPARAM data) {
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

static void ScanMonitors() {
	using std::swap;
	std::map<HMONITOR, MonitorDetail> m{};
	EnumDisplayMonitors(NULL, NULL, MonitorEnumProc, (LPARAM)&m);
	swap(monitorMap, m);
}

//WINDOWS MANEGMENT

static LRESULT WndprocParent(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
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

static LRESULT Wndproc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
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
		winData->hWnd = hWnd;
		SetWindowLongPtrW(hWnd, 0, (LONG_PTR)winData);

		winData->hDC = GetDC(winData->hWnd);
	} return 0;
	case WM_GETMINMAXINFO: {
		MINMAXINFO* m = (MINMAXINFO*)lParam;
		if (winData->visibility == window::visibility::Maximized && winData->displayMode == window::displaymode::Borderless) {
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

		winData->focus = active;
		winData->OnFocus(active);

		if (active && winData->visibility == window::visibility::Minimized && winData->displayMode == window::displaymode::BorderlessFullscreen) {
			winData->visibility = window::visibility::Maximized;
			winData->SetBorderlessMaximized();

		}
		else if (!active && winData->visibility == window::visibility::Maximized && winData->displayMode == window::displaymode::BorderlessFullscreen) {
			winData->visibility = window::visibility::Minimized;
			ShowWindow(hWnd, SW_MINIMIZE);

		}
	} return 0;
	case WM_WINDOWPOSCHANGING: {
		WINDOWPOS* position = (WINDOWPOS*)lParam;

		bool minimized = IsIconic(hWnd);
		bool maximized = IsZoomed(hWnd);

		if (minimized || maximized) return 0;

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

		if (minimized) {
			winData->visibility = window::visibility::Minimized;
		}
		else if (maximized) {
			winData->visibility = window::visibility::Maximized;
		}
		else if (position->flags & SWP_HIDEWINDOW) {
			winData->visibility = window::visibility::Hidden;
		}
		else {
			winData->visibility = window::visibility::Visible;
		}

		auto& monitor = monitorMap[MonitorFromWindow(hWnd, MONITOR_DEFAULTTONEAREST)];
		auto monitorOrigin = monitor.rect.A;
		auto monitorSize = monitor.rect.Size();

		winData->parentRect = monitor.rect;
		winData->parentWorkAreaRect = monitor.workAreaRect;

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
		
		winData->zDepthhWnd = position->hwndInsertAfter;

		winData->clientRect = clientRect;

		winData->rect = Recti{ winRectRaw.left, winRectRaw.top, winRectRaw.right, winRectRaw.bottom };

		RECT exclude_shadow;
		DwmGetWindowAttribute(winData->hWnd, DWMWA_EXTENDED_FRAME_BOUNDS, &exclude_shadow, sizeof(RECT));
		winData->windowRect = Recti{ exclude_shadow.left, exclude_shadow.top, exclude_shadow.right, exclude_shadow.bottom };


		if (winData->visibility == window::visibility::Visible) {
			winData->previousRect = winData->rect;
			winData->OnResize(winData->rect);
		}

		winData->OnVisibility(winData->visibility);
	} return 0;
	case WM_STYLECHANGED: {

	} return 0;
	case WM_CLOSE: {
		if(winData->hDC) ReleaseDC(hWnd, winData->hDC);
		DestroyWindow(hWnd);
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

static void ParentWindowLoop(std::promise<void>* promise) {
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

//CLIENT WINDOW

static void WindowLoop(Window_internal* windowData, std::promise<void>* promise) {
	Window* window = windowData->window;
	std::u16string wtitle = STAMP_NAMESPACE::to_utf16(windowData->settings.title);
	HWND hwnd = CreateWindowExW(
		WS_EX_APPWINDOW,					// Optional window styles.
		(LPCWSTR)classAtom,					// Window class
		(LPCWSTR)wtitle.c_str(),			// Window text
		WS_OVERLAPPEDWINDOW,				// Window style

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

	if(windowData->settings.rect.Size() != Vector2i{0,0}) {
		window->Rect(windowData->settings.rect);
	}
	if (windowData->settings.rectBound.Size() != Vector2i{ 0,0 }) {
		window->RectBound(windowData->settings.rectBound);
	}
	window->Visibility(windowData->settings.visibility);
	window->DisplayMode(windowData->settings.displaymode);

	PixelFormat(windowData);

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
	if (windowData->isAlive) {
		Close();
	}
	this->WindowClosePromise().wait();
	this->windowData = nullptr;
	delete winData;
}

void Window::Title(const STAMP_NAMESPACE::sstring& title) noexcept {
	if (windowData->title == title) return;
	windowData->title = title;

	std::u16string wtitle = STAMP_NAMESPACE::to_utf16(title);
	SetWindowTextW(windowData->hWnd, (LPCWSTR)wtitle.c_str());
}
STAMP_NAMESPACE::sstring Window::Title() const noexcept {
	return windowData->title;
}
STAMP_MATH_NAMESPACE::Recti Window::ParentRect() const noexcept {
	return windowData->parentWorkAreaRect;
}
STAMP_MATH_NAMESPACE::Recti Window::MonitorRect() const noexcept {
	return windowData->parentRect;
}
void Window::Rect(const STAMP_MATH_NAMESPACE::Recti& rect) noexcept {
	auto r = rect;
	auto size = r.Size();
	if (size == 0) {
		if (r.A == 0) return;

		size = r.A;
		r.A = windowData->clientRect.A;
		r.B = r.A + size;
	}
	if (size.x <= 0 || size.y <= 0) return;


	if (Visibility() != window::visibility::Visible) {
		Visibility(stamp::graphics::window::visibility::Visible);
	}
	// don't resize if not visible
	if (Visibility() != window::visibility::Visible) return;

	Recti borderOffset = windowData->rect - windowData->windowRect;
	borderOffset.B -= borderOffset.A;
	SetWindowPos(windowData->hWnd, nullptr, r.left + borderOffset.left, r.top + borderOffset.top, size.x + borderOffset.right, size.y + borderOffset.bottom, SWP_NOACTIVATE | SWP_NOZORDER | SWP_SHOWWINDOW);
}
STAMP_MATH_NAMESPACE::Recti Window::Rect() const noexcept {
	return windowData->rect;
}
void Window::RectBound(const STAMP_MATH_NAMESPACE::Recti& rect) noexcept {
	if (rect.A == 0 && rect.B == 0) {
		windowData->rectBound = { 0,0,0xFFFF,0xFFFF };
		return;
	}
	windowData->rectBound = rect;
}
STAMP_MATH_NAMESPACE::Recti Window::RectBound() const noexcept {
	return windowData->rectBound;
}
STAMP_MATH_NAMESPACE::Recti Window::ClientRectOffset() const noexcept {
	return windowData->clientRect - windowData->rect;
}
void Window::Visibility(window::visibility_t visibility) noexcept {
	if (visibility == windowData->visibility) return;
	if (visibility == window::visibility::Visible && DisplayMode() == window::displaymode::BorderlessFullscreen) visibility = window::visibility::Maximized;
	windowData->visibility = visibility;

	switch (visibility) {
	case window::visibility::Hidden: {
		ShowWindow(windowData->hWnd, SW_HIDE);
	} break;
	case window::visibility::Visible: {
		ShowWindow(windowData->hWnd, SW_SHOWNORMAL);
	} break;
	case window::visibility::Minimized: {
		if (!IsIconic(windowData->hWnd)) ShowWindow(windowData->hWnd, SW_MINIMIZE);
	} break;
	case window::visibility::Maximized: {
		if (DisplayMode() == window::displaymode::BorderlessFullscreen) {
			windowData->SetBorderlessMaximized();
		}
		else {
			if (!IsZoomed(windowData->hWnd)) ShowWindow(windowData->hWnd, SW_MAXIMIZE);
		}
	} break;
	}
}
window::visibility_t Window::Visibility() const noexcept {
	return windowData->visibility;
}
void Window::DisplayMode(window::displaymode_t displaymode) noexcept {
	if (displaymode == windowData->displayMode) return;
	windowData->displayMode = displaymode;
	switch (displaymode) {
		case window::displaymode::Normal: {
			SetWindowLongPtrW(windowData->hWnd, GWL_STYLE, WS_OVERLAPPEDWINDOW | WS_VISIBLE);
			SetWindowLongPtrW(windowData->hWnd, GWL_EXSTYLE, WS_EX_APPWINDOW);
		} break;
		case window::displaymode::Borderless: {
			SetWindowLongPtrW(windowData->hWnd, GWL_STYLE, WS_POPUP | WS_VISIBLE);
			SetWindowLongPtrW(windowData->hWnd, GWL_EXSTYLE, WS_EX_APPWINDOW);
		} break;
		case window::displaymode::BorderlessFullscreen: {
			SetWindowLongPtrW(windowData->hWnd, GWL_STYLE, WS_POPUP | WS_VISIBLE);
			SetWindowLongPtrW(windowData->hWnd, GWL_EXSTYLE, WS_EX_APPWINDOW);
			if (Visibility() == window::visibility::Visible || Visibility() == window::visibility::Maximized) windowData->SetBorderlessMaximized();
		} break;
		case window::displaymode::Popup: {
			SetWindowLongPtrW(windowData->hWnd, GWL_STYLE, WS_POPUPWINDOW | WS_CAPTION | WS_VISIBLE);
			SetWindowLongPtrW(windowData->hWnd, GWL_EXSTYLE, WS_EX_APPWINDOW);
		} break;
		case window::displaymode::Toolbox: {
			SetWindowLongPtrW(windowData->hWnd, GWL_STYLE, WS_POPUPWINDOW | WS_CAPTION | WS_VISIBLE);
			SetWindowLongPtrW(windowData->hWnd, GWL_EXSTYLE, WS_EX_APPWINDOW | WS_EX_TOOLWINDOW);
		} break;
	}

	windowData->OnDisplay(displaymode);
}
window::displaymode_t Window::DisplayMode() const noexcept {
	return windowData->displayMode;
}
void Window::Focus(bool focus) noexcept {
	if (focus && !windowData->focus) {
		SetForegroundWindow(windowData->hWnd);
	}
	windowData->focus = focus;
}
bool Window::Focus() const noexcept {
	return windowData->focus;
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
void Window::BindDisplayContext() {
	STAMPASSERT(!STAMP_NAMESPACE::IsRenderThread(), "stamp::graphics::window::bindDisplayContext - not in render thread");
	//STAMPASSERT(!windowData->hDC, "stamp::graphics::window::bindDisplayContext - already bound");
	if (windowData->hDC) wglMakeCurrent(windowData->hDC, openGlContext);
}
//void Window::UnbindDisplayContext() {
//	STAMPASSERT(!STAMP_NAMESPACE::IsRenderThread(), "stamp::graphics::window::bindDisplayContext - not in render thread");
//	//STAMPASSERT(windowData->hDC, "stamp::graphics::window::unbindDisplayContext - not bound");
//	wglMakeCurrent(NULL, NULL);
//}
void IWindowListener::AttachWindowListener(const STAMP_CORE_NAMESPACE::threadsafe_ptr<Window>& window) {
	if (!this->window.expired()) {
		auto w = this->window.lock();
		auto l = w.get()->windowData->listeners.get_unique_lock();
		w.get()->windowData->listeners.erase(this);
	}
	this->window = window;
	if (this->window.expired()) return;

	auto w = window.get();
	auto l = w->windowData->listeners.get_unique_lock();
	w->windowData->listeners.insert(this);

	this->OnResize(w->windowData->rect);
	this->OnVisibility(w->windowData->visibility);
	this->OnDisplay(w->windowData->displayMode);
	this->OnFocus(w->windowData->focus);
}
IWindowListener::IWindowListener() {}
IWindowListener::~IWindowListener() {
	AttachWindowListener(nullptr);
}

void STAMP_NAMESPACE::InitStampEngine(const STAMP_NAMESPACE::StampEngineSettings& settings) {
	::hInst = GetModuleHandle(NULL);
	::nCmdShow = SW_NORMAL;

	if (!settings.showConsole) ShowWindow(GetConsoleWindow(), SW_HIDE);
	ScanMonitors();

	std::cout << STAMP_DESCRIPTION_STRING << std::endl;


	const wchar_t PCLASS_NAME[] = L"Stamp Parent Window Class";
	WNDCLASSEXW  wc = { };
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = ::hInst;
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

	InitializedOpenGLContext();
}

void STAMP_NAMESPACE::CloseStampEngine() {
	DestroyOpenGLContext();
	DestroyWindow(parentHwnd);

	UnregisterClass((LPCWSTR)classAtom, ::hInst);
	UnregisterClass((LPCWSTR)parentClassAtom, ::hInst);
}
bool STAMP_NAMESPACE::IsRenderThread() {
	STAMPASSERT(renderThreadId == std::thread::id{}, "stamp::graphics::IsRenderThread - Render thread not initialized.");
	return renderThreadId == std::this_thread::get_id();
}


#endif