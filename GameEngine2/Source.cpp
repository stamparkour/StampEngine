#include <string>
#include <iostream>
#include <utility>
#include <cmath>
#include <iterator>
#include <chrono>

#include <stamp/math/alignment.h>
#include <stamp/math/vector.h>
#include <stamp/math/quaternion.h>
#include <stamp/math/matrix.h>
#include <stamp/lua/lua.h>
#include <stamp/core/define.h>
#include <stamp/core/memory.h>
#include <stamp/graphics/window.h>
#include <stamp/stamp.h>
#include <stamp/hid/keyboard.h>
#include <stamp/engine/module.h>
#include <stamp/graphics/gl/shader.h>
#include <stamp/engine/windowscene.h>
#include <Windows.h>

#ifdef STAMP_DEPLOY

using namespace stamp::hid;
using namespace stamp::math;
using namespace stamp;
using namespace std;


struct rectTransform {
	vector2f alignment{ 0,0 };
	vector2f alignmentOffset{ 0,0 };
	vector2f offset{ 0,0 };
	vector2f size{ 200, 200 };
	vector2f parentSize;
	vector2f parentOffset;

	void Parentrect(const recti& rect) {
		parentSize = rect.Size();
		parentOffset = (rect.A + rect.B) / 2;
	}

	recti rect() {
		Matrix3f mat = AlignmentMatrix(alignment * vector2f{ 1, -1 }, alignmentOffset * vector2f{ 1, -1 }, offset, size, parentSize);
		vector2f topLeft = static_cast<vector2f>(mat * vector3f{ -1,-1,1 }) * parentSize / 2 + parentOffset;
		vector2f bottomRight = static_cast<vector2f>(mat * vector3f{ 1,1,1 }) * parentSize / 2 + parentOffset;

		return { static_cast<vector2i>(topLeft), static_cast<vector2i>(bottomRight)};
	}
	vector2i Center() {
		Matrix3f mat = AlignmentMatrix(alignment * vector2f{ 1, -1 }, alignmentOffset * vector2f{ 1, -1 }, offset, size, parentSize);
		return static_cast<vector2f>(mat * vector3f{ 0,0,1 }) * parentSize / 2 + parentOffset;
	}
};

class Windowrect {
	stamp::threadsafe_ptr<stamp::graphics::Window> window;
public:
	rectTransform transform;
	Windowrect(const sstring& title, const recti& rect, const vector2f& alignment) {
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
		transform.Parentrect(win->Parentrect());
		win->rect(transform.rect());
	}

	recti Parentrect() const {
		return window.get_readonly_unsafe()->Parentrect();
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


int main(int argv, char* argc[]) {
	stamp::InitStampEngine(stamp::StampEngineSettings{.showConsole = true});

	{
		stamp::task_queue renderQueue{};
		stamp::engine::SceneManager sceneManager{ &renderQueue };

		auto window = stamp::graphics::Window::Create(stamp::graphics::window::CreationSettings{
				.title = U"TEST",
				.rect = { 800, 700 },
				.visibility = stamp::graphics::window::visibility::Visible,
				.displaymode = stamp::graphics::window::displaymode::Normal,
				.terminateApplicationOnClose = false,
			}
		);

		sceneManager.RegisterScene<stamp::engine::WindowScene>(window);

		while (window.get_readonly()->IsAlive()) renderQueue.run_all();
	}

	stamp::CloseStampEngine();
	return 0;



	recti monitor = { 0,0,1920,1080 };
	vector2i center = (monitor.A + monitor.B) / 2;
	vector2i centerY = { 0, center.y };

	Windowrect player1{ U"P1", recti{20,-100,100,100} + centerY, alignment::TopLeft<float> };
	Windowrect player2{ U"P2", recti{-100,-100,-20,100} + centerY, alignment::TopRight<float> };
	Windowrect ball{ U"Ball", {center.x - 50,center.y - 50,center.x + 50,center.y + 50}, alignment::TopLeft<float> };

	Keyboard key(0);

	vector2f ballVelocity{ 20, 0 };

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
		if (key.ButtonDown(scancodeUS::S) && player1.transform.offset.y <= player1.Parentrect().bottom - 208) {
			player1.transform.offset.y += 8;
			p1Vel += 8;
		}

		int aiMove = AIControl(ball.transform.offset.y, player2.transform.offset.y);
		if (aiMove < 0 && player2.transform.offset.y >= 8) { //key.ButtonDown(scancodeUS::UpArrow)
			player2.transform.offset.y -= 8;
			p2Vel -= 8;
		}
		if (aiMove > 0 && player2.transform.offset.y <= player2.Parentrect().bottom - 208) { //key.ButtonDown(scancodeUS::DownArrow)
			player2.transform.offset.y += 8;
			p2Vel += 8;
		}

		//y velocity stuff
		ball.transform.offset.y += ballVelocity.y;
		if (ball.transform.offset.y <= 0 || ball.transform.offset.y + ball.transform.size.y >= ball.Parentrect().bottom) {
			ballVelocity.y = -ballVelocity.y;
			ball.transform.offset.y += ballVelocity.y;
		}
		if (player1.IsAlive() && rectCollide(ball.transform.rect(), player1.transform.rect())) {
			ballVelocity.y = -ballVelocity.y + p1Vel * 0.2;
			ball.transform.offset.y += 2 * ballVelocity.y;
		}
		if (player2.IsAlive() && rectCollide(ball.transform.rect(), player2.transform.rect())) {
			ballVelocity.y = -ballVelocity.y + p2Vel * 0.2;
			ball.transform.offset.y += 2 * ballVelocity.y;
		}

		//x velocity stuff
		ball.transform.offset.x += ballVelocity.x;
		if (player1.IsAlive() && rectCollide(ball.transform.rect(), player1.transform.rect())) {
			float relativeOffset = ball.transform.Center().y - player1.transform.Center().y;
			ballVelocity.x = -ballVelocity.x;
			ballVelocity.y = p1Vel * 2 + relativeOffset * 0.2;
			ball.transform.offset.x += 2 * ballVelocity.x;
			//ball.transform.offset.y += ballVelocity.y;
		}
		if (player2.IsAlive() && rectCollide(ball.transform.rect(), player2.transform.rect())) {
			float relativeOffset = ball.transform.Center().y - player2.transform.Center().y;
			ballVelocity.x = -ballVelocity.x;
			ballVelocity.y = p2Vel * 2 + relativeOffset * 0.2;
			ball.transform.offset.x += 2 * ballVelocity.x;
			//ball.transform.offset.y += ballVelocity.y;
		}
		if (ball.transform.offset.x <= 0) {
			ballVelocity.y = 0;
			ball.transform.offset = vector2i{ center.x - 50, center.y - 50 };
			p2Score++;
			player2.SetTitle(U"P2 S:" + to_sstring(p2Score));
		}
		if (ball.transform.offset.x + ball.transform.size.x >= ball.Parentrect().right) {
			ballVelocity.y = 0;
			ball.transform.offset = vector2i{ center.x - 50, center.y - 50 };
			p1Score++;
			player1.SetTitle(U"P1 S:" + to_sstring(p1Score));
		}

		ballVelocity.y = std::clamp(ballVelocity.y, -15.0f, 15.0f);

		player1.Update();
		player2.Update();
		ball.Update();
	}

	stamp::CloseStampEngine();
	return 0;
}

#endif
