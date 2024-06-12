#pragma once
#include <Windows.h>
#include <memory>
#include <xaudio2.h>
#include <x3daudio.h>
#include "glmath.h"
#include <vector>

namespace game::audio {
	struct AudioPlayback : IXAudio2VoiceCallback {
		struct AudioData {
			std::shared_ptr<char> clip;
			IXAudio2SourceVoice* source;
		};
		std::vector<AudioData> data;
		HANDLE hBufferEndEvent;
		bool playing = false;

		void OnStreamEnd();
		void OnVoiceProcessingPassEnd() { }
		void OnVoiceProcessingPassStart(UINT32 SamplesRequired) { }
		void OnBufferEnd(void* pBufferContext) { }
		void OnBufferStart(void* pBufferContext) { }
		void OnLoopEnd(void* pBufferContext) { }
		void OnVoiceError(void* pBufferContext, HRESULT Error) { }
		bool isPlaying() const;
		void play();

		AudioPlayback() : hBufferEndEvent(CreateEvent(NULL, FALSE, FALSE, NULL)) {}
		AudioPlayback(std::vector<std::shared_ptr<char>> clip, WAVEFORMATEXTENSIBLE* format, XAUDIO2_BUFFER* buffer);
		~AudioPlayback();
	};
	struct AudioClip final  {
	private:

		WAVEFORMATEXTENSIBLE  fmt{};
		std::vector<std::shared_ptr<char>> clip;
		std::shared_ptr<char> ptr = nullptr;
		XAUDIO2_BUFFER buffer{};
	public:
		AudioClip() {}
		AudioClip(std::shared_ptr<char> buf, size_t length);
		~AudioClip();
		AudioPlayback play();
		AudioPlayback init();
	};


	struct AudioManager final : IXAudio2EngineCallback {
		friend struct AudioClip;
		friend struct AudioListener;
		friend struct AudioPlayback;
	private:
		void OnCriticalError(HRESULT Error);
		void OnProcessingPassEnd() {}
		void OnProcessingPassStart() {}

		IXAudio2* pXAudio2;
		X3DAUDIO_HANDLE XAudio3d;
		X3DAUDIO_LISTENER XAudio3dListener;
		IXAudio2MasteringVoice* pMasterVoice;

		std::vector<IXAudio2SourceVoice*> sourceVoices{};
		game::math::Vec3 prevPosition;

		IXAudio2SourceVoice* NewSourceVoice(const WAVEFORMATEX* format, IXAudio2VoiceCallback* callback);
		void SyncUpdate();
	public:
		bool Initialize();
		void SetListenerPosition();
	};
}