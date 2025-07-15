module;

#include <windows.h>
#include <windowsx.h>
#include <hidusage.h>
#include <xaudio2.h>
#include "debug.h"
#include "glm.h"

export module winmanager;

import std;
import math;

LRESULT Wndproc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
constexpr auto WIN_CLASS_NAME = "STAMPENGINE_WINCLASS";
export namespace wm {
	class Window;
	
	class Timer {
		static inline double tickTimeLength = []() -> double {
			LARGE_INTEGER largeInt{};
			QueryPerformanceFrequency(&largeInt);
			return 1.0 / largeInt.QuadPart;
		}();
	public:
		static double TimeTickLength() {
			return tickTimeLength;
		}
		static long long getTimeRaw() {
			LARGE_INTEGER largeInt{};
			QueryPerformanceCounter(&largeInt);
			return (largeInt.QuadPart);
		}
		static double getTime() {
			return getTimeRaw() * tickTimeLength;
		}
	};

	enum struct VertKey {
		None = 0,
		LeftMouse = 0x01,
		RightMouse = 0x02,
		MiddleMouse = 0x04,
		X1Mouse = 0x05,
		X2Mouse = 0x06,
		Backspace = 0x08,
		Tab = 0x09,
		Enter = 0x0D,
		Shift = 0x10,
		Control = 0x11,
		Alt = 0x12,
		Capslock = 0x14,
		Escape = 0x1b,
		Space = 0x20,
		PageUp = 0x21,
		PageDown = 0x22,
		End = 0x23,
		Home = 0x24,
		LeftArrow = 0x25,
		UpArrow = 0x26,
		RightArrow = 0x27,
		DownArrow = 0x28,
		Select = 0x29,
		Print = 0x2a,
		PrintScreen = 0x2c,
		Insert = 0x2d,
		Delete = 0x2e,
		Help = 0x2f,
		Zero = '0',
		One = '1',
		Two = '2',
		Three = '3',
		Four = '4',
		Five = '5',
		Six = '6',
		Seven = '7',
		Eight = '8',
		Nine = '9',
		A = 'A',
		B = 'B',
		C = 'C',
		D = 'D',
		E = 'E',
		F = 'F',
		G = 'G',
		H = 'H',
		I = 'I',
		J = 'J',
		K = 'K',
		L = 'L',
		M = 'M',
		N = 'N',
		O = 'O',
		P = 'P',
		Q = 'Q',
		R = 'R',
		S = 'S',
		T = 'T',
		U = 'U',
		V = 'V',
		W = 'W',
		X = 'X',
		Y = 'Y',
		Z = 'Z',
		LeftWindowsKey = 0x5B,
		RightWindowsKey = 0x5C,
		NumpadZero = 0x60,
		NumpadOne = 0x61,
		NumpadTwo = 0x62,
		NumpadThree = 0x63,
		NumpadFour = 0x64,
		NumpadFive = 0x65,
		NumpadSix = 0x66,
		NumpadSeven = 0x67,
		NumpadEight = 0x68,
		NumpadNine = 0x69,
		Multiply = 0x6a,
		Add = 0x6b,
		Subtract = 0x6c,
		Decimal = 0x6e,
		Divide = 0x6f,
		F1 = 0x70,
		F2 = 0x71,
		F3 = 0x72,
		F4 = 0x73,
		F5 = 0x74,
		F6 = 0x75,
		F7 = 0x76,
		F8 = 0x77,
		F9 = 0x78,
		F10 = 0x79,
		F11 = 0x7a,
		F12 = 0x7b,
		F13 = 0x7c,
		F14 = 0x7d,
		F15 = 0x7e,
		F16 = 0x7f,
		Numlock = 0x90,
		ScrollLock = 0x91,
		OEM_Comma = 0xbc,
		OEM_Period = 0xbe,
	};

	enum struct MouseButton {
		None = 0,
		LeftMouse = 0x01,
		RightMouse = 0x02,
		MiddleMouse = 0x04,
		X1Mouse = 0x05,
		X2Mouse = 0x06,
	};

	enum struct ShowWindowState {
		Borderless = -1,
		Maximize = SW_MAXIMIZE,
		Minimize = SW_MINIMIZE,
		Restore = SW_RESTORE,
		Focus = SW_SHOW,
		Unfocus = SW_SHOWNA,
		Default = CW_DEFAULT,
	};
	enum struct ConstrainCursorState {
		Free,
		Constrained,
		Freeze,
	};

	struct Rect {
		int x, y, width, height;
	};
	struct RectF {
		float x, y, width, height;
	};

	/*template <typename T>
	class SharedX : public std::enable_shared_from_this<T> {
	public:
		template<typename... P>
		static std::shared_ptr<T> Instantiate(P... var) {
			T* t = new T(var);
		}
	};*/

	class RawSceneBase : public std::enable_shared_from_this<RawSceneBase> {
		friend class Window;
		class Window* window = 0;
		GLuint framebuffer = 0;
		int colorAttachmentIndex = 0;
		int colorAttachmentWidth = 0;
		int colorAttachmentHeight = 0;
	protected:
		RawSceneBase(Window* window) {
			this->window = window;
		}

		virtual void Start() = 0;
		virtual void End() = 0;
		virtual void Update() = 0;
		virtual void SyncUpdate() = 0;
		virtual void Render();
		virtual void Resize(long width, long height) = 0;
	public:
		class Window* Window() {
			return window;
		}

		void SetFramebuffer(GLuint framebuffer, int width, int height, int colorAttachmentIndex = 0);

		virtual ~RawSceneBase() {}
	};

