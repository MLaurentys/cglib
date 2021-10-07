
#include "../cglib/include/game_concept.hpp"
#include <cstddef>
#include <filesystem>
#include <gtest/gtest.h>
#include <string>

template <CombinatorialGame G> bool IsCGame(G test) { return true; }

TEST(Concept, PrimitiveTypes) {
        ASSERT_DEATH(assert(CombinatorialGame<std::nullptr_t>), "");
        ASSERT_DEATH(assert(CombinatorialGame<void>), "");
        EXPECT_TRUE(IsCGame(1));
        EXPECT_TRUE(IsCGame(1.0f));
        EXPECT_TRUE(IsCGame(1.0));
        EXPECT_TRUE(IsCGame('a'));
        EXPECT_TRUE(IsCGame(false));
}