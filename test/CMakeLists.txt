cmake_minimum_required(VERSION 3.16)
include(FetchContent)

#source files
set(PROJECT_SOURCES
	"src/source.cpp"
)
set(PROJECT_HEADERS
	"src/core_tests.h"
	"src/diagnose_test.h"
	"src/math_test.h"
	"src/reflect_test.h"
	"src/serialize_test.h"
	"src/signal_test.h"
)

# add the executable
add_executable(stamp_test ${PROJECT_SOURCES} ${PROJECT_HEADERS})
target_compile_features(stamp_test PRIVATE cxx_std_23)
target_link_libraries(stamp_test stamp::stamp)

# dependencies
set(BUILD_SHARED_LIBS ON)

include(gtest)
target_link_libraries(stamp_test GTest::gtest_main)


#google test required lines
include(GoogleTest)
gtest_discover_tests(stamp_test)