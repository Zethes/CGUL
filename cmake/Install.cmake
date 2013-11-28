# Add the CGUL target
set(INSTALL_TARGET_LIST "# CGUL")
if(CGUL_STATIC)

    set(INSTALL_TARGET_LIST "${INSTALL_TARGET_LIST}\nadd_library(CGUL STATIC IMPORTED)")

else()

    set(INSTALL_TARGET_LIST "${INSTALL_TARGET_LIST}\nadd_library(CGUL SHARED IMPORTED)")
    list(APPEND INSTALL_SHARED_MODULES CGUL)

endif()

# Add CGUL import locations
get_target_property(__LOCATION CGUL LOCATION)
get_filename_component(__FILENAME "${__LOCATION}" NAME)
set(INSTALL_TARGET_LIST "${INSTALL_TARGET_LIST}\nset_target_properties(CGUL PROPERTIES IMPORTED_LOCATION \"\${CMAKE_CURRENT_LIST_DIR}/../${CGUL_LIB_DIR}/${__FILENAME}\")")

if(WIN32 AND CGUL_STATIC)

    set(INSTALL_TARGET_LIST "${INSTALL_TARGET_LIST}\nset_target_properties(CGUL PROPERTIES IMPORTED_IMPLIB \"\${CMAKE_CURRENT_LIST_DIR}/../${CGUL_LIB_DIR}/${__FILENAME}\")")

endif()

# Add an import for each configuration
foreach(__CONFIGURATION ${CMAKE_CONFIGURATION_TYPES})

    string(TOUPPER "${__CONFIGURATION}" __CONFIGURATION)
    get_target_property(__LOCATION CGUL LOCATION_${__CONFIGURATION})

    if(__LOCATION)

        get_filename_component(__FILENAME "${__LOCATION}" NAME)
        set(INSTALL_TARGET_LIST "${INSTALL_TARGET_LIST}\nset_target_properties(CGUL PROPERTIES IMPORTED_LOCATION_${__CONFIGURATION} \"\${CMAKE_CURRENT_LIST_DIR}/../${CGUL_LIB_DIR}/${__FILENAME}\")")

        if(WIN32 AND NOT CGUL_STATIC)

            set(INSTALL_TARGET_LIST "${INSTALL_TARGET_LIST}\nset_target_properties(CGUL PROPERTIES IMPORTED_IMPLIB_${__CONFIGURATION} \"\${CMAKE_CURRENT_LIST_DIR}/../${CGUL_LIB_DIR}/${__FILENAME}\")")

        endif()

    endif()

endforeach()

# Add to the list of libraries
set(INSTALL_TARGET_LIST "${INSTALL_TARGET_LIST}\nlist(APPEND CGUL_LIBRARIES CGUL)")

# Iterate through each library that needs to be installed
foreach(__LIBRARY ${INSTALL_LIBRARIES})

    # Create a comment listing each target
    set(INSTALL_COMMENT_TARGETS "${INSTALL_COMMENT_TARGETS}\n#  ${__LIBRARY}")

    # Create each target
    set(INSTALL_TARGET_LIST "${INSTALL_TARGET_LIST}\n\n# ${__LIBRARY}")
    if(${${__LIBRARY}_SHARED})

        set(INSTALL_TARGET_LIST "${INSTALL_TARGET_LIST}\nadd_library(${__LIBRARY} SHARED IMPORTED)")

    else()

        set(INSTALL_TARGET_LIST "${INSTALL_TARGET_LIST}\nadd_library(${__LIBRARY} STATIC IMPORTED)")

    endif()

    # Add an import for each configuration
    set(__FIRST ON)
    foreach(__CONFIGURATION DEFAULT ${CMAKE_CONFIGURATION_TYPES})

        # Add a case for the default configuration
        if(__FIRST)

            # Default configuration is simply blank
            set(__FIRST OFF)
            set(__CONFIGURATION "")

        else()

            # All other configurations have an underscore in front for properties
            set(__CONFIGURATION "_${__CONFIGURATION}")
            string(TOUPPER "${__CONFIGURATION}" __CONFIGURATION)

        endif()

        # Get the location
        get_target_property(__LOCATION ${__LIBRARY} LOCATION${__CONFIGURATION})

        # Check if this property exists, if not ignore it
        if(__LOCATION)

            # Find packaged and non-packaged libraries differently
            if(${__LIBRARY}_PACKAGE)

                # Use a directory relative to installation
                get_filename_component(__FILENAME "${__LOCATION}" NAME)
                set(INSTALL_TARGET_LIST "${INSTALL_TARGET_LIST}\nset_target_properties(${__LIBRARY} PROPERTIES IMPORTED_LOCATION${__CONFIGURATION} \"\${CMAKE_CURRENT_LIST_DIR}/../${CGUL_LIB_DIR}/${__FILENAME}\")")

                # Special case for MSVC, need to set IMPORTED_IMPLIB too
                if(WIN32 AND ${__LIBRARY}_SHARED)

                    set(INSTALL_TARGET_LIST "${INSTALL_TARGET_LIST}\nset_target_properties(${__LIBRARY} PROPERTIES IMPORTED_IMPLIB${__CONFIGURATION} \"\${CMAKE_CURRENT_LIST_DIR}/../${CGUL_LIB_DIR}/${__FILENAME}\")")

                endif()

            else()

                # Use a system-wide location
                set(INSTALL_TARGET_LIST "${INSTALL_TARGET_LIST}\nset_target_properties(${__LIBRARY} PROPERTIES IMPORTED_LOCATION${__CONFIGURATION} \"${__LOCATION}\")")

                # Special case for MSVC, need to set IMPORTED_IMPLIB too
                if(WIN32 AND ${__LIBRARY}_SHARED)

                    set(INSTALL_TARGET_LIST "${INSTALL_TARGET_LIST}\nset_target_properties(${__LIBRARY} PROPERTIES IMPORTED_IMPLIB${__CONFIGURATION} \"${__LOCATION}\")")

                endif()

            endif()

        endif()

    endforeach()

    # Append to the list of shared modules if necessary
    if(${__LIBRARY}_SHARED)

        list(APPEND INSTALL_SHARED_MODULES ${__LIBRARY})

    endif()

    # Add to the list of libraries
    set(INSTALL_TARGET_LIST "${INSTALL_TARGET_LIST}\nlist(APPEND CGUL_LIBRARIES ${__LIBRARY})")

