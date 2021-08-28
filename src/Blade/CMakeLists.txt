set(TARGET Blade)

project(${TARGET})

file(
    GLOB SOURCES
    *.cpp
    ../AnalyticGeometry/*.cpp
    ../App/*.cpp
    ../App/Windows/*.cpp
    ../BWorld/*.cpp
    ../Control/*.cpp
    ../enemies/*.cpp
    ../Entities/*.cpp
    ../Math/*.cpp
    ../NetMod/*.cpp
    ../Person/*.cpp
    ../Sound/*.cpp
)
set(RESOURCES Blade.rc)

if (BLD_NATIVE)
    enable_language(ASM_MASM)
    list(APPEND SOURCES asmMain.asm)
endif()

add_executable(${TARGET} WIN32 ${SOURCES} ${RESOURCES})

if (BLD_NATIVE)
    # Generate debug information for asm files
    target_compile_options(
        ${TARGET} PRIVATE $<$<COMPILE_LANGUAGE:ASM_MASM>:/Zi>
    )
    target_include_directories(${TARGET} PRIVATE asm)
    target_link_libraries(${TARGET} PRIVATE ddraw Mss32 shw32 wsock32)
    # Struct member alignment
    target_compile_options(${TARGET} PRIVATE "/Zp4")
    target_compile_definitions(
        ${TARGET} PRIVATE WINDOWS_IGNORE_PACKING_MISMATCH
    )
    set(EXPORT_FUNCTIONS_FILE "${PROJECT_SOURCE_DIR}/asm/export_cmd.txt")
    target_link_options(${TARGET} PRIVATE "@${EXPORT_FUNCTIONS_FILE}")
else()
    target_compile_definitions(${TARGET} PRIVATE BLD_NATIVE)
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
    BInputc
    Console
    python15
    Raster
    winmm
)
set_target_properties(
    ${TARGET} PROPERTIES
    ENABLE_EXPORTS true
    RUNTIME_OUTPUT_DIRECTORY ${BOD_RUNTIME_DIR}
)
