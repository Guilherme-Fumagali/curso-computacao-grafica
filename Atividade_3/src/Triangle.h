#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "vec3.h"

/**
 * @brief This class represents a triangle.
 * Each triangle is defined by three vertices, that are stored in a 3x1 array of vec3.
 * The first data of vec3 is the index of the vertex in the vertices array, the second is the index of the texture and the third is the index of the normal.
 */
class Triangle {
public:
    /**
     * @brief The vertices of the triangle.
     * */
    vec3 vertices[3];

    /**
     * @brief Default constructor.
     * @return Triangle with all vertices set to (0,0,0).
     */
    Triangle() : vertices{vec3(0,0,0), vec3(0,0,0), vec3(0,0,0)} {}

    /**
     * @brief Constructor with three vec3 as arguments.
     * @param v0 The first vec3.
     * @param v1 The second vec3.
     * @param v2 The third vec3.
     * @return Triangle with the given vec3 as vertices.
     */
    Triangle(vec3 v0, vec3 v1, vec3 v2) : vertices{v0, v1, v2} {}

    /**
     * @brief Returns the vertex at the given index.
     * @param i The index of the vertex to be returned.
     * @return The vertex at the given index.
     */
    vec3 operator[](int i) const { return vertices[i]; }
    vec3& operator[](int i) { return vertices[i]; }

    /**
     * @brief Compare two triangles.
     * @param t Triangle to be compared.
     *
     * @return True if the triangles are equal, false otherwise.
     */
    bool operator==(const Triangle &t) const {
        return vertices[0] == t.vertices[0] && vertices[1] == t.vertices[1] && vertices[2] == t.vertices[2];
    }
};

/**
 * @brief std::ostream operator overload.
 * @param out The output stream.
 * @param t The triangle to be printed.
 * @return The output stream.
 */
inline std::ostream &operator<<(std::ostream &out, const Triangle &t) {
    out << "Triangle: " << t.vertices[0] << ", " << t.vertices[1] << ", " << t.vertices[2];
    return out;
}

#endif //TRIANGLE_H
