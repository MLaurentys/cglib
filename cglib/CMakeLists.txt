cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

SET(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Weffc++")

set(CGLIB_SOURCE_FILES
    src/game_number_real.cpp
    src/game_number_sets.cpp
    src/game_number.cpp
    CACHE INTERNAL "Allows tests to easly find all src files")

set(CGLIB_INCLUDE_FILES
    include/game_number_real.hpp
    include/game_number.hpp
    include/definitions.hpp
    CACHE INTERNAL "Allows tests to easly find all include files")

project (cglib)
add_library(cglib STATIC ${CGLIB_SOURCE_FILES})
set_target_properties(cglib PROPERTIES PUBLIC_HEADER
                        include/game_number_real.hpp
                        include/game_number.hpp
                        include/definitions.hpp)
