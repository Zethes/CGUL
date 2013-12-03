# There are 4 types of error checking, ranked by severity.
# 0. Fast          - Performs crucial error checking only.
# 1. Cautious      - The recommended setting, quickly checks obvious errors. Recommended for
#                    production use.
# 2. Safe          - Checks very unlikely errors.
# 3. Sanity Check  - May perform slow error checking to catch logic errors.

set(CGUL_ERROR_LEVEL "1" CACHE STRING "Error checking level (0-3).")

set(__LEVEL 1)
if("${CGUL_ERROR_LEVEL}" STREQUAL "0")

    set(__LEVEL 0)

elseif("${CGUL_ERROR_LEVEL}" STREQUAL "2")

    set(__LEVEL 2)

elseif("${CGUL_ERROR_LEVEL}" STREQUAL "3")

    set(__LEVEL 3)

endif()

if(__LEVEL GREATER 0)

    set(CMAKE_REQUIRED_DEFINITIONS "${CMAKE_REQUIRED_DEFINITIONS} -DCGUL_CAUTIOUS")

endif()

if(__LEVEL GREATER 1)

    set(CMAKE_REQUIRED_DEFINITIONS "${CMAKE_REQUIRED_DEFINITIONS} -DCGUL_SAFE")

endif()

if(__LEVEL GREATER 2)

    set(CMAKE_REQUIRED_DEFINITIONS "${CMAKE_REQUIRED_DEFINITIONS} -DCGUL_SANITY_CHECK")

endif()
