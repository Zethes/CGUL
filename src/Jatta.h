/*                                    _____                                         *\
|                                   (, /                                             |
|                                     /  _  _/__/_ _                                 |
|                                 ___/__(_(_(__(__(_(_                               |
|                               /   /                                                |
|                              (__ /                                                 |
|                                                                                    |
|  Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall                        |
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

#include <Jatta/Config.h>

#ifdef Assimp_FOUND
#   include "Jatta/Assimp/Animation.h"
#   include "Jatta/Assimp/AnimationStates.h"
#   include "Jatta/Assimp/Assimp.h"
#   include "Jatta/Assimp/Bone.h"
#   include "Jatta/Assimp/Camera.h"
#   include "Jatta/Assimp/ExportBlob.h"
#   include "Jatta/Assimp/Exporter.h"
#   include "Jatta/Assimp/ExportFormatDesc.h"
#   include "Jatta/Assimp/Face.h"
#   include "Jatta/Assimp/Importer.h"
#   include "Jatta/Assimp/Light.h"
#   include "Jatta/Assimp/LightTypes.h"
#   include "Jatta/Assimp/Material.h"
#   include "Jatta/Assimp/MaterialEnums.h"
#   include "Jatta/Assimp/MaterialProperty.h"
#   include "Jatta/Assimp/Mesh.h"
#   include "Jatta/Assimp/MeshAnimation.h"
#   include "Jatta/Assimp/MeshKey.h"
#   include "Jatta/Assimp/Node.h"
#   include "Jatta/Assimp/NodeAnimation.h"
#   include "Jatta/Assimp/QuatKey.h"
#   include "Jatta/Assimp/Scene.h"
#   include "Jatta/Assimp/SceneFlags.h"
#   include "Jatta/Assimp/Texture.h"
#   include "Jatta/Assimp/UVTransform.h"
#   include "Jatta/Assimp/VectorKey.h"
#   include "Jatta/Assimp/VertexWeight.h"
#endif

#include "Jatta/Containers/Array.h"
#include "Jatta/Containers/Container.h"
#include "Jatta/Containers/FixedList.h"
#include "Jatta/Containers/HashMap.h"
#include "Jatta/Containers/List.h"
#include "Jatta/Containers/Vector.h"

#include "Jatta/Exceptions/Exception.h"
#include "Jatta/Exceptions/FatalException.h"
#include "Jatta/Exceptions/FileException.h"
#include "Jatta/Exceptions/NetworkException.h"
#include "Jatta/Exceptions/OpenGLException.h"

#ifdef FreeType_FOUND
#   include "Jatta/Fonts/Font.h"
#   include "Jatta/Fonts/FontStyles.h"
#   include "Jatta/Fonts/Glyph.h"
#endif

#include "Jatta/Images/Color.h"
#include "Jatta/Images/Colors.h"
#include "Jatta/Images/Image.h"
#include "Jatta/Images/ImageFormats.h"
#include "Jatta/Images/ImageInfo.h"
#include "Jatta/Images/ImageLoader.h"
#include "Jatta/Images/Mipmap.h"
#include "Jatta/Images/Loaders/BMP.h"

#include "Jatta/Math/Math.h"
#include "Jatta/Math/Matrix.h"
#include "Jatta/Math/Random.h"
#include "Jatta/Math/Quaternion.h"
#include "Jatta/Math/Vector2.h"
#include "Jatta/Math/Vector3.h"
#include "Jatta/Math/Vector4.h"

#ifdef Jatta_USE_NETWORK
#   include "Jatta/Network/Adapter.h"
#   include "Jatta/Network/DNS.h"
#   include "Jatta/Network/HTTPEnums.h"
#   include "Jatta/Network/HTTPRequest.h"
#   include "Jatta/Network/IPAddress.h"
#   include "Jatta/Network/SocketTCP.h"
#   include "Jatta/Network/SocketUDP.h"
#endif

#ifdef Jatta_USE_OPENGL
#   include "Jatta/OpenGL/Buffer.h"
#   include "Jatta/OpenGL/Context.h"
#   include "Jatta/OpenGL/FrameBuffer.h"
#   include "Jatta/OpenGL/GL.h"
#   include "Jatta/OpenGL/OpenGL.h"
#   include "Jatta/OpenGL/Program.h"
#   include "Jatta/OpenGL/RenderBuffer.h"
#   include "Jatta/OpenGL/Shader.h"
#   include "Jatta/OpenGL/Texture.h"
#   include "Jatta/OpenGL/VertexArray.h"
#endif

#ifdef PortAudio_FOUND
#   include "Jatta/PortAudio/Device.h"
#   include "Jatta/PortAudio/HostApi.h"
#   include "Jatta/PortAudio/HostError.h"
#   include "Jatta/PortAudio/InputStream.h"
#   include "Jatta/PortAudio/OutputStream.h"
#   include "Jatta/PortAudio/PortAudio.h"
#   include "Jatta/PortAudio/Stream.h"
#   include "Jatta/PortAudio/StreamData.h"
#   include "Jatta/PortAudio/StreamInfo.h"
#endif

#include "Jatta/Utility/AutoRelease.h"
#include "Jatta/Utility/Encryption.h"
#include "Jatta/Utility/File.h"
#include "Jatta/Utility/Memory.h"
#include "Jatta/Utility/Move.h"
#include "Jatta/Utility/Regex.h"
#include "Jatta/Utility/String.h"
#include "Jatta/Utility/Timer.h"
#include "Jatta/Utility/Thread.h"
#include "Jatta/Utility/Version.h"

/*#include "Jatta/Windows/Input.h"
#include "Jatta/Windows/Inputs.h"
#include "Jatta/Windows/InputState.h"*/
#include "Jatta/Windows/Window.h"
#include "Jatta/Windows/WindowStyle.h"
