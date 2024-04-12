#pragma once

namespace win::input {
	bool IsKeyDown(int virtualKey);
	//https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
	void KeyDown(int keyCode, bool isRepeat);
	//https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
	void KeyUp(int keyCode);
}
