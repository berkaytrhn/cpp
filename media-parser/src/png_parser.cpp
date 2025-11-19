#include <png_parser.hpp>
#include <fstream>

cv::Mat PNGParser::parse(const std::string &path)
{
    std::ifstream file_stream(path, std::ios::binary);
    if (!file_stream)
        return {};

    unsigned char header_bytes[8];
    file_stream.read(reinterpret_cast<char *>(header_bytes), 8);
    /*
    for(int i = 0; i < 8; i++) {
        std::cout << "PNG Header byte " << i << ": " << std::hex << static_cast<int>(header_bytes[i]) << std::endl;
    }
    */
    // 89 50 4E 47 0D 0A 1A 0A
    unsigned char png_signature[] = {137, 80, 78, 71, 13, 10, 26, 10};
    int var = memcmp(header_bytes, png_signature, 8);
    if (var != 0)
    {
        std::cout << "Not a valid PNG file." << std::endl;
    }
    /*
    unsigned char length_bytes[4];
    file_stream.read(reinterpret_cast<char*>(length_bytes), 4);
    for(int i = 0; i < 4; i++) {
        std::cout << "PNG Length bytes " << i << ": " << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(length_bytes[i]) << std::endl;
    }
    */
    // int int_cast = (length_bytes[0] << 24) | (length_bytes[1] << 16) | (length_bytes[2] << 8) | length_bytes[3];

    // pc little endian but png big endian, so returns reversed order
    /*
    int length;
    file_stream.read(reinterpret_cast<char*>(&length), 4);
    std::cout << "PNG Length: " << std::dec << length << std::endl;
    */
    int length = read_uint32_be(file_stream);
    std::cout << "PNG Length: " << std::dec << length << std::endl;

    int chunk_type = read_uint32_be(file_stream);
    std::cout << "Chunk Type : " << std::dec << chunk_type << std::endl;


    // TBC

    return cv::Mat{};
}

std::unique_ptr<PNGParser> PNGParser::create_png_parser()
{
    return std::make_unique<PNGParser>();
}

int PNGParser::read_uint32_be(std::ifstream &file_stream)
{
    // Read in big endian byte order
    // Local cpu uses little endian byte order, direct cast to integer makes value as (2^7-value)
    unsigned char length_bytes[4];
    file_stream.read(reinterpret_cast<char *>(length_bytes), 4);
    int length = (length_bytes[0] << 24) | (length_bytes[1] << 16) | (length_bytes[2] << 8) | length_bytes[3];
    return length;
}