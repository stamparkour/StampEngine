cmake_minimum_required(VERSION 3.16)
include(FetchContent)

#source files
set(STAMP_MATH_SOURCES
)
set(STAMP_DIAGNOSE_HEADERS
	"include/stamp/math/cayley_dickson.h"
	"include/stamp/math/tuple_base.h"
)

# add the library
add_library(math STATIC ${STAMP_MATH_SOURCES} ${STAMP_DIAGNOSE_HEADERS})
add_library(stamp::math ALIAS math)
target_compile_features(math PUBLIC cxx_std_23)

# adds a directory to search when finding header files
target_include_directories(math 
	PUBLIC "include" 
)

include(imgui)
target_link_libraries(math PUBLIC imgui)
