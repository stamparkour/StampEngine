cmake_minimum_required(VERSION 3.16)
include(FetchContent)

#source files
set(STAMP_CORE_SOURCES
	"src/source.cpp"
)
set(STAMP_CORE_HEADERS
	"include/stamp/stamp_config.h.in"
	"include/stamp/core/core.h"
)

# add the library
add_library(core STATIC ${STAMP_CORE_SOURCES} ${STAMP_CORE_HEADERS})
add_library(stamp::core ALIAS core)
target_compile_features(core PUBLIC cxx_std_23)

# adds a directory to search when finding header files
target_include_directories(core 
	PUBLIC "include" 
	PUBLIC "${stamp_BINARY_DIR}/core/include"
)

# dependencies
# include(boost)
# target_link_libraries(core PUBLIC 
# 	Boost::asio
#	Boost::filesystem
#	Boost::thread
#	Boost::program_options
# )

# include(glew)
# target_link_libraries(core PUBLIC glew_s)

# include(glfw)
# target_link_libraries(core PUBLIC glfw)

# include(imgui)
# target_link_libraries(core PUBLIC imgui)

# include(miniaudio)
# target_link_libraries(core PUBLIC miniaudio)

# include(concurrentqueue)
# target_link_libraries(core PUBLIC concurrentqueue)

# set the configure file for the project

configure_file("include/stamp/stamp_config.h.in" "include/stamp/stamp_config.h")
