# Jatta - General Utility Library
# Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
# All rights reserved.

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(Jatta)

SET(CMAKE_COLOR_MAKEFILE OFF)

ADD_SUBDIRECTORY(src)

INCLUDE(src/Scripts/TopLevelCache.cmake)
IF(JATTA_BUILD_EXAMPLES)
    ADD_SUBDIRECTORY(examples)
ENDIF()

#Compile tests with 'make check'
ADD_CUSTOM_TARGET(check COMMAND ctest)
ENABLE_TESTING()
ADD_SUBDIRECTORY(unit_tests)