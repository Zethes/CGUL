#set(DIR ${CMAKE_CURRENT_LIST_DIR}/)

#set(JATTA_SOURCE
#    ${JATTA_SOURCE}
#    ${DIR}Model.cpp
#    ${DIR}Obj.cpp
#    PARENT_SCOPE
#)

#INSTALL(FILES Group.h DESTINATION include/Jatta/Models/)
#INSTALL(FILES Model.h DESTINATION include/Jatta/Models/)
#INSTALL(FILES Obj.h DESTINATION include/Jatta/Models/)
#INSTALL(FILES VertexBuffer.h DESTINATION include/Jatta/Models/)

ADD_GROUP("Models")
ADD_HEADER(Group.h include/Jatta/Models/)
ADD_SOURCE(Model.cpp)
ADD_HEADER(Model.h include/Jatta/Models/)
ADD_SOURCE(Obj.cpp)
ADD_HEADER(Obj.h include/Jatta/Models/)
ADD_HEADER(VertexBuffer.h include/Jatta/Models/)