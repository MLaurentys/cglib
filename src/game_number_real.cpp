#include "../include/game_number_repr.hpp"

using T = GameNumberS<GNRepresentation::real>;

T:: GameNumberS (float val) : n{val} {}

T::GameNumberS (GameNumberS&& other) noexcept {
    n = other.get_float();
}

float T::get_float() const {
    return n;
}