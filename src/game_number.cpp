#include "game_number.hpp"

GameNumber_sets::GameNumber_sets (float n, float m) {
        left.push_back (std::make_shared<GameNumber_real>
            (GameNumber_real(n)));
        right.push_back (std::make_shared<GameNumber_real>
            (GameNumber_real(m)));
    }
}
float GameNumber_sets::get_float () {
    return 10.0f;
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