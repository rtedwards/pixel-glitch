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

    Image image;
    image.load(params.image_filename)
        .sort_image("standard", 4, true)
        .save(std::string("images/sorted.png"), "png");

    // stbi_image_free(image);
}
