include(FetchContent)

#source files
set(STAMP_NETWORK_SOURCES
	"src/source.cpp"
)
set(STAMP_NETWORK_HEADERS
	"include/stamp/network/network.h"
)

# add the library
add_library(stamp_network STATIC ${STAMP_NETWORK_SOURCES} ${STAMP_NETWORK_HEADERS})
add_library(stamp::network ALIAS stamp_network)
target_link_libraries(stamp_network PUBLIC stamp::task)
target_compile_features(stamp_network PUBLIC cxx_std_20)


# adds a directory to search when finding header files
target_include_directories(stamp_network 
	INTERFACE "include" 
)
