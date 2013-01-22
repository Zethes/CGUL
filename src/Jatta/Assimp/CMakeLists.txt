# Jatta - General Utility Library
# Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
# All rights reserved.

if(NOT JATTA_NO_ASSIMP)
    ADD_GROUP("Assimp")
    ADD_SOURCE(Assimp.cpp)
    ADD_HEADER(Assimp.h include/Jatta/Assimp/)
    ADD_SOURCE(Camera.cpp)
    ADD_HEADER(Camera.h include/Jatta/Assimp/)
    ADD_OTHER(CMakeLists.txt)
    ADD_SOURCE(Material.cpp)
    ADD_HEADER(Material.h include/Jatta/Assimp/)
    ADD_SOURCE(Mesh.cpp)
    ADD_HEADER(Mesh.h include/Jatta/Assimp/)
    ADD_SOURCE(Scene.cpp)
    ADD_HEADER(Scene.h include/Jatta/Assimp/)
    ADD_SOURCE(Texture.cpp)
    ADD_HEADER(Texture.h include/Jatta/Assimp/)
ENDIF()