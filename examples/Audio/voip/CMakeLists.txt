cmake_minimum_required(VERSION 2.8.7)
cmake_policy(VERSION 2.8.7)
project(VoIP CXX)

find_package(CGUL 0.1.0 REQUIRED)

include_directories(${CGUL_INCLUDE_DIRS})
add_executable(voip main.cpp)
target_link_libraries(voip ${CGUL_LIBRARIES})
cgul_bake_rpath(voip "$ORIGIN")
