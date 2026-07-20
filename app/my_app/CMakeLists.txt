include(FetchContent)

#source files
set(PROJECT_SOURCES
	"src/source.cpp"
	"src/source2.cpp"
)
set(PROJECT_HEADERS
)


# add the executable
add_executable(my_app ${PROJECT_SOURCES} ${PROJECT_HEADERS})
target_link_libraries(my_app PUBLIC stamp::stamp)
target_compile_features(my_app PUBLIC cxx_std_20)

include(gtest)
include(benchmark)
target_link_libraries(my_app PUBLIC  GTest::gtest_main benchmark::benchmark_main)