cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Weffc++")

set(REQUIRED_LIBS gtest gmock pthread)
set(TEST_FILES test.cpp test2.cpp)

project(tests)
link_libraries(${REQUIRED_LIBS})
add_executable(tests ${TEST_FILES})