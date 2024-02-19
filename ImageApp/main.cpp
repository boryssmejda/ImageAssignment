#include "ImageLibrary/ImageConverter.hpp"

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        std::cout <<" Usage: " << argv[0] << " ImageToLoadAndDisplay" << std::endl;
        return -1;
    }
    cv::Mat image;
    image = imread(argv[1], cv::IMREAD_COLOR); // Read the file

    if(image.empty())
    {
        std::cout << "Could not open or find the image" << std::endl ;
        return -1;
    }

    cv::namedWindow( "Display window", cv::WINDOW_AUTOSIZE ); // Create a window for display.
    cv::imshow( "Display window", image ); // Show our image inside it.
    cv::waitKey(0); // Wait for a keystroke in the window
    return 0;
}
