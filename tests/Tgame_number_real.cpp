
#include "../cglib/include/game_number_real.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <memory>
#include <typeinfo>
#include <vector>

using std::unique_ptr;

TEST(Operators, BetweenReals) {
        GameNumberReal gn1{3.0f};
        GameNumberReal gn2{2.0f};
        EXPECT_NE(gn1, gn2);
        EXPECT_GT(gn1, gn2);
        EXPECT_GE(gn1, gn2);
        EXPECT_GE(gn1, gn2);
        EXPECT_LT(gn2, gn1);
        EXPECT_LE(gn2, gn1);
        EXPECT_LE(gn2, gn1);
}

TEST(Operators, BetweenRealAndFloat) {
        GameNumberReal gn1(3.0f);
        EXPECT_NE(gn1, 0.0f);
        EXPECT_GT(gn1, 2.0f);
        EXPECT_GE(gn1, 3.0f);
        EXPECT_GE(gn1, 2.0f);
        EXPECT_LT(gn1, 4.0f);
        EXPECT_LE(gn1, 4.0f);
        EXPECT_LE(gn1, 3.0f);
}

TEST(ClassMethods, GetFloat) {
        GameNumberReal gn1(3.0f);
        EXPECT_FLOAT_EQ(gn1.get_float(), 3.0f);
}