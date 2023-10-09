#include "ImageWriter.hpp"

ImageWriter::ImageWriter(Image image)
{
    _image = image;
}

void ImageWriter::saveAs(ImageType type, string filePath)
{
    switch (type)
    {
        case PNG:
            _image.magick("PNG"); // Set the image format to PNG
            break;
        case PPM:
            _image.magick("PPM"); // Set the image format to PPM
            break;
        default:
            break;
    }

    _image.write(filePath); // Write the image to a file
}