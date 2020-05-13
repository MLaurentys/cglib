#include <string>
#include <vector>
#include <memory>
#include "definitions.h"

class GameNumber {
public:
    ~GameNumber(){}
};

template <enum class GNRepresentation::real>
class GameNumberS : GameNumber {

};

class GameNumber_real : public GameNumber {
public:
    GameNumber_real (float m) {n = m;}
    ~GameNumber_real(){}
private:
    float n;
};

class GameNumber_sets : public GameNumber {
public:
    GameNumber_sets (float n, float m) {
        left.push_back (std::make_shared<GameNumber_real>
            (GameNumber_real(n)));
        right.push_back (std::make_shared<GameNumber_real>
            (GameNumber_real(m)));
    }
    ~GameNumber_sets(){}
private:
    std::vector <std::shared_ptr<GameNumber>> left;
    std::vector <std::shared_ptr<GameNumber>> right;
};