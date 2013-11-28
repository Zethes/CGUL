/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "Shader.h"
#include "../Math/Vector2.hpp"
#include "../Math/Vector3.hpp"
#include "../Math/Vector4.hpp"
#include "../Math/Matrix.hpp"
#include "../Images/Color.h"
#include "../External/Defines.h"

/* OpenGL is an experimental namespace in Jatta! */
namespace Jatta
{
    namespace OpenGL
    {
        class Program
        {
            UInt32 program;
        public:
            _JATTA_EXPORT static void Uniform1f(SInt32 location, Float32 value0);
            _JATTA_EXPORT static void Uniform2f(SInt32 location, Float32 value0, Float32 value1);
            _JATTA_EXPORT static void Uniform2f(SInt32 location, Vector2 value);
            _JATTA_EXPORT static void Uniform3f(SInt32 location, Float32 value0, Float32 value1, Float32 value2);
            _JATTA_EXPORT static void Uniform3f(SInt32 location, Vector3 value);
            _JATTA_EXPORT static void Uniform4f(SInt32 location, Float32 value0, Float32 value1, Float32 value2, Float32 value3);
            _JATTA_EXPORT static void Uniform4f(SInt32 location, Vector4 value);

            _JATTA_EXPORT static void Uniform1i(SInt32 location, SInt32 value0);
            _JATTA_EXPORT static void Uniform2i(SInt32 location, SInt32 value0, SInt32 value1);
            _JATTA_EXPORT static void Uniform3i(SInt32 location, SInt32 value0, SInt32 value1, SInt32 value2);
            _JATTA_EXPORT static void Uniform4i(SInt32 location, SInt32 value0, SInt32 value1, SInt32 value2, SInt32 value3);

            _JATTA_EXPORT static void Uniform1ui(UInt32 location, UInt32 value0);
            _JATTA_EXPORT static void Uniform2ui(UInt32 location, UInt32 value0, UInt32 value1);
            _JATTA_EXPORT static void Uniform3ui(UInt32 location, UInt32 value0, UInt32 value1, UInt32 value2);
            _JATTA_EXPORT static void Uniform4ui(UInt32 location, UInt32 value0, UInt32 value1, UInt32 value2, UInt32 value3);

            _JATTA_EXPORT static void Uniform1fv(SInt32 location, Size count, const Float32* value);
            _JATTA_EXPORT static void Uniform2fv(SInt32 location, Size count, const Float32* value);
            _JATTA_EXPORT static void Uniform2fv(SInt32 location, Size count, const Vector2* value);
            _JATTA_EXPORT static void Uniform3fv(SInt32 location, Size count, const Float32* value);
            _JATTA_EXPORT static void Uniform3fv(SInt32 location, Size count, const Vector3* value);
            _JATTA_EXPORT static void Uniform4fv(SInt32 location, Size count, const Float32* value);
            _JATTA_EXPORT static void Uniform4fv(SInt32 location, Size count, const Vector4* value);

            _JATTA_EXPORT static void Uniform1iv(SInt32 location, Size count, const SInt32* value);
            _JATTA_EXPORT static void Uniform2iv(SInt32 location, Size count, const SInt32* value);
            _JATTA_EXPORT static void Uniform3iv(SInt32 location, Size count, const SInt32* value);
            _JATTA_EXPORT static void Uniform4iv(SInt32 location, Size count, const SInt32* value);

            _JATTA_EXPORT static void Uniform1uiv(SInt32 location, Size count, const UInt32* value);
            _JATTA_EXPORT static void Uniform2uiv(SInt32 location, Size count, const UInt32* value);
            _JATTA_EXPORT static void Uniform3uiv(SInt32 location, Size count, const UInt32* value);
            _JATTA_EXPORT static void Uniform4uiv(SInt32 location, Size count, const UInt32* value);

