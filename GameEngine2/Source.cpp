#include <string>
#include <iostream>
#include <utility>
#include <cmath>
#include <stamp/math/vector.h>
#include <stamp/math/quaternion.h>
#include <stamp/math/matrix.h>
#include <stamp/lua/lua.h>
#include <stamp/core/define.h>
#include <stamp/memory.h>
#include <stamp/graphics/window.h>
#include <stamp/state.h>
#include <stamp/hid/keyboard.h>
#include <Windows.h>

#ifdef STAMP_DEPLOY

using namespace stamp::math;
using namespace stamp;
using namespace std;

stamp::graphics::Window* window;

class MyKeyboard : public stamp::hid::IKeyboardListener {
public:
	const char* msg;

	MyKeyboard(size_t id, const char* msg) : IKeyboardListener(id), msg(msg) {}

	virtual void OnButtonDown(stamp::hid::buttonID_t index) {
		std::cout << msg << ": Button Down: " << std::hex << index << std::dec << std::endl;

		if (index == stamp::hid::scancodeUS::UpArrow) window->Alignment(window->Alignment() + Vector2f(0, 0.05));
		if (index == stamp::hid::scancodeUS::DownArrow) window->Alignment(window->Alignment() + Vector2f(0, -0.05));
		if (index == stamp::hid::scancodeUS::LeftArrow) window->Alignment(window->Alignment() + Vector2f(-0.05, 0));
		if (index == stamp::hid::scancodeUS::RightArrow) window->Alignment(window->Alignment() + Vector2f(0.05, 0));
	}
	virtual void OnButtonUp(stamp::hid::buttonID_t index) {

	}
	virtual void OnConnect() {

	}
	virtual void OnDisconnect() {

	}
};

int StampEngineInit(int argv, char* argc[]) {
	std::cout << "Hello, Stamp Engine!" << std::endl;

	Vector2<float> v1(3.0f, 4.0f);
	Vector2<int> v2(5, 4);
	//std::swap(v1, v2);


	//Vector<float, 2> v3{ 0 };
	//auto k = static_cast<Vector<int, 3>>(v3);

	////Matrix<float, 2, 2> m1{ 2, 3 };
	////Matrix<float, 2, 1> m2{ v2 };
	////auto m3 = m1 * m2; // Matrix multiplication

	//float i = magnitude(v2);

	//Vector3ld myVector = Vector3ld(5, 4, 3);
	//Vector3ld forward = Vector3ld::FORWARD;
	//auto q = cross(myVector, forward);
	//auto t = (myVector + 3.0l) / 5.0l;

	//sol::state lua = stamp::lua::InitializeLua();
	//lua.safe_script_file("resources\\script\\test.lua");


	window = new stamp::graphics::Window{ stamp::graphics::window::CreationSettings{
			.title = U"Stamp Engine - Window",
			.rect = { {100, 100}, {800, 600}},
			.visibility = stamp::graphics::window::visibility::Visible,
		}
	};

	MyKeyboard keyboardA(0, "A");


	int k = 0;
	bool toggle = false;
	while (window->IsAlive()) {
		Sleep(2);
		window->Rect({ -100 + k, -100, 100 + k, 100 });
		if (std::abs(k) > 400) toggle = !toggle;
		k += toggle ? 80 : -80;
	}

	window->WindowClosePromise().wait();

	return 0;
}

#endif