#include "MatrixIOImage.hpp"

IOImage::IOImage(string inputPath, string outputPath)
{
    MatrixConverter converter;
    _image = converter.readFromFile(inputPath);
    _outputPath = outputPath;
}

void IOImage::convertToPng()
{
    ImageGenerator generator(_image);
    generator.saveAs(ImageGenerator::PNG, this->_outputPath);
}

void IOImage::convertToPpm()
{
    ImageGenerator generator(_image);
    generator.saveAs(ImageGenerator::PPM, this->_outputPath);
}