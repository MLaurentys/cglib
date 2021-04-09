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
 * This base class is NOT instatiated directly.
 */
class GameNumber {
public:
    GameNumber (GameNumber&&) noexcept = default;
    virtual ~GameNumber() {}

    bool is_surreal () const;
    bool is_switch () const;

    // Return the value of the surreal number represented with real notation
    float get_float () const;
    // Returns the temperature represented with real number
    virtual float get_temperature () const;

    // Comparators
    bool operator== (const GameNumber& other) const;
    bool operator!= (const GameNumber& other) const;
    bool operator<= (const GameNumber& other) const;
    bool operator<  (const GameNumber& other) const;
    bool operator>= (const GameNumber& other) const;
    bool operator>  (const GameNumber& other) const;
    bool operator== (const float other) const;
    bool operator!= (const float other) const;
    bool operator<= (const float other) const;
    bool operator<  (const float other) const;
    bool operator>= (const float other) const;
    bool operator>  (const float other) const;

protected:
    // Prevents class from being directly instaciated
    GameNumber ();

    bool _surreal;
    bool _switch;
    float _real_value;
    float _bias;
    float _temperature;
};

#endif