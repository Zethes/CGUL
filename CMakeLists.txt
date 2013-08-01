# Jatta - General Utility Library
# Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
# All rights reserved.
cmake_minimum_required(VERSION 2.8.7)
cmake_policy(VERSION 2.8.7)

# Setup cmake settings
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_DEBUG_POSTFIX "d")
message(STATUS "Configuring...")

# Allow the installation to go under a different name
set(Jatta_OUTPUT_NAME "Jatta" CACHE STRING "The name to install Jatta under.")

# Do some weirdness if this is the first generation
if("${CMAKE_INSTALL_PREFIX}" STREQUAL "")
    set(FIRST ON)
else()
    set(FIRST OFF)
endif()

# Version information
set(Jatta_MAJOR_VERSION 0)
set(Jatta_MINOR_VERSION 1)
set(Jatta_PATCH_VERSION 1)
set(Jatta_VERSION ${Jatta_MAJOR_VERSION}.${Jatta_MINOR_VERSION}.${Jatta_PATCH_VERSION})
project(${Jatta_OUTPUT_NAME} CXX)

# Determine compiler
include(resources/Compiler.cmake)

# Determine system information
if(MINGW)
    set(SYSTEM_NAME mingw)
    set(SYSTEM_NAME_UPPER MinGW)
else()
    string(TOLOWER ${CMAKE_SYSTEM_NAME} SYSTEM_NAME)
    set(SYSTEM_NAME_UPPER ${CMAKE_SYSTEM_NAME})
endif()
math(EXPR SYSTEM_BITNESS "${CMAKE_SIZEOF_VOID_P} * 8")

# Check if we should pretend this build is 32bit
set(Jatta_PRETEND_BITNESS ${SYSTEM_BITNESS} CACHE STRING "The bitness that Jatta should pretend to be set at, initially set to the actual system bitness.")
mark_as_advanced(Jatta_PRETEND_BITNESS)
set(SYSTEM_BITNESS ${Jatta_PRETEND_BITNESS})

# Determine lib directory name
if(${SYSTEM_BITNESS} EQUAL 32)
    set(LIB_DIR "lib")
else()
    set(LIB_DIR "lib${SYSTEM_BITNESS}")
endif()

# Fix up the installation path
set(Jatta_FIX_INSTALL_PATH ON CACHE BOOL "Causes Jatta to fix the installation path on first generation.")
mark_as_advanced(Jatta_FIX_INSTALL_PATH)
set(Jatta_INSTALL_ESSENTIALS_ONLY OFF CACHE BOOL "Installation will only install libraries and include files (no documentation).")
mark_as_advanced(Jatta_INSTALL_ESSENTIALS_ONLY)
if(NOT Jatta_FIX_INSTALL_PATH)
    set(FIRST OFF)
endif()
if(FIRST)
    set(INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX})
    if(${INSTALL_PREFIX} STREQUAL "/usr/local")
        if(${Jatta_INSTALL_ESSENTIALS_ONLY})
            set(INSTALL_PREFIX "/usr")
        else()
            set(INSTALL_PREFIX "/usr/${LIB_DIR}")
        endif()
    endif()
    if(WIN32 OR NOT ${Jatta_INSTALL_ESSENTIALS_ONLY})
        string(FIND "${CMAKE_INSTALL_PREFIX}" "${PROJECT_NAME}" INDEX)
        if(INDEX EQUAL -1)
            set(INSTALL_PREFIX ${INSTALL_PREFIX}/${PROJECT_NAME})
        endif()
        set(INSTALL_PREFIX ${INSTALL_PREFIX}-${Jatta_VERSION})
    endif()
    get_property(CACHE_DOC CACHE "CMAKE_INSTALL_PREFIX" PROPERTY HELPSTRING)
    get_property(CACHE_TYPE CACHE "CMAKE_INSTALL_PREFIX" PROPERTY TYPE)
    unset(CMAKE_INSTALL_PREFIX CACHE)
    set(CMAKE_INSTALL_PREFIX ${INSTALL_PREFIX} CACHE ${CACHE_TYPE} "${CACHE_DOC}")
endif()

# Set common library include directories
if(IS_DIRECTORY "/usr/include/freetype2")
    set(LIBRARY_INCLUDE_DIRS ${LIBRARY_INCLUDE_DIRS} "/usr/include/freetype2")
endif()
set(Jatta_LIBRARY_INCLUDE_DIRS ${LIBRARY_INCLUDE_DIRS} CACHE STRING "Additional include directories.")

# Set the dependecy directory to the default path
set(Jatta_DEPENDENCY_LIBRARY_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/deps-${SYSTEM_NAME}/lib${SYSTEM_BITNESS}" CACHE STRING "Directories to look for libraries.")
set(Jatta_DEPENDENCY_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/deps-${SYSTEM_NAME}/include" CACHE STRING "Directories to look for headers.")
set(DOXYGEN_ENABLE OFF CACHE BOOL "Specifies whether or not to use Doxygen to generate documentation.")
set(DOXYGEN_WARNINGS OFF CACHE BOOL "Turns on Doxygen warnings during doc generation stage.")
mark_as_advanced(DOXYGEN_WARNINGS)
set(CMAKE_REQUIRED_INCLUDES ${Jatta_DEPENDENCY_INCLUDE_DIRS} ${Jatta_LIBRARY_INCLUDE_DIRS})
set(CMAKE_REQUIRED_DEFINITIONS "-DGLEW_NO_GLU -DGLEW_STATIC -DHAVE_BOOLEAN -DPNG_SKIP_SETJMP_CHECK")
if(MSVC)
    set(CMAKE_REQUIRED_DEFINITIONS "${CMAKE_REQUIRED_DEFINITIONS} -DMSVC")
endif()
set(CMAKE_REQUIRED_FLAGS ${CMAKE_REQUIRED_DEFINITIONS})

# Look for libraries
set(Jatta_REFRESH_LIBRARIES OFF CACHE BOOL "Forces Jatta to refresh searching for libraries everytime cmake runs.")
mark_as_advanced(Jatta_REFRESH_LIBRARIES)
include(libraries/libraries.cmake)

# Compile the library
add_subdirectory(src)

# Add a build step for Doxygen
include(resources/Doxygen.cmake)

# Allow packaging
include(resources/Package.cmake)
