cmake_minimum_required(VERSION 2.8.7)
cmake_policy(VERSION 2.8.7)
project(DNS CXX)

find_package(CGUL 0.1.8 REQUIRED)

include_directories(${CGUL_INCLUDE_DIRS})
add_executable(dns MACOSX_BUNDLE main.cpp)
target_link_libraries(dns ${CGUL_LIBRARIES})
cgul_bake_rpath(dns "$ORIGIN")

if(NOT CGUL_STATIC)
    get_target_property(__CGUL_PATH CGUL IMPORTED_LOCATION)
    get_filename_component(__CGUL_NAME ${__CGUL_PATH} NAME)
    add_custom_target(${__CGUL_NAME} ALL COMMAND cmake -E copy "${__CGUL_PATH}" "${CMAKE_CURRENT_BINARY_DIR}/" VERBATIM)
endif()
