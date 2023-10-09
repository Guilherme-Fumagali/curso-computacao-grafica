#include <iostream>
#include <fstream>
#include <string>

using namespace std;


/**
 * @brief Esse programa gera uma matriz de gradiente no formato da aplicação com dimensões 255x255.
 * O gradiente é gerado da direita para a esquerda, começando com a cor ciano (0, 255, 255) e 
 * terminando com a cor rosa claro (255, 0, 255).
 * 
 * @param output_file O caminho para o arquivo de saída que conterá a imagem.
 * 
 * @return int 0 se a geração da imagem foi bem sucedida, 1 caso contrário.
 */
int main(int argc, char const *argv[])
{
    if (argc != 2){
        cout << "Usage: " << argv[0] << " output_file" << endl;
        return 1;
    }

    int height = 255;
    int width = 255;
    string output_file = argv[1];

    ofstream file;
    file.open(output_file);

    file << height << " " << width << endl;

    /* Inicializando a cor ciano */
    int r = 0;
    int g = 255;
    int b = 255;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Soma 1 no vermelho e subtrai 1 no verde, indo em direção a cor rosa claro.
            r += 1;
            g -= 1;
            file << r << " " << g << " " << b << " ";
        }

        // Reinicia a cor ciano.
        r = 0;
        g = 255;
        b = 255;
        file << endl;
    }

    file.close();

    return 0;
}