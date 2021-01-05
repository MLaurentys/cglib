#include <cassert>
#include <iostream>
#include <memory>

#include "game_number.hpp"
#include "game_number_real.hpp"
#include "game_number_sets.hpp"

using std::cout, std::endl;

void test1 () {
    std::vector<std::shared_ptr<GameNumber>> s =
        {std::make_shared<GameNumberReal>(3.0f)};
    std::vector<std::shared_ptr<GameNumber>> t =
        {std::make_shared<GameNumberReal>(5.0f)};
    std::unique_ptr<GameNumber> gn1 = std::make_unique<GameNumberReal>(10.0f);
    std::unique_ptr<GameNumber> gn2 = 
        std::make_unique<GameNumberSets>(std::move(s), std::move(t));

    // gn1 = 10, gn2 = 4
    cout << (*gn1 == *gn2) << endl;
    cout << (*gn1 != *gn2) << endl;
    cout << (*gn1 <  *gn2) << endl;
    cout << (*gn1 <= *gn2) << endl;
    cout << (*gn1 >  *gn2) << endl;
    cout << (*gn1 >= *gn2) << endl;
}
void test2 () {
    // <10.5|11>
    std::vector<std::shared_ptr<GameNumber>> aux1, aux2, aux3, aux4;
    aux1.push_back(std::make_shared<GameNumberReal> (8.0f));
    aux1.push_back(std::make_shared<GameNumberReal> (10.5f));
    aux2.push_back(std::make_shared<GameNumberReal> (11.0f));
    aux2.push_back(std::make_shared<GameNumberReal> (12.0f));
    const GameNumber& gn1 = GameNumberSets(std::move(aux1), std::move(aux2));
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