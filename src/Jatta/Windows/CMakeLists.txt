# Jatta - General Utility Library
# Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
# All rights reserved.

if(APPLE)
    add_subdirectory(MacOS)
endif()

set(Jatta_SOURCES
    ${Jatta_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/Input.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/InputState.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Window.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/WindowStyle.cpp
    PARENT_SCOPE
)

set(Jatta_INSTALL
    ${Jatta_INSTALL}
    ${CMAKE_CURRENT_SOURCE_DIR}/Input.h
    ${CMAKE_CURRENT_SOURCE_DIR}/InputState.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Inputs.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Window.h
    ${CMAKE_CURRENT_SOURCE_DIR}/WindowStyle.h
    PARENT_SCOPE
)
