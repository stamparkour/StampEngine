cmake_minimum_required(VERSION 3.24)
# set the project name
project(stamp VERSION 0.1.0 LANGUAGES C CXX)


#options
option(STAMP_BUILD_APP OFF)
option(STAMP_BUILD_DOXYGEN OFF)

#config
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# set C++ version
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# include subdirectories
add_subdirectory(lib/reflect)
add_subdirectory(lib/serialize)
add_subdirectory(lib/memory)
add_subdirectory(lib/task)
add_subdirectory(lib/core)
add_subdirectory(lib/diagnose)
add_subdirectory(lib/math)
add_subdirectory(lib/signal)

add_library(stamp_stamp INTERFACE)
add_library(stamp::stamp ALIAS stamp_stamp)
target_link_libraries(stamp_stamp INTERFACE stamp::core stamp::serialize stamp::reflect stamp::task)

if(STAMP_BUILD_APP)
    add_subdirectory(app/my_app)
    add_subdirectory(test)

    #project warnings
    if (MSVC)
        add_compile_options(/W4 /WX)
        add_compile_options(/std:c++latest) 
    else()
        add_compile_options(-Wall -Wextra -pedantic -Werror)
    endif()
endif()

if(STAMP_BUILD_DOXYGEN)
    include(doxygen)
    if(Doxygen_FOUND)
        set(MY_DOXYGEN_SOURCES 
            ${PROJECT_SOURCE_DIR}/lib/
            ${PROJECT_SOURCE_DIR}/docs/
            ${PROJECT_SOURCE_DIR}/README.md
            ${PROJECT_SOURCE_DIR}/LICENSE.txt
        )

        set(DOXYGEN_USE_MDFILE_AS_MAINPAGE ${PROJECT_SOURCE_DIR}/README.md)
        set(DOXYGEN_BUILTIN_STL_SUPPORT YES)
        set(DOXYGEN_EXTRACT_ALL YES)
        set(DOXYGEN_EXTENSION_MAPPING txt=md)
        set(DOXYGEN_SHOW_NAMESPACES YES)
        set(DOXYGEN_INCLUDE_GRAPH YES)
        set(DOXYGEN_HAVE_DOT YES)
        set(DOXYGEN_CALL_GRAPH YES)
        set(DOXYGEN_RECURSIVE YES)
        set(DOXYGEN_SOURCE_BROWSER YES)

        doxygen_add_docs(stamp_docs ${MY_DOXYGEN_SOURCES} ALL)
    endif()
endif()