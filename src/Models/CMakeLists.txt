set(DIR ${CMAKE_CURRENT_LIST_DIR}/)

set(JATTA_SOURCE
    ${JATTA_SOURCE}
    ${DIR}Model.cpp
    ${DIR}Obj.cpp
    PARENT_SCOPE
)

INSTALL(FILES Group.h DESTINATION include/Jatta/Models/)
INSTALL(FILES Model.h DESTINATION include/Jatta/Models/)
INSTALL(FILES Obj.h DESTINATION include/Jatta/Models/)
INSTALL(FILES VertexBuffer.h DESTINATION include/Jatta/Models/)