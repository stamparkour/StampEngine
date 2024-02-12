#pragma once
#include <Windows.h>
#include "gamecore.h"

namespace game_component {
	struct AudioSourceEffect final : game_core::Component {
		Component_Requirements(AudioSourceEffect)
	public:
		xptr<game_core::AudioClip> clip = nullptr;
		bool autoDelete = false;
		AudioSourceEffect() noexcept;
		AudioSourceEffect(xptr<game_core::AudioClip> clip, bool autoDelete = true, bool startPlaying = true) noexcept;
		void Update(game_core::GameObject& gameObject) override;
		bool isPlaying();

		static void PlayClip(xptr<game_core::AudioClip> clip);
	};
}