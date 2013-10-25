cmake_minimum_required(VERSION 2.8.7)
cmake_policy(VERSION 2.8.7)
project(Image CXX)

find_package(Jatta 0.1.1 REQUIRED)

message(STATUS "Jatta found")
message(STATUS "  Location: ${Jatta_DIR}")
message(STATUS "  Version : ${Jatta_VERSION}")
message(STATUS "  Static  : ${Jatta_STATIC}")

include_directories(${Jatta_INCLUDE_DIRS})
add_executable(image MACOSX_BUNDLE main.cpp)
target_link_libraries(image ${Jatta_LIBRARIES})
jatta_copy_modules(image ${CMAKE_CURRENT_BINARY_DIR})
jatta_bake_rpath(image "$ORIGIN")

add_custom_command(TARGET image POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/resources ${CMAKE_CURRENT_BINARY_DIR}/resources/)
