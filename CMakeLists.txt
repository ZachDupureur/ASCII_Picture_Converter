cmake_minimum_required(VERSION 3.22)
project(ASCII_Picture_Converter)

set(CMAKE_CXX_STANDARD 11)

add_executable(ASCII_Picture_Converter
        header.h
        implementation.cpp
        main.cpp)

find_package(ImageMagick REQUIRED COMPONENTS Magick++ MagickWand MagickCore)
link_directories(${ImageMagick_INCLUDE_DIRS})

add_definitions( -DMAGICKCORE_QUANTUM_DEPTH=8 )
add_definitions( -DMAGICKCORE_HDRI_ENABLE=0 )
include_directories(${ImageMagick_INCLUDE_DIRS} Images)
target_link_directories(ASCII_Picture_Converter PUBLIC ${ImageMagick_LIBRARIES})
target_link_libraries(ASCII_Picture_Converter PUBLIC ${ImageMagick_LIBRARIES})
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Images/ascii-pineapple.jpg
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)