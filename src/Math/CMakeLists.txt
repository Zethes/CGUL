#set(DIR ${CMAKE_CURRENT_LIST_DIR}/)

#set(JATTA_SOURCE
    #${JATTA_SOURCE}
    #${DIR}Float2.cpp
    #${DIR}Float3.cpp
    #${DIR}Float4.cpp
    #${DIR}Math.cpp
    #${DIR}Matrix.cpp
    #${DIR}Random.cpp
    #PARENT_SCOPE
#)

#INSTALL(FILES Float2.h DESTINATION include/Jatta/Math/)
#INSTALL(FILES Float3.h DESTINATION include/Jatta/Math/)
#INSTALL(FILES Float4.h DESTINATION include/Jatta/Math/)
#INSTALL(FILES Math.h DESTINATION include/Jatta/Math/)
#INSTALL(FILES Matrix.h DESTINATION include/Jatta/Math/)
#INSTALL(FILES Random.h DESTINATION include/Jatta/Math/)

ADD_GROUP("Math")
ADD_SOURCE(Float2.cpp)
ADD_HEADER(Float2.h include/Jatta/Math/)
ADD_SOURCE(Float3.cpp)
ADD_HEADER(Float3.h include/Jatta/Math/)
ADD_SOURCE(Float4.cpp)
ADD_HEADER(Float4.h include/Jatta/Math/)
ADD_SOURCE(Math.cpp)
ADD_HEADER(Math.h include/Jatta/Math/)
ADD_SOURCE(Matrix.cpp)
ADD_HEADER(Matrix.h include/Jatta/Math/)
ADD_SOURCE(Random.cpp)
ADD_HEADER(Random.h include/Jatta/Math/)