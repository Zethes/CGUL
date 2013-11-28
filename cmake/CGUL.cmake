# Detect first time generation
if("${CMAKE_INSTALL_PREFIX}" STREQUAL "")
    set(CGUL_FIRST_GENERATION ON)
else()
    set(CGUL_FIRST_GENERATION OFF)
endif()

# Allow the installation to go under a different name
set(CGUL_OUTPUT_NAME "CGUL" CACHE STRING "The name to install CGUL under.")
