#set(DIR ${CMAKE_CURRENT_LIST_DIR}/)

#set(JATTA_SOURCE
    #${JATTA_SOURCE}
    #${DIR}Color.cpp
    #${DIR}Image.cpp
    #${DIR}Png.cpp
    #PARENT_SCOPE
#)

#INSTALL(FILES Color.h DESTINATION include/Jatta/Images/)
#INSTALL(FILES Image.h DESTINATION include/Jatta/Images/)

ADD_GROUP("Images")
ADD_SOURCE(Color.cpp)
ADD_HEADER(Color.h include/Jatta/Images/)
ADD_SOURCE(Image.cpp)
ADD_HEADER(Image.h include/Jatta/Images/)
ADD_SOURCE(Png.cpp)