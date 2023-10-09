#include "ImageWriter.hpp"

ImageWriter::ImageWriter(Image image)
{
    _image = image;
}

void ImageWriter::saveAs(string type, string filePath)
{
    try
    {
        _image.magick(type);    // Set the image format
        _image.write(filePath); // Write the image to a file
        cout << "Converted to " << type << "..." << endl;
    }
    catch (const Magick::ErrorMissingDelegate &e) // If format not specified
    {
        cout << "Format not specified, saving in default format (PNG)." << endl;
        _image.magick("PNG");
        _image.write(filePath + ".png");
    }
    catch (const Magick::Error &e) // If format not supported
    {
        cout << "Error: " << e.what() << endl;
        return;
    }
}