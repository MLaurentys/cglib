#include <cassert>
#include <iostream>

#include "game_number.hpp"

using namespace std;

void test () {
    GameNumber gn = GameNumberS<GNRepresentation::real> (10.0f);
    GameNumber gn2 = GameNumberS<GNRepresentation::sets> (3.0f, 5.0f);
    cout << (gn == gn2) << endl;
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