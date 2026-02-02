include(FetchContent)

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