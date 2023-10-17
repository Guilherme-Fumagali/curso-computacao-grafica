#include "MatrixIOImage.hpp"

void MatrixIOImage::generateImageFromMatrix(int **matrix, int width, int height, const string& outputPath) {
    Image image = convertMatrix(matrix, width, height);
    string extension = outputPath.substr(outputPath.find_last_of('.') + 1);
    if (extension == outputPath) extension = "png"; // If no extension is specified, save as PNG

    saveImage(image, extension, outputPath);
}

Image MatrixIOImage::convertMatrix(int** matrix, int width, int height) {
    /* Create a new image with the specified width and height, and fill it with black. */
    Image image(Geometry(width, height), ColorRGB(0, 0, 0));

    /* Iterate through the matrix and set the color of each pixel. */
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width * 3; j += 3)
        {
            /* Read the RGB values of each pixel. */
            double r = matrix[i][j] / 255.0;
            double g = matrix[i][j+1] / 255.0;
            double b = matrix[i][j+2] / 255.0;

            /* Set the pixel color. */
            ColorRGB color(r, g, b);
            image.pixelColor(j / 3, i, color);
        }

    return image;
}

void MatrixIOImage::saveImage(Image image, string format, string filePath) {
    try {
        image.magick(format);    // Set the image format
        image.write(filePath); // Write the image to a file
        cout << "Converted to " << format << "..." << endl;
    }
    catch (const ErrorMissingDelegate &e) // If format not specified
    {
        cout << "Format not specified, saving in default format (PNG)." << endl;
        image.magick("PNG");
        image.write(filePath + ".png");
    }
    catch (const Error &e) // If format not supported
    {
        cout << "Error: " << e.what() << endl;
        return;
    }
}