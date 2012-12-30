set(DIR ${CMAKE_CURRENT_LIST_DIR}/)

set(JATTA_SOURCE
    ${JATTA_SOURCE}
    ${DIR}Graphics.cpp
    ${DIR}Mesh.cpp
    ${DIR}Primitives.cpp
    ${DIR}RenderTarget.cpp
    ${DIR}Shader.cpp
    ${DIR}SubMesh.cpp
    ${DIR}Texture.cpp
    PARENT_SCOPE
)

INSTALL(FILES Graphics.h DESTINATION include/Jatta/Graphics/)
INSTALL(FILES Mesh.h DESTINATION include/Jatta/Graphics/)
INSTALL(FILES Primitives.h DESTINATION include/Jatta/Graphics/)
INSTALL(FILES RenderTarget.h DESTINATION include/Jatta/Graphics/)
INSTALL(FILES Shader.h DESTINATION include/Jatta/Graphics/)
INSTALL(FILES SubMesh.h DESTINATION include/Jatta/Graphics/)
INSTALL(FILES Texture.h DESTINATION include/Jatta/Graphics/)