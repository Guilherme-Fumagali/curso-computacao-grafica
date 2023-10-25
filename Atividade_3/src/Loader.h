#ifndef OBJREADER_H
#define OBJREADER_H

#include "vec2.h"
#include "vec3.h"
#include "Triangle.h"
#include <vector>
#include <iostream>
#include <fstream>


using namespace std;

/**
 * @brief Class for loading .obj files.
 * @details The class contains a static method for loading .obj files.
 * The method takes a file path as argument and returns a vector of vertices and a vector of triangles.
 * The vertices are stored as {@see vec3} vectors and the triangles are stored as {@see Triangle} objects.
 */
class Loader {

public:

    /**
     * @brief Loads a .obj file.
     * @param source The path to the .obj file.
     * @param out_vertices A pointer to a vector of vertices.
     * @param out_uvs A pointer to a vector of texture coordinates.
     * @param out_normals A pointer to a vector of normals.
     * @param out_triangles A pointer to a vector of triangles.
     * @return True if the file was loaded successfully, false otherwise.
     */
    static bool loadObj(const char *source, vector<vec3>* out_vertices, vector<vec2>* out_uvs, vector<vec3>* out_normals, vector<Triangle>* out_triangles) {

        // Try to open the file
        ifstream file(source);
        if(!file.is_open()){
            std::cerr << "Error: Could not open file " << source << std::endl;
            return false;
        }

        // Read the file line by line
        string line;
        while(true) {
            if (file.eof()) break; // end of file
            getline(file, line);

            // vertex data
            if (line.substr(0, 2) == "v ") {
                vec3 vertex;
                // read the three doubles from the line and store them in the vec3
                sscanf(line.c_str(), "v %lf %lf %lf\n", &vertex[0], &vertex[1], &vertex[2]);
                out_vertices->push_back(vertex); // add the vertex to the vector
            }

            // texture data
            if (line.substr(0, 2) == "vt") {
                vec2 uv;
                // read the two doubles from the line and store them in the vec2
                sscanf(line.c_str(), "vt %lf %lf\n", &uv[0], &uv[1]);
                out_uvs->push_back(uv); // add the uv to the vector
            }

            // normal data
            if (line.substr(0, 2) == "vn") {
                vec3 normal;
                // read the three doubles from the line and store them in the vec3
                sscanf(line.c_str(), "vn %lf %lf %lf\n", &normal[0], &normal[1], &normal[2]);
                out_normals->push_back(normal); // add the normal to the vector
            }

            // face data
            if (line.substr(0, 2) == "f ") {
                unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
                int matches = sscanf(line.c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d",
                                     &vertexIndex[0], &uvIndex[0], &normalIndex[0],
                                     &vertexIndex[1], &uvIndex[1], &normalIndex[1],
                                     &vertexIndex[2], &uvIndex[2], &normalIndex[2]);

                // check if the line was read correctly
                if (matches != 9) {
                    std::cerr << "Error: Could not read face data from line " << line << std::endl;
                    return false;
                }

                vector<vec3> faces; // vector for storing the faces
                for (int i = 0; i < 3; i++)
                    faces.emplace_back(vertexIndex[i] - 1, uvIndex[i] - 1, normalIndex[i] - 1);

                // add the triangle to the vector
                out_triangles->emplace_back(faces[0], faces[1], faces[2]);
            }
        }

        file.close();
        return true;
    }
};


#endif //OBJREADER_H
