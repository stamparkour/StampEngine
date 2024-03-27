#include "audio.h"
game_component::AudioSourceEffect::AudioSourceEffect() noexcept {
	
}
void game_component::AudioSourceEffect::Update() {
	if (autoDelete && clip && !isPlaying())selfObject()->Destroy();
}

bool game_component::AudioSourceEffect::isPlaying() {
	return clip && clip->isPlaying();
}
game_component::AudioSourceEffect::AudioSourceEffect(std::shared_ptr<game_core::AudioClip> clip, bool autoDelete, bool startPlaying) noexcept {
	this->clip = clip;
	this->autoDelete = autoDelete;
	if(startPlaying) this->clip->Play(1);
}
void game_component::AudioSourceEffect::PlayClip(std::shared_ptr<game_core::AudioClip> clip) {
	game_core::GameObject obj{};
	obj.AddComponent(AudioSourceEffect(clip));
	game_core::GameManager::Current()->scene->AddObject(obj);
}