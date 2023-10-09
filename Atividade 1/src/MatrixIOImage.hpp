#include "modules/MatrixReader.hpp"
#include "modules/ImageWriter.hpp"
#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Class for input/output of images using a matrix representation.
 * Uses the @ref MatrixReader module to read the input matrix and the @ref ImageWriter module to write the output image.
 */
class MatrixIOImage
{
private:
    Image _image;       // The image to be converted.
    string _outputPath; // The path to write the output image.

public:
    /**
     * @brief Constructs an MatrixIOImage object with the given input and output paths.
     *
     * @param inputPath The path to the input matrix.
     * @param outputPath The path to write the output image.
     */
    MatrixIOImage(string inputPath, string outputPath);

    /**
     * @brief Converts the input matrix to the output format.
     */
    void convert();
};