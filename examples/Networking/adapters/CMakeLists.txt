cmake_minimum_required(VERSION 2.8.7)
cmake_policy(VERSION 2.8.7)
project(Adapters CXX)

find_package(Jatta 0.1.0 REQUIRED)

include_directories(${Jatta_INCLUDE_DIRS})
add_executable(adapters MACOSX_BUNDLE main.cpp)
target_link_libraries(adapters ${Jatta_LIBRARIES})
jatta_copy_modules(adapters ${CMAKE_CURRENT_BINARY_DIR})
jatta_bake_rpath(adapters "$ORIGIN")
