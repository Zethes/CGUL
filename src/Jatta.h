#pragma once

#if !defined(WINDOWS) and !defined(LINUX) and !defined(MACOS)
#  if defined(_WIN32)
#    define WINDOWS
#  elif defined(__APPLE__)
#    define MACOS
#  elif defined(unix)
#    define LINUX
#  else
#    error Failed to automatically detected operating system.  Must define WINDOWS, LINUX, or MACOS on the command line.
#  endif
#endif

// Standard Template Library
#include <array>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>