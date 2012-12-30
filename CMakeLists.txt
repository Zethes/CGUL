cmake_minimum_required(VERSION 2.6)

project(Jatta)

set(CMAKE_COLOR_MAKEFILE off)

# The version number.
set(JATTA_VERSION_MAJOR 0)
set(JATTA_VERSION_MINOR 2)

set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS}")

SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

add_subdirectory(src)

#file(COPY src/*.h DESTINATION ${CMAKE_CURRENT_LIST_DIR}/include)