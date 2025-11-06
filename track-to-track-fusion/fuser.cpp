#include <iostream>
#include <filesystem>
#include <Eigen>

using namespace Eigen;

int main(int argc, char** argv) {

    Vector2d s1(100, 50);
    Vector2d s2 = Vector2d(102, 49);

    Matrix2d p1, p2;
    
    p1 <<
        4, 0, 
        0, 9;
    p2 <<
        9, 0, 
        0, 4;
    
    Matrix2d Pf = (p1.inverse() + p2.inverse()).inverse();
    Vector2d xf = Pf * (p1.inverse() * s1 + p2.inverse() * s2);

    std::cout << "fused pos:\n" << xf << "\n";
    std::cout << "fused covariance:\n" << Pf << std::endl;
    return 0;
}