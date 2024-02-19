set(MODULE_NAME AppCompileFlags)

add_library(${MODULE_NAME} INTERFACE)

target_compile_options(${MODULE_NAME} INTERFACE
    -Wall
    -Wextra
    -Werror
)
