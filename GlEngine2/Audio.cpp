#include "audio.h"
#include "gamecore.h"
#include <fstream>
#include <iostream>
#include <xaudio2fx.h>
#include <x3daudio.h>

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

	hr = pXAudio2->CreateMasteringVoice(&pMasterVoice, 2, XAUDIO2_DEFAULT_SAMPLERATE, 0, NULL, NULL, AudioCategory_GameEffects);
	if (FAILED(hr))
		return true;
	DWORD dwChannelMask;
	pMasterVoice->GetChannelMask(&dwChannelMask);
	X3DAudioInitialize(dwChannelMask, X3DAUDIO_SPEED_OF_SOUND, XAudio3d);

	return false;
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

game::audio::AudioClip::AudioClip(const char *buffer, size_t length) : hBufferEndEvent(CreateEvent(NULL, FALSE, FALSE, NULL)) {
	HRESULT hr;
	auto pXAudio2 = game::core::GameManager::Current()->audio.pXAudio2;
	ptr = std::shared_ptr<char>{ new char[length] };
	memcpy_s(ptr.get(), length, buffer, length);
	//little endian
	if (*(long*)(buffer + 0) != 'FFIR') return;
	long fileSize = *(long*)(buffer + 4) + 8;
	if (*(long*)(buffer + 8) != 'EVAW') return;
	size_t fmtIndex = 0;
	size_t fmtLength = 0;
	if (!getChunk(' tmf', ptr.get(), length, fmtIndex, fmtLength)) return;
	size_t dataIndex = 0;
	size_t dataSize = 0;
	if (!getChunk('atad', ptr.get(), length, dataIndex, dataSize)) return;
	memcpy_s(&fmt, sizeof(WAVEFORMATEXTENSIBLE), (char*)ptr.get() + fmtIndex, fmtLength);
	data.pAudioData = (const BYTE*)(ptr.get() + dataIndex);
	data.AudioBytes = dataSize;
	data.PlayBegin = 0;
	data.PlayLength = 0;
	data.Flags = XAUDIO2_END_OF_STREAM;
	data.pContext = this;

	XAUDIO2_SEND_DESCRIPTOR sendDesc[] = {
		{0, game::core::GameManager::Current()->audio.pMasterVoice}
	};
	XAUDIO2_VOICE_SENDS sends{};
	sends.SendCount = sizeof(sendDesc)/sizeof(sendDesc[0]);
	sends.pSends = sendDesc;
	//fmt.Format.nChannels = 1;
	//fmt.Format.nBlockAlign = 4;
	hr = pXAudio2->CreateSourceVoice(&pSourceVoice, (WAVEFORMATEX*)&fmt, 0, XAUDIO2_DEFAULT_FREQ_RATIO, this, &sends, NULL);
	if (FAILED(hr))
		std::cout << "XAUDIO ERROR : AUDIOCLIP CONSTRUCTOR : " << std::hex << hr << std::endl;
	hr = pSourceVoice->SubmitSourceBuffer(&data);
	if (FAILED(hr))
		std::cout << "XAUDIO ERROR : AUDIOCLIP CONSTRUCTOR : " << std::hex << hr << std::endl;
}
std::shared_ptr<char> game::core::readFile(const char* path, size_t* out_Size, bool isBinary = false) {
	std::fstream stream = std::fstream(path, (isBinary ? std::ios::binary : 0) | std::ios::in);
	if (!stream) return nullptr;
	stream.seekg(0, stream.end);
	size_t length = stream.tellg();
	stream.seekg(0, stream.beg);
	if (out_Size) *out_Size = length;
	char* c = new char[length + 1];
	stream.read(c, length);
	c[length] = 0;
	return std::shared_ptr<char>{c};
}
game::audio::AudioClip::~AudioClip() {
	CloseHandle(hBufferEndEvent);
}
void game::audio::AudioClip::OnStreamEnd() {
	SetEvent(hBufferEndEvent);
	playing = false;
}
bool game::audio::AudioClip::isPlaying() const {
	return playing;
}
bool game::audio::AudioClip::Play(float volume) {
	playing = true;
	HRESULT hr = pSourceVoice->Start(0);
	if (FAILED(hr))
		return true;
	return false;
}

game::component::AudioSource::AudioSource() noexcept {
	
}
void game::component::AudioSource::Update() {
	if (autoDelete && clip && !isPlaying())selfObject()->Destroy();
}

bool game::component::AudioSource::isPlaying() {
	return clip && clip->isPlaying();
}
game::component::AudioSource::AudioSource(std::shared_ptr<game::audio::AudioClip> clip, bool autoDelete, bool startPlaying) noexcept {
	this->clip = clip;
	this->autoDelete = autoDelete;
	if(startPlaying) this->clip->Play(1);
}
game::core::GameObject game::component::AudioSource::PlayClip(std::shared_ptr<game::audio::AudioClip> clip) {
	game::core::GameObject obj{};
	obj.AddComponent(AudioSource(clip));
	return obj;
}