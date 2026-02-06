message("importing concurrentqueue...")

FetchContent_Declare(
	concurrentqueue
	GIT_REPOSITORY https://github.com/cameron314/concurrentqueue.git
	GIT_TAG origin/master # should change to explicit commit
	DOWNLOAD_EXTRACT_TIMESTAMP ON
)

FetchContent_MakeAvailable(concurrentqueue)

if(concurrentqueue_POPULATED)
	message("concurrentqueue found!")
else()
	message("failed to find concurrentqueue")
endif()