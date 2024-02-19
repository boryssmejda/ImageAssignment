include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/AppCompileFlags.cmake)

set(APP_NAME ImageApp)

add_executable(${APP_NAME} main.cpp)
target_link_libraries(${APP_NAME}
    PRIVATE
        AppCompileFlags
        ImageLibrary
)
