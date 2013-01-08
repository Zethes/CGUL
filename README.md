Jatta
=====

General Utility Library
Learn more at [our website](http://jatta.zethes.com/).

Building
=====

In order to build Jatta you will need the following libraries:

<il>
<li>libfreetype.a</li>
<li>libglew.a (*not required on mac*)</li>
<li>libjpeg.a</li>
<li>libpng15.a</li>
<li>libz.a</li>
</il>

We'll add better support for finding these libraries later.  For now create a directory in the root Jatta directory, call it dep and create two more directories in there called "lib" and "include" so it looks like this:
<il>
<li>Jatta/dep/include</li>
<li>Jatta/dep/lib</li>
</il>

Put the library files in the lib folder and the necessary includes in the include folder.

Hopefully this process will be streamlined in the future but for now this is what we're working with!

Once you have the libraries you can build using CMake.

Make the build directory:
> mkdir build
> cd build

Linux:
> cmake -G "Unix Makefiles" ..

MinGW:
> cmake -G "MSYS Makefiles" ..

Visual Studio:
> cmake -G "Visual Studio 10" ..

Then build as normal.  For MinGW/Linux type "make."  For Visual Studio open the sln file.  Mac instructions coming eventually!

Windows
-----
We officially support Windows builds with MinGW.  It is also possible to build with Visual Studio but you still must have the MinGW runtimes installed.  Copy these library files into the Jatta/dep/lib directory if you wish to build with Visual Studio:
<il>
<li>libmingwex.a</li>
<li>libgcc.a</li>
</il>
