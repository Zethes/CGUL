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
    public:
        Shader();
        Shader(const Shader& copy) = delete;
        Shader(Shader&& move) = delete;
        ~Shader();

        void load(const std::string& vertex, const std::string& fragment);
        void unload();

        void begin();
        void end();

        void setBoolean(const std::string& name, bool value);
        void setFloat(const std::string& name, float value);
        void setFloat2(const std::string& name, const Jatta::Float2& value);
        void setFloat3(const std::string& name, const Jatta::Float3& value);
        void setFloat4(const std::string& name, const Jatta::Float4& value);
        void setColor(const std::string& name, const Jatta::Color& color);
        void setMatrix(const std::string& name, const Jatta::Matrix& matrix);
        void setTexture(const std::string& name, const Texture& texture);
        //void setTexture(const std::string& name, Texture texture);
        //void setTexture(const std::string& name, CubeMap* texture);
        //void setTexture(const std::string& name, CubeMap texture);
        //void setArray(const std::string& name, Vector4* vectors, UInt size);

        void bindAttribute(unsigned int index, const std::string& name);
    };
}

#include "../External/Undefines.h"