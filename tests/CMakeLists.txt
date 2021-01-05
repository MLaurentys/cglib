cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Weffc++")

set(REQUIRED_LIBS gtest gmock pthread)
set(TEST_FILES main.cpp)

FUNCTION(PREPEND var prefix)
    SET(listVar "")
    FOREACH(f ${ARGN})
       LIST(APPEND listVar "${prefix}/${f}")
    ENDFOREACH(f)
    SET(${var} "${listVar}" PARENT_SCOPE)
ENDFUNCTION(PREPEND)

PREPEND(CGLIB_SOURCE_FILES ../cglib ${CGLIB_SOURCE_FILES})
PREPEND(CGLIB_INCLUDE_FILES ../cglib ${CGLIB_INCLUDE_FILES})

message(STATUS "foo include files: ${CGLIB_INCLUDE_FILES}")
message(STATUS "foo source files: ${CGLIB_SOURCE_FILES}")

project(tests)
link_libraries(${REQUIRED_LIBS})
add_executable(tests
    ${CGLIB_SOURCE_FILES}
    ${CGLIB_INCLUDE_FILES}
    ${TEST_FILES})


