//        JATTA        //
// by Joshua Brookover //

#pragma once
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
        unsigned int vertexID, fragmentID, shaderID;

        _JATTA_EXPORT Shader(const Shader& copy);
        _JATTA_EXPORT Shader(Shader&& move);
    public:
        _JATTA_EXPORT Shader();
        _JATTA_EXPORT ~Shader();

        _JATTA_EXPORT void load(const std::string& vertex, const std::string& fragment);
        _JATTA_EXPORT void unload();

        _JATTA_EXPORT void begin();
        _JATTA_EXPORT void end();

        _JATTA_EXPORT void setBoolean(const std::string& name, bool value);
        _JATTA_EXPORT void setFloat(const std::string& name, float value);
        _JATTA_EXPORT void setFloat2(const std::string& name, const Jatta::Float2& value);
        _JATTA_EXPORT void setFloat3(const std::string& name, const Jatta::Float3& value);
        _JATTA_EXPORT void setFloat4(const std::string& name, const Jatta::Float4& value);
        _JATTA_EXPORT void setColor(const std::string& name, const Jatta::Color& color);
        _JATTA_EXPORT void setMatrix(const std::string& name, const Jatta::Matrix& matrix);
        _JATTA_EXPORT void setTexture(const std::string& name, const Texture& texture);
        //void setTexture(const std::string& name, Texture texture);
        //void setTexture(const std::string& name, CubeMap* texture);
        //void setTexture(const std::string& name, CubeMap texture);
        //void setArray(const std::string& name, Vector4* vectors, UInt size);

        _JATTA_EXPORT void bindAttribute(unsigned int index, const std::string& name);
    };
}

#include "../External/Undefines.h"