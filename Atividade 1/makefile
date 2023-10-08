main: main.o ioImage.o matrixConverter.o imageGenerator.o
	gcc -o main build/main.o build/ioImage.o build/modules/matrixConverter.o build/modules/imageGenerator.o `Magick++-config --cppflags --cxxflags --ldflags --libs` -lstdc++

main.o: main.cpp 
	mkdir -p build
	gcc -c main.cpp -o build/main.o `Magick++-config --cppflags --cxxflags --ldflags --libs`

ioImage.o: src/IOImage.cpp src/IOImage.hpp
	mkdir -p build
	gcc -c src/IOImage.cpp -o build/ioImage.o `Magick++-config --cppflags --cxxflags --ldflags --libs` 

matrixConverter.o: src/modules/MatrixConverter.cpp src/modules/MatrixConverter.hpp
	mkdir -p build/modules
	gcc -c src/modules/MatrixConverter.cpp -o build/modules/matrixConverter.o `Magick++-config --cppflags --cxxflags --ldflags --libs`

imageGenerator.o: src/modules/ImageGenerator.cpp src/modules/ImageGenerator.hpp
	mkdir -p build/modules
	gcc -c src/modules/ImageGenerator.cpp -o build/modules/imageGenerator.o `Magick++-config --cppflags --cxxflags --ldflags --libs`

clean:
	rm -rf build