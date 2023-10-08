#include "ImageGenerator.hpp"

ImageGenerator::ImageGenerator(Image image)
{
    _image = image;
}

void ImageGenerator::saveAs(ImageType type, string filePath)
{
    switch (type)
    {
        case PNG:
            _image.magick("PNG");
            break;
        case PPM:
            _image.magick("PPM");
            break;
        default:
            break;
    }

    _image.write(filePath);
}