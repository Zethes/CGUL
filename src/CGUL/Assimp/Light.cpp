// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Light.cpp
 */

#include "Light.hpp"

_CGUL_EXPORT CGUL::Assimp::Light::Light(aiLight* light)
{
    this->light = light;
}

_CGUL_EXPORT CGUL::String CGUL::Assimp::Light::GetName()
{
    return String(light->mName.C_Str());
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::Light::GetType()
{
    return light->mType;
}

_CGUL_EXPORT CGUL::Vector3 CGUL::Assimp::Light::GetPosition()
{
    return Vector3(light->mPosition.x, light->mPosition.y, light->mPosition.z);
}

_CGUL_EXPORT CGUL::Vector3 CGUL::Assimp::Light::GetDirection()
{
    return Vector3(light->mDirection.x, light->mDirection.y, light->mDirection.z);
}

_CGUL_EXPORT CGUL::Float32 CGUL::Assimp::Light::GetAngleInnerCone()
{
    return light->mAngleInnerCone;
}

_CGUL_EXPORT CGUL::Float32 CGUL::Assimp::Light::GetAngleOuterCone()
{
    return light->mAngleOuterCone;
}

_CGUL_EXPORT CGUL::Float32 CGUL::Assimp::Light::GetAttenuationConstant()
{
    return light->mAttenuationConstant;
}

_CGUL_EXPORT CGUL::Float32 CGUL::Assimp::Light::GetAttenuationLinear()
{
    return light->mAttenuationLinear;
}

_CGUL_EXPORT CGUL::Float32 CGUL::Assimp::Light::GetAttenuationQuadratic()
{
    return light->mAttenuationQuadratic;
}

_CGUL_EXPORT CGUL::Color CGUL::Assimp::Light::GetColorDiffuse()
{
    return Color(light->mColorDiffuse.r, light->mColorDiffuse.g, light->mColorDiffuse.b);
}

_CGUL_EXPORT CGUL::Color CGUL::Assimp::Light::GetColorSpecular()
{
    return Color(light->mColorSpecular.r, light->mColorSpecular.g, light->mColorSpecular.b);
}

_CGUL_EXPORT CGUL::Color CGUL::Assimp::Light::GetColorAmbient()
{
    return Color(light->mColorAmbient.r, light->mColorAmbient.g, light->mColorAmbient.b);
}
