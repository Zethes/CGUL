# Macro to use a library
macro(use_library NAME SYSTEM)

    if(${SYSTEM})

        if(MSVC)

            list(APPEND INSTALL_LIBRARIES_SYSTEM "${NAME}.lib")

        else()

            list(APPEND INSTALL_LIBRARIES_SYSTEM "${NAME}")
        endif()

    else()

        list(APPEND INSTALL_LIBRARIES "${NAME}")

    endif()

endmacro()

# Macro to find Mac framework
macro(find_framework NAME)

    find_library(FRAMEWORK ${NAME})
    use_library(${FRAMEWORK} ON)
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

    use_library(Ws2_32 ON)
    use_library(Iphlpapi ON)

elseif(APPLE)

    find_framework(Carbon)
    find_framework(Cocoa)
    find_framework(ApplicationServices)

else()

    use_library(X11 ON)

endif()

# OpenGL
if(Jatta_USE_OPENGL)

    use_library(glew OFF)

    if(WIN32)

        use_library(opengl32 ON)

    elseif(APPLE)

        find_framework(OpenGL)

    else()

        use_library(GL ON)

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

# Assimp
if(Assimp_ENABLED)

    use_library(Assimp OFF)

    list(APPEND ACKNOWLEDGEMENTS
        "\n\n"
        "Open Asset Import Library http://assimp.sourceforge.net/\n"
        "Copyright (C) 2006-2012 assimp team\n"
        "All rights reserved."
    )

endif()

# FreeType
if(FreeType_ENABLED)

    use_library(FreeType OFF)

    list(APPEND ACKNOWLEDGEMENTS
        "\n\n"
        "FreeType http://www.freetype.org/\n"
        "Copyright (C) 1996-2002, David Turner, Robert Wilhelm, and Werner Lemberg"
    )

endif()

# JPEG
if(JPEG_ENABLED)

    use_library(JPEG OFF)

    list(APPEND ACKNOWLEDGEMENTS
        "\n\n"
        "libjpeg http://libjpeg.sourceforge.net/\n"
        "Copyright (C) 1991-2012, Thomas G. Lane, Guido Vollbeding."
    )

endif()

# PNG
if(PNG_ENABLED)

    use_library(PNG OFF)
    use_library(zlib OFF)

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

# PortAudio
if(PortAudio_ENABLED)

    use_library(PortAudio OFF)

    if(WIN32)

        use_library(WinMM ON)

    elseif(APPLE)

        find_framework(CoreAudio)
        find_framework(AudioToolbox)
        find_framework(AudioUnit)

    else()

        use_library(asound ON)

    endif()

    list(APPEND ACKNOWLEDGEMENTS
        "\n\n"
        "PortAudio Portable Real-Time Audio Library http://www.portaudio.com/\n"
        "Copyright (C) 1999-2011 Ross Bencina, Phil Burk"
    )

endif()

# PCRE
if(PCRE_ENABLED)

    use_library(PCRE OFF)

    list(APPEND ACKNOWLEDGEMENTS
        "\n\n"
        "Perl Compatible Regular Expression http://www.pcre.org/\n"
        "Copyright (C) 1997-2013 University of Cambridge\n"
        "Copyright (C) 2009-2013 Foltan Herczeg\n"
        "All rights reserved."
    )

endif()

# OpenSSL
if(OpenSSL_ENABLED)

    use_library(OpenSSL OFF)

    list(APPEND ACKNOWLEDGEMENTS
        "\n\n"
        "OpenSSL - Open Secure Sockets Layer http://www.openssl.org/\n"
        "Copyright (C) 1999-2013 The OpenSSL Project\n"
        "Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)\n"
        "All rights reserved."
    )

endif()

# Crypto
if(Crypto_ENABLED)

    use_library(Crypto OFF)

    list(APPEND ACKNOWLEDGEMENTS
        "\n\n"
        "OpenSSL - Crypto http://www.openssl.org/\n"
        "Copyright (C) 1999-2013 The OpenSSL Project\n"
        "Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)\n"
        "All rights reserved."
    )

endif()

list(APPEND ACKNOWLEDGEMENTS
    "\n\n"
    "The libraries above are released under absolutely no warranty."
)

string(REPLACE ";" "" ACKNOWLEDGEMENTS ${ACKNOWLEDGEMENTS})
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/acknowledgements.txt.in" "${CMAKE_CURRENT_BINARY_DIR}/acknowledgements.txt")
