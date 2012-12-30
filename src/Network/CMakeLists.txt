set(DIR ${CMAKE_CURRENT_LIST_DIR}/)

set(JATTA_SOURCE
    ${JATTA_SOURCE}
    ${DIR}DNS.cpp
    ${DIR}Network.cpp
    ${DIR}TCP.cpp
    PARENT_SCOPE
)

INSTALL(FILES Dns.h DESTINATION include/Jatta/Network/)
INSTALL(FILES TCP.h DESTINATION include/Jatta/Network/)