#ifndef OBJREADER_H
#define OBJREADER_H

#include "vec3.h"
#include <vector>
#include <iostream>
#include <fstream>


using namespace std;

class Loader {

public:
    static bool loadObj(const char *source, vector<vec3>* out_vertices){
        ifstream file(source);
        if(!file.is_open()){
            std::cerr << "Error: Could not open file " << source << std::endl;
            return false;
        }

        string line;
        while(true) {
            getline(file, line);
            if (file.eof()) break;

            // vertex data
            if (line.substr(0, 2) == "v ") {
                vec3 vertex;
                sscanf(line.c_str(), "v %lf %lf %lf\n", &vertex[0], &vertex[1], &vertex[2]);
                out_vertices->push_back(vertex);
            }
        }

        file.close();
        return true;
    }
};


#endif //OBJREADER_H
