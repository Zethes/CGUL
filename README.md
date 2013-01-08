Jatta
=====

General Utility Library
Learn more at [our website](http://jatta.zethes.com/).

Building
=====

In order to build Jatta you will need the following libraries:

* libfreetype.a
* libglew.a (*not required on mac*)
* libjpeg.a
* libpng15.a
* libz.a

We'll add better support for finding these libraries later.  For now create a directory in the root Jatta directory, call it dep and create two more directories in there called "lib" and "include" so it looks like this:

<pre>
Jatta/dep/include
Jatta/dep/lib
</pre>

Put the library files in the lib folder and the necessary includes in the include folder.

Hopefully this process will be streamlined in the future but for now this is what we're working with!

Once you have the libraries you can build using CMake.

Make the build directory:
<pre>
mkdir build
cd build
</pre>

Linux:
<pre>
cmake -G "Unix Makefiles" ..
</pre>

MinGW:
<pre>
cmake -G "MSYS Makefiles" ..
</pre>

Visual Studio:
<pre>
cmake -G "Visual Studio 10" ..
</pre>

Then build as normal.  For MinGW/Linux type "make."  For Visual Studio open the sln file.  Mac instructions coming eventually!

Windows
-----
We officially support Windows builds with MinGW.  It is also possible to build with Visual Studio but you still must have the MinGW runtimes installed.  Copy these library files into the Jatta/dep/lib directory if you wish to build with Visual Studio:

* libmingwex.a
* libgcc.a
