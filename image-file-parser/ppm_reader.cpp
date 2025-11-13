#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
    string tempText;

    string format;
    int width, height, colorDepth;

    // read given ppm file
    ifstream MyFile(argv[1], ios::binary);
    // First Line
    getline(MyFile, tempText);

    if (tempText != "P6")
    {
        cout << "Invalid PPM P6 file." << endl;
        return -1;
    }
    cout << "Valid PPM P6 file." << endl;

    // dimensions
    getline(MyFile, tempText);

    stringstream stream(tempText);
    stream >> width >> height;

    // Color Depth
    getline(MyFile, tempText);
    colorDepth = stoi(tempText);

    cout << "Image Format:" << format << endl;
    cout << "Width: " << width << ", Height: " << height << ", Color Depth: " << colorDepth << endl;

    // 8 bit unsigned int, 3 channels(Order: BGR)
    Mat image(height, width, CV_8UC3);
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
        // because char 8 bits, using it for efficiency and precision
        unsigned char r, g, b;
        MyFile.read(reinterpret_cast<char*>(&r), 1);
        MyFile.read(reinterpret_cast<char*>(&g), 1);
        MyFile.read(reinterpret_cast<char*>(&b), 1);

        image.at<Vec3b>(i, j) = Vec3b(b, g, r); // OpenCV uses BGR order
        }
    }

    imshow("PPM Decoded Image", image);
    waitKey(0);
    return 0;
}