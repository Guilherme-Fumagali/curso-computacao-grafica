#include "MatrixConverter.hpp"

Image MatrixConverter::readFromFile(string filePath)
{
    ifstream file(filePath);
    string line;

    getline(file, line);
    int width = stoi(line.substr(0, line.find(" ")));
    int height = stoi(line.substr(line.find(" ") + 1, line.length()));

    Image image(Geometry(width, height), ColorRGB(0, 0, 0));

    for (int i = 0; i < height; i++)
    {
        getline(file, line);
        for (int j = 0; j < width; j++)
        {
            int r = stoi(line.substr(0, line.find(" ")));
            line = line.substr(line.find(" ") + 1, line.length());
            int g = stoi(line.substr(0, line.find(" ")));
            line = line.substr(line.find(" ") + 1, line.length());
            int b = stoi(line.substr(0, line.find(" ")));
            line = line.substr(line.find(" ") + 1, line.length());

            ColorRGB color(r, g, b);
            image.pixelColor(j, i, color);
        }
    }

    return image;
}