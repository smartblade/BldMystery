set(TARGET rOpenGL)

project(${TARGET})

file(GLOB SOURCES *.cpp)

if (BLD_NATIVE)
    enable_language(ASM_MASM)
    list(APPEND SOURCES asmMain.asm)
endif()
set(RESOURCES Resources/rOpenGL.rc)

add_library(${TARGET} SHARED ${SOURCES} ${RESOURCES})

if (BLD_NATIVE)
    # Generate debug information for asm files
    target_compile_options(
        ${TARGET} PRIVATE $<$<COMPILE_LANGUAGE:ASM_MASM>:/Zi>
    )
    target_include_directories(${TARGET} PRIVATE asm)
    # Struct member alignment
    target_compile_options(${TARGET} PRIVATE "/Zp4")
    target_compile_definitions(
        ${TARGET} PRIVATE WINDOWS_IGNORE_PACKING_MISMATCH BLD_NATIVE
    )
    set(EXPORT_FUNCTIONS_FILE "${PROJECT_SOURCE_DIR}/asm/export_cmd.txt")
    target_link_options(${TARGET} PRIVATE "@${EXPORT_FUNCTIONS_FILE}")
endif()

target_compile_definitions(
    ${TARGET} PRIVATE
    _CRT_NONSTDC_NO_DEPRECATE
    _CRT_SECURE_NO_DEPRECATE
)
target_include_directories(${TARGET} PRIVATE ${BOD_COMMON_INCLUDE_DIR})
target_link_directories(${TARGET} PRIVATE ${BOD_EXTERNAL_LIB_DIR})
target_link_libraries(
    ${TARGET} PRIVATE
    BBLibc
    Raster
    bicrt
    OpenGL32
    Glu32
    ComCtl32
)
set_target_properties(
    ${TARGET} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${BOD_RUNTIME_DIR}/Raster
)
