#include <Magick++.h>
#include <fstream>
#include <iostream>

using namespace Magick;
using namespace std;

/**
 * @brief Class for converting a matrix from a file to an @link Magick::Image @endlink.
 * @see https://imagemagick.org/Magick++/Image++.html for more information about the @link Magick::Image @endlink class.
 */
class MatrixConverter {
    public:
        /**
         * @brief Reads a matrix from a file and converts it to an image.
         * 
         * @param filePath The path to the file containing the matrix.
         * @return The converted image.
         */
        Image readFromFile(string filePath);
};