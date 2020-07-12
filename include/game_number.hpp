/*
 * This file contains the base class definition for Game Numbers
 */

#ifndef _GAME_NUMBER_H
#define _GAME_NUMBER_H

#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
#include <cmath>
#include <iostream>
#include <limits>
#include "definitions.hpp"

/*
 * This class, together with its derived classes, meets the definition and
 *  functionality of Surreal Number and Non-Numbers as defined on ONAG and
 *  developed in the book Winning Ways for Your Mathematical Plays.
 * This class is NOT instatiated directly.
 */
class GameNumber {
public:
    GameNumber (GameNumber&&) noexcept = default;
    virtual ~GameNumber() {}
    // Return the value of the surreal number represented through real notation
    virtual float get_float () const {return 0.0f;};
    // Whether the Game Number is a Sureal Number
    virtual bool is_surreal () const {return false;};
    // Comparators
    bool operator == (const GameNumber& other);
    bool operator != (const GameNumber& other);
    bool operator <= (const GameNumber& other);
    bool operator <  (const GameNumber& other);
    bool operator >= (const GameNumber& other);
    bool operator >  (const GameNumber& other);
protected:
    // Prevents class from being directly instaciated
    GameNumber() {};
};


#endif