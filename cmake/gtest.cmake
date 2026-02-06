message("importing gtest...")


FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/releases/download/v1.17.0/googletest-1.17.0.tar.gz
  DOWNLOAD_EXTRACT_TIMESTAMP ON
)

set(BUILD_SHARED_LIBS OFF)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
set(BUILD_SHARED_LIBS ON)

if(googletest_POPULATED)
	message("gtest found!")
else()
	message("failed to find gtest")
endif()
