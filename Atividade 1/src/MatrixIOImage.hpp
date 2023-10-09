#include "modules/MatrixReader.hpp"
#include "modules/ImageWriter.hpp"
#include <iostream>
#include <string>

using namespace std;

class IOImage
{
private:
    Image _image;
    string _outputPath;

public:
    IOImage(string inputPath, string outputPath);

    void convert();
};