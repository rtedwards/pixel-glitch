#ifndef PARSE_USER_ARGUMENTS
#define PARSE_USER_ARGUMENTS

#include <argparse.hpp>

struct Parameters {
    std::string image_file_path;
    std::string algorithm;
    float angle;
    float percent;
    bool reverse;
    std::string shape;
    bool verbose;
} params;

Parameters parse_arguments(int argc, char* argv[]){
    argparse::ArgumentParser program("program name");
    
    program.add_argument("image")
        .help("path to image file")
        .required();

    program.add_argument("-a", "--algorithm")
        .help("sorting algorithm (bubblesort, heapsort, insertionsort, mergesort, quicksort")
        .default_value(std::string("quicksort"))
        .action([](const std::string& value) {
            static const std::vector<std::string> choices = { "bubblesort", "heapsort", "insertionsort", "mergesort", "quicksort" };
            if (std::find(choices.begin(), choices.end(), value) != choices.end()) {
                return value;
            }
            return std::string{ "quicksort" };
        });
    
    program.add_argument("-a", "--angle")
        .help("sorting angle (degrees)")
        .default_value(0.0f)
        .scan<'g', double>();

    program.add_argument("-%", "--percent")
        .help("stop sorting once xx% finished")
        .default_value(1.0f)
        .scan<'g', double>();

    program.add_argument("-r", "--reverse")
        .help("sorting algorithm")
        .default_value(false)
        .implicit_value(true);

    program.add_argument("-s", "--shape")
        .help("sorting shape (line, circle, square, equation)")
        .default_value(std::string("line"))
        .action([](const std::string& value) {
            static const std::vector<std::string> choices = { "line", "circle", "square", "equation" };
            if (std::find(choices.begin(), choices.end(), value) != choices.end()) {
                return value;
            }
            return std::string{ "line" };
        });

    program.add_argument("-V", "--verbose")
        .help("increase output verbosity")
        .default_value(false)
        .implicit_value(true);

    try {
        program.parse_args(argc, argv);
    }
    catch (const std::runtime_error& err) {
        std::cout << err.what() << std::endl;
        std::cout << program;
        exit(0);
    }

    params.image_file_path = program.get<std::string>("image");
    params.algorithm = program.get<std::string>("--algorithm");
    params.angle = program.get<float>("--angle");
    params.percent = program.get<float>("--percent");
    params.reverse = program.get<bool>("--reverse");
    params.shape = program.get<std::string>("--shape");
    params.verbose = program.get<bool>("--verbose");

    return params;
};

#endif