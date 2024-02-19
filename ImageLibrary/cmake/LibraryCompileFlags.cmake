set(MODULE_NAME LibraryCompileFlags)

add_library(${MODULE_NAME} INTERFACE)

target_compile_options(${MODULE_NAME} INTERFACE
    -Wall
    -Wextra
    -Wshadow
    -Werror
    -pedantic
)
