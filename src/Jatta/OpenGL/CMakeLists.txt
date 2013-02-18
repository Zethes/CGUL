# Jatta - General Utility Library
# Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
# All rights reserved.

if(JATTA_USE_OPENGL)
    IF(APPLE)
        ADD_SUBDIRECTORY(MacOS)
    ENDIF()

    ADD_GROUP("OpenGL")
    ADD_SOURCE(Buffer.cpp)
    ADD_HEADER(Buffer.h include/Jatta/OpenGL/)
    ADD_OTHER(CMakeLists.txt)
    ADD_SOURCE(Context.cpp)
    ADD_HEADER(Context.h include/Jatta/OpenGL/)
    ADD_SOURCE(OpenGL.cpp)
    ADD_HEADER(OpenGL.h include/Jatta/OpenGL/)
    ADD_SOURCE(Program.cpp)
    ADD_HEADER(Program.h include/Jatta/OpenGL/)
    ADD_SOURCE(Shader.cpp)
    ADD_HEADER(Shader.h include/Jatta/OpenGL/)
    ADD_SOURCE(Texture.cpp)
    ADD_HEADER(Texture.h include/Jatta/OpenGL/)
    ADD_SOURCE(VertexArray.cpp)
    ADD_HEADER(VertexArray.h include/Jatta/OpenGL/)
ENDIF()