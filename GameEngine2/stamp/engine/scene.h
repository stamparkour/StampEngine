//stamp/graphics/color.h

#pragma once
#ifndef STAMP_ENGINE_SCENE_H
#define STAMP_ENGINE_SCENE_H

// Copyright 2025 Elijah Clark, Stamparkour
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#include <vector>
#include <concepts>
#include <thread>
#include <functional>
#include <queue>

#include <stamp/engine/define.h>
#include <stamp/core/noncopyable.h>
#include <stamp/core/memory.h>
#include <stamp/core/time.h>

STAMP_ENGINE_NAMESPACE_BEGIN

//scene manager
//base scene class
//render to screenbased scene
//object-based scene
//game object
//components
//
//basic scene attached to all windows that allow rendering to screen and transforming render rect

using scene_state_t = int;
namespace scene_state {
	enum : scene_state_t {
		Uninitialized,
		Opened,
		Running,
		Closed,
		Error,
	};
}

using queue_priority_t = int;
namespace queue_priority {
	enum : queue_priority_t {
		Low,
		Normal,
		High,
	};
}

namespace scene {
	class STAMP_CORE_NAMESPACE::threadsafe_ptr<class IScene> Current();
}

class SceneManager : public STAMP_CORE_NAMESPACE::enable_threadsafe_from_this<SceneManager>, STAMP_CORE_NAMESPACE::INonCopyable  {
	friend class IScene;

	static inline SceneManager* globalSceneManager = nullptr;
	STAMP_CORE_NAMESPACE::lockable<std::vector<STAMP_CORE_NAMESPACE::threadsafe_ptr<IScene>>> scenes;
public:
	SceneManager(int workerThreadsCount = 1) {
		globalSceneManager = this;
	}

	template<std::derived_from<class IScene> T, typename... Args>
	STAMP_CORE_NAMESPACE::threadsafe_ptr<class IScene> RegisterScene(Args&... args) {
		auto scene = STAMP_CORE_NAMESPACE::make_threadsafe<T>(args...);

		{
			auto lock = scenes.get_unique_lock();
			scenes->push_back(scene);
		}

		return scene;
	}


};

class SceneFixedUpdateTask : public STAMP_CORE_NAMESPACE::enable_threadsafe_from_this<SceneFixedUpdateTask>, STAMP_CORE_NAMESPACE::INonCopyable {
	friend class IScene;
	std::thread thread;
	std::function<bool(double)> func;
	std::chrono::high_resolution_clock::time_point prevTime;

	std::chrono::microseconds interval;
	double intervald;
	
	std::atomic_bool isActive = true;

	SceneFixedUpdateTask(std::function<bool(double)> func, double interval) {
		this->func = func;
		this->interval = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::duration<double>(interval));
		this->intervald = interval;
		prevTime = std::chrono::high_resolution_clock::now();
		thread = std::thread{ &SceneFixedUpdateTask::task, this };
	}

	void task() {
		auto ptr = threadsafe_from_this(); // keep the object alive for the duration of the task

		double deltaTime = intervald;
		try {
			while (isActive) {
				if (!func(deltaTime)) break;

				std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
				if (now < prevTime + interval) {
					std::this_thread::sleep_until(prevTime + interval);
					prevTime += interval;
					deltaTime = intervald;
				}
				else {
					deltaTime = std::chrono::duration<double>(now - prevTime).count();
					prevTime = now;
				}

				//should see time for sleep until and verify return time

				//sleep_until a little before next wake and then spin until correct time

			}
		}
		catch (std::exception& e) {
			STAMPDMSG("stamp::engine::SceneFixedUpdateTask - " << e.what());
		}

		isActive = false;
	}
public:
	void Stop() {
		isActive = false;
	}
	bool IsActive() {
		return isActive;
	}
};

class IScene : public STAMP_CORE_NAMESPACE::enable_threadsafe_from_this<IScene> {
	friend class SceneManager;

	std::thread thread;

	long long prevUpdateTime = 0;
	long long prevRenderTime = 0;

	scene_state_t state = scene_state::Uninitialized;

protected:
	IScene() {
	}

	virtual void Open() = 0;
	virtual void Close() = 0;


	SceneFixedUpdateTask RegesterFixedUpdate(float interval, const std::function<bool(float)>& func) {
		double prevTime = STAMP_NAMESPACE::time::getTimeRaw();

	}
public:
	virtual ~IScene() = 0;
	virtual bool IsAlive() = 0;

};

class IRunnableScene : public IScene, public STAMP_CORE_NAMESPACE::enable_threadsafe_from_this_derived<IRunnableScene, IScene> {
	friend class SceneManager;

	std::thread thread;

	long long prevUpdateTime = 0;
	long long prevRenderTime = 0;

	scene_state_t state = scene_state::Uninitialized;

	void task() {
		Open();
		state = scene_state::Running;

		while (state == scene_state::Running) {

		}
	}
protected:
	IRunnableScene() {
		thread = std::thread{ &IRunnableScene::task, this };
	}
	
	virtual void Open() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(float deltaTime) = 0;
	virtual void Close() = 0;


public:
	virtual ~IRunnableScene() = 0;
	virtual bool IsAlive() = 0;

};

STAMP_ENGINE_NAMESPACE_END

#endif
