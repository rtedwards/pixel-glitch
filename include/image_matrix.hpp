#pragma once

#include <functional>
#include <vector>

#include "pixel.hpp"
#include "shapes.hpp"
#include "sorting.hpp"
#include "stb_image.h"
#include "stb_image_write.h"

using PixelRow = std::vector<Pixel>;

class Image {
  public:
    int width;
    int height;
    int channels;

    std::vector<PixelRow> matrix;

    Image();

    Image &load(std::string filename);
    Image &save(std::string filename, std::string image_type);
    Image &sort_image(std::string sort_method, int color, bool reverse);
    Image &sort_image_pixels(std::string sort_method, int color, bool reverse);

    std::vector<PixelRow> &create_image_matrix(std::string shape);

  private:
    unsigned char *image_buffer;
};

Image::Image(){};

Image &Image::load(std::string filename) {
    image_buffer = stbi_load(filename.c_str(), &this->width, &this->height, &this->channels, 0);
    if (image_buffer == NULL) {
        std::cout << "Error loading image: " << filename << std::endl;
        exit(1);
    }
    std::cout << "(" << this->width << ", " << this->height << ") - " << this->channels << std::endl;
    return *this;
};

Image &Image::save(std::string filename, std::string image_type) {
    if (image_type == "png" || "PNG") {
        std::cout << "saving image to: " << filename << std::endl;
        stbi_write_png(filename.c_str(), width, height, channels, image_buffer, width * channels);
    }
    return *this;
};

std::vector<PixelRow> &Image::create_image_matrix(std::string shape) {
    // TODO: switch statement to call method according to shape
    std::vector<PixelRow> rows;

    if (shape == "line") {
        matrix = horizontal_line(this->image_buffer, this->height, this->width, this->channels);
    } else {
        std::logic_error(shape + " Not Implemented!");
    }
    return matrix;
}

Image &Image::sort_image(std::string sort_method, int color, bool reverse) {
    this->matrix = this->create_image_matrix(sort_method);

    for (auto &row : matrix) {
        std::sort(row.begin(), row.end(), [reverse](Pixel x, Pixel y) { return compare_pixels(x, y, reverse); });
    }

    int offset;
    for (int row = 0; row < this->height; row++) {
        for (int col = 0; col < this->width; col++) {
            offset = (col + this->width * row) * this->channels;
            this->image_buffer[offset] = matrix[row][col].red;
            this->image_buffer[offset + 1] = matrix[row][col].green;
            this->image_buffer[offset + 2] = matrix[row][col].blue;
            this->image_buffer[offset + 3] = matrix[row][col].alpha;
        }
    }
    return *this;
}
