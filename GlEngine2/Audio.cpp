#include "audio.h"
game::component::AudioSourceEffect::AudioSourceEffect() noexcept {
	
}
void game::component::AudioSourceEffect::Update() {
	if (autoDelete && clip && !isPlaying())selfObject()->Destroy();
}

bool game::component::AudioSourceEffect::isPlaying() {
	return clip && clip->isPlaying();
}
game::component::AudioSourceEffect::AudioSourceEffect(std::shared_ptr<game::core::AudioClip> clip, bool autoDelete, bool startPlaying) noexcept {
	this->clip = clip;
	this->autoDelete = autoDelete;
	if(startPlaying) this->clip->Play(1);
}
void game::component::AudioSourceEffect::PlayClip(std::shared_ptr<game::core::AudioClip> clip) {
	game::core::GameObject obj{};
	obj.AddComponent(AudioSourceEffect(clip));
	game::core::GameManager::Current()->scene->AddObject(obj);
}