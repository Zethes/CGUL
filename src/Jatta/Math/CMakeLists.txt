# Jatta - General Utility Library
# Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
# All rights reserved.

set(Jatta_SOURCES
    ${Jatta_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/Float2.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Float3.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Float4.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Math.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Matrix.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Quaternion.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Random.cpp
    PARENT_SCOPE
)

set(Jatta_INSTALL
    ${Jatta_INSTALL}
    ${CMAKE_CURRENT_SOURCE_DIR}/Float2.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Float3.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Float4.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Math.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Matrix.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Quaternion.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Random.h
    PARENT_SCOPE
)
