####################################################################################################
## SimpleSource.cmake                                                                             ##
## by Joshua Brookover                                                                            ##
## Version 1.2                                                                                    ##
##                                                                                                ##
## PURPOSE                                                                                        ##
## To simplify (and prettify!) the process of including source files for C/C++ projects.          ##
##                                                                                                ##
## VERSION HISTORY                                                                                ##
## Version 1.0 - Initial release.                                                                 ##
## Version 1.1 - Added implementation file support.                                               ##
## Version 1.2 - Fixed silly bugs.                                                                ##
##                                                                                                ##
## LICENSE                                                                                        ##
## Use this file however you want.                                                                ##
## * No credit is necessary.                                                                      ##
## * No warranty.                                                                                 ##
####################################################################################################

##
# SIMPLESOURCE_INIT
# Sets up the environment for SimpleSource.
# Params:
# INSTALL  - ON / OFF, sets whether or not to install header and implementation files.  Note that if
#            this is ON you can use ADD_HEADER_NO_INSTALL or ADD_IMPLEMENTATION_NO_INSTALL to add a
#            file but not install it.
# VARIABLE - The variable to store the sources into.
##
MACRO(SIMPLESOURCE_INIT INSTALL VARIABLE)
    SET(SIMPLESOURCE_INSTALL ${INSTALL})
    SET(SIMPLESOURCE_VARIABLE ${VARIABLE})

    IF(SIMPLESOURCE_INSTALL)
        ##
        # ADD_HEADER_NO_INSTALL
        # Adds a header file without putting it in the install list.
        # Params:
        # FILE - The relative file name.
        ##
        MACRO(ADD_HEADER_NO_INSTALL FILE)
            ADD_SOURCE(${FILE})
        ENDMACRO()

        ##
        # ADD_HEADER (installation version)
        # Adds a header file to the build, as well adds it to the list of files to install.
        # Params:
        # FILE         - The relative file name.
        # INSTALL_PATH - Where to install the file.
        ##
        MACRO(ADD_HEADER FILE INSTALL_PATH)
            ADD_OTHER(${FILE})
            INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/${FILE} DESTINATION ${INSTALL_PATH})
        ENDMACRO()

        ##
        # ADD_IMPLEMENTATION_NO_INSTALL
        # Adds an implementation file without putting it in the install list.
        # Params:
        # FILE - The relative file name.
        ##
        MACRO(ADD_IMPLEMENTATION_NO_INSTALL FILE)
            ADD_SOURCE(${FILE})
        ENDMACRO()

        ##
        # ADD_IMPLEMENTATION (installation version)
        # Adds an implementation file to the build, as well adds it to the list of files to install.
        # Params:
        # FILE         - The relative file name.
        # INSTALL_PATH - Where to install the file.
        ##
        MACRO(ADD_IMPLEMENTATION FILE INSTALL_PATH)
            ADD_OTHER(${FILE})
            INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/${FILE} DESTINATION ${INSTALL_PATH})
        ENDMACRO()
    ELSE()
        ##
        # ADD_HEADER (non-installation version)
        # Adds a header file.
        # Params:
        # FILE - The relative file name.
        ##
        MACRO(ADD_HEADER FILE)
            ADD_OTHER(${FILE})
        ENDMACRO()

        ##
        # ADD_IMPLEMENTATION (non-installation version)
        # Adds an implementation file.
        # Params:
        # FILE - The relative file name.
        ##
        MACRO(ADD_IMPLEMENTATION FILE)
            ADD_OTHER(${FILE})
        ENDMACRO()
    ENDIF()
ENDMACRO()

##
# SIMPLESOURCE_FINISH
# Finalizes the SimpleSource script.  Must be called AFTER the target is added to the build (with
# ADD_EXECUTABLE, ADD_LIBRARY, etc).
##
MACRO(SIMPLESOURCE_FINISH)
    FOREACH(GROUP ${GROUPS})
        SET(GROUP_FILES ${GROUP}_FILES)
        SOURCE_GROUP(${GROUP} FILES ${${GROUP_FILES}})
    ENDFOREACH()
ENDMACRO()

##
# ADD_GROUP
# Adds all the subsequent files to the group.
# Params:
# LABEL - Name of the group.
##
MACRO(ADD_GROUP LABEL)
    SET(GROUPS ${GROUPS} ${LABEL} PARENT_SCOPE)
    SET(CURRENT_GROUP ${LABEL})
ENDMACRO()

##
# ADD_OTHER
# Adds a non-source file.
# Params:
# FILE - The relative file name.
##
MACRO(ADD_OTHER FILE)
    IF(NOT SIMPLESOURCE_VARIABLE)
        MESSAGE(FATAL_ERROR "SIMPLESOURCE_INIT has not been called.")
    ENDIF()
    SET(GROUP_FILES ${CURRENT_GROUP}_FILES)
    SET(CURRENT_GROUP_FILES ${GROUP_FILES})
    SET(${GROUP_FILES} ${${GROUP_FILES}} ${CMAKE_CURRENT_SOURCE_DIR}/${FILE} )
    SET(${GROUP_FILES} ${${GROUP_FILES}} ${CMAKE_CURRENT_LIST_DIR}/${FILE} PARENT_SCOPE)
    SET(${SIMPLESOURCE_VARIABLE} ${${SIMPLESOURCE_VARIABLE}} ${CMAKE_CURRENT_SOURCE_DIR}/${FILE})
    SET(${SIMPLESOURCE_VARIABLE} ${${SIMPLESOURCE_VARIABLE}} PARENT_SCOPE)
ENDMACRO()

##
# ADD_SOURCE
# Adds a source file.
# Params:
# FILE - The relative file name.
##
MACRO(ADD_SOURCE FILE)
    ADD_OTHER(${FILE})
ENDMACRO()