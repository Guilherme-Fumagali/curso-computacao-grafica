#include "MatrixIOImage.hpp"

MatrixIOImage::MatrixIOImage(string inputPath, string outputPath)
{
    MatrixReader converter;
    _image = converter.readFromFile(inputPath);
    _outputPath = outputPath;
}

void MatrixIOImage::convert()
{
    string extension = _outputPath.substr(_outputPath.find_last_of(".") + 1);
    ImageWriter writer(_image);
    writer.saveAs(extension, _outputPath);
}