cmake_minimum_required(VERSION 2.8.7)
cmake_policy(VERSION 2.8.7)
project(HTTPRequest CXX)

find_package(Jatta 0.1.0 REQUIRED)

include_directories(${Jatta_INCLUDE_DIRS})

add_executable(http main.cpp)
target_link_libraries(http ${Jatta_LIBRARIES})
jatta_bake_rpath(http "$ORIGIN")

set(CPACK_PACKAGE_FILE_NAME "${PROJECT_NAME}")
if(WIN32)
    set(CPACK_GENERATOR "ZIP")
else()
    set(CPACK_GENERATOR "TGZ")
endif()
include(CPack)
