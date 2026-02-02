cmake_minimum_required(VERSION 3.16)
include(FetchContent)

#source files
set(STAMP_SERIALIZE_SOURCES
    "src/source.cpp"
)
set(STAMP_SERIALIZE_HEADERS
	"include/stamp/serialize/resource_context.h"
	"include/stamp/serialize/serialize_traits.h"
	"include/stamp/serialize/concepts.h"
)

# add the library
add_library(serialize STATIC ${STAMP_SERIALIZE_SOURCES} ${STAMP_SERIALIZE_HEADERS})
add_library(stamp::serialize ALIAS serialize)
target_compile_features(serialize PRIVATE cxx_std_23)

# adds a directory to search when finding header files
target_include_directories(serialize 
	PUBLIC "include" 
	PUBLIC "${stamp_BINARY_DIR}/serialize/include" 
	PRIVATE "./"
)

target_link_libraries(serialize PUBLIC 
	stamp::core
)

message("Finding package Boost library...")
include(boost)
target_link_libraries(serialize PUBLIC 
	Boost::asio
	Boost::filesystem
	Boost::thread
	Boost::program_options
)

configure_file("include/stamp/serialize/config.h.in" "include/stamp/serialize/config.h")