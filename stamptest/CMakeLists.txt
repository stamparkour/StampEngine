cmake_minimum_required(VERSION 3.16)

#source files
set(STAMP_SOURCES
	"src/source.cpp"
)
set(STAMP_HEADERS

	"include/stamp/service/display.h"
	"include/stamp/service/resource.h"
	"include/stamp/service/network.h"
	"include/stamp/type_traits.h"
	"include/stamp/scene.h"
)

# add the executable
add_executable(stamptest STATIC ${STAMPTEST_SOURCES} ${STAMPTEST_HEADERS})
target_compile_features(stamptest PRIVATE cxx_std_23)

target_link_libraries(stamptest PRIVATE stamp)
