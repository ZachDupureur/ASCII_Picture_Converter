cmake_minimum_required(VERSION 3.22)
project(ASCII_Picture_Converter)

set(CMAKE_CXX_STANDARD 14)
find_package(ImageMagick REQUIRED COMPONENTS Magick++ MagickWand MagickCore)
include_directories(${ImageMagick_INCLUDE_DIRS})
link_directories(${ImageMagick_INCLUDE_DIRS})
add_executable(ASCII_Picture_Converter
        main.cpp header.h implementation.cpp)
