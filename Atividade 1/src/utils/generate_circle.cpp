#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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
            int x = i - center_x;
            int y = j - center_y;

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