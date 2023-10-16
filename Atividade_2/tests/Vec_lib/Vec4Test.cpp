#include "gtest/gtest.h"
#include "vec4.h"

/* -------------- */
/* Vec4 Functions */
/* -------------- */

/* Constructor and accessor test */
TEST(Vec4, Constructor) {
    vec4 v1;
    vec4 v2(1, 2, 3, 4);

    EXPECT_EQ(v1.x(), 0);
    EXPECT_EQ(v1.y(), 0);
    EXPECT_EQ(v1.z(), 0);
    EXPECT_EQ(v1.w(), 0);

    EXPECT_EQ(v2.x(), 1);
    EXPECT_EQ(v2.y(), 2);
    EXPECT_EQ(v2.z(), 3);
    EXPECT_EQ(v2.w(), 4);
}

/* Negation test "-v1" */
TEST(Vec4, Negation) {
    vec4 v1(1, 2, 3, 4);

    vec4 v2 = -v1;

    EXPECT_EQ(v2.x(), -1);
    EXPECT_EQ(v2.y(), -2);
    EXPECT_EQ(v2.z(), -3);
    EXPECT_EQ(v2.w(), -4);
}

/* Subscript test "v1[i]" */
TEST(Vec4, Subscript) {
    vec4 v1(1, 2, 3, 4);

    EXPECT_EQ(v1[0], 1);
    EXPECT_EQ(v1[1], 2);
    EXPECT_EQ(v1[2], 3);
    EXPECT_EQ(v1[3], 4);

    v1[0] = 5;
    v1[1] = 6;
    v1[2] = 7;
    v1[3] = 8;

    EXPECT_EQ(v1[0], 5);
    EXPECT_EQ(v1[1], 6);
    EXPECT_EQ(v1[2], 7);
    EXPECT_EQ(v1[3], 8);
}

/* Addition test "v1 = v1 + v2" */
TEST(Vec4, Addition) {
    vec4 v1(1, 2, 3, 4);
    vec4 v2(5, 6, 7, 8);

    v1 += v2;

    EXPECT_EQ(v1.x(), 6);
    EXPECT_EQ(v1.y(), 8);
    EXPECT_EQ(v1.z(), 10);
    EXPECT_EQ(v1.w(), 12);
}

/* Subtraction test "v1 = v1 - v2" */
TEST(Vec4, Subtraction) {
    vec4 v1(1, 2, 3, 4);
    vec4 v2(5, 6, 7, 8);

    v1 -= v2;

    EXPECT_EQ(v1.x(), -4);
    EXPECT_EQ(v1.y(), -4);
    EXPECT_EQ(v1.z(), -4);
    EXPECT_EQ(v1.w(), -4);
}

/* Multiplication test "v1 = v1 * t" */
TEST(Vec4, Multiplication) {
    vec4 v1(1, 2, 3, 4);

    v1 *= 2;

    EXPECT_EQ(v1.x(), 2);
    EXPECT_EQ(v1.y(), 4);
    EXPECT_EQ(v1.z(), 6);
    EXPECT_EQ(v1.w(), 8);
}

/* Division test "v1 = v1 / t" */
TEST(Vec4, Division) {
    vec4 v1(1, 2, 3, 4);

    v1 /= 2;

    EXPECT_EQ(v1.x(), 0.5);
    EXPECT_EQ(v1.y(), 1);
    EXPECT_EQ(v1.z(), 1.5);
    EXPECT_EQ(v1.w(), 2);
}

/* Length test "v1.length()" */
TEST(Vec4, Length) {
    vec4 v1(1, 2, 3, 4); // 1^2 + 2^2 + 3^2 + 4^2 = 30

    EXPECT_EQ(v1.length(), sqrt(30));
}

/* Length Squared test "v1.length_squared()" */
TEST(Vec4, LengthSquared) {
    vec4 v1(1, 2, 3, 4); // 1^2 + 2^2 + 3^2 + 4^2 = 30

    EXPECT_EQ(v1.length_squared(), 30);
}

/* Point4 test "point4(x, y, z, w)" */
TEST(Vec4, Point4) {
    point4 p1(1, 2, 3, 4);

    EXPECT_EQ(p1.x(), 1);
    EXPECT_EQ(p1.y(), 2);
    EXPECT_EQ(p1.z(), 3);
    EXPECT_EQ(p1.w(), 4);
}

/* ------------------------ */
/* Vector Utility Functions */
/* ------------------------ */

