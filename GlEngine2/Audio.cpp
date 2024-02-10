#include "audio.h"
game_component::AudioSourceEffect::AudioSourceEffect() noexcept {
}
void game_component::AudioSourceEffect::Update(game_core::GameObject& gameObject) {
	if (!isPlaying())gameObject.Destroy();
}

bool game_component::AudioSourceEffect::isPlaying() {
	return clip && clip->isPlaying();
}