	//joystick etc
	class PeripheralDevice : public std::enable_shared_from_this<PeripheralDevice>{
		friend Window;
	protected:
		PeripheralDevice(Window* window);

		Window* window = 0;
		HANDLE device = 0;
		virtual void Input(RAWINPUT* input) = 0;
		virtual void InputDeviceChange(RAWINPUT* input) = 0;
		virtual void SyncUpdate() = 0;

		bool isValid() {
			return false;
		}

		bool isDevice(HANDLE h);

	public:
		virtual ~PeripheralDevice();
	}; 

	class Keyboard : public std::enable_shared_from_this<Keyboard> {
	public:
	private:
		friend class Window;
		friend class Mouse;
		friend class Controls;
		friend LRESULT(::Wndproc)(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

		class Window* window = 0;
		std::bitset<256> scancode;
		std::bitset<256> prevScancode;
		std::bitset<256> vertKeys;
		std::bitset<256> prevVertKeys;

		int index = 0;
		int prevIndex = 0;
		char buffer[256];
		int utfLen = 0;

		Keyboard() {}
		Keyboard(class Window* window) : window(window) {}

		void onChar(uint16_t value, uint32_t flags) {
			if (utfLen == 3) { // 3 byte code - 1110xxxx 10xxxxxx 10xxxxxx
				buffer[index++] = value & 0xFF;
				if (index >= sizeof(buffer)) index = 0;
				utfLen = 0;
				return;
			} else if (utfLen == 4) { // 4 byte code - 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
				buffer[index++] = value & 0xFF;
				if (index >= sizeof(buffer)) index = 0;
				buffer[index++] = (value >> 8) & 0xFF;
				if (index >= sizeof(buffer)) index = 0;
				utfLen = 0;
				return;
			}

			if ((value & 0x80) == 0) utfLen = 1;
			else if ((value & 0x20) == 0) utfLen = 2;
			else if ((value & 0x10) == 0) utfLen = 3;
			else if ((value & 0x08) == 0) utfLen = 4;

			buffer[index++] = value & 0xFF;
			if (index >= sizeof(buffer)) index = 0;
			if (utfLen > 1) {
				buffer[index++] = (value >> 8) & 0xFF;
				if (index >= sizeof(buffer)) index = 0;
			}
			if (utfLen <= 2) utfLen = 0;
			
		}
		void onKeyDown(VertKey key, int scancode, uint32_t flags) {
			this->vertKeys[(int)key] = true;
			this->scancode[scancode] = true;
		}
		void onKeyUp(VertKey key, int scancode, uint32_t flags) {
			this->vertKeys[(int)key] = false;
			this->scancode[scancode] = false;
		}

		void SyncUpdate() {
			prevScancode = scancode;
			prevVertKeys = vertKeys;
		}
	public:
		bool isKeyDown(VertKey key) const {
			return vertKeys[(int)key];
		}
		bool isKeyUp(VertKey key) const {
			return !vertKeys[(int)key];
		}
		bool isKeyPress(VertKey key) const {
			return vertKeys[(int)key] && !prevVertKeys[(int)key];
		}
		bool isKeyRelease(VertKey key) const {
			return !vertKeys[(int)key] && prevVertKeys[(int)key];
		}
		bool isKeyDown(int scanCode) const {
			return scancode[scanCode];
		}
		bool isKeyUp(int scanCode) const {
			return !scancode[scanCode];
		}
		bool isKeyPress(int scanCode) const {
			return scancode[scanCode] && !prevScancode[scanCode];
		}
		bool isKeyRelease(int scanCode) const {
			return !scancode[scanCode] && prevScancode[scanCode];
		}
		int popBuffer(char* buffer, int length) {
			if (buffer == NULL) return (index - prevIndex) % sizeof(this->buffer);
			if (prevIndex == index) return 0;
			int i;
			for (i = 0; i < length - 1; i++) {
				buffer[i] = this->buffer[prevIndex++];
				if (prevIndex >= sizeof(this->buffer)) prevIndex = 0;
				if (prevIndex == index) break;
			}

			buffer[i + 1] = 0;
			return i + 2;
		}
	};

