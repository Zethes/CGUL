# C++ General Utility Library (mailto:cgul@zethes.com)
# Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
# All rights reserved.

if(NOT CGUL_USE_OPENGL)
    return()
endif()

if(APPLE)
    add_subdirectory(MacOS)
endif()

set(CGUL_SOURCES
    ${CGUL_SOURCES}
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

set(CGUL_INSTALL
    ${CGUL_INSTALL}
    ${CMAKE_CURRENT_SOURCE_DIR}/Buffer.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Context.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/FrameBuffer.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/GL.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/OpenGL.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Program.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/RawGL.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/RenderBuffer.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Shader.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Texture.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/VertexArray.hpp
    PARENT_SCOPE
)

set(CGUL_PROJECT_FILES
    ${CGUL_PROJECT_FILES}
    ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
    PARENT_SCOPE
)
