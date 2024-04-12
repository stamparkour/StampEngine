#pragma once
#include <Windows.h>
#include "gamecore.h"

namespace game::component {
	struct AudioSourceEffect final : game::core::Component {
		Component_Requirements(AudioSourceEffect)
	public:
		std::shared_ptr<game::core::AudioClip> clip = nullptr;
		bool autoDelete = false;
		AudioSourceEffect() noexcept;
		AudioSourceEffect(std::shared_ptr<game::core::AudioClip> clip, bool autoDelete = true, bool startPlaying = true) noexcept;
		void Update() override;
		bool isPlaying();

		static void PlayClip(std::shared_ptr<game::core::AudioClip> clip);
	};
}