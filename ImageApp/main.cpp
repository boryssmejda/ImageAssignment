#include "ImageLibrary/ImageConverter.hpp"

#include <cstdlib>
#include <iostream>
#include <string>

int mainImageGrayScaleConversion(int argc, char** argv)
{
    if(argc != 3)
    {
        std::cerr <<"Usage: " << "./" << argv[0]
            << " <input_filename> <output_filename>" << std::endl;
        return EXIT_FAILURE;
    }

    const std::string inputFilename{argv[1]};
    const std::string outputFilename{argv[2]};

    if (imageLibrary::initializeImageLibrary() != imageLibrary::Status::Success)
    {
        std::cerr << "Could not initialize the ImageLibrary!\n";
        return EXIT_FAILURE;
    }

    imageLibrary::Image image;
    if (image.readImage(inputFilename) != imageLibrary::Status::Success)
    {
        std::cerr << "Reading the image failed!" << std::endl;
        return EXIT_FAILURE;
    }

    const auto conversionStatus = image.convertImageToGrayscale();
    if (conversionStatus != imageLibrary::Status::Success)
    {
        std::cerr << "Grayscale conversion failed!" << std::endl;
        return EXIT_FAILURE;
    }

    if (image.saveImage(outputFilename) != imageLibrary::Status::Success)
    {
        std::cerr << "Saving image failed!" << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int main(int argc, char** argv)
{
    return mainImageGrayScaleConversion(argc, argv);
}
