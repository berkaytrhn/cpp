cmake_minimum_required(VERSION 4.1)
project(PPMReader)

set(CMAKE_CXX_STANDARD 17)

# Set OpenCV location
set(OpenCV_DIR "../libs/OpenCV-MinGW-Build-OpenCV-4.5.5-x64")

find_package(OpenCV REQUIRED)

add_executable(ppm_reader ppm_reader.cpp)

target_include_directories(ppm_reader PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(ppm_reader ${OpenCV_LIBS})