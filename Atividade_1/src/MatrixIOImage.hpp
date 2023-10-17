#include <ImageMagick-7/Magick++.h>
#include <fstream>
#include <iostream>

using namespace Magick;
using namespace std;

/**
 * @brief Class responsible for converting a matrix and saving it in a file.
 *
 * This class uses the @link Magick::Image @endlink class to convert a matrix and save it in a file.
 * @see https://imagemagick.org/Magick++/Image++.html for more information about the @link Magick::Image @endlink class.
 */
class MatrixIOImage {
    public:

        /**
         * @brief Generates an image from a matrix and saves it in a file.
         *
         * @param matrix The matrix to be converted.
         * @param width The width of the matrix.
         * @param height The height of the matrix.
         * @param format The format in which the image should be saved.
         * @param outputPath The file path where the image should be saved.
         */
        static void generateImageFromMatrix(int** matrix, int width, int height, const string& outputPath);

    private:
        /**
         * @brief Reads a matrix and converts it to an image.
         * 
         * @param matrix The matrix to be converted.
         * @param width The width of the matrix.
         * @param height The height of the matrix.
         *
         * @return The converted @link Magick::Image @endlink.
         */
        static Image convertMatrix(int** matrix, int width, int height);

        /**
        * @brief Saves the image in the specified format and file path.
        *
        * @param format The format in which the image should be saved.
        * @param filePath The file path where the image should be saved.
        */
        static void saveImage(Image image, string format, string filePath);
};