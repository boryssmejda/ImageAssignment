#pragma once

#include <memory>
#include <string>

namespace imageLibrary
{

enum class Status
{
    Success,
    Failure,
};

auto initializeImageLibrary() -> Status;

class Image
{
public:
    Image();
    ~Image();
    auto readImage(const std::string& filename) -> Status;
    auto saveImage(const std::string& filename) -> Status;
    auto convertImageToGrayscale() -> Status;

private:
    struct ImageImpl;
    std::unique_ptr<ImageImpl> impl;
};
} // namespace imageLibrary
