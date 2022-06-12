///     Created by Zach Dupureur on 09/06/2022
///     This program will take an image and compose an entirely new image using ASCII characters.
///     This was made as a bridge between my beginner/intermediate level and to make me solidly an intermediate programmer.
///     This program uses the Magick++ library from the open source software ImageMagick.

#include "header.h"

int main(int argC, char* argV[]) {
try {
    InitializeMagick(*argV);
    std::cout << "Hello!" << std::endl;

    Image image("640x550", "white");
    std::cout << image.totalColors() << std::endl << image.rows() << std::endl << image.columns();
}

catch (std::exception &e) {
    std::cerr << "Caught exception: " << e.what() << std::endl;
}

}
