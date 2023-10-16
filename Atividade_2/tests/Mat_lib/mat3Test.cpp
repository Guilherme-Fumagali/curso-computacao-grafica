#include "gtest/gtest.h"
#include "mat3.h"

/* -------------- */
/* Mat3 Functions */
/* -------------- */

/* Constructor and accessor test */
TEST(Mat3, Constructor) {
    mat3 m1;
    mat3 m2(vec3(1, 2, 3), vec3(4, 5, 6), vec3(7, 8, 9));

    for (int i = 0; i < 3; i++)
        for (int j = 0; i < 3; i++)
            EXPECT_EQ(m1[i][j], 0);

    for (int i = 0; i < 3; i++)
        for (int j = 0; i < 3; i++)
            EXPECT_EQ(m2[i][j], i*3 + j + 1);
}

/* Addition test "m1 = m1 + m2" */
TEST(Mat3, Addition) {
    mat3 m1(vec3(1, 2, 3), vec3(4, 5, 6), vec3(7, 8, 9));
    mat3 m2(vec3(10, 11, 12), vec3(13, 14, 15), vec3(16, 17, 18));

    m1 += m2;

    EXPECT_EQ(m1[0][0], 11);
    EXPECT_EQ(m1[0][1], 13);
    EXPECT_EQ(m1[0][2], 15);
    EXPECT_EQ(m1[1][0], 17);
    EXPECT_EQ(m1[1][1], 19);
    EXPECT_EQ(m1[1][2], 21);
    EXPECT_EQ(m1[2][0], 23);
    EXPECT_EQ(m1[2][1], 25);
    EXPECT_EQ(m1[2][2], 27);
}

/* Subtraction test "m1 = m1 - m2" */
TEST(Mat3, Subtraction) {
    mat3 m1(vec3(1, 2, 3), vec3(4, 5, 6), vec3(7, 8, 9));
    mat3 m2(vec3(10, 11, 12), vec3(13, 14, 15), vec3(16, 17, 18));

    m1 -= m2;

    for (int i = 0; i < 3; i++)
        for (int j = 0; i < 3; i++)
            EXPECT_EQ(m1[i][j], -9);
}

/* Multiplication test "m1 = m1 * t" */
TEST(Mat3, Multiplication) {
    mat3 m1(vec3(1, 2, 3), vec3(4, 5, 6), vec3(7, 8, 9));

    m1 *= 2;

    EXPECT_EQ(m1[0][0], 2);
    EXPECT_EQ(m1[0][1], 4);
    EXPECT_EQ(m1[0][2], 6);
    EXPECT_EQ(m1[1][0], 8);
    EXPECT_EQ(m1[1][1], 10);
    EXPECT_EQ(m1[1][2], 12);
    EXPECT_EQ(m1[2][0], 14);
    EXPECT_EQ(m1[2][1], 16);
    EXPECT_EQ(m1[2][2], 18);
}

/* Division test "m1 = m1 / t" */
TEST(Mat3, Division) {
    mat3 m1(vec3(1, 2, 3), vec3(4, 5, 6), vec3(7, 8, 9));

    m1 /= 2;

    EXPECT_EQ(m1[0][0], 0.5);
    EXPECT_EQ(m1[0][1], 1);
    EXPECT_EQ(m1[0][2], 1.5);
    EXPECT_EQ(m1[1][0], 2);
    EXPECT_EQ(m1[1][1], 2.5);
    EXPECT_EQ(m1[1][2], 3);
    EXPECT_EQ(m1[2][0], 3.5);
    EXPECT_EQ(m1[2][1], 4);
    EXPECT_EQ(m1[2][2], 4.5);
}

/* ------------------------ */
/* Matrix Utility Functions */
/* ------------------------ */

/* Output test */
TEST(Mat3, Output) {
    mat3 m1(vec3(1, 2, 3), vec3(4, 5, 6), vec3(7, 8, 9));

    std::stringstream ss;
    ss << m1;

    EXPECT_EQ(ss.str(), "1 2 3\n4 5 6\n7 8 9");
}

/* Addition test "m1 + m2" */
TEST(Mat3Utility, Addition) {
    mat3 m1(vec3(1, 2, 3), vec3(4, 5, 6), vec3(7, 8, 9));
    mat3 m2(vec3(10, 11, 12), vec3(13, 14, 15), vec3(16, 17, 18));

    mat3 m3 = m1 + m2;

    EXPECT_EQ(m3[0][0], 11);
    EXPECT_EQ(m3[0][1], 13);
    EXPECT_EQ(m3[0][2], 15);
    EXPECT_EQ(m3[1][0], 17);
    EXPECT_EQ(m3[1][1], 19);
    EXPECT_EQ(m3[1][2], 21);
    EXPECT_EQ(m3[2][0], 23);
    EXPECT_EQ(m3[2][1], 25);
    EXPECT_EQ(m3[2][2], 27);
}

/* Subtraction test "m1 - m2" */
TEST(Mat3Utility, Subtraction) {
    mat3 m1(vec3(1, 2, 3), vec3(4, 5, 6), vec3(7, 8, 9));
    mat3 m2(vec3(10, 11, 12), vec3(13, 14, 15), vec3(16, 17, 18));

    mat3 m3 = m1 - m2;

    for (int i = 0; i < 3; i++)
        for (int j = 0; i < 3; i++)
            EXPECT_EQ(m3[i][j], -9);
}

/* Multiplication test "m1 * t and t * m1" */
TEST(Mat3Utility, Multiplication) {
    mat3 m1(vec3(1, 2, 3), vec3(4, 5, 6), vec3(7, 8, 9));

    mat3 m2 = m1 * 2;
    mat3 m3 = 2 * m1;

    EXPECT_EQ(m2[0][0], 2);
    EXPECT_EQ(m2[0][1], 4);
    EXPECT_EQ(m2[0][2], 6);
    EXPECT_EQ(m2[1][0], 8);
    EXPECT_EQ(m2[1][1], 10);
    EXPECT_EQ(m2[1][2], 12);
    EXPECT_EQ(m2[2][0], 14);
    EXPECT_EQ(m2[2][1], 16);
    EXPECT_EQ(m2[2][2], 18);

    EXPECT_EQ(m3[0][0], 2);
    EXPECT_EQ(m3[0][1], 4);
    EXPECT_EQ(m3[0][2], 6);
    EXPECT_EQ(m3[1][0], 8);
    EXPECT_EQ(m3[1][1], 10);
    EXPECT_EQ(m3[1][2], 12);
    EXPECT_EQ(m3[2][0], 14);
    EXPECT_EQ(m3[2][1], 16);
    EXPECT_EQ(m3[2][2], 18);
}

/* Division test "m1 / t" */
TEST(Mat3Utility, Division) {
    mat3 m1(vec3(1, 2, 3), vec3(4, 5, 6), vec3(7, 8, 9));

    mat3 m2 = m1 / 2;

    EXPECT_EQ(m2[0][0], 0.5);
    EXPECT_EQ(m2[0][1], 1);
    EXPECT_EQ(m2[0][2], 1.5);
    EXPECT_EQ(m2[1][0], 2);
    EXPECT_EQ(m2[1][1], 2.5);
    EXPECT_EQ(m2[1][2], 3);
    EXPECT_EQ(m2[2][0], 3.5);
    EXPECT_EQ(m2[2][1], 4);
    EXPECT_EQ(m2[2][2], 4.5);
}