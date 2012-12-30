set(DIR ${CMAKE_CURRENT_LIST_DIR}/)

set(JATTA_SOURCE
    ${JATTA_SOURCE}
    ${DIR}Float2.cpp
    ${DIR}Float3.cpp
    ${DIR}Float4.cpp
    ${DIR}Math.cpp
    ${DIR}Matrix.cpp
    ${DIR}Random.cpp
    PARENT_SCOPE
)

INSTALL(FILES Float2.h DESTINATION include/Jatta/Math/)
INSTALL(FILES Float3.h DESTINATION include/Jatta/Math/)
INSTALL(FILES Float4.h DESTINATION include/Jatta/Math/)
INSTALL(FILES Math.h DESTINATION include/Jatta/Math/)
INSTALL(FILES Matrix.h DESTINATION include/Jatta/Math/)
INSTALL(FILES Random.h DESTINATION include/Jatta/Math/)