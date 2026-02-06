cmake_minimum_required(VERSION 3.16)
include(FetchContent)

#source files
set(STAMP_DIAGNOSE_SOURCES
	"src/source.cpp"
)
set(STAMP_DIAGNOSE_HEADERS
)

# add the library
add_library(diagnose STATIC ${STAMP_DIAGNOSE_SOURCES} ${STAMP_DIAGNOSE_HEADERS})
add_library(stamp::diagnose ALIAS diagnose)
target_compile_features(diagnose PUBLIC cxx_std_23)

target_link_libraries(diagnose PUBLIC imgui)

# adds a directory to search when finding header files
target_include_directories(diagnose 
	PUBLIC "include" 
)

include(imgui)
target_link_libraries(diagnose PUBLIC imgui)
