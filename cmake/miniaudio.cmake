message("importing miniaudio...")

FetchContent_Declare(
	miniaudio 
	GIT_REPOSITORY https://github.com/mackron/miniaudio.git
	GIT_TAG origin/master # should change to explicit commit
	# DOWNLOAD_EXTRACT_TIMESTAMP ON
)

set(BUILD_SHARED_LIBS OFF)
FetchContent_MakeAvailable(miniaudio)
set(BUILD_SHARED_LIBS ON)

if(miniaudio_POPULATED)
	message("miniaudio found!")
else()
	message("failed to find miniaudio")
endif()
