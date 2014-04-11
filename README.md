![alt text](https://raw.github.com/Zethes/CGUL/master/resources/logo.png "CGUL Logo")  
Thanks to [Mordi](http://mordi.ziphoid.com/) for the sweet logo

What is it?
=====
The C++ General Utility Library (CGUL, formerly Jatta) is a multi-purpose "hybrid" library aiming to aid in a variety of problems, with a consistent feel throughout the codebase.  The CGUL developers are avid gamers so much of the library is focused around game development.  CGUL is partially a thin wrapper between popular C libraries, but also uses and abuses the C++ syntax to extend the language.  CGUL's goal is to be compliant with C++ standards instead of C standards.  CGUL takes an object-oriented approach to common problems.  Error checking occurs through exceptions and classes are RAII compliant.  No error goes unchecked.

Disclaimer
=====
CGUL is only used by a handful of developers and lacks the support to advertise true reliability and completeness in the API.  If you are interested in the project, please get in touch with us at cgul@zethes.com.  We are interested in hearing your feedback.  We do use the GitHub Issue tracker and Pull Request system, both are welcome.

To get a feel for what is left to do, visit our [Issues](https://github.com/Zethes/CGUL/issues) page.

Features
=====

- **Cross-platform**
  - Windows build tested with MinGW 4.7 and Visual Studio 10
  - Tested with Mac OS 10.6.8, GCC 4.2 and Clang 3.2
  - Linux requires X11 for windows and ALSA for audio (common in most distros)
- **CMake build system**
  - Unix Makefiles
  - Visual Studio 10/11
  - Xcode
  - Ninja
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
- **Window system on Windows (WinAPI), MacOS (Cocoa) and Linux (X11)**
- **Utf-8 everywhere**
- **PortAudio wrapper**
- **A very liberal [license](https://github.com/Zethes/CGUL/blob/master/license.md)***

<i>* CGUL and the libraries required to build CGUL are released under very unrestricting licenses for your convenience and freedom as a developer. Please consider uprooting all your improvements to the [respective developers](http://www.zethes.com/cgul/doxygen/acknowledgements.html).  Thanks!</i>

Ubuntu Packages
=====
- libx11-dev (for x11 windows)
- libgl1-mesa-dev (for opengl)
- libasound2-dev (for audio)
