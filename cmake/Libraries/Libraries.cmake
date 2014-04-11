include(CheckIncludeFileCXX)

# Assimp
list(APPEND CGUL_LIBRARY_LIST Assimp)
set(Assimp_NAMES Assimp)

# FreeType
list(APPEND CGUL_LIBRARY_LIST FreeType)
set(FreeType_NAMES freetype)

# glew
list(APPEND CGUL_LIBRARY_LIST glew)
set(glew_NAMES glew glew32 glew32s GLEW)

# JPEG
list(APPEND CGUL_LIBRARY_LIST JPEG)
set(JPEG_NAMES jpeg)

# PNG
list(APPEND CGUL_LIBRARY_LIST PNG)
set(PNG_NAMES png libpng png16 libpng16 png15 libpng15 png14 libpng14 png12 libpng12)

# zlib
list(APPEND CGUL_LIBRARY_LIST zlib)
set(zlib_NAMES z zlib)

# PortAudio
list(APPEND CGUL_LIBRARY_LIST PortAudio)
set(PortAudio_NAMES portaudio)

# PCRE
list(APPEND CGUL_LIBRARY_LIST PCRE)
set(PCRE_NAMES pcre)

# OpenSSL
list(APPEND CGUL_LIBRARY_LIST OpenSSL)
set(OpenSSL_NAMES ssl)

# Crypto
list(APPEND CGUL_LIBRARY_LIST Crypto)
set(Crypto_NAMES crypto)

# ALSA (Linux Only)
if("${System_TYPE_LOWER}" STREQUAL "linux")
    list(APPEND CGUL_LIBRARY_LIST ALSA)
    set(ALSA_NAMES asound)
endif()

# pthread
list(APPEND CGUL_LIBRARY_LIST pthread)
set(pthread_NAMES pthread)

# Try to find each library
foreach(__LIBRARY ${CGUL_LIBRARY_LIST})

    if(NOT DEFINED ${__LIBRARY}_ENABLED OR
       NOT DEFINED ${__LIBRARY}_LIBRARY OR
       NOT DEFINED ${__LIBRARY}_SHARED  OR
       NOT DEFINED ${__LIBRARY}_PACKAGE )

        message(STATUS "Looking for library ${__LIBRARY}")

        # Clear cache
        unset(${__LIBRARY}_LIBRARY CACHE)
        unset(${__LIBRARY}_SHARED  CACHE)
        unset(${__LIBRARY}_PACKAGE CACHE)

        # Find the library
        find_library(${__LIBRARY}_LIBRARY NAMES ${${__LIBRARY}_NAMES} PATHS ${CGUL_DEPENDENCY_LIBRARY_DIRS})

        # Check if the library was found
        if(${__LIBRARY}_LIBRARY)

            # Library was found
            if(NOT DEFINED ${__LIBRARY}_ENABLED)
                set(${__LIBRARY}_ENABLED ON)
            endif()

            # Detect if library is static or shared based on file extension
            get_filename_component(__EXTENSION ${${__LIBRARY}_LIBRARY} EXT)
            string(TOLOWER "${__EXTENSION}" __EXTENSION)
            if("${__EXTENSION}" STREQUAL ".a" OR "${__EXTENSION}" STREQUAL ".lib")

                # Static library
                set(${__LIBRARY}_SHARED  OFF)
                set(${__LIBRARY}_PACKAGE ON)

            else()

                # Shared library
                set(${__LIBRARY}_SHARED  ON)
                set(${__LIBRARY}_PACKAGE OFF)

            endif()

        else()

            # Library wasn't found
            if(NOT DEFINED ${__LIBRARY}_ENABLED)
                set(${__LIBRARY}_ENABLED OFF)
            endif()

        endif()

        # Save to cache
        set(${__LIBRARY}_ENABLED ${${__LIBRARY}_ENABLED} CACHE BOOL "")
        set(${__LIBRARY}_SHARED  ${${__LIBRARY}_SHARED}  CACHE BOOL "")
        set(${__LIBRARY}_PACKAGE ${${__LIBRARY}_PACKAGE} CACHE BOOL "")

        # Allow different configurations to use different libraries
        foreach(__CONFIGURATION ${CMAKE_CONFIGURATION_TYPES})

            string(TOUPPER "${__CONFIGURATION}" __CONFIGURATION)
            set(${__LIBRARY}_LIBRARY_${__CONFIGURATION} "" CACHE STRING "")

        endforeach()

        # Disable result message
        if(${__LIBRARY}_LIBRARY)

            message(STATUS "Looking for library ${__LIBRARY} - found")

        else()

            message(STATUS "Looking for library ${__LIBRARY} - not found")

        endif()

    endif()

    # Cause an error if enabled and not found
    if(${__LIBRARY}_ENABLED AND NOT ${__LIBRARY}_LIBRARY)

        message(SEND_ERROR "Library ${__LIBRARY} is enabled but cannot be found.")

    endif()

    # Build the test source file to check compatibility
    if(${__LIBRARY}_ENABLED)

        try_compile(__COMPILED
          ${CMAKE_BINARY_DIR}
          ${CMAKE_CURRENT_SOURCE_DIR}/cmake/Libraries/${__LIBRARY}.cpp
          COMPILE_DEFINITIONS ${CMAKE_REQUIRED_DEFINITIONS}
          CMAKE_FLAGS
          -DCOMPILE_DEFINITIONS:STRING=${CMAKE_REQUIRED_FLAGS}
          "-DINCLUDE_DIRECTORIES=${CMAKE_REQUIRED_INCLUDES}"
          OUTPUT_VARIABLE __OUTPUT)

        if(NOT __COMPILED)

            # Write compilation error to the cmake error log
            file(APPEND ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/CMakeError.log
              "Unable to compile package test script for ${__LIBRARY}!\n"
              "The test file ${__LIBRARY}.cpp failed to compile:\n"
              "${__OUTPUT}\n\n"
            )

            # Warn the user
            if(${__LIBRARY}_ENABLED)

                message(SEND_ERROR "Using an incompatible ${__LIBRARY} library (might be missing the header files).")

            endif()

        endif()

    endif()

    # For Config.h
    if(${__LIBRARY}_ENABLED)

        set(${__LIBRARY}_FOUND ON)

    endif()

