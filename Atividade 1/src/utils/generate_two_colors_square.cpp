#include <iostream>
#include <fstream>
#include <string>

using namespace std;
/**
 * @brief This program generates a matrix at the format of the application of a square with dimensions 500x500.
 * This square is generated with center at position (250, 250) and side 250, half of the image is black and the other half is white.
 *
 * @param output_file path to the output file.
 *
 * @return int 0 if the program was executed successfully, 1 otherwise.
 */
int main(int argc, char const *argv[])
{
    if (argc != 2)
        cout << "Usage: " << argv[0] << " output_file" << endl;

    int height = 500;
    int width = 500;

    string output_file = argv[1];

    ofstream file;
    file.open(output_file);

    file << height << " " << width << endl;

    int black[] = {0, 0, 0};
    int white[] = {255, 255, 255};

    int square_size = 250;

    int *square_color = black;
    int *background_color = white;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Verifica se o pixel está dentro do quadrado
            if (i >= height / 2 - square_size / 2 && i <= height / 2 + square_size / 2 &&
                j >= width / 2 - square_size / 2 && j <= width / 2 + square_size / 2)
                file << square_color[0] << " " << square_color[1] << " " << square_color[2] << " ";
            else
                file << background_color[0] << " " << background_color[1] << " " << background_color[2] << " ";
        }

        // Se a linha atual é a metade da imagem
        if (i == height / 2 - 1)
        {
            // Inverte as cores do quadrado e do fundo
            square_color = white;
            background_color = black;
        }

        file << endl;
    }

    file.close();

    return 0;
}