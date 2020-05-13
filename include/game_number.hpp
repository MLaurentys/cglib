#include <string>
#include <vector>
#include <memory>
#include "definitions.h"


class GameNumber {
public:
    virtual float get_float() const {}

    bool operator==(const GameNumber& other);
    bool operator<(const GameNumber& other);
    bool operator<(const GameNumber& other);

    ~GameNumber() {}

protected:
    GameNumber() {};
};

template <GNRepresentation repr>
class GameNumberS {};

template<>
class GameNumberS<GNRepresentation::real> : public GameNumber {
public:
    GameNumberS (float m) {n = m;}
    virtual float get_float() const override;
    ~GameNumberS(){}
private:
    float n;
};

template<>
class GameNumberS<GNRepresentation::sets> : public GameNumber {
public:
    GameNumberS () {};
    GameNumberS (float n, float m);
    virtual float get_float() const override;
    ~GameNumberS() {}
private:
    std::vector<std::shared_ptr<GameNumber>> left;
    std::vector<std::shared_ptr<GameNumber>> right;

    std::shared_ptr<GameNumber> get_max_left();
    std::shared_ptr<GameNumber> get_min_right();
};