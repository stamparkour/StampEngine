include(FetchContent)

#source files
set(PROJECT_SOURCES
	"src/source.cpp"
	"src/reflect_test.cpp"
	"src/diagnose_test.cpp"
	"src/task_test.cpp"
)
set(PROJECT_HEADERS
	"src/core_tests.h"
	"src/math_test.h"
	"src/serialize_test.h"
	"src/signal_test.h"
)


# add the executable
add_executable(stamp_test ${PROJECT_SOURCES} ${PROJECT_HEADERS})
target_link_libraries(stamp_test PUBLIC stamp::stamp)

enable_testing() # Enable testing in CMake

include(gtest)
target_link_libraries(stamp_test PUBLIC GTest::gtest_main)


#google test required lines
include(GoogleTest)
gtest_discover_tests(stamp_test)