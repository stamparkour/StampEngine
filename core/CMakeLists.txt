cmake_minimum_required(VERSION 3.16)
include(FetchContent)

#source files
set(STAMP_CORE_SOURCES
	"src/source.cpp"
)
set(STAMP_CORE_HEADERS
)

# add the library
add_library(core STATIC ${STAMP_CORE_SOURCES} ${STAMP_CORE_HEADERS})
add_library(stamp::core ALIAS core)
target_compile_features(core PRIVATE cxx_std_23)

# adds a directory to search when finding header files
target_include_directories(core 
	PUBLIC "include" 
	PUBLIC "${stamp_BINARY_DIR}/core/include" 
	PRIVATE "./"
)

# dependencies
set(BUILD_SHARED_LIBS ON)

# boost
message("Finding package Boost library...")
include(boost)
target_link_libraries(core PUBLIC 
	Boost::asio
	Boost::filesystem
	Boost::thread
	Boost::program_options
)

#glew
message("Fetching GLEW library...")
include(glew)
target_link_libraries(core PUBLIC glew_s)

#glfw
message("Fetching GLFW library...")
include(glfw)
target_link_libraries(core PUBLIC glfw)

# deer imgui
message("Fetching Deer Imgui library...")
include(deerimgui)
target_link_libraries(core PUBLIC deerimgui)

#miniaudio
message("Fetching MiniAudio library...")
include(miniaudio)
target_link_libraries(core PUBLIC miniaudio)

# moody camel concurrent queue
message("Fetching MoodyCamel Concurrent Queue library...")
include(concurrentqueue)
target_link_libraries(core PUBLIC concurrentqueue)

# set the configure file for the project

configure_file("include/stamp/core/config.h.in" "include/stamp/core/config.h")
