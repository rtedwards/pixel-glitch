// #define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
// #define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

struct Pixel {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
    uint8_t value; // value used for sorting

    int row;
    int col;
    int index; // index used for sort order
    int offset; // byte offset from start of image
};

using Row = std::vector<Pixel>;

class ImageMatrix {
    public:
    int m_width;
    int m_height;
    int m_channels; 
    
    std::vector<Row> m_rows;

    ImageMatrix() {};

    void load(std::string filename);
    void save(std::string filename, std::string image_type);

    private:
    unsigned char *m_image_buffer;

};

void ImageMatrix::load(std::string filename) {
    m_image_buffer = stbi_load(filename.c_str(), &m_width, &m_height, &m_channels, 0);
    if (m_image_buffer == NULL) {
        std::cout << "Error loading image: " << filename << std::endl;
        exit(1);
    }
    std::cout << "(" << m_width << ", " << m_height << ") - "<< m_channels << std::endl;
};

void ImageMatrix::save(std::string filename, std::string image_type) {
    if (image_type == "png" || "PNG") {
        std::cout << "saving image" << std::endl;
        stbi_write_png(filename.c_str(), m_width, m_height, m_channels, m_image_buffer, m_width * m_channels);
    }
};

