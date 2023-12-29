#pragma once

#include <Windows.h>
#include <gl/gl.h>
#include <gl/glu.h>

namespace GLCore {

	void Start(double time);
	void Update(double time);
	void Resize(double time, int width, int height);
	void Render(double time);
	//https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
	void KeyDown(int keyCode, bool isRepeat);
	//https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
	void KeyUp(int keyCode);

	void TerminateWindow();
}

namespace GLInput {
	bool IsKeyDown(int virtualKey);
}
