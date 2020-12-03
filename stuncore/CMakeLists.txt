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
    stunreader.h
    stuntypes.h
    stunutils.h
    crc32.h
)

add_library(stuntmancore
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

set_target_properties(stuntmancore PROPERTIES
    OUTPUT_NAME stuncore)

target_include_directories(stuntmancore PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/>)

target_link_libraries(stuntmancore stuntmancommon OpenSSL::Crypto)

install(FILES ${stuncore_headers} DESTINATION include/)

install(TARGETS stuntmancore EXPORT StuntmanTargets
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    INCLUDES DESTINATION include)
