# Jatta - General Utility Library
# Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
# All rights reserved.

set(Jatta_SOURCES
    ${Jatta_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/AABB2D.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/AABB3D.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Circle.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Collision.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sphere.cpp
    PARENT_SCOPE
)

set(Jatta_INSTALL
    ${Jatta_INSTALL}
    ${CMAKE_CURRENT_SOURCE_DIR}/AABB2D.h
    ${CMAKE_CURRENT_SOURCE_DIR}/AABB3D.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Circle.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Collision.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Sphere.h
    PARENT_SCOPE
)
