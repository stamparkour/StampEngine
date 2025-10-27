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
	Vector2f alignment{ 0,0 };
	Vector2f alignmentOffset{ 0,0 };
	Vector2f offset{ 0,0 };
	Vector2f size{ 200, 200 };
	Vector2f parentSize;
	Vector2f parentOffset;

	void ParentRect(const Recti& rect) {
		parentSize = rect.Size();
		parentOffset = (rect.A + rect.B) / 2;
	}

	Recti Rect() {
		Matrix3f mat = AlignmentMatrix(alignment * Vector2f{ 1, -1 }, alignmentOffset * Vector2f{ 1, -1 }, offset, size, parentSize);
		Vector2f topLeft = static_cast<Vector2f>(mat * Vector3f{ -1,-1,1 }) * parentSize / 2 + parentOffset;
		Vector2f bottomRight = static_cast<Vector2f>(mat * Vector3f{ 1,1,1 }) * parentSize / 2 + parentOffset;

		return { static_cast<Vector2i>(topLeft), static_cast<Vector2i>(bottomRight)};
	}
};

class WindowRect {
	stamp::threadsafe_ptr<stamp::graphics::Window> window;
public:
	RectTransform transform;
	WindowRect(const sstring& title, const Recti& rect, const Vector2f& alignment) {
		window = stamp::graphics::Window::Create(stamp::graphics::window::CreationSettings{
			.title = title,
			.visibility = stamp::graphics::window::visibility::Visible,
			.displaymode = stamp::graphics::window::displaymode::Popup,
			}
		);

		transform.alignment = alignment;
		transform.offset = rect.A;
		transform.size = rect.Size();
		transform.alignmentOffset = alignment::TopLeft<float>;
	}

	void Update() {
		auto win = window.get();
		transform.ParentRect(win->ParentRect());
		win->Rect(transform.Rect());
	}

	Recti ParentRect() const {
		return window.get_readonly_unsafe()->ParentRect();
	}

	bool IsAlive() const {
		return window.get_readonly_unsafe()->IsAlive();
	}
};

int StampEngineInit(int argv, char* argc[]) {
	Recti monitor = { 0,0,1920,1080 };
	Vectori center = (monitor.A + monitor.B) / 2;

	WindowRect player1{ U"Player 1", {0,100,200,300}, alignment::TopLeft<float> };
	WindowRect player2{ U"Player 2", {-200,100,0,300}, alignment::TopRight<float> };
	WindowRect ball{ U"Ball", {center.x - 50,center.y - 50,center.x + 50,center.y + 50}, alignment::TopLeft<float> };

	Keyboard key(0);

	Vector2i ballVelocity{ 20, -12 };

	while (player1.IsAlive() || player2.IsAlive()) {
		Sleep(20);

		if (key.ButtonDown(scancodeUS::W) && player1.transform.offset.y >= 10) player1.transform.offset.y -= 10;
		if (key.ButtonDown(scancodeUS::S) && player1.transform.offset.y <= player1.ParentRect().bottom - 210) player1.transform.offset.y += 10;

		if (key.ButtonDown(scancodeUS::UpArrow) && player2.transform.offset.y >= 10) player2.transform.offset.y -= 10;
		if (key.ButtonDown(scancodeUS::DownArrow) && player2.transform.offset.y <= player2.ParentRect().bottom - 210) player2.transform.offset.y += 10;

		ball.transform.offset.y += ballVelocity.y;
		if (ball.transform.offset.y <= 0 || ball.transform.offset.y + ball.transform.size.y >= ball.ParentRect().bottom) {
			ballVelocity.y = -ballVelocity.y;
			ball.transform.offset.y += ballVelocity.y;
		}
		if (RectCollide(ball.transform.Rect(), player1.transform.Rect()) ||
			RectCollide(ball.transform.Rect(), player2.transform.Rect())) {
			ballVelocity.y = -ballVelocity.y;
			ball.transform.offset.y += 2 * ballVelocity.y;
		}
		ball.transform.offset.x += ballVelocity.x;
		if (RectCollide(ball.transform.Rect(), player1.transform.Rect()) ||
			RectCollide(ball.transform.Rect(), player2.transform.Rect())) {
			ballVelocity.x = -ballVelocity.x;
			ball.transform.offset.x += 2 * ballVelocity.x;
		}
		if (ball.transform.offset.x <= 0 || ball.transform.offset.x + ball.transform.size.x >= ball.ParentRect().right) {
			ballVelocity.y = 20;
			ball.transform.offset = Vector2i{ center.x - 50, center.y - 50 };
		}

		player1.Update();
		player2.Update();
		ball.Update();
	}

	return 0;
}

#endif