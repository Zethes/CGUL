# Jatta - General Utility Library
# Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
# All rights reserved.

if(JPEG_FOUND)
    set(Jatta_SOURCES
        ${Jatta_SOURCES}
        ${CMAKE_CURRENT_SOURCE_DIR}/Jpg.cpp
    )
endif()

if(PNG_FOUND)
    set(Jatta_SOURCES
        ${Jatta_SOURCES}
        ${CMAKE_CURRENT_SOURCE_DIR}/Png.cpp
    )
endif()

set(Jatta_SOURCES
    ${Jatta_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/Bmp.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Color.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Dds.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Image.cpp
    PARENT_SCOPE
)

set(Jatta_INSTALL
    ${Jatta_INSTALL}
    ${CMAKE_CURRENT_SOURCE_DIR}/Color.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Colors.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Image.h
    PARENT_SCOPE
)
