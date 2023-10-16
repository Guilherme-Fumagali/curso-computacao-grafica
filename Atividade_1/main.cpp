#include "src/MatrixIOImage.hpp"
#include <iostream>

/**
 * @brief Main function that converts a matrix to a image. The format of the output image is determined by the extension of the output file.
 * 
 * @param input_file path to the input file containing the matrix.
 * @param output_file path to the output file.
 * 
 * @return int 0 if the program was executed successfully, 1 otherwise.
 */
int main(int argc, char const *argv[])
{
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <input_file> <output_file>" << endl;
        return 1;
    }

    MatrixIOImage ioImage(argv[1], argv[2]); // Create an MatrixIOImage object.
    ioImage.convert(); // Convert the matrix to a PNG image.
    return 0;
}