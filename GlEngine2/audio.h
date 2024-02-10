#pragma once
#include <Windows.h>
#include "gamecore.h"

namespace game_component {
	struct AudioSourceEffect final : game_core::Component {
		Component_Requirements(AudioSourceEffect)
	public:
		xptr<game_core::AudioClip> clip = nullptr;
		AudioSourceEffect() noexcept;
		void Update(game_core::GameObject& gameObject) override;
		bool isPlaying();
	};
}