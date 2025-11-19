#include <ppm_parser.hpp>
#include <png_parser.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv){
    std::unique_ptr<MediaParser> my_parser = PNGParser::create_png_parser();
    
    if(argc < 2){
        printf("Please provide a Media File path.\n");
        return -1;
    }
    cv::Mat image = my_parser->parse(argv[1]);
    if(image.empty()){
        printf("Failed to parse the media file.\n");
        return -1;
    }
    cv::imshow("Parsed Image", image);
    cv::waitKey(0);
}