            _JATTA_EXPORT static void UniformMatrix2f(SInt32 location, Boolean transpose, const Float32* value);
            _JATTA_EXPORT static void UniformMatrix3f(SInt32 location, Boolean transpose, const Float32* value);
            _JATTA_EXPORT static void UniformMatrix4f(SInt32 location, Boolean transpose, const Float32* value);
            _JATTA_EXPORT static void UniformMatrix4f(SInt32 location, Boolean transpose, const Matrix& value);
            _JATTA_EXPORT static void UniformMatrix2x3f(SInt32 location, Boolean transpose, const Float32* value);
            _JATTA_EXPORT static void UniformMatrix3x2f(SInt32 location, Boolean transpose, const Float32* value);
            _JATTA_EXPORT static void UniformMatrix2x4f(SInt32 location, Boolean transpose, const Float32* value);
            _JATTA_EXPORT static void UniformMatrix4x2f(SInt32 location, Boolean transpose, const Float32* value);
            _JATTA_EXPORT static void UniformMatrix3x4f(SInt32 location, Boolean transpose, const Float32* value);
            _JATTA_EXPORT static void UniformMatrix4x3f(SInt32 location, Boolean transpose, const Float32* value);

            _JATTA_EXPORT static void UniformMatrix2fv(SInt32 location, Size count, Boolean transpose, const Float32* value);
            _JATTA_EXPORT static void UniformMatrix3fv(SInt32 location, Size count, Boolean transpose, const Float32* value);
            _JATTA_EXPORT static void UniformMatrix4fv(SInt32 location, Size count, Boolean transpose, const Float32* value);
            _JATTA_EXPORT static void UniformMatrix4fv(SInt32 location, Size count, Boolean transpose, const Matrix* value);
            _JATTA_EXPORT static void UniformMatrix2x3fv(SInt32 location, Size count, Boolean transpose, const Float32* value);
            _JATTA_EXPORT static void UniformMatrix3x2fv(SInt32 location, Size count, Boolean transpose, const Float32* value);
            _JATTA_EXPORT static void UniformMatrix2x4fv(SInt32 location, Size count, Boolean transpose, const Float32* value);
            _JATTA_EXPORT static void UniformMatrix4x2fv(SInt32 location, Size count, Boolean transpose, const Float32* value);
            _JATTA_EXPORT static void UniformMatrix3x4fv(SInt32 location, Size count, Boolean transpose, const Float32* value);
            _JATTA_EXPORT static void UniformMatrix4x3fv(SInt32 location, Size count, Boolean transpose, const Float32* value);

            _JATTA_EXPORT Program();
            _JATTA_EXPORT ~Program();

            _JATTA_EXPORT void Create();
            _JATTA_EXPORT void Delete();
            _JATTA_EXPORT UInt32 GetID();

            _JATTA_EXPORT void Bind();
            _JATTA_EXPORT void Unbind();

            _JATTA_EXPORT void AttachShader(const Shader& shader);
            _JATTA_EXPORT void DetachShader(const Shader& shader);

            _JATTA_EXPORT void BindAttribLocation(UInt32 index, const String& name);

            _JATTA_EXPORT void Link();
            _JATTA_EXPORT void Validate();

            _JATTA_EXPORT Boolean GetDeleteStatus();
            _JATTA_EXPORT Boolean GetLinkStatus();
            _JATTA_EXPORT Boolean GetValidateStatus();
            _JATTA_EXPORT String GetInfoLog();
            // TODO: GL_ATTACHED_SHADERS
            // TODO: GL_ACTIVE_ATTRIBUTES
            // TODO: GL_ACTIVE_ATTRIBUTE_MAX_LENGTH
            // TODO: GL_ACTIVE_UNIFORMS
            // TODO: GL_ACTIVE_UNIFORM_MAX_LENGTH

            _JATTA_EXPORT SInt32 GetUniformLocation(const String& name);

            // TODO: finish importing opengl program functions
        };
    }
}

#include "../External/Undefines.h"
