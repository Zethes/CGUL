# Jatta - General Utility Library
# Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
# All rights reserved.

set(Jatta_SOURCES
    ${Jatta_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/Random.cpp
    PARENT_SCOPE
)

set(Jatta_INSTALL
    ${Jatta_INSTALL}
    ${CMAKE_CURRENT_SOURCE_DIR}/Math.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Math_Implement.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Matrix.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Matrix_Implement.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Quaternion.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Quaternion_Implement.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Random.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Vector2.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Vector2_Implement.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Vector3.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Vector3_Implement.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Vector4.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Vector4_Implement.h
    PARENT_SCOPE
)
