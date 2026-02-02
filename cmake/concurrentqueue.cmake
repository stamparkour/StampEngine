include(FetchContent)

FetchContent_Declare(
	moodycamel_concurrentqueue
	GIT_REPOSITORY https://github.com/cameron314/concurrentqueue.git
	GIT_TAG origin/master # should change to explicit commit
)
FetchContent_GetProperties(moodycamel_concurrentqueue)
if(NOT moodycamel_concurrentqueue_POPULATED)
	FetchContent_MakeAvailable(moodycamel_concurrentqueue)
endif()