#ifndef MAT2_H
#define MAT2_H

#include <cmath>
#include <iostream>

#include "vec2.h"

using std::sqrt;

class mat2 {
public:
    vec2 e[2];

    mat2() : e{{0,0},{0,0}} {}
    mat2(vec2 e0, vec2 e1) : e{e0, e1} {}

    vec2 operator[](int i) const { return e[i]; }
    vec2& operator[](int i) { return e[i]; }

    mat2& operator+=(const mat2 &m) {
        e[0] += m.e[0];
        e[1] += m.e[1];
        return *this;
    }

    mat2& operator*=(double t) {
        e[0] *= t;
        e[1] *= t;
        return *this;
    }

    mat2& operator/=(double t) {
        return *this *= 1/t;
    }

};

// Matrix Utility Functions

inline std::ostream& operator<<(std::ostream &out, const mat2 &m) {
    return out << m.e[0] << '\n' << m.e[1];
}

inline mat2 operator+(const mat2 &u, const mat2 &v) {
    return {u.e[0] + v.e[0],
            u.e[1] + v.e[1]};
}

inline mat2 operator-(const mat2 &u, const mat2 &v) {
    return {u.e[0] - v.e[0],
            u.e[1] - v.e[1]};
}

inline mat2 operator*(const mat2 &m, double t) {
    return {m.e[0] * t,
            m.e[1] * t};
}

inline mat2 operator*(double t, const mat2 &m) {
    return m * t;
}

inline mat2 operator/(const mat2 &m, double t) {
    return m * (1/t);
}

inline vec2 operator*(const mat2 &m, const vec2 &v) {
    return {m.e[0].x() * v.x() + m.e[0].y() * v.y(),
            m.e[1].x() * v.x() + m.e[1].y() * v.y()};
}

inline vec2 operator*(const vec2 &v, const mat2 &m) {
    return m * v;
}

#endif //MAT2_H
