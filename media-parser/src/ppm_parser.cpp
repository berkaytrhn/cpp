#include <ppm_parser.hpp>
#include <fstream>

cv::Mat PPMParser::parse(const std::string &path) {
    std::ifstream file_stream(path, std::ios::binary);
    if (!file_stream)
        return {};
    std::string token;
    file_stream >> token;
    if (token != "P6")
        return {};
    int width, height, color_ceiling;
    file_stream >> width >> height;
    // new line
    //file_stream.get();
    file_stream >> std::ws; // white space
    file_stream >> color_ceiling;
    // new line
    // file_stream.get();
    file_stream >> std::ws; // white space

    // Read pixel data
    cv::Mat image(height, width, CV_8UC3);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // because char 8 bits, using it for efficiency and precision
            unsigned char r, g, b;
            file_stream.read(reinterpret_cast<char *>(&r), 1);
            file_stream.read(reinterpret_cast<char *>(&g), 1);
            file_stream.read(reinterpret_cast<char *>(&b), 1);

            image.at<cv::Vec3b>(i, j) = cv::Vec3b(b, g, r); // OpenCV uses BGR order
        }
    }

    /*
    file_stream.read(reinterpret_cast<char*>(image.data), width * height * 3);
    cv::cvtColor(image, image, cv::COLOR_RGB2BGR);
    */
    return image;
}

std::unique_ptr<PPMParser> PPMParser::create_ppm_parser() {
    return std::make_unique<PPMParser>();
}