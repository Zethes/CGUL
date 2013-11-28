# C++ General Utility Library (mailto:cgul@zethes.com)
# Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
# All rights reserved.

set(CGUL_SOURCES
    ${CGUL_SOURCES}
    PARENT_SCOPE
)

set(CGUL_INSTALL
    ${CGUL_INSTALL}
    ${CMAKE_CURRENT_SOURCE_DIR}/Defines.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Once.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Undefines.h
    PARENT_SCOPE
)
