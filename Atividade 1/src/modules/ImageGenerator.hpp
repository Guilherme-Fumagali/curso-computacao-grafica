#include <Magick++.h>
#include <fstream>

using namespace Magick;
using namespace std;

class ImageGenerator {
    private:
        Image _image;
    public:
        ImageGenerator(Image image);

        void saveAsPng(string filePath);

        void saveAsPpm(string filePath);
};