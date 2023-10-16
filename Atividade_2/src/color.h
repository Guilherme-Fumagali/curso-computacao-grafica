#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <iostream>

/**
 * Alias for the vec3 class, representing color.
 */
using color = vec3;

/**
 * Writes the color values to an output stream.
 *
 * This function writes the translated [0,255] value of each color component to the
 * output stream in the format "R G B\n".
 *
 * @param out          The output stream to write the color to.
 * @param pixel_color  The color to be written.
 */
void write_color(std::ostream &out, color pixel_color) {
    out << static_cast<int>(255.999 * pixel_color.x()) << ' '
        << static_cast<int>(255.999 * pixel_color.y()) << ' '
        << static_cast<int>(255.999 * pixel_color.z()) << '\n';
}

#endif