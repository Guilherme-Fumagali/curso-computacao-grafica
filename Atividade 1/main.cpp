#include "src/IOImage.hpp"

int main(int argc, char const *argv[])
{
    IOImage ioImage(argv[1], argv[2]);
    ioImage.convertToPng();
    return 0;
}