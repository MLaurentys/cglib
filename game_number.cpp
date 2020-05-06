#include "game_number.hpp"

GameNumber::GameNumber () {
    representation = GNRepresentation::sets;
    left = {};
    right = {};
}

GameNumber::GameNumber (int n) {
    representation = GNRepresentation::integer;
    inum = n;
}

GameNumber::GameNumber (float n) {
    representation = GNRepresentation::real;
    fnum = n;
}


GameNumber::GameNumber (std::vector<GameNumber*>& l,
        std::vector<GameNumber*>& r) {
    representation = GNRepresentation::sets;
    left = l;
    right = r;
}

GameNumber::GameNumber (const std::string& string_representation) {}

GameNumber::GameNumber (const GameNumber& other) {
    representation = other.representation;
    switch (representation)
    {
    case (GNRepresentation::integer):
        inum = other.inum;
        break;
    case (GNRepresentation::real):
        fnum = other.fnum;
        break;
    case (GNRepresentation::sets):
        left = other.left;
        right = other.right;
        break;
    }
}

GameNumber::GameNumber (GameNumber&&) {}

GameNumber::~GameNumber (){}

GameNumber::GameNumber& operator = (const GameNumber&){}
GameNumber::GameNumber& operator = (const GameNumber&&){}

void GameNumber::get_fraction () {}
float GameNumber::get_float () {
    if (representation == GNRepresentation::integer) return (float)inum;
    if (representation == GNRepresentation::real) return fnum;

}

bool GameNumber::is_surreal(){}

GameNumber& GameNumber::get_max_L() {}
GameNumber& GameNumber::get_min_R() {}