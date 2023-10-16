#include "gtest/gtest.h"
#include "mat4.h"

/* -------------- */
/* Mat4 Functions */
/* -------------- */

/* Constructor and accessor test */
TEST(Mat4, Constructor) {
    mat4 m1;
    mat4 m2(vec4(1, 2, 3, 4), vec4(5, 6, 7, 8), vec4(9, 10, 11, 12), vec4(13, 14, 15, 16));

    for (int i = 0; i < 4; i++)
        for (int j = 0; i < 4; i++)
            EXPECT_EQ(m1[i][j], 0);

    for (int i = 0; i < 4; i++)
        for (int j = 0; i < 4; i++)
            EXPECT_EQ(m2[i][j], i*4 + j + 1);
}

/* Addition test "m1 = m1 + m2" */
TEST(Mat4, Addition) {
    mat4 m1(vec4(1, 2, 3, 4), vec4(5, 6, 7, 8), vec4(9, 10, 11, 12), vec4(13, 14, 15, 16));
    mat4 m2(vec4(17, 18, 19, 20), vec4(21, 22, 23, 24), vec4(25, 26, 27, 28), vec4(29, 30, 31, 32));

    m1 += m2;

    EXPECT_EQ(m1[0][0], 18);
    EXPECT_EQ(m1[0][1], 20);
    EXPECT_EQ(m1[0][2], 22);
    EXPECT_EQ(m1[0][3], 24);
    EXPECT_EQ(m1[1][0], 26);
    EXPECT_EQ(m1[1][1], 28);
    EXPECT_EQ(m1[1][2], 30);
    EXPECT_EQ(m1[1][3], 32);
    EXPECT_EQ(m1[2][0], 34);
    EXPECT_EQ(m1[2][1], 36);
    EXPECT_EQ(m1[2][2], 38);
    EXPECT_EQ(m1[2][3], 40);
    EXPECT_EQ(m1[3][0], 42);
    EXPECT_EQ(m1[3][1], 44);
    EXPECT_EQ(m1[3][2], 46);
    EXPECT_EQ(m1[3][3], 48);
}

/* Subtraction test "m1 = m1 - m2" */
TEST(Mat4, Subtraction) {
    mat4 m1(vec4(1, 2, 3, 4), vec4(5, 6, 7, 8), vec4(9, 10, 11, 12), vec4(13, 14, 15, 16));
    mat4 m2(vec4(17, 18, 19, 20), vec4(21, 22, 23, 24), vec4(25, 26, 27, 28), vec4(29, 30, 31, 32));

    m1 -= m2;

    for (int i = 0; i < 4; i++)
        for (int j = 0; i < 4; i++)
            EXPECT_EQ(m1[i][j], -16);
}

/* Multiplication test "m1 = m1 * t" */
TEST(Mat4, Multiplication) {
    mat4 m1(vec4(1, 2, 3, 4), vec4(5, 6, 7, 8), vec4(9, 10, 11, 12), vec4(13, 14, 15, 16));

    m1 *= 2;

    EXPECT_EQ(m1[0][0], 2);
    EXPECT_EQ(m1[0][1], 4);
    EXPECT_EQ(m1[0][2], 6);
    EXPECT_EQ(m1[0][3], 8);
    EXPECT_EQ(m1[1][0], 10);
    EXPECT_EQ(m1[1][1], 12);
    EXPECT_EQ(m1[1][2], 14);
    EXPECT_EQ(m1[1][3], 16);
    EXPECT_EQ(m1[2][0], 18);
    EXPECT_EQ(m1[2][1], 20);
    EXPECT_EQ(m1[2][2], 22);
    EXPECT_EQ(m1[2][3], 24);
    EXPECT_EQ(m1[3][0], 26);
    EXPECT_EQ(m1[3][1], 28);
    EXPECT_EQ(m1[3][2], 30);
    EXPECT_EQ(m1[3][3], 32);
}

/* Division test "m1 = m1 / t" */
TEST(Mat4, Division) {
    mat4 m1(vec4(1, 2, 3, 4), vec4(5, 6, 7, 8), vec4(9, 10, 11, 12), vec4(13, 14, 15, 16));

    m1 /= 2;

    EXPECT_EQ(m1[0][0], 0.5);
    EXPECT_EQ(m1[0][1], 1);
    EXPECT_EQ(m1[0][2], 1.5);
    EXPECT_EQ(m1[0][3], 2);
    EXPECT_EQ(m1[1][0], 2.5);
    EXPECT_EQ(m1[1][1], 3);
    EXPECT_EQ(m1[1][2], 3.5);
    EXPECT_EQ(m1[1][3], 4);
    EXPECT_EQ(m1[2][0], 4.5);
    EXPECT_EQ(m1[2][1], 5);
    EXPECT_EQ(m1[2][2], 5.5);
    EXPECT_EQ(m1[2][3], 6);
    EXPECT_EQ(m1[3][0], 6.5);
    EXPECT_EQ(m1[3][1], 7);
    EXPECT_EQ(m1[3][2], 7.5);
    EXPECT_EQ(m1[3][3], 8);
}

