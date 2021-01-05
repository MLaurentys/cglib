/*
 * This file contains the definition of the derivative classes that handle all
 *  cases of the game numbers shwon in WW
 */

#ifndef _GAME_NUMBER_SETS_H
#define _GAME_NUMBER_SETS_H

#include "game_number.hpp"
#include "game_number_real.hpp"

using std::get, std::make_shared;

class GameNumberSets : public GameNumber {
public:
    // Most basic constructor. Also used because it makes testing is easier.
    GameNumberSets (std::vector<std::shared_ptr<GameNumber>>&& l,
        std::vector<std::shared_ptr<GameNumber>>&& r);
    GameNumberSets (GameNumberSets&& other) noexcept;
    // This constructor is used because it allows the ability to create a number
    //  from a pre-built game tree.
    template <typename Titable, // type of the iterable core
              typename Uittor> // type of the iterator through the core
    GameNumberSets (
        const Titable&, //root of the game-tree
        float* (get_eval) (const Titable&), //function to evaluate
        std::tuple<Uittor, Uittor> (lIt) (const Titable&),  // L begin/end iters
        std::tuple<Uittor, Uittor> (rIt) (const Titable&)); // R brgin/end iters

    float get_temperature () const override;
    ~GameNumberSets () {}
private:
    void init ();

    std::vector<std::shared_ptr<GameNumber>> left;
    std::vector<std::shared_ptr<GameNumber>> right;

    std::shared_ptr<GameNumber> get_max_left() const;
    std::shared_ptr<GameNumber> get_min_right() const;
};

template <typename Titable, typename Uittor>
GameNumberSets::GameNumberSets (
        const Titable& game,
        float* (get_eval) (const Titable&),
        std::tuple<Uittor, Uittor> (lIt) (const Titable&),
        std::tuple<Uittor, Uittor> (rIt) (const Titable&))
            : left{}, right{} {
    if (get_eval(game) != nullptr) throw std::invalid_argument(
        "Attempt to create a non-set game number using sets constructor");
    auto lIter = lIt(game);
    auto rIter = rIt(game);
    for (auto it = get<0>(lIter); it != get<1>(lIter); ++it) {
        if (get_eval(*it) != nullptr)
            left.push_back(make_shared<GameNumberReal>(*(get_eval(*it))));
        else
            left.push_back(make_shared<GameNumberSets>(*it, get_eval, lIt, rIt));
    }
    for (auto it = get<0>(rIter); it != get<1>(rIter); ++it) {
        if (get_eval(*it) != nullptr)
            right.push_back(make_shared<GameNumberReal>(*(get_eval(*it))));
        else
            right.push_back(make_shared<GameNumberSets>(*it, get_eval, lIt, rIt));
    }
    init();
}
#endif