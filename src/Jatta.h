/*                                    _____                                         *\
|                                   (, /                                             |
|                                     /  _  _/__/_ _                                 |
|                                 ___/__(_(_(__(__(_(_                               |
|                               /   /                                                |
|                              (__ /                                                 |
|                                                                                    |
|  Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall and Amber Thrall                        |
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

#include "Jatta/Models/Group.h"
#include "Jatta/Models/Model.h"
#include "Jatta/Models/Obj.h"
#include "Jatta/Models/VertexBuffer.h"

#include "Jatta/Network/DNS.h"
#include "Jatta/Network/TCP.h"

#include "Jatta/OpenGL/OpenGL.h"
#include "Jatta/OpenGL/Program.h"
#include "Jatta/OpenGL/Shader.h"

#include "Jatta/Utility/Object.h"
#include "Jatta/Utility/Regex.h"
#include "Jatta/Utility/String.h"
#include "Jatta/Utility/Timer.h"

#include "Jatta/Windows/Input.h"
#include "Jatta/Windows/Window.h"
#include "Jatta/Windows/WindowStyle.h"

/** @mainpage Jatta
 *
 *  @section intro Introduction
 *  Jatta is an object oriented General Utility Library.  Jatta simplifies the process of creating
 *  windows, working with OpenGL, networking, loading in images and models, and much more.
 *
 *  The library does not depend on OpenGL, and optionally it can be disabled when building Jatta.
 *  All tools included can be used in any project for any purpose, including commercial.  Please see
 *  the @ref license for more information.
 *
 *  @section getting_started Getting Started
 *  To begin using the Jatta library, download either a binary or the source code from the
 *  @ref downloads page.  If you prefer to build from source, see the @ref building page.
 *  @warning Jatta is still in developmental stages! Expect many things to not work and those that
 *  do work to change very soon!
 */

/** @page downloads Downloads
 *  Visit our Github page:@n
 *  https://github.com/JoshuaBrookover/Jatta
 */

/** @page license License
 *  @section note Note
 *  Jatta is licensed under the BSD 2-Clause License which can be found below.  If you plan to
 *  release Jatta as source code or as a static library, you must also include the copyright for the
 *  licenses Jatta depends on.  See @ref acknowledgements.  If you simply plan to build and use the
 *  Jatta shared library (DLL, SO, or DYLIB) then you do not have to include any acknowledgements
 *  except Jatta's, which is found in the BSD 2-Clause License.
 *
 *  @section bsd License
 *  Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall@n
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without modification, are permitted
 *  provided that the following conditions are met:
 *
 *  @li Redistributions of source code must retain the above copyright notice, this list of
 *  conditions and the following disclaimer.
 *  @li Redistributions in binary form must reproduce the above copyright notice, this list of
 *  conditions and the following disclaimer in the documentation and/or other materials provided
 *  with the distribution.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
 *  IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND 
 *  FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 *  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 *  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 *  OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */

/** @page acknowledgements Acknowledgements
 *  Jatta utilizes the following fantastic libraries.  This project would not be possible without
 *  them!
 *
 *  @b libpng http://www.libpng.org/ @n
 *  Copyright (C) 1998-2012, Glenn Randers-Pehrson@n
 *  Copyright (C) 1996-1997, Andreas Dilger@n
 *  Copyright (C) 1995-1996, Guy Eric Schalnat, Group 42, Inc.@n
 *
 *  @b zlib http://www.zlib.net/ @n
 *  Copyright (C) 1995-2012, Jean-loup Gailly and Mark Adler
 *
 *  @b The @b OpenGL @b Extension @b Wrangler @b Library http://glew.sourceforge.net/ @n
 *  Copyright (C) 2002-2007, Milan Ikits <milan ikits[]ieee org>@n
 *  Copyright (C) 2002-2007, Marcelo E. Magallon <mmagallo[]debian org>@n
 *  Copyright (C) 2002, Lev Povalahev@n
 *  All rights reserved.
 *
 *  @b libjpeg http://libjpeg.sourceforge.net/ @n
 *  Copyright (C) 1991-2012, Thomas G. Lane, Guido Vollbeding.
 *
 *  @b FreeType http://www.freetype.org/ @n
 *  Copyright (C) 1996-2002, David Turner, Robert Wilhelm, and Werner Lemberg
 *
 *  @n This HTML help page was generated by Doxygen.  Check it out!@n
 *  http://www.stack.nl/~dimitri/doxygen/
 */

