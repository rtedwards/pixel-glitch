

#define CATCH_CONFIG_MAIN
// #define CATCH_CONFIG_RUNNER

#include "catch.hpp"
#include "pixel.hpp"
#include "sorting.hpp"

TEST_CASE("Test Sorting", "[sorting, pixel]") {
    SECTION("Forward") {
        bool reverse = false;
        SECTION("A < B") {
            Pixel pixel_a = { 0x00, 0x00, 0x00, 0x00, 0 };
            Pixel pixel_b = { 0x00, 0x00, 0x00, 0x00, 255 };
            REQUIRE(compare_pixels(pixel_a, pixel_b, reverse) == false);
        }
        SECTION("A > B") {
            Pixel pixel_a = { 0x00, 0x00, 0x00, 0x00, 255 };
            Pixel pixel_b = { 0x00, 0x00, 0x00, 0x00, 0 };
            REQUIRE(compare_pixels(pixel_a, pixel_b, reverse) == true);
        }
        SECTION("A == B") {
            Pixel pixel_a = { 0x00, 0x00, 0x00, 0x00, 255 };
            Pixel pixel_b = { 0x00, 0x00, 0x00, 0x00, 255 };
            REQUIRE(compare_pixels(pixel_a, pixel_b, reverse) == false);
        }
    }

    SECTION("Reverse") {
        bool reverse = true;
        SECTION("A < B") {
            Pixel pixel_a = { 0x00, 0x00, 0x00, 0x00, 0 };
            Pixel pixel_b = { 0x00, 0x00, 0x00, 0x00, 255 };
            REQUIRE(compare_pixels(pixel_a, pixel_b, reverse) == true);
        }
        SECTION("A > B") {
            Pixel pixel_a = { 0x00, 0x00, 0x00, 0x00, 255 };
            Pixel pixel_b = { 0x00, 0x00, 0x00, 0x00, 0 };
            REQUIRE(compare_pixels(pixel_a, pixel_b, reverse) == false);
        }
        SECTION("A == B") {
            Pixel pixel_a = { 0x00, 0x00, 0x00, 0x00, 255 };
            Pixel pixel_b = { 0x00, 0x00, 0x00, 0x00, 255 };
            REQUIRE(compare_pixels(pixel_a, pixel_b, reverse) == false);
        }
    }
}