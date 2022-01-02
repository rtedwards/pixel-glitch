// Various sorting functions and helper functions

#pragma once

#include <map>
#include <vector>

#include "pixel.hpp"

using Row = std::vector<Pixel>;

// TODO: create enum or dict
// enum class COLORS {
//     R,
//     G,
//     B,
//     A
// };

std::vector<Row> horizontal_line(unsigned char *image_buffer, int height, int width, int channels, std::string sort_value) {
    unsigned char *pixel_offset;
    Colors colors;  // TODO: initialize to set size
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;

    std::vector<Row> matrix(height, std::vector<Pixel>(width));

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            pixel_offset = image_buffer + (col + width * row) * channels;

            red = pixel_offset[0];
            green = pixel_offset[1];
            blue = pixel_offset[2];
            alpha = pixel_offset[3];

            colors['r'] = pixel_offset[0];
            colors['g'] = pixel_offset[1];
            colors['b'] = pixel_offset[2];
            colors['a'] = pixel_offset[3];

            matrix[row][col] = Pixel{ red, green, blue, alpha, pixel_value(colors, sort_value) };
        };
    };
    return matrix;
}
