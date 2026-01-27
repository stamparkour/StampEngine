cmake_minimum_required(VERSION 3.16)
include(FetchContent)

#source files
set(STAMP_SOURCES
	"src/source.cpp"
)
set(STAMP_HEADERS

	"include/stamp/service/display.h"
	"include/stamp/service/resource.h"
	"include/stamp/service/network.h"
	"include/stamp/type_traits.h"
	"include/stamp/scene.h"
)

# add the library
add_library(stamp STATIC ${STAMP_SOURCES} ${STAMP_HEADERS})
target_compile_features(stamp PRIVATE cxx_std_23)

# adds a directory to search when finding header files
target_include_directories(stamp 
	PUBLIC "include/" 
	PUBLIC "${stamp_BINARY_DIR}/stamp/include/" 
	PRIVATE "src/"
)

# dependencies
set(BUILD_SHARED_LIBS ON)

# boost
message("Finding package Boost library...")
find_package(Boost 1.90.0 CONFIG)
if(NOT Boost_FOUND)
	message("Boost not found")
	message("Fetching Boost library...")
	FetchContent_Declare(
		Boost
		URL https://github.com/boostorg/boost/releases/download/boost-1.90.0/boost-1.90.0-cmake.tar.xz
		URL_HASH SHA256=aca59f889f0f32028ad88ba6764582b63c916ce5f77b31289ad19421a96c555f
		DOWNLOAD_EXTRACT_TIMESTAMP ON
	)
	FetchContent_GetProperties(Boost)
	if(NOT Boost_POPULATED)
		message("Populating Boost library...")
		FetchContent_MakeAvailable(Boost)
	endif()
endif()

target_link_libraries(stamp PUBLIC 
	Boost::asio
	Boost::filesystem
	Boost::thread
	Boost::program_options
)

#eigen
message("Fetching Eigen library...")
FetchContent_Declare(
	eigen 
	GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git 
	GIT_TAG origin/5.0
)
FetchContent_GetProperties(eigen)
if(NOT eigen_POPULATED)
	FetchContent_MakeAvailable(eigen)
endif()
target_link_libraries(stamp PUBLIC eigen)

#glew
message("Fetching GLEW library...")
FetchContent_Declare(
	glew 
	URL https://github.com/nigels-com/glew/releases/download/glew-2.3.1/glew-2.3.1.tgz
	URL_HASH SHA256=b64790f94b926acd7e8f84c5d6000a86cb43967bd1e688b03089079799c9e889
	DOWNLOAD_EXTRACT_TIMESTAMP ON
)
FetchContent_GetProperties(glew)
if(NOT glew_POPULATED)
	FetchContent_MakeAvailable(glew)
	add_subdirectory(${glew_SOURCE_DIR}/build/cmake ${glew_BINARY_DIR})
	target_include_directories(glew_s PUBLIC ${glew_SOURCE_DIR}/include) # fix to allow for fetchContent
endif()
target_link_libraries(stamp PUBLIC glew_s)

#glfw
message("Fetching GLFW library...")
FetchContent_Declare(
	glfw 
	GIT_REPOSITORY https://github.com/glfw/glfw.git
	GIT_TAG origin/master # should change to explicit commit
)
FetchContent_GetProperties(glfw)
if(NOT glfw_POPULATED)
	FetchContent_MakeAvailable(glfw)
endif()
target_link_libraries(stamp PUBLIC glfw)

# deer imgui
message("Fetching Deer Imgui library...")
FetchContent_Declare(
	deerimgui
	GIT_REPOSITORY https://github.com/ocornut/imgui.git
	GIT_TAG origin/master # should change to explicit commit
	DOWNLOAD_EXTRACT_TIMESTAMP ON
)
FetchContent_GetProperties(deerimgui)
if(NOT deerimgui_POPULATED)
	FetchContent_MakeAvailable(deerimgui)
	file(GLOB DEERIMGUI_BASE_SOURCES "${deerimgui_SOURCE_DIR}/*.cpp")
	set(DEERIMGUI_BACKEND_SOURCES 
		"${deerimgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp"
		"${deerimgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp"
	)
	add_library(deerimgui STATIC ${DEERIMGUI_BASE_SOURCES} ${DEERIMGUI_BACKEND_SOURCES})
	target_include_directories(deerimgui 
		PUBLIC "${deerimgui_SOURCE_DIR}"
	)
	target_link_libraries(deerimgui PUBLIC glfw)
endif()
target_link_libraries(stamp PUBLIC deerimgui)

#miniaudio
message("Fetching MiniAudio library...")
FetchContent_Declare(
	miniaudio 
	GIT_REPOSITORY https://github.com/mackron/miniaudio.git
	GIT_TAG origin/master # should change to explicit commit
)
FetchContent_GetProperties(miniaudio)
if(NOT miniaudio_POPULATED)
	set(BUILD_SHARED_LIBS OFF)
	FetchContent_MakeAvailable(miniaudio)
	set(BUILD_SHARED_LIBS ON)
endif()
target_link_libraries(stamp PUBLIC miniaudio)

# moody camel concurrent queue
message("Fetching MoodyCamel Concurrent Queue library...")
FetchContent_Declare(
	moodycamel_concurrentqueue
	GIT_REPOSITORY https://github.com/cameron314/concurrentqueue.git
	GIT_TAG origin/master # should change to explicit commit
)
FetchContent_GetProperties(moodycamel_concurrentqueue)
if(NOT moodycamel_concurrentqueue_POPULATED)
	FetchContent_MakeAvailable(moodycamel_concurrentqueue)
endif()
target_link_libraries(stamp PUBLIC concurrentqueue)

# set the configure file for the project

configure_file("include/stamp/stamp_config.h.in" "include/stamp/stamp_config.h")
