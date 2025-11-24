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
#include <stamp/noncopyable.h>
#include <stamp/memory.h>
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
		Standby,
		Closed,
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
	class STAMP_NAMESPACE::threadsafe_ptr<class IScene> Current();
}

class SceneManager : public STAMP_NAMESPACE::enable_threadsafe_from_this<SceneManager>, STAMP_NAMESPACE::INonCopyable  {
	friend class IScene;

	struct taskItem_t {
		queue_priority_t priority;
		std::function<void()> second;
		taskItem_t(queue_priority_t p, const std::function<void()>& f) : priority(p), second(f) {}

		bool operator <(const taskItem_t& other) const {
			return priority < other.priority;
		}
	};

	static inline SceneManager* globalSceneManager = nullptr;


	std::vector<STAMP_NAMESPACE::threadsafe_ptr<class IScene>> sceneList{};
	std::vector<std::thread> workerThreads{};
	STAMP_NAMESPACE::lockable<std::priority_queue<taskItem_t>> taskQueue{ };
	std::condition_variable_any taskCondition{};

	void EnqueueTask(const std::function<void()>& task, queue_priority_t priority = queue_priority::Normal) {
		std::lock_guard lock(taskQueue);
		taskQueue.emplace(priority, task);
		taskCondition.notify_one();
	}

	void ThreadWorker() {
		while (true) {
			std::function<void()> task;
			{
				std::unique_lock lock{ taskQueue };
				taskCondition.wait(lock, [&]() -> bool {
					return !taskQueue.empty();
				});
				task = taskQueue.top().second;
				taskQueue.pop();
			}
			if (task) {
				task();
			}
		}
	}
public:
	SceneManager(int workerThreadsCount = 1) {
		globalSceneManager = this;
		workerThreads.reserve(workerThreadsCount);
		for (int i = 0; i < workerThreadsCount; i++) {
			workerThreads.emplace_back(&SceneManager::ThreadWorker, this);
		}
	}

	template<std::derived_from<class IScene> T, typename... Args>
	STAMP_NAMESPACE::threadsafe_ptr<class IScene> RegisterScene(Args&... args) {
		auto scene = STAMP_NAMESPACE::make_threadsafe<T>(args...);
		sceneList.push_back(scene);
		EnqueueTask([scene]() {
			scene->Open_task();
		});
		return scene;
	}


};

class SceneFixedUpdate : STAMP_NAMESPACE::INonCopyable {

};

class IScene : public STAMP_NAMESPACE::enable_threadsafe_from_this<IScene> {
	friend class SceneManager;

	long long prevUpdateTime = 0;
	long long prevRenderTime = 0;

	scene_state_t state = scene_state::Uninitialized;

	void Open_task() {
		Open();
		state = scene_state::Opened;
		
	}
	void Update_task() {
		this->state = scene_state::Running;
		long long now = STAMP_NAMESPACE::time::getTimeRaw();

		Update((now - prevUpdateTime) * STAMP_NAMESPACE::time::TimeTickLength());

		prevUpdateTime = now;

		SceneManager::globalSceneManager->EnqueueTask([this]() {
			this->Update_task();
		});
	}
	void Render_action() {
		long long now = STAMP_NAMESPACE::time::getTimeRaw();
		Render((now - prevRenderTime) * STAMP_NAMESPACE::time::TimeTickLength());
		prevRenderTime = now;
	}
protected:
	IScene() {}
	
	virtual void Open() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(float deltaTime) = 0;
	virtual void Close() = 0;


	SceneFixedUpdate RegesterFixedUpdate(float interval, const std::function<bool(float)>& func) {
		double prevTime = STAMP_NAMESPACE::time::getTimeRaw();
		std::function<void()> f = [f, func, prevTime]() mutable {
			double t = STAMP_NAMESPACE::time::getTimeRaw();
			if (!func((t - prevTime) * STAMP_NAMESPACE::time::TimeTickLength())) return;
			prevTime = t; // can be modified because lamda is mutable
			SceneManager::globalSceneManager->EnqueueTask(f);
		};

		SceneManager::globalSceneManager->EnqueueTask(f);
	}
public:
	virtual ~IScene() = 0;
	virtual bool IsAlive() = 0;

};

class DisplayScene : public IScene {
	void Open() override {}
	void Update(float deltaTime) override {}
	void Render(float deltaTime) override {}
	void Close() override {}

public:
	DisplayScene(/* window& w*/) {}
};

STAMP_ENGINE_NAMESPACE_END

#endif
