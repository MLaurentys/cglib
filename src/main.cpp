#include <cassert>
#include <iostream>

#include "game_number_repr.hpp"

using namespace std;

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
    std::vector<std::shared_ptr<GameNumber>> aux1, aux2, aux3, aux4;
    aux1.push_back(std::make_shared<GameNumberS<GNRepresentation::real>> (8.0f));
    aux1.push_back(std::make_shared<GameNumberS<GNRepresentation::real>> (10.5f));
    aux2.push_back(std::make_shared<GameNumberS<GNRepresentation::real>> (11.0f));
    aux2.push_back(std::make_shared<GameNumberS<GNRepresentation::real>> (12.0f));
    GameNumber gn1 = GameNumberS<GNRepresentation::sets>(std::move(aux1), std::move(aux2));
    GameNumber gn2 = GameNumberS<GNRepresentation::real> (10.0f);
    cout << gn1.get_float() << endl;
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