	class Mouse {
		friend Window;
		friend class Controls;
		friend LRESULT(::Wndproc)(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

		Window* window = 0;
		math::Vec2d gamePos = { 0,0 };
		math::Vec2d gameNextPos = { 0,0 };
		math::Vec2i screenPos = { 0,0 };
		math::Vec2i screenNextPos = { 0,0 };
		math::Vec2d rawVelocity = { 0,0 };
		math::Vec2d gameVelocity = { 0,0 };
		math::Vec2i screenVelocity = { 0,0 };
		math::Vec2d nextRawVelocity = { 0,0 };
		math::Vec2d scrollVelocity = { 0,0 };
		double sensitivity = 1.0f;
		double scrollSenitivity = 1.0f;
		bool isShown = true;
		bool currentlyShown = true;
		
		std::bitset<6> mouseButtons;
		std::bitset<6> prevMouseButtons;

		ConstrainCursorState constrainState = ConstrainCursorState::Free;
		ConstrainCursorState prevConstrainState = ConstrainCursorState::Free;
		Mouse() {}
		Mouse(Window* window);
		
		void Input(RAWINPUT* input);
		void MouseMove(int x, int y);
		void SyncUpdate();

		void InternalShowCursor(bool visible) {
			if (currentlyShown && !visible) {
				currentlyShown = false;
				ShowCursor(FALSE);
			}
			else if (!currentlyShown && visible) {
				currentlyShown = true;
				ShowCursor(TRUE);
			}
		}
		void InternalConstrainCursor(ConstrainCursorState state);

	public:
		bool isKeyDown(MouseButton key) const {
			return mouseButtons[(int)key];
		}
		bool isKeyUp(MouseButton key) const {
			return !mouseButtons[(int)key];
		}
		bool isKeyPress(MouseButton key) const {
			return mouseButtons[(int)key] && !prevMouseButtons[(int)key];
		}
		bool isKeyRelease(MouseButton key) const {
			return !mouseButtons[(int)key] && prevMouseButtons[(int)key];
		}
		/// <summary>
		/// 
		/// </summary>
		/// <returns>current position of cursor in normalized game space</returns>
		math::Vec2d GetGameSpacePosition() const {
			return gamePos;
		}
		/// <summary>
		/// 
		/// </summary>
		/// <returns>current position of cursor in window's screen space</returns>
		math::Vec2i GetScreenSpacePosition() const {
			return screenPos;
		}
		/// <summary>
		/// alias for <see cref="GetGameSpacePosition()"/>
		/// </summary>
		/// <returns>current position of cursor in normalized game space</returns>
		math::Vec2d GetPosition() const {
			return GetGameSpacePosition();
		}
		/// <summary>
		/// 
		/// </summary>
		/// <returns>current screen space velocity of the mouse</returns>
		math::Vec2d GetGameSpaceVelocity() const {
			return gameVelocity;
		}
		/// <summary>
		/// 
		/// </summary>
		/// <returns>current screen space velocity of the mouse</returns>
		math::Vec2i GetScreenSpaceVelocity() const {
			return screenVelocity;
		}
		/// <summary>
		/// 
		/// </summary>
		/// <returns>current raw input velocity of the mouse</returns>
		math::Vec2d GetInputVelocity() const {
			return rawVelocity;
		}
		/// <summary>
		/// alias for <see cref="GetInputVelocity()"/>
		/// </summary>
		/// <returns>current raw input velocity of the mouse</returns>
		math::Vec2d GetVelocity() const {
			return GetInputVelocity();
		}
		/// <summary>
		/// 
		/// </summary>
		/// <param name="sensitivity"> - multiplier for <see cref="GetInputVelocity()"/></param>
		void setSensitivity(double sensitivity) {
			this->sensitivity = sensitivity;
		}
		/// <summary>
		/// 
		/// </summary>
		/// <param name="sensitivity"> - multiplier for <see cref="GetInputVelocity()"/></param>
		void setScrollSensitivity(double sensitivity) {
			this->scrollSenitivity = sensitivity;
		}

		/// <summary>
		/// sets the visibility of the cursor.
		/// </summary>
		/// <param name="show">- true if the mouse is visible</param>
		void Visibility(bool show) {
			isShown = show;
		}

		void ConstrainCursor(ConstrainCursorState state);
	};

	class Controls : public std::enable_shared_from_this<Controls> {
		friend Window;
	public:
		static const size_t MAX_ACTIONS = 512;
		struct InputAction {
			VertKey key;
			bool ignoreMod;
			bool shift;
			bool control;
			bool alt;
		};
	private:
		class Window* window = 0;
		InputAction actions[MAX_ACTIONS];
		Controls() {}
		Controls(Window* window) {
			this->window = window;
		}
	public:
		void BindAction(int index, InputAction& action) {
			if (index < 0 || index >= MAX_ACTIONS) return;
			actions[index] = action;
		}

		bool isActionDown(int index) const;
		bool isActionUp(int index) const;
		bool isActionPress(int index) const;
		bool isActionRelease(int index) const;
	};

	class AudioManager final : public std::enable_shared_from_this<AudioManager> {
		friend class Window;
		Window* window;
		AudioManager() = default;
		AudioManager(Window* window) : window(window){ 
			IXAudio2* m_xAudio2{};
			::XAudio2Create(&m_xAudio2, 0, XAUDIO2_DEFAULT_PROCESSOR);
		}
	public:



		~AudioManager() {

		}
	};

	struct WindowConstruct {

	};

