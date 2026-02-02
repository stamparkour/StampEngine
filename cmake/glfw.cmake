include(FetchContent)

FetchContent_Declare(
	glfw 
	GIT_REPOSITORY https://github.com/glfw/glfw.git
	GIT_TAG origin/master # should change to explicit commit
)
FetchContent_GetProperties(glfw)
if(NOT glfw_POPULATED)
	FetchContent_MakeAvailable(glfw)
endif()