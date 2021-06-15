#include "../../cglib/include/game_concept.hpp"
#include <gtest/gtest.h>

int main() {
        static_assert(CombinatorialGame<char>);
        return 0;
}