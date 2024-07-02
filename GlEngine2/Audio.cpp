#include "audio.h"
#include "gamecore.h"
#include <fstream>
#include <iostream>
#include <xaudio2fx.h>
#include <x3daudio.h>

void game::audio::AudioManager::OnCriticalError(HRESULT Error) {
	std::cout << "AUDIO ENGINE CRITICAL ERROR : " << std::hex << Error << std::endl;
}

//https://learn.microsoft.com/en-us/windows/win32/xaudio2/how-to--play-a-sound-with-xaudio2
bool game::audio::AudioManager::Initialize() {
	HRESULT hr;
	pXAudio2 = nullptr;
	if (FAILED(hr = XAudio2Create(&pXAudio2, 0, XAUDIO2_DEFAULT_PROCESSOR)))
		return true;

	XAUDIO2_DEBUG_CONFIGURATION debug{};
	debug.TraceMask = XAUDIO2_LOG_ERRORS | XAUDIO2_LOG_WARNINGS | XAUDIO2_LOG_INFO | XAUDIO2_LOG_DETAIL | XAUDIO2_LOG_FUNC_CALLS | XAUDIO2_LOG_TIMING | XAUDIO2_LOG_LOCKS | XAUDIO2_LOG_MEMORY | XAUDIO2_LOG_STREAMING;
	debug.BreakMask = XAUDIO2_LOG_ERRORS | XAUDIO2_LOG_WARNINGS;
	debug.LogFunctionName = true;
	debug.LogTiming = true;
	debug.LogFileline = true;
	debug.LogThreadID = true;

	pXAudio2->SetDebugConfiguration(&debug);

	pXAudio2->RegisterForCallbacks(this);

	hr = pXAudio2->CreateMasteringVoice(&pMasterVoice, XAUDIO2_DEFAULT_CHANNELS, XAUDIO2_DEFAULT_SAMPLERATE, 0, NULL, NULL, AudioCategory_GameEffects);
	if (FAILED(hr))
		return true;

	DWORD dwChannelMask;
	pMasterVoice->GetChannelMask(&dwChannelMask);
	X3DAudioInitialize(dwChannelMask, X3DAUDIO_SPEED_OF_SOUND, XAudio3d);

	return false;
}

IXAudio2SourceVoice* game::audio::AudioManager::NewSourceVoice(const WAVEFORMATEX* format, IXAudio2VoiceCallback* callback)
{
	IXAudio2SourceVoice* voice;
	pXAudio2->CreateSourceVoice(&voice, format, 0, 2, callback);
	sourceVoices.push_back(voice);
	return voice;
}
bool getChunk(long fourcc,const char* data, size_t length, size_t& index, size_t& size) {
	for (size_t i = 12; i < length;) {
		if (*(long*)(data + i) == fourcc) {
			i += 4;
			size = *(uint32_t*)(data + i);
			i += 4;
			index = ((i + 1) / 2) * 2;
			return true;
		}
		else {
			i += 4;
			i += *(uint32_t*)(data + i) + 4;
			i = ((i + 1) / 2) * 2;
		}
	}
	return false;
}

game::audio::AudioClip::AudioClip(std::shared_ptr<char> buf, size_t length) {
	HRESULT hr;
	auto pXAudio2 = game::core::GameManager::Current()->audio.pXAudio2;
	ptr = buf;
	clip = {};
	//little endian
	if (*(long*)(ptr.get() + 0) != 'FFIR') return;
	long fileSize = *(long*)(ptr.get() + 4) + 8;
	if (*(long*)(ptr.get() + 8) != 'EVAW') return;
	size_t fmtIndex = 0;
	size_t fmtLength = 0;
	if (!getChunk(' tmf', ptr.get(), length, fmtIndex, fmtLength)) return;
	size_t dataIndex = 0;
	size_t dataSize = 0;
	if (!getChunk('atad', ptr.get(), length, dataIndex, dataSize)) return;
	memcpy_s(&fmt, sizeof(WAVEFORMATEX), (char*)ptr.get() + fmtIndex, fmtLength);
	size_t channelSize = dataSize / fmt.Format.nChannels;
	size_t unitSize = fmt.Format.nBlockAlign / fmt.Format.nChannels;

	for (int i = 0; i < fmt.Format.nChannels; i++) {
		char* buf = new char[channelSize];
		
		char* d = ptr.get() + dataIndex + unitSize * i;
		char* b = buf;
		size_t cs = channelSize;
		while (cs > 0) {
			memcpy_s(b, cs, d, unitSize);
			b += unitSize;
			d += fmt.Format.nBlockAlign;
			cs -= unitSize;
		}
		clip.push_back(std::shared_ptr<char>(buf));
	}
	buffer.AudioBytes = channelSize;
	fmt.Format.nBlockAlign = unitSize;
	fmt.Format.nChannels = 1;
}
game::audio::AudioPlayback game::audio::AudioClip::init() {
	return AudioPlayback(clip, &fmt, &buffer);
}
game::audio::AudioPlayback game::audio::AudioClip::play() {
	auto v = init();
	v.play();
	return v;
}

game::audio::AudioClip::~AudioClip() {

}
game::audio::AudioPlayback::AudioPlayback(std::vector<std::shared_ptr<char>> clip, WAVEFORMATEXTENSIBLE* format, XAUDIO2_BUFFER* buffer) {
	data = std::vector< AudioData>(clip.size());
	for (int i = 0; i < clip.size(); i++) {
		data[i].clip = clip[i];
		data[i].source = game::core::GameManager::Current()->audio.NewSourceVoice((WAVEFORMATEX*)format, NULL);
		buffer->pAudioData = (const BYTE*)clip[i].get();
		data[i].source->SubmitSourceBuffer(buffer);
		data[i].source->SetVolume(1.0 / clip.size());
	}
}
void game::audio::AudioPlayback::play() {
	for (int i = 0; i < data.size(); i++) {
		data[i].source->Start();
	}
}
game::audio::AudioPlayback::~AudioPlayback() {
	//CloseHandle(hBufferEndEvent);
}
void game::audio::AudioPlayback::OnStreamEnd() {
	playing = false;
}
bool game::audio::AudioPlayback::isPlaying() const {
	return playing;
}

game::component::AudioSource::AudioSource() noexcept {
	
}
void game::component::AudioSource::Update() {
	if (autoDelete && !isPlaying()) selfObject()->Destroy();
}

bool game::component::AudioSource::isPlaying() {
	return clip.isPlaying();
}
game::component::AudioSource::AudioSource(std::shared_ptr<game::audio::AudioClip> clip, bool autoDelete, bool startPlaying) noexcept {
	this->clip = clip.get()->init();
	this->autoDelete = autoDelete;
}
game::core::GameObject game::component::AudioSource::PlayClip(std::shared_ptr<game::audio::AudioClip> clip) {
	game::core::GameObject obj{};
	obj.AddComponent(AudioSource(clip));
	clip.get()->play();
	return obj;
}