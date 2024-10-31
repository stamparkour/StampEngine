#include "SWM.hpp"
#include <thread>
#include <hidusage.h>
#include <windowsx.h>
#include "eventlistener.hpp"
#include <iostream>
#include "libload.h"


thread_local swm::SWHWND* localWindow = 0;

//#define SWM_ERRORCATCH

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
	EventListener<double> Start_proc{};
	EventListener<double> Update_proc{};
	EventListener<double> SyncUpdate_proc{};
	EventListener<double> Render_proc{};
	EventListener<double, long, long> Resize_proc{};
	EventListener<VertKey> Keydown_proc{};
	EventListener<VertKey> Keyup_proc{};
};
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
static void PauseTimer(swm::SWHWND* win) {
	long long t = getTimeRaw();
	if (win->data->pauseTime != 0) {
		win->data->startTime += t - win->data->pauseTime;
	}
	win->data->pauseTime = t;
}

static bool InternalCursorConstraint(swm::SWHWND* win, swm::CursorConstraintState constraint) {
	RECT rect{};
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
static bool InternalShowCursor(swm::SWHWND* win, bool visible) {
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

static void OnCreate(HWND hwnd, CREATESTRUCT* create) {
	swm::SWHWND* ptr = (swm::SWHWND*)create->lpCreateParams;
	ptr->data->winHandle = hwnd;
	SetWindowLongPtr(hwnd, 0, (LONG_PTR)ptr);
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
	if (wglMakeCurrent(displayContext, glContext) == FALSE) throw std::runtime_error("Wndproc -> OnCreate - failed to opengl context");
	std::cout << "[opengl] max version: " << glGetString(GL_VERSION) << std::endl;
	GLMInit();
	int value;
	glGetIntegerv(GL_STENCIL_BITS, &value);
	wglSwapIntervalEXT(1);
	if (ptr->data->vSync) {
		glDrawBuffer(GL_BACK);
	}
	else {
		glDrawBuffer(GL_FRONT);
	}
	RAWINPUTDEVICE Rid[1]{} ;
	Rid[0].usUsagePage = HID_USAGE_PAGE_GENERIC;
	Rid[0].usUsage = HID_USAGE_GENERIC_MOUSE;
	Rid[0].dwFlags = RIDEV_INPUTSINK;
	Rid[0].hwndTarget = hwnd;
	RegisterRawInputDevices(Rid, 1, sizeof(Rid[0]));

	libload::LibloadInit();
	libload::LoadLibraries(ptr);
	std::cout << "[window] created" << std::endl;
	ptr->data->Start_proc(ptr->getTime());
}

void OnPaint(swm::SWHWND* ptr) {
	HDC hdc = wglGetCurrentDC();
	HGLRC glc = wglGetCurrentContext();
	glStencilMask(0xFF);
	glDepthMask(GL_TRUE);
	glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	ptr->data->Render_proc(ptr->getTime());

	if (ptr->data->vSync) {
		if (!SwapBuffers(hdc)) std::cout << "FAILED SWAP BUFFER!" << std::endl;
	}
	else {
		glFinish();//glFlush();
	}
}

static LRESULT __stdcall Wndproc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
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
		if (data && !(lParam & 0x40000000)) data->Keydown_proc((swm::VertKey)wParam);
		break;
	case WM_KEYUP://https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
	case WM_SYSKEYUP:
		if(data) data->Keyup_proc(swm::VertKey{ (int)wParam });
		break;
	case WM_CREATE:
		OnCreate(hwnd, (CREATESTRUCT*)lParam);
		break;
	case WM_PAINT: {
		static thread_local int count = 0;
		if (++count > 64) {
			OnPaint(ptr);
			count = 0;
		}
	} break;		
	case WM_WINDOWPOSCHANGED: {
		WINDOWPOS* winpos = (WINDOWPOS*)lParam;
		if (!data) break;
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
		data->Resize_proc(ptr->getTime(), winpos->cx, winpos->cy);
		glViewport(0, 0, winpos->cx, winpos->cy);
	} break;
	case WM_ACTIVATE:
		if (data == nullptr) break;
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
		if (data == nullptr) break;
		if (!data->active) {
			InternalCursorConstraint(ptr, data->cursorContraint);
			InternalShowCursor(ptr, data->cursorVisble);
			data->active = true;
		}
		break;
	case WM_INPUT:
		if (data == nullptr) break;
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
		if (data == nullptr) break;
		if (data->active) {
			data->cursorX = GET_X_LPARAM(lParam);
			data->cursorY = GET_Y_LPARAM(lParam);
		}
		break;
	case WM_MOUSEWHEEL:
		if (data == nullptr) break;
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

static void ManageWindow(swm::SWHWND* ptr) {
#ifdef SWM_ERRORCATCH
	try {
#endif

	auto* data = ptr->data;
	localWindow = ptr;
	data->startTime = getTimeRaw();

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
		data->winHandle = CreateWindowExW(0, L"StampWinManager_CLASS", data->desc.name,
			WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_CAPTION | WS_SYSMENU | WS_VISIBLE | WS_SIZEBOX | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
			CW_USEDEFAULT, CW_USEDEFAULT, defaultWidth, defaultHeight, NULL, NULL, data->hInstance, ptr);
	}

	if (data->winHandle == NULL) {
		DWORD error = GetLastError();
		throw std::runtime_error("swm::SWHWND -> ManageWindow - failed to initialize window");
	}
	MSG msg;

	std::cout << "[window] start running loop" << std::endl;
	while (IsWindow(data->winHandle)) {
		for (int i = 0; i < 500 && PeekMessage(&msg, data->winHandle, 0, 0, PM_REMOVE) != 0; i++) {
			if (msg.message == WM_PAINT)
				break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		ptr->data->pauseTime = 0;
		std::thread update{ [data](double time) { 
			data->Update_proc(time);
		} , ptr->getTime() };

		OnPaint(ptr);

		update.join();
		data->SyncUpdate_proc(ptr->getTime());

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
#ifdef SWM_ERRORCATCH
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}
#endif
}

void swm::initializeSWM(HINSTANCE hInstance, SWIF flags = {}) {
	static bool hasInit = false;
	if (hasInit) return;
	hasInit = true;

	delete SWM_struct;
	SWM_struct = new SWM_struct_t();
	SWM_struct->SWHWND_setVsync_proc = [](swm::SWHWND* self, bool v) {
		if (!self->data->canUpdateWin) throw - 1;
		self->data->vSync = v;
		self->data->updateWinAttrib._value |= UpdateWin::vSync;
	};
	SWM_struct->SWHWND_getVsync_proc = [](const swm::SWHWND* self) {
		return self->data->vSync;
	};
	SWM_struct->SWHWND_setBorderless_proc = [](swm::SWHWND* self, bool v) {
		if (!self->data->canUpdateWin) throw - 1;
		self->data->borderless = v;
		self->data->updateWinAttrib._value |= UpdateWin::WindowMode;
	};
	SWM_struct->SWHWND_getBorderless_proc = [](const swm::SWHWND* self) {
		return self->data->borderless;
	};
	SWM_struct->getCursorAbsolutePos_proc = []() -> swm::WinPoint {
		POINT p;
		GetCursorPos(&p);
		swm::WinPoint k{};
		k.x = p.x;
		k.y = p.y;
		return k;
	};
	SWM_struct->SWHWND_getTime_proc = [](const swm::SWHWND* self) -> double {
		return (getTimeRaw() - self->data->startTime) * tickTimeLength;
	};
	SWM_struct->getDesktopResolution_proc = [](int& horizontal, int& vertical) {
		RECT desktop;
		const HWND hDesktop = GetDesktopWindow();
		GetWindowRect(hDesktop, &desktop);
		horizontal = desktop.right;
		vertical = desktop.bottom;
	};
	SWM_struct->isKeyDown_proc = [](VertKey key) -> bool {
		return GetAsyncKeyState((int)key) < 0;
	};
	SWM_struct->isKeyUp_proc = [](VertKey key)-> bool {
		return !swm::isKeyDown(key);
	};
	SWM_struct->SWHWND_getCursorDeltaScroll_proc = [](const swm::SWHWND* self) -> long {
		return self->data->deltaScroll;
	};
	SWM_struct->SWHWND_getCursorDeltaX_proc = [](const swm::SWHWND* self) -> long {
		return self->data->deltaMouseX;
	};
	SWM_struct->SWHWND_getCursorDeltaY_proc = [](const swm::SWHWND* self) -> long {
		return self->data->deltaMouseY;
	};
	SWM_struct->SWHWND_getCursorX_proc = [](const swm::SWHWND* self) -> long {
		return self->data->cursorX;
	};
	SWM_struct->SWHWND_getCursorY_proc = [](const swm::SWHWND* self) -> long {
		return self->data->cursorY;
		};
	SWM_struct->SWHWND_setCursorVisibility_proc = [](swm::SWHWND* self, bool visible) {
		self->data->cursorVisble = visible;
		self->data->updateWinAttrib._value |= UpdateWin::Cursor;
	};
	SWM_struct->SWHWND_getCursorVisibility_proc = [](const swm::SWHWND* self) -> bool {
		return self->data->cursorVisble;
	};
	SWM_struct->SWHWND_setCursorConstraint_proc = [](swm::SWHWND* self, swm::CursorConstraintState state) {
		self->data->cursorContraint = state;
		self->data->updateWinAttrib._value |= UpdateWin::Cursor;
	};
	SWM_struct->SWHWND_getCursorConstraint_proc = [](const swm::SWHWND* self) -> swm::CursorConstraintState {
		return self->data->cursorContraint;
	};
	SWM_struct->SWHWND_terminateWindow_proc = [](swm::SWHWND* self) {
		DestroyWindow(self->data->winHandle);
	};
	SWM_struct->SWHWND_isWindow_proc = [](const swm::SWHWND* self) -> bool {
		return IsWindow(self->data->winHandle);
	};
	SWM_struct->SWHWND_isWindowActive_proc = [](const swm::SWHWND* self) -> bool {
		return self->data->active;
	};
	SWM_struct->SWHWND_sleepUntilWindowTerminate_proc = [](swm::SWHWND* self) {
		if (std::this_thread::get_id() == self->data->managementThread.get_id())
			throw std::runtime_error("swm::SWHWND::sleepUntilWindowTerminate - wrong thread, thread required is not management thread");
		self->data->managementThread.join();
	};
	SWM_struct->SWHWND_processWinEvents_proc = [](swm::SWHWND* self) {
		if (std::this_thread::get_id() != self->data->managementThread.get_id())
			throw std::runtime_error("swm::SWHWND::processWinEvents - wrong thread, thread required is management thread");
		MSG msg;
		while (PeekMessage(&msg, self->data->winHandle, 0, 0, PM_REMOVE) > 0) {
			if (msg.message == WM_PAINT)
				break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	};
	SWM_struct->SWHWND_processWinEvents_proc = [](swm::SWHWND* self) {
		if (std::this_thread::get_id() != self->data->managementThread.get_id())
			throw std::runtime_error("swm::SWHWND::processWinEvents - wrong thread, thread required is management thread");
		MSG msg;
		while (PeekMessage(&msg, self->data->winHandle, 0, 0, PM_REMOVE) > 0) {
			if (msg.message == WM_PAINT)
				break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	};
	SWM_struct->isRenderThread_proc = []() {
		return localWindow != 0;
	};
	SWM_struct->getWindow_proc = []() {
		return localWindow;
	};

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
#pragma warning(suppress : 4996 6031)
		freopen("CONOUT$", "w", stdout);
#pragma warning(suppress : 4996 6031)
		freopen("CONIN$", "r", stdin);
#pragma warning(suppress : 4996 6031)
		freopen("CONOUT$", "w", stderr);
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
	AddListener(desc->winevent);
	data->managementThread = std::thread{ ManageWindow, this };
}
swm::SWHWND::~SWHWND() {
	delete data;
	data = 0;
}

void swm::SWHWND::AddListener(WinEvent& e)
{
	this->data->Start_proc.subscribe(e.Start_proc);
	this->data->Update_proc.subscribe(e.Update_proc);
	this->data->SyncUpdate_proc.subscribe(e.SyncUpdate_proc);
	this->data->Render_proc.subscribe(e.Render_proc);
	this->data->Resize_proc.subscribe(e.Resize_proc);
	this->data->Keydown_proc.subscribe(e.Keydown_proc);
	this->data->Keyup_proc.subscribe(e.Keyup_proc);
}

void swm::checkOpenGLErrors() {
	GLenum error = glGetError();
	while (error != GL_NO_ERROR) {
		// Handle the error appropriately
		std::cout << "OpenGL error: " << error << std::endl;
		error = glGetError();
	}
}