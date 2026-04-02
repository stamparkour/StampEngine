include(FetchContent)

#source files
set(STAMP_SERIALIZE_SOURCES
)
set(STAMP_SERIALIZE_HEADERS
)

# add the library
add_library(stamp_serialize INTERFACE ${STAMP_SERIALIZE_SOURCES} ${STAMP_SERIALIZE_HEADERS})
add_library(stamp::serialize ALIAS stamp_serialize)
target_link_libraries(stamp_serialize INTERFACE stamp::core stamp::reflect)
target_compile_features(stamp_serialize INTERFACE cxx_std_20)


# adds a directory to search when finding header files
target_include_directories(stamp_reflect 
	INTERFACE "include" 
)
