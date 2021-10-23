#include <iostream>
#include <parse_user_inputs.hpp>

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

    return 0;
}
