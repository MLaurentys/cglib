#include <iostream>

#include "game_number_repr.hpp"

using T = GameNumberS<GNRepresentation::sets>;

T::GameNumberS (GameNumberS&& other) noexcept{
    left = {std::move(other.left)};
    right = {std::move(other.right)};
}

T::GameNumberS (std::vector<std::shared_ptr<GameNumber>>&& l,
    std::vector<std::shared_ptr<GameNumber>>&& r) {
    left = l;
    right = r;
}

std::shared_ptr<GameNumber> T::get_max_left() const{
    std::shared_ptr<GameNumber> max;
    for (auto& g : left)
        if (*g > *max)
            max = g;
    return max;
}

std::shared_ptr<GameNumber> T::get_min_right() const{
    std::shared_ptr<GameNumber> min;
    for (auto& g : right)
        if (*g < *min)
            min = g;
    return min;
}

float T::get_float () const {
    float ret;
    
    if (left.size() == 0.0f)
        if (right.size() == 0.0f)
            ret = 0.0f;
        else
            ret = std::floor (get_min_right()->get_float()) - 1.0f;
    else if (right.size() == 0.0f)
        ret = std::floor (get_min_right()->get_float()) + 1.0f;
    else {
        float maxL = get_max_left()->get_float();
        float minR = get_min_right()->get_float();
        if (maxL >= minR) {
            throw std::exception();
        }
        float dist = std::floor(maxL);
        maxL -= dist;
        minR -= dist;
        // 0.0 <= maxL < 1.0
        float fact = 1.0f;
        float ref = 1.0f/4096.0f;
        while (fact > ref)
            if (maxL < fact)
                if (minR > fact)
                    break;
                else
                    fact *= 0.5f;
            else
                fact += fact*0.5f;
        ret = dist + fact;
    }

    return ret;
}

bool T::is_surreal () const {
    if (left.size() == 0 || right.size() == 0) return true;
    float maxL = get_max_left()->get_float();
    float minR = get_min_right()->get_float();
    return maxL < minR;
}

