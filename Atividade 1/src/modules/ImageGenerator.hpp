#include <Magick++.h>
#include <fstream>

using namespace Magick;
using namespace std;

class ImageGenerator {
    private:
        Image _image;
    public:
        enum ImageType {
            PNG,
            PPM
        };

        ImageGenerator(Image image);

        void saveAs(ImageType type, string filePath);
};