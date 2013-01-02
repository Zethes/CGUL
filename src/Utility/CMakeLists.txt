#set(DIR ${CMAKE_CURRENT_LIST_DIR}/)

#set(JATTA_SOURCE
#    ${JATTA_SOURCE}
#    ${DIR}Object.cpp
#    ${DIR}String.cpp
#    PARENT_SCOPE
#)

#INSTALL(FILES Object.h DESTINATION include/Jatta/Utility/)
#INSTALL(FILES Ptr.h DESTINATION include/Jatta/Utility/)
#INSTALL(FILES String.h DESTINATION include/Jatta/Utility/)

ADD_GROUP("Utility")
ADD_SOURCE(Object.cpp)
ADD_HEADER(Object.h include/Jatta/Utility/)
ADD_HEADER(Ptr.h include/Jatta/Utility/)
ADD_SOURCE(String.cpp)
ADD_HEADER(String.h include/Jatta/Utility/)