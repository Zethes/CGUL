# Jatta - General Utility Library
# Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
# All rights reserved.

if (PNG_FOUND)
    set(Jatta_SOURCES
        ${Jatta_SOURCES}
        ${CMAKE_CURRENT_SOURCE_DIR}/PNG.cpp
    )

    set(Jatta_INSTALL
        ${Jatta_INSTALL}
        ${CMAKE_CURRENT_SOURCE_DIR}/PNG.h
    )
endif()

set(Jatta_SOURCES
    ${Jatta_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/BMP.cpp
    PARENT_SCOPE
)

set(Jatta_INSTALL
    ${Jatta_INSTALL}
    ${CMAKE_CURRENT_SOURCE_DIR}/BMP.h
    PARENT_SCOPE
)
