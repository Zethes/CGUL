/*#define _JATTA_HWND_SIZE 4
#define _JATTA_DWORD_SIZE 4
#define _JATTA_PIXELFORMATDESCRIPTOR_SIZE 40
#define _JATTA_FT_FACE_SIZE 4

#if defined(JATTA_INCLUDES)
#  include <Windows.h>
#  include <ft2build.h>
#  include <freetype/freetype.h>
#  include <freetype/ftxf86.h>
#  define CHECK(x, y) static_assert(sizeof(x) == y, ":( </3");
   CHECK(HWND, _JATTA_HWND_SIZE);
   CHECK(DWORD, _JATTA_DWORD_SIZE);
   CHECK(PIXELFORMATDESCRIPTOR, _JATTA_PIXELFORMATDESCRIPTOR_SIZE);
   CHECK(FT_Face, _JATTA_FT_FACE_SIZE);
#  undef CHECK
#  include "JattaUndefines.h"
#  define _JATTA_HWND(x) HWND x
#  define _JATTA_DWORD(x) DWORD x
#  define _JATTA_PIXELFORMATDESCRIPTOR(x) PIXELFORMATDESCRIPTOR x
#  define _JATTA_FT_FACE(x) FT_Face x
#else
#  define _JATTA_HWND(x) char x[_JATTA_HWND_SIZE]
#  define _JATTA_DWORD(x) char x[_JATTA_HWND_SIZE]
#  define _JATTA_PIXELFORMATDESCRIPTOR(x) char x[_JATTA_HWND_SIZE]
#  define _JATTA_FT_FACE(x) char x[_JATTA_HWND_SIZE]
#endif*/


#define _JATTA_HWND_SIZE 4
#define _JATTA_DWORD_SIZE 4
#define _JATTA_PIXELFORMATDESCRIPTOR_SIZE 40
#define _JATTA_FT_FACE_SIZE 4

#if defined(JATTA_INCLUDES)
#  include <Windows.h>
#  include <ft2build.h>
#  include <freetype/freetype.h>
#  include <freetype/ftxf86.h>
#  define CHECK(x, y) static_assert(sizeof(x) == y, ":( </3");
   CHECK(HWND, _JATTA_HWND_SIZE);
   CHECK(DWORD, _JATTA_DWORD_SIZE);
   CHECK(PIXELFORMATDESCRIPTOR, _JATTA_PIXELFORMATDESCRIPTOR_SIZE);
   CHECK(FT_Face, _JATTA_FT_FACE_SIZE);
#  undef CHECK
#  include "JattaUndefines.h"
#  define _JATTA_HWND(x) HWND x
#  define _JATTA_DWORD(x) DWORD x
#  define _JATTA_PIXELFORMATDESCRIPTOR(x) PIXELFORMATDESCRIPTOR x
#  define _JATTA_FT_FACE(x) FT_Face x
#else
#  define _JATTA_HWND(x) char x[_JATTA_HWND_SIZE]
#  define _JATTA_DWORD(x) char x[_JATTA_HWND_SIZE]
#  define _JATTA_PIXELFORMATDESCRIPTOR(x) char x[_JATTA_HWND_SIZE]
#  define _JATTA_FT_FACE(x) char x[_JATTA_HWND_SIZE]