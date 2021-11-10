// Various sorting functions and helper functions

#pragma once

#include <vector>

#include "pixel.hpp"

using Row = std::vector<Pixel>;

std::vector<Row> horizontal_line(unsigned char *image_buffer, int height, int width, int channels) {
    // TODO: add parameter to calculate sort value

    unsigned char *pixel_offset;
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
            matrix[row][col] = Pixel{ red, green, blue, alpha, (uint8_t)(red * blue * green) };
        }
    }
    return matrix;
}