#set(DIR ${CMAKE_CURRENT_LIST_DIR}/)

#set(JATTA_SOURCE
    #${JATTA_SOURCE}
    #${DIR}Graphics.cpp
    #${DIR}Mesh.cpp
    #${DIR}Primitives.cpp
    #${DIR}RenderTarget.cpp
    #${DIR}Shader.cpp
    #${DIR}SubMesh.cpp
    #${DIR}Texture.cpp
    #PARENT_SCOPE
#)

#INSTALL(FILES Graphics.h DESTINATION include/Jatta/Graphics/)
#INSTALL(FILES Mesh.h DESTINATION include/Jatta/Graphics/)
#INSTALL(FILES Primitives.h DESTINATION include/Jatta/Graphics/)
#INSTALL(FILES RenderTarget.h DESTINATION include/Jatta/Graphics/)
#INSTALL(FILES Shader.h DESTINATION include/Jatta/Graphics/)
#INSTALL(FILES SubMesh.h DESTINATION include/Jatta/Graphics/)
#INSTALL(FILES Texture.h DESTINATION include/Jatta/Graphics/)

ADD_GROUP("Graphics")
ADD_SOURCE(Graphics.cpp)
ADD_HEADER(Graphics.h include/Jatta/Graphics/)
ADD_SOURCE(Mesh.cpp)
ADD_HEADER(Mesh.h include/Jatta/Graphics/)
ADD_SOURCE(Primitives.cpp)
ADD_HEADER(Primitives.h include/Jatta/Graphics/)
ADD_SOURCE(RenderTarget.cpp)
ADD_HEADER(RenderTarget.h include/Jatta/Graphics/)
ADD_SOURCE(Shader.cpp)
ADD_HEADER(Shader.h include/Jatta/Graphics/)
ADD_SOURCE(SubMesh.cpp)
ADD_HEADER(SubMesh.h include/Jatta/Graphics/)
ADD_SOURCE(Texture.cpp)
ADD_HEADER(Texture.h include/Jatta/Graphics/)