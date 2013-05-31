cmake_minimum_required(VERSION 2.8.7)
cmake_policy(VERSION 2.8.7)
project(Wave CXX)

find_package(Jatta 0.1.0 REQUIRED)

include_directories(${Jatta_INCLUDE_DIRS})
add_executable(wave main.cpp)
target_link_libraries(wave ${Jatta_LIBRARIES})
jatta_copy_modules(wave ${CMAKE_CURRENT_BINARY_DIR})