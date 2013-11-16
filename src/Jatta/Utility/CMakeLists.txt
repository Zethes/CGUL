# Jatta - General Utility Library
# Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
# All rights reserved.

set(Jatta_SOURCES
    ${Jatta_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/CRC32.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/File.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/MD5.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Regex.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/String.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Thread.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Timer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Version.cpp
    PARENT_SCOPE
)

set(Jatta_INSTALL
    ${Jatta_INSTALL}
    ${CMAKE_CURRENT_SOURCE_DIR}/AutoRelease.h
    ${CMAKE_CURRENT_SOURCE_DIR}/AutoRelease_Implement.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Encryption.h
    ${CMAKE_CURRENT_SOURCE_DIR}/File.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Memory.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Memory_Implement.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Move.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Move_Implement.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Regex.h
    ${CMAKE_CURRENT_SOURCE_DIR}/String.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Thread.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Timer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Version.h
    PARENT_SCOPE
)
