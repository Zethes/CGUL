cmake_minimum_required(VERSION 2.8.7)
cmake_policy(VERSION 2.8.7)
project(JSON CXX)

find_package(CGUL 0.1.1 REQUIRED)

message(STATUS "CGUL found")
message(STATUS "  Location: ${CGUL_DIR}")
message(STATUS "  Version : ${CGUL_VERSION}")
message(STATUS "  Static  : ${CGUL_STATIC}")

include_directories(${CGUL_INCLUDE_DIRS})
add_executable(json MACOSX_BUNDLE main.cpp)
target_link_libraries(json ${CGUL_LIBRARIES})
cgul_bake_rpath(json "$ORIGIN")
