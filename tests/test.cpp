#include <iostream>
#include <gtest/gtest.h>

TEST(Test, Test1){
    ASSERT_TRUE(true == true);
}
int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);

    std::cout <<"lul?\n";

    return RUN_ALL_TESTS();
}