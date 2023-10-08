#include "src/IOImage.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <input_file> <output_file>" << endl;
        return 1;
    }

    IOImage ioImage(argv[1], argv[2]);
    ioImage.convertToPng();
    return 0;
}