#include "SWM.hpp"
#include <thread>
#include <hidusage.h>
#include <windowsx.h>
#include "eventlistener.hpp"
#include "EL_list.hpp"

EventListener<swm::SWHWND*> EL_WinCreateGLInit;

struct UpdateWin {
	enum {
		Cursor = 1,
		vSync = 2,
		WindowMode = 4,
	};
	unsigned int _value;
};

struct swm::SWHWND_d {
	std::thread managementThread{};
	HWND winHandle = 0;
	swm::StampWindowDesc desc{};
	bool initialized = false;
	bool active = false;
	bool vSync = false;
	bool currentCursorVisible = false;
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
	swm::WinPos winPos{};
	HINSTANCE hInstance = 0;
};
//timer management
double tickTimeLength = []() -> double {
	LARGE_INTEGER largeInt{};
	QueryPerformanceFrequency(&largeInt);
	return 1.0 / largeInt.QuadPart;
}();
long long getTimeRaw() {
	LARGE_INTEGER largeInt{};
	QueryPerformanceCounter(&largeInt);
	return (largeInt.QuadPart);
}
double swm::SWHWND::getTime() const {
	return (getTimeRaw() - data->startTime) * tickTimeLength;
}
void PauseTimer(swm::SWHWND* win) {
	long long t = getTimeRaw();
	if (win->data->pauseTime != 0) {
		win->data->startTime += t - win->data->pauseTime;
	}
	win->data->pauseTime = t;
}

POINT swm::getCursorAbsolutePos() {
	POINT p;
	GetCursorPos(&p);
	return p;
}
void swm::getDesktopResolution(int& horizontal, int& vertical) {
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
	horizontal = desktop.right;
	vertical = desktop.bottom;
}

bool InternalCursorConstraint(swm::SWHWND* win, swm::CursorConstraintState constraint) {
	RECT rect;
	switch (constraint) {
	case(swm::CursorConstraintState::Free):
		return ClipCursor(NULL);
	case(swm::CursorConstraintState::Confined): {
		auto v = win->data->winPos;
		rect.left = v.left;
		rect.top = v.top;
		rect.bottom = v.top + v.height;
		rect.right = v.left + v.width;
		return ClipCursor(&rect);
	}
	case(swm::CursorConstraintState::Frozen): {
		auto v = win->data->winPos;
		rect.left = v.left + v.width / 2;
		rect.top = v.top + v.height / 2;
		rect.right = v.left + v.width / 2 + 1;
		rect.bottom = v.top + v.height / 2 + 1;
		return ClipCursor(&rect);
	}
	}
	return false;
}
bool InternalShowCursor(swm::SWHWND* win, bool visible) {
	if (win->data->currentCursorVisible && !visible) {
		win->data->currentCursorVisible = false;
		return ShowCursor(false);
	}
	else if (!win->data->currentCursorVisible && visible) {
		win->data->currentCursorVisible = true;
		return ShowCursor(true);
	}
	return 0;
}

bool swm::isKeyDown(VertKey key) {
	return GetAsyncKeyState(key._value) < 0;
}
bool swm::isKeyUp(VertKey key) {
	return !swm::isKeyDown(key);
}

