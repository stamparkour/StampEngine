include(FetchContent)

#source files
set(STAMP_MEMORY_SOURCES
	"src/source.cpp"
)
set(STAMP_MEMORY_HEADERS
	"include/stamp/memory/memory.h"
)

# add the library
add_library(stamp_memory STATIC ${STAMP_MEMORY_SOURCES} ${STAMP_MEMORY_HEADERS})
add_library(stamp::memory ALIAS stamp_memory)
# target_link_libraries(stamp_memory PUBLIC)
target_compile_features(stamp_memory PUBLIC cxx_std_20)


# adds a directory to search when finding header files
target_include_directories(stamp_memory 
	INTERFACE "include" 
)
