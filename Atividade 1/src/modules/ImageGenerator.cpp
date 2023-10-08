#include "ImageGenerator.hpp"

ImageGenerator::ImageGenerator(Image image)
{
    _image = image;
}

void ImageGenerator::saveAsPng(string filePath)
{
    _image.magick("PNG");
    _image.write(filePath);
}

void ImageGenerator::saveAsPpm(string filePath)
{
    ofstream file(filePath);
    file << "P3" << endl;
    file << _image.columns() << " " << _image.rows() << endl;
    file << "255" << endl;

    for (int i = 0; i < _image.rows(); i++)
    {
        for (int j = 0; j < _image.columns(); j++)
        {
            ColorRGB color = _image.pixelColor(j, i);
            file << color.red() << " " << color.green() << " " << color.blue() << endl;
        }
    }
}