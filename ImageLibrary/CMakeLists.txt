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
        CompileFlags
        OpenCvWrapper
)

set_target_properties(${LIBRARY_NAME} PROPERTIES PUBLIC_HEADER ${HEADERS})

# I decided to add installation commands to build the nice package out of the library.
# I must admit I am not certain that this would work
# if I tried to use find_package(ImageLibrary CONFIG REQUIRED) in other project.
# I did not have time to dig deeper into this. I would be glad to discuss this though.
# I still have the impression that the client would have to call find_package(OpenCV REQUIRED),
# even though the ImageLibrary does not expose this dependency explicitly.

install(TARGETS ${LIBRARY_NAME}
    EXPORT ${LIBRARY_NAME}Targets
    DESTINATION ${LIBRARY_NAME}/lib/
    PUBLIC_HEADER DESTINATION ${LIBRARY_NAME}/include/${LIBRARY_NAME}
)

install(EXPORT ${LIBRARY_NAME}Targets
        DESTINATION ${LIBRARY_NAME}/cmake/
        FILE ${LIBRARY_NAME}Config.cmake
        NAMESPACE ${LIBRARY_NAME}::
)

# Add CompileFlags and OpencvWrapper to the export set
install(TARGETS CompileFlags OpenCvWrapper
    EXPORT ImageLibraryTargets
    DESTINATION ${LIBRARY_NAME}/lib/
)

# Generate and install the export configuration file
install(EXPORT ImageLibraryTargets
    FILE ImageLibraryTargets.cmake
    NAMESPACE ${LIBRARY_NAME}::
    DESTINATION ${LIBRARY_NAME}/cmake/
)
