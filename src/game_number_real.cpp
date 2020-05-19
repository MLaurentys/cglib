#include "../include/game_number_repr.hpp"

using T = GameNumberS<GNRepresentation::real>;

T::GameNumberS (GameNumberS&& other) noexcept{
    n = other.get_float();
}

float T::get_float() const {
    return n;
}


// GameNumber::GameNumber (float n) {
// }


// GameNumber::GameNumber (std::vector<GameNumber*>& l,
//         std::vector<GameNumber*>& r) {}

// GameNumber::GameNumber (const std::string& string_representation) {}

// GameNumber::GameNumber (const GameNumber& other) {}

// GameNumber::GameNumber (GameNumber&&) {}

// GameNumber::~GameNumber (){}

// //GameNumber::GameNumber& operator = (const GameNumber&){}
// //GameNumber::GameNumber& operator = (const GameNumber&&){}

// void GameNumber::get_fraction () {}
// float GameNumber::get_float () {
//     return 0;
// }

// bool GameNumber::is_surreal(){}

// GameNumber& GameNumber::get_max_L() {}
// GameNumber& GameNumber::get_min_R() {}