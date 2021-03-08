set(TARGET python15)

project(${TARGET})

file(
    GLOB SOURCES
    Modules/*.c
    Objects/*.c
    Parser/*.c
    PC/*.c
    Python/*.c
)
set(RESOURCES PC/python_nt.rc)

add_library(${TARGET} SHARED ${SOURCES} ${RESOURCES})

target_compile_definitions(
    ${TARGET} PRIVATE
    USE_DL_EXPORT
    _CRT_NONSTDC_NO_DEPRECATE
    _CRT_SECURE_NO_DEPRECATE
)
target_include_directories(
    ${TARGET} PRIVATE
    ${PROJECT_SOURCE_DIR}/Include
    ${PROJECT_SOURCE_DIR}/Python
)
target_link_libraries(${TARGET} PRIVATE winmm wsock32)
set_target_properties(
    ${TARGET} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${BOD_RUNTIME_DIR}
)
