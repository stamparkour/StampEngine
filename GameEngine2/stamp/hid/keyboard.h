//stamp/hid/keyboard.h

#pragma once
#ifndef STAMP_HID_KEYBOARD_H
#define STAMP_HID_KEYBOARD_H

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


#include <stamp/core/string_internal.h>
#include <stamp/hid/define.h>
#include <stamp/hid/hid.h>
#include <stamp/noncopyable.h>
#include <stamp/memory.h>

STAMP_HID_NAMESPACE_BEGIN


namespace scancodeUS {
	//https://learn.microsoft.com/en-us/windows/win32/inputdev/about-keyboard-input#scan-codes
	enum : size_t {
		A = 0x001E,
		B = 0x0030,
		C = 0x002E,
		D = 0x0020,
		E = 0x0012,
		F = 0x0021,
		G = 0x0022,
		H = 0x0023,
		I = 0x0017,
		J = 0x0024,
		K = 0x0025,
		L = 0x0026,
		M = 0x0032,
		N = 0x0031,
		O = 0x0018,
		P = 0x0019,
		Q = 0x0010,
		R = 0x0013,
		S = 0x001F,
		T = 0x0014,
		U = 0x0016,
		V = 0x002F,
		W = 0x0011,
		X = 0x002D,
		Y = 0x0015,
		Z = 0x002C,
		k1 = 0x0002,
		k2 = 0x0003,
		k3 = 0x0004,
		k4 = 0x0005,
		k5 = 0x0006,
		k6 = 0x0007,
		k7 = 0x0008,
		k8 = 0x0009,
		k9 = 0x000A,
		k0 = 0x000B,
		Bang = 0x0002,
		At = 0x0003,
		Hash = 0x0004,
		Dollar = 0x0005,
		Percent = 0x0006,
		Caret = 0x0007,
		Ampersand = 0x0008,
		Star = 0x0009,
		LeftBracket = 0x000A,
		RightBracket = 0x000B,
		Return = 0x001C,
		Enter = 0x001C,
		Escape = 0x0001,
		Delete = 0x000E,
		Tab = 0x000F,
		Space = 0x0039,
		Dash = 0x000C,
		Underscore = 0x000C,
		Equals = 0x000D,
		Plus = 0x000D,
		LeftBracketSquare = 0x001A,
		RightBracketSquare = 0x001B,
		Backslash = 0x002B,
		Pipe = 0x002B,
		NonUSHash = 0x002B,
		NonUsTilde = 0x002B,
		Semicolon = 0x0027,
		Colon = 0x0027,
		Apostrophe = 0x0028,
		Quote = 0x0028,
		GraveAccent = 0x029,
		Tilde = 0x029,
		Comma = 0x0033,
		LessThan = 0x0033,
		Period = 0x0034,
		GreaterThan = 0x0034,
		Slash = 0x0035,
		QuestionMark = 0x0035,
		CapsLock = 0x003A,
		F1 = 0x003B,
		F2 = 0x003C,
		F3 = 0x003D,
		F4 = 0x003E,
		F5 = 0x003F,
		F6 = 0x0040,
		F7 = 0x0041,
		F8 = 0x0042,
		F9 = 0x0043,
		F10 = 0x0044,
		F11 = 0x0057,
		F12 = 0x0058,
		PrintScreen = 0xE037,
		ScrollLock = 0x0046,
		Pause = 0xE046,
		Insert = 0xE052,
		Home = 0xE047,
		PageUp = 0xE049,
		DeleteForward = 0xE053,
		End = 0xE04F,
		PageDown = 0xE051,
		RightArrow = 0xE04D,
		LeftArrow = 0xE04B,
		DownArrow = 0xE050,
		UpArrow = 0xE048,
		NumLock = 0x0045,
		Clear = 0x0045,
		nSlash = 0x0035,
		nStar = 0x0037,
		nMinus = 0x004A,
		nPlus = 0x004E,
		nEnter = 0xE01C,
		n1 = 0x004F,
		n2 = 0x0050,
		n3 = 0x0051,
		n4 = 0x004B,
		n5 = 0x004C,
		n6 = 0x004D,
		n7 = 0x0047,
		n8 = 0x0048,
		n9 = 0x0049,
		n0 = 0x0052,
		nPeriod = 0x0053,
		NonUSBackslash = 0x0056,
		NonUSPipe = 0x0056,
		nEqual = 0x0059,
		nComma = 0x007E,
		International1 = 0x0073,
		International2 = 0x0070,
		International3 = 0x007D,
		International4 = 0x0079,
		International5 = 0x007B,
		International6 = 0x005C,
		LeftControl = 0x001D,
		LeftShift = 0x002A,
		LeftAlt = 0x0038,
		LeftGUI = 0xE05B,
		RightControl = 0xE01D,
		RightShift = 0x0036,
		RightAlt = 0xE038,
		RightGUI = 0xE05C,
	};
}

