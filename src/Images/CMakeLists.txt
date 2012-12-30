set(DIR ${CMAKE_CURRENT_LIST_DIR}/)

set(JATTA_SOURCE
    ${JATTA_SOURCE}
    ${DIR}Color.cpp
    ${DIR}Image.cpp
    ${DIR}Png.cpp
    PARENT_SCOPE
)

INSTALL(FILES Color.h DESTINATION include/Jatta/Images/)
INSTALL(FILES Image.h DESTINATION include/Jatta/Images/)