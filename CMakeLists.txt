cmake_minimum_required(VERSION 3.16)

project(rational_nums LANGUAGES CXX C)

# control where the static and shared libraries are built so that on windows
# we don't need to tinker with the path to run the executable
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

option(BUILD_EXAMPLE "Build example applications that showcase the library" ON)

add_subdirectory(src)

if (BUILD_EXAMPLE)
	add_subdirectory(example)
endif ()