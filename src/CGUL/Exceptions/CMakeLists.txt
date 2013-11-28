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
    ${CMAKE_CURRENT_SOURCE_DIR}/Exception.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/FatalException.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/FileException.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ImageException.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/NetworkException.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/OpenGLException.hpp
    PARENT_SCOPE
)
