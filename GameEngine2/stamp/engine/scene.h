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
	std::vector<STAMP_NAMESPACE::threadsafe_ptr<class IScene>> sceneList{};
	std::vector<std::thread> workerThreads{};
	STAMP_NAMESPACE::lockable<std::priority_queue<std::pair<queue_priority_t, std::function<void()>>>> taskQueue{};
	std::condition_variable taskCondition{};

	void EnqueueTask(std::function<void()>& task, queue_priority_t priority = queue_priority::Normal) {
		std::lock_guard lock(taskQueue);
		taskQueue.emplace(priority, task);
	}

	void ThreadWorker() {
		while (true) {
			std::function<void()> task;
			{
				std::unique_lock lock = taskQueue.unique_lock();
				if (taskQueue.empty()) {
					taskCondition.wait(lock);
				}
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
		workerThreads.reserve(workerThreadsCount);
		for (int i = 0; i < workerThreadsCount; i++) {
			
		}
	}

	template<std::derived_from<class IScene> T, typename... Args>
	STAMP_NAMESPACE::threadsafe_ptr<class IScene> RegisterScene(Args&... args) {
		auto scene = STAMP_NAMESPACE::make_threadsafe<T>(args...);
		sceneList.push_back(scene);
		return scene;
	}


};

class IScene {
	friend class SceneManager;

	scene_state_t state = scene_state::Uninitialized;

	void OpenTask() {

	}
protected:
	IScene() {}
	
	virtual void Open() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(float deltaTime) = 0;
	virtual void Close() = 0;
public:
	virtual ~IScene() = 0;
	virtual bool IsAlive() = 0;

	void RegesterFixedUpdate(float interval, std::function<float>& func);
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
