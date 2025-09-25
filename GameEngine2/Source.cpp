#include <string>
#include <iostream>
#include <utility>
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

using namespace stamp::math;
using namespace stamp;
using namespace std;

class MyKeyboard : public stamp::hid::IKeyboardListener {
public:
	MyKeyboard(size_t id) : IKeyboardListener(id) {}

	virtual void OnButtonDown(stamp::hid::buttonID_t index) {
		std::cout << "Button Down: " << std::hex << index << std::endl;
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

	//Vector2<float> v1(3.0f, 4.0f);
	//Vector2<float> v2(5.0f, 4.0f);
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


	stamp::graphics::Window window{ stamp::graphics::window::CreationSettings{
			.title = U"Stamp Engine - Window",
			.rect = { {100, 100}, {800, 600}},
			.visibility = stamp::graphics::window::visibility::Visible,
			.vsync = true,
		}
	};

	stamp::graphics::Window window2{ stamp::graphics::window::CreationSettings{
			.title = U"Stamp Engine - Window",
			.rect = { {100, 100}, {800, 600}},
			.visibility = stamp::graphics::window::visibility::Visible,
			.vsync = true,
		}
	};

	MyKeyboard keyboard(0);

	window.WaitForWindowClose().wait();
	window2.WaitForWindowClose().wait();

	return 0;
}