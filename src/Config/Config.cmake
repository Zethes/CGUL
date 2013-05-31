include(CheckIncludeFileCXX)
include(CheckCXXCompilerFlag)

macro(check_feature VARIABLE FILE)
    try_compile(FEATURE_COMPILES ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/Config/${FILE})
    if(${FEATURE_COMPILES})
        set(${VARIABLE} ON)
    endif()
endmacro()

check_include_file_cxx(algorithm CPP_HEADER_ALGORITHM)
check_include_file_cxx(cctype CPP_HEADER_CCTYPE)
check_include_file_cxx(fstream CPP_HEADER_FSTREAM)
check_include_file_cxx(list CPP_HEADER_LIST)
check_include_file_cxx(map CPP_HEADER_MAP)
check_include_file_cxx(memory CPP_HEADER_MEMORY)
check_include_file_cxx(sstream CPP_HEADER_SSTREAM)
check_include_file_cxx(stdexcept CPP_HEADER_STDEXCEPT)
check_include_file_cxx(string CPP_HEADER_STRING)
check_include_file_cxx(thread CPP_HEADER_THREAD)
check_include_file_cxx(utility CPP_HEADER_UTILITY)
check_include_file_cxx(vector CPP_HEADER_VECTOR)

check_include_file_cxx(cstdint CPP_HEADER_CSTDINT)
check_include_file_cxx(stdint.h CPP_HEADER_STDINT_H)

check_feature(CPP_HAS_DOUBLE_REFERENCE double_reference.cpp)
check_feature(CPP_HAS_HYPERBOLIC_ARC hyperbolic_arc.cpp)
check_feature(CPP_HAS_MOVE_CONSTRUCTOR move_constructor.cpp)
check_feature(CPP_HAS_STATIC_ASSERT static_assert.cpp)
check_feature(CPP_HAS_STD_THREAD std_thread.cpp)
check_feature(CPP_HAS_U8 u8.cpp)

jatta_define_feature(Jatta_STATIC "Build a static library." OFF)
jatta_define_feature(Jatta_USE_NETWORK "Compile with networking features.")
jatta_define_feature(Jatta_USE_OPENGL "Compile with OpenGL support." glew)

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