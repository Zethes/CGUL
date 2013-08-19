# Macro to use a library
macro(use_library NAME LIBRARY SYSTEM)
    if(${SYSTEM} AND MSVC)
        list(APPEND Jatta_LIBRARIES "general ${LIBRARY}.lib ")
    else()
        list(APPEND Jatta_LIBRARIES "${LIBRARY} ")
    endif()
    if(${SYSTEM})
        set(SYSTEM_LIBRARIES "${SYSTEM_LIBRARIES} ${LIBRARY}")
    elseif(DEFINED ${NAME}_SHARED)
        if(DEFINED STATIC_LIBRARIES)
            set(STATIC_LIBRARIES "${STATIC_LIBRARIES};${NAME}")
        else()
            set(STATIC_LIBRARIES "${NAME}")
        endif()
    endif()
endmacro()

# Macro to find Mac framework
macro(find_framework NAME)
    find_library(FRAMEWORK ${NAME})
    use_library(${NAME} ${FRAMEWORK} ON)
    unset(FRAMEWORK CACHE)
endmacro()

# Keep track of acknowledgements
LIST(APPEND ACKNOWLEDGEMENTS
    "This software utilizies the following libraries:\n\n"
    "Jatta http://jatta.zethes.com/\n"
    "Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall"
)

# System generic libraries
if(WIN32)
    use_library(WinSock2 Ws2_32 ON)
    use_library(Iphlpapi Iphlpapi ON)
elseif(APPLE)
    find_framework(Carbon)
    find_framework(Cocoa)
    find_framework(ApplicationServices)
else()
    use_library(X11 X11 ON)
endif()

# OpenGL
if(Jatta_USE_OPENGL)
    use_library(glew ${glew_LINK} OFF)
    if(WIN32)
        use_library(OpenGL opengl32 ON)
    elseif(APPLE)
        find_framework(OpenGL)
    else()
        use_library(OpenGL GL ON)
    endif()

    list(APPEND ACKNOWLEDGEMENTS
        "\n\n"
        "The OpenGL Extension Wrangler Library http://glew.sourceforge.net/\n"
        "Copyright (C) 2002-2007, Milan Ikits <milan ikits[]ieee org>\n"
        "Copyright (C) 2002-2007, Marcelo E. Magallon <mmagallo[]debian org>\n"
        "Copyright (C) 2002, Lev Povalahev\n"
        "All rights reserved."
    )
endif()

# Imported libraries
if(Assimp_FOUND)
    use_library(Assimp ${Assimp_LINK} OFF)

    list(APPEND ACKNOWLEDGEMENTS
        "\n\n"
        "Open Asset Import Library http://assimp.sourceforge.net/\n"
        "Copyright (C) 2006-2012 assimp team\n"
        "All rights reserved."
    )
endif()
if(FreeType_FOUND)
    use_library(FreeType ${FreeType_LINK} OFF)

    list(APPEND ACKNOWLEDGEMENTS
        "\n\n"
        "FreeType http://www.freetype.org/\n"
        "Copyright (C) 1996-2002, David Turner, Robert Wilhelm, and Werner Lemberg"
    )
endif()
if(JPEG_FOUND)
    use_library(JPEG ${JPEG_LINK} OFF)

    list(APPEND ACKNOWLEDGEMENTS
        "\n\n"
        "libjpeg http://libjpeg.sourceforge.net/\n"
        "Copyright (C) 1991-2012, Thomas G. Lane, Guido Vollbeding."
    )
endif()
if(PNG_FOUND)
    use_library(PNG ${PNG_LINK} OFF)
    use_library(zlib ${zlib_LINK} OFF)

    list(APPEND ACKNOWLEDGEMENTS
        "\n\n"
        "libpng http://www.libpng.org/\n"
        "Copyright (C) 1998-2012, Glenn Randers-Pehrson\n"
        "Copyright (C) 1996-1997, Andreas Dilger\n"
        "Copyright (C) 1995-1996, Guy Eric Schalnat, Group 42, Inc.\n"
        "\n"
        "zlib http://www.zlib.net/\n"
        "Copyright (C) 1995-2012, Jean-loup Gailly and Mark Adler"
    )
endif()
if(PortAudio_FOUND)
    use_library(PortAudio ${PortAudio_LINK} OFF)
    if(WIN32)
        use_library(WinMM winmm ON)
    elseif(APPLE)
        find_framework(CoreAudio)
        find_framework(AudioToolbox)
        find_framework(AudioUnit)
    else()
        use_library(asound asound ON)
    endif()

    list(APPEND ACKNOWLEDGEMENTS
        "\n\n"
        "PortAudio Portable Real-Time Audio Library http://www.portaudio.com/\n"
        "Copyright (C) 1999-2011 Ross Bencina, Phil Burk"
    )
endif()
if(PCRE_FOUND)
    use_library(PCRE ${PCRE_LINK} OFF)

    list(APPEND ACKNOWLEDGEMENTS
        "\n\n"
        "Perl Compatible Regular Expression http://www.pcre.org/\n"
        "Copyright (C) 1997-2013 University of Cambridge\n"
        "Copyright (C) 2009-2013 Foltan Herczeg\n"
        "All rights reserved."
    )
endif()

#if(OpenSSL_FOUND)
#    use_library(OpenSSL ${OpenSSL_LINK} OFF)
#
#    list(APPEND ACKNOWLEDGEMENTS
#        "\n\n"
#        "OpenSSL - Open Secure Sockets Layer http://www.openssl.org/\n"
#        "Copyright (C) 1999-2013 The OpenSSL Project\n"
#        "Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)\n"
#        "All rights reserved."
#    )
#endif()

#if(Crypto_FOUND)
#    use_library(Crypto ${Crypto_LINK} OFF)
#
#    list(APPEND ACKNOWLEDGEMENTS
#        "\n\n"
#        "OpenSSL - Crypto http://www.openssl.org/\n"
#        "Copyright (C) 1999-2013 The OpenSSL Project\n"
#        "Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)\n"
#        "All rights reserved."
#    )
#endif()

list(APPEND ACKNOWLEDGEMENTS
    "\n\n"
    "The libraries above are released under absolutely no warranty."
)

string(REPLACE ";" "" ACKNOWLEDGEMENTS ${ACKNOWLEDGEMENTS})
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/acknowledgements.txt.in" "${CMAKE_CURRENT_BINARY_DIR}/acknowledgements.txt")
