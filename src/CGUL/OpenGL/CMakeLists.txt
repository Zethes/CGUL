# Jatta - General Utility Library
# Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
# All rights reserved.

if(NOT Jatta_USE_OPENGL)
    return()
endif()

if(APPLE)
    add_subdirectory(MacOS)
endif()

set(Jatta_SOURCES
    ${Jatta_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/Buffer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Context.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/FrameBuffer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/OpenGL.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Program.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/RawGL.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/RenderBuffer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Shader.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Texture.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/VertexArray.cpp
    PARENT_SCOPE
)

set(Jatta_INSTALL
    ${Jatta_INSTALL}
    ${CMAKE_CURRENT_SOURCE_DIR}/Buffer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Context.h
    ${CMAKE_CURRENT_SOURCE_DIR}/FrameBuffer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/GL.h
    ${CMAKE_CURRENT_SOURCE_DIR}/OpenGL.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Program.h
    ${CMAKE_CURRENT_SOURCE_DIR}/RawGL.h
    ${CMAKE_CURRENT_SOURCE_DIR}/RenderBuffer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Shader.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Texture.h
    ${CMAKE_CURRENT_SOURCE_DIR}/VertexArray.h
    PARENT_SCOPE
)
