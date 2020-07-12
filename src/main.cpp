#include <cassert>
#include <iostream>
#include <memory>

#include "game_number.hpp"
#include "game_number_repr.hpp"

using std::cout, std::endl;
using gn_ptr = std::unique_ptr<GameNumber>;
using sets = GameNumberS<GNRepresentation::sets>;
using real = GameNumberS<GNRepresentation::real>;

void test1 () {
    std::vector<std::shared_ptr<GameNumber>> s =
        {std::make_shared<realGN>(3.0f)};
    std::vector<std::shared_ptr<GameNumber>> t =
        {std::make_shared<realGN>(5.0f)};

    std::unique_ptr<GameNumber> gn =
        std::make_unique<GameNumberS<GNRepresentation::real>>(10.0f);
    std::unique_ptr<GameNumber> gn2 = 
        std::make_unique<GameNumberS<GNRepresentation::sets>>(std::move(s),
                                                              std::move(t));
    cout << (*gn == *gn2) << endl;
    cout << (*gn != *gn2) << endl;
    cout << (*gn <  *gn2) << endl;
    cout << (*gn <= *gn2) << endl;
    cout << (*gn >  *gn2) << endl;
    cout << (*gn >= *gn2) << endl;
}
void test2 () {
    // <10.5|11>
    std::vector<std::shared_ptr<GameNumber>> aux1, aux2, aux3, aux4;
    aux1.push_back(std::make_shared<realGN> (8.0f));
    aux1.push_back(std::make_shared<realGN> (10.5f));
    aux2.push_back(std::make_shared<realGN> (11.0f));
    aux2.push_back(std::make_shared<realGN> (12.0f));
    const GameNumber& gn1 = setsGN(std::move(aux1), std::move(aux2));
    //GameNumber gn2 = realGN (10.0f);
    float a = gn1.get_float();
    cout << a << std::endl;
}
int main () {
    #ifndef NOT_DEBUG
    std::cout << "Debug Mode\n";
    test1();
    test2();
    #else
    std::cout << "Release Mode\n";
    #endif
    
    return 0;
}