cmake_minimum_required(VERSION 4.1)
project(MediaParser)

set(CMAKE_CXX_STANDARD 17)

# Set OpenCV location
set(OpenCV_DIR "../libs/OpenCV-MinGW-Build-OpenCV-4.5.5-x64")
set(SOURCES
    src/main.cpp
    src/ppm_parser.cpp
)

find_package(OpenCV REQUIRED)
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${OpenCV_INCLUDE_DIRS})
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})