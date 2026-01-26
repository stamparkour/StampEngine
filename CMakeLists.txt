cmake_minimum_required(VERSION 3.16)

# set the project name
project(stamp VERSION 0.1.0.0 LANGUAGES C CXX)

#options
option(STAMP_TEST_BUILD_EXECUTABLE "Set to ON to build the test executable" OFF)

# include subdirectories
add_subdirectory(stamp)
if(STAMP_TEST_BUILD_EXECUTABLE)
	add_subdirectory(stamptest)
endif()