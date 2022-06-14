///     Created by Zach Dupureur on 09/06/2022
///     This program will take an image and compose an entirely new image using ASCII characters.
///     This was made as a bridge between my beginner/intermediate level and to make me solidly an intermediate programmer.
///     This program uses the Magick++ library from the open source software ImageMagick.

#include "header.h"

int main(int argC, char* argV[]) {
    try {
        InitializeMagick(*argV);
        Image image("ascii-pineapple.jpg");

        int columns = image.columns();
        int rows = image.rows();


        MagickCore::PixelPacket *pixels = image.getPixels(0, 0, columns, rows);

        int row = 0;
        int column = 0;
        Color color = pixels[columns * row + column];

        int curRed = 0;
        int curGreen = 0;
        int curBlue = 0;
        int count = 0;

        for (row = 0; row < rows; row++) {
            for (column = 0; column < columns; column++) {
                Color color = pixels[columns * row + column];
                curRed = pixels[columns * row + column].red;
                curGreen = pixels[columns * row + column].green;
                curBlue = pixels[columns * row + column].blue;
                std::cout << curRed << " " << curGreen << " " << curBlue << std::endl;
                image.syncPixels();
                count++;
            }
        }

        std::cout << "Current count: " << std::endl << std::endl << count;

    }

    catch (std::exception &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
}