	class Window : public std::enable_shared_from_this<Window> {
		friend class PeripheralDevice;
		friend LRESULT(::Wndproc)(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

		static inline thread_local Window* currentThreadWindow = 0;

		std::vector<std::shared_ptr<PeripheralDevice>> devices{};
		HWND hwnd = 0;
		HGLRC glContext;
		int clientX = 0;
		int clientY = 0;
		int clientWidth = 0;
		int clientHeight = 0;
		int windowX = 0;
		int windowY = 0;
		int windowWidth = 0;
		int windowHeight = 0;
		int maxWindowWidth = 16384;
		int maxWindowHeight = 16384;
		int minWindowWidth = 160;
		int minWindowHeight = 40;
		bool active = false;
		bool exsists = true;
		bool initialized = false;
		bool sync = true;
		int executeCount = 0;
		float gameRatio = 1;
		float clientRatio = 0;
		bool fullscreen = false;
		long long creationTime = 0;
		double deltaTime = 0;
		GLint initFBO = -1;
		float timeScale = 1;
		bool vsync = false;

		Keyboard keyboard{};
		Mouse mouse{};
		Controls controls{};
		AudioManager audioManager{};

		std::shared_ptr<RawSceneBase> scene = nullptr;
		std::shared_ptr<RawSceneBase> (*sceneInstantiate)(Window* window) = 0;

		std::mutex closeMutex{};
		std::condition_variable closeCV{};
		std::mutex initializeMutex{};
		std::condition_variable initializeCV{};
		std::thread::id controlThreadID;
		std::string title;

		static inline Window* activeWindow = 0;

		bool Create(HWND hwnd, CREATESTRUCT* createStruct) {
			this->hwnd = hwnd;

			HRESULT hr = ::CoInitializeEx(nullptr, COINIT_MULTITHREADED);
			if (FAILED(hr)) return hr;

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
				return false;
			glContext = wglCreateContext(displayContext);
			if (!wglMakeCurrent(displayContext, glContext)) {
				STAMPSTACK();
				STAMPDMSG("Wndproc -> OnCreate - failed to opengl context");
			}
			std::cout << "[opengl] max version: " << glGetString(GL_VERSION) << std::endl;
			GLMInit();
			//int value;
			//glGetIntegerv(GL_STENCIL_BITS, &value);
			wglSwapIntervalEXT(1);

			exsists = true;

			if (initFBO == -1) glGetIntegerv(GL_FRAMEBUFFER_BINDING, &initFBO);

			keyboard = { this };
			mouse = { this };
			controls = { this };
			audioManager = { this };
			return exsists;
		}
		bool Close() {
			return true;
		}
		void PositionChanged(WINDOWPOS* pos, Rect* client) {
			if (!(pos->flags & SWP_NOSIZE) || !initialized) { //1
				this->clientWidth = client->width;
				this->clientHeight = client->height;
				this->windowWidth = pos->cx;
				this->windowHeight = pos->cy;

				clientRatio = (float)clientWidth / clientHeight;
			}
			if (!(pos->flags & SWP_NOMOVE) || !initialized) { //2
				this->windowX = pos->x;
				this->windowY = pos->y;
				this->clientX = client->x;
				this->clientY = client->y;
			}
		}
		void Active(int active, int showWindowState) {
			this->active = active;
			if (active) activeWindow = this;
			if (fullscreen) {
				if (active) {
					SetWindowState(ShowWindowState::Borderless);
				}
				else {
					SetWindowState(ShowWindowState::Minimize);
				}
			}
		}
		void Input(HRAWINPUT hinput) {
			RAWINPUT input;
			UINT dwSize = sizeof(input);
			GetRawInputData(hinput, RID_INPUT, &input, &dwSize, sizeof(RAWINPUTHEADER));
			mouse.Input(&input);
			for (int i = 0; i < devices.size(); i++) {
				devices[i]->Input(&input);
			}
		}

		void Control() {
			HWND win = CreateWindowExA(
				0, //styleEX
				WIN_CLASS_NAME, //window class
				(const char*)title.c_str(), //class title
				WS_OVERLAPPEDWINDOW, //style
				CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, // X, Y, width, height
				NULL, //window parent
				NULL, //hmenu
				GetModuleHandle(nullptr), //hinstance
				this //create pointer
			);
			STAMPERROR(win == 0, "wm::Window::Window - create class failed");
			currentThreadWindow = this;
			creationTime = Timer::getTimeRaw();
			MSG msg;
			std::thread updateThread = std::thread{ &Window::Update, this };

			//filter out all necessary messages
			while (PeekMessageA(&msg, hwnd, 0, 0, PM_REMOVE) != 0) {
				if (msg.message == WM_PAINT)
					break;
				TranslateMessage(&msg);
				DispatchMessageA(&msg);
			}

			HDC hdc = GetDC(hwnd);
			wglMakeCurrent(hdc, glContext);
			SetWindowState(wm::ShowWindowState::Focus);

			long long prevTime = Timer::getTimeRaw();
			while (exsists) {

				//sync
				long long t = Timer::getTimeRaw();
				deltaTime = (t - prevTime) * Timer::TimeTickLength();
				prevTime = t;

				if (sceneInstantiate) {
					if (scene) {
						scene->End();
					}
					scene = sceneInstantiate(this);
					sceneInstantiate = 0;
					scene->Start();
				}

				if (scene) scene->SyncUpdate();
				mouse.SyncUpdate();
				keyboard.SyncUpdate();
				for (int i = 0; i < devices.size(); i++) {
					devices[i]->SyncUpdate();
				}
				if (sceneInstantiate) continue;
				
				//parallel
                std::thread update(&Window::Update, this);

				for (int i = 0; PeekMessageA(&msg, hwnd, 0, 0, PM_REMOVE) != 0 && i < 128; i++) {
					if (msg.message == WM_PAINT)
						break;
					TranslateMessage(&msg);
					DispatchMessageA(&msg);
				}
				if (!exsists) break;

				//render
				if (scene) scene->Render();
				glFlush();
				if (vsync) SwapBuffers(hdc);

				update.join();
			}

		}
		void Update() {
			currentThreadWindow = this;
			// double t = Timer::getTime();
			if (scene) scene->Update();
		}

		void AwaitInitialize() {
			std::unique_lock lk(initializeMutex);
			initializeCV.wait(lk, [this] { return initialized; });
		}
	public:
		Window(std::string title, WindowConstruct* construct = nullptr);

		Window(Window&) = delete;
		Window& operator = (Window&) = delete;

		void SetGameRatio(float ratio) { 
			gameRatio = ratio;
		}
		void SetGameRatioOptimal() {
			gameRatio = (float)clientWidth / clientHeight;
		}
		void SetClientSize(int width, int height, bool shouldMoveWindow = true) {
			RECT desktop;
			const HWND hDesktop = GetDesktopWindow();
			GetWindowRect(hDesktop, &desktop);
			width += windowWidth - clientWidth;
			height += windowHeight - clientHeight;
			if (width > desktop.right - desktop.left) width = desktop.right - desktop.left;
			if (height > desktop.bottom - desktop.top) height = desktop.bottom - desktop.top;
			int x = desktop.right / 2 - width / 2;
			int y = desktop.bottom / 2 - height / 2;
			ShowWindow(hwnd, SW_RESTORE);
			SetWindowPos(hwnd, HWND_TOP, x, y, width, height, shouldMoveWindow ? 0 : SWP_NOMOVE);
			fullscreen = false;
		}
		void SetPosition(int x, int y) {
			SetWindowPos(hwnd, HWND_TOP, x, y, 0, 0, SWP_NOSIZE);
		}
		void SetMinSize(int width, int height) {
			minWindowWidth = width + windowWidth - clientWidth;
			minWindowHeight = height + windowHeight - clientHeight;
		}
		void SetMaxSize(int width, int height) {
			maxWindowWidth = width + windowWidth - clientWidth;
			maxWindowHeight = height + windowHeight - clientHeight;
		}
		void SetTimeScale(float scale) {
			creationTime = Timer::getTimeRaw() - (Timer::getTimeRaw() - creationTime) * timeScale / scale;
			timeScale = scale;
		}
		float GetTimeScale() {
			return timeScale;
		}
		void SetVSync(bool vsync) {
			this->vsync = vsync;
		}
		GLenum GetRenderTarget() {
			return vsync ? GL_BACK_LEFT : GL_FRONT_LEFT;
		}

		void SetWindowName(std::string name) {
			this->title = name;
			SetWindowTextA(hwnd, (const char*)title.c_str());
		}

		/// <summary>
		/// 
		/// </summary>
		/// <returns>gets the rect for the game space in screen space</returns>
		Rect GetGameScreenSpaceRect() {
			Rect r = GetGameRect();
			r.x += clientX;
			r.y += clientY;
			return r;
		}
		/// <summary>
		/// 
		/// </summary>
		/// <returns>gets the rect for the game space in client space</returns>
		Rect GetGameRect() {
			Rect r;
			
			if (gameRatio == clientRatio) {
				r.y = r.x = 0;
				r.width = clientWidth;
				r.height = clientHeight;
			}
			else if (gameRatio < clientRatio) {
				r.y = 0;
				r.height = clientHeight;
				r.width = (int)(clientHeight * gameRatio);
				r.x = (clientWidth - r.width) / 2;
			}
			else {
				r.x = 0;
				r.width = clientWidth;
				r.height = (int)(clientWidth / gameRatio);
				r.y = (clientHeight - r.height) / 2;
			}

			return r;
		}
		RectF GetNormalizedGameRect() {
			Rect r = GetGameRect();
			RectF l{};
			l.x = (float)r.x / clientWidth * 2 - 1;
			l.y = (float)r.y / clientHeight * 2 - 1;
			l.width = (float)r.width / clientWidth * 2 - 1;
			l.height = (float)r.height / clientHeight * 2 - 1;
			return l;
		}
		/// <summary>
		/// 
		/// </summary>
		/// <returns>gets the rect for the client space in screen space</returns>
		Rect GetClientRect() {
			Rect r{};
			r.x = clientX;
			r.x = clientY;
			r.width = clientWidth;
			r.height = clientHeight;
			return r;
		}

		void SetWindowState(ShowWindowState state) {
			if (state == ShowWindowState::Borderless) {
				RECT desktop;
				const HWND hDesktop = GetDesktopWindow();
				GetWindowRect(hDesktop, &desktop);
				int width = desktop.right + windowWidth - clientWidth;
				int height = desktop.bottom + windowHeight - clientHeight;
				int x = windowX-clientX;
				int y = windowY - clientY;
				SetWindowPos(hwnd, HWND_TOPMOST, x, y, width, height, 0);
				fullscreen = true;
				ShowWindow(hwnd, SW_SHOW);
			}
			else ShowWindow(hwnd, (int)state);
		}
		void Resizable(bool resizable) {}


		void AwaitClose() {
			std::unique_lock lk(closeMutex);
			closeCV.wait(lk, [this] { return !exsists; });
		}

		template<typename SCENE>
		void SetScene() {
			sceneInstantiate = [](wm::Window* window) -> std::shared_ptr<RawSceneBase> {
				auto k = std::make_shared<SCENE>(window);
				return (std::shared_ptr<RawSceneBase>)k;
			};
		}
		/// <summary>
		/// 
		/// </summary>
		/// <returns>time since window creation</returns>
		double Time() {
			return (Timer::getTimeRaw() - creationTime) * Timer::TimeTickLength() * timeScale;
		}
		double DeltaTime() {
			return deltaTime * timeScale;
		}

		GLuint GetInitialFramebuffer() {
			return initFBO;
		}
		HWND GetWindowHandle() {
			return hwnd;
		}
		Keyboard* Keyboard() {
			return &keyboard;
		}
		Mouse* Mouse() {
			return &mouse;
		}
		Controls* Controls() {
			return &controls;
		}

		bool isControlThread() {
            return std::this_thread::get_id() == controlThreadID;
		}
		bool isActive() {
			return active;
		}
		bool isExsists() {
			return exsists;
		}

		operator bool() { return isExsists(); }
		bool operator !() { return !isExsists(); }

		void Destroy() {
			if (exsists) {
				std::unique_lock lk(closeMutex);
				exsists = false;
				if (scene) {
					scene->End();
					scene.reset();
				}
				closeCV.notify_all();
				PostQuitMessage(0);
			}
		}

		~Window() {
			Destroy();
		}

		friend Window* CurrentWindow();
	};

