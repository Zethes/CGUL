# C++ General Utility Library (mailto:cgul@zethes.com)
# Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
# All rights reserved.

if(NOT Assimp_FOUND)
    return()
endif()

set(CGUL_SOURCES
    ${CGUL_SOURCES}
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

set(CGUL_INSTALL
    ${CGUL_INSTALL}
    ${CMAKE_CURRENT_SOURCE_DIR}/Animation.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/AnimationStates.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Assimp.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Bone.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Camera.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ExportBlob.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ExportFormatDesc.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Exporter.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Face.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Importer.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Light.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/LightTypes.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Material.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/MaterialEnums.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/MaterialProperty.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Mesh.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/MeshAnimation.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/MeshKey.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Node.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/NodeAnimation.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/QuatKey.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Scene.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/SceneFlags.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Texture.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/UVTransform.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/VectorKey.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/VertexWeight.hpp
    PARENT_SCOPE
)

set(CGUL_PROJECT_FILES
    ${CGUL_PROJECT_FILES}
    ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
    PARENT_SCOPE
)
