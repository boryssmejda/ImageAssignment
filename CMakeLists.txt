cmake_minimum_required(VERSION 3.27)

project(ImageAssignment)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/CompileFlags.cmake)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/ImageLibrary)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/ImageApp)
