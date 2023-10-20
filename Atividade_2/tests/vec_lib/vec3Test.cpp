#include <gtest/gtest.h>
#include "vec3.h"

/* -------------- */
/* Vec3 Functions */
/* -------------- */

/* Constructor and accessor test */
TEST(Vec3, Constructor) {
    vec3 v1;
    vec3 v2(1, 2, 3);

    EXPECT_EQ(v1.x(), 0);
    EXPECT_EQ(v1.y(), 0);
    EXPECT_EQ(v1.z(), 0);

    EXPECT_EQ(v2.x(), 1);
    EXPECT_EQ(v2.y(), 2);
    EXPECT_EQ(v2.z(), 3);
}

TEST(Vec3, ConstructorWithNegativeValues) {
    vec3 v1(-1, -2, -3);

    EXPECT_EQ(v1.x(), -1);
    EXPECT_EQ(v1.y(), -2);
    EXPECT_EQ(v1.z(), -3);
}

/* Negation test "-v1" */
TEST(Vec3, Negation) {
    vec3 v1(1, 2, 3);

    vec3 v2 = -v1;

    EXPECT_EQ(v2.x(), -1);
    EXPECT_EQ(v2.y(), -2);
    EXPECT_EQ(v2.z(), -3);
}

TEST(Vec3, NegationWithNegativeValues) {
    vec3 v1(-1, -2, -3);

    vec3 v2 = -v1;

    EXPECT_EQ(v2.x(), 1);
    EXPECT_EQ(v2.y(), 2);
    EXPECT_EQ(v2.z(), 3);
}

/* Subscript test "v1[i]" */
TEST(Vec3, Subscript) {
    vec3 v1(1, 2, 3);

    EXPECT_EQ(v1[0], 1);
    EXPECT_EQ(v1[1], 2);
    EXPECT_EQ(v1[2], 3);

    v1[0] = 4;
    v1[1] = 5;
    v1[2] = 6;

    EXPECT_EQ(v1[0], 4);
    EXPECT_EQ(v1[1], 5);
    EXPECT_EQ(v1[2], 6);
}

/* Addition test "v1 = v1 + v2" */
TEST(Vec3, Addition) {
    vec3 v1(1, 2, 3);
    vec3 v2(4, 5, 6);

    v1 += v2;

    EXPECT_EQ(v1.x(), 5);
    EXPECT_EQ(v1.y(), 7);
    EXPECT_EQ(v1.z(), 9);
}

TEST(Vec3, AdditionWithNegativeValues) {
    vec3 v1(-1, -2, -3);
    vec3 v2(-4, -5, -6);

    v1 += v2;

    EXPECT_EQ(v1.x(), -5);
    EXPECT_EQ(v1.y(), -7);
    EXPECT_EQ(v1.z(), -9);
}

TEST(Vec3, AdditionWithPositiveAndNegativeValues) {
    vec3 v1(-1, -2, -3);
    vec3 v2(1, 2, 3);

    v1 += v2;

    EXPECT_EQ(v1.x(), 0);
    EXPECT_EQ(v1.y(), 0);
    EXPECT_EQ(v1.z(), 0);
}

/* Subtraction test "v1 = v1 - v2" */
TEST(Vec3, Subtraction) {
    vec3 v1(1, 2, 3);
    vec3 v2(4, 5, 6);

    v1 -= v2;

    EXPECT_EQ(v1.x(), -3);
    EXPECT_EQ(v1.y(), -3);
    EXPECT_EQ(v1.z(), -3);
}

TEST(Vec3, SubtractionWithNegativeValues) {
    vec3 v1(-1, -2, -3);
    vec3 v2(-4, -5, -6);

    v1 -= v2;

    EXPECT_EQ(v1.x(), 3);
    EXPECT_EQ(v1.y(), 3);
    EXPECT_EQ(v1.z(), 3);
}

TEST(Vec3, SubtractionWithPositiveAndNegativeValues) {
    vec3 v1(-1, -2, -3);
    vec3 v2(1, 2, 3);

    v1 -= v2;

    EXPECT_EQ(v1.x(), -2);
    EXPECT_EQ(v1.y(), -4);
    EXPECT_EQ(v1.z(), -6);
}

/* Multiplication test "v1 = v1 * t" */
TEST(Vec3, Multiplication) {
    vec3 v1(1, 2, 3);

    v1 *= 2;

    EXPECT_EQ(v1.x(), 2);
    EXPECT_EQ(v1.y(), 4);
    EXPECT_EQ(v1.z(), 6);
}

TEST(Vec3, MultiplicationWithNegativeValues) {
    vec3 v1(-1, -2, -3);

    v1 *= 2;

    EXPECT_EQ(v1.x(), -2);
    EXPECT_EQ(v1.y(), -4);
    EXPECT_EQ(v1.z(), -6);
}

/* Division test "v1 = v1 / t" */
TEST(Vec3, Division) {
    vec3 v1(1, 2, 3);

    v1 /= 2;

    EXPECT_EQ(v1.x(), 0.5);
    EXPECT_EQ(v1.y(), 1);
    EXPECT_EQ(v1.z(), 1.5);
}

TEST(Vec3, DivisionWithNegativeValues) {
    vec3 v1(-1, -2, -3);

    v1 /= 2;

    EXPECT_EQ(v1.x(), -0.5);
    EXPECT_EQ(v1.y(), -1);
    EXPECT_EQ(v1.z(), -1.5);
}

TEST(Vec3, DivisionByZero) {
    vec3 v1(1, 2, 3);

    v1 /= 0;

    ASSERT_TRUE(std::isinf(v1.x()));
    ASSERT_TRUE(std::isinf(v1.y()));
    ASSERT_TRUE(std::isinf(v1.z()));
}

