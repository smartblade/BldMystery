set(TARGET Raster)

project(${TARGET})

file(GLOB SOURCES *.cpp)

add_library(${TARGET} SHARED ${SOURCES})

target_include_directories(${TARGET} PRIVATE ${BOD_COMMON_INCLUDE_DIR})
target_link_libraries(${TARGET} PRIVATE python15)
set_target_properties(
    ${TARGET} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${BOD_RUNTIME_DIR}
)
