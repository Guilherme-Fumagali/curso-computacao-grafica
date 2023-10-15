#ifndef MAT3_H
#define MAT3_H

#include <cmath>
#include <iostream>

#include "vec3.h"

using std::sqrt;

class mat3 {
public:
    vec3 e[3];

    mat3() : e{{0,0,0},{0,0,0},{0,0,0}} {}
    mat3(vec3 e0, vec3 e1, vec3 e2) : e{e0, e1, e2} {}

    vec3 operator[](int i) const { return e[i]; }
    vec3& operator[](int i) { return e[i]; }

    mat3& operator+=(const mat3 &m) {
        e[0] += m.e[0];
        e[1] += m.e[1];
        e[2] += m.e[2];
        return *this;
    }

    mat3& operator*=(double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    mat3& operator/=(double t) {
        return *this *= 1/t;
    }

};

// Matrix Utility Functions

inline std::ostream& operator<<(std::ostream &out, const mat3 &m) {
    return out << m.e[0] << '\n' << m.e[1] << '\n' << m.e[2];
}

inline mat3 operator+(const mat3 &u, const mat3 &v) {
    return {u.e[0] + v.e[0],
            u.e[1] + v.e[1],
            u.e[2] + v.e[2]};
}

inline mat3 operator-(const mat3 &u, const mat3 &v) {
    return {u.e[0] - v.e[0],
            u.e[1] - v.e[1],
            u.e[2] - v.e[2]};
}

inline mat3 operator*(const mat3 &m, double t) {
    return {m.e[0] * t,
            m.e[1] * t,
            m.e[2] * t};
}

inline mat3 operator*(double t, const mat3 &m) {
    return m * t;
}

inline mat3 operator/(const mat3 &m, double t) {
    return m * (1/t);
}

inline vec3 operator*(const mat3 &m, const vec3 &v) {
    return {m.e[0].x() * v.x() + m.e[0].y() * v.y() + m.e[0].z() * v.z(),
            m.e[1].x() * v.x() + m.e[1].y() * v.y() + m.e[1].z() * v.z(),
            m.e[2].x() * v.x() + m.e[2].y() * v.y() + m.e[2].z() * v.z()};
}

inline vec3 operator*(const vec3 &v, const mat3 &m) {
    return m * v;
}

#endif //MAT3_H
