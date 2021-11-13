set(TARGET AnalyticGeometry)

project(${TARGET})

file(GLOB SOURCES *.cpp)

add_library(${TARGET} STATIC ${SOURCES})

if (BLD_NATIVE)
    # Struct member alignment
    target_compile_options(${TARGET} PRIVATE "/Zp4")
    target_compile_definitions(
        ${TARGET} PRIVATE WINDOWS_IGNORE_PACKING_MISMATCH BLD_NATIVE
    )
endif()

target_include_directories(${TARGET} PRIVATE ${BOD_COMMON_INCLUDE_DIR})
