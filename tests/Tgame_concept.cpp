
#include "../cglib/include/game_concept.hpp"
#include <filesystem>
#include <gtest/gtest.h>
#include <string>

constexpr auto baseCmd = "g++ -std=c++2a -I../../cglib/include -O0";

bool compiles(const std::string &filename, const std::string &execName) {
        auto cmd = static_cast<std::string>(baseCmd) + " -o " + execName +
                   " ../../tests/game_concept/" + filename;
        bool ret = system(cmd.c_str()) == 0;
        std::filesystem::remove(execName);
        return ret;
}

TEST(Concept, PrimitiveTypes) {
        ASSERT_DEATH(assert(CombinatorialGame<char *>), "");
        ASSERT_DEATH(assert(CombinatorialGame<int>), "");
}