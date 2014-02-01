![alt text](https://raw.github.com/Zethes/CGUL/master/resources/logo.png "CGUL Logo")  
Celebrating a  year on GitHub :tada:

What is it?
=====
CGUL (formerly Jatta) is a General Utility Library for C++.  CGUL is partially a thin wrapper between popular C libraries, but also uses and abuses the C++ syntax to extend the language.  CGUL's goal is to be compliant with C++ standards instead of C standards.  CGUL takes an object-oriented approach to common problems.  Error checking occurs through exceptions and classes are RAII compliant.  No error goes unchecked.

Features
=====

#### _All features are heavily work-in-progress and experimental. Don't expect things to work._

- **Cross-platform**
  - Windows is mostly supported through MinGW
  - Tested with Mac OS X 10.6
  - Linux requires X11 for windows and ALSA for audio (common in most distros)
- **CMake build system**
  - Supports most CMake generators on all supported platforms
- **Powerful Assimp library wrapper to load in 3D models and scenes**
- **File system**
- **Font loading via FreeType**
- **Simplified image loading/saving**
  - Bitmap
  - PNG with libpng
  - Jpeg with libjpeg
  - DDS
- **Mathematics library**
  - Matrices, quaternions, and vectors for 3D worlds
  - Linear congruential generator (RNG)
  - Probability distributions
  - Many common mathematic functions
- **Simplified networking**
  - TCP Sockets
  - UDP Sockets
  - DNS Lookup
  - SSL/TLS Support via OpenSSL
  - Query local network interfaces
- **Object oriented OpenGL wrapper**
- **Window system on Windows (WinAPI), MacOS (Cocoa) and Linux (X11)**
- **Utf-8 everywhere**
- **Easy to use PortAudio wrapper**
- **A very liberal [license](https://github.com/Zethes/CGUL/blob/master/license.md)***

<i>* CGUL and the libraries required to build CGUL are released under very unrestricting licenses for your convenience and freedom as a developer. Please consider uprooting all your improvements to the [respective developers](http://www.zethes.com/cgul/doxygen/acknowledgements.html).  Thanks!</i>

Ubuntu Packages
=====
- libx11-dev (for x11 windows)
- libgl1-mesa-dev (for opengl)
- libasound2-dev (for audio)
