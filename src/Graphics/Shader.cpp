#include "Shader.h"
#include "../File/File.h"
#include <GL/glew.h>
#include <sstream>

#include "../Math/Float2.h"
#include "../Math/Float3.h"
#include "../Math/Float4.h"
#include "../Math/Matrix.h"
#include "../Images/Color.h"
#include "Texture.h"

_JATTA_EXPORT Jatta::Shader::Shader(const Shader& copy)
{
    /* Deleted */
}

_JATTA_EXPORT Jatta::Shader::Shader(Shader&& move)
{
    /* Deleted */
}

_JATTA_EXPORT Jatta::Shader::Shader()
{
    this->vertexID = this->fragmentID = this->shaderID = 0;
}

_JATTA_EXPORT Jatta::Shader::~Shader()
{

}

_JATTA_EXPORT void Jatta::Shader::load(const std::string& vertex, const std::string& fragment)
{
    // Create the vertex and fragment shaders
    _JATTA_DEBUG_LN("Creating shaders...");
    _JATTA_DEBUG_LN((void*)glCreateShader);
    vertexID = glCreateShader(GL_VERTEX_SHADER);
    fragmentID = glCreateShader(GL_FRAGMENT_SHADER);

    _JATTA_DEBUG_LN("Reading file...");
    std::string vertexFile, fragmentFile;
    if (!Jatta::File::getText(vertex, &vertexFile))
    {
        glDeleteShader(vertexID);
        glDeleteShader(fragmentID);
        _JATTA_DEBUG_LN("Failed to load vertex shader.");
        return;
    }
    if (!Jatta::File::getText(fragment, &fragmentFile))
    {
        glDeleteShader(vertexID);
        glDeleteShader(fragmentID);
        _JATTA_DEBUG_LN("Failed to load fragment shader.");
        return;
    }

    const char* vertexString = vertexFile.c_str();
    const char* fragmentString = fragmentFile.c_str();

    // variables for compile-error checking
    int testShader;
    char buffer[1024];
    GLsizei length = 0;

    _JATTA_DEBUG_LN("Compiling vertex shader...");
    glShaderSource(vertexID, 1, &vertexString, nullptr);
    glCompileShader(vertexID);

    glGetShaderiv(vertexID, GL_COMPILE_STATUS, &testShader);
    if (!testShader)
    {
        glGetShaderInfoLog(vertexID, 1024, &length, buffer);
        std::stringstream ss(std::stringstream::out | std::stringstream::in);
        ss << "Error compiling " << vertex << ":\n" << buffer;
        glDeleteShader(vertexID);
        glDeleteShader(fragmentID);
        _JATTA_DEBUG_LN(ss.str());
        return;
    }

    _JATTA_DEBUG_LN("Compiling fragment shader...");
    glShaderSource(fragmentID, 1, &fragmentString, nullptr);
    glCompileShader(fragmentID);

    glGetShaderiv(fragmentID, GL_COMPILE_STATUS, &testShader);
    if (!testShader)
    {
        glGetShaderInfoLog(fragmentID, 1024, &length, buffer);
        std::stringstream ss(std::stringstream::out | std::stringstream::in);
        ss << "Error compiling " << fragment << ":\n" << buffer;
        glDeleteShader(vertexID);
        glDeleteShader(fragmentID);
        _JATTA_DEBUG_LN(ss.str());
        return;
    }

    _JATTA_DEBUG_LN("Creating shader program...");
    shaderID = glCreateProgram();
    glAttachShader(shaderID, vertexID);
    glAttachShader(shaderID, fragmentID);

    _JATTA_DEBUG_LN("Linking shader...");
    glLinkProgram(shaderID);

    _JATTA_DEBUG_LN("Cleaning up...");
    glDeleteShader(vertexID);
    glDeleteShader(fragmentID);

    glGetProgramiv(shaderID, GL_LINK_STATUS, &testShader);
    if (!testShader)
    {
        glGetProgramInfoLog(shaderID, 1024, &length, buffer);
        std::stringstream ss(std::stringstream::out | std::stringstream::in);
        ss << buffer;
        glDeleteProgram(shaderID);
        glDeleteShader(vertexID);
        glDeleteShader(fragmentID);
        // TODO: error checking
        _JATTA_DEBUG_LN(ss.str());
        return;
    }

    _JATTA_DEBUG_LN("Validating shader program...");
    glValidateProgram(shaderID);

    glGetProgramiv(shaderID, GL_VALIDATE_STATUS, &testShader);
    if (!testShader)
    {
        glGetProgramInfoLog(shaderID, 1024, &length, buffer);
        std::stringstream ss(std::stringstream::out | std::stringstream::in);
        ss << buffer;
        glDeleteProgram(shaderID);
        glDeleteShader(vertexID);
        glDeleteShader(fragmentID);
        // TODO: error checking
        _JATTA_DEBUG_LN(ss.str());
        return;
    }

    _JATTA_DEBUG_LN("Done loading shader.");
}

_JATTA_EXPORT void Jatta::Shader::unload()
{
    // TODO: Jatta::Shader::unload()
}

_JATTA_EXPORT void Jatta::Shader::begin()
{
    glUseProgram(shaderID);
}

_JATTA_EXPORT void Jatta::Shader::end()
{
    glUseProgram(0);
}

_JATTA_EXPORT void Jatta::Shader::setBoolean(const std::string& name, bool value)
{
    glUniform1i(glGetUniformLocation(shaderID, name.c_str()), value);
}

_JATTA_EXPORT void Jatta::Shader::setFloat(const std::string& name, float value)
{
    glUniform1f(glGetUniformLocation(shaderID, name.c_str()), value);
}

_JATTA_EXPORT void Jatta::Shader::setFloat2(const std::string& name, const Jatta::Float2& value)
{
    glUniform2f(glGetUniformLocation(shaderID, name.c_str()), value.x, value.y);
}

_JATTA_EXPORT void Jatta::Shader::setFloat3(const std::string& name, const Jatta::Float3& value)
{
    glUniform3f(glGetUniformLocation(shaderID, name.c_str()), value.x, value.y, value.z);
}

_JATTA_EXPORT void Jatta::Shader::setFloat4(const std::string& name, const Jatta::Float4& value)
{
    glUniform4f(glGetUniformLocation(shaderID, name.c_str()), value.x, value.y, value.z, value.w);
}

_JATTA_EXPORT void Jatta::Shader::setColor(const std::string& name, const Jatta::Color& color)
{
    glUniform4f(glGetUniformLocation(shaderID, name.c_str()), color.r / 255.0f, color.g / 255.0f, color.b / 255.0f, color.a / 255.0f);
}

_JATTA_EXPORT void Jatta::Shader::setMatrix(const std::string& name, const Jatta::Matrix& matrix)
{
    glUniformMatrix4fv(glGetUniformLocation(shaderID, name.c_str()), 1, GL_FALSE, matrix.getData());
}

_JATTA_EXPORT void Jatta::Shader::setTexture(const std::string& name, const Texture& texture)
{
    int id = 0;
    int myTexture = glGetUniformLocation(shaderID, name.c_str());
    glUniform1i(myTexture, id);
    glActiveTexture(GL_TEXTURE0 + id);
    glBindTexture(GL_TEXTURE_2D, texture.getTexture());
}

_JATTA_EXPORT void Jatta::Shader::bindAttribute(unsigned int index, const std::string& name)
{
    glBindAttribLocation(shaderID, index, name.c_str());
    glLinkProgram(shaderID); // @TODO make shaders not call this every time
}
