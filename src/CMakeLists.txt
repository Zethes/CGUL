add_subdirectory(External)
add_subdirectory(File)
add_subdirectory(Fonts)
add_subdirectory(Graphics)
add_subdirectory(Images)
add_subdirectory(Math)
add_subdirectory(Models)
add_subdirectory(Network)
add_subdirectory(Utility)
add_subdirectory(Windows)

#if (MSVC)
    #message(FATAL_ERROR "Sorry, Visual Studio builds of Jatta are not currently supported.  They will be in the future!")
#endif (MSVC)

if (APPLE)
    message(FATAL_ERROR "Sorry, Macintosh builds of Jatta are not currently supported.  They will be in the future!")
endif (APPLE)

set(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR})

if (MSYS)
    set(CMAKE_CXX_FLAGS "-IC:/ZethesLibs/Windows32/include -LC:/ZethesLibs/Windows32/lib -std=c++11 -Os -s -o ${CMAKE_CXX_FLAGS}")
endif (MSYS)

SET(JATTA_DEFINITIONS ${JATTA_DEFINITIONS} -DJATTA_INCLUDES -DGLEW_STATIC -DWIN32_LEAN_AND_MEAN -DNOMINMAX -DJATTA_BUILD)

if (MSVC)
    set(CMAKE_CXX_FLAGS "-IC:/ZethesLibs/Windows32/include /EHsc")
    SET(JATTA_DEFINITIONS ${JATTA_DEFINITIONS} -DMSVC)
endif (MSVC)

message(STATUS ${TOP_LEVEL})

add_library(Jatta SHARED ${JATTA_SOURCE})

ADD_LIBRARY(libpng STATIC IMPORTED)
SET_TARGET_PROPERTIES(libpng PROPERTIES IMPORTED_LOCATION ${TOP_LEVEL}/dep/lib/libpng15.a)
set(JATTA_LIBRARIES ${JATTA_LIBRARIES} libpng)

ADD_LIBRARY(glew STATIC IMPORTED)
SET_TARGET_PROPERTIES(glew PROPERTIES IMPORTED_LOCATION ${TOP_LEVEL}/dep/lib/libglew.a)
set(JATTA_LIBRARIES ${JATTA_LIBRARIES} glew)

if (NOT JATTA_NO_FONTS)
    ADD_LIBRARY(freetype STATIC IMPORTED)
    SET_TARGET_PROPERTIES(freetype PROPERTIES IMPORTED_LOCATION ${TOP_LEVEL}/dep/lib/libfreetype.a)
    set(JATTA_LIBRARIES ${JATTA_LIBRARIES} freetype)
    SET(JATTA_DEFINITIONS ${JATTA_DEFINITIONS} -DJATTA_FONTS)
endif (NOT JATTA_NO_FONTS)

ADD_LIBRARY(zlib STATIC IMPORTED)
SET_TARGET_PROPERTIES(zlib PROPERTIES IMPORTED_LOCATION ${TOP_LEVEL}/dep/lib/libz.a)
set(JATTA_LIBRARIES ${JATTA_LIBRARIES} zlib)

if (MSVC)
    ADD_LIBRARY(mingw STATIC IMPORTED)
    SET_TARGET_PROPERTIES(mingw PROPERTIES IMPORTED_LOCATION ${TOP_LEVEL}/dep/lib/libmingwex.a)
    set(JATTA_LIBRARIES ${JATTA_LIBRARIES} mingw)

    ADD_LIBRARY(gcc STATIC IMPORTED)
    SET_TARGET_PROPERTIES(gcc PROPERTIES IMPORTED_LOCATION ${TOP_LEVEL}/dep/lib/libgcc.a)
    set(JATTA_LIBRARIES ${JATTA_LIBRARIES} gcc)
endif (MSVC)

if (UNIX)
    SET(JATTA_LIBRARIES ${JATTA_LIBRARIES} GL)
endif (UNIX)

if (WIN32)
    SET(JATTA_LIBRARIES ${JATTA_LIBRARIES} opengl32)
endif (WIN32)

TARGET_LINK_LIBRARIES(Jatta ${JATTA_LIBRARIES})

add_definitions(${JATTA_DEFINITIONS})

INSTALL(FILES Jatta.h DESTINATION include/)
INSTALL(TARGETS Jatta DESTINATION lib/)