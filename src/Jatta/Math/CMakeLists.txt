# Jatta - General Utility Library
# Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
# All rights reserved.

set(Jatta_SOURCES
    ${Jatta_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/Matrix.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Quaternion.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Random.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Vector2.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Vector3.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Vector4.cpp
    PARENT_SCOPE
)

set(Jatta_INSTALL
    ${Jatta_INSTALL}
    ${CMAKE_CURRENT_SOURCE_DIR}/Math.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Math.ipp
    ${CMAKE_CURRENT_SOURCE_DIR}/Matrix.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Quaternion.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Random.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Vector2.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Vector3.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Vector4.h
    PARENT_SCOPE
)
