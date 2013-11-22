include(CheckIncludeFileCXX)
include(CheckCXXCompilerFlag)

macro(check_feature VARIABLE FILE)
    if(Jatta_REFRESH_CAPABILITIES)
        unset(${VARIABLE} CACHE)
    endif()
    if(NOT DEFINED ${VARIABLE})
        message(STATUS "Checking C++ capability ${VARIABLE}")
        try_compile(FEATURE_COMPILES ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/Config/${FILE}
            CMAKE_FLAGS "-DCMAKE_CXX_LINK_EXECUTABLE='echo a'" # this line stops cmake from linking on the try_compile call
            OUTPUT_VARIABLE OUTPUT
          )
        if(${FEATURE_COMPILES})
            set(${VARIABLE} ON CACHE INTERNAL "Feature")
            message(STATUS "Checking C++ capability ${VARIABLE} - passed")
        else()
            file(APPEND ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/CMakeError.log
              "Unable to compile config test script ${FILE}!"
              "The test file ${FILE} failed to compile:"
              "${OUTPUT}\n\n"
            )
            set(${VARIABLE} OFF CACHE INTERNAL "Feature")
            message(STATUS "Checking C++ capability ${VARIABLE} - failed")
        endif()
    endif()
endmacro()

macro(fast_check_include_file FILE VARIABLE)
    if(Jatta_REFRESH_CAPABILITIES)
        unset(${VARIABLE} CACHE)
    endif()
    if(NOT DEFINED ${VARIABLE})
        check_include_file_cxx(${FILE} ${VARIABLE})
        set(${VARIABLE} ${${VARIABLE}} CACHE INTERNAL "Include")
    endif()
endmacro()

fast_check_include_file(algorithm CPP_HEADER_ALGORITHM)
fast_check_include_file(cctype CPP_HEADER_CCTYPE)
fast_check_include_file(fstream CPP_HEADER_FSTREAM)
fast_check_include_file(list CPP_HEADER_LIST)
fast_check_include_file(map CPP_HEADER_MAP)
fast_check_include_file(memory CPP_HEADER_MEMORY)
fast_check_include_file(sstream CPP_HEADER_SSTREAM)
fast_check_include_file(stdexcept CPP_HEADER_STDEXCEPT)
fast_check_include_file(string CPP_HEADER_STRING)
fast_check_include_file(thread CPP_HEADER_THREAD)
fast_check_include_file(utility CPP_HEADER_UTILITY)
fast_check_include_file(vector CPP_HEADER_VECTOR)

fast_check_include_file(cstdint CPP_HEADER_CSTDINT)
fast_check_include_file(stdint.h CPP_HEADER_STDINT_H)

fast_check_include_file(cstddef CPP_HEADER_CSTDDEF)
fast_check_include_file(stddef.h CPP_HEADER_STDDEF_H)

# C++ standard checks
check_feature(CPP_HAS_DOUBLE_REFERENCE double_reference.cpp)
check_feature(CPP_HAS_FUNCTION_TEMPLATE_DEFAULT function_template_default.cpp)
check_feature(CPP_HAS_HYPERBOLIC_ARC hyperbolic_arc.cpp)
check_feature(CPP_HAS_MOVE_CONSTRUCTOR move_constructor.cpp)
check_feature(CPP_HAS_PTHREAD pthread.cpp)
check_feature(CPP_HAS_STATIC_ASSERT static_assert.cpp)
check_feature(CPP_HAS_STD_MOVE std_move.cpp)
check_feature(CPP_HAS_STD_REGEX std_regex.cpp)
check_feature(CPP_HAS_STD_THREAD std_thread.cpp)
check_feature(CPP_HAS_U8 u8.cpp)

# Library specific checks
check_feature(PCRE_HAS_FREE_STUDY pcre_free_study.cpp)

# Deprecated tag checks
check_feature(CPP_DEPRECATED_GCC_MESSAGE deprecated_gcc_message.cpp)
if(NOT CPP_DEPRECATED_GCC_MESSAGE)
    check_feature(CPP_DEPRECATED_GCC deprecated_gcc.cpp)
    if(NOT CPP_DEPRECATED_GCC)
        check_feature(CPP_DEPRECATED_MSVC deprecated_msvc.cpp)
    endif()
endif()

if(Jatta_REFRESH_CAPABILITIES)
    unset(Jatta_USE_NETWORK CACHE)
    unset(Jatta_USE_OPENGL CACHE)
endif()
jatta_define_feature(Jatta_STATIC "Build a static library.")
jatta_define_feature(Jatta_USE_NETWORK "Compile with networking features.")
jatta_define_feature(Jatta_USE_OPENGL "Compile with OpenGL support (requires glew)." glew)

set(Jatta_INLINE_DEFINE "" CACHE STRING "The inline to use for a function define.")
mark_as_advanced(Jatta_INLINE_DEFINE)
set(Jatta_INLINE_IMPLEMENT "inline" CACHE STRING "The inline to use for a function implementation.")
mark_as_advanced(Jatta_INLINE_IMPLEMENT)

# MinGW
if (MINGW)
    if(Jatta_USE_NETWORK)
        jatta_common_library(ws2_32)
    endif()
    if(Jatta_USE_OPENGL)
        jatta_common_library(opengl32)
    endif()
# Visual Studio
elseif(MSVC)
# MacOS
elseif(APPLE)
# Linux
else()
endif()
