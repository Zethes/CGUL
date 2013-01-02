#set(DIR ${CMAKE_CURRENT_LIST_DIR}/)

#set(JATTA_SOURCE
    #${JATTA_SOURCE}
    #${DIR}Font.cpp
    #${DIR}Font.h
    #${DIR}Glyph.cpp
    #${DIR}Glyph.h
    #PARENT_SCOPE
#)

#INSTALL(FILES Font.h DESTINATION include/Jatta/Fonts/)
#INSTALL(FILES Glyph.h DESTINATION include/Jatta/Fonts/)

ADD_GROUP("Fonts")
ADD_SOURCE(Font.cpp)
ADD_HEADER(Font.h include/Jatta/Fonts)