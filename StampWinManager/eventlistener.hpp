#pragma once
#include <mutex>
#include "SWM.hpp"


template<class... P>
class EventListener {
	std::mutex mutex;
	std::vector<void (*)(P...)> ptr{};
public:
	bool subscribe(void (*callback)(P...));
	bool unsubscribe(void (*callback)(P...));
	bool hasCallback(void (*callback)(P...));
	void operator() (P... p);
	void call(P... p) { (*this)(p...); }
};

template<class ...P>
bool EventListener<P...>::subscribe(void(*callback)(P...)) {
	mutex.lock();
	ptr.push_back(callback);
	mutex.unlock();
	return true;
}
template<class ...P>
bool EventListener<P...>::unsubscribe(void(*callback)(P...)) {
	mutex.lock();
	for (int i = 0; i < ptr.size(); i++) {
		if (ptr[i] == callback) {
			ptr.erase(ptr.begin() + i);
			mutex.unlock();
			return true;
		}
	}
	mutex.unlock();
	return false;
}
template<class ...P>
bool EventListener<P...>::hasCallback(void(*callback)(P...)) {
	mutex.lock();
	for (int i = 0; i < ptr.size(); i++) {
		if (ptr[i] == callback) {
			mutex.unlock();
			return true;
		}
	}
	mutex.unlock();
	return false;
}
template<class ...P>
void EventListener<P...>::operator()(P... p) {
	mutex.lock();
	for (int i = 0; i < ptr.size(); i++) {
		ptr[i](p...);
	}
	mutex.unlock();
}
