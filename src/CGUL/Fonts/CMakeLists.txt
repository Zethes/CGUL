# C++ General Utility Library
# Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
# All rights reserved.

if(NOT FreeType_FOUND)
    return()
endif()

set(CGUL_SOURCES
    ${CGUL_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/Font.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Glyph.cpp
    PARENT_SCOPE
)

set(CGUL_INSTALL
    ${CGUL_INSTALL}
    ${CMAKE_CURRENT_SOURCE_DIR}/Font.h
    ${CMAKE_CURRENT_SOURCE_DIR}/FontStyles.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Glyph.h
    PARENT_SCOPE
)
