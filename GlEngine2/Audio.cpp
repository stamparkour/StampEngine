#include "audio.h"
game::component::AudioSource::AudioSource() noexcept {
	
}
void game::component::AudioSource::Update() {
	if (autoDelete && clip && !isPlaying())selfObject()->Destroy();
}

bool game::component::AudioSource::isPlaying() {
	return clip && clip->isPlaying();
}
game::component::AudioSource::AudioSource(std::shared_ptr<game::core::AudioClip> clip, bool autoDelete, bool startPlaying) noexcept {
	this->clip = clip;
	this->autoDelete = autoDelete;
	if(startPlaying) this->clip->Play(1);
}
void game::component::AudioSource::PlayClip(std::shared_ptr<game::core::AudioClip> clip) {
	game::core::GameObject obj{};
	obj.AddComponent(AudioSource(clip));
	game::core::GameManager::Current()->scene->AddObject(obj);
}