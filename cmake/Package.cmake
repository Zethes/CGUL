# Script to package CGUL into various formats
# Officially supported formats:
#   DEB  - Debian package
#   NSIS - Nullsoft Installer
#   RPM  - Redhat package
#   STGZ - Self extracting gzip compressed package
#   TBZ2 - BZip2 compressed tar package (requires bzip2 to create package)
#   TGZ  - GZip compressed tar package
#   TZ   - UNIX compressed tar package
#   ZIP  - Compressed zip package

# Set CGUL_PACKAGE_TYPE to one of the above formats then build the package with the generator.
# For makefiles this is done with "make package"

# Setup the package info
set(CPACK_GENERATOR "${CGUL_PACKAGE_TYPE}")
#set(CPACK_PACKAGE_FILE_NAME "${PROJECT_NAME}")
set(CPACK_PACKAGE_VENDOR "Zethes" )
set(CPACK_PACKAGE_VERSION "${CGUL_VERSION}")
set(CPACK_PACKAGE_VERSION_MAJOR "${CGUL_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${CGUL_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${CGUL_VERSION_PATCH}")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/license.txt")
set(CPACK_SYSTEM_NAME "${System_DISTRO}-${System_BITNESS}bit${Compiler_SUFFIX}")

# Setup per-package settings file
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/resources/PackageConfig.cmake.in" "${CMAKE_CURRENT_BINARY_DIR}/PackageConfig.cmake" @ONLY)
set(CPACK_PROJECT_CONFIG_FILE ${CMAKE_CURRENT_BINARY_DIR}/PackageConfig.cmake)

# Allow source packaging
set(CPACK_SOURCE_IGNORE_FILES "${CMAKE_BINARY_DIR}")

# Include cpack
include(CPack)
