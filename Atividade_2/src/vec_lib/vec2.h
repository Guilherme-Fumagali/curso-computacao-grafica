#ifndef VEC2_H
#define VEC2_H

#include <cmath>
#include <iostream>

using std::sqrt;

/**
 * @brief Class for 2D vector and its operations.
 */
class vec2 {
public:
    /**
     * @brief The elements of the vector.
     *
     * The elements are stored in a 2x1 array of doubles.
     */
    double e[2];

    /**
     * @brief Default constructor.
     * @return vec2 with all elements set to 0.
     */
    vec2() : e{0,0} {}

    /**
     * @brief Constructor with two doubles as arguments.
     * @param e0 The first double.
     * @param e1 The second double.
     * @return vec2 with the given doubles as elements.
     */
    vec2(double e0, double e1) : e{e0, e1} {}

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
     * @brief Inverts the signs of the elements of the vector.
     * @return vec2 with the values with inverted signs.
     */
    vec2 operator-() const { return {-e[0], -e[1]}; }

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
     * @return vec2& with each element of v added to the corresponding element of this vector.
     */
    vec2& operator+=(const vec2 &v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        return *this;
    }

    /**
     * @brief Subtracts the given vector from this vector.
     * @param v The vector to be subtracted.
     * @return vec2& with each element of v subtracted from the corresponding element of this vector.
     */
    vec2& operator-=(const vec2 &v) {
        e[0] -= v.e[0];
        e[1] -= v.e[1];
        return *this;
    }

    /**
     * @brief Multiplies this vector by the given scalar.
     * @param t The scalar to multiply by.
     * @return vec2& with each element of this vector multiplied by t.
     */
    vec2& operator*=(double t) {
        e[0] *= t;
        e[1] *= t;
        return *this;
    }

    /**
     * @brief Divides this vector by the given scalar.
     * @param t The scalar to divide by.
     * @return vec2& with each element of this vector divided by t.
     */
    vec2& operator/=(double t) {
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
        return e[0]*e[0] + e[1]*e[1];
    }
};

/**
 * @brief Alias for vec2.
 */
using point2 = vec2;

/**
 * @brief std::ostream operator overload for vec2.
 * @param out The output stream.
 * @param v The vector to be printed.
 * @return std::ostream&
 */
inline std::ostream& operator<<(std::ostream &out, const vec2 &v) {
    return out << v.e[0] << ' ' << v.e[1];
}

/**
 * @brief Adds the given vectors.
 * @param u The first vector.
 * @param v The second vector.
 * @return vec2 with each element of u added to the corresponding element of v.
 */
inline vec2 operator+(const vec2 &u, const vec2 &v) {
    return {u.e[0] + v.e[0],
            u.e[1] + v.e[1]};
}

/**
 * @brief Subtracts the given vectors.
 * @param u The first vector.
 * @param v The second vector.
 * @return vec2 with each element of v subtracted from the corresponding element of u.
 */
inline vec2 operator-(const vec2 &u, const vec2 &v) {
    return {u.e[0] - v.e[0],
            u.e[1] - v.e[1]};
}

/**
 * @brief Multiplies the given vectors.
 * @param u The first vector.
 * @param v The second vector.
 * @return vec2 with each element of u multiplied by the corresponding element of v.
 */
inline vec2 operator*(const vec2 &u, const vec2 &v) {
    return {u.e[0] * v.e[0],
            u.e[1] * v.e[1]};
}

/**
 * @brief Multiplies the given vector by the given scalar.
 * @param t The scalar.
 * @param v The vector.
 * @return vec2 with each element of v multiplied by t.
 */
inline vec2 operator*(double t, const vec2 &v) {
    return {t*v.e[0],
            t*v.e[1]};
}

/**
 * @brief Multiplies the given scalar by the given vector.
 * @param v The vector.
 * @param t The scalar.
 * @return vec2 with each element of v multiplied by t.
 */
inline vec2 operator*(const vec2 &v, double t) {
    return t * v;
}

/**
 * @brief Divides the given vector by the given scalar.
 * @param v The vector.
 * @param t The scalar.
 * @return vec2 with each element of v divided by t.
 */
inline vec2 operator/(vec2 v, double t) {
    return (1/t) * v;
}

/**
 * @brief Returns the dot product of the given vectors.
 * @param u The first vector.
 * @param v The second vector.
 * @return The dot product of the given vectors.
 */
inline double dot(const vec2 &u, const vec2 &v) {
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1];
}

/**
 * @brief Returns the cross product of the given vectors.
 * @param u The first vector.
 * @param v The second vector.
 * @return The cross product of the given vectors.
 */
inline double cross(const vec2 &u, const vec2 &v) {
    return u.e[0] * v.e[1]
         - u.e[1] * v.e[0];

/**
 * @brief Returns the unit vector of the given vector.
 * @param v The vector.
 * @return The unit vector of the given vector.
 */
inline vec2 unit_vector(vec2 v) {
    return v / v.length();
}

#endif //VEC2_H