/** @page building Building Jatta
 *  Good luck.
 */

/** @page developing Developing Jatta
 *  This page is dedicated to Jatta developers looking to import the source code into their project.
 *  Since Jatta uses CMake, it is recommended that developers also use CMake.  All of the code on
 *  this page is CMake-related and aims to explain the process of importing Jatta's CMakeLists.txt
 *  properly.
 *
 *  @section importing_jatta Importing Jatta
 *  Jatta breaks up the CMakeLists.txt into three categories: project level, source level and
 *  source-directory level.  The project level CMake list should not be used if importing Jatta into
 *  another project.  This level is only used if building Jatta on its own.  The CMake list
 *  developers should import is the source level list.  The source-directory level lists are loaded
 *  from the source level list.
 *
 *  Here is an example CMake for importing Jatta:
 *  @code
 *  CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
 *
 *  PROJECT(MyProject)
 *
 *  SET(JATTA_LIB_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
 *  SET(JATTA_DLL_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
 *
 *  ADD_SUBDIRECTORY(/dir/to/Jatta/src "${CMAKE_CURRENT_BINARY_DIR}/Jatta")
 *  @endcode
 *  In this example the LIB and DLL will both be exported to ${CMAKE_CURRENT_SOURCE_DIR}.  You can
 *  specify any directory you wish for Jatta to be exported into.  By default, it gets exported in
 *  its build directory under /bin for the shared library and under /lib for the library.  It is
 *  also possible to change where in the build directory that Jatta is exported by changing the
 *  second argument in ADD_SUBDIRECTORY().  Do note that once the directory to Jatta is specified
 *  the /src directory should be tagged on the end to capture Jatta's source directory instead of
 *  its root directory.
 *
 *  At this point, Jatta will build whenever your project is built.  Any modifications made to the
 *  source will come into effect.  One more step needs to be done so that the Jatta directories are
 *  included properly.  It is recommended that you setup a variable, such as JATTA_DIRECTORY, to
 *  initially include the Jatta subdirectory.
 *  @code
 *  CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
 *
 *  PROJECT(MyProject)
 *
 *  SET(JATTA_LIB_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
 *  SET(JATTA_DLL_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
 *  SET(JATTA_DIRECTORY /dir/to/Jatta)
 *
 *  ADD_SUBDIRECTORY(${JATTA_DIRECTORY}/src "${CMAKE_CURRENT_BINARY_DIR}/Jatta")
 *  @endcode
 *
 *  Later, when your main executable is defined, you will want to add the Jatta source directory to
 *  the includes of your project so that you can include <Jatta.h>:
 *  @code
 *  ADD_EXECUTABLE(MyProject ${SOURCE_FILES})
 *  INCLUDE_DIRECTORIES(${JATTA_DIRECTORY}/src)
 *  TARGET_LINK_LIBRARIES(MyProject Jatta)
 *  @endcode
 *
 *  Some optional flags can be defined to customize how Jatta is built.
 *  @code
 *  SET(JATTA_NO_FONTS ON) # Disables font support (removes freetype)
 *
 *  SET(JATTA_NO_GRAPHICS ON) # Disables OpenGL (removes glew and opengl)
 *
 *  SET(JATTA_NO_NETWORK ON) # Disables networking (removes winsock / bsd sockets)
 *  @endcode
 */

/** @page graphics Graphics & Windows
 *  @tableofcontents
 *  In this tutorial we will be going over how to create a basic window and initiate an OpenGL
 *  graphics device.
 *  @section create_window Creating a Window
 *  Creating a window in Jatta is a very simple process.  The code to create a window will be
 *  demonstrated first, then we will talk about what is happening.
 *  @code
 *  #include <Jatta.h>
 *
 *  int main()
 *  {
 *      // Create and populate the window style
 *      Jatta::WindowStyle style;
 *      style.title = "My First Window";
 *      style.width = 640;
 *      style.height = 480;
 *      style.backgroundColor = Jatta::Color(255, 0, 0);
 *
 *      // Create the window
 *      Jatta::Window window;
 *      window.Create(style);
 *
 *      // Begin the update loop
 *      while (window.IsOpen())
 *      {
 *          window.Update();
 *      }
 *  }
 *  @endcode
 *  @subsection window_style Window Style
 *  When creating a window, a Window Style must be specified.  This defines some information about
 *  the window before it is created.  Refer to Jatta::WindowStyle for a complete list of
 *  attributes.
 *  @subsection subsection2 The second subsection
 *  More text.
*/
