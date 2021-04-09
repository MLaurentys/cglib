/*
 * This file contains the definition of the GameNumber REAL class specification
 */

#ifndef _GAME_NUMBER_REAL_HPP
#define _GAME_NUMBER_REAL_HPP

#include "game_number.hpp"

/*
 * This class represents a subset of game numbers: the real numbers
 * It is used because it allows the standard representation to avoid recursing
 *  until the '0 = < {} | {} >' base case.
 */
class GameNumberReal : public GameNumber {
      public:
        GameNumberReal(GameNumberReal &&other) noexcept;
        GameNumberReal(float);

        float get_temperature() const override;
        ~GameNumberReal() {}
};

#endif