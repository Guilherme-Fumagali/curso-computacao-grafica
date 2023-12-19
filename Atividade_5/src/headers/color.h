#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include "Interval.h"

#include <iostream>

/**
 * Alias for the vec3 class, representing color.
 */
using color = vec3;

/**
 * @brief Writes the color values to an output stream.
 *
 * This function takes a color and the number of samples per pixel as input, scales the color by the inverse of the number of samples,
 * clamps each color component within the interval [0.000, 0.999], and writes the result to the color object.
 *
 * @param pixel_color The color to be written. It is a vec3 where each component represents a color channel (red, green, blue).
 * @param samples_per_pixel The number of samples per pixel. This is used to scale the color.
 * @return The color object with the scaled and clamped color values.
 */
color write_color(color pixel_color, int samples_per_pixel) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // Divide the color by the number of samples.
    auto scale = 1.0 / samples_per_pixel;
    r *= scale;
    g *= scale;
    b *= scale;

    // Write the translated [0,255] value of each color component.
    static const interval intensity(0.000, 0.999);

    return {intensity.clamp(r), intensity.clamp(g), intensity.clamp(b)};
}

#endif