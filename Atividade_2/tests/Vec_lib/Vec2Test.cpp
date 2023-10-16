#include "gtest/gtest.h"
#include "vec2.h"

/* -------------- */
/* Vec2 Functions */
/* -------------- */

/* Constructor and accessor test */
TEST(Vec2, Constructor) {
    vec2 v1;
    vec2 v2(1, 2);

    EXPECT_EQ(v1.x(), 0);
    EXPECT_EQ(v1.y(), 0);

    EXPECT_EQ(v2.x(), 1);
    EXPECT_EQ(v2.y(), 2);
}

/* Negation test "-v1" */
TEST(Vec2, Negation) {
    vec2 v1(1, 2);

    vec2 v2 = -v1;

    EXPECT_EQ(v2.x(), -1);
    EXPECT_EQ(v2.y(), -2);
}

/* Subscript test "v1[i]" */
TEST(Vec2, Subscript) {
    vec2 v1(1, 2);

    EXPECT_EQ(v1[0], 1);
    EXPECT_EQ(v1[1], 2);

    v1[0] = 3;
    v1[1] = 4;

    EXPECT_EQ(v1[0], 3);
    EXPECT_EQ(v1[1], 4);
}

/* Addition test "v1 = v1 + v2" */
TEST(Vec2, Addition) {
    vec2 v1(1, 2);
    vec2 v2(3, 4);

    v1 += v2;

    EXPECT_EQ(v1.x(), 4);
    EXPECT_EQ(v1.y(), 6);
}

/* Subtraction test "v1 = v1 - v2" */
TEST(Vec2, Subtraction) {
    vec2 v1(1, 2);
    vec2 v2(3, 4);

    v1 -= v2;

    EXPECT_EQ(v1.x(), -2);
    EXPECT_EQ(v1.y(), -2);
}

/* Multiplication test "v1 = v1 * t" */
TEST(Vec2, Multiplication) {
    vec2 v1(1, 2);
    double t = 2;

    v1 *= t;

    EXPECT_EQ(v1.x(), 2);
    EXPECT_EQ(v1.y(), 4);
}

/* Division test "v1 = v1 / t" */
TEST(Vec2, Division) {
    vec2 v1(1, 2);
    double t = 2;

    v1 /= t;

    EXPECT_EQ(v1.x(), 0.5);
    EXPECT_EQ(v1.y(), 1);

}

/* Length test "v1.length()" */
TEST(Vec2, Length) {
    vec2 v1(1, 2); // 1^2 + 2^2 = 5

    double length = v1.length();

    EXPECT_EQ(length, sqrt(5));
}

/* Length squared test "v1.length_squared()" */
TEST(Vec2, LengthSquared) {
    vec2 v1(1, 2); // 1^2 + 2^2 = 5

    double length_squared = v1.length_squared();

    EXPECT_EQ(length_squared, 5);
}

/* Point2 test "point2" */
TEST(Vec2, Point2) {
    point2 p1(1, 2);

    EXPECT_EQ(p1.x(), 1);
    EXPECT_EQ(p1.y(), 2);
}

/* ------------------------ */
/* Vector Utility Functions */
/* ------------------------ */

/* Output test "std::cout << v1" */
TEST(Vec2Utility, Output) {
    vec2 v1(1, 2);

    std::stringstream ss;
    ss << v1;

    EXPECT_EQ(ss.str(), "1 2");
}

/* Addition test "u + v" */
TEST(Vec2Utility, Addition) {
    vec2 v1(1, 2);
    vec2 v2(3, 4);

    vec2 v3 = v1 + v2;

    EXPECT_EQ(v3.x(), 4);
    EXPECT_EQ(v3.y(), 6);
}

/* Subtraction test "v1 - v2" */
TEST(Vec2Utility, Subtraction) {
    vec2 v1(1, 2);
    vec2 v2(3, 4);

    vec2 v3 = v1 - v2;

    EXPECT_EQ(v3.x(), -2);
    EXPECT_EQ(v3.y(), -2);
}

/* Multiplication test "v1 * v2" */
TEST(Vec2Utility, MultiplicationTwoVectors) {
    vec2 v1(1, 2);
    vec2 v2(3, 4);

    vec2 v3 = v1 * v2;

    EXPECT_EQ(v3.x(), 3);
    EXPECT_EQ(v3.y(), 8);
}

/* Multiplication test "v1 * t" */
TEST(Vec2Utility, MultiplicationVectorAndScalar) {
    vec2 v1(1, 2);
    double t = 2;

    vec2 v2 = v1 * t;

    EXPECT_EQ(v2.x(), 2);
    EXPECT_EQ(v2.y(), 4);
}

/* Multiplication test "t * v1" */
TEST(Vec2Utility, MultiplicationScalarAndVector) {
    vec2 v1(1, 2);
    double t = 2;

    vec2 v2 = t * v1;

    EXPECT_EQ(v2.x(), 2);
    EXPECT_EQ(v2.y(), 4);
}

/* Division test "v1 / t" */
TEST(Vec2Utility, Division) {
    vec2 v1(1, 2);
    double t = 2;

    vec2 v2 = v1 / t;

    EXPECT_EQ(v2.x(), 0.5);
    EXPECT_EQ(v2.y(), 1);
}

/* Dot product test "dot(v1, v2)" */
TEST(Vec2Utility, DotProduct) {
    vec2 v1(1, 2);
    vec2 v2(3, 4);

    double dot_product = dot(v1, v2);
    /*
     *  1 * 3 = 3
     *  2 * 4 = 8
     *
     *  3 + 8 = 11
     * */
    EXPECT_EQ(dot_product, 11);
}

/* Unit vector test "unit_vector(v1)" */
TEST(Vec2Utility, UnitVector) {
    vec2 v1(1, 2); // 1^2 + 2^2 = 5

    vec2 v2 = unit_vector(v1);

    EXPECT_EQ(v2.x(), 1/sqrt(5));
    EXPECT_EQ(v2.y(), 2/sqrt(5));
}