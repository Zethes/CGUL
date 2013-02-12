# TODO: exclude libraries if they are excluded from the build

SET(JATTA_ACKNOWLEDGEMENTS "This software utilizies the following libraries:!ACKNOWLEDGEMENTS!" CACHE STRING "The outputted acknowledgements string.")

LIST(APPEND ACKNOWLEDGEMENTS
"\n
Jatta - General Utility Library
Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall"
)

LIST(APPEND ACKNOWLEDGEMENTS
"\n
libpng http://www.libpng.org/ 
Copyright (C) 1998-2012, Glenn Randers-Pehrson
Copyright (C) 1996-1997, Andreas Dilger
Copyright (C) 1995-1996, Guy Eric Schalnat, Group 42, Inc.

zlib http://www.zlib.net/ 
Copyright (C) 1995-2012, Jean-loup Gailly and Mark Adler"
)

LIST(APPEND ACKNOWLEDGEMENTS
"\n
The OpenGL Extension Wrangler Library http://glew.sourceforge.net/ 
Copyright (C) 2002-2007, Milan Ikits <milan ikits[]ieee org>
Copyright (C) 2002-2007, Marcelo E. Magallon <mmagallo[]debian org>
Copyright (C) 2002, Lev Povalahev
All rights reserved."
)

LIST(APPEND ACKNOWLEDGEMENTS
"\n
libjpeg http://libjpeg.sourceforge.net/ 
Copyright (C) 1991-2012, Thomas G. Lane, Guido Vollbeding."
)

LIST(APPEND ACKNOWLEDGEMENTS
"\n
FreeType http://www.freetype.org/ 
Copyright (C) 1996-2002, David Turner, Robert Wilhelm, and Werner Lemberg"
)

LIST(APPEND ACKNOWLEDGEMENTS
"\n
Open Asset Import Library http://assimp.sourceforge.net/ 
Copyright (C) 2006-2012 assimp team
All rights reserved."
)

LIST(APPEND ACKNOWLEDGEMENTS
"\n
PortAudio Portable Real-Time Audio Library http://www.portaudio.com/
Copyright (C) 1999-2011 Ross Bencina, Phil Burk

PulseAudio Implementation for PortAudio https://github.com/bkgood/portaudio-pulseaudio
Copyright (C) 2011 William 'Bill' Good"
)

STRING(REPLACE ";" "" ACKNOWLEDGEMENTS ${ACKNOWLEDGEMENTS})

STRING(REPLACE "!ACKNOWLEDGEMENTS!" "${ACKNOWLEDGEMENTS}" ACKNOWLEDGEMENTS ${JATTA_ACKNOWLEDGEMENTS})

STRING(REPLACE "@n" "\n" ACKNOWLEDGEMENTS ${ACKNOWLEDGEMENTS})

CONFIGURE_FILE("acknowledgements.txt.in" "acknowledgements.txt")