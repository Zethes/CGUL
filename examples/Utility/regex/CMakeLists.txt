cmake_minimum_required(VERSION 2.8.7)
cmake_policy(VERSION 2.8.7)
project(Regex CXX)

find_package(CGUL 0.1 REQUIRED)

include_directories(${CGUL_INCLUDE_DIRS})
add_executable(regex MACOSX_BUNDLE main.cpp)
target_link_libraries(regex ${CGUL_LIBRARIES})
cgul_bake_rpath(regex "$ORIGIN")
