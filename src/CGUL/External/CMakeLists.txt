# Jatta - General Utility Library
# Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
# All rights reserved.

set(Jatta_SOURCES
    ${Jatta_SOURCES}
    PARENT_SCOPE
)

set(Jatta_INSTALL
    ${Jatta_INSTALL}
    ${CMAKE_CURRENT_SOURCE_DIR}/Defines.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Once.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Undefines.h
    PARENT_SCOPE
)
