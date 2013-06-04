/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Camera.h"

_JATTA_EXPORT Jatta::Assimp::Camera::Camera(aiCamera* camera)
{
    this->camera = camera;
}

Jatta::String Jatta::Assimp::Camera::GetName()
{
    return String(camera->mName.C_Str());
}

Jatta::Vector3 Jatta::Assimp::Camera::GetLookAt()
{
    return Vector3(camera->mLookAt.x, camera->mLookAt.y, camera->mLookAt.z);
}

Jatta::Vector3 Jatta::Assimp::Camera::GetPosition()
{
    return Vector3(camera->mPosition.x, camera->mPosition.y, camera->mPosition.z);
}

Jatta::Vector3 Jatta::Assimp::Camera::GetUp()
{
    return Vector3(camera->mUp.x, camera->mUp.y, camera->mUp.z);
}

Jatta::Float32 Jatta::Assimp::Camera::GetAspectRatio()
{
    return camera->mAspect;
}

Jatta::Float32 Jatta::Assimp::Camera::GetClipPlaneFar()
{
    return camera->mClipPlaneFar;
}

Jatta::Float32 Jatta::Assimp::Camera::GetClipPlaneNear()
{
    return camera->mClipPlaneNear;
}

Jatta::Float32 Jatta::Assimp::Camera::GetFieldOfView()
{
    return camera->mHorizontalFOV;
}
