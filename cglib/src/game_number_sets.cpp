/*
 * This file implements the GameNumberSets class
 */

#include <iostream>

#include "../include/game_number_sets.hpp"

// Calculates all the member vairables
void GameNumberSets::init() {
        _switch = false;
        float maxL;
        float minR;
        // checks whether all children are surreal numbers
        bool l_flag = false, r_flag = false;
        for (auto &n : left) {
                if (!n->is_surreal()) {
                        l_flag = true;
                        break;
                }
        }
        for (auto &n : right) {
                if (!n->is_surreal()) {
                        r_flag = true;
                        break;
                }
        }
        if (!l_flag && !r_flag) {
                // calculates the surreal number or marks it as switch
                if (left.empty()) {
                        _surreal = true;
                        if (right.empty())
                                _real_value = 0.0f;
                        else
                                _real_value = std::min(
                                    std::floor(get_min_right()->get_float()),
                                    0.0f);
                } else if (right.empty()) {
                        _surreal = true;
                        _real_value = std::max(
                            std::ceil(get_max_left()->get_float()), 0.0f);
                } else {
                        maxL = get_max_left()->get_float();
                        minR = get_min_right()->get_float();
                        _surreal = maxL < minR;
                        if (_surreal) {
                                float dist = std::floor(maxL);
                                maxL -= dist;
                                minR -= dist;
                                // 0.0 <= maxL < 1.0
                                float fact = 1.0f;
                                while (fact > 1.0f / 4096.0f)
                                        if (maxL < fact)
                                                if (minR > fact)
                                                        break;
                                                else
                                                        fact *= 0.5f;
                                        else
                                                fact *= 1.5f;
                                _real_value = dist + fact;
                        } else {
                                _switch = true;
                        }
                }
        }

        // gets bias and temperature if it is a switch and termograph if it is a
        //  neither surreal nor switch
        if (_switch) {
                _bias = 0.5 * (maxL + minR);
                _temperature = 0.5 * (maxL - minR);
        } else if (!_surreal) {
                // gets termograph
        }
}

GameNumberSets::GameNumberSets(GameNumberSets &&other) noexcept
    : left{std::move(other.left)}, right{std::move(other.right)} {
        init();
}

GameNumberSets::GameNumberSets(float number) {
        if (number == 0.0f)
                init();
        else if (number > 0.0f) {
        }
}

GameNumberSets::GameNumberSets(const std::vector<float> &l,
                               const std::vector<float> &r)
    : {}

GameNumberSets::GameNumberSets(std::vector<std::shared_ptr<GameNumber>> &&l,
                               std::vector<std::shared_ptr<GameNumber>> &&r)
    : left{l}, right{r} {
        init();
}

std::shared_ptr<GameNumber> GameNumberSets::get_max_left() const {
        std::shared_ptr<GameNumber> max =
            std::make_shared<GameNumberReal>(std::numeric_limits<float>::min());
        for (auto &g : left)
                if (*g > *max)
                        max = g;
        return max;
}

std::shared_ptr<GameNumber> GameNumberSets::get_min_right() const {
        std::shared_ptr<GameNumber> min =
            std::make_shared<GameNumberReal>(std::numeric_limits<float>::max());
        for (auto &g : right)
                if (*g < *min)
                        min = g;
        return min;
}

// Supposes that every games in left/right subtrees are numbers
float GameNumberSets::get_temperature() const {
        float mx_l = get_max_left()->get_float();
        float mn_r = get_min_right()->get_float();
        if (mx_l < mn_r)
                return 0.0f;
        return 0.5f * (mx_l - mn_r);
}