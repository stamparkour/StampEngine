include(FetchContent)

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