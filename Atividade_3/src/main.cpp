#include "Loader.h"
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input file>" << std::endl;
        return 1;
    }

    vector<vec3> vertices;
    vector<Triangle> triangles;

    const char *file = argv[1];

    bool res = Loader::loadObj(file, &vertices, &triangles);
    if (!res) {
        std::cerr << "Error: Could not load obj file " << argv[1] << std::endl;
        return 1;
    }

    std::cout << "Vertices:" << std::endl;
    for (int i = 0; i < vertices.size(); i++) {
        vec3 vertice = vertices[i];
        std::cout << i << "\t" << vertice.x() << " " << vertice.y() << " " << vertice.z() << std::endl;
    }

    std::cout << "Triangles:" << std::endl;
    for (int i = 0; i < triangles.size(); i++) {
        Triangle triangle = triangles[i];
        std::cout << i << "\t" << triangle << std::endl;
    }
}

