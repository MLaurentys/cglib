#ifndef _GAME_NUMBER_REPR_H
#define _GAME_NUMBER_REPR_H

#include "game_number.hpp"

template <GNRepresentation repr>
class GameNumberS {};

template<>
class GameNumberS<GNRepresentation::real> : public GameNumber {
public:
    GameNumberS (GameNumberS&& other) noexcept;
    GameNumberS (float);

    float get_float() const override;

    ~GameNumberS(){}
private:
    float n;
};

template<>
class GameNumberS<GNRepresentation::sets> : public GameNumber {
public:
    GameNumberS (std::vector<std::shared_ptr<GameNumber>>&& l,
        std::vector<std::shared_ptr<GameNumber>>&& r);
    GameNumberS (GameNumberS&& other) noexcept;
    // GameNumberS (const std::string&);
    template <typename Titable, typename Uittor>
    GameNumberS (const Titable&, float* (Titable::*get_eval)() const,
                 std::tuple<Uittor, Uittor> (Titable::*lIt)(),
                 std::tuple<Uittor, Uittor> (Titable::*rIt)());

    template <typename Titable, typename Uittor>
    GameNumberS (const Titable&, float* (get_eval) (const Titable&),
                 std::tuple<Uittor, Uittor> (lIt) (const Titable&),
                 std::tuple<Uittor, Uittor> (rIt) (const Titable&));

    float get_float() const override;
    bool is_surreal() const override;

    ~GameNumberS() {}
private:
    GameNumberS (const std::string&, int);
    std::vector<std::shared_ptr<GameNumber>> left;
    std::vector<std::shared_ptr<GameNumber>> right;

    std::shared_ptr<GameNumber> get_max_left() const;
    std::shared_ptr<GameNumber> get_min_right() const;
};

using realGN = GameNumberS<GNRepresentation::real>;
using setsGN = GameNumberS<GNRepresentation::sets>;
using std::get;

template <typename Titable, typename Uittor>
GameNumberS<GNRepresentation::sets>::GameNumberS
        (const Titable& game, float* (Titable::*get_eval)() const,
         std::tuple<Uittor, Uittor> (Titable::*lIt)(),
         std::tuple<Uittor, Uittor> (Titable::*rIt)()) {
    if (game.get_eval() != nullptr) throw std::invalid_argument(
      "Attempt to create a non-set game number using sets constructor");
    auto lIter = game.lIt();
    auto rIter = game.rIt();
    for (auto it = get<0>(lIter); it != get<1>(lIter); ++it) {
        if (*it.get_eval() != nullptr)
            left.push_back(std::make_shared<realGN>(*(*it.get_eval())));
        else
            left.push_back(std::make_shared<setsGN>(*it, get_eval, lIt, rIt));
    }
    for (auto it = get<0>(rIter); it != get<1>(rIter); ++it) {
        if (*it.get_eval() != nullptr)
            right.push_back(std::make_shared<realGN>(*(*it.get_eval())));
        else
            right.push_back(std::make_shared<setsGN>(*it, get_eval, lIt, rIt));
    }
}

template <typename Titable, typename Uittor>
GameNumberS<GNRepresentation::sets>::GameNumberS (
                const Titable& game,
                float* (get_eval) (const Titable&),
                std::tuple<Uittor, Uittor> (lIt) (const Titable&),
                std::tuple<Uittor, Uittor> (rIt) (const Titable&)) {
    if (get_eval(game) != nullptr) throw std::invalid_argument(
      "Attempt to create a non-set game number using sets constructor");
    auto lIter = lIt(game);
    auto rIter = rIt(game);
    for (auto it = get<0>(lIter); it != get<1>(lIter); ++it) {
        if (get_eval(*it) != nullptr)
            left.push_back(std::make_shared<realGN>(*(get_eval(*it))));
        else
            left.push_back(std::make_shared<setsGN>(*it, get_eval, lIt, rIt));
    }
    for (auto it = get<0>(rIter); it != get<1>(rIter); ++it) {
        if (get_eval(*it) != nullptr)
            right.push_back(std::make_shared<realGN>(*(get_eval(*it))));
        else
            right.push_back(std::make_shared<setsGN>(*it, get_eval, lIt, rIt));
    }
}
#endif