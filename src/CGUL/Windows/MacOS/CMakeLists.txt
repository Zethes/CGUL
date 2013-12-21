# C++ General Utility Library (mailto:cgul@zethes.com)
# Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
# All rights reserved.

set(CGUL_SOURCES
    ${CGUL_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/Application.mm
    ${CMAKE_CURRENT_SOURCE_DIR}/ApplicationDelegate.mm
    ${CMAKE_CURRENT_SOURCE_DIR}/MacWindow.mm
    ${CMAKE_CURRENT_SOURCE_DIR}/WindowDelegate.mm
    PARENT_SCOPE
)

set(CGUL_PROJECT_FILES
    ${CGUL_PROJECT_FILES}
    ${CMAKE_CURRENT_SOURCE_DIR}/Application.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ApplicationDelegate.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
    ${CMAKE_CURRENT_SOURCE_DIR}/MacWindow.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/WindowDelegate.hpp
    PARENT_SCOPE
)
