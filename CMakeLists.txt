cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

SET(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Weffc++")

add_subdirectory(cglib)
add_subdirectory(tests)