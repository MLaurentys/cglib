cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

SET(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Weffc++")

set(LIB_FILES src/game_number_real.cpp src/game_number_sets.cpp
src/game_number.cpp)

project (cglib)
add_library(cglib STATIC ${LIB_FILES})
set_target_properties(cglib PROPERTIES PUBLIC_HEADER
                        include/game_number_repr.hpp
                        include/game_number.hpp
                        include/definitions.hpp)