void swm::SWHWND::setVsync(bool v) {
	if (!data->canUpdateWin) throw - 1;
	data->vSync = v;
	data->updateWinAttrib._value |= UpdateWin::vSync;
}
bool swm::SWHWND::getVsync() const {
	return data->vSync;
}
void swm::SWHWND::setBorderless(bool v) {
	if (!data->canUpdateWin) throw - 1;
	data->borderless = v;
	data->updateWinAttrib._value |= UpdateWin::WindowMode;
}
bool swm::SWHWND::getBorderless() const {
	return data->borderless;
}
long swm::SWHWND::getCursorDeltaScroll() const {
	return data->deltaScroll;
}
long swm::SWHWND::getCursorDeltaX() const {
	return data->deltaMouseX;
}
long swm::SWHWND::getCursorDeltaY() const {
	return data->deltaMouseY;
}
long swm::SWHWND::getCursorX() const {
	return data->cursorX;
}
long swm::SWHWND::getCursorY() const {
	return data->cursorY;
}
void swm::SWHWND::setCursorVisibility(bool visible) {
	data->cursorVisble = visible;
	data->updateWinAttrib._value |= UpdateWin::Cursor;
}
bool swm::SWHWND::getCursorVisibility() const {
	return data->cursorVisble;
}
void swm::SWHWND::setCursorConstraint(swm::CursorConstraintState state) {
	data->cursorContraint = state;
	data->updateWinAttrib._value |= UpdateWin::Cursor;
}
swm::CursorConstraintState swm::SWHWND::getCursorConstraint() {
	return data->cursorContraint;
}
void swm::SWHWND::terminateWindow() {
	DestroyWindow(data->winHandle);
}
bool swm::SWHWND::isWindow() const {
	return IsWindow(data->winHandle);
}
bool swm::SWHWND::isWindowActive() const {
	return data->active;
}
void swm::SWHWND::sleepUntilWindowTerminate() {
	if (std::this_thread::get_id() == data->managementThread.get_id()) 
		throw new std::exception("current thread cannot be the same as management thread.", SWM_WRONG_THREAD);
	data->managementThread.join();
}
void swm::SWHWND::processWinEvents() {
	if (std::this_thread::get_id() != data->managementThread.get_id())
		throw new std::exception("current thread requires to be management thread.", SWM_WRONG_THREAD);
	MSG msg;
	while (PeekMessage(&msg, data->winHandle, 0, 0, PM_REMOVE) > 0) {
		if (msg.message == WM_PAINT)
			break;
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

void OnCreate(HWND hwnd, CREATESTRUCT* create) {
	swm::SWHWND* ptr = (swm::SWHWND*)create->lpCreateParams;
	ptr->data->winHandle = hwnd;
	SetWindowLongPtr(hwnd, 0, (LONG_PTR)ptr);
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
	if (wglMakeCurrent(displayContext, glContext) == FALSE) throw SWM_GL_FAIL_CREATION;
	glmInit();
	EL_WinCreateGLInit(ptr);
	int value;
	glGetIntegerv(GL_STENCIL_BITS, &value);
	wglSwapIntervalEXT(1);
	glDrawBuffer(ptr->data->vSync ? GL_BACK : GL_FRONT);

	RAWINPUTDEVICE Rid[1];
	Rid[0].usUsagePage = HID_USAGE_PAGE_GENERIC;
	Rid[0].usUsage = HID_USAGE_GENERIC_MOUSE;
	Rid[0].dwFlags = RIDEV_INPUTSINK;
	Rid[0].hwndTarget = hwnd;
	RegisterRawInputDevices(Rid, 1, sizeof(Rid[0]));
	ReleaseDC(hwnd, displayContext);
}

LRESULT __stdcall Wndproc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	swm::SWHWND* ptr = (swm::SWHWND*)GetWindowLongPtrW(hwnd, 0);
	swm::SWHWND_d* data = 0;
	if (ptr != NULL) data = ptr->data;
	switch (msg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		FreeConsole();
		break;
	case WM_KEYDOWN:
	case WM_SYSKEYDOWN:
		if(data && data->desc.winevent.Keydown_proc) data->desc.winevent.Keydown_proc(swm::VertKey{ (int)wParam });
		break;
	case WM_KEYUP://https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
	case WM_SYSKEYUP:
		data->desc.winevent.Keyup_proc(swm::VertKey{ (int)wParam });
		break;
	case WM_CREATE:
		OnCreate(hwnd, (CREATESTRUCT*)lParam);
		break;
	case WM_PAINT:
		break;
	case WM_WINDOWPOSCHANGED: {
		WINDOWPOS* winpos = (WINDOWPOS*)lParam;
		data->winPos.width = winpos->cx;
		data->winPos.height = winpos->cy;
		data->winPos.left = winpos->x;
		data->winPos.top = winpos->y;
		if (data->active || !data->initialized) {
			InternalCursorConstraint(ptr, data->cursorContraint);
			InternalShowCursor(ptr, data->cursorVisble);
			data->active = true;
		}
		if (!data->initialized) {
			data->initialized = true;
		}
		if (data && data->desc.winevent.Resize_proc) data->desc.winevent.Resize_proc(ptr->getTime(), winpos->cx, winpos->cy);
		glViewport(0, 0, winpos->cx, winpos->cy);
		PauseTimer(ptr);
	} break;
	case WM_ACTIVATE:
		if (wParam == WA_INACTIVE) {
			data->active = false;
			InternalShowCursor(ptr,true);
			InternalCursorConstraint(ptr, swm::CursorConstraintState::Free);
			if (data->borderless) {
				ShowWindow(hwnd, SW_MINIMIZE);
			}
		}
		else if (data->borderless) {
			InternalCursorConstraint(ptr, data->cursorContraint);
			InternalShowCursor(ptr, data->cursorVisble);
			data->active = true;
		}
		break;
	case WM_LBUTTONDOWN:
		if (!data->active) {
			InternalCursorConstraint(ptr, data->cursorContraint);
			InternalShowCursor(ptr, data->cursorVisble);
			data->active = true;
		}
		break;
	case WM_INPUT:
		if (data->active) {
			UINT dwSize = sizeof(RAWINPUT);
			static thread_local BYTE lpb[sizeof(RAWINPUT)];

			GetRawInputData((HRAWINPUT)lParam, RID_INPUT, lpb, &dwSize, sizeof(RAWINPUTHEADER));

			RAWINPUT* raw = (RAWINPUT*)lpb;

			if (raw->header.dwType == RIM_TYPEMOUSE)
			{
				data->deltaMouseX += raw->data.mouse.lLastX;
				data->deltaMouseY += raw->data.mouse.lLastY;
			}
		}
		break;
	case WM_MOUSEMOVE:
		if (data->active) {
			data->cursorX = GET_X_LPARAM(lParam);
			data->cursorY = GET_Y_LPARAM(lParam);
		}
		break;
	case WM_MOUSEWHEEL:
		if (data->active) {
			data->deltaScroll += GET_WHEEL_DELTA_WPARAM(wParam);
			data->cursorX = GET_X_LPARAM(lParam);
			data->cursorY = GET_Y_LPARAM(lParam);
		}
		break;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}

void ManageWindow(swm::SWHWND* ptr) {
	auto* data = ptr->data;
	if (data->borderless) {
		int width = CW_USEDEFAULT;
		int height = CW_USEDEFAULT;
		swm::getDesktopResolution(width, height);
		data->winHandle = CreateWindowExW(WS_EX_TOPMOST, L"StampWinManager_CLASS", data->desc.name, WS_POPUP,
			0, 0, width, height, NULL, NULL, data->hInstance, ptr);
	}
	else {
		int defaultWidth = data->desc.width != 0 ? data->desc.width : CW_USEDEFAULT;
		int defaultHeight = data->desc.height != 0 ? data->desc.height : CW_USEDEFAULT;
		data->winHandle = CreateWindowW(L"StampWinManager_CLASS", data->desc.name,
			WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_CAPTION | WS_SYSMENU | WS_VISIBLE | WS_SIZEBOX | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
			CW_USEDEFAULT, CW_USEDEFAULT, defaultWidth, defaultHeight, NULL, NULL, data->hInstance, ptr);
	}

	if (data->winHandle == NULL) {
		DWORD error = GetLastError();
		throw SWM_WINDOW_FAIL_CREATION;
	}

	data->startTime = getTimeRaw();
	try {
		if(data->desc.winevent.Start_proc) data->desc.winevent.Start_proc(ptr->getTime());
		MSG msg;
		while (IsWindow(data->winHandle)) {
			for (int i = 0; i < 500 && PeekMessage(&msg, data->winHandle, 0, 0, PM_REMOVE) != 0; i++) {
				if (msg.message == WM_PAINT)
					break;
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}

			std::thread update{ data->desc.winevent.Update_proc, ptr->getTime() };

			HDC hdc = wglGetCurrentDC();
			//HGLRC glc = wglGetCurrentContext();
			glStencilMask(0xFF);
			glDepthMask(GL_TRUE);
			glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

			if(data->desc.winevent.Render_proc) data->desc.winevent.Render_proc(ptr->getTime());
			glFlush();//glFinish();
			if (data->vSync) SwapBuffers(hdc);

			update.join();
			if(data->desc.winevent.SyncUpdate_proc) data->desc.winevent.SyncUpdate_proc(ptr->getTime());

			data->deltaMouseX = 0;
			data->deltaMouseY = 0;
			data->deltaScroll = 0;

			if (data->updateWinAttrib._value) {
				if (data->updateWinAttrib._value & UpdateWin::Cursor) {
					InternalCursorConstraint(ptr, data->cursorContraint);
					InternalShowCursor(ptr, data->cursorVisble);
				}
				if (data->updateWinAttrib._value & UpdateWin::vSync) {
					glDrawBuffer(data->vSync ? GL_BACK : GL_FRONT);
				}
				if (data->updateWinAttrib._value & UpdateWin::WindowMode) {
					//borderless
				}
				data->updateWinAttrib._value = 0;
			}
		}
	}
	catch (std::exception e) {

	}
}

void swm::initializeSWM(HINSTANCE hInstance, SWIF flags) {
	static bool hasInit = false;
	if (hasInit) return;
	hasInit = true;

	HRESULT hr;
	hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	if (FAILED(hr))
		throw hr;

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
		throw error;
	}

	if (flags._value & SWIF::Debug) {
		AllocConsole();
#pragma warning(suppress : 4996)
		freopen("CONOUT$", "w", stdout);
#pragma warning(suppress : 4996)
		freopen("CONIN$", "r", stdin);
	}
}
swm::SWHWND::SWHWND(StampWindowDesc* desc, HINSTANCE hInstance) {
	data = 0;
	if (desc == NULL) return;
	data = new SWHWND_d();
	data->updateWinAttrib._value = 0;
	data->desc = *desc;
	data->borderless = desc->flags._value & SWDF::Borderless;
	data->vSync = desc->flags._value & SWDF::Vsync;
	data->cursorContraint = swm::CursorConstraintState::Free;
	data->hInstance = hInstance;
	data->canUpdateWin = desc->flags._value & SWDF::DynamicAttributes;

	data->managementThread = std::thread{ ManageWindow, this };
}
swm::SWHWND::~SWHWND() {
	delete data;
}