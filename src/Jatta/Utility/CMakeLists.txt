# Jatta - General Utility Library
# Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
# All rights reserved.

set(Jatta_SOURCES
    ${Jatta_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/CRC32.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/MD5.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Regex.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/String.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Thread.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Timer.cpp
    PARENT_SCOPE
)

set(Jatta_INSTALL
    ${Jatta_INSTALL}
    ${CMAKE_CURRENT_SOURCE_DIR}/Encryption.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Hook.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Hook.ipp
    ${CMAKE_CURRENT_SOURCE_DIR}/Regex.h
    ${CMAKE_CURRENT_SOURCE_DIR}/String.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Thread.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Timer.h
    PARENT_SCOPE
)
