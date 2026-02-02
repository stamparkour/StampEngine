include(FetchContent)

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