
//#include "../cglib/include/game_concept.hpp"
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <gtest/gtest.h>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <typeinfo>
#include <vector>

constexpr auto baseCmd = "g++ -std=c++2a -I../../cglib/include -O3 ";

bool compiles(const std::string &filename) {
        auto cmd = static_cast<std::string>(baseCmd) + "-o" + filename +
                   " game_concept/" + filename;
        std::cout << cmd << std::endl;
        return system(cmd.c_str()) == 0;
}

TEST(Concept, PrimitiveTypes) { EXPECT_TRUE(compiles("float.cpp")); }

// int main() {
//         std::cout << compiles("float.cpp");
//         return 0;
// }