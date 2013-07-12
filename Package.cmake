# Script to package Jatta into various formats
# Officially supported formats:
#   DEB  - Debian package
#   NSIS - Nullsoft Installer
#   RPM  - Redhat package
#   STGZ - Self extracting gzip compressed package
#   TBZ2 - BZip2 compressed tar package (requires bzip2 to create package)
#   TGZ  - GZip compressed tar package
#   TZ   - UNIX compressed tar package
#   ZIP  - Compressed zip package

# Set Jatta_PACKAGE_TYPE to one of the above formats then build the package with the generator.
# For makefiles this is done with "make package"

if(WIN32)
    set(Jatta_PACKAGE_TYPE "ZIP" CACHE STRING "The type of package to create with CPack.")
else()
    set(Jatta_PACKAGE_TYPE "TGZ" CACHE STRING "The type of package to create with CPack.")
endif()

# Setup the package info
set(CPACK_GENERATOR "${Jatta_PACKAGE_TYPE}")
set(CPACK_PACKAGE_FILE_NAME "${PROJECT_NAME}")
set(CPACK_PACKAGE_VENDOR "Zethes" )
set(CPACK_PACKAGE_VERSION "${Jatta_VERSION}")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/license.txt")

# Redhat Package Manager (RPM)
if("${Jatta_PACKAGE_TYPE}" STREQUAL "RPM")
    set(CPACK_RPM_PACKAGE_NAME "${Jatta_OUTPUT_NAME}")
    set(CPACK_RPM_PACKAGE_SUMMARY "General Utility Library")
    set(CPACK_RPM_PACKAGE_DESCRIPTION "General Utility Library - Learn more at http://www.zethes.com/")
    set(CPACK_RPM_PACKAGE_LICENSE "BSD 2-Clause")
    set(CPACK_PACKAGING_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")
endif()

# Debian Package
if("${Jatta_PACKAGE_TYPE}" STREQUAL "DEB")
    set(CPACK_DEBIAN_PACKAGE_NAME "${Jatta_OUTPUT_NAME}")
    set(CPACK_DEBIAN_PACKAGE_VERSION "${Jatta_VERSION}")
    set(CPACK_DEBIAN_PACKAGE_MAINTAINER "jatta@zethes.com")
    set(CPACK_DEBIAN_PACKAGE_DESCRIPTION "General Utility Library - Learn more at http://www.zethes.com/")
    set(CPACK_PACKAGING_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")
endif()

# NSIS Installer (Windows)
if("${Jatta_PACKAGE_TYPE}" STREQUAL "NSIS")
    set(CPACK_PACKAGE_NAME "${Jatta_OUTPUT_NAME}")
    set(CPACK_NSIS_DISPLAY_NAME "${Jatta_OUTPUT_NAME}")
    file(TO_CMAKE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/resources/nsis.bmp" NSIS_ICON)
    if(WIN32)
        string(REPLACE "/" "\\\\\\\\" NSIS_ICON "${NSIS_ICON}")
        message(STATUS ${NSIS_ICON})
    endif()
    set(CPACK_PACKAGE_ICON "${NSIS_ICON}")
    set(CPACK_NSIS_CONTACT "jatta@zethes.com")
    set(CPACK_NSIS_URL_INFO_ABOUT "http://www.zethes.com/")
endif()

include(CPack)
