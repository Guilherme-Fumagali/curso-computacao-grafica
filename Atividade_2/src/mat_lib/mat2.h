#ifndef MAT2_H
#define MAT2_H

#include <cmath>
#include <iostream>

#include "../vec_lib/vec2.h"

using std::sqrt;

/**
 * @brief Class for 2x2 matrix and its operations.
 */
class mat2 {
public:
    /**
     * @brief The elements of the matrix.
     *
     * The elements are stored in a 2x2 array of {@see vec2} vectors.
     * Each vector represents a row of the matrix.
     */
    vec2 e[2];

    /**
     * @brief Default constructor.
     * @return mat2 with all elements set to 0.
     */
    mat2() : e{{0,0},{0,0}} {}

    /**
     * @brief Constructor with two vectors as arguments.
     * @param e0 The first {@see vec2} vector.
     * @param e1 The second {@see vec2} vector.
     * @return mat2 with the given vectors as elements.
     */
    mat2(vec2 e0, vec2 e1) : e{e0, e1} {}

    /**
     * @brief Returns the vector at the given index.
     * @param i The index of the vector to be returned.
     * @return vec2 at the given index.
     */
    vec2 operator[](int i) const { return e[i]; }
    vec2& operator[](int i) { return e[i]; }

    /**
     * @brief Adds the given matrix to this matrix.
     * @param m The matrix to be added.
     * @return mat2& with each element of m added to the corresponding element of this matrix.
     */
    mat2& operator+=(const mat2 &m) {
        e[0] += m.e[0];
        e[1] += m.e[1];
        return *this;
    }

    /**
     * @brief Subtracts the given matrix from this matrix.
     * @param m The matrix to be subtracted.
     * @return mat2& with each element of m subtracted from the corresponding element of this matrix.
     */
    mat2& operator-=(const mat2 &m) {
        e[0] -= m.e[0];
        e[1] -= m.e[1];
        return *this;
    }

    /**
     * @brief Multiplies this matrix by the given scalar.
     * @param t The scalar to multiply by.
     * @return mat2& with each element multiplied by t.
     */
    mat2& operator*=(double t) {
        e[0] *= t;
        e[1] *= t;
        return *this;
    }

    /**
     * @brief Divides this matrix by the given scalar.
     * @param t The scalar to divide by.
     * @return mat2& with each element divided by t.
     */
    mat2& operator/=(double t) {
        return *this *= 1/t;
    }

};

/**
 * @brief std::ostream operator overload for mat2.
 * @param out The output stream.
 * @param m The matrix to be printed.
 * @return std::ostream&
 */
inline std::ostream& operator<<(std::ostream &out, const mat2 &m) {
    return out << m.e[0] << '\n' << m.e[1];
}

/**
 * @brief Adds two matrices.
 * @param u The first matrix.
 * @param v The second matrix.
 * @return mat2 with each element of u added to the corresponding element of v.
 */
inline mat2 operator+(const mat2 &u, const mat2 &v) {
    return {u.e[0] + v.e[0],
            u.e[1] + v.e[1]};
}

/**
 * @brief Subtracts two matrices.
 * @param u The first matrix.
 * @param v The second matrix.
 * @return mat2 with each element of v subtracted from the corresponding element of u.
 */
inline mat2 operator-(const mat2 &u, const mat2 &v) {
    return {u.e[0] - v.e[0],
            u.e[1] - v.e[1]};
}

/**
 * @brief Multiplies a matrix by a scalar.
 * @param m The matrix.
 * @param t The scalar.
 * @return mat2 with each element multiplied by t.
 */
inline mat2 operator*(const mat2 &m, double t) {
    return {m.e[0] * t,
            m.e[1] * t};
}

/**
 * @brief Multiplies a scalar by a matrix.
 * @param t The scalar.
 * @param m The matrix.
 * @return mat2 with each element multiplied by t.
 */
inline mat2 operator*(double t, const mat2 &m) {
    return m * t;
}

/**
 * @brief Multiplies a matrix by a vector.
 * @param m The matrix.
 * @param v The vector.
 * @return vec2 with each element multiplied by the corresponding element in the matrix.
 */
inline vec2 operator*(const mat2 &m, const vec2 &v) {
    return {m.e[0].x() * v.x() + m.e[0].y() * v.y(),
            m.e[1].x() * v.x() + m.e[1].y() * v.y()};
}

/**
 * @brief Multiplies a vector by a matrix.
 * @param v The vector.
 * @param m The matrix.
 * @return vec2 with each element multiplied by the corresponding element in the matrix.
 */
inline vec2 operator*(const vec2 &v, const mat2 &m) {
    return m * v;
}

/**
 * @brief Divides a matrix by a scalar.
 * @param m The matrix.
 * @param t The scalar.
 * @return mat2 with each element divided by t.
 */
inline mat2 operator/(const mat2 &m, double t) {
    return m * (1/t);
}

#endif //MAT2_H
