#pragma once
#include <Windows.h>
#include "gamecore.h"

namespace game_component {
	struct AudioSource final : game_core::Component {
		Component_Requirements(AudioSource)
	public:
		xptr<game_core::AudioClip> clip = nullptr;
		AudioSource() noexcept;
		void Update(game_core::GameObject& gameObject) override;
	};
}