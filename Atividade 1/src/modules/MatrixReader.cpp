#include "MatrixReader.hpp"

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
            double r = stod(line.substr(0, line.find(" "))) / 255;
            line = line.substr(line.find(" ") + 1, line.length());

            double g = stod(line.substr(0, line.find(" "))) / 255;
            line = line.substr(line.find(" ") + 1, line.length());
            
            double b = stod(line.substr(0, line.find(" "))) / 255;
            line = line.substr(line.find(" ") + 1, line.length());

            ColorRGB color(r, g, b);
            image.pixelColor(j, i, color);
        }
    }

    return image;
}