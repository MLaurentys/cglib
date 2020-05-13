#ifndef _GAME_NUMBER_REPR_H
#define _GAME_NUMBER_REPR_H

#include "game_number.hpp"

template <GNRepresentation repr>
class GameNumberS {};

template<>
class GameNumberS<GNRepresentation::real> : public GameNumber {
public:
    GameNumberS (float m) {n = m;}
    virtual float get_float() const override;
    GameNumberS (GameNumberS&& other) noexcept;
    ~GameNumberS(){}
private:
    float n;
};

template<>
class GameNumberS<GNRepresentation::sets> : public GameNumber {
public:
    GameNumberS () {};
    GameNumberS (std::vector<std::shared_ptr<GameNumber>>&& l,
        std::vector<std::shared_ptr<GameNumber>>&& r);
    virtual float get_float() const override;
    GameNumberS (GameNumberS&& other) noexcept;

    bool is_surreal() const override;

    ~GameNumberS() {}
private:
    std::vector<std::shared_ptr<GameNumber>> left;
    std::vector<std::shared_ptr<GameNumber>> right;

    std::shared_ptr<GameNumber> get_max_left() const;
    std::shared_ptr<GameNumber> get_min_right() const;
};

#endif