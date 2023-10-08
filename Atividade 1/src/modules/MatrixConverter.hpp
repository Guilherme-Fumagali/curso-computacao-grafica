#include <Magick++.h>
#include <fstream>

using namespace Magick;
using namespace std;

class MatrixConverter {
    public:
        Image readFromFile(string filePath);
};