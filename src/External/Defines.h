#include "../Jatta.h"

#define _JATTA_HWND void*
#define _JATTA_DWORD long
#define _JATTA_PIXELFORMATDESCRIPTOR std::array<char, 40>
#define _JATTA_HDC int
#define _JATTA_HGLRC int
#define _JATTA_FT_FACE int

#if defined(JATTA_INCLUDES)
#  include <Windows.h>
#  include <ft2build.h>
#  include <freetype/freetype.h>
#  include <freetype/ftxf86.h>
#  define CHECK(x, y) static_assert(sizeof(x) == sizeof(y), ":( </3");
   CHECK(HWND, _JATTA_HWND);
   CHECK(DWORD, _JATTA_DWORD);
   CHECK(PIXELFORMATDESCRIPTOR, _JATTA_PIXELFORMATDESCRIPTOR);
   CHECK(HDC, _JATTA_HDC);
   CHECK(HGLRC, _JATTA_HGLRC);
   CHECK(FT_Face, _JATTA_FT_FACE);
#  undef CHECK
#  include "Undefines.h"
#  define _JATTA_HWND HWND
#  define _JATTA_DWORD DWORD
#  define _JATTA_PIXELFORMATDESCRIPTOR PIXELFORMATDESCRIPTOR
#  define _JATTA_HDC HDC
#  define _JATTA_HGLRC HGLRC
#  define _JATTA_FT_FACE FT_Face
#endif

