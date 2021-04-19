cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Weffc++")
set(CGLIB_SOURCE_FILES CACHE INTERNAL
    "Allows tests to easly find all src files" FORCE)
set(CGLIB_INCLUDE_FILES CACHE INTERNAL
    "Allows tests to easly find all include files" FORCE)

add_subdirectory(cglib)
add_subdirectory(tests)