/* Length test "v1.length()" */
TEST(Vec3, Length) {
    vec3 v1(1, 2, 3); // 1^2 + 2^2 + 3^2 = 14

    EXPECT_EQ(v1.length(), sqrt(14));
}

TEST(Vec3, LengthWithNegativeValues) {
    vec3 v1(-1, -2, -3); // 1^2 + 2^2 + 3^2 = 14

    EXPECT_EQ(v1.length(), sqrt(14));
}

TEST(Vec3, LengthWithZeroValues) {
    vec3 v1(0, 0, 0); // 0^2 + 0^2 + 0^2 = 0

    EXPECT_EQ(v1.length(), 0);
}

/* Length squared test "v1.length_squared()" */
TEST(Vec3, LengthSquared) {
    vec3 v1(1, 2, 3); // 1^2 + 2^2 + 3^2 = 14

    EXPECT_EQ(v1.length_squared(), 14);
}

TEST(Vec3, LengthSquaredWithNegativeValues) {
    vec3 v1(-1, -2, -3); // 1^2 + 2^2 + 3^2 = 14

    EXPECT_EQ(v1.length_squared(), 14);
}

TEST(Vec3, LengthSquaredWithZeroValues) {
    vec3 v1(0, 0, 0); // 0^2 + 0^2 + 0^2 = 0

    EXPECT_EQ(v1.length_squared(), 0);
}

/* Point3 test "point3(x, y, z)" */
TEST(Vec3, Point3) {
    point3 p1(1, 2, 3);

    EXPECT_EQ(p1.x(), 1);
    EXPECT_EQ(p1.y(), 2);
    EXPECT_EQ(p1.z(), 3);
}

/* ------------------------ */
/* Vector Utility Functions */
/* ------------------------ */

/* Output stream test "cout << v1" */
TEST(Vec3, Output) {
    vec3 v1(1, 2, 3);

    std::stringstream ss;
    ss << v1;

    EXPECT_EQ(ss.str(), "1 2 3");
}

/* Addition test "v1 + v2" */
TEST(Vec3Utility, Addition) {
    vec3 v1(1, 2, 3);
    vec3 v2(4, 5, 6);

    vec3 v3 = v1 + v2;

    EXPECT_EQ(v3.x(), 5);
    EXPECT_EQ(v3.y(), 7);
    EXPECT_EQ(v3.z(), 9);
}

/* Subtraction test "v1 - v2" */
TEST(Vec3Utility, Subtraction) {
    vec3 v1(1, 2, 3);
    vec3 v2(4, 5, 6);

    vec3 v3 = v1 - v2;

    EXPECT_EQ(v3.x(), -3);
    EXPECT_EQ(v3.y(), -3);
    EXPECT_EQ(v3.z(), -3);
}

/* Multiplication test "v1 * v2" */
TEST(Vec3Utility, MultiplicationTwoVec3) {
    vec3 v1(1, 2, 3);
    vec3 v2(4, 5, 6);

    vec3 v3 = v1 * v2;

    EXPECT_EQ(v3.x(), 4);
    EXPECT_EQ(v3.y(), 10);
    EXPECT_EQ(v3.z(), 18);
}

/* Multiplication test "v1 * t" */
TEST(Vec3Utility, MultiplicationVec3AndScalar) {
    vec3 v1(1, 2, 3);
    double t = 2;

    vec3 v2 = v1 * t;

    EXPECT_EQ(v2.x(), 2);
    EXPECT_EQ(v2.y(), 4);
    EXPECT_EQ(v2.z(), 6);
}

/* Multiplication test "t * v1" */
TEST(Vec3Utility, MultiplicationScalarAndVec3) {
    vec3 v1(1, 2, 3);
    double t = 2;

    vec3 v2 = t * v1;

    EXPECT_EQ(v2.x(), 2);
    EXPECT_EQ(v2.y(), 4);
    EXPECT_EQ(v2.z(), 6);
}

/* Division test "v1 / t" */
TEST(Vec3Utility, Division) {
    vec3 v1(1, 2, 3);
    double t = 2;

    vec3 v2 = v1 / t;

    EXPECT_EQ(v2.x(), 0.5);
    EXPECT_EQ(v2.y(), 1);
    EXPECT_EQ(v2.z(), 1.5);
}

/* Dot product test "dot(v1, v2)" */
TEST(Vec3Utility, DotProduct) {
    vec3 v1(1, 2, 3);
    vec3 v2(4, 5, 6);

    double dot_result = dot(v1, v2);

    /* 1 * 4 + 2 * 5 + 3 * 6 = 32 */

    EXPECT_EQ(dot_result, 32);
}

/* Cross product test "cross(v1, v2)" */
TEST(Vec3Utility, CrossProduct) {
    vec3 v1(1, 2, 3);
    vec3 v2(4, 5, 6);

    vec3 v3 = cross(v1, v2);

    /* (2 * 6 - 3 * 5, 3 * 4 - 1 * 6, 1 * 5 - 2 * 4) = (-3, 6, -3) */

    EXPECT_EQ(v3.x(), -3);
    EXPECT_EQ(v3.y(), 6);
    EXPECT_EQ(v3.z(), -3);
}

/* Unit vector test "unit_vector(v1)" */
TEST(Vec3Utility, UnitVector) {
    vec3 v1(1, 2, 3);

    vec3 v2 = unit_vector(v1);

    EXPECT_EQ(v2.x(), 1 / sqrt(14));
    EXPECT_EQ(v2.y(), 2 / sqrt(14));
    EXPECT_EQ(v2.z(), 3 / sqrt(14));
}