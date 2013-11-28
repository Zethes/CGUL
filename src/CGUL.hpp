/*                                    _____                                         *\
|                                   (, /                                             |
|                                     /  _  _/__/_ _                                 |
|                                 ___/__(_(_(__(__(_(_                               |
|                               /   /                                                |
|                              (__ /                                                 |
|                                                                                    |
|  Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall                        |
|  All rights reserved.                                                              |
|                                                                                    |
|  Redistribution and use in source and binary forms, with or without modification,  |
|  are permitted provided that the following conditions are met:                     |
|                                                                                    |
|  * Redistributions of source code must retain the above copyright notice, this     |
|    list of conditions and the following disclaimer.                                |
|  * Redistributions in binary form must reproduce the above copyright notice, this  |
|    list of conditions and the following disclaimer in the documentation and/or     |
|    other materials provided with the distribution.                                 |
|                                                                                    |
|  THIS SOFTWARE IS PROVIDED BY THE  COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND  |
|  ANY EXPRESS OR IMPLIED  WARRANTIES,  INCLUDING, BUT NOT  LIMITED TO, THE IMPLIED  |
|  WARRANTIES  OF  MERCHANTABILITY  AND   FITNESS  FOR  A  PARTICULAR  PURPOSE  ARE  |
|  DISCLAIMED.  IN NO EVENT  SHALL THE COPYRIGHT HOLDER  OR CONTRIBUTORS BE  LIABLE  |
|  FOR  ANY DIRECT,  INDIRECT,  INCIDENTAL,  SPECIAL,  EXEMPLARY,  OR CONSEQUENTIAL  |
|  DAMAGES  (INCLUDING, BUT  NOT LIMITED  TO,  PROCUREMENT  OF SUBSTITUTE  GOODS OR  |
|  SERVICES;  LOSS OF  USE,  DATA, OR PROFITS;  OR  BUSINESS INTERRUPTION)  HOWEVER  |
|  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  |
|  TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY WAY OUT  OF THE USE OF  |
|  THIS  SOFTWARE,   EVEN  IF  ADVISED   OF   THE   POSSIBILITY  OF   SUCH  DAMAGE.  |
|                                                                                    |
\*                                                                                  */

#pragma once

#include <CGUL/Config.h>

#ifdef Assimp_FOUND
#   include "CGUL/Assimp/Animation.h"
#   include "CGUL/Assimp/AnimationStates.h"
#   include "CGUL/Assimp/Assimp.h"
#   include "CGUL/Assimp/Bone.h"
#   include "CGUL/Assimp/Camera.h"
#   include "CGUL/Assimp/ExportBlob.h"
#   include "CGUL/Assimp/Exporter.h"
#   include "CGUL/Assimp/ExportFormatDesc.h"
#   include "CGUL/Assimp/Face.h"
#   include "CGUL/Assimp/Importer.h"
#   include "CGUL/Assimp/Light.h"
#   include "CGUL/Assimp/LightTypes.h"
#   include "CGUL/Assimp/Material.h"
#   include "CGUL/Assimp/MaterialEnums.h"
#   include "CGUL/Assimp/MaterialProperty.h"
#   include "CGUL/Assimp/Mesh.h"
#   include "CGUL/Assimp/MeshAnimation.h"
#   include "CGUL/Assimp/MeshKey.h"
#   include "CGUL/Assimp/Node.h"
#   include "CGUL/Assimp/NodeAnimation.h"
#   include "CGUL/Assimp/QuatKey.h"
#   include "CGUL/Assimp/Scene.h"
#   include "CGUL/Assimp/SceneFlags.h"
#   include "CGUL/Assimp/Texture.h"
#   include "CGUL/Assimp/UVTransform.h"
#   include "CGUL/Assimp/VectorKey.h"
#   include "CGUL/Assimp/VertexWeight.h"
#endif

#include "CGUL/Containers/Array.h"
#include "CGUL/Containers/Container.h"
#include "CGUL/Containers/FixedList.h"
#include "CGUL/Containers/HashMap.h"
#include "CGUL/Containers/List.h"
#include "CGUL/Containers/Vector.h"

