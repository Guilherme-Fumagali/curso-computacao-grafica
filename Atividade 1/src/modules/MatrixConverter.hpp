#include <Magick++.h>
#include <fstream>
#include <iostream>

using namespace Magick;
using namespace std;

class MatrixConverter {
    public:
        Image readFromFile(string filePath);
};