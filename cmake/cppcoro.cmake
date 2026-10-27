

message("importing cppcoro...")

FetchContent_Declare(
	cppcoro 
	GIT_REPOSITORY https://github.com/andreasbuhr/cppcoro.git
	GIT_TAG origin/main # should change to explicit commit
	DOWNLOAD_EXTRACT_TIMESTAMP ON
	FIND_PACKAGE_ARGS
)

set(BUILD_SHARED_LIBS OFF)
FetchContent_MakeAvailable(cppcoro)

if(cppcoro_POPULATED)
	message("cppcoro found!")
else()
	message("failed to find cppcoro")
endif()
