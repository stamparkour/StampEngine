//stamp/engine/scene.h

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
#include <chrono>

#include <stamp/engine/define.h>
#include <stamp/core/noncopyable.h>
#include <stamp/core/memory.h>
#include <stamp/core/time.h>
#include <stamp/core/taskqueue.h>

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

class SceneFixedUpdateTask : public STAMP_CORE_NAMESPACE::enable_threadsafe_from_this<SceneFixedUpdateTask>, STAMP_CORE_NAMESPACE::INonCopyable {
	STAMP_MEMORY_THREADSAFE_FRIEND;
	friend class IScene;
public:
	using clock_t = std::chrono::high_resolution_clock;
	using timepoint_t = std::chrono::high_resolution_clock::time_point;
private:
	std::thread thread;
	std::function<bool(timepoint_t, double)> func;
	std::function<bool(timepoint_t)> onerror;
	std::chrono::high_resolution_clock::time_point prevTime;

	std::chrono::microseconds interval;
	double intervald;
	
	std::atomic_bool isActive = true;

	STAMP_CORE_NAMESPACE::weak_threadsafe_ptr<IScene> owner;

	SceneFixedUpdateTask(double interval, STAMP_CORE_NAMESPACE::weak_threadsafe_ptr<IScene> owner, std::function<bool(timepoint_t, double)> func, std::function<bool(timepoint_t)> onerror = nullptr) {
		this->func = func;
		this->onerror = onerror;
		this->owner = owner;
		this->interval = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::duration<double>(interval));
		this->intervald = interval;
		thread = std::thread{ &SceneFixedUpdateTask::task, this, threadsafe_from_this() };
	}

	void task(STAMP_CORE_NAMESPACE::threadsafe_ptr<SceneFixedUpdateTask> ptr) {
		// ptr keep the object alive for the duration of the task

		prevTime = clock_t::now();
		double deltaTime = intervald;
		try {
			while (isActive && !owner.expired()) {
				if (!func || !func(prevTime, deltaTime)) break;

				timepoint_t now = clock_t::now();
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
			if(onerror) onerror(prevTime);
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

	std::atomic_bool isActive = true;
protected:
	IScene() {}

	virtual void OnSceneOpen() {}
	virtual void OnSceneClose();

	STAMP_CORE_NAMESPACE::threadsafe_ptr<SceneFixedUpdateTask> RegesterFixedUpdate(const std::function<bool(SceneFixedUpdateTask::timepoint_t, double)>& func, double interval = 1.0/60.0) {
		return STAMP_CORE_NAMESPACE::make_threadsafe<SceneFixedUpdateTask>(interval, STAMP_CORE_NAMESPACE::weak_threadsafe_ptr(threadsafe_from_this()), func);
	}
	void PushRenderTask(const std::function<void()>& func);
public:
	virtual ~IScene() = 0;
	bool IsSceneActive() {
		return isActive.load();
	}
	void Close() {
		if (!isActive) return;
		isActive = false;
		OnSceneClose();
	}
};

class IRunnableScene : public IScene, public STAMP_CORE_NAMESPACE::enable_threadsafe_from_this_derived<IRunnableScene, IScene> {
	friend class SceneManager;

	double interval;
	STAMP_CORE_NAMESPACE::threadsafe_ptr<SceneFixedUpdateTask> mainLoop;

	scene_state_t state = scene_state::Uninitialized;

protected:
	IRunnableScene(double interval = 1.0 / 60.0) : interval(interval) {
		state = scene_state::Opened;
	}
	
	virtual void OnSceneOpen() override {
		IScene::OnSceneOpen();
		state = scene_state::Running;
		mainLoop = RegesterFixedUpdate([this](SceneFixedUpdateTask::timepoint_t now, double deltaTime) {
			OnSceneUpdate(now, deltaTime);
			return state == scene_state::Running;
		}, interval);
	}
	virtual void OnSceneUpdate(SceneFixedUpdateTask::timepoint_t now, double deltaTime) = 0;
	virtual void OnSceneClose() override {
		state = scene_state::Closed;
		mainLoop.get()->Stop();
		IScene::OnSceneClose();
	}


public:
	virtual ~IRunnableScene() {}
};

class IRenderableScene : public IRunnableScene, public STAMP_CORE_NAMESPACE::enable_threadsafe_from_this_derived<IRenderableScene, IRunnableScene> {
private:
	std::atomic_bool isRendering = false;
protected:
	virtual void OnSceneUpdate(SceneFixedUpdateTask::timepoint_t now, double deltaTime) override {
		if (!isRendering) {
			isRendering = true;
			PushRenderTask([this, now, deltaTime]() {
				OnRender(now, deltaTime);
				isRendering = false;
			});
		}
	}
	virtual void OnRender(SceneFixedUpdateTask::timepoint_t now, double deltaTime) {}
public:
	~IRenderableScene()  {}
};

class SceneManager : public STAMP_CORE_NAMESPACE::enable_threadsafe_from_this<SceneManager>, STAMP_CORE_NAMESPACE::INonCopyable {
	friend class IScene;
	friend STAMP_CORE_NAMESPACE::threadsafe_ptr<SceneManager> scene_manager();
public:
	template<std::derived_from<class IScene> T>
	class SceneTypeIterator {
		friend class SceneManager;
	public:
		using iterator_category = std::forward_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = STAMP_CORE_NAMESPACE::threadsafe_ptr<T>;
		using pointer = value_type*;  // or also value_type*
		using reference = value_type&;  // or also value_type&
	private:
		using iterator_type = std::vector<STAMP_CORE_NAMESPACE::threadsafe_ptr<IScene>>::iterator;
		iterator_type current;
		iterator_type end;

		SceneTypeIterator(iterator_type start, iterator_type end) : current(start), end(end) {
			if (STAMP_CORE_NAMESPACE::dynamic_pointer_cast<T>(*current) == nullptr) {
				++(*this);
			}
		}
	public:
		SceneTypeIterator<T>& operator++() {
			while (++current != end) {
				if (STAMP_CORE_NAMESPACE::dynamic_pointer_cast<T>(*current) != nullptr) break;
			}
			return *this;
		}
		SceneTypeIterator<T> operator++(int) {
			SceneTypeIterator<T> tmp = *this;
			++(*this);
			return tmp;
		}
		bool operator==(const SceneTypeIterator<T>& other) const {
			return current == other.current;
		}
		bool operator==(const iterator_type& other) const {
			return current == other;
		}
		STAMP_CORE_NAMESPACE::threadsafe_ptr<T> operator*() const {
			return std::static_pointer_cast<T>(*current);
		}
	};
private:
	static inline STAMP_CORE_NAMESPACE::threadsafe_ptr<SceneManager> instance = nullptr;
	STAMP_CORE_NAMESPACE::lockable<std::vector<STAMP_CORE_NAMESPACE::threadsafe_ptr<IScene>>> scenes{};
	std::atomic_bool isRunning = true;
	STAMP_CORE_NAMESPACE::TaskQueue* renderQueue = nullptr;
public:
	SceneManager(STAMP_CORE_NAMESPACE::TaskQueue* rq) {
		STAMPASSERT(instance == nullptr, "stamp::engine::SceneManger - existing scene manager present before construction");
		instance = threadsafe_from_this();
		renderQueue = rq;
	}

	template<std::derived_from<IScene> T, typename... Args>
	STAMP_CORE_NAMESPACE::weak_threadsafe_ptr<T> RegisterScene(Args&... args) {
		auto scene = STAMP_CORE_NAMESPACE::make_threadsafe<T>(args...);
		STAMP_CORE_NAMESPACE::threadsafe_ptr<IScene> s = STAMP_CORE_NAMESPACE::static_pointer_cast<class IScene>(scene);
		{
			auto lock = scenes.get_unique_lock();
			scenes.push_back(s);
		}
		s.get_unsafe()->OnOpen();
		return scene;
	}

	bool UnregisterScene(STAMP_CORE_NAMESPACE::threadsafe_ptr<IScene> scene) {
		bool found = false;
		{
			auto lock = scenes.get_unique_lock();
			auto it = std::find(scenes.begin(), scenes.end(), scene);
			if (it != scenes.end()) {
				scenes.erase(it);
				found = true;
			}
		}
		if (found) {
			scene.get()->Close();
		}
		return found;
	}

	template<typename T>
	SceneTypeIterator<T> find() {
		return SceneTypeIterator<T>(scenes->begin(), scenes->end());
	}

	template<typename T>
	size_t count() {
		size_t c = 0;
		for (auto& s : find<T>()) c++;
		return c;
	}

	auto begin() {
		auto lock = scenes.get_unique_lock();
		return scenes.begin();
	}
	auto end() {
		auto lock = scenes.get_unique_lock();
		return scenes.end();
	}

	void End() {
		isRunning = false;
	}
};

STAMP_CORE_NAMESPACE::threadsafe_ptr<IScene> this_scene();
STAMP_CORE_NAMESPACE::threadsafe_ptr<SceneManager> scene_manager() {
	return SceneManager::instance;
}

// implementation

void IScene::OnSceneClose() {
	SceneManager::instance.get()->UnregisterScene(threadsafe_from_this());
}
void IScene::PushRenderTask(const std::function<void()>& func) {
	SceneManager::instance.get()->renderQueue->push(func);
}

STAMP_ENGINE_NAMESPACE_END

#endif
