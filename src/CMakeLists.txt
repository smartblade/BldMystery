cmake_minimum_required(VERSION 3.0)

project(BOD)

if (BLD_NATIVE)
    # Disable exceptions
    string(REGEX REPLACE /EHsc /EHs-c- CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
    # Disable RTTI
    string(REGEX REPLACE /GR /GR- CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
    # Set optimisation level
    string(
        REGEX REPLACE /O2 /Od
        CMAKE_CXX_FLAGS_RELWITHDEBINFO ${CMAKE_CXX_FLAGS_RELWITHDEBINFO}
    )
    link_libraries(${PROJECT_SOURCE_DIR}/../lib/VC/bicrt.lib)
    add_compile_definitions(_NO_CRT_STDIO_INLINE _USE_32BIT_TIME_T)
endif()
if (MSVC)
    # Enable asserts
    string(
        REGEX REPLACE "/DNDEBUG" ""
        CMAKE_CXX_FLAGS_RELWITHDEBINFO ${CMAKE_CXX_FLAGS_RELWITHDEBINFO}
    )
endif()

list(APPEND BOD_COMMON_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")
list(APPEND BOD_COMMON_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/Blade")
set(PYTHON_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/Python-1.5.2/Include")

set(BOD_EXTERNAL_LIB_DIR "${PROJECT_SOURCE_DIR}/../lib/VC")

set(BOD_RUNTIME_DIR "${PROJECT_SOURCE_DIR}/../install/bin")

add_subdirectory(Blade)
add_subdirectory(BladeExt)
add_subdirectory(netgame)
add_subdirectory(Python-1.5.2)
add_subdirectory(Raster)
