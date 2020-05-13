#ifndef _GAME_NUMBER_H
#define _GAME_NUMBER_H

#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
#include <cmath>
#include <iostream>
#include <limits>
#include "definitions.h"


class GameNumber {
public:
    GameNumber(GameNumber&&) noexcept = default;

    virtual float get_float() const { std::cout << "FALHOUT" << std::endl; return 0.0f;}
    virtual bool is_surreal() const {return false;}

    bool operator==(const GameNumber& other);
    bool operator!=(const GameNumber& other);
    bool operator<=(const GameNumber& other);
    bool operator<(const GameNumber& other);
    bool operator>=(const GameNumber& other);
    bool operator>(const GameNumber& other);

    ~GameNumber() {}

protected:
    GameNumber() {};
};


#endif