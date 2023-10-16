#include <Magick++.h>
#include <iostream>
#include <fstream>

using namespace Magick;
using namespace std;

/**
 * @brief Module responsible for saving an image in a file with a specified format.
 * As an interface, this module receives an @link Magick::Image @endlink object and saves it in a file.
 */
class ImageWriter
{
private:
    Image _image;

public:

    /**
     * @brief Constructor for ImageGenerator class.
     * @param image The image to be generated and saved.
     */
    ImageWriter(Image image);

    /**
     * @brief Saves the image in the specified format and file path.
     * @param format The format in which the image should be saved.
     * @param filePath The file path where the image should be saved.
     */
    void saveAs(string format, string filePath);
};