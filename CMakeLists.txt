# C++ General Utility Library (mailto:cgul@zethes.com)
# Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
# All rights reserved.
cmake_minimum_required(VERSION 2.8.7)
cmake_policy(VERSION 2.8.7)
message(STATUS "Configuring...")

# Setup CGUL options
include(cmake/CGUL.cmake)

# Set installation path
include(cmake/InstallPath.cmake)

# Setup CMake
set(CMAKE_CONFIGURATION_TYPES "Release;Debug" CACHE STRING "A list of build configurations.")
project(${CGUL_OUTPUT_NAME} CXX)

# Support configuration postfixes
foreach(__CONFIGURATION ${CMAKE_CONFIGURATION_TYPES})

    string(TOUPPER "${__CONFIGURATION}" __CONFIGURATION_UPPER)

    if("${__CONFIGURATION_UPPER}" STREQUAL "RELEASE")

        set(CGUL_POSTFIX_${__CONFIGURATION_UPPER} "" CACHE STRING "Postfix for configuration ${__CONFIGURATION}.")

    else()

        set(CGUL_POSTFIX_${__CONFIGURATION_UPPER} "${__CONFIGURATION}" CACHE STRING "Postfix for configuration ${__CONFIGURATION}.")

    endif()

endforeach()

# Version information
include(cmake/Version.cmake)

# Determine system information
include(cmake/System.cmake)

# Determine compiler
include(cmake/Compiler.cmake)

# Determine compiler
include(cmake/CompilerSettings.cmake)

# Determine lib directory name
if(${System_BITNESS} EQUAL 32)
    set(CGUL_LIB_DIR "lib")
else()
    set(CGUL_LIB_DIR "lib${System_BITNESS}")
endif()

# Fix up the installation path
set(CGUL_FIX_INSTALL_PATH ON CACHE BOOL "Causes CGUL to fix the installation path on first generation.")
mark_as_advanced(CGUL_FIX_INSTALL_PATH)
set(CGUL_INSTALL_ESSENTIALS_ONLY OFF CACHE BOOL "Installation will only install libraries and include files (no documentation).")
mark_as_advanced(CGUL_INSTALL_ESSENTIALS_ONLY)
if(NOT CGUL_FIX_INSTALL_PATH)
    set(CGUL_FIRST_GENERATION OFF)
endif()
if(CGUL_FIRST_GENERATION)
    set(INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX})
    if(${INSTALL_PREFIX} STREQUAL "/usr/local")
        if(${CGUL_INSTALL_ESSENTIALS_ONLY})
            set(INSTALL_PREFIX "/usr")
        else()
            set(INSTALL_PREFIX "/usr/local/share/")
        endif()
    endif()
    if(WIN32 OR NOT CGUL_INSTALL_ESSENTIALS_ONLY)
        string(FIND "${CMAKE_INSTALL_PREFIX}" "${PROJECT_NAME}" INDEX)
        if(INDEX EQUAL -1)
            set(INSTALL_PREFIX ${INSTALL_PREFIX}/${PROJECT_NAME})
        endif()
        set(INSTALL_PREFIX ${INSTALL_PREFIX}-${CGUL_VERSION})
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
set(CGUL_LIBRARY_INCLUDE_DIRS ${LIBRARY_INCLUDE_DIRS} CACHE STRING "Additional include directories.")

# Set the dependecy directory to the default path
set(CGUL_DEPENDENCY_LIBRARY_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/deps-${System_DISTRO_LOWER}/lib${System_BITNESS}" CACHE STRING "Directories to look for libraries.")
set(CGUL_DEPENDENCY_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/deps-${System_DISTRO_LOWER}/include" CACHE STRING "Directories to look for headers.")
set(DOXYGEN_ENABLE OFF CACHE BOOL "Specifies whether or not to use Doxygen to generate documentation.")
set(DOXYGEN_WARNINGS OFF CACHE BOOL "Turns on Doxygen warnings during doc generation stage.")
mark_as_advanced(DOXYGEN_WARNINGS)
set(CMAKE_REQUIRED_INCLUDES ${CGUL_DEPENDENCY_INCLUDE_DIRS} ${CGUL_LIBRARY_INCLUDE_DIRS})

if(WIN32)

    set(__PLATFORM "-DCGUL_WINDOWS")

elseif(APPLE)

    set(__PLATFORM "-DCGUL_MACOS")

else()

    set(__PLATFORM "-DCGUL_LINUX")

endif()

set(CMAKE_REQUIRED_DEFINITIONS "-DGLEW_NO_GLU -DGLEW_STATIC -DHAVE_BOOLEAN -DPNG_SKIP_SETJMP_CHECK ${__PLATFORM}")
if(MSVC)
    set(CMAKE_REQUIRED_DEFINITIONS "${CMAKE_REQUIRED_DEFINITIONS} -DMSVC")
endif()
set(CMAKE_REQUIRED_FLAGS ${CMAKE_REQUIRED_DEFINITIONS})

# Look for libraries
set(CGUL_REFRESH_CAPABILITIES OFF CACHE BOOL "Forces CGUL to refresh c++ capabilities in Config.hpp")
mark_as_advanced(CGUL_REFRESH_CAPABILITIES)
include(cmake/Libraries/Libraries.cmake)

# Compile the library
add_subdirectory(src)


# Add external program support
include(cmake/Programs/Programs.cmake)

# Allow packaging
include(cmake/Package.cmake)
