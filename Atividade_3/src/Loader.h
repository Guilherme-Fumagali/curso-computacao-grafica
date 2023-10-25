#ifndef OBJREADER_H
#define OBJREADER_H

#include "vec3.h"
#include "Triangle.h"
#include <vector>
#include <iostream>
#include <fstream>


using namespace std;

class Loader {

public:
    static bool loadObj(const char *source, vector<vec3>* out_vertices, vector<Triangle>* out_triangles) {
        ifstream file(source);
        if(!file.is_open()){
            std::cerr << "Error: Could not open file " << source << std::endl;
            return false;
        }

        string line;
        while(true) {
            if (file.eof()) break;
            getline(file, line);

            // vertex data
            if (line.substr(0, 2) == "v ") {
                vec3 vertex;
                sscanf(line.c_str(), "v %lf %lf %lf\n", &vertex[0], &vertex[1], &vertex[2]);
                out_vertices->push_back(vertex);
            }

            // face data
            if (line.substr(0, 2) == "f ") {
                unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
                int matches = sscanf(line.c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d",
                                     &vertexIndex[0], &uvIndex[0], &normalIndex[0],
                                     &vertexIndex[1], &uvIndex[1], &normalIndex[1],
                                     &vertexIndex[2], &uvIndex[2], &normalIndex[2]);

                if (matches != 9) {
                    std::cerr << "Error: Could not read face data from line " << line << std::endl;
                    return false;
                }

                vector<vec3> faces;
                for (int i = 0; i < 3; i++)
                    faces.emplace_back(vertexIndex[i] - 1, uvIndex[i] - 1, normalIndex[i] - 1);

                out_triangles->emplace_back(faces[0], faces[1], faces[2]);
            }

        }

        file.close();
        return true;
    }
};


#endif //OBJREADER_H
