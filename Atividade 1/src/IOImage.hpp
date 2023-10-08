#include "modules/MatrixConverter.hpp"
#include "modules/ImageGenerator.hpp"

class IOImage
{
private:
    Image _image;
    string _outputPath;

public:
    IOImage(string inputPath, string outputPath);

    void convertToPng();

    void convertToPpm();
};