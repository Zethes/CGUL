set(DIR ${CMAKE_CURRENT_LIST_DIR}/)

set(JATTA_SOURCE
    ${JATTA_SOURCE}
    ${DIR}Object.cpp
    ${DIR}String.cpp
    PARENT_SCOPE
)

INSTALL(FILES Object.h DESTINATION include/Jatta/Utility/)
INSTALL(FILES Ptr.h DESTINATION include/Jatta/Utility/)
INSTALL(FILES String.h DESTINATION include/Jatta/Utility/)