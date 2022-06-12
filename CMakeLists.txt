cmake_minimum_required(VERSION 3.22)
project(ASCII_Picture_Converter)

set(CMAKE_CXX_STANDARD 11)

add_executable(ASCII_Picture_Converter
        header.h
        implementation.cpp
        main.cpp)

find_package(ImageMagick REQUIRED COMPONENTS Magick++ MagickWand MagickCore)
link_directories(${ImageMagick_INCLUDE_DIRS})

add_definitions( -DMAGICKCORE_QUANTUM_DEPTH=16 )
add_definitions( -DMAGICKCORE_HDRI_ENABLE=0 )
include_directories(${ImageMagick_INCLUDE_DIRS})
target_link_directories(ASCII_Picture_Converter PUBLIC ${ImageMagick_LIBRARIES})
target_link_libraries(ASCII_Picture_Converter PUBLIC ${ImageMagick_LIBRARIES})
