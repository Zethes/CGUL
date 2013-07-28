# Jatta - General Utility Library
# Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
# All rights reserved.

set(Jatta_SOURCES
    ${Jatta_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/Exception.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/FatalException.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/NetworkException.cpp
    PARENT_SCOPE
)

set(Jatta_INSTALL
    ${Jatta_INSTALL}
    ${CMAKE_CURRENT_SOURCE_DIR}/Exception.h
    ${CMAKE_CURRENT_SOURCE_DIR}/FatalException.h
    ${CMAKE_CURRENT_SOURCE_DIR}/NetworkException.h
    PARENT_SCOPE
)
