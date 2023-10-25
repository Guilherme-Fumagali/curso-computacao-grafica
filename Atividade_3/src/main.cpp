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
    const char *file = argv[1];

    bool res = Loader::loadObj(file, &vertices);
    if (!res) {
        std::cerr << "Error: Could not load obj file " << argv[1] << std::endl;
        return 1;
    }

    std::cout << "Vertices:" << std::endl;
    for (const auto & vertice : vertices) {
        std::cout << vertice.x() << " " << vertice.y() << " " << vertice.z() << std::endl;
    }
}

