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

# Setup the package info
set(CPACK_GENERATOR "${Jatta_PACKAGE_TYPE}")
#set(CPACK_PACKAGE_FILE_NAME "${PROJECT_NAME}")
set(CPACK_PACKAGE_VENDOR "Zethes" )
set(CPACK_PACKAGE_VERSION "${Jatta_VERSION}")
set(CPACK_PACKAGE_VERSION_MAJOR "${Jatta_MAJOR_VERSION}")
set(CPACK_PACKAGE_VERSION_MINOR "${Jatta_MINOR_VERSION}")
set(CPACK_PACKAGE_VERSION_PATCH "${Jatta_PATCH_VERSION}")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/license.txt")
set(CPACK_SYSTEM_NAME "${SYSTEM_NAME_UPPER}-${SYSTEM_BITNESS}bit${COMPILER_SUFFIX}")

# Setup per-package settings file
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/resources/PackageConfig.cmake.in" "${CMAKE_CURRENT_BINARY_DIR}/PackageConfig.cmake" @ONLY)
set(CPACK_PROJECT_CONFIG_FILE ${CMAKE_CURRENT_BINARY_DIR}/PackageConfig.cmake)

# Allow source packaging
set(CPACK_SOURCE_IGNORE_FILES "${CMAKE_BINARY_DIR}")

# Include cpack
include(CPack)
