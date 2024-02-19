include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/LibraryCompileFlags.cmake)

find_package(OpenCV REQUIRED)

add_library(OpenCvWrapper INTERFACE)
target_include_directories(OpenCvWrapper INTERFACE
    $<BUILD_INTERFACE:${OpenCV_INCLUDE_DIRS}>
)
target_link_libraries(OpenCvWrapper INTERFACE
    ${OpenCV_LIBS}
)

set(LIBRARY_NAME ImageLibrary)

set(HEADERS
    include/ImageLibrary/ImageConverter.hpp
)

set(SOURCES
    src/ImageConverter.cpp
)

add_library(${LIBRARY_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${LIBRARY_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
    $<INSTALL_INTERFACE:include/>
)

target_link_libraries(${LIBRARY_NAME}
    PRIVATE
        LibraryCompileFlags
    PUBLIC
        OpenCvWrapper
)
