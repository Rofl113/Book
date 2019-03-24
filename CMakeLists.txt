cmake_minimum_required(VERSION 2.8.12)

add_definitions(-Werror)
add_definitions(-Wextra -Wno-unused-parameter)

# Конфигурация сборки:
set(BUILD_CONFIG "MAIN" CACHE STRING "Select build configuration")
set_property(CACHE BUILD_CONFIG PROPERTY STRINGS "MAIN")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/release/${BUILD_CONFIG})

# JSON
# TODO: move to sub/CMakeLists.txt
set(JSON_INCLUDE ${PROJECT_SOURCE_DIR}/sub/json/single_include)

add_subdirectory(backend)
add_subdirectory(frontend)
add_subdirectory(sub)
