/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Once.h"

#ifdef WINDOWS
#  define _JATTA_HWND void*
#  define _JATTA_DWORD long
#  define _JATTA_PIXELFORMATDESCRIPTOR std::array<char, 40>
#  define _JATTA_HDC int
#  define _JATTA_HGLRC int
#endif

#ifdef LINUX
#  define _JATTA_DISPLAY void*
#  define _JATTA_WINDOW void*
#  define _JATTA_GLXCONTEXT void*
#endif

#define _JATTA_FT_FACE void*

#if defined(JATTA_INCLUDES)
#  ifdef WINDOWS
#    define UNICODE
#    define _UNICODE
#    include <Windows.h>
#    include <GL/glew.h>
#  endif
#  ifdef LINUX
#    include <X11/Xlib.h>
#    include <GL/glxew.h>
#    include <GL/glew.h>
#  endif
#  ifdef MACOS
#    import <Cocoa/Cocoa.h>
#    import <OpenGL/GL.h>
#    define glGenVertexArrays(x, y) glGenVertexArraysAPPLE(x, y)
#    define glBindVertexArray(x) glBindVertexArrayAPPLE(x)
#  endif
#  include <ft2build.h>
#  include <freetype/freetype.h>
#  include <freetype/ftxf86.h>
#  define CHECK(x, y) //static_assert(sizeof(x) == sizeof(y), "sizeof(" #x ") != sizeof(" #y ")");
#  ifdef WINDOWS
     CHECK(::HWND, _JATTA_HWND);
     CHECK(::DWORD, _JATTA_DWORD);
     CHECK(::PIXELFORMATDESCRIPTOR, _JATTA_PIXELFORMATDESCRIPTOR);
     CHECK(::HDC, _JATTA_HDC);
     CHECK(::HGLRC, _JATTA_HGLRC);
#  endif
#  ifdef LINUX
     CHECK(::Display*, _JATTA_DISPLAY);
     CHECK(::Window, _JATTA_WINDOW);
     CHECK(::GLXContext, _JATTA_GLXCONTEXT);
#  endif
   CHECK(::FT_Face, _JATTA_FT_FACE);
#  undef CHECK
#  include "Undefines.h"
#  ifdef WINDOWS
#    define _JATTA_HWND ::HWND
#    define _JATTA_DWORD ::DWORD
#    define _JATTA_PIXELFORMATDESCRIPTOR ::PIXELFORMATDESCRIPTOR
#    define _JATTA_HDC ::HDC
#    define _JATTA_HGLRC ::HGLRC
#  endif
#  ifdef LINUX
#    define _JATTA_DISPLAY ::Display*
#    define _JATTA_WINDOW ::Window
#    define _JATTA_GLXCONTEXT ::GLXContext
#  endif
#  define _JATTA_FT_FACE ::FT_Face
#endif