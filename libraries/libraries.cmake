include(CheckIncludeFileCXX)

macro(jatta_find_library VARIABLE)
    find_library(${VARIABLE} NAMES ${ARGN} PATHS ${Jatta_DEPENDENCY_LIBRARY_DIRS})
endmacro()

macro(jatta_find_package LIBRARY)
    message(STATUS "Looking for library ${LIBRARY}")

    # Parse arguments
    set(TYPE "")
    set(NAMES "")
    set(DEBUG "")
    set(PARENTS "")
    set(${LIBRARY}_SECONDARY OFF)
    foreach(ARG ${ARGN})
        if("${ARG}" STREQUAL "NAMES" OR "${ARG}" STREQUAL "DEBUG" OR "${ARG}" STREQUAL "PARENTS")
            set(TYPE ${ARG})
        elseif("${TYPE}" STREQUAL "NAMES")
            list(APPEND NAMES ${ARG})
        elseif("${TYPE}" STREQUAL "DEBUG")
            list(APPEND DEBUG ${ARG})
        elseif("${TYPE}" STREQUAL "PARENTS")
            list(APPEND PARENTS ${ARG})
            set(${LIBRARY}_SECONDARY ON)
        else()
            message(FATAL_ERROR "Syntax of jatta_find_package incorrect.")
        endif()
    endforeach()

    # Setup cache
    if(NOT ${${LIBRARY}_SECONDARY})
        set(${LIBRARY}_REQUIRED OFF CACHE BOOL "Causes the compilation to fail if ${LIBRARY} cannot be found.")
        set(${LIBRARY}_IGNORE OFF CACHE BOOL "Ignores this library even if it was found.")
    endif()

    # Look for the release and debug libraries
    jatta_find_library(${LIBRARY}_LIBRARY ${NAMES})
    set(${LIBRARY}_RELEASE_FOUND ON)
    if("${${LIBRARY}_LIBRARY}" STREQUAL "${LIBRARY}_LIBRARY-NOTFOUND")
        set(${LIBRARY}_RELEASE_FOUND OFF)
    endif()
    jatta_find_library(${LIBRARY}_DEBUG_LIBRARY ${DEBUG})
    set(${LIBRARY}_DEBUG_FOUND ON)
    if("${${LIBRARY}_DEBUG_LIBRARY}" STREQUAL "${LIBRARY}_DEBUG_LIBRARY-NOTFOUND")
        set(${LIBRARY}_DEBUG_FOUND OFF)
    endif()
    set(${LIBRARY}_FOUND ON)
    if(NOT ${${LIBRARY}_RELEASE_FOUND} AND NOT ${${LIBRARY}_DEBUG_FOUND})
        set(${LIBRARY}_FOUND OFF)
        message(STATUS "Looking for library ${LIBRARY} -- not found")
    endif()

    # Test compatibility
    if(${${LIBRARY}_FOUND})
        try_compile(${LIBRARY}_COMPILED
          ${CMAKE_BINARY_DIR}
          ${CMAKE_CURRENT_SOURCE_DIR}/libraries/${LIBRARY}.cpp
          COMPILE_DEFINITIONS ${CMAKE_REQUIRED_DEFINITIONS}
          CMAKE_FLAGS
          -DCOMPILE_DEFINITIONS:STRING=${CMAKE_REQUIRED_FLAGS}
          "-DINCLUDE_DIRECTORIES=${CMAKE_REQUIRED_INCLUDES}"
          OUTPUT_VARIABLE OUTPUT)
        if(NOT ${LIBRARY}_COMPILED)
            set(${LIBRARY}_FOUND OFF)
            message(STATUS "Looking for library ${LIBRARY} -- incompatible")
            file(APPEND ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/CMakeError.log
                "Unable to compile package test script for ${LIBRARY}!"
                "The test file ${LIBRARY}.cpp failed to compile:"
                "${OUTPUT}\n\n"
            )
        endif()
    endif()

    # Check the ignore flag
    if(${${LIBRARY}_IGNORE})
        if(${${LIBRARY}_FOUND})
            message(STATUS "Looking for library ${LIBRARY} -- ignored")
            set(${LIBRARY}_FOUND OFF)
        endif()
    endif()

    # Check for required library
    if(NOT ${${LIBRARY}_FOUND})
        if(${${LIBRARY}_SECONDARY})
            foreach(PARENT ${PARENTS})
                if(${${PARENT}_REQUIRED})
                    message(FATAL_ERROR "Unable to find dependency for required library ${PARENT}: ${LIBRARY}")
                endif()
            endforeach()
        else()
            if(${${LIBRARY}_REQUIRED})
                if(${${LIBRARY}_IGNORE})
                    message(FATAL_ERROR "The library ${LIBRARY} was both marked as REQUIRED and IGNORED.\nPlease switch off either ${LIBRARY}_REQUIRED or ${LIBRARY}_IGNORE.")
                else()
                    message(FATAL_ERROR "Unable to find required library: ${LIBRARY}")
                endif()
            endif()
        endif()
    else()
        # Import the library
        message(STATUS "Looking for library ${LIBRARY} -- found")
        add_library(${LIBRARY} STATIC IMPORTED)
        if(${${LIBRARY}_RELEASE_FOUND})
            set_target_properties(${LIBRARY} PROPERTIES IMPORTED_LOCATION "${${LIBRARY}_LIBRARY}")
        else()
            set_target_properties(${LIBRARY} PROPERTIES IMPORTED_LOCATION "${${LIBRARY}_DEBUG_LIBRARY}")
        endif()
        add_library(${LIBRARY}d STATIC IMPORTED)
        if(${${LIBRARY}_DEBUG_FOUND})
            set_target_properties(${LIBRARY}d PROPERTIES IMPORTED_LOCATION "${${LIBRARY}_DEBUG_LIBRARY}")
        else()
            set_target_properties(${LIBRARY}d PROPERTIES IMPORTED_LOCATION "${${LIBRARY}_LIBRARY}")
        endif()

        # Determine how to link this depending on the generator
        if(MSVC)
            set(${LIBRARY}_LINK "debug ${LIBRARY}d optimized ${LIBRARY}")
        else()
            if("${CMAKE_BUILD_TYPE}" STREQUAL "DEBUG")
                set(${LIBRARY}_LINK ${LIBRARY}d)
            else()
                set(${LIBRARY}_LINK ${LIBRARY})
            endif()
        endif()
    endif()

    if(${${LIBRARY}_SECONDARY})
        unset(${LIBRARY}_LIBRARY CACHE)
        unset(${LIBRARY}_DEBUG_LIBRARY CACHE)
    endif()