	Window* CurrentWindow() {
		return Window::currentThreadWindow;
	}

	bool checkOpenGLErrors() {
		GLenum error = glGetError();
		bool k = false;
		while (error != GL_NO_ERROR) {
			k = true;
			// Handle the error appropriately
			std::cout << "OpenGL error: (" << error << ") ";
			switch (error) {
			case GL_INVALID_ENUM:
				std::cout << "invalid enum";
				break;
			case GL_INVALID_VALUE:
				std::cout << "invalid value";
				break;
			case GL_INVALID_OPERATION:
				std::cout << "invalid operation";
				break;
			case GL_STACK_OVERFLOW:
				std::cout << "stack overflow";
				break;
			case GL_STACK_UNDERFLOW:
				std::cout << "stack underflow";
				break;
			case GL_OUT_OF_MEMORY:
				std::cout << "out of memory";
				break;
			case GL_INVALID_FRAMEBUFFER_OPERATION:
				std::cout << "invalid framebuffer operation";
				break;
			case GL_CONTEXT_LOST:
				std::cout << "context lost";
				break;
			case GL_TABLE_TOO_LARGE:
				std::cout << "table too large";
				break;
			}
			std::cout << std::endl;
			error = glGetError();
		}
		return k;
	}
}

LRESULT Wndproc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
	wm::Window* window = (wm::Window*)GetWindowLongPtrA(hwnd, 0);
	//std::cout << window << ": " << msg << std::endl;
	switch (msg) {
	case WM_CREATE:
		SetWindowLongPtrA(hwnd, 0, (long long)((CREATESTRUCT*)lparam)->lpCreateParams);
		window = (wm::Window*)((CREATESTRUCT*)lparam)->lpCreateParams;
		return window->Create(hwnd, (CREATESTRUCT*)lparam) ? 0 : -1;
	case WM_DESTROY:
		if (window) window->Destroy();
		//PostQuitMessage(0);
		return 0;
	case WM_CLOSE:
		if (!window || window->Close()) DestroyWindow(hwnd);
		return 0;
	case WM_KEYDOWN:
	case WM_SYSKEYDOWN:
		if (window && window->active) window->keyboard.onKeyDown((wm::VertKey)wparam, (lparam >> 16) & 0xFF, lparam);
		return 0;
	case WM_KEYUP:
	case WM_SYSKEYUP:
		if (window && window->active) window->keyboard.onKeyUp((wm::VertKey)wparam, (lparam >> 16) & 0xFF, lparam);
		return 0;
	case WM_CHAR:
		if (window && window->active) window->keyboard.onChar(wparam, lparam);
		return 0;
	case WM_NCMOUSEMOVE: {
		int xPos = GET_X_LPARAM(lparam) - window->windowX;
		int yPos = GET_Y_LPARAM(lparam) - (window->windowY + (window->windowHeight - window->clientHeight));
		if (window && window->active) window->mouse.MouseMove(xPos, yPos);
	} return 0;
	case WM_MOUSEMOVE: {
		int xPos = GET_X_LPARAM(lparam);
		int yPos = GET_Y_LPARAM(lparam);
		if (window && window->active) window->mouse.MouseMove(xPos, yPos);
	} return 0;
	case WM_INPUT:
		if (GET_RAWINPUT_CODE_WPARAM(wparam) == RIM_INPUTSINK) return 0;
		if (wm::Window::activeWindow && wm::Window::activeWindow->active) wm::Window::activeWindow->Input((HRAWINPUT)lparam);
		return 0;
	case WM_ACTIVATE:
		if (window) window->Active(LOWORD(wparam),HIWORD(wparam));
		return 0;
	case WM_GETMINMAXINFO: {
		MINMAXINFO* minmax = (MINMAXINFO*)lparam;
		if (!window || window->fullscreen) {
			minmax->ptMaxTrackSize.x = 16384;
			minmax->ptMaxTrackSize.y = 16384;
		}
		else {
			minmax->ptMaxTrackSize.x = window->maxWindowWidth;
			minmax->ptMaxTrackSize.y = window->maxWindowHeight;
			minmax->ptMinTrackSize.x = window->minWindowWidth;
			minmax->ptMinTrackSize.y = window->minWindowHeight;
		}
	} return 0;
	case WM_WINDOWPOSCHANGED: {
		if (!window) return 0;
		WINDOWPOS* pos = (WINDOWPOS*)lparam;
		RECT client;
		GetClientRect(hwnd, &client);
		POINT a { client.left, client.top };
		POINT b { client.right, client.bottom };
		ClientToScreen(hwnd, &a);
		ClientToScreen(hwnd, &b);
		wm::Rect r = { a.x, a.y, b.x - a.x, b.y - a.y };
		window->PositionChanged(pos, &r);
		{
			std::lock_guard lk(window->initializeMutex);
			window->initialized = true;
		}
		window->initializeCV.notify_all();
	} return 0;
	}

