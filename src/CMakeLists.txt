# Generate configuration file
include(Config/Config.cmake)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Config/Config.h.in ${CMAKE_CURRENT_BINARY_DIR}/Jatta/Config.h)

# Include the source tree
add_subdirectory(Jatta)
set(Jatta_INSTALL ${Jatta_INSTALL} ${CMAKE_CURRENT_SOURCE_DIR}/Jatta.h)

# Make all of the files Obj-C++ on Mac
if(APPLE AND NOT ${CMAKE_GENERATOR} STREQUAL "Xcode")
    set(CMAKE_CXX_FLAGS "-ObjC++ ${CMAKE_CXX_FLAGS}")
endif()

# Turn on all warnings and warning to errors in GCC
if(CMAKE_COMPILER_IS_GNUCXX)
    #set(CMAKE_CXX_FLAGS "-Wall -Werror ${CMAKE_CXX_FLAGS}")
    # there is a very good reason that this is commented out
    # and it is only 50% because of laziness
endif()

# Determine dependencies
include(dependencies.cmake)

# Determine library type
set(Jatta_LIBRARY_TYPE SHARED)
if (Jatta_STATIC)
    set(Jatta_LIBRARY_TYPE STATIC)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_REQUIRED_INCLUDES})
if(APPLE)
    include_directories(/Developer/Headers/FlatCarbon)
endif()
add_definitions(-DJATTA_BUILD -DJATTA_INCLUDES ${CMAKE_REQUIRED_FLAGS})
add_library(Jatta ${Jatta_LIBRARY_TYPE} ${Jatta_SOURCES} ${CMAKE_CURRENT_BINARY_DIR}/Jatta/Config.h)
set_property(TARGET Jatta PROPERTY OUTPUT_NAME "${Jatta_OUTPUT_NAME}")

string(STRIP "${Jatta_LIBRARIES}" Jatta_LIBRARIES)
string(REPLACE " " ";" LIBRARY_LIST "${Jatta_LIBRARIES}")
target_link_libraries(Jatta ${LIBRARY_LIST})

# Get information about the library
if("${CMAKE_BUILD_TYPE}" STREQUAL "")
    get_property(Jatta_MODULE_NAME_PATH TARGET Jatta PROPERTY LOCATION)
else()
    get_property(Jatta_MODULE_NAME_PATH TARGET Jatta PROPERTY LOCATION_${CMAKE_BUILD_TYPE})
endif()
get_filename_component(Jatta_MODULE_NAME ${Jatta_MODULE_NAME_PATH} NAME)

# Fix for Xcode to enforce Obj-C++ on all files
if(APPLE AND ${CMAKE_GENERATOR} STREQUAL "Xcode")
    set_target_properties(Jatta PROPERTIES XCODE_ATTRIBUTE_GCC_INPUT_FILETYPE sourcecode.cpp.objcpp)
endif()

# Version info
set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/Jatta/Utility/Version.cpp PROPERTIES COMPILE_DEFINITIONS "_JATTA_MAJOR=${Jatta_MAJOR_VERSION};_JATTA_MINOR=${Jatta_MINOR_VERSION};_JATTA_PATCH=${Jatta_PATCH_VERSION};_COMPILER_NAME=\"${COMPILER_NAME_SIMPLE}${COMPILER_VERSION}\"")

# Installation setup
string(LENGTH "${CMAKE_CURRENT_SOURCE_DIR}" DIR_LENGTH)
math(EXPR DIR_LENGTH "${DIR_LENGTH} + 1")
foreach(FILE ${Jatta_INSTALL})
    string(SUBSTRING "${FILE}" ${DIR_LENGTH} -1 INSTALL_FILE)
    get_filename_component(INSTALL_DIR ${INSTALL_FILE} PATH)
    install(FILES ${FILE} DESTINATION include/${INSTALL_DIR}/)
