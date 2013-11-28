cmake_minimum_required(VERSION 2.8.7)
cmake_policy(VERSION 2.8.7)
project(3DWorld CXX)

find_package(CGUL 0.1.1 REQUIRED)

message(STATUS "CGUL found")
message(STATUS "  Location: ${CGUL_DIR}")
message(STATUS "  Version : ${CGUL_VERSION}")
message(STATUS "  Static  : ${CGUL_STATIC}")

message(STATUS "${CGUL_INCLUDE_DIRS}")
include_directories(${CGUL_INCLUDE_DIRS})
add_executable(3dworld MACOSX_BUNDLE main.cpp)
target_link_libraries(3dworld ${CGUL_LIBRARIES})
cgul_bake_rpath(3dworld "$ORIGIN")

add_custom_command(TARGET 3dworld POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/resources ${CMAKE_CURRENT_BINARY_DIR}/resources/)
