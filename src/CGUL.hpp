/*                                                                                  *\
|                       ,gggg,                                                       |
|                      ,88"""Y8b,                        ,dPYb,                      |
|                     d8"     `Y8                        IP'`Yb                      |
|                    d8'   8b  d8                        I8  8I                      |
|                   ,8I    "Y88P'                        I8  8'                      |
|                   I8'            ,gggg,gg  gg      gg  I8 dP                       |
|                   d8            dP"  "Y8I  I8      8I  I8dP                        |
|                   Y8,          i8'    ,8I  I8,    ,8I  I8P                         |
|                   `Yba,,_____,,d8,   ,d8I ,d8b,  ,d8b,,d8b,_                       |
|                     `"Y8888888P"Y8888P"8888P'"Y88P"`Y88P'"Y88                      |
|                                      ,d8I'                                         |
|                                    ,dP'8I                                          |
|                                   ,8"  8I                                          |
|                                   I8   8I                                          |
|                                   `8, ,8I                                          |
|                                    `Y8P"                                           |
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

#include <CGUL/Config.hpp>

#ifdef Assimp_FOUND
#   include "CGUL/Assimp/Animation.hpp"
#   include "CGUL/Assimp/AnimationStates.hpp"
#   include "CGUL/Assimp/Assimp.hpp"
#   include "CGUL/Assimp/Bone.hpp"
#   include "CGUL/Assimp/Camera.hpp"
#   include "CGUL/Assimp/ExportBlob.hpp"
#   include "CGUL/Assimp/Exporter.hpp"
#   include "CGUL/Assimp/ExportFormatDesc.hpp"
#   include "CGUL/Assimp/Face.hpp"
#   include "CGUL/Assimp/Importer.hpp"
#   include "CGUL/Assimp/Light.hpp"
#   include "CGUL/Assimp/LightTypes.hpp"
#   include "CGUL/Assimp/Material.hpp"
#   include "CGUL/Assimp/MaterialEnums.hpp"
#   include "CGUL/Assimp/MaterialProperty.hpp"
#   include "CGUL/Assimp/Mesh.hpp"
#   include "CGUL/Assimp/MeshAnimation.hpp"
#   include "CGUL/Assimp/MeshKey.hpp"
#   include "CGUL/Assimp/Node.hpp"
#   include "CGUL/Assimp/NodeAnimation.hpp"
#   include "CGUL/Assimp/QuatKey.hpp"
#   include "CGUL/Assimp/Scene.hpp"
#   include "CGUL/Assimp/SceneFlags.hpp"
#   include "CGUL/Assimp/Texture.hpp"
#   include "CGUL/Assimp/UVTransform.hpp"
#   include "CGUL/Assimp/VectorKey.hpp"
#   include "CGUL/Assimp/VertexWeight.hpp"
#endif

#include "CGUL/Containers/Array.hpp"
#include "CGUL/Containers/Container.hpp"
#include "CGUL/Containers/FixedList.hpp"
#include "CGUL/Containers/HashMap.hpp"
#include "CGUL/Containers/List.hpp"
#include "CGUL/Containers/Vector.hpp"

#include "CGUL/Exceptions/Exception.hpp"
#include "CGUL/Exceptions/FatalException.hpp"
#include "CGUL/Exceptions/FileException.hpp"
#include "CGUL/Exceptions/NetworkException.hpp"
#include "CGUL/Exceptions/OpenGLException.hpp"

#ifdef FreeType_FOUND
#   include "CGUL/Fonts/Font.hpp"
#   include "CGUL/Fonts/FontStyles.hpp"
#   include "CGUL/Fonts/Glyph.hpp"
#endif

#include "CGUL/Images/Color.hpp"
#include "CGUL/Images/Colors.hpp"
#include "CGUL/Images/Format.hpp"
#include "CGUL/Images/Image.hpp"
#include "CGUL/Images/ImageHandler.hpp"
#include "CGUL/Images/Loader.hpp"
#ifdef JPEG_FOUND
#   include "CGUL/Images/JPEG.hpp"
#endif
#ifdef PNG_FOUND
#   include "CGUL/Images/PNG.hpp"
#endif

#include "CGUL/Math/Math.hpp"
#include "CGUL/Math/Matrix.hpp"
#include "CGUL/Math/Random.hpp"
#include "CGUL/Math/Quaternion.hpp"
#include "CGUL/Math/Vector2.hpp"
#include "CGUL/Math/Vector3.hpp"
#include "CGUL/Math/Vector4.hpp"

#ifdef CGUL_USE_NETWORK
#   include "CGUL/Network/Adapter.hpp"
#   include "CGUL/Network/DNS.hpp"
#   include "CGUL/Network/HTTPEnums.hpp"
#   include "CGUL/Network/HTTPRequest.hpp"
#   include "CGUL/Network/IPAddress.hpp"
#   include "CGUL/Network/SocketTCP.hpp"
#   include "CGUL/Network/SocketUDP.hpp"
#endif

#ifdef CGUL_USE_OPENGL
#   include "CGUL/OpenGL/Buffer.hpp"
#   include "CGUL/OpenGL/Context.hpp"
#   include "CGUL/OpenGL/FrameBuffer.hpp"
#   include "CGUL/OpenGL/GL.hpp"
#   include "CGUL/OpenGL/OpenGL.hpp"
#   include "CGUL/OpenGL/Program.hpp"
#   include "CGUL/OpenGL/RawGL.hpp"
#   include "CGUL/OpenGL/RenderBuffer.hpp"
#   include "CGUL/OpenGL/Shader.hpp"
#   include "CGUL/OpenGL/Texture.hpp"
#   include "CGUL/OpenGL/VertexArray.hpp"
#endif

#ifdef PortAudio_FOUND
#   include "CGUL/PortAudio/Device.hpp"
#   include "CGUL/PortAudio/HostApi.hpp"
#   include "CGUL/PortAudio/HostError.hpp"
#   include "CGUL/PortAudio/InputStream.hpp"
#   include "CGUL/PortAudio/OutputStream.hpp"
#   include "CGUL/PortAudio/PortAudio.hpp"
#   include "CGUL/PortAudio/Stream.hpp"
#   include "CGUL/PortAudio/StreamData.hpp"
#   include "CGUL/PortAudio/StreamInfo.hpp"
#endif

#include "CGUL/Utility/AutoRelease.hpp"
#include "CGUL/Utility/Encryption.hpp"
#include "CGUL/Utility/Event.hpp"
#include "CGUL/Utility/File.hpp"
#include "CGUL/Utility/JSON.hpp"
#include "CGUL/Utility/Memory.hpp"
#include "CGUL/Utility/Move.hpp"
#include "CGUL/Utility/Regex.hpp"
#include "CGUL/Utility/String.hpp"
#include "CGUL/Utility/Timer.hpp"
#include "CGUL/Utility/Thread.hpp"
#include "CGUL/Utility/Version.hpp"

/*#include "CGUL/Windows/Input.hpp"
#include "CGUL/Windows/Inputs.hpp"
#include "CGUL/Windows/InputState.hpp"*/
#include "CGUL/Windows/Window.hpp"
#include "CGUL/Windows/WindowStyle.hpp"
