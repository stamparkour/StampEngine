#pragma once
#include <Windows.h>
#include <memory>
#include <xaudio2.h>
#include <x3daudio.h>


namespace game::audio {
	struct AudioClip final : IXAudio2VoiceCallback {
	private:
		WAVEFORMATEXTENSIBLE  fmt{};
		XAUDIO2_BUFFER data{};
		IXAudio2SourceVoice* pSourceVoice = nullptr;
		std::shared_ptr<char> ptr = nullptr;
		HANDLE hBufferEndEvent;
		bool playing = false;
	public:
		AudioClip() : hBufferEndEvent(CreateEvent(NULL, FALSE, FALSE, NULL)) {}
		AudioClip(const char* buffer, size_t length);
		~AudioClip();
		bool Play(float volume);
		void OnStreamEnd();
		void OnVoiceProcessingPassEnd() { }
		void OnVoiceProcessingPassStart(UINT32 SamplesRequired) {    }
		void OnBufferEnd(void* pBufferContext) { }
		void OnBufferStart(void* pBufferContext) {    }
		void OnLoopEnd(void* pBufferContext) {    }
		void OnVoiceError(void* pBufferContext, HRESULT Error) { }
		bool isPlaying() const;
	};

	struct AudioManager final {
		friend struct AudioClip;
	private:
		IXAudio2* pXAudio2;
		X3DAUDIO_HANDLE XAudio3d;
		IXAudio2MasteringVoice* pMasterVoice;
	public:
		bool Initialize();
	};
}