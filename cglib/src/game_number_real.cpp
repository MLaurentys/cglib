/*
 * This file implements the GameNumberReal class
 */

#include "../include/game_number_real.hpp"

GameNumberReal::GameNumberReal (float val) {
    _surreal = true;
    _real_value = val;
    _switch = false;
}

GameNumberReal::GameNumberReal (GameNumberReal&& other) noexcept {
    _surreal = other._surreal;
    _real_value = other._real_value;
    _switch = false;
}

float GameNumberReal::get_temperature () const {
    return 0.0f; //every real number is a cool game
}