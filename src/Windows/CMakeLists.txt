set(DIR ${CMAKE_CURRENT_LIST_DIR}/)

set(JATTA_SOURCE
    ${JATTA_SOURCE}
    ${DIR}Input.cpp
    ${DIR}Window.cpp
    ${DIR}WindowStyle.cpp
    PARENT_SCOPE
)

INSTALL(FILES Input.h DESTINATION include/Jatta/Windows/)
INSTALL(FILES Window.h DESTINATION include/Jatta/Windows/)
INSTALL(FILES WindowStyle.h DESTINATION include/Jatta/Windows/)