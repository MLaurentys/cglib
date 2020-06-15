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


class GameNumber {
public:
    GameNumber(GameNumber&&) noexcept = default;

    virtual float get_float() const;
    virtual bool is_surreal() const {return false;}

    bool operator==(const GameNumber& other);
    bool operator!=(const GameNumber& other);
    bool operator<=(const GameNumber& other);
    bool operator<(const GameNumber& other);
    bool operator>=(const GameNumber& other);
    bool operator>(const GameNumber& other);

    virtual ~GameNumber() {}

protected:
    GameNumber() {};
};


#endif