cmake_minimum_required(VERSION 3.27)

project(ImageAssignment)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Library and App would have separate compile flags,
# if they were developed independently. Since in this project,
# both are developed in the same repo, there is one set of flags
# used in both targets. This prevents code duplication
# across the project.
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/CompileFlags.cmake)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/ImageLibrary)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/ImageApp)
