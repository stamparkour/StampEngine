#include <iostream>
#include <stamp/task/coroutine.h>
#include <stamp/task/task_queue.h>
#include <thread>

using namespace stamp::task;

coroutine<int> get_msg() {
	int i = 0;
	while (true) {
		std::this_thread::sleep_for(std::chrono::duration<float, std::chrono::seconds::period>(0.01203));
		std::cout << "hello " << i << std::endl;
		co_yield i;
		i++;
	}

	co_return 0;
}

coroutine<void> test(const coroutine<void>& trigger, const char* message) {
	while (!trigger.done()) {
		co_await trigger;
		std::cout << message << std::endl;
	}
	co_return;
}

int main(int argc, char** argv) {

	auto coro_pair = co_dispatch_thread(get_msg);

	coroutine<void> coro = std::move(coro_pair.first);
	coro_pair.second();
	std::this_thread::sleep_for(std::chrono::duration<float, std::chrono::seconds::period>(0.1));
	auto c1 = test(coro, "hello world!").start();

	auto c2 = test(c1, "cheese!").start();

	std::this_thread::sleep_for(std::chrono::duration<float, std::chrono::seconds::period>(1));
	coro.kill();
	std::cout << "killed!" << std::endl;
	coro.wait();
	std::cout << "ended!" << std::endl;

	return 0;
}
