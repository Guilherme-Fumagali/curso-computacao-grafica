#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * @brief Esse programa gera uma matriz de um círculo no formato da aplicação com dimensões 500x500.
 * Esse círculo é gerado com o centro na posição (250, 250) e raio 200, na cor laranja (255, 155, 0).
 * 
 * @param output_file O caminho para o arquivo de saída que conterá a imagem.
 * 
 * @return int 0 se a geração da imagem foi bem sucedida, 1 caso contrário.
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

    int color_circle[] = {255, 155, 0};
    int color_background[] = {0, 0, 0};

    int radius = 200;
    int center_x = 250;
    int center_y = 250;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++) 
        {
            /* Coordenadas do pixel em relação ao centro do círculo */
            int x = i - center_x; 
            int y = j - center_y;

            /* Verifica se o pixel está dentro do círculo */
            if (x * x + y * y <= radius * radius)
                file << color_circle[0] << " " << color_circle[1] << " " << color_circle[2] << " ";
            else
                file << color_background[0] << " " << color_background[1] << " " << color_background[2] << " ";
        }

        file << endl;
    }

    file.close();

    return 0;
}