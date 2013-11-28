macro(doxygen_exclude FOLDER)
    set(DOXYGEN_EXCLUDE "${DOXYGEN_EXCLUDE} ${CMAKE_CURRENT_SOURCE_DIR}/src/CGUL/${FOLDER}")
endmacro()

if(DOXYGEN_ENABLE)

    # Find the doxygen executable
    find_package(Doxygen)
    if(DOXYGEN_FOUND)
        # Control doxygen output messages
        set(DOXYGEN_SHOW_WARNINGS "NO")
        set(DOXYGEN_QUIET "YES")
        if(DOXYGEN_WARNINGS)
            set(DOXYGEN_SHOW_WARNINGS "YES")
            set(DOXYGEN_QUIET "NO")
        endif()

        # Use a different doxyfile depending on the doxygen version available
        if(${DOXYGEN_VERSION} VERSION_LESS 1.7)
            set(DOXYGEN_IN "Doxyfile-1.6.in")
        elseif(${DOXYGEN_VERSION} VERSION_GREATER 1.6.1)
            set(DOXYGEN_IN "Doxyfile.in")
        else()
            message(SEND_ERROR "Invalid Doxygen version. Requires version 1.6.1 or higher.  Set DOXYGEN_ENABLE to OFF to disable this error.")
        endif()

        # Make sure the doxygen version is compatible
        if(NOT "${DOXYGEN_IN}" STREQUAL "")
            # Setup doxygen defines
            set(DOXYGEN_DEFINES "")

            # Setup doxygen excludes
            if(NOT Assimp_FOUND)
                doxygen_exclude(Assimp)
            endif()
            if(NOT PortAudio_FOUND)
                doxygen_exclude(PortAudio)
            endif()
            if(NOT CGUL_USE_OPENGL)
                doxygen_exclude(OpenGL)
            endif()

            # Configure the doxygen file
            configure_file(${CMAKE_CURRENT_SOURCE_DIR}/resources/${DOXYGEN_IN} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)

            # Add a build step to build doxygen
            add_custom_target(doc ALL
                ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
                WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                COMMENT "Generating API documentation with Doxygen" VERBATIM)
        endif()
    endif()
else()
    set(DOXYGEN_FOUND OFF)
endif()
