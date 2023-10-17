#include <iostream>
#include <fstream>
#include "MatrixIOImage.hpp"

using namespace std;

/**
 * @brief This is the main function for a program that reads an input file containing
 * image data, processes it, and generates an output image.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line arguments.
 * @return 0 if the program executed successfully; otherwise, a non-zero value.
 */
int main(int argc, char** argv) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <input file> <output file>" << std::endl;
        return 1;
    }

    // Attempt to open the input file.
    ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cerr << "Could not open file " << argv[1] << std::endl;
        return 1;
    }

    // Read the image dimensions from the first line of the input file.
    string line;
    getline(file, line);
    int width_image = stoi(line.substr(0, line.find(' ')));
    int height_image = stoi(line.substr(line.find(' ') + 1, line.length()));

    // Create a dynamic 2D array to store image data.
    int** matrix = new int*[height_image];
    for (int i = 0; i < height_image; i++)
        matrix[i] = new int[width_image * 3];

    // Read the image data from the input file.
    for (int i = 0; i < height_image; i++) {
        getline(file, line);
        for (int j = 0; j < width_image * 3; j++){
            matrix[i][j] = stoi(line.substr(0, line.find(' ')));
            line = line.substr(line.find(' ') + 1, line.length());
        }
    }

    // Process and generate the image using MatrixIOImage class.
    MatrixIOImage::generateImageFromMatrix(matrix, width_image, height_image, argv[2]);

    // Free the memory allocated for the dynamic 2D array.
    for (int i = 0; i < height_image; i++)
        delete[] matrix[i];
    delete[] matrix;

    return 0;
}

