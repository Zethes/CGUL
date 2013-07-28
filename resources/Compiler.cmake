# Determines compiler type

set(COMPILER_NAME "Unknown")
set(COMPILER_NAME_SIMPLE "Unknown")
set(COMPILER_VERSION "")
set(COMPILER_SUFFIX "")
if(${MSVC10} OR ${MSVC11})
    set(COMPILER_NAME "Visual Studio")
    set(COMPILER_NAME_SIMPLE "VS")
    if(MSVC60)
        set(COMPILER_VERSION "6.0")
    elseif(MSVC70)
        set(COMPILER_VERSION "2002")
    elseif(MSVC71)
        set(COMPILER_VERSION "2003")
    elseif(MSVC80)
        set(COMPILER_VERSION "2005")
    elseif(MSVC90)
        set(COMPILER_VERSION "2008")
    elseif(MSVC10)
        set(COMPILER_VERSION "2010")
    elseif(MSVC11)
        set(COMPILER_VERSION "2011")
    endif()
    set(COMPILER_SUFFIX "-${COMPILER_NAME_SIMPLE}${COMPILER_VERSION}")
elseif(CMAKE_COMPILER_IS_GNUCXX)
    set(COMPILER_NAME "GNU Compiler Collection (GCC)")
    set(COMPILER_NAME_SIMPLE "GCC")
    execute_process(COMMAND ${CMAKE_CXX_COMPILER} -dumpversion OUTPUT_VARIABLE COMPILER_VERSION)
    string(REPLACE "\n" "" COMPILER_VERSION ${COMPILER_VERSION})
    set(COMPILER_SUFFIX "-${COMPILER_NAME_SIMPLE}${COMPILER_VERSION}")
endif()

if("${COMPILER_NAME}" STREQUAL "Unknown" AND ${FIRST})
    message(WARNING "Your compiler is not recognized and may be unsupported.")
endif()