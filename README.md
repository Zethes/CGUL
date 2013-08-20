![Jatta](https://raw.github.com/Zethes/Jatta/master/resources/logo.png)

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
- **3D mathematics library**
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
- **A very liberal [license](https://github.com/Zethes/Jatta/blob/master/license.md)***

<i>* Jatta and the libraries required to build Jatta are released under very unrestricting licenses for your convenience and freedom as a developer. Please consider uprooting all your improvements to the [respective developers](http://jatta.zethes.com/acknowledgements.html).  Thanks!</i>

Ubuntu Packages
=====
- libx11-dev (for x11 windows)
- libgl1-mesa-dev (for opengl)
- libasound2-dev (for audio)
