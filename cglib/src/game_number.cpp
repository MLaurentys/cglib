/*
 * This file contain the definition for the methods defined in the correspondant
 *  header file.
 */

#include "../include/game_number.hpp"

bool GameNumber::operator< (const GameNumber& other) const {
    return get_float() < other.get_float();
}
bool GameNumber::operator> (const GameNumber& other) const {
    return get_float() > other.get_float();
}
bool GameNumber::operator== (const GameNumber& other) const {
    return get_float() == other.get_float();
}
bool GameNumber::operator!= (const GameNumber& other) const {
    return !(*this == other);
}
bool GameNumber::operator<= (const GameNumber& other) const {
    return *this < other || *this == other;
}
bool GameNumber::operator>= (const GameNumber& other) const {
    return *this > other || *this == other;
}

// Accessors
bool GameNumber::is_surreal () const {
    return _surreal;
}
bool GameNumber::is_switch () const {
    return _switch;
}
float GameNumber::get_temperature () const {
    return 0.0f;
}
float GameNumber::get_float () const {
    if (!_surreal)
        throw std::domain_error("Attempt to build real number from non-number");
    return _real_value;
}

// For good measure
GameNumber::GameNumber () : _surreal{false}, _switch{false},
    _real_value{0.0f} {}