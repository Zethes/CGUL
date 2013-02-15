MACRO(DEFINE_CACHE NAME VALUE TYPE DESCRIPTION)
    IF(DEFINED ${NAME})
        SET(${NAME} ${${NAME}} CACHE ${TYPE} ${DESCRIPTION})
    ELSE()
        SET(${NAME} ${VALUE} CACHE ${TYPE} ${DESCRIPTION})
    ENDIF()
ENDMACRO()

DEFINE_CACHE(JATTA_STATIC OFF BOOL "Builds a static library.")

DEFINE_CACHE(JATTA_OUTPUT_DIR "${CMAKE_BINARY_DIR}/bin" PATH "Where to export the Jatta library.")

GET_FILENAME_COMPONENT(JATTA_DEP "${CMAKE_CURRENT_SOURCE_DIR}/../dep" REALPATH)
DEFINE_CACHE(JATTA_DEPENDENCY_DIR ${JATTA_DEP} PATH "Specifies the Jatta dependency directory.")

DEFINE_CACHE(JATTA_USE_ASSIMP ON BOOL "Compiles with Assimp support.")
DEFINE_CACHE(JATTA_USE_AUDIO ON BOOL "Compiles with PortAudio support.")
DEFINE_CACHE(JATTA_USE_FREETYPE ON BOOL "Compiles with FreeType support.")
DEFINE_CACHE(JATTA_USE_JPEG ON BOOL "Compiles with libjpeg support.")
IF(WIN32)
    DEFINE_CACHE(JATTA_USE_NETWORK ON BOOL "Compiles with BSD sockets support.")
ELSE()
    DEFINE_CACHE(JATTA_USE_NETWORK ON BOOL "Compiles with WinSock support.")
ENDIF()
DEFINE_CACHE(JATTA_USE_OPENGL ON BOOL "Compiles with OpenGL support.")
DEFINE_CACHE(JATTA_USE_PNG ON BOOL "Compiles with libpng support.")