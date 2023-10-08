#include "src/MatrixIOImage.hpp"
#include <iostream>

/**
 * @brief Main function that converts an matrix to a PNG image.
 * 
 * @param input_file path to the input file that contains the matrix.
 * @param output_file path to the output file that will contain the PNG image.
 * 
 * @return 0 if the conversion was successful, 1 otherwise.
 */
int main(int argc, char const *argv[])
{
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <input_file> <output_file>" << endl;
        return 1;
    }

    IOImage ioImage(argv[1], argv[2]); // Create an IOImage object.
    ioImage.convertToPng(); // Convert the matrix to a PNG image.
    return 0;
}