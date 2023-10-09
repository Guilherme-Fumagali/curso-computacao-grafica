#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * @brief This program generates a matrix at the format of the application of a gradient with dimensions 255x255.
 * This gradient is generated from right to left, starting with the color cyan (0, 255, 255) and ending with the color light pink (255, 0, 255).
 *
 * @param output_file path to the output file.
 *
 * @return int 0 if the program was executed successfully, 1 otherwise.
 */
int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        cout << "Usage: " << argv[0] << " output_file" << endl;
        return 1;
    }

    int height = 255;
    int width = 255;
    string output_file = argv[1];

    ofstream file;
    file.open(output_file);

    file << height << " " << width << endl;

    /* Initializate the color cyan */
    int r = 0;
    int g = 255;
    int b = 255;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            /**
             * Sum 1 to the red color and subtract 1 from the green color
             * How the pink color is (255, 0, 255), and the cyan color is (0, 255, 255),
             * we can generate the gradient from right to left by summing 1 to the red color and subtracting 1 from the green color.
             */
            r += 1;
            g -= 1;
            file << r << " " << g << " " << b << " ";
        }

        /* Reset the cyan color */
        r = 0;
        g = 255;
        b = 255;
        file << endl;
    }

    file.close();

    return 0;
}