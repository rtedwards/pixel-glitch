#pragma once

struct Pixel {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
    uint8_t value;  // value used for sorting

    int row;
    int col;
    int index;   // index used for sort order
    int offset;  // byte offset from start of image
};