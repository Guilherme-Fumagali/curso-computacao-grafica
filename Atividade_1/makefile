all: main.o MatrixIOImage.o MatrixReader.o ImageWriter.o
	gcc -o build/main build/main.o build/MatrixIOImage.o build/modules/MatrixReader.o build/modules/ImageWriter.o `Magick++-config --cppflags --cxxflags --ldflags --libs` -lstdc++

main.o: main.cpp 
	mkdir -p build
	gcc -c main.cpp -o build/main.o `Magick++-config --cppflags --cxxflags --ldflags --libs`

MatrixIOImage.o: src/MatrixIOImage.cpp src/MatrixIOImage.hpp
	mkdir -p build
	gcc -c src/MatrixIOImage.cpp -o build/MatrixIOImage.o `Magick++-config --cppflags --cxxflags --ldflags --libs` 

MatrixReader.o: src/modules/MatrixReader.cpp src/modules/MatrixReader.hpp
	mkdir -p build/modules
	gcc -c src/modules/MatrixReader.cpp -o build/modules/MatrixReader.o `Magick++-config --cppflags --cxxflags --ldflags --libs`

ImageWriter.o: src/modules/ImageWriter.cpp src/modules/ImageWriter.hpp
	mkdir -p build/modules
	gcc -c src/modules/ImageWriter.cpp -o build/modules/ImageWriter.o `Magick++-config --cppflags --cxxflags --ldflags --libs`

docs:
	doxygen Doxyfile

clean:
	rm -rf build