include(FetchContent)

#source files
set(PROJECT_SOURCES
	"src/source.cpp"
)
set(PROJECT_HEADERS
)


# add the executable
add_executable(task_benchmark ${PROJECT_SOURCES} ${PROJECT_HEADERS})
target_link_libraries(task_benchmark PUBLIC stamp::stamp)
target_compile_features(task_benchmark PUBLIC cxx_std_20)

include(gtest)
include(benchmark)
target_link_libraries(task_benchmark PUBLIC  GTest::gtest_main benchmark::benchmark_main)