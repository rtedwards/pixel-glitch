

#define CATCH_CONFIG_MAIN
// #define CATCH_CONFIG_RUNNER

#include "catch.hpp"
#include "pixel.hpp"
#include "sorting.hpp"

SCENARIO("Pixels can be compared by value", "[sorting, pixel]") {
    GIVEN("two Pixels") {
        WHEN("forward sorting (reverse == false") {
            bool reverse = false;
            THEN("pixel_a.value < pixel_b.value") {
                Pixel pixel_a = { 0x00, 0x00, 0x00, 0x00, 0 };
                Pixel pixel_b = { 0x00, 0x00, 0x00, 0x00, 255 };
                REQUIRE(compare_pixels(pixel_a, pixel_b, reverse) == false);
            }
            THEN("pixel_a.value > pixel_b.value") {
                Pixel pixel_a = { 0x00, 0x00, 0x00, 0x00, 255 };
                Pixel pixel_b = { 0x00, 0x00, 0x00, 0x00, 0 };
                REQUIRE(compare_pixels(pixel_a, pixel_b, reverse) == true);
            }
            THEN("pixel_a.value == pixel_b.value") {
                Pixel pixel_a = { 0x00, 0x00, 0x00, 0x00, 255 };
                Pixel pixel_b = { 0x00, 0x00, 0x00, 0x00, 255 };
                REQUIRE(compare_pixels(pixel_a, pixel_b, reverse) == true);
            }
        }

        WHEN("reverse sorting (reverse == true") {
            bool reverse = true;
            THEN("pixel_a.value < pixel_b.value") {
                Pixel pixel_a = { 0x00, 0x00, 0x00, 0x00, 0 };
                Pixel pixel_b = { 0x00, 0x00, 0x00, 0x00, 255 };
                REQUIRE(compare_pixels(pixel_a, pixel_b, reverse) == true);
            }
            THEN("pixel_a.value > pixel_b.value") {
                Pixel pixel_a = { 0x00, 0x00, 0x00, 0x00, 255 };
                Pixel pixel_b = { 0x00, 0x00, 0x00, 0x00, 0 };
                REQUIRE(compare_pixels(pixel_a, pixel_b, reverse) == false);
            }
            THEN("pixel_a.value == pixel_b.value") {
                Pixel pixel_a = { 0x00, 0x00, 0x00, 0x00, 255 };
                Pixel pixel_b = { 0x00, 0x00, 0x00, 0x00, 255 };
                REQUIRE(compare_pixels(pixel_a, pixel_b, reverse) == false);
            }
        }
    }
}