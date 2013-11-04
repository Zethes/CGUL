# Detect first time generation
if("${CMAKE_INSTALL_PREFIX}" STREQUAL "")
    set(Jatta_FIRST_GENERATION ON)
else()
    set(Jatta_FIRST_GENERATION OFF)
endif()

# Allow the installation to go under a different name
set(Jatta_OUTPUT_NAME "Jatta" CACHE STRING "The name to install Jatta under.")
