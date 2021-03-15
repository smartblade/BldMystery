set(TARGET NetBlade)

project(${TARGET})

file(GLOB SOURCES *.cpp)

add_library(${TARGET} SHARED ${SOURCES})

target_compile_definitions(${TARGET} PRIVATE _CRT_SECURE_NO_DEPRECATE)
target_include_directories(${TARGET} PRIVATE ${BOD_COMMON_INCLUDE_DIR})
target_link_libraries(${TARGET} PRIVATE bicrt dplayx)
set_target_properties(
    ${TARGET} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${BOD_RUNTIME_DIR}/NetBlade
)

add_subdirectory(dplayx)
