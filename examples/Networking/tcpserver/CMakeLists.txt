cmake_minimum_required(VERSION 2.8.7)
cmake_policy(VERSION 2.8.7)
project(TCPServer CXX)

find_package(CGUL 0.1.0 REQUIRED)

include_directories(${CGUL_INCLUDE_DIRS})

add_executable(server server.cpp)
target_link_libraries(server ${CGUL_LIBRARIES})
cgul_bake_rpath(server "$ORIGIN")

add_executable(client client.cpp)
target_link_libraries(client ${CGUL_LIBRARIES})
cgul_bake_rpath(client "$ORIGIN")
