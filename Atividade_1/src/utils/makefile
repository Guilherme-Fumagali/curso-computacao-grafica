all: generate_circle generate_gradient generate_two_colors_square

generate_two_colors_square: generate_two_colors_square.cpp
	gcc -o generate_two_colors_square generate_two_colors_square.cpp -lstdc++

generate_circle: generate_circle.cpp
	gcc -o generate_circle generate_circle.cpp -lstdc++

generate_gradient: generate_gradient.cpp
	gcc -o generate_gradient generate_gradient.cpp -lstdc++

clean:
	rm -f generate_gradient
	rm -f generate_circle
	rm -f generate_two_colors_square