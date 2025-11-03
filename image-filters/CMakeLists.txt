cmake_minimum_required(VERSION 4.1)
project(ImageFiltersApp)

set(CMAKE_CXX_STANDARD 17)

# Set OpenCV location
set(OpenCV_DIR "../libs/OpenCV-MinGW-Build-OpenCV-4.5.5-x64")

find_package(OpenCV REQUIRED)

add_executable(main main.cpp)

target_include_directories(main PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(main ${OpenCV_LIBS})