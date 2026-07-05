include(FetchContent)

#source files
set(STAMP_TASK_SOURCES
)
set(STAMP_TASK_HEADERS
	"include/stamp/task/task.h"
)

# add the library
add_library(stamp_task INTERFACE ${STAMP_TASK_SOURCES} ${STAMP_TASK_HEADERS})
add_library(stamp::task ALIAS stamp_task)
target_link_libraries(stamp_task)
target_compile_features(stamp_task INTERFACE cxx_std_20)


# adds a directory to search when finding header files
target_include_directories(stamp_task 
	INTERFACE "include" 
)
