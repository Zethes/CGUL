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

if (MSVC)
    message(FATAL_ERROR "Sorry, Visual Studio builds of Jatta are not currently supported.  They will be in the future!")
endif (MSVC)

if (APPLE)
    message(FATAL_ERROR "Sorry, Macintosh builds of Jatta are not currently supported.  They will be in the future!")
endif (APPLE)

set(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR})

set(CMAKE_CXX_FLAGS "-DJATTA_INCLUDES -DGLEW_STATIC -IC:/ZethesLibs/Windows32/include -LC:/ZethesLibs/Windows32/lib -std=c++11 -Os -s -o ${CMAKE_CXX_FLAGS}")

message(STATUS ${TOP_LEVEL})

add_library(Jatta SHARED ${JATTA_SOURCE})

ADD_LIBRARY(libpng STATIC IMPORTED)
SET_TARGET_PROPERTIES(libpng PROPERTIES IMPORTED_LOCATION ${TOP_LEVEL}/dep/lib/libpng15.a)

ADD_LIBRARY(glew STATIC IMPORTED)
SET_TARGET_PROPERTIES(glew PROPERTIES IMPORTED_LOCATION ${TOP_LEVEL}/dep/lib/libglew.a)

ADD_LIBRARY(freetype STATIC IMPORTED)
SET_TARGET_PROPERTIES(freetype PROPERTIES IMPORTED_LOCATION ${TOP_LEVEL}/dep/lib/libfreetype.a)

ADD_LIBRARY(zlib STATIC IMPORTED)
SET_TARGET_PROPERTIES(zlib PROPERTIES IMPORTED_LOCATION ${TOP_LEVEL}/dep/lib/libz.a)

TARGET_LINK_LIBRARIES(Jatta libpng freetype glew zlib opengl32)

INSTALL(FILES Jatta.h DESTINATION include/)
INSTALL(TARGETS Jatta DESTINATION lib/)