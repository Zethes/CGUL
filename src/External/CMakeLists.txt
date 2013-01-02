#set(DIR ${CMAKE_CURRENT_LIST_DIR}/)

#INSTALL(FILES Defines.h DESTINATION include/Jatta/External/)
#INSTALL(FILES Once.h DESTINATION include/Jatta/External/)
#INSTALL(FILES Undefines.h DESTINATION include/Jatta/External/)

ADD_GROUP("External")
ADD_HEADER(Defines.h include/Jatta/External)
ADD_HEADER(Once.h include/Jatta/External)
ADD_HEADER(Undefines.h include/Jatta/External)