endmacro()

function(jatta_define_feature NAME DOC)
    set(ENABLED ON)
    foreach(dependency ${ARGN})
        if(NOT ${dependency}_FOUND)
            set(ENABLED OFF)
        endif()
    endforeach()
    set(${NAME} ${ENABLED} CACHE BOOL ${DOC})
endfunction()

macro(jatta_common_library LIBRARY)
    set(Jatta_COMMON_LIBRARIES ${Jatta_COMMON_LIBRARIES} ${LIBRARY})
endmacro()

jatta_find_package(
    Assimp
    NAMES assimp
    DEBUG assimpd
)

jatta_find_package(
    FreeType
    NAMES freetype
    DEBUG freetyped
)

jatta_find_package(
    glew
    NAMES glew glew32 glew32s
    DEBUG glewd glew32d glew32sd
)

jatta_find_package(
    JPEG
    NAMES jpeg
    DEBUG jpegd
)

jatta_find_package(
    PNG
    NAMES png libpng png15 libpng15 png14 libpng14 png12 libpng12
    DEBUG png15d libpng15d png14d libpng14d png12d libpng12d
)

jatta_find_package(
    zlib
    NAMES z zlib
    DEBUG zd zlibd
    PARENTS PNG
)

jatta_find_package(
    PortAudio
    NAMES portaudio
    DEBUG portaudiod
)

if("${SYSTEM_NAME}" STREQUAL "linux")
    jatta_find_package(
        ALSA
        NAMES asound
        PARENTS PortAudio
    )
endif()