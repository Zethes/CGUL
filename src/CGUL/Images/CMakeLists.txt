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
    ${CMAKE_CURRENT_SOURCE_DIR}/Color.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Color_Implement.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Colors.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Image.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ImageFormats.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Mipmap.hpp
    PARENT_SCOPE
)
