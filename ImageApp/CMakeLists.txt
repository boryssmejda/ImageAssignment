set(APP_NAME ImageApp)

add_executable(${APP_NAME} main.cpp)
target_link_libraries(${APP_NAME}
    PRIVATE
        CompileFlags
        ImageLibrary
)

# Install the executable
install(TARGETS ImageApp DESTINATION ${APP_NAME}/bin)

# Install the contents of the resource folder alongside the executable
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/resources
    DESTINATION ${APP_NAME}/bin)
