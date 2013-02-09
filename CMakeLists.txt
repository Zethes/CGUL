# Jatta - General Utility Library
# Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
# All rights reserved.

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(Jatta)

SET(CMAKE_COLOR_MAKEFILE off)
SET(JATTA_NO_JPEG on)
SET(JATTA_NO_NETWORK on)

MESSAGE(STATUS "CXX_FLAGS: " ${CMAKE_CXX_FLAGS})

#SET(CMAKE_CXX_FLAGS "-stdlib=libc++ -std=c++0x -ObjC++ ${CMAKE_CXX_FLAGS}")

#SET(TOP_LEVEL ${CMAKE_CURRENT_SOURCE_DIR})

ADD_SUBDIRECTORY(src)
