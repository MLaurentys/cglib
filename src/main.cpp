#include <cassert>
#include <iostream>

#include "game_number.hpp"


void test () {
    GameNumber gn = GameNumber (3);
    std::cout << gn.get_float() << "\n\n";
    assert (gn.get_float() == 3.0f);
}
int main () {
    #ifndef NOT_DEBUG
    std::cout << "Debug mode\n";
    test ();
    #else
    std::cout << "Release mode\n";
    #endif
    
    return 0;
}