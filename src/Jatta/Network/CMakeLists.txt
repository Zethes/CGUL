# Jatta - General Utility Library
# Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
# All rights reserved.

if(NOT Jatta_USE_NETWORK)
    return()
endif()

set(Jatta_SOURCES
    ${Jatta_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/DNS.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Network.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/SocketTCP.cpp
    PARENT_SCOPE
)

set(Jatta_INSTALL
    ${Jatta_INSTALL}
    ${CMAKE_CURRENT_SOURCE_DIR}/DNS.h
    ${CMAKE_CURRENT_SOURCE_DIR}/SocketTCP.h
    PARENT_SCOPE
)
