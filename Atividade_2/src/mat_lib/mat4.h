#ifndef MAT4_H
#define MAT4_H

#include <cmath>
#include <iostream>

#include "../vec_lib/vec4.h"

using std::sqrt;

/**
 * @brief Class for 4x4 matrix and its operations.
 */
class mat4 {
public:
    /**
     * @brief The elements of the matrix.
     *
     * The elements are stored in a 4x4 array of {@see vec4} vectors.
     * Each vector represents a row of the matrix.
     */
    vec4 e[4];

    /**
     * @brief Default constructor.
     * @return mat4 with all elements set to 0.
     */
    mat4() : e{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}} {}

    /**
     * @brief Constructor with four vectors as arguments.
     * @param e0 The first {@see vec4} vector.
     * @param e1 The second {@see vec4} vector.
     * @param e2 The third {@see vec4} vector.
     * @param e3 The fourth {@see vec4} vector.
     * @return mat4 with the given vectors as elements.
     */
    mat4(vec4 e0, vec4 e1, vec4 e2, vec4 e3) : e{e0, e1, e2, e3} {}

    /**
     * @brief Returns the vector at the given index.
     * @param i The index of the vector to be returned.
     * @return vec4 at the given index.
     */
    vec4 operator[](int i) const { return e[i]; }
    vec4& operator[](int i) { return e[i]; }

    /**
     * @brief Adds the given matrix to this matrix.
     * @param m The matrix to be added.
     * @return mat4& with each element of m added to the corresponding element of this matrix.
     */
    mat4& operator+=(const mat4 &m) {
        e[0] += m.e[0];
        e[1] += m.e[1];
        e[2] += m.e[2];
        e[3] += m.e[3];
        return *this;
    }

    /**
     * @brief Subtracts the given matrix from this matrix.
     * @param m The matrix to be subtracted.
     * @return mat4& with each element of m subtracted from the corresponding element of this matrix.
     */
    mat4& operator-=(const mat4 &m) {
        e[0] -= m.e[0];
        e[1] -= m.e[1];
        e[2] -= m.e[2];
        e[3] -= m.e[3];
        return *this;
    }

    /**
     * @brief Multiplies this matrix by the given scalar.
     * @param t The scalar to be multiplied by.
     * @return mat4& with each element of this matrix multiplied by t.
     */
    mat4& operator*=(double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        e[3] *= t;
        return *this;
    }

    /**
     * @brief Divides this matrix by the given scalar.
     * @param t The scalar to be divided by.
     * @return mat4& with each element of this matrix divided by t.
     */
    mat4& operator/=(double t) {
        return *this *= 1/t;
    }

};

/**
 * @brief std::ostream operator overload for mat4.
 * @param out The output stream.
 * @param m The matrix to be printed.
 * @return std::ostream&
 */
inline std::ostream& operator<<(std::ostream &out, const mat4 &m) {
    return out << m.e[0] << '\n' << m.e[1] << '\n' << m.e[2] << '\n' << m.e[3];
}

/**
 * @brief Adds the given matrices.
 * @param u The first matrix.
 * @param v The second matrix.
 * @return mat4 with each element of u added to the corresponding element of v.
 */
inline mat4 operator+(const mat4 &u, const mat4 &v) {
    return {u.e[0] + v.e[0],
            u.e[1] + v.e[1],
            u.e[2] + v.e[2],
            u.e[3] + v.e[3]};
}

/**
 * @brief Subtracts the given matrices.
 * @param u The first matrix.
 * @param v The second matrix.
 * @return mat4 with each element of v subtracted from the corresponding element of u.
 */
inline mat4 operator-(const mat4 &u, const mat4 &v) {
    return {u.e[0] - v.e[0],
            u.e[1] - v.e[1],
            u.e[2] - v.e[2],
            u.e[3] - v.e[3]};
}

/**
 * @brief Multiplies the given matrix by the given scalar.
 * @param m The matrix.
 * @param t The scalar.
 * @return mat4 with each element of m multiplied by t.
 */
inline mat4 operator*(const mat4 &m, double t) {
    return {m.e[0] * t,
            m.e[1] * t,
            m.e[2] * t,
            m.e[3] * t};
}

/**
 * @brief Multiplies the given scalar by the given matrix.
 * @param t The scalar.
 * @param m The matrix.
 * @return mat4 with each element of m multiplied by t.
 */
inline mat4 operator*(double t, const mat4 &m) {
    return m * t;
}

/**
 * @brief Multiplies the given matrix by the given matrix.
 * @param u The first matrix.
 * @param v The second matrix.
 * @return mat4 with each element of u multiplied by the corresponding element of v.
 */
inline vec4 operator*(const mat4 &m, const vec4 &v) {
    return {m.e[0].x() * v.x() + m.e[0].y() * v.y() + m.e[0].z() * v.z() + m.e[0].w() * v.w(),
            m.e[1].x() * v.x() + m.e[1].y() * v.y() + m.e[1].z() * v.z() + m.e[1].w() * v.w(),
            m.e[2].x() * v.x() + m.e[2].y() * v.y() + m.e[2].z() * v.z() + m.e[2].w() * v.w(),
            m.e[3].x() * v.x() + m.e[3].y() * v.y() + m.e[3].z() * v.z() + m.e[3].w() * v.w()};
}

/**
 * @brief Multiplies the given vector by the given matrix.
 * @param v The vector.
 * @param m The matrix.
 * @return vec4 with each element of v multiplied by the corresponding row of m.
 */
inline vec4 operator*(const vec4 &v, const mat4 &m) {
    return m * v;
}

/**
 * @brief Divides the given matrix by the given scalar.
 * @param m The matrix.
 * @param t The scalar.
 * @return mat4 with each element of m divided by t.
 */
inline mat4 operator/(const mat4 &m, double t) {
    return m * (1/t);
}

#endif //MAT4_H
