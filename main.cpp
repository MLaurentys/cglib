#include <cassert>
#include <iostream>

void test () {
    assert (1 + 1 == 2);
}
int main () {
    #ifdef BASE_DEBUG
    std::cout << "Debug mode\n";
    test ();
    #else
    std::cout << "Release mode\n";
    #endif
    
    return 0;
}