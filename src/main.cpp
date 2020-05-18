#include <cassert>
#include <iostream>

#include "game_number_repr.hpp"

using std::cout, std::endl;
using realGN = GameNumberS<GNRepresentation::real>;
using setsGN = GameNumberS<GNRepresentation::sets>;

void test1 () {
    // GameNumber gn = GameNumberS<GNRepresentation::real> (10.0f);
    // GameNumber gn2 = GameNumberS<GNRepresentation::sets> (3.0f, 5.0f);
    // cout << (gn == gn2) << endl;
    // cout << (gn != gn2) << endl;
    // cout << (gn < gn2) << endl;
    // cout << (gn <= gn2) << endl;
    // cout << (gn > gn2) << endl;
    // cout << (gn >= gn2) << endl;
}
void test2 () {
    // <10.5|11>
    std::vector<std::shared_ptr<GameNumber>> aux1, aux2, aux3, aux4;
    aux1.push_back(std::make_shared<realGN> (8.0f));
    aux1.push_back(std::make_shared<realGN> (10.5f));
    aux2.push_back(std::make_shared<realGN> (11.0f));
    aux2.push_back(std::make_shared<realGN> (12.0f));
    auto gn1 = setsGN(std::move(aux1), std::move(aux2));
    //GameNumber gn2 = realGN (10.0f);
    float a = gn1.get_float();
    cout << a << std::endl;
}
int main () {
    #ifndef NOT_DEBUG
    std::cout << "Debug mode\n";
    test2 ();
    #else
    std::cout << "Release mode\n";
    #endif
    
    return 0;
}