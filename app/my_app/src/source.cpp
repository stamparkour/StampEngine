/**
 * @file source.cpp
 * @brief Performance profiling of the StampEngine Coroutine System using Google Benchmark
 */

#include <stamp/task/coroutine.h>
#include <stamp/task/task_queue.h>
#include <stamp/task/thread_pool.h>
#include <benchmark/benchmark.h>
#include <unordered_map>
#include <mutex>
#include <shared_mutex>
#include <chrono>
#include <windows.h>
#include <stamp/task/stream.h>

using namespace stamp::task;

int main(int argc, char** argv) {

}