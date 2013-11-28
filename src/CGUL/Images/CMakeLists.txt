# C++ General Utility Library (mailto:cgul@zethes.com)
# Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
# All rights reserved.

add_subdirectory(Loaders)

set(CGUL_SOURCES
    ${CGUL_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/Color.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Image.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Mipmap.cpp
    PARENT_SCOPE
)

set(CGUL_INSTALL
    ${CGUL_INSTALL}
    ${CMAKE_CURRENT_SOURCE_DIR}/Color.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Color_Implement.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Colors.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Image.h
    ${CMAKE_CURRENT_SOURCE_DIR}/ImageFormats.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Mipmap.h
    PARENT_SCOPE
)
