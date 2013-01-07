/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include "RenderTarget.h"
#include "../External/Defines.h"

namespace Jatta
{
    struct Float2;
    struct Float3;
    struct Float4;
    struct Matrix;
    struct Color;
}

namespace Jatta
{
    class Texture;
    
    class Shader
    {
        unsigned int vertexID, fragmentID, shaderID, textureID;
        std::map<std::string, int> textures;

        _JATTA_EXPORT Shader(const Shader& copy);
        _JATTA_EXPORT Shader(Shader&& move);
    public:
        _JATTA_EXPORT Shader();
        _JATTA_EXPORT ~Shader();

        _JATTA_EXPORT void Load(const std::string& vertex, const std::string& fragment);
        _JATTA_EXPORT void Unload();

        _JATTA_EXPORT void Begin();
        _JATTA_EXPORT void End();

        _JATTA_EXPORT void SetBoolean(const std::string& name, bool value);
        _JATTA_EXPORT void SetFloat(const std::string& name, float value);
        _JATTA_EXPORT void SetFloat2(const std::string& name, const Jatta::Float2& value);
        _JATTA_EXPORT void SetFloat3(const std::string& name, const Jatta::Float3& value);
        _JATTA_EXPORT void SetFloat4(const std::string& name, const Jatta::Float4& value);
        _JATTA_EXPORT void SetColor(const std::string& name, const Jatta::Color& color);
        _JATTA_EXPORT void SetMatrix(const std::string& name, const Jatta::Matrix& matrix);
        _JATTA_EXPORT void SetTexture(const std::string& name, const Texture& texture);
        _JATTA_EXPORT void SetTexture(const std::string& name, const RenderTarget& texture);
        //void setTexture(const std::string& name, Texture texture);
        //void setTexture(const std::string& name, CubeMap* texture);
        //void setTexture(const std::string& name, CubeMap texture);
        //void setArray(const std::string& name, Vector4* vectors, UInt size);

        _JATTA_EXPORT void BindTextureAttributes(const char* , const char* );
        _JATTA_EXPORT void BindAttribute(unsigned int index, const std::string& name);
    };
}

#include "../External/Undefines.h"
