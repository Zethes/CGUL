cmake_minimum_required(VERSION 2.8.7)
cmake_policy(VERSION 2.8.7)
project(JSON CXX)

find_package(Jatta 0.1.1 REQUIRED)

message(STATUS "Jatta found")
message(STATUS "  Location: ${Jatta_DIR}")
message(STATUS "  Version : ${Jatta_VERSION}")
message(STATUS "  Static  : ${Jatta_STATIC}")

include_directories(${Jatta_INCLUDE_DIRS})
add_executable(json MACOSX_BUNDLE main.cpp)
target_link_libraries(json ${Jatta_LIBRARIES})
jatta_bake_rpath(json "$ORIGIN")
