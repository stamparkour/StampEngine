cmake_minimum_required(VERSION 3.16)

# set the project name
project(stamp VERSION 0.1.0 LANGUAGES C CXX)

#options

#config
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# include subdirectories
add_subdirectory(core)
add_subdirectory(diagnose)
add_subdirectory(math)
add_subdirectory(reflect)
add_subdirectory(serialize)
add_subdirectory(signal)
add_subdirectory(test)


add_library(stamp INTERFACE)
add_library(stamp::stamp ALIAS stamp)
target_link_libraries(stamp INTERFACE stamp::core stamp::math)