endforeach()
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/Jatta/Config.h DESTINATION include/Jatta/)
install(TARGETS Jatta DESTINATION ${LIB_DIR}/)
if(NOT ${Jatta_INSTALL_ESSENTIALS_ONLY})
    install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/../license.txt DESTINATION .)
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/acknowledgements.txt DESTINATION .)
    if(DOXYGEN_ENABLE)
        install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../html DESTINATION doc)
    endif()
    foreach(STATIC ${STATIC_LIBRARIES})
        if(Jatta_STATIC OR ${STATIC}_SHARED)
            if("${CMAKE_BUILD_TYPE}" STREQUAL "DEBUG")
                get_target_property(STATIC_DIR ${STATIC}d IMPORTED_LOCATION)
            else()
                get_target_property(STATIC_DIR ${STATIC} IMPORTED_LOCATION)
            endif()
            get_filename_component(STATIC_DIR_REAL ${STATIC_DIR} REALPATH)
            get_filename_component(STATIC_DIR_NAME ${STATIC_DIR} NAME)
            if(DEFINED ${STATIC}_SHARED AND NOT ${STATIC}_SHARED)
                set(STATIC_IMPORTS "${STATIC_IMPORTS}\n\nadd_library(${STATIC} STATIC IMPORTED)")
            else()
                set(STATIC_IMPORTS "${STATIC_IMPORTS}\n\nadd_library(${STATIC} SHARED IMPORTED)")
                if(${STATIC}_PACKAGE)
                    set(STATIC_IMPORTS "${STATIC_IMPORTS}\nset(Jatta_${STATIC}_PACKAGE ON CACHE STRING \"Packages the ${STATIC} library with Jatta.\")")
                else()
                    set(STATIC_IMPORTS "${STATIC_IMPORTS}\nset(Jatta_${STATIC}_PACKAGE OFF CACHE STRING \"Packages the ${STATIC} library with Jatta.\")")
                endif()
                set(STATIC_IMPORTS "${STATIC_IMPORTS}\nmark_as_advanced(Jatta_${STATIC}_PACKAGE)")
            endif()
            if(${STATIC}_PACKAGE)
                install(FILES ${STATIC_DIR_REAL} DESTINATION ${LIB_DIR} RENAME ${STATIC_DIR_NAME})
                set(STATIC_IMPORTS "${STATIC_IMPORTS}\nset_target_properties(${STATIC} PROPERTIES IMPORTED_LOCATION \${CMAKE_CURRENT_LIST_DIR}/../${LIB_DIR}/${STATIC_DIR_NAME})")
            else()
                set(STATIC_IMPORTS "${STATIC_IMPORTS}\nfind_library(Jatta_${STATIC}_LIBRARY ${STATIC_DIR_NAME})")
                set(STATIC_IMPORTS "${STATIC_IMPORTS}\nset_target_properties(${STATIC} PROPERTIES IMPORTED_LOCATION \${Jatta_${STATIC}_LIBRARY})")
            endif()
            if(${STATIC}_SHARED)
                if("${SHARED_MODULES}" STREQUAL "")
                    set(SHARED_MODULES "${STATIC}")
                else()
                    set(SHARED_MODULES "${SHARED_MODULES};${STATIC}")
                endif()
            endif()
            set(TARGET_COMMENT "${TARGET_COMMENT}\n#  ${STATIC}")
        endif()
    endforeach()
    string(STRIP "${STATIC_LIBRARIES}" STATIC_LIBRARIES_PARSED)
    string(REPLACE ";" " " STATIC_LIBRARIES_PARSED "${STATIC_LIBRARIES_PARSED}")
    set(SYSTEM_LIBRARIES " ${STATIC_LIBRARIES_PARSED}${SYSTEM_LIBRARIES}")
    configure_file("${CMAKE_CURRENT_SOURCE_DIR}/../resources/JattaConfig.cmake.in" "${CMAKE_CURRENT_BINARY_DIR}/../cmakescripts/${Jatta_OUTPUT_NAME}Config.cmake" @ONLY)
    configure_file("${CMAKE_CURRENT_SOURCE_DIR}/../resources/JattaConfigVersion.cmake.in" "${CMAKE_CURRENT_BINARY_DIR}/../cmakescripts/${Jatta_OUTPUT_NAME}ConfigVersion.cmake" @ONLY)
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/../cmakescripts/${Jatta_OUTPUT_NAME}Config.cmake DESTINATION cmake/)
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/../cmakescripts/${Jatta_OUTPUT_NAME}ConfigVersion.cmake DESTINATION cmake/)
endif()
