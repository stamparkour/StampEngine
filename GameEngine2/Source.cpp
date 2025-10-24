#include <string>
#include <iostream>
#include <utility>
#include <cmath>
#include <stamp/math/alignment.h>
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

using namespace stamp::hid;
using namespace stamp::math;
using namespace stamp;
using namespace std;

struct RectTransform {
	Vector2f alignment;
	Vector2f alignmentOffset;
	Vector2f offset;
	Vector2f size;
	Vector2f parentSize;
	Vector2f parentOffset;

	void ParentRect(const Recti& rect) {
		parentSize = rect.Size();
		parentOffset = { rect.A.x, rect.B.y };
	}

	Recti Rect() {
		Matrix3f mat = AlignmentMatrix(alignment, alignmentOffset, offset, size, parentSize);
		Vector2f topLeft = static_cast<Vector2f>(mat * Vector3f{ -1,1,1 }) + parentOffset;
		Vector2f bottomRight = static_cast<Vector2f>(mat * Vector3f{ -1,1,1 }) + parentOffset;

		return { static_cast<Vector2i>(topLeft), static_cast<Vector2i>(bottomRight)};
	}
};

int StampEngineInit(int argv, char* argc[]) {
	auto myWindow = stamp::graphics::Window::Create(stamp::graphics::window::CreationSettings{
			.title = U"Stamp Engine - Window",
			.rect = { {100, 100}, {800, 600}},
			.visibility = stamp::graphics::window::visibility::Visible,
		}
	);

	Keyboard key(0);

	while (myWindow.get_readonly_unsafe()->IsAlive()) {
		Sleep(2);

		auto win = myWindow.get();
		
		if (key.ButtonDown(scancodeUS::W)) {
			std::cout << "Hell" << std::endl;
		}
		win->Rect({ 100,100,200,200 });
	}

	myWindow.get_readonly_unsafe()->WindowClosePromise().wait();

	return 0;
}

#endif