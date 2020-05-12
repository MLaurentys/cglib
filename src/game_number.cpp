#include "game_number.hpp"

GameNumber::GameNumber () {
    gn = GNSpecialized<GNRepresentation::integer> ();
}

GameNumber::GameNumber (int n) {
    std::cout << "decltype(i) is " << type_name<decltype(gn)>() << '\n';
    gn = GNSpecialized<GNRepresentation::integer> (n);
    std::cout << "decltype(i) is " << type_name<decltype(gn)>() << '\n';
    gn.print_n();
}

GameNumber::GameNumber (float n) {
    gn = GNSpecialized<GNRepresentation::real> (n);
}


GameNumber::GameNumber (std::vector<GameNumber*>& l,
        std::vector<GameNumber*>& r) {}

GameNumber::GameNumber (const std::string& string_representation) {}

GameNumber::GameNumber (const GameNumber& other) {}

GameNumber::GameNumber (GameNumber&&) {}

GameNumber::~GameNumber (){}

//GameNumber::GameNumber& operator = (const GameNumber&){}
//GameNumber::GameNumber& operator = (const GameNumber&&){}

void GameNumber::get_fraction () {}
float GameNumber::get_float () {
    return 0;
}

bool GameNumber::is_surreal(){}

GameNumber& GameNumber::get_max_L() {}
GameNumber& GameNumber::get_min_R() {}