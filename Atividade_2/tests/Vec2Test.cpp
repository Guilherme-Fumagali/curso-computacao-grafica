#include "gtest/gtest.h"
#include "../Vec_lib/vec2.h"

TEST(Vec2, Constructor) {
    vec2 v1;
    vec2 v2(1, 2);

    EXPECT_EQ(v1.x(), 0);
    EXPECT_EQ(v1.y(), 0);

    EXPECT_EQ(v2.x(), 1);
    EXPECT_EQ(v2.y(), 2);
}