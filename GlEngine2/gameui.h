#pragma once
#include "gamerender.h"

namespace game::component {
	class TextRendererUI final : public TextRenderer {
		Component_Requirements(TextRendererUI)
	public:
		TextRendererUI() : TextRenderer() {}
		void OnRender(int phase) override;
	};
	enum struct MouseState {
		Down,
		Up
	};
	typedef void (*MouseAction)(int x, int y, int buttonID, MouseState state);

	struct RectTransform final : game::core::Component {
		Component_Requirements(RectTransform)
	public:
		game::render::RectAlignment alignment;
		game::math::Vec2 position;
		game::math::Vec2 scale;
		MouseAction mouseAction;
		float depth = 0;
		RectTransform() {}
		RectTransform(game::render::RectAlignment alignment, game::math::Vec2 position, float depth = 1, game::math::Vec2 scale = { 1,1 }) : alignment(alignment), position(position), depth(depth), scale(scale) {}
		void Update() override;
	};

}