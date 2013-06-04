/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Light.h"

_JATTA_EXPORT Jatta::Assimp::Light::Light(aiLight* light)
{
    this->light = light;
}

_JATTA_EXPORT Jatta::String Jatta::Assimp::Light::GetName()
{
    return String(light->mName.C_Str());
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Light::GetType()
{
    return light->mType;
}

_JATTA_EXPORT Jatta::Vector3 Jatta::Assimp::Light::GetPosition()
{
    return Vector3(light->mPosition.x, light->mPosition.y, light->mPosition.z);
}
_JATTA_EXPORT Jatta::Vector3 Jatta::Assimp::Light::GetDirection()
{
    return Vector3(light->mDirection.x, light->mDirection.y, light->mDirection.z);
}
_JATTA_EXPORT Jatta::Float32 Jatta::Assimp::Light::GetAngleInnerCone()
{
    return light->mAngleInnerCone;
}
_JATTA_EXPORT Jatta::Float32 Jatta::Assimp::Light::GetAngleOuterCone()
{
    return light->mAngleOuterCone;
}

_JATTA_EXPORT Jatta::Float32 Jatta::Assimp::Light::GetAttenuationConstant()
{
    return light->mAttenuationConstant;
}
_JATTA_EXPORT Jatta::Float32 Jatta::Assimp::Light::GetAttenuationLinear()
{
    return light->mAttenuationLinear;
}
_JATTA_EXPORT Jatta::Float32 Jatta::Assimp::Light::GetAttenuationQuadratic()
{
    return light->mAttenuationQuadratic;
}

_JATTA_EXPORT Jatta::Color Jatta::Assimp::Light::GetColorDiffuse()
{
    return Color(light->mColorDiffuse.r, light->mColorDiffuse.g, light->mColorDiffuse.b);
}
_JATTA_EXPORT Jatta::Color Jatta::Assimp::Light::GetColorSpecular()
{
    return Color(light->mColorSpecular.r, light->mColorSpecular.g, light->mColorSpecular.b);
}
_JATTA_EXPORT Jatta::Color Jatta::Assimp::Light::GetColorAmbient()
{
    return Color(light->mColorAmbient.r, light->mColorAmbient.g, light->mColorAmbient.b);
}
