#pragma once


namespace win::input {
	bool IsKeyDown(int virtualKey);
	//https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
	void KeyDown(int keyCode, bool isRepeat);
	//https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
	void KeyUp(int keyCode);

	void CursorVisibility(bool visible);
	enum struct CursorConstraintState {
		Free,
		Confined,
		Frozen,
	};
	void CursorConstraint(CursorConstraintState constraint);

	int GetCursorDeltaX();
	int GetCursorDeltaY();
	int GetCursorAbsoluteX();
	int GetCursorAbsoluteY();
	int GetCursorX();
	int GetCursorY();
	int GetCursorDeltaScroll();
}

namespace win::event {
	void Start(double time);
	void Update(double time);
	void SyncUpdate(double time);
	void FixedUpdate(double time);
	void Resize(double time, int width, int height);
	void Render(double time);
}
namespace win::state {
	enum struct WindowStyle {
		Normal,
		Borderless,
	};

	void TerminateWindow();
	double GetTime();
	bool isWindowActive();
	void SetWindowState(WindowStyle style, unsigned int width, unsigned int height);
	bool vSync();
	void vSync(bool enable);
	void ProcessWinEvents();
	double FixedUpdateInverval();
	void FixedUpdateInverval(double seconds);
}

#ifdef UNICODE
typedef wchar_t WIN_CHAR;
#else
typedef char WIN_CHAR;
#endif

extern const WIN_CHAR* WIN_NAME;