// #define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
// #define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

struct Pixel {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
    uint8_t value; // value used for sorting

    int row;
    int col;
    int index; // index used for sort order
    int offset; // byte offset from start of image
};

using Row = std::vector<Pixel>;

class Image {
    public:
    int width;
    int height;
    int channels; 
    
    std::vector<Row> rows;

    Image() {};

    void load(std::string filename);
    void save(std::string filename, std::string image_type);
    void sort_image(std::string sort_method, int color);

    private:
    unsigned char *image_buffer;

};

void Image::load(std::string filename) {
    image_buffer = stbi_load(filename.c_str(), &width, &height, &channels, 0);
    if (image_buffer == NULL) {
        std::cout << "Error loading image: " << filename << std::endl;
        exit(1);
    }
    std::cout << "(" << width << ", " << height << ") - "<< channels << std::endl;
};

void Image::save(std::string filename, std::string image_type) {
    if (image_type == "png" || "PNG") {
        std::cout << "saving image to: " << filename << std::endl;
        stbi_write_png(filename.c_str(), width, height, channels, image_buffer, width * channels);
    }
};

void Image::sort_image(std::string sort_method, int color) {
    int offset;
    unsigned char *pixel_offset;
    std::vector<uint8_t> image_row = std::vector<uint8_t> (this->width);
    
    for (int row=0; row<this->height; row++) {
        for (int col=0; col<this->width; col++) {
            // pixel_offset = image + (row + width * col) * channels;
            pixel_offset = this->image_buffer + (col + this->width * row) * this->channels;
            image_row[col] = pixel_offset[color];
        }
        
        std::sort(image_row.begin(), image_row.end());

        for (int col=0; col<this->width; col++) {
            offset = (col + this->width * row) * this->channels + color;
            this->image_buffer[offset] = image_row[col];
        }
    }
}

