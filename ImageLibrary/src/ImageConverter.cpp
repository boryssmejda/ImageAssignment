#include "ImageLibrary/ImageConverter.hpp"

#include <opencv2/opencv.hpp>
#include <opencv2/core/utils/logger.hpp>

namespace imageLibrary
{
struct Image::ImageImpl
{
    cv::Mat image{};
};

Image::Image() : impl(std::make_unique<ImageImpl>())
{
}

Image::~Image() = default;

auto Image::readImage(const std::string& filename) -> Status
{
    impl->image = cv::imread(filename, cv::IMREAD_COLOR);
    return not impl->image.empty() ? Status::Success : Status::Failure;
}

auto Image::saveImage(const std::string& filename) -> Status
{
    const bool wasImageSuccessfullySaved = cv::imwrite(filename, impl->image);
    return wasImageSuccessfullySaved ? Status::Success : Status::Failure;
}

auto Image::convertImageToGrayscale() -> Status
{
    cv::cvtColor(impl->image, impl->image, cv::COLOR_BGR2GRAY, 1);
    return (impl->image.channels() == 1) ? Status::Success : Status::Failure;
}

// Library will be always initialized successfully. For this task, the function is
// necessary, only because of the OpenCV logs that would otherwise appear
// in the client's code. I do not think that they should appear in the client's code,
// as they would introduce confusion and mess.
auto imageLibrary::initializeImageLibrary() -> Status
{
    cv::utils::logging::setLogLevel(cv::utils::logging::LogLevel::LOG_LEVEL_SILENT);
    return imageLibrary::Status::Success;
}

} // namespace imageLibrary
