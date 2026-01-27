cmake_minimum_required(VERSION 3.16)

#source files
set(STAMPTEST_SOURCES
	"src/source.cpp"
)
set(STAMPTEST_HEADERS
)

# uncomment for no gui build for windows
# list(APPEND STAMPTEST_EXECUTABLE_OPTIONS "WIN32")

# add the executable
add_executable(stamptest ${STAMPTEST_EXECUTABLE_OPTIONS} ${STAMPTEST_SOURCES} ${STAMPTEST_HEADERS})
target_compile_features(stamptest PRIVATE cxx_std_23)

message("stamptest linking to stamp")
target_link_libraries(stamptest PRIVATE stamp)
