include(FetchContent)

#source files
set(PROJECT_SOURCES
	"src/source.cpp"
)
set(PROJECT_HEADERS
)


# add the executable
add_executable(my_app ${PROJECT_SOURCES} ${PROJECT_HEADERS})
target_link_libraries(my_app PUBLIC stamp::stamp)

set_target_properties(my_app PROPERTIES 
	CXX_STANDARD 20 
	CXX_STANDARD_REQUIRED ON
)