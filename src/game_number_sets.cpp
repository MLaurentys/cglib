#include "game_number.hpp"

float GameNumberS<GNRepresentation::sets>::get_float () const {
    return 10.0f;
}

GameNumberS<GNRepresentation::sets>::GameNumberS (float n, float m) {
    auto a = GameNumberS<GNRepresentation::sets>();
    left.push_back (std::make_shared<GameNumberS
        <GNRepresentation::real>>(n));
    right.push_back (std::make_shared<GameNumberS
        <GNRepresentation::sets>>(a));
}