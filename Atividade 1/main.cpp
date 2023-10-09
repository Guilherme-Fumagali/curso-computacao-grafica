#include "src/MatrixIOImage.hpp"
#include <iostream>

/**
 * @brief Função principal que converte uma matriz para uma imagem PNG.
 * 
 * @param input_file caminho para o arquivo de entrada que contém a matriz.
 * @param output_file caminho para o arquivo de saída que conterá a imagem.
 * 
 * @return int 0 se a conversão foi bem sucedida, 1 caso contrário.
 */
int main(int argc, char const *argv[])
{
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <input_file> <output_file>" << endl;
        return 1;
    }

    IOImage ioImage(argv[1], argv[2]); // Create an IOImage object.
    ioImage.convert(); // Convert the matrix to a PNG image.
    return 0;
}