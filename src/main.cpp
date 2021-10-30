#include <iostream>

#define STB_IMAGE_IMPLEMENTATION // needs to be in main.cpp
#define STB_IMAGE_WRITE_IMPLEMENTATION // needs to be in main.cpp

#include "parse_user_inputs.hpp"
#include "image_matrix.hpp"


int main(int argc, char* argv[]) {

    auto params = parse_arguments(argc, argv);

    if (params.verbose == true) {
        std::cout << "image: "      << params.image_filename << std::endl;
        std::cout << "algorithm: "  << params.algorithm << std::endl;
        std::cout << "angle: "      << params.angle << std::endl;
        std::cout << "percent: "    << params.percent << std::endl;
        std::cout << "reverse: "    << params.reverse << std::endl;
        std::cout << "shape: "      << params.shape << std::endl;
    }

    // read image
    Image matrix;
    matrix.load(params.image_filename);
    matrix.save(std::string("images/sorted.png"), "png");

    // int width, height, channels, ok;
    // ok = stbi_info(params.image_filename.c_str(), &width, &height, &channels);
    // if (!ok) {
    //     std::cout << "Error loading image information: " << params.image_filename << std::endl;
    //     exit(1);
    // }
    // std::cout << "(" << width / channels << ", " << height / channels << ") - "<< channels << std::endl;
    
    // unsigned char *image = stbi_load(params.image_filename.c_str(), &width, &height, &channels, 4);
    // if (image == NULL) {
    //     std::cout << "Error loading image: " << params.image_filename << std::endl;
    //     exit(1);
    // }
    // std::cout << "(" << width << ", " << height << ") - "<< channels << std::endl << std::endl;


    // int offset;
    // unsigned char *pixel_offset;
    // std::vector<uint8_t> image_row = std::vector<uint8_t> (width);
    // int color = 0;
    // for (int row=0; row<height; row++) {
    //     for (int col=0; col<width; col++) {
    //         // pixel_offset = image + (row + width * col) * channels;
    //         pixel_offset = image + (col + width * row) * channels;
    //         image_row[col] = pixel_offset[color];
    //     }
        
    //     std::sort(image_row.begin(), image_row.end());

    //     for (int col=0; col<width; col++) {
    //         offset = (col + width * row) * channels + color;
    //         image[offset] = image_row[col];
    //     }
    // }

    // std::cout << "saving image" << std::endl;
    // stbi_write_png("images/sorted.png", width, height, channels, image, width * channels);

    // stbi_image_free(image);
}
