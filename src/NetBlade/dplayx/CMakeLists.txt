set(TARGET dplayx)

project(${TARGET})

add_library(${TARGET} INTERFACE)

target_include_directories(${TARGET} INTERFACE ${PROJECT_SOURCE_DIR})
target_link_libraries(
    ${TARGET} INTERFACE
    ${PROJECT_SOURCE_DIR}/dplayx.lib
    ${PROJECT_SOURCE_DIR}/dxguid.lib
)

