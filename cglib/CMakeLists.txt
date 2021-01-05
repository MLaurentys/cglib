
set(LIB_FILES src/game_number_real.cpp src/game_number_sets.cpp
src/game_number.cpp)

project (cglib)
add_library(cglib STATIC ${LIB_FILES})
set_target_properties(cglib PROPERTIES PUBLIC_HEADER
                        include/game_number_repr.hpp
                        include/game_number.hpp
                        include/definitions.hpp)
