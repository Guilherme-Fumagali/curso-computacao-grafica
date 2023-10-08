#include "IOImage.hpp"

IOImage::IOImage(string inputPath, string outputPath)
{
    MatrixConverter converter;
    _image = converter.readFromFile(inputPath);
    _outputPath = outputPath;
}

void IOImage::convertToPng()
{
    ImageGenerator generator(_image);
    generator.saveAsPng(this->_outputPath);
}

void IOImage::convertToPpm()
{
    ImageGenerator generator(_image);
    generator.saveAsPpm(this->_outputPath);
}