endforeach()

# We either want both zlib and png, or neither
if(PNG_ENABLED AND NOT zlib_ENABLED)

    message(SEND_ERROR "Cannot use libpng without zlib.")

elseif(NOT PNG_ENABLED)

    set(zlib_ENABLED OFF)

endif()

# Create the library targets
foreach(__LIBRARY ${CGUL_LIBRARY_LIST})

    if(${__LIBRARY}_ENABLED)

        # Add to the list of libraries
        list(APPEND CGUL_LIBRARIES ${__LIBRARY})

        # Create the correct type of library
        if(${__LIBRARY}_SHARED)

            add_library(${__LIBRARY} SHARED IMPORTED)

        else()

            add_library(${__LIBRARY} STATIC IMPORTED)

        endif()

        # Set the default imported location
        list(APPEND __PROPERTIES IMPORTED_LOCATION "${${__LIBRARY}_LIBRARY}")

        # Set the import locations for each configuration
        foreach(__CONFIGURATION ${CMAKE_CONFIGURATION_TYPES})

            # Add the property if it exists
            string(TOUPPER "${__CONFIGURATION}" __CONFIGURATION)
            if(${__LIBRARY}_LIBRARY_${__CONFIGURATION})

                list(APPEND __PROPERTIES IMPORTED_LOCATION_${__CONFIGURATION} "${${__LIBRARY}_LIBRARY_${__CONFIGURATION}}")

            endif()

        endforeach()

        # Apply the properties
        set_target_properties(${__LIBRARY} PROPERTIES ${__PROPERTIES})

    endif()

endforeach()

function(cgul_define_feature NAME DOC)
    set(ENABLED ON)
    foreach(dependency ${ARGN})
        if(NOT ${dependency}_ENABLED)
            set(ENABLED OFF)
        endif()
    endforeach()
    set(${NAME} ${ENABLED} CACHE BOOL ${DOC})
endfunction()

macro(cgul_common_library LIBRARY)
    set(CGUL_COMMON_LIBRARIES ${CGUL_COMMON_LIBRARIES} ${LIBRARY})
endmacro()
