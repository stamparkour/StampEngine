#include "SWM.hpp"
#include <thread>
#include <windowsx.h>

struct UpdateWin {
	enum {
		Cursor = 1,
		vSync = 2,
		WindowMode = 4,
	};
	unsigned int value;
};

struct swm::SWHWND_d {
	std::thread managementThread;
	HWND winHandle;
	swm::StampWindowDesc desc;
	bool initialized;
	bool active;
	bool vSync;
	bool currentCursorVisible;
	bool cursorVisble;
	bool borderless;
	swm::CursorConstraintState cursorContraint;
	bool canUpdateWin;
	UpdateWin updateWinAttrib;
	int deltaMouseX;
	int deltaMouseY;
	int cursorX;
	int cursorY;
	int deltaScroll;
	long long pauseTime;
	long long startTime;
	swm::WinPos winPos;
	HINSTANCE hInstance;
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
}

bool swm::isKeyDown(VertKey key) {
	return GetAsyncKeyState(key.value) < 0;
}
bool swm::isKeyUp(VertKey key) {
	return !swm::isKeyDown(key);
}

void swm::SWHWND::setVsync(bool v) {
	if (!data->canUpdateWin) throw - 1;
	data->vSync = v;
	data->updateWinAttrib.value |= UpdateWin::vSync;
}
bool swm::SWHWND::getVsync() const {
	return data->vSync;
}
void swm::SWHWND::setBorderless(bool v) {
	if (!data->canUpdateWin) throw - 1;
	data->borderless = v;
	data->updateWinAttrib.value |= UpdateWin::WindowMode;
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
	data->updateWinAttrib.value |= UpdateWin::Cursor;
}
bool swm::SWHWND::getCursorVisibility() const {
	return data->cursorVisble;
}
void swm::SWHWND::setCursorConstraint(swm::CursorConstraintState state) {
	data->cursorContraint = state;
	data->updateWinAttrib.value |= UpdateWin::Cursor;
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

LRESULT __stdcall Wndproc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	swm::SWHWND* ptr = (swm::SWHWND*)GetWindowLongPtrW(hwnd, 0);
	switch (msg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		FreeConsole();
		break;
	case WM_KEYDOWN:
	case WM_SYSKEYDOWN:
		ptr->data->desc.winevent.Keydown_proc(swm::VertKey{ (int)wParam });
		break;
	case WM_KEYUP://https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
	case WM_SYSKEYUP:
		ptr->data->desc.winevent.Keyup_proc(swm::VertKey{ (int)wParam });
		break;
	case WM_CREATE:
		OnCreate(hwnd);
		break;
	case WM_PAINT:
		break;
	case WM_WINDOWPOSCHANGED: {
		WINDOWPOS* winpos = (WINDOWPOS*)lParam;
		ptr->data->winPos.width = winpos->cx;
		ptr->data->winPos.height = winpos->cy;
		ptr->data->winPos.left = winpos->x;
		ptr->data->winPos.top = winpos->y;
		if (ptr->data->active || !ptr->data->initialized) {
			InternalCursorConstraint(ptr, ptr->data->cursorContraint);
			InternalShowCursor(ptr, ptr->data->cursorVisble);
			ptr->data->active = true;
		}
		if (!ptr->data->initialized) {
			ptr->data->initialized = true;
		}
		ptr->data->desc.winevent.Resize_proc(ptr->getTime(), winpos->cx, winpos->cy);
		glViewport(0, 0, winpos->cx, winpos->cy);
		PauseTimer(ptr);
	} break;
	case WM_ACTIVATE:
		if (wParam == WA_INACTIVE) {
			ptr->data->active = false;
			InternalShowCursor(ptr,true);
			InternalCursorConstraint(ptr, swm::CursorConstraintState::Free);
			if (ptr->data->borderless) {
				ShowWindow(hwnd, SW_MINIMIZE);
			}
		}
		else if (ptr->data->borderless) {
			InternalCursorConstraint(ptr, ptr->data->cursorContraint);
			InternalShowCursor(ptr, ptr->data->cursorVisble);
			ptr->data->active = true;
		}
		break;
	case WM_LBUTTONDOWN:
		if (!ptr->data->active) {
			InternalCursorConstraint(ptr, ptr->data->cursorContraint);
			InternalShowCursor(ptr, ptr->data->cursorVisble);
			ptr->data->active = true;
		}
		break;
	case WM_INPUT:
		if (ptr->data->active) {
			UINT dwSize = sizeof(RAWINPUT);
			static thread_local BYTE lpb[sizeof(RAWINPUT)];

			GetRawInputData((HRAWINPUT)lParam, RID_INPUT, lpb, &dwSize, sizeof(RAWINPUTHEADER));

			RAWINPUT* raw = (RAWINPUT*)lpb;

			if (raw->header.dwType == RIM_TYPEMOUSE)
			{
				ptr->data->deltaMouseX += raw->data.mouse.lLastX;
				ptr->data->deltaMouseY += raw->data.mouse.lLastY;
			}
		}
		break;
	case WM_MOUSEMOVE:
		if (ptr->data->active) {
			ptr->data->cursorX = GET_X_LPARAM(lParam);
			ptr->data->cursorY = GET_Y_LPARAM(lParam);
		}
		break;
	case WM_MOUSEWHEEL:
		if (ptr->data->active) {
			ptr->data->deltaScroll += GET_WHEEL_DELTA_WPARAM(wParam);
			ptr->data->cursorX = GET_X_LPARAM(lParam);
			ptr->data->cursorY = GET_Y_LPARAM(lParam);
		}
		break;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}

void ManageWindow(swm::SWHWND* ptr) {

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

	WNDCLASSEX windowClass = {
		CS_HREDRAW | CS_VREDRAW | CS_CLASSDC,
		sizeof(WNDCLASSEX),
		Wndproc,
		0,
		0,
		hInstance,
		NULL,//icon
		NULL,//cursor
		NULL,
		NULL,
		L"StampWinManager_CLASS"
	};

	ATOM windowClassAtom = RegisterClassExW(&windowClass);
	if (windowClassAtom == NULL) {
		DWORD error = GetLastError();
		throw error;
	}

	if (flags.value & SWIF::Debug) {
		AllocConsole();
#pragma warning(suppress : 4996)
		freopen("CONOUT$", "w", stdout);
#pragma warning(suppress : 4996)
		freopen("CONIN$", "r", stdin);
	}
}
swm::SWHWND::SWHWND(StampWindowDesc* desc, HINSTANCE hInstance) {
	if (desc == NULL) return;
	data = new SWHWND_d();
	data->updateWinAttrib.value = 0;
	data->desc = *desc;
	data->borderless = desc->flags & SWDF::Borderless;
	data->vSync = desc->flags & SWDF::Vsync;
	data->cursorContraint = swm::CursorConstraintState::Free;
	data->hInstance = hInstance;
	data->canUpdateWin = desc->flags & SWDF::DynamicAttributes;
	HWND hwnd;

	if (data->borderless) {
		int width = CW_USEDEFAULT;
		int height = CW_USEDEFAULT;
		swm::getDesktopResolution(width, height);
		hwnd = CreateWindowExW(WS_EX_TOPMOST, L"StampWinManager_CLASS", data->desc.name, WS_POPUP,
			0, 0, width, height, NULL, NULL, hInstance, NULL);
	}
	else {
		int defaultWidth = CW_USEDEFAULT;
		int defaultHeight = CW_USEDEFAULT;
		hwnd = CreateWindowW(L"StampWinManager_CLASS", data->desc.name,
			WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_CAPTION | WS_SYSMENU | WS_VISIBLE | WS_SIZEBOX | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
			CW_USEDEFAULT, CW_USEDEFAULT, defaultWidth, defaultHeight, NULL, NULL, hInstance, NULL);
	}

	swm::SWHWND* ptr = (swm::SWHWND*)GetWindowLongPtrW(hwnd, 0);
	ptr = this;

	data->managementThread = std::thread{ ManageWindow, this };
}
swm::SWHWND::~SWHWND() {
	delete data;
}