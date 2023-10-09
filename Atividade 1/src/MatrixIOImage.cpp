#include "MatrixIOImage.hpp"

IOImage::IOImage(string inputPath, string outputPath)
{
    MatrixConverter converter;
    _image = converter.readFromFile(inputPath);
    _outputPath = outputPath;
}

void IOImage::convertToPng()
{
    ImageWriter generator(_image);
    generator.saveAs(ImageWriter::PNG, this->_outputPath);
}

void IOImage::convertToPpm()
{
    ImageWriter generator(_image);
    generator.saveAs(ImageWriter::PPM, this->_outputPath);
}