	return DefWindowProcA(hwnd, msg, wparam, lparam);
}

wm::PeripheralDevice::PeripheralDevice(class Window* window) {
	this->window = window;
	window->devices.push_back(this->shared_from_this());
}

bool wm::PeripheralDevice::isDevice(HANDLE h) {
	if (device != 0) return device == h;
	for (int i = 0; i < window->devices.size(); i++) {
		if (window->devices[i]->device == h) return false;
	}
	device = h;
	return true;
}

wm::PeripheralDevice::~PeripheralDevice() {
	if (window) {
		auto it = std::find(window->devices.begin(), window->devices.end(), this->shared_from_this());
		if (it != window->devices.end()) window->devices.erase(it);
	}
}

wm::Mouse::Mouse(wm::Window* window) {
	this->window = window;
	RAWINPUTDEVICE devices[1];
	devices[0].usUsagePage = HID_USAGE_PAGE_GENERIC;
	devices[0].usUsage = HID_USAGE_GENERIC_MOUSE;
	devices[0].dwFlags = RIDEV_DEVNOTIFY;
	devices[0].hwndTarget = window->GetWindowHandle();
	RegisterRawInputDevices(devices, 1, sizeof(RAWINPUTDEVICE));
}

void wm::Mouse::Input(RAWINPUT* input) {
	if (input->header.dwType != RIM_TYPEMOUSE) return;
	RAWMOUSE* mouse = &input->data.mouse;
	if (mouse->usFlags & MOUSE_MOVE_ABSOLUTE) {
		//abs mouse
		STAMPDMSG("Mouse - absolute mouse movement not implemented");
	}
	else {
		nextRawVelocity += { (double)mouse->lLastX, (double)mouse->lLastY };
	}

	//mouse input
	if (mouse->usButtonFlags & RI_MOUSE_LEFT_BUTTON_DOWN) {
		window->Keyboard()->vertKeys[(int)wm::VertKey::LeftMouse] = true;
		mouseButtons[(int)wm::MouseButton::LeftMouse] = true;
	}
	if (mouse->usButtonFlags & RI_MOUSE_LEFT_BUTTON_UP) {
		window->Keyboard()->vertKeys[(int)wm::VertKey::LeftMouse] = false;
		mouseButtons[(int)wm::MouseButton::LeftMouse] = false;
	}
	if (mouse->usButtonFlags & RI_MOUSE_RIGHT_BUTTON_DOWN) {
		window->Keyboard()->vertKeys[(int)wm::VertKey::RightMouse] = true;
		mouseButtons[(int)wm::MouseButton::RightMouse] = true;
	}
	if (mouse->usButtonFlags & RI_MOUSE_RIGHT_BUTTON_UP) {
		window->Keyboard()->vertKeys[(int)wm::VertKey::RightMouse] = false;
		mouseButtons[(int)wm::MouseButton::RightMouse] = false;
	}
	if (mouse->usButtonFlags & RI_MOUSE_MIDDLE_BUTTON_DOWN) {
		window->Keyboard()->vertKeys[(int)wm::VertKey::MiddleMouse] = true;
		mouseButtons[(int)wm::MouseButton::MiddleMouse] = true;
	}
	if (mouse->usButtonFlags & RI_MOUSE_MIDDLE_BUTTON_UP) {
		window->Keyboard()->vertKeys[(int)wm::VertKey::MiddleMouse] = false;
		mouseButtons[(int)wm::MouseButton::MiddleMouse] = false;
	}
	if (mouse->usButtonFlags & RI_MOUSE_BUTTON_4_DOWN) {
		window->Keyboard()->vertKeys[(int)wm::VertKey::X1Mouse] = true;
		mouseButtons[(int)wm::MouseButton::X1Mouse] = true;
	}
	if (mouse->usButtonFlags & RI_MOUSE_BUTTON_4_UP) {
		window->Keyboard()->vertKeys[(int)wm::VertKey::X1Mouse] = false;
		mouseButtons[(int)wm::MouseButton::X1Mouse] = false;
	}
	if (mouse->usButtonFlags & RI_MOUSE_BUTTON_5_DOWN) {
		window->Keyboard()->vertKeys[(int)wm::VertKey::X2Mouse] = true;
		mouseButtons[(int)wm::MouseButton::X2Mouse] = true;
	}
	if (mouse->usButtonFlags & RI_MOUSE_BUTTON_5_UP) {
		window->Keyboard()->vertKeys[(int)wm::VertKey::X2Mouse] = false;
		mouseButtons[(int)wm::MouseButton::X2Mouse] = false;
	}
	if (mouse->usButtonFlags & RI_MOUSE_WHEEL) {
		scrollVelocity.y = (signed short)mouse->usButtonData * scrollSenitivity;
	}
	if (mouse->usButtonFlags & RI_MOUSE_HWHEEL) {
		scrollVelocity.x = (signed short)mouse->usButtonData * scrollSenitivity;
	}
}

void wm::Mouse::MouseMove(int x, int y) {
	Rect r = window->GetGameRect();
	double sx = (double)(x - r.x) / r.width * 2 - 1;
	double sy = (double)(y - r.y) / r.height * 2 - 1;
	gameNextPos = { sx, sy };
	screenNextPos = { x, y };
}

void wm::Mouse::SyncUpdate() {
	prevMouseButtons = mouseButtons;

	rawVelocity = nextRawVelocity * sensitivity;
	nextRawVelocity = { 0, 0 };

	screenVelocity = screenNextPos - screenPos;
	screenPos = screenNextPos;
	gameVelocity = gameNextPos - gamePos;
	gamePos = gameNextPos;
	math::Vec2d v = GetPosition();
	//std::cout << v << std::endl;
	bool inRange = !(v.x > 1 || v.x < -1 || v.y > 1 || v.y < -1);
	InternalShowCursor(!inRange || !window->isActive() || isShown);

	if (window->isActive() && inRange) {
		InternalConstrainCursor(constrainState);
	}
	else {
		InternalConstrainCursor(ConstrainCursorState::Free);
	}
}

void wm::Mouse::InternalConstrainCursor(ConstrainCursorState state) {
	if (state == prevConstrainState) return;
	prevConstrainState = state;
	switch (state) {
	default:
	case ConstrainCursorState::Free: {
		std::cout << "FREE MOUSE" << std::endl;
		ClipCursor(NULL);
	} break;
	case ConstrainCursorState::Constrained: {
		std::cout << "CONSTRAINED MOUSE" << std::endl;
		RECT v{};
		Rect k = window->GetGameScreenSpaceRect();
		v.top = k.y;
		v.left = k.x;
		v.bottom = k.y + k.height;
		v.right = k.x + k.width;
		ClipCursor(&v);
	} break;
	case ConstrainCursorState::Freeze: {
		std::cout << "FREEZE MOUSE" << std::endl;
		RECT v{};
		Rect k = window->GetGameScreenSpaceRect();
		v.top = v.bottom = k.y + k.height / 2;
		v.left = v.right = k.x + k.width / 2;
		ClipCursor(&v);
	} break;
	}
}

void wm::Mouse::ConstrainCursor(ConstrainCursorState state) {
	constrainState = state;
}

wm::Window::Window(std::string title, wm::WindowConstruct* construct) {
	this->title = title;

	static BOOL console = []()->BOOL {
		BOOL k = AllocConsole();
#pragma warning(suppress : 4996 6031)
		freopen("CONOUT$", "w", stdout);
#pragma warning(suppress : 4996 6031)
		freopen("CONIN$", "r", stdin);
#pragma warning(suppress : 4996 6031)
		freopen("CONOUT$", "w", stderr);
		return k;
	}();

	std::cout << "[Window] created!" << std::endl;

	static ATOM classAtom = []()->ATOM{
		const WNDCLASSEXA wndClass{
			.cbSize = sizeof(WNDCLASSEX),
			.style = CS_OWNDC,
			.lpfnWndProc = Wndproc,
			.cbClsExtra = 0,
			.cbWndExtra = sizeof(void*),
			.hInstance = GetModuleHandle(nullptr),
			.hIcon = NULL,
			.hCursor = NULL,
			.hbrBackground = NULL,
			.lpszMenuName = NULL,
			.lpszClassName = WIN_CLASS_NAME,
			.hIconSm = NULL,
		};

		ATOM a = RegisterClassExA(&wndClass);
		STAMPERROR(a == 0, "wm::Window::Window - register windows class failed");
		return a;
	}();

	std::thread controlThread = std::thread{ &Window::Control, this };
	controlThreadID = controlThread.get_id();
	controlThread.detach();
	AwaitInitialize();
}

void wm::RawSceneBase::Render() {
	GLSTAMPERROR;
	glBindFramebuffer(GL_READ_FRAMEBUFFER, framebuffer);
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, window->GetInitialFramebuffer());
	glReadBuffer(GL_COLOR_ATTACHMENT0 + colorAttachmentIndex);
	glDrawBuffer(wm::CurrentWindow()->GetRenderTarget());
	Rect r = window->GetGameRect();
	GLSTAMPERROR;
	glBlitFramebuffer(0, 0, colorAttachmentWidth, colorAttachmentHeight, r.x, r.y,
		r.x + r.width, r.y + r.height, GL_COLOR_BUFFER_BIT, GL_NEAREST);//GL_NEAREST  GL_LINEAR GL_SCALED_RESOLVE_FASTEST_EXT GL_SCALED_RESOLVE_NICEST_EXT

