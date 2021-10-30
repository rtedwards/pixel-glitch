#pragma once

#include <functional>
#include <vector>

#include "pixel.hpp"
#include "sorting.hpp"
#include "stb_image.h"
#include "stb_image_write.h"

using Row = std::vector<Pixel>;

class Image {
  public:
    int width;
    int height;
    int channels;

    std::vector<Row> rows;

    Image();

    Image &load(std::string filename);
    Image &save(std::string filename, std::string image_type);
    Image &sort_image(std::string sort_method, int color, bool reverse);
    Image &sort_image_pixels(std::string sort_method, int color, bool reverse);

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

Image &Image::sort_image(std::string sort_method, int color, bool reverse) {
    int offset;
    unsigned char *pixel_offset;

    std::vector<Pixel> image_row = std::vector<Pixel>(this->width);

    for (int row = 0; row < this->height; row++) {
        for (int col = 0; col < this->width; col++) {
            pixel_offset = this->image_buffer + (col + this->width * row) * this->channels;

            // TODO: only use a pointer to offset to avoid creating and copying 4 new variables
            // maybe use a macro of colors to numbers for readability
            uint8_t red = pixel_offset[0];
            uint8_t green = pixel_offset[1];
            uint8_t blue = pixel_offset[2];
            uint8_t alpha = pixel_offset[3];
            image_row[col] = Pixel{ red, green, blue, alpha, (uint8_t)(blue) };
        }

        std::sort(image_row.begin(), image_row.end(), [reverse](Pixel x, Pixel y) { return compare_pixels(x, y, reverse); });

        for (int col = 0; col < this->width; col++) {
            // TODO: Create new image_buffer and fill it with what each pixel offset points to
            // this let's us loop by steps of 4 rather than 1
            offset = (col + this->width * row) * this->channels;
            this->image_buffer[offset] = image_row[col].red;
            this->image_buffer[offset + 1] = image_row[col].green;
            this->image_buffer[offset + 2] = image_row[col].blue;
            this->image_buffer[offset + 3] = image_row[col].alpha;
        }
    }
    return *this;
}
