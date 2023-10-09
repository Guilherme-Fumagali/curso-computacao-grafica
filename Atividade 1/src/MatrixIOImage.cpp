#include "MatrixIOImage.hpp"

IOImage::IOImage(string inputPath, string outputPath)
{
    MatrixConverter converter;
    _image = converter.readFromFile(inputPath);
    _outputPath = outputPath;
}

void IOImage::convert()
{
    string extension = _outputPath.substr(_outputPath.find_last_of(".") + 1);
    ImageWriter writer(_image);
    writer.saveAs(extension, _outputPath);
}