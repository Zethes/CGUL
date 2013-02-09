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

#include "Jatta/Config.h"

#include "Jatta/Assimp/Assimp.h"
#include "Jatta/Assimp/Camera.h"
#include "Jatta/Assimp/Material.h"
#include "Jatta/Assimp/Mesh.h"
#include "Jatta/Assimp/Scene.h"
#include "Jatta/Assimp/Texture.h"

#include "Jatta/Audio/Device.h"
#include "Jatta/Audio/HostApiInfo.h"
#include "Jatta/Audio/PortAudio.h"
#include "Jatta/Audio/Stream.h"

#include "Jatta/Collision/AABB2D.h"
#include "Jatta/Collision/AABB3D.h"

#include "Jatta/Containers/List.h"
#include "Jatta/Containers/Locale.h"

#include "Jatta/File/File.h"

#include "Jatta/Fonts/Font.h"

#include "Jatta/Graphics/Graphics.h"
#include "Jatta/Graphics/Mesh.h"
#include "Jatta/Graphics/Primitives.h"
#include "Jatta/Graphics/RenderTarget.h"
#include "Jatta/Graphics/Shader.h"
#include "Jatta/Graphics/SubMesh.h"
#include "Jatta/Graphics/Terrain.h"
#include "Jatta/Graphics/Texture.h"

#include "Jatta/Images/Color.h"
#include "Jatta/Images/Colors.h"
#include "Jatta/Images/Image.h"

#include "Jatta/Math/Float2.h"
#include "Jatta/Math/Float3.h"
#include "Jatta/Math/Float4.h"
#include "Jatta/Math/Math.h"
#include "Jatta/Math/Matrix.h"
#include "Jatta/Math/Random.h"
#include "Jatta/Math/Quaternion.h"

#include "Jatta/Models/Group.h"
#include "Jatta/Models/Model.h"
#include "Jatta/Models/Obj.h"
#include "Jatta/Models/VertexBuffer.h"

#include "Jatta/Network/DNS.h"
#include "Jatta/Network/SocketTCP.h"

#include "Jatta/OpenGL/Buffer.h"
#include "Jatta/OpenGL/Context.h"
#include "Jatta/OpenGL/OpenGL.h"
#include "Jatta/OpenGL/Program.h"
#include "Jatta/OpenGL/Shader.h"
#include "Jatta/OpenGL/Texture.h"
#include "Jatta/OpenGL/VertexArray.h"

#include "Jatta/Utility/Encryption.h"
#include "Jatta/Utility/Object.h"
#include "Jatta/Utility/Regex.h"
#include "Jatta/Utility/String.h"
#include "Jatta/Utility/Timer.h"

#include "Jatta/Windows/Input.h"
#include "Jatta/Windows/Inputs.h"
#include "Jatta/Windows/InputState.h"
#include "Jatta/Windows/Window.h"
#include "Jatta/Windows/WindowStyle.h"
