# Jatta - General Utility Library
# Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
# All rights reserved.

if(NOT JATTA_NO_GRAPHICS)
    ADD_GROUP("OpenGL")
    ADD_OTHER(CMakeLists.txt)
    ADD_SOURCE(OpenGL.cpp)
    ADD_HEADER(OpenGL.h include/Jatta/OpenGL/)
    ADD_SOURCE(Program.cpp)
    ADD_HEADER(Program.h include/Jatta/OpenGL/)
    ADD_SOURCE(Shader.cpp)
    ADD_HEADER(Shader.h include/Jatta/OpenGL/)
ENDIF()