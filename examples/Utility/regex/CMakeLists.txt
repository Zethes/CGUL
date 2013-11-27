cmake_minimum_required(VERSION 2.8.7)
cmake_policy(VERSION 2.8.7)
project(Regex CXX)

find_package(Jatta 0.1 REQUIRED)

include_directories(${Jatta_INCLUDE_DIRS})
add_executable(regex MACOSX_BUNDLE main.cpp)
target_link_libraries(regex ${Jatta_LIBRARIES})
jatta_bake_rpath(regex "$ORIGIN")
