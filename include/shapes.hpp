// Various sorting functions and helper functions

#pragma once

#include <vector>

#include "pixel.hpp"

using Row = std::vector<Pixel>;

std::vector<Row> horizontal_line(unsigned char *image_buffer, int height, int width, int channels) {
    // TODO: add parameter to calculate sort value

    unsigned char *pixel_offset;

    std::vector<Row> matrix(height, std::vector<Pixel>(width));

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            pixel_offset = image_buffer + (col + width * row) * channels;

            // TODO: only use a pointer to offset to avoid creating and copying 4 new variables
            // maybe use a macro of colors to numbers for readability
            uint8_t red = pixel_offset[0];
            uint8_t green = pixel_offset[1];
            uint8_t blue = pixel_offset[2];
            uint8_t alpha = pixel_offset[3];
            matrix[row][col] = Pixel{ red, green, blue, alpha, (uint8_t)(red * blue * green) };
        }
    }
    return matrix;
}