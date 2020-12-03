set(stuncore_headers
    buffer.h
    datastream.h
    messagehandler.h
    socketaddress.h
    socketrole.h
    stunauth.h
    stunbuilder.h
    stunclientlogic.h
    stunclienttests.h
    stuncore.h
    stunreader.h
    stuntypes.h
    stunutils.h
    crc32.h
)

add_library(stuncore
    ${stuncore_headers}
    buffer.cpp
    datastream.cpp
    messagehandler.cpp
    socketaddress.cpp
    stunbuilder.cpp
    stunclientlogic.cpp
    stunclienttests.cpp
    stunreader.cpp
    stunutils.cpp
    crc32.cpp
)

target_include_directories(stuncore PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/>)

target_link_libraries(stuncore common OpenSSL::Crypto)

install(FILES ${stuncore_headers} DESTINATION include/)

install(TARGETS stuncore EXPORT StuntmanTargets
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    INCLUDES DESTINATION include)
