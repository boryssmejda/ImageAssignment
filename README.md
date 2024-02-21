# Image Assignment

## Toolset

The project has been developed on Windows.
Following tools were used:
- CMake, version used 3.28.3
- MSVC, version used 19.38


## Building the project

Important Note: I used prebuilt binaries for OpenCV that I downloaded from Github. I used [OpenCV 4.9.0](https://github.com/opencv/opencv/releases/download/4.9.0/opencv-4.9.0-windows.exe).
I installed the library according to the [`Installation in Windows`](https://docs.opencv.org/4.x/d3/d52/tutorial_windows_install.html).

I have tried Conan 2 for installation of opencv. My idea was that the package manager would gladly install OpenCV for me and would make life easier to build the project on a different machine. However, much to my surprise, the conan package for OpenCV 4.8.1 cannot be downloaded and the error message is:

```
ERROR: Version conflict: Conflict between libpng/1.6.42 and libpng/1.6.40 in the graph.
Conflict originates from freetype/2.13.2
```

I tried using version 4.9 or any other OpenCV 4 version, but the conan center seemed not to have these packages.
Therefore adding package manager support to the project would definitely help and would be top on the improvement areas for the project.

```sh
mkdir build
cd build
cmake ../ -DCMAKE_PREFIX_PATH=<path_to_installed_opencv>
cmake --build . --config Debug
cmake --build . --config Release
./ImageApp/Release/ImageApp.exe <input_picture_path> <output_picture_path>
./ImageApp/Debug/ImageApp.exe <input_picture_path> <output_picture_path>
```

I installed OpenCV into deps/ folder inside my ImageAssignment repository to have an easy access to the library. I also added bin/ directory to the environment variables as suggest on their website to run opencv application easily without issues of lacking .dll files.

TODO JUTRO:
vcpkg support
napisać prostego UT.
dodaj zdjecie do testowania --> Done


Further Development Areas:
1) Unit tests with memory and address sanitizer checking, valgrind support.
2) Code Coverage
3) Static Analysis - Clang Tidy
4) Running CI/CD
5) For the library - ABI Compliance Checker - if the library can be built and used as the DLL.
6) Package Manager like Conan
7) Library could be ported to other platforms and compilers.
8) Documentation in the code like Doxygen for example.
