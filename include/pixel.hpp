#pragma once

#include <map>
#include <numeric>
#include <vector>

typedef std::map<char, uint8_t> Colors;

struct Pixel {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
    unsigned int sort_value;  // value used for sorting
};

unsigned int pixel_value(Colors colors_map, std::string sort_value) {
    std::vector<char> possible_values{ 'r', 'g', 'b', 'a' };
    std::vector<char> color_values;
    for (const char &i : sort_value) {
        if (std::find(possible_values.begin(), possible_values.end(), i) != possible_values.end()) {  //&& std::find(sort_values.begin(), sort_values.end(), i) != sort_values.end()) {
            color_values.push_back(i);
        }
    }

    std::vector<uint8_t> colors;
    for (auto const &[key, val] : colors_map) {
        if (std::find(color_values.begin(), color_values.end(), key) != color_values.end())
            colors.push_back(val);
    };
    return std::accumulate(colors.begin(), colors.end(), 0);
}