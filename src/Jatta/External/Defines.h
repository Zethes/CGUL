/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Once.h"

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

#if defined(JATTA_INCLUDES)
#   ifdef WINDOWS
#       define UNICODE
#       define _UNICODE
#       include <Windows.h>
#       ifdef JATTA_GRAPHICS
#           include <GL/glew.h>
#       endif
#   endif
#   ifdef LINUX
#       include <X11/Xlib.h>
#       ifdef JATTA_GRAPHICS
#           include <GL/glxew.h>
#           include <GL/glew.h>
#       endif
#   endif
#   ifdef MACOS
#       import <Cocoa/Cocoa.h>
#       ifdef JATTA_GRAPHICS
#           import <OpenGL/GL.h>
#           define glGenVertexArrays(x, y) glGenVertexArraysAPPLE(x, y)
#           define glBindVertexArray(x) glBindVertexArrayAPPLE(x)
#           define glDeleteVertexArrays(x, y) glDeleteVertexArraysAPPLE(x, y)
#       endif
#   endif
#   ifdef JATTA_FONTS
#       include <ft2build.h>
#       include <freetype/freetype.h>
#       include <freetype/ftxf86.h>
#   endif
#   ifdef JATTA_ASSIMP
#       include <assimp/cimport.h>
#       include <assimp/scene.h>
#       include <assimp/postprocess.h>
#   endif
#   define CHECK(x, y) //static_assert(sizeof(x) == sizeof(y), "sizeof(" #x ") != sizeof(" #y ")");
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
      CHECK(::FT_Face, _JATTA_FT_FACE);
      CHECK(::aiScene*, _JATTA_AISCENE);
      CHECK(::aiMesh*, _JATTA_AIMESH);
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
#       ifdef JATTA_GRAPHICS
#           define _JATTA_GLXCONTEXT ::GLXContext
#       endif
#   endif
#   ifdef JATTA_FONTS
#       define _JATTA_FT_FACE ::FT_Face
#   endif
#   ifdef JATTA_ASSIMP
#       define _JATTA_AISCENE ::aiScene*
#       define _JATTA_AIMESH ::aiMesh*
#   endif
#endif