/* ------------------------ */
/* Matrix Utility Functions */
/* ------------------------ */

/* Output test "cout << m1" */
TEST(Mat4Utility, Output) {
    mat4 m1(vec4(1, 2, 3, 4), vec4(5, 6, 7, 8), vec4(9, 10, 11, 12), vec4(13, 14, 15, 16));

    std::stringstream ss;
    ss << m1;

    EXPECT_EQ(ss.str(), "1 2 3 4\n5 6 7 8\n9 10 11 12\n13 14 15 16");
}

/* Addition test "m1 + m2" */
TEST(Mat4Utility, Addition) {
    mat4 m1(vec4(1, 2, 3, 4), vec4(5, 6, 7, 8), vec4(9, 10, 11, 12), vec4(13, 14, 15, 16));
    mat4 m2(vec4(17, 18, 19, 20), vec4(21, 22, 23, 24), vec4(25, 26, 27, 28), vec4(29, 30, 31, 32));

    mat4 m3 = m1 + m2;

    EXPECT_EQ(m3[0][0], 18);
    EXPECT_EQ(m3[0][1], 20);
    EXPECT_EQ(m3[0][2], 22);
    EXPECT_EQ(m3[0][3], 24);
    EXPECT_EQ(m3[1][0], 26);
    EXPECT_EQ(m3[1][1], 28);
    EXPECT_EQ(m3[1][2], 30);
    EXPECT_EQ(m3[1][3], 32);
    EXPECT_EQ(m3[2][0], 34);
    EXPECT_EQ(m3[2][1], 36);
    EXPECT_EQ(m3[2][2], 38);
    EXPECT_EQ(m3[2][3], 40);
    EXPECT_EQ(m3[3][0], 42);
    EXPECT_EQ(m3[3][1], 44);
    EXPECT_EQ(m3[3][2], 46);
    EXPECT_EQ(m3[3][3], 48);
}

/* Subtraction test "m1 - m2" */
TEST(Mat4Utility, Subtraction) {
    mat4 m1(vec4(1, 2, 3, 4), vec4(5, 6, 7, 8), vec4(9, 10, 11, 12), vec4(13, 14, 15, 16));
    mat4 m2(vec4(17, 18, 19, 20), vec4(21, 22, 23, 24), vec4(25, 26, 27, 28), vec4(29, 30, 31, 32));

    mat4 m3 = m1 - m2;

    for (int i = 0; i < 4; i++)
        for (int j = 0; i < 4; i++)
            EXPECT_EQ(m3[i][j], -16);
}

/* Multiplication test "m1 * t" and "t * m1" */
TEST(Mat4Utility, Multiplication) {
    mat4 m1(vec4(1, 2, 3, 4), vec4(5, 6, 7, 8), vec4(9, 10, 11, 12), vec4(13, 14, 15, 16));

    mat4 m3 = m1 * 2;
    mat4 m4 = 2 * m1;

    EXPECT_EQ(m3[0][0], 2);
    EXPECT_EQ(m3[0][1], 4);
    EXPECT_EQ(m3[0][2], 6);
    EXPECT_EQ(m3[0][3], 8);
    EXPECT_EQ(m3[1][0], 10);
    EXPECT_EQ(m3[1][1], 12);
    EXPECT_EQ(m3[1][2], 14);
    EXPECT_EQ(m3[1][3], 16);
    EXPECT_EQ(m3[2][0], 18);
    EXPECT_EQ(m3[2][1], 20);
    EXPECT_EQ(m3[2][2], 22);
    EXPECT_EQ(m3[2][3], 24);
    EXPECT_EQ(m3[3][0], 26);
    EXPECT_EQ(m3[3][1], 28);
    EXPECT_EQ(m3[3][2], 30);
    EXPECT_EQ(m3[3][3], 32);
}

/* Division test "m1 / t" */
TEST(Mat4Utility, Division) {
    mat4 m1(vec4(1, 2, 3, 4), vec4(5, 6, 7, 8), vec4(9, 10, 11, 12), vec4(13, 14, 15, 16));

    mat4 m3 = m1 / 2;

    EXPECT_EQ(m3[0][0], 0.5);
    EXPECT_EQ(m3[0][1], 1);
    EXPECT_EQ(m3[0][2], 1.5);
    EXPECT_EQ(m3[0][3], 2);
    EXPECT_EQ(m3[1][0], 2.5);
    EXPECT_EQ(m3[1][1], 3);
    EXPECT_EQ(m3[1][2], 3.5);
    EXPECT_EQ(m3[1][3], 4);
    EXPECT_EQ(m3[2][0], 4.5);
    EXPECT_EQ(m3[2][1], 5);
    EXPECT_EQ(m3[2][2], 5.5);
    EXPECT_EQ(m3[2][3], 6);
    EXPECT_EQ(m3[3][0], 6.5);
    EXPECT_EQ(m3[3][1], 7);
    EXPECT_EQ(m3[3][2], 7.5);
    EXPECT_EQ(m3[3][3], 8);
}