endforeach()

# Add system libraries
if(INSTALL_LIBRARIES_SYSTEM)

    set(INSTALL_TARGET_LIST "${INSTALL_TARGET_LIST}\n\n# System libraries")

endif()

# Append each system library
foreach(__LIBRARY ${INSTALL_LIBRARIES_SYSTEM})

    set(INSTALL_TARGET_LIST "${INSTALL_TARGET_LIST}\nlist(APPEND CGUL_LIBRARIES ${__LIBRARY})")

endforeach()

# Configure the CMake files
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/../resources/CGULConfig.cmake.in" "${CMAKE_CURRENT_BINARY_DIR}/../cmakescripts/${CGUL_OUTPUT_NAME}Config.cmake" @ONLY)
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/../resources/CGULConfigVersion.cmake.in" "${CMAKE_CURRENT_BINARY_DIR}/../cmakescripts/${CGUL_OUTPUT_NAME}ConfigVersion.cmake" @ONLY)

# Install CGUL
install(DIRECTORY ${CMAKE_BINARY_DIR}/${CGUL_LIB_DIR} DESTINATION ${CMAKE_INSTALL_PREFIX})
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/../cmakescripts/${CGUL_OUTPUT_NAME}Config.cmake DESTINATION ${CMAKE_INSTALL_PREFIX}/cmake/)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/../cmakescripts/${CGUL_OUTPUT_NAME}ConfigVersion.cmake DESTINATION ${CMAKE_INSTALL_PREFIX}/cmake/)

# Install include files
string(LENGTH "${CMAKE_CURRENT_SOURCE_DIR}" DIR_LENGTH)
math(EXPR DIR_LENGTH "${DIR_LENGTH} + 1")
foreach(FILE ${CGUL_INSTALL})

    string(SUBSTRING "${FILE}" ${DIR_LENGTH} -1 INSTALL_FILE)
    get_filename_component(INSTALL_DIR ${INSTALL_FILE} PATH)
    install(FILES ${FILE} DESTINATION ${CMAKE_INSTALL_PREFIX}/include/${INSTALL_DIR}/)

endforeach()

# Install Config.h
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/CGUL/Config.h DESTINATION ${CMAKE_INSTALL_PREFIX}/include/CGUL/)

# Install license
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/../license.txt DESTINATION ${CMAKE_INSTALL_PREFIX})
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/acknowledgements.txt DESTINATION ${CMAKE_INSTALL_PREFIX})

# Install other libraries
foreach(__LIBRARY ${INSTALL_LIBRARIES})

    if(${__LIBRARY}_PACKAGE)

        foreach(__CONFIGURATION DEFAULT ${CMAKE_CONFIGURATION_TYPES})

            # Add a case for the default configuration
            if(__FIRST)

                # Default configuration is simply blank
                set(__FIRST OFF)
                set(__CONFIGURATION "")

            else()

                # All other configurations have an underscore in front for properties
                set(__CONFIGURATION "_${__CONFIGURATION}")
                string(TOUPPER "${__CONFIGURATION}" __CONFIGURATION)

                # Get the location
                get_target_property(__LOCATION ${__LIBRARY} LOCATION${__CONFIGURATION})

                # Check for duplicates
                get_filename_component(__FILENAME ${__LOCATION} NAME)
                list(FIND __ALREADY_INSTALLED ${__FILENAME} __FIND)
                list(APPEND __ALREADY_INSTALLED ${__FILENAME})

                # Install the library
                if("${__FIND}" STREQUAL "-1")

                    install(FILES ${__LOCATION} DESTINATION ${CMAKE_INSTALL_PREFIX}/${CGUL_LIB_DIR})

                endif()

            endif()

        endforeach()

    endif()

endforeach()

# Installing the "include" directory is a temporary workaround for OpenGL calls in CGUL
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../include DESTINATION ${CMAKE_INSTALL_PREFIX})
