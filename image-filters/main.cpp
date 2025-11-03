#include <iostream>
#include <opencv2/opencv.hpp>
#include <filesystem>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {

    filesystem::path path = filesystem::current_path();

    cout << "Current Path: " << path << endl;

    cout << "Filters Application" << endl;
    Mat image = imread(argv[1]);
    Mat rotated;
    rotate(image, rotated, ROTATE_90_CLOCKWISE);
    imshow("Rotated Image", rotated);
    waitKey(0);
    return 0;
}