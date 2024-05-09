#pragma once
#include <Windows.h>
#include "gamecore.h"

namespace game::component {
	struct AudioSource final : game::core::Component {
		Component_Requirements(AudioSource)
	public:
		std::shared_ptr<game::core::AudioClip> clip = nullptr;
		bool autoDelete = false;
		AudioSource() noexcept;
		AudioSource(std::shared_ptr<game::core::AudioClip> clip, bool autoDelete = true, bool startPlaying = true) noexcept;
		void Update() override;
		bool isPlaying();

		static void PlayClip(std::shared_ptr<game::core::AudioClip> clip);
	};
}