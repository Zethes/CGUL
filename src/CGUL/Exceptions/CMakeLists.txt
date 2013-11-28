# C++ General Utility Library (mailto:cgul@zethes.com)
# Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
# All rights reserved.

set(CGUL_SOURCES
    ${CGUL_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/Exception.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/FatalException.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/FileException.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ImageException.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/NetworkException.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/OpenGLException.cpp
    PARENT_SCOPE
)

set(CGUL_INSTALL
    ${CGUL_INSTALL}
    ${CMAKE_CURRENT_SOURCE_DIR}/Exception.h
    ${CMAKE_CURRENT_SOURCE_DIR}/FatalException.h
    ${CMAKE_CURRENT_SOURCE_DIR}/FileException.h
    ${CMAKE_CURRENT_SOURCE_DIR}/ImageException.h
    ${CMAKE_CURRENT_SOURCE_DIR}/NetworkException.h
    ${CMAKE_CURRENT_SOURCE_DIR}/OpenGLException.h
    PARENT_SCOPE
)
