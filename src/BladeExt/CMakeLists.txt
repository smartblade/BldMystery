set(TARGET Bladex)

project(${TARGET})

file(GLOB SOURCES *.cpp)

add_library(${TARGET} SHARED ${SOURCES})

target_compile_definitions(
    ${TARGET} PRIVATE
    _CRT_NONSTDC_NO_DEPRECATE
    _CRT_SECURE_NO_DEPRECATE
)
target_include_directories(${TARGET} PRIVATE ${BOD_COMMON_INCLUDE_DIR})
target_link_libraries(${TARGET} PRIVATE Blade python15)
set_target_properties(
    ${TARGET} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${BOD_RUNTIME_DIR}
)
