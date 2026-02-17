include(FetchContent)

#source files
set(STAMP_MATH_SOURCES
	"src/math.cpp"
)
set(STAMP_DIAGNOSE_HEADERS
	"include/stamp/math/cayley_dickson.h"
	"include/stamp/math/tuple_base.h"
)

# add the library
add_library(stamp_math STATIC ${STAMP_MATH_SOURCES} ${STAMP_DIAGNOSE_HEADERS})
add_library(stamp::math ALIAS stamp_math)
target_compile_features(stamp_math PUBLIC cxx_std_20)

# adds a directory to search when finding header files
target_include_directories(stamp_math 
	PUBLIC "include" 
)

include(imgui)
target_link_libraries(stamp_math PUBLIC imgui)
