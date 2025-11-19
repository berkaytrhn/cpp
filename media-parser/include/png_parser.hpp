#pragma once
#include <media_parser.hpp>

class PNGParser : public MediaParser {
    public:
        cv::Mat parse(const std::string &path) override;
        int read_uint32_be(std::ifstream &file_stream);
        ~PNGParser() override = default;

        static std::unique_ptr<PNGParser> create_png_parser();
};