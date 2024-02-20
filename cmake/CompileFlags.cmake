set(MODULE_NAME CompileFlags)

add_library(${MODULE_NAME} INTERFACE)

target_compile_options(${MODULE_NAME} INTERFACE
    /W4
    /WX
)
