// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Camera.cpp
 */

#include "Camera.hpp"

_CGUL_EXPORT CGUL::Assimp::Camera::Camera(aiCamera* camera)
{
    this->camera = camera;
}

CGUL::String CGUL::Assimp::Camera::GetName()
{
    return String(camera->mName.C_Str());
}

CGUL::Vector3 CGUL::Assimp::Camera::GetLookAt()
{
    return Vector3(camera->mLookAt.x, camera->mLookAt.y, camera->mLookAt.z);
}

CGUL::Vector3 CGUL::Assimp::Camera::GetPosition()
{
    return Vector3(camera->mPosition.x, camera->mPosition.y, camera->mPosition.z);
}

CGUL::Vector3 CGUL::Assimp::Camera::GetUp()
{
    return Vector3(camera->mUp.x, camera->mUp.y, camera->mUp.z);
}

CGUL::Float32 CGUL::Assimp::Camera::GetAspectRatio()
{
    return camera->mAspect;
}

CGUL::Float32 CGUL::Assimp::Camera::GetClipPlaneFar()
{
    return camera->mClipPlaneFar;
}

CGUL::Float32 CGUL::Assimp::Camera::GetClipPlaneNear()
{
    return camera->mClipPlaneNear;
}

CGUL::Float32 CGUL::Assimp::Camera::GetFieldOfView()
{
    return camera->mHorizontalFOV;
}
