/* Jatta - General Utility Library
 * Copyright (c) 2012-2013, Joshua Brookover
 * All rights reserved.
 */

#ifdef WINDOWS
#  undef _JATTA_HWND
#  undef _JATTA_DWORD
#  undef _JATTA_PIXELFORMATDESCRIPTOR
#  undef _JATTA_HDC
#  undef _JATTA_HGLRC
#endif

#ifdef LINUX
#  undef _JATTA_DISPLAY
#  undef _JATTA_WINDOW
#  undef _JATTA_GLXCONTEXT
#endif

#undef _JATTA_FT_FACE
