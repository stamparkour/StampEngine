//stamp/engine/module.h

#pragma once
#ifndef STAMP_ENGINE_MODULE_H
#define STAMP_ENGINE_MODULE_H

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
#include <stamp/core/coroutine.h>

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



// irunnablescene
// irenderablescene

class module_manager : public STAMP_CORE_NAMESPACE::enable_threadsafe_from_this<module_manager>, STAMP_CORE_NAMESPACE::INonCopyable {
	friend class IModule;
	friend const STAMP_CORE_NAMESPACE::threadsafe_ptr<module_manager>& global_module_manager_instance();
public:
	template<std::derived_from<class IModule> T>
	class SceneTypeIterator {
		friend class module_manager;
	public:
		using iterator_category = std::forward_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = STAMP_CORE_NAMESPACE::threadsafe_ptr<T>;
		using pointer = value_type*;  // or also value_type*
		using reference = value_type&;  // or also value_type&
	private:
		using iterator_type = std::vector<STAMP_CORE_NAMESPACE::threadsafe_ptr<IModule>>::iterator;
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
	static inline STAMP_CORE_NAMESPACE::threadsafe_ptr<module_manager> instance = nullptr;
	STAMP_CORE_NAMESPACE::lockable<std::vector<STAMP_CORE_NAMESPACE::threadsafe_ptr<IModule>>> modules{};
	STAMP_CORE_NAMESPACE::coroutine_queue* renderQueue = nullptr;
	STAMP_CORE_NAMESPACE::co_thread_pool* threadPool = nullptr;
public:
	module_manager(STAMP_CORE_NAMESPACE::coroutine_queue* rq, STAMP_CORE_NAMESPACE::co_thread_pool* tp) {
		STAMPASSERT(instance == nullptr, "stamp::engine::SceneManger - existing scene manager present before construction");
		instance = threadsafe_from_this();
		renderQueue = rq;
		threadPool = tp;
	}

	STAMP_CORE_NAMESPACE::awaitable<void, STAMP_CORE_NAMESPACE::coroutine_queue> await_render(bool run_next = false) {
		return { renderQueue, run_next };
	}
	STAMP_CORE_NAMESPACE::awaitable<void, STAMP_CORE_NAMESPACE::co_thread_pool> await(bool run_next = false) {
		return { threadPool, run_next };
	}

	template<std::derived_from<IModule> T, typename... Args>
	STAMP_CORE_NAMESPACE::weak_threadsafe_ptr<T> register_scene(Args&... args) {
		auto scene = STAMP_CORE_NAMESPACE::make_threadsafe<T>(args...);
		STAMP_CORE_NAMESPACE::threadsafe_ptr<IModule> s = STAMP_CORE_NAMESPACE::static_pointer_cast<class IModule>(scene);
		{
			auto lock = modules.get_unique_lock();
			modules.push_back(s);
		}
		s.get_unsafe()->OnModuleOpen();
		return scene;
	}

	bool unregister_scene(STAMP_CORE_NAMESPACE::threadsafe_ptr<IModule> scene) {
		bool found = false;
		{
			auto lock = modules.get_unique_lock();
			auto it = std::find(modules.begin(), modules.end(), scene);
			if (it != modules.end()) {
				modules.erase(it);
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
		return SceneTypeIterator<T>(modules->begin(), modules->end());
	}

	template<typename T>
	size_t count() {
		size_t c = 0;
		for (auto& s : find<T>()) c++;
		return c;
	}
	size_t size() const {
		return modules.size();
	}

	auto begin() {
		auto lock = modules.get_unique_lock();
		return modules.begin();
	}
	auto end() {
		auto lock = modules.get_unique_lock();
		return modules.end();
	}
};
inline const STAMP_CORE_NAMESPACE::threadsafe_ptr<module_manager>& global_module_manager_instance() {
	return module_manager::instance;
}
inline const STAMP_CORE_NAMESPACE::threadsafe_ptr<module_manager>& global_module_manager = global_module_manager_instance();

class IModule : public STAMP_CORE_NAMESPACE::enable_threadsafe_from_this<IModule> {
	friend class module_manager;
private:
	static inline thread_local STAMP_CORE_NAMESPACE::threadsafe_ptr<IModule> currentModule = nullptr;
	std::atomic_bool isActive = true;
protected:
	IModule() {}

	virtual void OnModuleOpen() = 0;
	virtual void OnModuleClose() = 0;
public:
	virtual ~IModule() {
		CloseModule();
	}
	bool IsSceneActive() {
		return isActive.load();
	}
	void CloseModule() {
		if (!isActive) return;
		isActive = false;
		global_module_manager.get()->unregister_scene(threadsafe_from_this());
		OnModuleClose();
	}
};


// implementation


STAMP_ENGINE_NAMESPACE_END

#endif
