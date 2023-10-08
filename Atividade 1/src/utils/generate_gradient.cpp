#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    if (argc != 2)
        cout << "Usage: " << argv[0] << " output_file" << endl;

    int height = 255;
    int width = 255;
    string output_file = argv[1];

    ofstream file;
    file.open(output_file);

    file << height << " " << width << endl;

    int r = 0;
    int g = 255;
    int b = 255;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            r += 1;
            g -= 1;
            file << r << " " << g << " " << b << " ";
        }

        r = 0;
        g = 255;
        b = 255;
        file << endl;
    }

    file.close();

    return 0;
}