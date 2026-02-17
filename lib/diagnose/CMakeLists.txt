include(FetchContent)

#source files
set(STAMP_DIAGNOSE_SOURCES
	"src/diagnose.cpp"
)
set(STAMP_DIAGNOSE_HEADERS
	"include/stamp/diagnose.h"
 "include/stamp/diagnose/dynamic_type.h")

# add the library
add_library(stamp_diagnose STATIC ${STAMP_DIAGNOSE_SOURCES} ${STAMP_DIAGNOSE_HEADERS})
add_library(stamp::diagnose ALIAS stamp_diagnose)
target_link_libraries(stamp_diagnose PUBLIC stamp::core stamp::reflect)
target_compile_features(stamp_diagnose PUBLIC cxx_std_20)

# adds a directory to search when finding header files
target_include_directories(stamp_diagnose 
	PUBLIC "include" 
)

include(glew)
include(glfw)
include(imgui)
target_link_libraries(stamp_diagnose PUBLIC imgui)
