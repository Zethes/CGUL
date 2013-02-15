/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

 /** @file Defines.h
  *  @brief Sets up the build environment for header files.
  *  @details The goal of this file was to exclude system files which dump defines to the global
  *  namespace from applications which relied on Jatta.  An example of this is Window's CreateWindow
  *  function which is commonly defined as either CreateWindowA or CreateWindowW.  Since this same
  *  define does not exist on Linux or Mac it creates issues only present on Windows.  By excluding
  *  the inclusion of Windows.h in the final product, OS-specific defines are minimized.
  */

#include "Once.h"

#ifndef DOXYGEN

#ifdef WINDOWS
#   define _JATTA_HWND void*
#   define _JATTA_DWORD long
#   define _JATTA_PIXELFORMATDESCRIPTOR Jatta::_JATTA_PIXELFORMATDESCRIPTOR
#   define _JATTA_HDC int
#   define _JATTA_HGLRC int
#endif

#ifdef LINUX
#   define _JATTA_DISPLAY void*
#   define _JATTA_WINDOW void*
#   define _JATTA_GLXCONTEXT void*
#endif

#define _JATTA_FT_FACE void*
#define _JATTA_AISCENE void*
#define _JATTA_AIMESH void*
#define _JATTA_AITEXTURE void*
#define _JATTA_AIMATERIAL void*
#define _JATTA_AICAMERA void*
#define _JATTA_AIBONE void*
#define _JATTA_AIVERTEXWEIGHT void*
#define _JATTA_PASTREAM void*
#define _JATTA_PASTREAM_CALLBACK_TIMEINFO void*
#define _JATTA_PASTREAM_CALLBACK_FLAGS unsigned long
#define _JATTA_PADEVICE_INFO void*
#define _JATTA_PAHOSTAPI_INFO void*

#if defined(WINDOWS) && !defined(MSVC)
#   define _WIN32_WINNT 0x0501
#endif

#if defined(JATTA_INCLUDES)
#   ifdef WINDOWS
#       define UNICODE
#       define _UNICODE
#       ifdef JATTA_USE_NETWORK
#           include <WinSock2.h>
#           include <Ws2tcpip.h>
#       endif
#       include <Windows.h>
#       ifdef JATTA_USE_OPENGL
#           include <GL/glew.h>
#       endif
#   endif
#   ifdef LINUX
#       include <X11/Xlib.h>
#       include <X11/Xlib.h>
#       include <X11/Xatom.h>
#       ifdef JATTA_USE_OPENGL
#           include <GL/glxew.h>
#           include <GL/glew.h>
#       endif
#   endif
#   ifdef MACOS
#       ifdef JATTA_USE_OPENGL
#           include <GL/glew.h>
#       endif
#       import <Cocoa/Cocoa.h>
#   endif
#   ifdef JATTA_USE_FREETYPE
#       include <ft2build.h>
#       include <freetype/freetype.h>
#       include <freetype/ftxf86.h>
#   endif
#   ifdef JATTA_USE_ASSIMP
#       include <assimp/cimport.h>
#       include <assimp/scene.h>
#       include <assimp/postprocess.h>
#   endif
#   ifdef JATTA_USE_AUDIO
#       include <portaudio.h>
#   endif
#   if defined(LINUX) | defined(MACOS)
#       include <arpa/inet.h>
#       include <errno.h>
#       include <fcntl.h>
#       include <netdb.h>
#       include <netinet/in.h>
#       include <netinet/tcp.h>
#       include <signal.h>
#       include <stdio.h>
#       include <stdlib.h>
#       include <string.h>
#       include <sys/socket.h>
#       include <sys/types.h>
#       include <sys/wait.h>
#       include <unistd.h>
#       define INVALID_SOCKET ~0
#       define SOCKET_ERROR -1
#   endif
#   define CHECK(x, y) static_assert(sizeof(x) == sizeof(y), "sizeof(" #x ") != sizeof(" #y ")");
#   ifdef WINDOWS
        CHECK(::HWND, _JATTA_HWND);
        CHECK(::DWORD, _JATTA_DWORD);
        CHECK(::PIXELFORMATDESCRIPTOR, _JATTA_PIXELFORMATDESCRIPTOR);
        CHECK(::HDC, _JATTA_HDC);
        CHECK(::HGLRC, _JATTA_HGLRC);
#   endif
#   ifdef LINUX
        CHECK(::Display*, _JATTA_DISPLAY);
        CHECK(::Window, _JATTA_WINDOW);
        CHECK(::GLXContext, _JATTA_GLXCONTEXT);
#   endif
#   ifdef JATTA_USE_ASSIMP
      CHECK(::FT_Face, _JATTA_FT_FACE);
      CHECK(::aiScene*, _JATTA_AISCENE);
      CHECK(::aiMesh*, _JATTA_AIMESH);
      CHECK(::aiTexture*, _JATTA_AITEXTURE);
      CHECK(::aiTexture*, _JATTA_AIMATERIAL);
#   endif
#   ifdef JATTA_USE_AUDIO
      CHECK(::PaStreamCallbackTimeInfo*, _JATTA_PASTREAM_CALLBACK_TIMEINFO);
      CHECK(::PaStreamCallbackFlags, _JATTA_PASTREAM_CALLBACK_FLAGS);
      CHECK(::PaDeviceInfo*, _JATTA_PADEVICE_INFO);
      CHECK(::PaHostApiInfo*, _JATTA_PAHOSTAPI_INFO);
#   endif
#   undef CHECK
#   include "Undefines.h"
#   ifdef WINDOWS
#       define _JATTA_HWND ::HWND
#       define _JATTA_DWORD ::DWORD
#       define _JATTA_PIXELFORMATDESCRIPTOR ::PIXELFORMATDESCRIPTOR
#       define _JATTA_HDC ::HDC
#       define _JATTA_HGLRC ::HGLRC
#    endif
#    ifdef LINUX
#       define _JATTA_DISPLAY ::Display*
#       define _JATTA_WINDOW ::Window
#       ifdef JATTA_USE_OPENGL
#           define _JATTA_GLXCONTEXT ::GLXContext
#       endif
#   endif
#   ifdef JATTA_USE_FREETYPE
#       define _JATTA_FT_FACE ::FT_Face
#   endif
#   ifdef JATTA_USE_ASSIMP
#       define _JATTA_AISCENE ::aiScene*
#       define _JATTA_AIMESH ::aiMesh*
#       define _JATTA_AITEXTURE ::aiTexture*
#       define _JATTA_AIMATERIAL ::aiMaterial*
#       define _JATTA_AICAMERA ::aiCamera*
#       define _JATTA_AIBONE ::aiBone*
#       define _JATTA_AIVERTEXWEIGHT ::aiVertexWeight*
#   endif
#   ifdef JATTA_USE_AUDIO
#        define _JATTA_PASTREAM ::PaStream*
#        define _JATTA_PASTREAM_CALLBACK_TIMEINFO ::PaStreamCallbackTimeInfo*
#        define _JATTA_PASTREAM_CALLBACK_FLAGS ::PaStreamCallbackFlags
#        define _JATTA_PADEVICE_INFO ::PaDeviceInfo*
#        define _JATTA_PAHOSTAPI_INFO ::PaHostApiInfo*
#   endif
#endif

#endif