	GLSTAMPERROR;
}

void wm::RawSceneBase::SetFramebuffer(GLuint framebuffer, int width, int height, int colorAttachmentIndex) {
	this->framebuffer = framebuffer;
	this->colorAttachmentWidth = width;
	this->colorAttachmentHeight = height;
	this->colorAttachmentIndex = colorAttachmentIndex;
	if (window) window->SetGameRatio((float)width / height);
}

bool wm::Controls::isActionDown(int index) const {
	STAMPERROR(index < 0 || index >= MAX_ACTIONS, "Keyboard::isActionDown - index out of range");
	const InputAction& action = actions[index];
	if (action.key == VertKey::None) return false;
	if (action.ignoreMod) {
		return window->Keyboard()->isKeyDown(action.key);
	}
	else {
		return window->Keyboard()->isKeyDown(action.key) && action.shift == window->Keyboard()->isKeyDown(VertKey::Shift) &&
			action.control == window->Keyboard()->isKeyDown(VertKey::Control) &&
			action.alt == window->Keyboard()->isKeyDown(VertKey::Alt);
	}
}
bool wm::Controls::isActionUp(int index) const {
	STAMPERROR(index < 0 || index >= MAX_ACTIONS, "Keyboard::isActionUp - index out of range");
	const InputAction& action = actions[index];
	if (action.key == VertKey::None) return false;
	return window->Keyboard()->isKeyUp(action.key);
}
bool wm::Controls::isActionPress(int index) const {
	STAMPERROR(index < 0 || index >= MAX_ACTIONS, "Keyboard::isActionPress - index out of range");
	const InputAction& action = actions[index];
	if (action.key == VertKey::None) return false;
	if (action.ignoreMod) {
		return window->Keyboard()->isKeyPress(action.key);
	}
	else {
		return window->Keyboard()->isKeyPress(action.key) && action.shift == window->Keyboard()->isKeyDown(VertKey::Shift) &&
			action.control == window->Keyboard()->isKeyDown(VertKey::Control) &&
			action.alt == window->Keyboard()->isKeyDown(VertKey::Alt);
	}
}
bool wm::Controls::isActionRelease(int index) const {
	STAMPERROR(index < 0 || index >= MAX_ACTIONS, "Keyboard::isActionRelease - index out of range");
	const InputAction& action = actions[index];
	if (action.key == VertKey::None) return false;
	return window->Keyboard()->isKeyRelease(action.key);
}