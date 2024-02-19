set(MODULE_NAME ProjectCompileFlags)

add_library(${MODULE_NAME} INTERFACE)

target_compile_options(${MODULE_NAME} INTERFACE
    -Wall
    -Wextra
    -Wshadow
    -Werror
    -pedantic
)

