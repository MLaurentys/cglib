#include <string>
#include <vector>
#include <memory>
#include "definitions.h"

template <class T>
class GameNumber {
// public:
//     float get_float () {
//         static_cast<T*>(this)->get_float();
//     }
// public:
//     GameNumber ();
//     GameNumber (std::vector<GameNumber*>& left, std::vector<GameNumber*>& right);
//     GameNumber (const std::string& string_representation);
//     GameNumber (const GameNumber&);
//     GameNumber (GameNumber&&);
//     ~GameNumber ();

//     GameNumber& operator = (const GameNumber&);
//     GameNumber& operator = (const GameNumber&&);

//     void get_fraction();
//     float get_float();

//     bool is_surreal();
// private:
//     GameNumber& get_max_L();
//     GameNumber& get_min_R();
};


class GameNumber_real : public GameNumber<GameNumber_real> {
public:
    GameNumber_real (float m) {n = m;}
private:
    float n;
};

class GameNumber_sets : public GameNumber<GameNumber_sets> {
public:
    GameNumber_sets (float n, float m) {
        left.push_back (std::make_shared<GameNumber_real>
            (GameNumber_real(n)));
        right.push_back (std::make_shared<GameNumber_real>
            (GameNumber_real(m)));
    }
private:
    std::vector <std::shared_ptr<GameNumber>> left;
    std::vector <std::shared_ptr<GameNumber>> right;
};