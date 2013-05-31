# Jatta - General Utility Library
# Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
# All rights reserved.
cmake_minimum_required(VERSION 2.8.7)
cmake_policy(VERSION 2.8.7)

# Setup cmake settings
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Do some weirdness if this is the first generation
if("${CMAKE_INSTALL_PREFIX}" STREQUAL "")
    set(FIRST ON)
endif()

# Version information
set(Jatta_MAJOR_VERSION 0)
set(Jatta_MINOR_VERSION 1)
set(Jatta_PATCH_VERSION 0)
set(Jatta_VERSION ${Jatta_MAJOR_VERSION}.${Jatta_MINOR_VERSION}.${Jatta_PATCH_VERSION})
project(Jatta-${Jatta_VERSION} CXX)

# Fix up the installation path
if(FIRST)
    string(FIND "${CMAKE_INSTALL_PREFIX}" "${PROJECT_NAME}" INDEX)
    if(INDEX EQUAL -1)
        set(INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME})
        get_property(CACHE_DOC CACHE "CMAKE_INSTALL_PREFIX" PROPERTY HELPSTRING) 
        get_property(CACHE_TYPE CACHE "CMAKE_INSTALL_PREFIX" PROPERTY TYPE) 
        unset(CMAKE_INSTALL_PREFIX CACHE)
        set(CMAKE_INSTALL_PREFIX ${INSTALL_PREFIX} CACHE ${CACHE_TYPE} "${CACHE_DOC}")
    endif()
endif()

# Determine system information
if(MINGW)
    set(SYSTEM_NAME mingw)
else()
    string(TOLOWER ${CMAKE_SYSTEM_NAME} SYSTEM_NAME)
endif()
math(EXPR SYSTEM_BITNESS "${CMAKE_SIZEOF_VOID_P} * 8")

# Set the dependecy directory to the default path
set(Jatta_DEPENDENCY_LIBRARY_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/deps-${SYSTEM_NAME}/lib${SYSTEM_BITNESS}" CACHE STRING "Directories to look for libraries.")
set(Jatta_DEPENDENCY_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/deps-${SYSTEM_NAME}/include" CACHE STRING "Directories to look for headers.")
set(DOXYGEN_ENABLE ON CACHE BOOL "Specifies whether or not to use Doxygen to generate documentation.")
set(DOXYGEN_WARNINGS OFF CACHE BOOL "Turns on Doxygen warnings during doc generation stage.")
set(CMAKE_REQUIRED_INCLUDES ${Jatta_DEPENDENCY_INCLUDE_DIRS})
set(CMAKE_REQUIRED_DEFINITIONS "-DGLEW_NO_GLU -DGLEW_STATIC -DHAVE_BOOLEAN")
if(MSVC)
    set(CMAKE_REQUIRED_DEFINITIONS "${CMAKE_REQUIRED_DEFINITIONS} -DMSVC")
endif()
set(CMAKE_REQUIRED_FLAGS ${CMAKE_REQUIRED_DEFINITIONS})

# Look for libraries
include(libraries/libraries.cmake)

# Compile the library
add_subdirectory(src)

# Add a build step for Doxygen
if(DOXYGEN_ENABLE)
    find_package(Doxygen)
    if(DOXYGEN_FOUND)
        set(DOXYGEN_WARNINGS "NO")
        set(DOXYGEN_QUIET "YES")
        if(Jatta_DOXYGEN_WARNINGS)
            set(DOXYGEN_WARNINGS "YES")
            set(DOXYGEN_QUIET "NO")
        endif()
        configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
        add_custom_target(doc ALL
            ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen" VERBATIM)
    endif()
else()
    set(DOXYGEN_FOUND OFF)
endif()