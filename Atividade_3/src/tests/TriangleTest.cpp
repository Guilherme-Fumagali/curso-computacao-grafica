#include <gtest/gtest.h>
#include "../Triangle.h"

/* -------------- */
/* Triangle Tests */
/* -------------- */

/* Constructor and accessor test */
TEST(Triangle, Constructor) {
    Triangle t1;
    Triangle t2(vec3(1, 2, 3), vec3(4, 5, 6), vec3(7, 8, 9));

    EXPECT_EQ(t1[0], vec3(0, 0, 0));
    EXPECT_EQ(t1[1], vec3(0, 0, 0));
    EXPECT_EQ(t1[2], vec3(0, 0, 0));

    EXPECT_EQ(t2[0], vec3(1, 2, 3));
    EXPECT_EQ(t2[1], vec3(4, 5, 6));
    EXPECT_EQ(t2[2], vec3(7, 8, 9));
}

TEST(Triangle, ConstructorWithNegativeValues) {
    Triangle t1(vec3(-1, -2, -3), vec3(-4, -5, -6), vec3(-7, -8, -9));

    EXPECT_EQ(t1[0], vec3(-1, -2, -3));
    EXPECT_EQ(t1[1], vec3(-4, -5, -6));
    EXPECT_EQ(t1[2], vec3(-7, -8, -9));
}

/* Subscript test "t1[i]" */
TEST(Triangle, Subscript) {
    Triangle t1(vec3(1, 2, 3), vec3(4, 5, 6), vec3(7, 8, 9));

    EXPECT_EQ(t1[0], vec3(1, 2, 3));
    EXPECT_EQ(t1[1], vec3(4, 5, 6));
    EXPECT_EQ(t1[2], vec3(7, 8, 9));

    t1[0] = vec3(10, 11, 12);
    t1[1] = vec3(13, 14, 15);
    t1[2] = vec3(16, 17, 18);

    EXPECT_EQ(t1[0], vec3(10, 11, 12));
    EXPECT_EQ(t1[1], vec3(13, 14, 15));
    EXPECT_EQ(t1[2], vec3(16, 17, 18));
}

/* Equals test "t1 == t2" */
TEST(Triangle, Equals) {
    Triangle t1(vec3(1, 2, 3), vec3(4, 5, 6), vec3(7, 8, 9));
    Triangle t2(vec3(1, 2, 3), vec3(4, 5, 6), vec3(7, 8, 9));

    EXPECT_TRUE(t1 == t2);
}

TEST(Triangle, EqualsWithNegativeValues) {
    Triangle t1(vec3(-1, -2, -3), vec3(-4, -5, -6), vec3(-7, -8, -9));
    Triangle t2(vec3(-1, -2, -3), vec3(-4, -5, -6), vec3(-7, -8, -9));

    EXPECT_TRUE(t1 == t2);
}

TEST(Triangle, EqualsWithPositiveAndNegativeValues) {
    Triangle t1(vec3(-1, -2, -3), vec3(-4, -5, -6), vec3(-7, -8, -9));
    Triangle t2(vec3(1, 2, 3), vec3(4, 5, 6), vec3(7, 8, 9));

    EXPECT_FALSE(t1 == t2);
}

/* Inequality test "t1 != t2" */
TEST(Triangle, Inequality) {
    Triangle t1(vec3(1, 2, 3), vec3(4, 5, 6), vec3(7, 8, 9));
    Triangle t2(vec3(10, 11, 12), vec3(13, 14, 15), vec3(16, 17, 18));

    EXPECT_FALSE(t1 == t2);
}

/* std ostream test */
TEST(Triangle, StdOstream) {
    Triangle t1(vec3(1, 2, 3), vec3(4, 5, 6), vec3(7, 8, 9));

    std::stringstream ss;
    ss << t1;

    EXPECT_EQ(ss.str(), "Triangle: [1 2 3], [4 5 6], [7 8 9]");
}