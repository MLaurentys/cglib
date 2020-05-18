cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(LIB_FILES src/game_number_real.cpp src/game_number_sets.cpp
src/game_number.cpp include/definitions.hpp include/game_number_repr.hpp
include/game_number.hpp)

project(gn_tests)

add_executable(gn_tests src/main.cpp)

add_library(game_numbers ${LIB_FILES})