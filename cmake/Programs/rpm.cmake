if (UNIX AND NOT APPLE AND NOT CYGWIN)
    # Make sure rpmbuild is installed
    find_program(rpmbuild_BINARY rpmbuild DOC "rpmbuild is used to build both binary and source software packages.")

    # Add custom target to cmake
    add_custom_target("rpm" COMMAND "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Programs/makerpm.sh" ${CMAKE_CURRENT_BINARY_DIR} ${CGUL_VERSION})
endif()