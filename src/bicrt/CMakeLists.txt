set(TARGET bicrt)

project(${TARGET})

add_library(${TARGET} INTERFACE)

if (BLD_NATIVE)
    target_compile_definitions(
        ${TARGET} INTERFACE
        _NO_CRT_STDIO_INLINE
        _USE_32BIT_TIME_T
        USE_BICRT
    )
    target_link_libraries(${TARGET} INTERFACE ${BOD_EXTERNAL_LIB_DIR}/bicrt.lib)
endif()
