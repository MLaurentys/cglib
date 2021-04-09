
#include "../cglib/include/game_number_sets.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <memory>
#include <typeinfo>
#include <vector>

using namespace std;

using std::unique_ptr;

TEST(Constructors, UsingVectorsOfFloats) {
        std::vector<float> v1{2.0f};
        std::vector<float> v2{};
        GameNumberSets(v1, v2);
}