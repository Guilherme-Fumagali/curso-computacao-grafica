#include <gtest/gtest.h>
#include "mat2.h"

/* -------------- */
/* Mat2 Functions */
/* -------------- */

/* Constructor and accessor test */
TEST(Mat2, Constructor) {
    mat2 m1;
    mat2 m2(vec2(1, 2), vec2(3, 4));

    EXPECT_EQ(m1[0][0], 0);
    EXPECT_EQ(m1[0][1], 0);
    EXPECT_EQ(m1[1][0], 0);
    EXPECT_EQ(m1[1][1], 0);

    EXPECT_EQ(m2[0][0], 1);
    EXPECT_EQ(m2[0][1], 2);
    EXPECT_EQ(m2[1][0], 3);
    EXPECT_EQ(m2[1][1], 4);
}

TEST(Mat2, ConstructorWithNegativeValues) {
    mat2 m1(vec2(-1, -2), vec2(-3, -4));

    EXPECT_EQ(m1[0][0], -1);
    EXPECT_EQ(m1[0][1], -2);
    EXPECT_EQ(m1[1][0], -3);
    EXPECT_EQ(m1[1][1], -4);
}

/* Addition test "m1 = m1 + m2" */
TEST(Mat2, Addition) {
    mat2 m1(vec2(1, 2), vec2(3, 4));
    mat2 m2(vec2(5, 6), vec2(7, 8));

    m1 += m2;

    EXPECT_EQ(m1[0][0], 6);
    EXPECT_EQ(m1[0][1], 8);
    EXPECT_EQ(m1[1][0], 10);
    EXPECT_EQ(m1[1][1], 12);
}

TEST(Mat2, AdditionWithNegativeValues) {
    mat2 m1(vec2(-1, -2), vec2(-3, -4));
    mat2 m2(vec2(-5, -6), vec2(-7, -8));

    m1 += m2;

    EXPECT_EQ(m1[0][0], -6);
    EXPECT_EQ(m1[0][1], -8);
    EXPECT_EQ(m1[1][0], -10);
    EXPECT_EQ(m1[1][1], -12);
}

TEST(Mat2, AdditionWithPositiveAndNegativeValues) {
    mat2 m1(vec2(-1, -2), vec2(-3, -4));
    mat2 m2(vec2(1, 2), vec2(3, 4));

    m1 += m2;

    EXPECT_EQ(m1[0][0], 0);
    EXPECT_EQ(m1[0][1], 0);
    EXPECT_EQ(m1[1][0], 0);
    EXPECT_EQ(m1[1][1], 0);
}

/* Subtraction test "m1 = m1 - m2" */
TEST(Mat2, Subtraction) {
    mat2 m1(vec2(1, 2), vec2(3, 4));
    mat2 m2(vec2(5, 6), vec2(7, 8));

    m1 -= m2;

    for (int i = 0; i < 2; i++)
        for (int j = 0; i < 2; i++)
            EXPECT_EQ(m1[i][j], -4);
}

TEST(Mat2, SubtractionWithNegativeValues) {
    mat2 m1(vec2(-1, -2), vec2(-3, -4));
    mat2 m2(vec2(-5, -6), vec2(-7, -8));

    m1 -= m2;

    for (int i = 0; i < 2; i++)
        for (int j = 0; i < 2; i++)
            EXPECT_EQ(m1[i][j], 4);
}

TEST(Mat2, SubtractionWithPositiveAndNegativeValues) {
    mat2 m1(vec2(-1, -2), vec2(-3, -4));
    mat2 m2(vec2(1, 2), vec2(3, 4));

    m1 -= m2;

    for (int i = 0; i < 2; i++)
        for (int j = 0; i < 2; i++)
            EXPECT_EQ(m1[i][j], -2*i*2 - 2*j - 2);
}

/* Multiplication test "m1 = m1 * t" */
TEST(Mat2, Multiplication) {
    mat2 m1(vec2(1, 2), vec2(3, 4));

    m1 *= 2;

    EXPECT_EQ(m1[0][0], 2);
    EXPECT_EQ(m1[0][1], 4);
    EXPECT_EQ(m1[1][0], 6);
    EXPECT_EQ(m1[1][1], 8);
}

TEST(Mat2, MultiplicationWithNegativeValues) {
    mat2 m1(vec2(-1, -2), vec2(-3, -4));

    m1 *= 2;

    EXPECT_EQ(m1[0][0], -2);
    EXPECT_EQ(m1[0][1], -4);
    EXPECT_EQ(m1[1][0], -6);
    EXPECT_EQ(m1[1][1], -8);
}

