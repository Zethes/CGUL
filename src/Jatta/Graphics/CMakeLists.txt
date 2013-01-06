# Jatta - General Utility Library
# Copyright (c) 2012-2013, Joshua Brookover
# All rights reserved.

if(NOT JATTA_NO_GRAPHICS)
    ADD_GROUP("Graphics")
    ADD_OTHER(CMakeLists.txt)
    ADD_SOURCE(Graphics.cpp)
    ADD_HEADER(Graphics.h include/Jatta/Graphics/)
    ADD_SOURCE(Mesh.cpp)
    ADD_HEADER(Mesh.h include/Jatta/Graphics/)
    ADD_SOURCE(Primitives.cpp)
    ADD_HEADER(Primitives.h include/Jatta/Graphics/)
    ADD_SOURCE(RenderTarget.cpp)
    ADD_HEADER(RenderTarget.h include/Jatta/Graphics/)
    ADD_SOURCE(Shader.cpp)
    ADD_HEADER(Shader.h include/Jatta/Graphics/)
    ADD_SOURCE(SubMesh.cpp)
    ADD_HEADER(SubMesh.h include/Jatta/Graphics/)
    ADD_SOURCE(Texture.cpp)
    ADD_HEADER(Texture.h include/Jatta/Graphics/)
ENDIF()