class Keyboard final : public IHumanInterfaceDevice_Base {
	class Keyboard_internal* data;
private:
public:
	Keyboard(int id);

	~Keyboard() noexcept;

	bool Exists() const noexcept override;

	bool ButtonDown(size_t index) const noexcept override;
	bool ButtonUp(size_t index) const noexcept override;
	bool ButtonPressed(size_t index) const noexcept override;
	bool ButtonReleased(size_t index) const noexcept override;

	virtual STAMP_DEFAULT_FLOATINGPOINT Axis(size_t index) const noexcept override;
	virtual STAMP_DEFAULT_FLOATINGPOINT AxisDelta(size_t index) const noexcept override;
};

class KeyboardCharacterBuffer final : public STAMP_NAMESPACE::INonCopyable {
	friend class Keyboard;
public:
	using char_type = stamp::stamp_char;
	using keyboard_string = stamp::sstring;
private:
	size_t cursor;
	size_t lineWidth;
	keyboard_string buffer;
public:
	KeyboardCharacterBuffer(Keyboard keyboard);

	void Reset(keyboard_string newBuffer = U"") noexcept {
		this->buffer = std::move(newBuffer);
		cursor = buffer.size();
	}
	void LineWidth(size_t width) noexcept {
		lineWidth = width;
	}
	size_t LineWidth() const noexcept {
		return lineWidth;
	}
	const keyboard_string& Buffer() const noexcept {
		return buffer;
	}

	void Cursor(size_t index) noexcept {
		if (index > buffer.size()) index = buffer.size();
		cursor = index;
	}
	size_t Cursor() const noexcept {
		return cursor;
	}
	void Write(char_type c) noexcept {
		buffer.insert(cursor, 1, c);
		cursor++;
	}
	void CursorUp() noexcept {
		if (cursor == 0) return;
		//retrieves the current line index
		size_t newlineIndex = cursor;
		for (; newlineIndex > 0 && buffer[newlineIndex - 1] != '\n'; --newlineIndex);
		size_t currentLineLength = cursor - newlineIndex;

		//calculates the previous line index taking into account line width
		if (lineWidth != 0 && currentLineLength >= lineWidth) {
			size_t localLineLength = currentLineLength % lineWidth;
			size_t currentLine = currentLineLength / lineWidth;
			size_t nextLineIndex = (currentLine - 1) * lineWidth + localLineLength;
			cursor = nextLineIndex + newlineIndex;
			return;
		}
		//checks if we are on the first line of the message
		if (newlineIndex == 0) {
			cursor = 0;
			return;
		}

		//closest line is previous newline
		size_t prevNewlineIndex = cursor;
		for (; prevNewlineIndex > 0 && buffer[prevNewlineIndex - 1] != '\n'; --prevNewlineIndex);
		size_t prevLineLength = newlineIndex - prevNewlineIndex;

		//go up to the previous line without any line width restrictions
		if (lineWidth == 0 || prevLineLength < lineWidth) {
			cursor = prevNewlineIndex + (prevLineLength >= currentLineLength ? currentLineLength : prevLineLength);
		}
		else {
			size_t localLineLength = currentLineLength;
			size_t prevLine = currentLineLength / lineWidth;
			size_t nextLineIndex = prevLine * lineWidth + localLineLength;
			cursor = nextLineIndex + prevNewlineIndex;
		}
	}
	void CursorRight() noexcept {
		if (cursor == buffer.size()) return;
		cursor++;
	}
	void CursorLeft() noexcept {
		if (cursor == 0) return;
		cursor--;
	}
	//unfinished
	void CursorDown() {
		size_t newlineIndex = cursor;
		for (; newlineIndex < buffer.size() && buffer[newlineIndex + 1] != '\n'; ++newlineIndex);
		size_t currentLineLength = cursor - newlineIndex;

	}
};

STAMP_HID_NAMESPACE_END

#endif