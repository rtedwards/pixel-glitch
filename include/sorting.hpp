// Various sorting functions and helper functions

#pragma once

#include "image_matrix.hpp"
#include "pixel.hpp"

// TODO: combine the 2 compare functions into 1 with an extra
// bool compare_pixels(const Pixel &x, const Pixel &y, bool reverse) { return reverse ? x.value < y.value : x.value > y.value; }
bool compare_pixels(const uint8_t &x, const uint8_t &y, bool reverse) { return reverse ? x < y : x > y; }

// bool compare_pixels(const Pixel &x, const Pixel &y) { return x.value < y.value; }
// bool compare_pixels_reverse(const uint8_t &x, const uint8_t &y) { return x.value < y.value; }

// bool compare_pixels(const uint8_t &x, const uint8_t &y) { return x < y; }
// bool compare_pixels_reverse(const uint8_t &x, const uint8_t &y) { return x < y; }

// uint8_t pixel_value( *f()) {

// }