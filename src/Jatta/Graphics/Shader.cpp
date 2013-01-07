/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

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
    this->vertexID = this->fragmentID = this->shaderID = this->textureID = 0;
}

_JATTA_EXPORT Jatta::Shader::~Shader()
{

}

_JATTA_EXPORT void Jatta::Shader::Load(const std::string& vertex, const std::string& fragment)
{
    // Create the vertex and fragment shaders
    vertexID = glCreateShader(GL_VERTEX_SHADER);
    fragmentID = glCreateShader(GL_FRAGMENT_SHADER);

    std::string vertexFile, fragmentFile;
    if (!Jatta::File::GetText(vertex, &vertexFile))
    {
        glDeleteShader(vertexID);
        glDeleteShader(fragmentID);
        std::ostringstream ss;
        ss << "Failed to load vertex shader: " << vertex;
        throw std::runtime_error(ss.str().c_str());
        return;
    }
    if (!Jatta::File::GetText(fragment, &fragmentFile))
    {
        glDeleteShader(vertexID);
        glDeleteShader(fragmentID);
        std::ostringstream ss;
		ss << "Failed to load fragment shader: " << fragment;
		throw std::runtime_error(ss.str().c_str());
    }

    const char* vertexString = vertexFile.c_str();
    const char* fragmentString = fragmentFile.c_str();

    // variables for compile-error checking
    int testShader;
    char buffer[1024];
    GLsizei length = 0;

    glShaderSource(vertexID, 1, &vertexString, nullptr);
    glCompileShader(vertexID);

    glGetShaderiv(vertexID, GL_COMPILE_STATUS, &testShader);
    if (!testShader)
    {
        glGetShaderInfoLog(vertexID, 1024, &length, buffer);
		std::ostringstream ss;
		ss << "Error compiling " << vertex << ":\n" << buffer;
		glDeleteShader(vertexID);
		glDeleteShader(fragmentID);
        throw std::runtime_error(ss.str().c_str());
    }

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
        throw std::runtime_error(ss.str().c_str());
    }

    shaderID = glCreateProgram();
    glAttachShader(shaderID, vertexID);
    glAttachShader(shaderID, fragmentID);

    glLinkProgram(shaderID);

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
        throw std::runtime_error(ss.str().c_str());
    }

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
        throw std::runtime_error(ss.str().c_str());
    }

    //_JATTA_DEBUG_LN("Done loading shader.");
}

_JATTA_EXPORT void Jatta::Shader::Unload()
{
    // TODO: Jatta::Shader::unload()
}

_JATTA_EXPORT void Jatta::Shader::Begin()
{
    glUseProgram(shaderID);
}

_JATTA_EXPORT void Jatta::Shader::End()
{
    glUseProgram(0);
}

_JATTA_EXPORT void Jatta::Shader::SetBoolean(const std::string& name, bool value)
{
    glUniform1i(glGetUniformLocation(shaderID, name.c_str()), value);
}

_JATTA_EXPORT void Jatta::Shader::SetFloat(const std::string& name, float value)
{
    glUniform1f(glGetUniformLocation(shaderID, name.c_str()), value);
}

_JATTA_EXPORT void Jatta::Shader::SetFloat2(const std::string& name, const Jatta::Float2& value)
{
    glUniform2f(glGetUniformLocation(shaderID, name.c_str()), value.x, value.y);
}

_JATTA_EXPORT void Jatta::Shader::SetFloat3(const std::string& name, const Jatta::Float3& value)
{
    glUniform3f(glGetUniformLocation(shaderID, name.c_str()), value.x, value.y, value.z);
}

_JATTA_EXPORT void Jatta::Shader::SetFloat4(const std::string& name, const Jatta::Float4& value)
{
    glUniform4f(glGetUniformLocation(shaderID, name.c_str()), value.x, value.y, value.z, value.w);
}

_JATTA_EXPORT void Jatta::Shader::SetColor(const std::string& name, const Jatta::Color& color)
{
    glUniform4f(glGetUniformLocation(shaderID, name.c_str()), color.r / 255.0f, color.g / 255.0f, color.b / 255.0f, color.a / 255.0f);
}

_JATTA_EXPORT void Jatta::Shader::SetMatrix(const std::string& name, const Jatta::Matrix& matrix)
{
    glUniformMatrix4fv(glGetUniformLocation(shaderID, name.c_str()), 1, GL_FALSE, matrix.GetData());
}

_JATTA_EXPORT void Jatta::Shader::SetTexture(const std::string& name, const Texture& texture)
{
    int id = 0;
    std::map<std::string,int>::iterator it = textures.find(name);
    if (it != textures.end())
    {
    	id = it->second;
    }
    else
    {
    	id = textureID++;
    	textures.insert(std::make_pair(name,id));
    }

    int myTexture = glGetUniformLocation(shaderID, name.c_str());
    glUniform1i(myTexture, id);
    glActiveTexture(GL_TEXTURE0 + id);
    glBindTexture(GL_TEXTURE_2D, texture.GetTexture());
}

_JATTA_EXPORT void Jatta::Shader::SetTexture(const std::string& name, const RenderTarget& texture)
{
	int id = 0;
	std::map<std::string,int>::iterator it = textures.find(name);
	if (it != textures.end())
	{
		id = it->second;
	}
	else
	{
		id = textureID++;
		textures.insert(std::make_pair(name,id));
	}

	int myTexture = glGetUniformLocation(shaderID, name.c_str());
	glUniform1i(myTexture, id);
	glActiveTexture(GL_TEXTURE0 + id);
	glBindTexture(GL_TEXTURE_2D, texture.GetTexture(0));
}

_JATTA_EXPORT void Jatta::Shader::BindTextureAttributes(const char* texCoords, const char* vertPosition)
{
	for (unsigned int i = 0; i < 13; i++)
	{
		Jatta::String str = "texColor";
		str += (int)i;
		BindAttribute(i, str.GetData());
	}
	BindAttribute(14, texCoords);
	BindAttribute(15, vertPosition);
}

_JATTA_EXPORT void Jatta::Shader::BindAttribute(unsigned int index, const std::string& name)
{
    glBindAttribLocation(shaderID, index, name.c_str());
    glLinkProgram(shaderID); // TODO: make shaders not call this every time
}