/* Division test "m1 = m1 / t" */
TEST(Mat2, Division) {
    mat2 m1(vec2(1, 2), vec2(3, 4));

    m1 /= 2;

    EXPECT_EQ(m1[0][0], 0.5);
    EXPECT_EQ(m1[0][1], 1);
    EXPECT_EQ(m1[1][0], 1.5);
    EXPECT_EQ(m1[1][1], 2);
}

TEST(Mat2, DivisionWithNegativeValues) {
    mat2 m1(vec2(-1, -2), vec2(-3, -4));

    m1 /= 2;

    EXPECT_EQ(m1[0][0], -0.5);
    EXPECT_EQ(m1[0][1], -1);
    EXPECT_EQ(m1[1][0], -1.5);
    EXPECT_EQ(m1[1][1], -2);
}

TEST(Mat2, DivisionByZero) {
    mat2 m1(vec2(-1, -2), vec2(-3, -4));

    m1 /= 0;

    for (int i = 0; i < 2; i++)
        for (int j = 0; i < 2; i++)
            EXPECT_TRUE(std::isinf(m1[i][j]));
}

/* ------------------------ */
/* Matrix Utility Functions */
/* ------------------------ */

/* Output stream test */
TEST(Mat2, Output) {
    mat2 m1(vec2(1, 2), vec2(3, 4));

    std::stringstream ss;
    ss << m1;

    EXPECT_EQ(ss.str(), "1 2\n3 4");
}

/* Addition test "m1 + m2" */
TEST(Mat2Utility, Addition) {
    mat2 m1(vec2(1, 2), vec2(3, 4));
    mat2 m2(vec2(5, 6), vec2(7, 8));

    mat2 m3 = m1 + m2;

    EXPECT_EQ(m3[0][0], 6);
    EXPECT_EQ(m3[0][1], 8);
    EXPECT_EQ(m3[1][0], 10);
    EXPECT_EQ(m3[1][1], 12);
}

/* Subtraction test "m1 - m2" */
TEST(Mat2Utility, Subtraction) {
    mat2 m1(vec2(1, 2), vec2(3, 4));
    mat2 m2(vec2(5, 6), vec2(7, 8));

    mat2 m3 = m1 - m2;

    EXPECT_EQ(m3[0][0], -4);
    EXPECT_EQ(m3[0][1], -4);
    EXPECT_EQ(m3[1][0], -4);
    EXPECT_EQ(m3[1][1], -4);
}

/* Multiplication test "m1 * t" */
TEST(Mat2Utility, Multiplication) {
    mat2 m1(vec2(1, 2), vec2(3, 4));
    double t = 2;

    mat2 m2 = m1 * t;

    EXPECT_EQ(m2[0][0], 2);
    EXPECT_EQ(m2[0][1], 4);
    EXPECT_EQ(m2[1][0], 6);
    EXPECT_EQ(m2[1][1], 8);
}

/* Multiplication test "t * m1" */
TEST(Mat2Utility, MultiplicationScalarAndMatrix) {
    mat2 m1(vec2(1, 2), vec2(3, 4));
    double t = 2;

    mat2 m2 = t * m1;

    EXPECT_EQ(m2[0][0], 2);
    EXPECT_EQ(m2[0][1], 4);
    EXPECT_EQ(m2[1][0], 6);
    EXPECT_EQ(m2[1][1], 8);
}

/* Multiplication test "m1 * v1" */
TEST(Mat2Utility, MultiplicationMatrixAndVec2) {
    mat2 m1(vec2(1, 2), vec2(3, 4));
    vec2 v1(5, 6);

    vec2 v2 = m1 * v1;

    EXPECT_EQ(v2.x(), 17);
    EXPECT_EQ(v2.y(), 39);
}

/* Multiplication test "v1 * m1" */
TEST(Mat2Utility, MultiplicationVec2AndMatrix) {
    mat2 m1(vec2(1, 2), vec2(3, 4));
    vec2 v1(5, 6);

    vec2 v2 = v1 * m1;

    EXPECT_EQ(v2.x(), 17);
    EXPECT_EQ(v2.y(), 39);
}

/* Division test "m1 / t" */
TEST(Mat2Utility, Division) {
    mat2 m1(vec2(1, 2), vec2(3, 4));
    double t = 2;

    mat2 m2 = m1 / t;

    EXPECT_EQ(m2[0][0], 0.5);
    EXPECT_EQ(m2[0][1], 1);
    EXPECT_EQ(m2[1][0], 1.5);
    EXPECT_EQ(m2[1][1], 2);
}

