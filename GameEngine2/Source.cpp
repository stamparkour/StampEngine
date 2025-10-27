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
	Vector2i Center() {
		Matrix3f mat = AlignmentMatrix(alignment * Vector2f{ 1, -1 }, alignmentOffset * Vector2f{ 1, -1 }, offset, size, parentSize);
		return static_cast<Vector2f>(mat * Vector3f{ 0,0,1 }) * parentSize / 2 + parentOffset;
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
			.displaymode = stamp::graphics::window::displaymode::Toolbox,
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
	void SetTitle(const sstring& title) {
		window.get()->Title(title);
	}
};

int AIControl(float ballY, float currentY) {
	if (ballY + 50 < currentY + 100) {
		return -1;
	}
	else if (ballY > currentY + 100) {
		return 1;
	}
	return 0;
}

int StampEngineInit(int argv, char* argc[]) {
	Recti monitor = { 0,0,1920,1080 };
	Vector2i center = (monitor.A + monitor.B) / 2;
	Vector2i centerY = { 0, center.y };

	WindowRect player1{ U"P1", Recti{20,-100,100,100} + centerY, alignment::TopLeft<float> };
	WindowRect player2{ U"P2", Recti{-100,-100,-20,100} + centerY, alignment::TopRight<float> };
	WindowRect ball{ U"Ball", {center.x - 50,center.y - 50,center.x + 50,center.y + 50}, alignment::TopLeft<float> };

	Keyboard key(0);

	Vector2f ballVelocity{ 20, 0 };

	int p1Score = 0;
	int p2Score = 0;

	while (player1.IsAlive() || player2.IsAlive()) {
		Sleep(17);

		float p1Vel = 0;
		float p2Vel = 0;

		//player controls
		if (key.ButtonDown(scancodeUS::W) && player1.transform.offset.y >= 8) {
			player1.transform.offset.y -= 8;
			p1Vel -= 8;
		}
		if (key.ButtonDown(scancodeUS::S) && player1.transform.offset.y <= player1.ParentRect().bottom - 208) {
			player1.transform.offset.y += 8;
			p1Vel += 8;
		}

		int aiMove = AIControl(ball.transform.offset.y, player2.transform.offset.y);
		if (aiMove < 0 && player2.transform.offset.y >= 8) { //key.ButtonDown(scancodeUS::UpArrow)
			player2.transform.offset.y -= 8;
			p2Vel -= 8;
		}
		if (aiMove > 0 && player2.transform.offset.y <= player2.ParentRect().bottom - 208) { //key.ButtonDown(scancodeUS::DownArrow)
			player2.transform.offset.y += 8;
			p2Vel += 8;
		}

		//y velocity stuff
		ball.transform.offset.y += ballVelocity.y;
		if (ball.transform.offset.y <= 0 || ball.transform.offset.y + ball.transform.size.y >= ball.ParentRect().bottom) {
			ballVelocity.y = -ballVelocity.y;
			ball.transform.offset.y += ballVelocity.y;
		}
		if (RectCollide(ball.transform.Rect(), player1.transform.Rect())) {
			ballVelocity.y = -ballVelocity.y + p1Vel * 0.2;
			ball.transform.offset.y += 2 * ballVelocity.y;
		}
		if (RectCollide(ball.transform.Rect(), player2.transform.Rect())) {
			ballVelocity.y = -ballVelocity.y + p2Vel * 0.2;
			ball.transform.offset.y += 2 * ballVelocity.y;
		}

		//x velocity stuff
		ball.transform.offset.x += ballVelocity.x;
		if (RectCollide(ball.transform.Rect(), player1.transform.Rect())) {
			float relativeOffset = ball.transform.Center().y - player1.transform.Center().y;
			ballVelocity.x = -ballVelocity.x;
			ballVelocity.y = p1Vel * 2 + relativeOffset * 0.2;
			ball.transform.offset.x += 2 * ballVelocity.x;
			//ball.transform.offset.y += ballVelocity.y;
		}
		if (RectCollide(ball.transform.Rect(), player2.transform.Rect())) {
			float relativeOffset = ball.transform.Center().y - player2.transform.Center().y;
			ballVelocity.x = -ballVelocity.x;
			ballVelocity.y = p2Vel * 2 + relativeOffset * 0.2;
			ball.transform.offset.x += 2 * ballVelocity.x;
			//ball.transform.offset.y += ballVelocity.y;
		}
		if (ball.transform.offset.x <= 0) {
			ballVelocity.y = 0;
			ball.transform.offset = Vector2i{ center.x - 50, center.y - 50 };
			p2Score++;
			//player2.SetTitle(U"P2 " + to_sstring(p1Score));
		}
		if (ball.transform.offset.x + ball.transform.size.x >= ball.ParentRect().right) {
			ballVelocity.y = 0;
			ball.transform.offset = Vector2i{ center.x - 50, center.y - 50 };
			p1Score++;
			//player1.SetTitle(U"P1 " + to_sstring(p1Score));
		}

		ballVelocity.y = std::clamp(ballVelocity.y, -15.0f, 15.0f);

		player1.Update();
		player2.Update();
		ball.Update();
	}

	return 0;
}

#endif