#include "CGUL/Exceptions/Exception.h"
#include "CGUL/Exceptions/FatalException.h"
#include "CGUL/Exceptions/FileException.h"
#include "CGUL/Exceptions/NetworkException.h"
#include "CGUL/Exceptions/OpenGLException.h"

#ifdef FreeType_FOUND
#   include "CGUL/Fonts/Font.h"
#   include "CGUL/Fonts/FontStyles.h"
#   include "CGUL/Fonts/Glyph.h"
#endif

#include "CGUL/Images/Color.h"
#include "CGUL/Images/Colors.h"
#include "CGUL/Images/Image.h"
#include "CGUL/Images/ImageFormats.h"
#include "CGUL/Images/Mipmap.h"
#include "CGUL/Images/Loaders/BMP.h"
#ifdef PNG_FOUND
#   include "CGUL/Images/Loaders/PNG.h"
#endif
#ifdef JPEG_FOUND
#   include "CGUL/Images/Loaders/JPEG.h"
#endif

#include "CGUL/Math/Math.hpp"
#include "CGUL/Math/Matrix.hpp"
#include "CGUL/Math/Random.hpp"
#include "CGUL/Math/Quaternion.hpp"
#include "CGUL/Math/Vector2.hpp"
#include "CGUL/Math/Vector3.hpp"
#include "CGUL/Math/Vector4.hpp"

#ifdef CGUL_USE_NETWORK
#   include "CGUL/Network/Adapter.h"
#   include "CGUL/Network/DNS.h"
#   include "CGUL/Network/HTTPEnums.h"
#   include "CGUL/Network/HTTPRequest.h"
#   include "CGUL/Network/IPAddress.h"
#   include "CGUL/Network/SocketTCP.h"
#   include "CGUL/Network/SocketUDP.h"
#endif

#ifdef CGUL_USE_OPENGL
#   include "CGUL/OpenGL/Buffer.h"
#   include "CGUL/OpenGL/Context.h"
#   include "CGUL/OpenGL/FrameBuffer.h"
#   include "CGUL/OpenGL/GL.h"
#   include "CGUL/OpenGL/OpenGL.h"
#   include "CGUL/OpenGL/Program.h"
#   include "CGUL/OpenGL/RawGL.h"
#   include "CGUL/OpenGL/RenderBuffer.h"
#   include "CGUL/OpenGL/Shader.h"
#   include "CGUL/OpenGL/Texture.h"
#   include "CGUL/OpenGL/VertexArray.h"
#endif

#ifdef PortAudio_FOUND
#   include "CGUL/PortAudio/Device.h"
#   include "CGUL/PortAudio/HostApi.h"
#   include "CGUL/PortAudio/HostError.h"
#   include "CGUL/PortAudio/InputStream.h"
#   include "CGUL/PortAudio/OutputStream.h"
#   include "CGUL/PortAudio/PortAudio.h"
#   include "CGUL/PortAudio/Stream.h"
#   include "CGUL/PortAudio/StreamData.h"
#   include "CGUL/PortAudio/StreamInfo.h"
#endif

#include "CGUL/Utility/AutoRelease.h"
#include "CGUL/Utility/Encryption.h"
#include "CGUL/Utility/File.h"
#include "CGUL/Utility/JSON.hpp"
#include "CGUL/Utility/Memory.h"
#include "CGUL/Utility/Move.h"
#include "CGUL/Utility/Regex.h"
#include "CGUL/Utility/String.h"
#include "CGUL/Utility/Timer.h"
#include "CGUL/Utility/Thread.h"
#include "CGUL/Utility/Version.h"

/*#include "CGUL/Windows/Input.h"
#include "CGUL/Windows/Inputs.h"
#include "CGUL/Windows/InputState.h"*/
#include "CGUL/Windows/Window.h"
#include "CGUL/Windows/WindowStyle.h"
