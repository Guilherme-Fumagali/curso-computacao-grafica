#ifndef MAT3_H
#define MAT3_H

#include <cmath>
#include <iostream>

#include "../vec_lib/vec3.h"

using std::sqrt;

/**
 * @brief Class for 3x3 matrix and its operations.
 */
class mat3 {
public:
    /**
     * @brief The elements of the matrix.
     *
     * The elements are stored in a 3x3 array of {@see vec3} vectors.
     * Each vector represents a row of the matrix.
     */
    vec3 e[3];

    /**
     * @brief Default constructor.
     * @return mat3 with all elements set to 0.
     */
    mat3() : e{{0,0,0},{0,0,0},{0,0,0}} {}

    /**
     * @brief Constructor with three vectors as arguments.
     * @param e0 The first {@see vec3} vector.
     * @param e1 The second {@see vec3} vector.
     * @param e2 The third {@see vec3} vector.
     * @return mat3 with the given vectors as elements.
     */
    mat3(vec3 e0, vec3 e1, vec3 e2) : e{e0, e1, e2} {}

    /**
     * @brief Returns the vector at the given index.
     * @param i The index of the vector to be returned.
     * @return vec3 at the given index.
     */
    vec3 operator[](int i) const { return e[i]; }
    vec3& operator[](int i) { return e[i]; }

    /**
     * @brief Adds the given matrix to this matrix.
     * @param m The matrix to be added.
     * @return mat3& with each element of m added to the corresponding element of this matrix.
     */
    mat3& operator+=(const mat3 &m) {
        e[0] += m.e[0];
        e[1] += m.e[1];
        e[2] += m.e[2];
        return *this;
    }

    /**
     * @brief Subtracts the given matrix from this matrix.
     * @param m The matrix to be subtracted.
     * @return mat3& with each element of m subtracted from the corresponding element of this matrix.
     */
    mat3& operator-=(const mat3 &m) {
        e[0] -= m.e[0];
        e[1] -= m.e[1];
        e[2] -= m.e[2];
        return *this;
    }

    /**
     * @brief Multiplies this matrix by the given scalar.
     * @param t The scalar to multiply by.
     * @return mat3& with each element multiplied by t.
     */
    mat3& operator*=(double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    /**
     * @brief Divides this matrix by the given scalar.
     * @param t The scalar to divide by.
     * @return mat3& with each element divided by t.
     */
    mat3& operator/=(double t) {
        return *this *= 1/t;
    }

};

/**
 * @brief std::ostream operator overload for mat3.
 * @param out The output stream.
 * @param m The matrix to be printed.
 * @return std::ostream&
 */
inline std::ostream& operator<<(std::ostream &out, const mat3 &m) {
    return out << m.e[0] << '\n' << m.e[1] << '\n' << m.e[2];
}

/**
 * @brief Adds the given matrices.
 * @param u The first matrix.
 * @param v The second matrix.
 * @return mat3 with each element of u added to the corresponding element of v.
 */
inline mat3 operator+(const mat3 &u, const mat3 &v) {
    return {u.e[0] + v.e[0],
            u.e[1] + v.e[1],
            u.e[2] + v.e[2]};
}

/**
 * @brief Subtracts the given matrices.
 * @param u The first matrix.
 * @param v The second matrix.
 * @return mat3 with each element of v subtracted from the corresponding element of u.
 */
inline mat3 operator-(const mat3 &u, const mat3 &v) {
    return {u.e[0] - v.e[0],
            u.e[1] - v.e[1],
            u.e[2] - v.e[2]};
}

/**
 * @brief Multiplies the given matrix by the given scalar.
 * @param m The matrix.
 * @param t The scalar.
 * @return mat3 with each element of m multiplied by t.
 */
inline mat3 operator*(const mat3 &m, double t) {
    return {m.e[0] * t,
            m.e[1] * t,
            m.e[2] * t};
}

/**
 * @brief Multiplies the given scalar by the given matrix.
 * @param t The scalar.
 * @param m The matrix.
 * @return mat3 with each element of m multiplied by t.
 */
inline mat3 operator*(double t, const mat3 &m) {
    return m * t;
}

/**
 * @brief Multiplies the given matrix by the given vector.
 * @param m The matrix.
 * @param v The vector.
 * @return vec3 with each element of v multiplied by the corresponding row of m.
 */
inline vec3 operator*(const mat3 &m, const vec3 &v) {
    return {m.e[0].x() * v.x() + m.e[0].y() * v.y() + m.e[0].z() * v.z(),
            m.e[1].x() * v.x() + m.e[1].y() * v.y() + m.e[1].z() * v.z(),
            m.e[2].x() * v.x() + m.e[2].y() * v.y() + m.e[2].z() * v.z()};
}

/**
 * @brief Multiplies the given vector by the given matrix.
 * @param v The vector.
 * @param m The matrix.
 * @return vec3 with each element of v multiplied by the corresponding column of m.
 */
inline vec3 operator*(const vec3 &v, const mat3 &m) {
    return m * v;
}

/**
 * @brief Divides the given matrix by the given scalar.
 * @param m The matrix.
 * @param t The scalar.
 * @return mat3 with each element of m divided by t.
 */
inline mat3 operator/(const mat3 &m, double t) {
    return m * (1/t);
}

#endif //MAT3_H
