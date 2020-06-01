#include "../include/game_number.hpp"

float GameNumber::get_float() const {
    std::cout << "Poly fail" << std::endl;
    return 0.0f;
}

bool GameNumber::operator ==(const GameNumber& other) {
    return get_float() == other.get_float();
}
bool GameNumber::operator !=(const GameNumber& other) {
    return get_float() != other.get_float();
}
bool GameNumber::operator <(const GameNumber& other) {
    return get_float() < other.get_float();
}
bool GameNumber::operator <=(const GameNumber& other) {
    return *this == other || *this < other;
}
bool GameNumber::operator >=(const GameNumber& other) {
    return *this == other || *this > other;
}
bool GameNumber::operator >(const GameNumber& other) {
    float a = get_float();
    float b = other.get_float();
    return a > b;
}

