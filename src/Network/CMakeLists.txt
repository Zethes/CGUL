#set(DIR ${CMAKE_CURRENT_LIST_DIR}/)

#set(JATTA_SOURCE
#    ${JATTA_SOURCE}
#    ${DIR}DNS.cpp
#    ${DIR}Network.cpp
#    ${DIR}TCP.cpp
#    PARENT_SCOPE
#)

#INSTALL(FILES DNS.h DESTINATION include/Jatta/Network/)
#INSTALL(FILES TCP.h DESTINATION include/Jatta/Network/)

ADD_GROUP("Network")
ADD_SOURCE(DNS.cpp)
ADD_HEADER(DNS.h include/Jatta/Network/)
ADD_SOURCE(Network.cpp)
ADD_SOURCE(TCP.cpp)
ADD_HEADER(TCP.h include/Jatta/Network/)