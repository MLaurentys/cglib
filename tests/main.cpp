#include <iostream>
#include <gtest/gtest.h>
#include "../cglib/include/game_number_real.hpp"

TEST(t1, t1_1) {
    GameNumberReal gn(3.0f);
    EXPECT_EQ(gn.get_float(), 3.0f);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}