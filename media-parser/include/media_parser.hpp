#pragma once
#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <string>


class MediaParser {
    public:
        virtual cv::Mat parse(const std::string &path) = 0;
        virtual ~MediaParser() = default;
};