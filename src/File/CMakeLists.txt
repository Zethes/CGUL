#set(DIR ${CMAKE_CURRENT_LIST_DIR}/)

#set(JATTA_SOURCE
    #${JATTA_SOURCE}
    #${DIR}File.cpp
    #${DIR}File.h
    #PARENT_SCOPE
#)

#INSTALL(FILES File.h DESTINATION include/Jatta/File/)

ADD_GROUP("Files")
ADD_SOURCE(File.cpp)
ADD_HEADER(File.h include/Jatta/Files)