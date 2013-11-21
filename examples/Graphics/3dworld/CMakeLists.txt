cmake_minimum_required(VERSION 2.8.7)
cmake_policy(VERSION 2.8.7)
project(3DWorld CXX)

find_package(Jatta 0.1.1 REQUIRED)

message(STATUS "Jatta found")
message(STATUS "  Location: ${Jatta_DIR}")
message(STATUS "  Version : ${Jatta_VERSION}")
message(STATUS "  Static  : ${Jatta_STATIC}")

include_directories(${Jatta_INCLUDE_DIRS})
add_executable(3dworld MACOSX_BUNDLE main.cpp)
target_link_libraries(3dworld ${Jatta_LIBRARIES})
jatta_bake_rpath(3dworld "$ORIGIN")

add_custom_command(TARGET 3dworld POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/resources ${CMAKE_CURRENT_BINARY_DIR}/resources/)
