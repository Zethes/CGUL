IF(JATTA_USE_JPEG)
    ADD_LIBRARY(jpeg STATIC IMPORTED)
    SET_TARGET_PROPERTIES(jpeg PROPERTIES IMPORTED_LOCATION ${JATTA_DEPENDENCY_DIR}/lib/libjpeg.a)
    SET(JATTA_LIBRARIES ${JATTA_LIBRARIES} jpeg)
ENDIF()