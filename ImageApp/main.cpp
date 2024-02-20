#include "ImageLibrary/ImageConverter.hpp"

#include <cstdlib>
#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    if(argc != 3)
    {
        std::cout <<"Usage: " << "./" << argv[0]
            << " <input_filename> <output_filename>" << std::endl;
        return EXIT_FAILURE;
    }

    const std::string inputFilename{argv[1]};
    const std::string outputFilename{argv[2]};

    if (imageLibrary::initializeImageLibrary() != imageLibrary::Status::Success)
    {
        std::cout << "Could not initialize the ImageLibrary!\n";
        return EXIT_FAILURE;
    }

    imageLibrary::Image image;
    if (image.readImage(inputFilename) != imageLibrary::Status::Success)
    {
        std::cout << "Reading the image failed!" << std::endl;
        return EXIT_FAILURE;
    }

    const auto conversionStatus = image.convertImageToGrayscale();
    if (conversionStatus != imageLibrary::Status::Success)
    {
        std::cout << "Grayscale conversion failed!" << std::endl;
        return EXIT_FAILURE;
    }

    if (image.saveImage(outputFilename) != imageLibrary::Status::Success)
    {
        std::cout << "Saving image failed!" << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