/* Output test "std::cout << v1" */
TEST(Vec4, Output) {
    vec4 v1(1, 2, 3, 4);

    std::stringstream ss;
    ss << v1;

    EXPECT_EQ(ss.str(), "1 2 3 4");
}

/* Addition test "v1 + v2" */
TEST(Vec4Utility, Addition) {
    vec4 v1(1, 2, 3, 4);
    vec4 v2(5, 6, 7, 8);

    vec4 v3 = v1 + v2;

    EXPECT_EQ(v3.x(), 6);
    EXPECT_EQ(v3.y(), 8);
    EXPECT_EQ(v3.z(), 10);
    EXPECT_EQ(v3.w(), 12);
}

/* Subtraction test "v1 - v2" */
TEST(Vec4Utility, Subtraction) {
    vec4 v1(1, 2, 3, 4);
    vec4 v2(5, 6, 7, 8);

    vec4 v3 = v1 - v2;

    EXPECT_EQ(v3.x(), -4);
    EXPECT_EQ(v3.y(), -4);
    EXPECT_EQ(v3.z(), -4);
    EXPECT_EQ(v3.w(), -4);
}

/* Multiplication test "v1 * v2" */
TEST(Vec4Utility, MultiplicationTwoVec4) {
    vec4 v1(1, 2, 3, 4);
    vec4 v2(5, 6, 7, 8);

    vec4 v3 = v1 * v2;

    EXPECT_EQ(v3.x(), 5);
    EXPECT_EQ(v3.y(), 12);
    EXPECT_EQ(v3.z(), 21);
    EXPECT_EQ(v3.w(), 32);
}

/* Multiplication test "v1 * t" */
TEST(Vec4Utility, MultiplicationVectorAndScalar) {
    vec4 v1(1, 2, 3, 4);
    double t = 2;

    vec4 v2 = v1 * t;

    EXPECT_EQ(v2.x(), 2);
    EXPECT_EQ(v2.y(), 4);
    EXPECT_EQ(v2.z(), 6);
    EXPECT_EQ(v2.w(), 8);
}

/* Multiplication test "t * v1" */
TEST(Vec4Utility, MultiplicationScalarAndVector) {
    vec4 v1(1, 2, 3, 4);
    double t = 2;

    vec4 v2 = t * v1;

    EXPECT_EQ(v2.x(), 2);
    EXPECT_EQ(v2.y(), 4);
    EXPECT_EQ(v2.z(), 6);
    EXPECT_EQ(v2.w(), 8);
}

/* Division test "v1 / t" */
TEST(Vec4Utility, Division) {
    vec4 v1(1, 2, 3, 4);
    double t = 2;

    vec4 v2 = v1 / t;

    EXPECT_EQ(v2.x(), 0.5);
    EXPECT_EQ(v2.y(), 1);
    EXPECT_EQ(v2.z(), 1.5);
    EXPECT_EQ(v2.w(), 2);
}

/* Dot product test "dot(v1, v2)" */
TEST(Vec4Utility, DotProduct) {
    vec4 v1(1, 2, 3, 4);
    vec4 v2(5, 6, 7, 8);

    double dot_result = dot(v1, v2);

    /* 1 * 5 + 2 * 6 + 3 * 7 + 4 * 8 = 70 */

    EXPECT_EQ(dot_result, 70);
}

/* Cross product test "cross(v1, v2)" */
TEST(Vec4Utility, CrossProduct) {
    vec4 v1(1, 2, 3, 4);
    vec4 v2(5, 6, 7, 8);

    vec4 v3 = cross(v1, v2);

    /* (2 * 7 - 3 * 6, 3 * 5 - 1 * 7, 1 * 6 - 2 * 5) = (-4, 8, -4) */

    EXPECT_EQ(v3.x(), -4);
    EXPECT_EQ(v3.y(), 8);
    EXPECT_EQ(v3.z(), -4);
    EXPECT_EQ(v3.w(), 0);
}

/* Unit vector test "unit_vector(v1)" */
TEST(Vec4Utility, UnitVector) {
    vec4 v1(1, 2, 3, 4); // 1^2 + 2^2 + 3^2 + 4^2 = 30

    vec4 v2 = unit_vector(v1);

    EXPECT_EQ(v2.x(), 1/sqrt(30));
    EXPECT_EQ(v2.y(), 2/sqrt(30));
    EXPECT_EQ(v2.z(), 3/sqrt(30));
    EXPECT_EQ(v2.w(), 4/sqrt(30));
}

