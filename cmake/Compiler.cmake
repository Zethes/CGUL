# - Gathers information about the compiler
# Defines the following cache variables:
#  Compiler_NAME        - Detailed name of the compiler
#  Compiler_NAME_SIMPLE - Simple name of the compiler
#  Compiler_VERSION     - Compiler-specific version
# Defines the following internal variables:
#  Compiler_CHECK       - CMake parseable check for compiler compatibility
# Defines the following variables:
#  Compiler_SUFFIX      - Special suffix for compiler name and version

if(NOT DEFINED Compiler_NAME        OR
   NOT DEFINED Compiler_NAME_SIMPLE OR
   NOT DEFINED Compiler_VERSION     OR
   NOT DEFINED Compiler_CHECK       )

    message(STATUS "Gather CXX compiler info")

    # Clear the cache
    unset(Compiler_NAME        CACHE)
    unset(Compiler_NAME_SIMPLE CACHE)
    unset(Compiler_VERSION     CACHE)
    unset(Compiler_CHECK       CACHE)

    # Default values
    set(Compiler_NAME        "Unknown")
    set(Compiler_NAME_SIMPLE "Unknown")
    set(Compiler_VERSION     "")
    set(Compiler_SUFFIX      "")
    set(Compiler_CHECK       "")

    # Microsoft Visual Studio
    if(MSVC)

        # Set the compiler name
        set(Compiler_NAME "Microsoft Visual Studio")
        set(Compiler_NAME_SIMPLE "VS")

        # Get the version based on predefined CMake variables
        if(MSVC60)
            set(Compiler_VERSION "6.0")
        elseif(MSVC70)
            set(Compiler_VERSION "2002")
        elseif(MSVC71)
            set(Compiler_VERSION "2003")
        elseif(MSVC80)
            set(Compiler_VERSION "2005")
        elseif(MSVC90)
            set(Compiler_VERSION "2008")
        elseif(MSVC10)
            set(Compiler_VERSION "2010")
        elseif(MSVC11)
            set(Compiler_VERSION "2011")
        endif()

        # Specify compatibility check
        set(Compiler_CHECK "MSVC")

    endif()

    # GNU Compiler Collection (GCC)
    if(CMAKE_COMPILER_IS_GNUCXX)

        # Set the compiler name
        set(Compiler_NAME "GNU Compiler Collection (GCC)")
        set(Compiler_NAME_SIMPLE "GCC")

        # Query version from compiler
        execute_process(COMMAND ${CMAKE_CXX_COMPILER} -dumpversion OUTPUT_VARIABLE Compiler_VERSION)
        string(REPLACE "\n" "" Compiler_VERSION ${Compiler_VERSION})

        # Specify compatibility check
        set(Compiler_CHECK "CMAKE_COMPILER_IS_GNUCXX")

    endif()

    # LLVM Clang
    if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")

        # Set the compiler name
        set(Compiler_NAME "LLVM Clang")
        set(Compiler_NAME_SIMPLE "clang")

        # Query version from compiler
        execute_process(COMMAND ${CMAKE_CXX_COMPILER} -dumpversion OUTPUT_VARIABLE Compiler_VERSION)
        string(REPLACE "\n" "" Compiler_VERSION ${Compiler_VERSION})

        # Specify compatibility check
        set(Compiler_CHECK "\"${CMAKE_CXX_COMPILER_ID}\" STREQUAL \"Clang\"")

    endif()

    # Check if the compiler is valid
    if("${Compiler_NAME}" STREQUAL "Unknown")
        message(WARNING "Your compiler is not recognized and may not be supported.")
    else()
        set(Compiler_SUFFIX "-${Compiler_NAME_SIMPLE}${Compiler_VERSION}")
    endif()

    # Save to cache
    set(Compiler_NAME        ${Compiler_NAME}        CACHE STRING   "Detailed name of the compiler.")
    set(Compiler_NAME_SIMPLE ${Compiler_NAME_SIMPLE} CACHE STRING   "Simple name of the compiler.")
    set(Compiler_VERSION     ${Compiler_VERSION}     CACHE STRING   "Compiler-specific version.")
    set(Compiler_CHECK       ${Compiler_CHECK}       CACHE INTERNAL "CMake parseable check for compiler compatibility.")

    message(STATUS "Gather CXX compiler info - done")

endif()
