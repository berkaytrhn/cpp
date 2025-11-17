#pragma once 
#include <media_parser.hpp>


class PPMParser : public MediaParser{
    public:
        cv::Mat parse(const std::string &path) override;
        ~PPMParser() override = default;  
        
        static std::unique_ptr<PPMParser> create_ppm_parser();
};  