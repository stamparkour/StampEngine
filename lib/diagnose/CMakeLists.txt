include(FetchContent)

#source files
set(STAMP_DIAGNOSE_SOURCES
	"src/diagnose.cpp"
)
set(STAMP_DIAGNOSE_HEADERS
	"include/stamp/diagnose.h"
)

# add the library
add_library(stamp_diagnose STATIC ${STAMP_DIAGNOSE_SOURCES} ${STAMP_DIAGNOSE_HEADERS})
add_library(stamp::diagnose ALIAS stamp_diagnose)
target_link_libraries(stamp_diagnose PUBLIC stamp::core stamp::reflect)

set_target_properties(stamp_diagnose PROPERTIES 
	CXX_STANDARD 20 
	CXX_STANDARD_REQUIRED ON
)

# adds a directory to search when finding header files
target_include_directories(stamp_diagnose 
	PUBLIC "include" 
)

include(glew)
include(glfw)
include(imgui)
target_link_libraries(stamp_diagnose PUBLIC imgui)
