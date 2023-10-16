#ifndef MAT4_H
#define MAT4_H

#include <cmath>
#include <iostream>

#include "../Vec_lib/vec4.h"

using std::sqrt;

class mat4 {
public:
    vec4 e[4];

    mat4() : e{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}} {}
    mat4(vec4 e0, vec4 e1, vec4 e2, vec4 e3) : e{e0, e1, e2, e3} {}

    vec4 operator[](int i) const { return e[i]; }
    vec4& operator[](int i) { return e[i]; }

    mat4& operator+=(const mat4 &m) {
        e[0] += m.e[0];
        e[1] += m.e[1];
        e[2] += m.e[2];
        e[3] += m.e[3];
        return *this;
    }

    mat4& operator-=(const mat4 &m) {
        e[0] -= m.e[0];
        e[1] -= m.e[1];
        e[2] -= m.e[2];
        e[3] -= m.e[3];
        return *this;
    }

    mat4& operator*=(double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        e[3] *= t;
        return *this;
    }

    mat4& operator/=(double t) {
        return *this *= 1/t;
    }

};

// Matrix Utility Functions

inline std::ostream& operator<<(std::ostream &out, const mat4 &m) {
    return out << m.e[0] << '\n' << m.e[1] << '\n' << m.e[2] << '\n' << m.e[3];
}

inline mat4 operator+(const mat4 &u, const mat4 &v) {
    return {u.e[0] + v.e[0],
            u.e[1] + v.e[1],
            u.e[2] + v.e[2],
            u.e[3] + v.e[3]};
}

inline mat4 operator-(const mat4 &u, const mat4 &v) {
    return {u.e[0] - v.e[0],
            u.e[1] - v.e[1],
            u.e[2] - v.e[2],
            u.e[3] - v.e[3]};
}

inline mat4 operator*(const mat4 &m, double t) {
    return {m.e[0] * t,
            m.e[1] * t,
            m.e[2] * t,
            m.e[3] * t};
}

inline mat4 operator*(double t, const mat4 &m) {
    return m * t;
}

inline vec4 operator*(const mat4 &m, const vec4 &v) {
    return {m.e[0].x() * v.x() + m.e[0].y() * v.y() + m.e[0].z() * v.z() + m.e[0].w() * v.w(),
            m.e[1].x() * v.x() + m.e[1].y() * v.y() + m.e[1].z() * v.z() + m.e[1].w() * v.w(),
            m.e[2].x() * v.x() + m.e[2].y() * v.y() + m.e[2].z() * v.z() + m.e[2].w() * v.w(),
            m.e[3].x() * v.x() + m.e[3].y() * v.y() + m.e[3].z() * v.z() + m.e[3].w() * v.w()};
}

inline vec4 operator*(const vec4 &v, const mat4 &m) {
    return m * v;
}

inline mat4 operator/(const mat4 &m, double t) {
    return m * (1/t);
}

#endif //MAT4_H
