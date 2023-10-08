#include <Magick++.h>
#include <fstream>

using namespace Magick;
using namespace std;

class MatrixConverter {
    public:
        static Image readFromFile(string filePath) {
            ifstream file(filePath);
            string line;

            getline(file, line);
            int width = stoi(line.substr(0, line.find(" ")));
            int height = stoi(line.substr(line.find(" ") + 1, line.length()));

            Image image(Geometry(width, height));

            for (int i = 0; i < height; i++)
            {
                getline(file, line);
                for (int j = 0; j < width; j++)
                {
                    int r = stoi(line.substr(0, line.find(" ")));
                    int g = stoi(line.substr(line.find(" ") + 1, line.find(" ")));
                    int b = stoi(line.substr(line.find(" ") + 1, line.length()));
                    ColorRGB color(r, g, b);
                    image.pixelColor(j, i, color);
                }
            }

            return image;
        }
};