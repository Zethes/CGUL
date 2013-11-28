# Jatta - General Utility Library
# Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
# All rights reserved.

if(NOT Assimp_FOUND)
    return()
endif()

set(Jatta_SOURCES
    ${Jatta_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/Animation.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Assimp.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Bone.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Camera.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ExportBlob.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ExportFormatDesc.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Exporter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Face.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Importer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Light.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Material.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/MaterialProperty.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Mesh.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/MeshAnimation.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Node.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/NodeAnimation.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Scene.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Texture.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/UVTransform.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/VertexWeight.cpp
    PARENT_SCOPE
)

set(Jatta_INSTALL
    ${Jatta_INSTALL}
    ${CMAKE_CURRENT_SOURCE_DIR}/Animation.h
    ${CMAKE_CURRENT_SOURCE_DIR}/AnimationStates.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Assimp.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Bone.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Camera.h
    ${CMAKE_CURRENT_SOURCE_DIR}/ExportBlob.h
    ${CMAKE_CURRENT_SOURCE_DIR}/ExportFormatDesc.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Exporter.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Face.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Importer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Light.h
    ${CMAKE_CURRENT_SOURCE_DIR}/LightTypes.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Material.h
    ${CMAKE_CURRENT_SOURCE_DIR}/MaterialEnums.h
    ${CMAKE_CURRENT_SOURCE_DIR}/MaterialProperty.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Mesh.h
    ${CMAKE_CURRENT_SOURCE_DIR}/MeshAnimation.h
    ${CMAKE_CURRENT_SOURCE_DIR}/MeshKey.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Node.h
    ${CMAKE_CURRENT_SOURCE_DIR}/NodeAnimation.h
    ${CMAKE_CURRENT_SOURCE_DIR}/QuatKey.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Scene.h
    ${CMAKE_CURRENT_SOURCE_DIR}/SceneFlags.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Texture.h
    ${CMAKE_CURRENT_SOURCE_DIR}/UVTransform.h
    ${CMAKE_CURRENT_SOURCE_DIR}/VectorKey.h
    ${CMAKE_CURRENT_SOURCE_DIR}/VertexWeight.h
    PARENT_SCOPE
)
