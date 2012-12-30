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

set(CMAKE_CXX_FLAGS "-DJATTA_INCLUDES -IC:/ZethesLibs/Windows32/include -LC:/ZethesLibs/Windows32/lib -std=c++11 ${CMAKE_CXX_FLAGS}")

add_library(Jatta ${JATTA_SOURCE})

INSTALL(FILES Jatta.h DESTINATION include/)
INSTALL(TARGETS Jatta DESTINATION lib/)