// Various sorting functions and helper functions

#pragma once

#include "pixel.hpp"

bool compare_pixels(const Pixel &x, const Pixel &y, bool reverse) { return reverse ? x.value < y.value : x.value >= y.value; }

// Calculates the pixel value to use for sorting
// uint8_t pixel_value(std::string method) { std::logic_error("Not Implemented"); }

// Determines the most prevalent colors in image [r, g, b, a]
// std::string most_prevalent_colors(Image &image) { std::logic_error("Not Implemented"); }