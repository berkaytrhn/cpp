#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;

int main(int argc, char** argv)
{
    string tempText;

    string format;
    int width, height, colorDepth;

    // read given ppm file
    ifstream MyFile(argv[1]);
    // First Line 
    getline(MyFile, tempText);

    if(tempText != "P6"){
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

    // Read image data as bytes
    return 0;
}
