# C++ General Utility Library (mailto:cgul@zethes.com)
# Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
# All rights reserved.

set(CGUL_SOURCES
    ${CGUL_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/Check.cpp
    PARENT_SCOPE
)

set(CGUL_INSTALL
    ${CGUL_INSTALL}
    ${CMAKE_CURRENT_SOURCE_DIR}/Defines.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Once.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Undefines.hpp
    PARENT_SCOPE
)

set(CGUL_PROJECT_FILES
    ${CGUL_PROJECT_FILES}
    ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
    PARENT_SCOPE
)
