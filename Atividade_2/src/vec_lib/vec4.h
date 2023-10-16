//
// Created by gfumagali on 15/10/23.
//

#ifndef VEC4_H
#define VEC4_H

#include <cmath>
#include <iostream>

using std::sqrt;

/**
 * @brief Class for 4D vector and its operations.
 */
class vec4 {
public:
    /**
     * @brief The elements of the vector.
     *
     * The elements are stored in a 4x1 array of doubles.
     */
    double e[4];

    /**
     * @brief Default constructor.
     * @return vec4 with all elements set to 0.
     */
    vec4() : e{0,0,0,0} {}

    /**
     * @brief Constructor with four doubles as arguments.
     * @param e0 The first double.
     * @param e1 The second double.
     * @param e2 The third double.
     * @param e3 The fourth double.
     * @return vec4 with the given doubles as elements.
     */
    vec4(double e0, double e1, double e2, double e3) : e{e0, e1, e2, e3} {}

    /**
     * @brief Returns the x-coordinate of the vector.
     * @return The x-coordinate of the vector.
     */
    double x() const { return e[0]; }

    /**
     * @brief Returns the y-coordinate of the vector.
     * @return The y-coordinate of the vector.
     */
    double y() const { return e[1]; }

    /**
     * @brief Returns the z-coordinate of the vector.
     * @return The z-coordinate of the vector.
     */
    double z() const { return e[2]; }

    /**
     * @brief Returns the w-coordinate of the vector.
     * @return The w-coordinate of the vector.
     */
    double w() const { return e[3]; }

    /**
     * @brief Inverts the signs of the elements of the vector.
     * @return vec4 with the values with inverted signs.
     */
    vec4 operator-() const { return {-e[0], -e[1], -e[2], -e[3]}; }

    /**
     * @brief Returns the element at the given index.
     * @param i The index of the element to be returned.
     * @return The element at the given index.
     */
    double operator[](int i) const { return e[i]; }
    double& operator[](int i) { return e[i]; }

    /**
     * @brief Adds the given vector to this vector.
     * @param v The vector to be added.
     * @return vec4& with each element of v added to the corresponding element of this vector.
     */
    vec4& operator+=(const vec4 &v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        e[3] += v.e[3];
        return *this;
    }

    /**
     * @brief Subtracts the given vector from this vector.
     * @param v The vector to be subtracted.
     * @return vec4& with each element of v subtracted from the corresponding element of this vector.
     */
    vec4& operator-=(const vec4 &v) {
        e[0] -= v.e[0];
        e[1] -= v.e[1];
        e[2] -= v.e[2];
        e[3] -= v.e[3];
        return *this;
    }

    /**
     * @brief Multiplies this vector by the given scalar.
     * @param t The scalar to multiply by.
     * @return vec4& with each element of this vector multiplied by t.
     */
    vec4& operator*=(double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        e[3] *= t;
        return *this;
    }

    /**
     * @brief Divides this vector by the given scalar.
     * @param t The scalar to divide by.
     * @return vec4& with each element of this vector divided by t.
     */
    vec4& operator/=(double t) {
        return *this *= 1/t;
    }

    /**
     * @brief Returns the length of the vector.
     * @return The length of the vector.
     */
    double length() const {
        return sqrt(length_squared());
    }

    /**
     * @brief Returns the squared length of the vector.
     * @return The squared length of the vector.
     */
    double length_squared() const {
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2] + e[3]*e[3];
    }
};

/**
 * @brief Alias for vec4.
 */
using point4 = vec4;

/**
 * @brief std::ostream operator overload for vec4.
 * @param out The output stream.
 * @param v The vector to be printed.
 * @return The output stream.
 */
inline std::ostream& operator<<(std::ostream &out, const vec4 &v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2] << ' ' << v.e[3];
}

/**
 * @brief Adds the given vectors.
 * @param u The first vector.
 * @param v The second vector.
 * @return vec4 with each element of u added to the corresponding element of v.
 */
inline vec4 operator+(const vec4 &u, const vec4 &v) {
    return {u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2], u.e[3] + v.e[3]};
}

/**
 * @brief Subtracts the given vectors.
 * @param u The first vector.
 * @param v The second vector.
 * @return vec4 with each element of v subtracted from the corresponding element of u.
 */
inline vec4 operator-(const vec4 &u, const vec4 &v) {
    return {u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2], u.e[3] - v.e[3]};
}

/**
 * @brief Multiplies the given vectors.
 * @param u The first vector.
 * @param v The second vector.
 * @return vec4 with each element of u multiplied by the corresponding element of v.
 */
inline vec4 operator*(const vec4 &u, const vec4 &v) {
    return {u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2], u.e[3] * v.e[3]};
}

/**
 * @brief Multiplies the given vector by the given scalar.
 * @param t The scalar to multiply by.
 * @param v The vector to be multiplied.
 * @return vec4 with each element of v multiplied by t.
 */
inline vec4 operator*(double t, const vec4 &v) {
    return {t*v.e[0], t*v.e[1], t*v.e[2], t*v.e[3]};
}

/**
 * @brief Multiplies the given scalar by the given vector.
 * @param v The vector to be multiplied.
 * @param t The scalar to multiply by.
 * @return vec4 with each element of v multiplied by t.
 */
inline vec4 operator*(const vec4 &v, double t) {
    return t * v;
}

/**
 * @brief Divides the given vector by the given scalar.
 * @param v The vector to be divided.
 * @param t The scalar to divide by.
 * @return vec4 with each element of v divided by t.
 */
inline vec4 operator/(vec4 v, double t) {
    return (1/t) * v;
}

/**
 * @brief Returns the dot product of the given vectors.
 * @param u The first vector.
 * @param v The second vector.
 * @return The dot product of the given vectors.
 */
inline double dot(const vec4 &u, const vec4 &v) {
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1]
         + u.e[2] * v.e[2]
         + u.e[3] * v.e[3];
}

/**
 * @brief Returns the cross product of the given vectors.
 * @param u The first vector.
 * @param v The second vector.
 * @return The cross product of the given vectors.
 */
inline vec4 cross(const vec4 &u, const vec4 &v) {
    return {u.e[1] * v.e[2] - u.e[2] * v.e[1],
            u.e[2] * v.e[0] - u.e[0] * v.e[2],
            u.e[0] * v.e[1] - u.e[1] * v.e[0],
            0};
}

/**
 * @brief Returns the unit vector of the given vector.
 * @param v The vector.
 * @return The unit vector of the given vector.
 */
inline vec4 unit_vector(vec4 v) {
    return v / v.length();
}

#endif //VEC4_H
