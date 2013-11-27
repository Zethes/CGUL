cmake_minimum_required(VERSION 2.8.7)
cmake_policy(VERSION 2.8.7)
project(TCPServer CXX)

find_package(Jatta 0.1.0 REQUIRED)

include_directories(${Jatta_INCLUDE_DIRS})

add_executable(server server.cpp)
target_link_libraries(server ${Jatta_LIBRARIES})
jatta_bake_rpath(server "$ORIGIN")

add_executable(client client.cpp)
target_link_libraries(client ${Jatta_LIBRARIES})
jatta_bake_rpath(client "$ORIGIN")

install(TARGETS server DESTINATION .)
install(TARGETS client DESTINATION .)
install(FILES "${Jatta_MODULES}" DESTINATION .)
set(CPACK_PACKAGE_FILE_NAME "${PROJECT_NAME}")
if(WIN32)
    set(CPACK_GENERATOR "ZIP")
else()
    set(CPACK_GENERATOR "TGZ")
endif()
include(CPack)
