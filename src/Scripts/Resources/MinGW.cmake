IF(MSVC)
    ADD_LIBRARY(mingw STATIC IMPORTED)
    SET_TARGET_PROPERTIES(mingw PROPERTIES IMPORTED_LOCATION ${JATTA_DEPENDENCY_DIR}/lib/libmingwex.a)
    set(JATTA_LIBRARIES ${JATTA_LIBRARIES} mingw)

    ADD_LIBRARY(gcc STATIC IMPORTED)
    SET_TARGET_PROPERTIES(gcc PROPERTIES IMPORTED_LOCATION ${JATTA_DEPENDENCY_DIR}/lib/libgcc.a)
    set(JATTA_LIBRARIES ${JATTA_LIBRARIES} gcc)
ENDIF()